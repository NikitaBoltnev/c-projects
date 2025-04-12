#include "s21_cat.h"

int main(int argc, char *argv[]) {
  char *flags = calloc(1024, sizeof(char));
  char *flagGNU = calloc(1024, sizeof(char));
  int errorFlag = 0;
  parseShortFlags(argv, argc, flags, &errorFlag);
  parseLongFlags(argv, argc, flagGNU, &errorFlag);
  concatenateFlags(flags, flagGNU);
  if (errorFlag == 1) {
    free(flags);
    free(flagGNU);

  } else {
    const char **fileNames =
        (const char **)calloc(argc + 1, sizeof(const char *));
    int fileCount = 0;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        fileNames[fileCount++] = argv[i];
      }
    }
    processFiles(flags, fileNames, fileCount);

    free(flags);
    free(flagGNU);
    free(fileNames);
  }
  return 0;
}

void processFiles(const char flags[], const char *fileName[], int fileCount) {
  Flags f = parseFlags(flags);

  for (int i = 0; i < fileCount; i++) {
    FILE *file = fopen(fileName[i], "r");
    if (file == NULL) {
      printf("s21_cat: %s : No such file or directory\n", fileName[i]);
      continue;
    }

    processFileWithFlags(file, &f);
    fclose(file);
  }
}

Flags parseFlags(const char flags[]) {
  Flags f = {0};

  if (strchr(flags, 'e') != NULL) {
    f.showEnds = 1;
    f.showNonPrintable = 1;
  }
  if (strchr(flags, 'E') != NULL) {
    f.showEnds = 1;
  }
  if (strchr(flags, 't') != NULL) {
    f.showTabs = 1;
    f.showNonPrintable = 1;
  }
  if (strchr(flags, 'T') != NULL) {
    f.showTabs = 1;
  }
  if (strchr(flags, 'b') != NULL) {
    f.numberNonBlank = 1;
  }
  if (strchr(flags, 'n') != NULL) {
    f.number = 1;
  }
  if (strchr(flags, 's') != NULL) {
    f.squeezeBlank = 1;
  }
  if (strchr(flags, 'v') != NULL) {
    f.showNonPrintable = 1;
  }
  if (f.numberNonBlank) {
    f.number = 0;
  }

  return f;
}

void processFileWithFlags(FILE *f, const Flags *flags) {
  int lineNumber = 1;
  int flagNewLine = 1;
  int newLineCounter = 0;
  char newLine = '\n';
  char tab = '\t';
  int ch = 0;
  while ((ch = fgetc(f)) != EOF) {
    if (ch != newLine && flagNewLine &&
        (flags->numberNonBlank || flags->number)) {
      printf("%6d\t", lineNumber++);
    }

    if (ch == newLine && flagNewLine && flags->number &&
        !flags->numberNonBlank) {
      printf("%6d\t", lineNumber++);
      flagNewLine = 0;
    }
    if (((ch >= 0 && ch < 9) || (ch > 10 && ch < 32) ||
         (ch > 126 && ch < 160)) &&
        (flags->showNonPrintable || (ch == tab && flags->showTabs))) {
      flagNewLine = 0;
      newLineCounter = 0;
      if (ch > 127) {
        printf("M-");
      }
      printf("^%c", ch >= 32 ? ch - '@' : ch + '@');
    } else if (ch == tab && flags->showTabs) {
      flagNewLine = 0;
      newLineCounter = 0;
      printf("^I");
    } else {
      if (ch == newLine) {
        if (newLineCounter < 2) {
          flagNewLine = 1;
          if (flags->showEnds) {
            printf("$\n");
          } else {
            printf("\n");
          }
        }
        if (flags->squeezeBlank) {
          newLineCounter++;
        }
      } else {
        newLineCounter = 0;
        flagNewLine = 0;
        printf("%c", ch);
      }
    }
  }
}

void parseShortFlags(char *fileName[], int amountFiles, char flagNoGNU[],
                     int *errorFlag) {
  int flagIndex = 0;
  char *flags = calloc(1024, sizeof(char));
  for (int i = 1; i < amountFiles; i++) {
    if (fileName[i][0] == '-' && fileName[i][1] != '\0' &&
        fileName[i][1] != '-') {
      int j = 1;
      while (fileName[i][j] != '\n' && fileName[i][j] != ' ' &&
             fileName[i][j] != '\0') {
        flags[flagIndex] = fileName[i][j];
        flagIndex++;
        j++;
      }
    }
  }
  removeDuplicates(flags, flagIndex);
  validateFlags(flags, errorFlag);
  strcpy(flagNoGNU, flags);
  free(flags);
}

void removeDuplicates(char flags[], int arraySize) {
  int check = 0;
  if (arraySize <= 0) {
    check = 1;
  }

  if (check == 0) {
    char *uniqueFlags = (char *)calloc((arraySize + 1), sizeof(char));
    int uniqueCount = 0;
    for (int i = 0; i < arraySize; i++) {
      int isDuplicate = 0;
      for (int j = 0; j < uniqueCount; j++) {
        if (flags[i] == uniqueFlags[j]) {
          isDuplicate = 1;
          break;
        }
      }

      if (!isDuplicate) {
        uniqueFlags[uniqueCount++] = flags[i];
      }
    }

    uniqueFlags[uniqueCount] = '\0';

    strcpy(flags, uniqueFlags);
    free(uniqueFlags);
  }
}

void parseLongFlags(char *fileName[], int amountFiles, char flagGNU[],
                    int *errorFlag) {
  int flagIndex = 0;
  char *array = calloc(1024, sizeof(char));
  for (int i = 0; i < amountFiles; i++) {
    if (fileName[i][0] == fileName[i][1] && fileName[i][0] == '-' &&
        fileName[i][2] != '\0') {
      int j = 2;
      while (fileName[i][j] != '\n' && fileName[i][j] != ' ' &&
             fileName[i][j] != '\0') {
        array[flagIndex] = fileName[i][j];
        flagIndex++;
        j++;
      }
      array[flagIndex] = ' ';
      flagIndex++;
    }
  }
  if (flagIndex != 0) {
    removeDuplicatesForGNU(array, flagIndex, errorFlag);
    strcpy(flagGNU, array);
  }
  free(array);
}

void removeDuplicatesForGNU(char *flagsGNU, int size, int *errorFlag) {
  int checkArray = 0;
  int falseCheck = 0;
  char *cleanArray = calloc(1024, sizeof(char));
  for (int i = 0; i < size; i++) {
    if (i + 15 < size && flagsGNU[i] == 'n' && flagsGNU[i + 1] == 'u' &&
        flagsGNU[i + 2] == 'm' && flagsGNU[i + 3] == 'b' &&
        flagsGNU[i + 4] == 'e' && flagsGNU[i + 5] == 'r' &&
        flagsGNU[i + 6] == '-' && flagsGNU[i + 7] == 'n' &&
        flagsGNU[i + 8] == 'o' && flagsGNU[i + 9] == 'n' &&
        flagsGNU[i + 10] == 'b' && flagsGNU[i + 11] == 'l' &&
        flagsGNU[i + 12] == 'a' && flagsGNU[i + 13] == 'n' &&
        flagsGNU[i + 14] == 'k' &&
        (flagsGNU[i + 15] == ' ' || flagsGNU[i + 15] == '\0' ||
         flagsGNU[i + 15] == '\n')) {
      cleanArray[checkArray] = 'b';
      checkArray++;
      i += 15;
      continue;
    }

    if (i + 6 < size && flagsGNU[i] == 'n' && flagsGNU[i + 1] == 'u' &&
        flagsGNU[i + 2] == 'm' && flagsGNU[i + 3] == 'b' &&
        flagsGNU[i + 4] == 'e' && flagsGNU[i + 5] == 'r' &&
        (flagsGNU[i + 6] == ' ' || flagsGNU[i + 6] == '\0' ||
         flagsGNU[i + 6] == '\n')) {
      cleanArray[checkArray] = 'n';
      checkArray++;
      i += 6;
      continue;
    }

    if (i + 13 < size && flagsGNU[i] == 's' && flagsGNU[i + 1] == 'q' &&
        flagsGNU[i + 2] == 'u' && flagsGNU[i + 3] == 'e' &&
        flagsGNU[i + 4] == 'e' && flagsGNU[i + 5] == 'z' &&
        flagsGNU[i + 6] == 'e' && flagsGNU[i + 7] == '-' &&
        flagsGNU[i + 8] == 'b' && flagsGNU[i + 9] == 'l' &&
        flagsGNU[i + 10] == 'a' && flagsGNU[i + 11] == 'n' &&
        flagsGNU[i + 12] == 'k' &&
        (flagsGNU[i + 13] == ' ' || flagsGNU[i + 13] == '\0' ||
         flagsGNU[i + 13] == '\n')) {
      cleanArray[checkArray] = 's';
      checkArray++;
      i += 13;
      continue;
    }

    falseCheck++;
  }

  if (falseCheck != 0) {
    printf("s21_cat: unrecognized option\n");

    *errorFlag = 1;
  } else {
    removeDuplicates(cleanArray, checkArray);
    strcpy(flagsGNU, cleanArray);
    flagsGNU[checkArray] = '\0';
  }
  free(cleanArray);
}

void validateFlags(const char flags[], int *errorFlag) {
  int check = 0;
  while (flags[check] != '\0') {
    check++;
  }
  for (int i = 0; i < check; i++) {
    switch (flags[i]) {
    case 'b':

    case 'n':

    case 's':

    case 'T':

    case 'E':

    case 'e':

    case 'v':

    case 't':

      break;

    default:
      printf("21_cat: Invalid option: - '%c'\n", flags[i]);
      *errorFlag = 1;
    }
  }
}

void concatenateFlags(char flags[], const char flagGNU[]) {
  strcat(flags, flagGNU);
  removeDuplicates(flags, 10);
}