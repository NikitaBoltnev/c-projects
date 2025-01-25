#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char pattern[SIZE][SIZE] = {0};
  int optInd = 0;
  flags flagStruct = {0};
  values value = {0};
  int fileLocation = 0;

  optInd = parseInput(argc, argv, &flagStruct, &value, pattern);

  if (argc > 2 && flagStruct.error != 1) {
    if (optInd != argc) {
      fileLocation = findPattern(optInd, argv, pattern);
      while (fileLocation < argc) {
        if (argv[fileLocation + 1] != NULL) {
          value.countFiles += 1;
        }
        value.path = argv[fileLocation];
        processFile(value, flagStruct, pattern);
        fileLocation += 1;
      }
    }
  }
}

int findPattern(int optInd, char *argv[], char patterns[SIZE][SIZE]) {
  int fileLocation = 0;
  if (*patterns[0] == 0) {
    fileLocation = optInd + 1;
    strcpy(patterns[0], argv[optind]);

  } else {
    fileLocation = optInd;
  }
  return fileLocation;
}

int parseInput(int argc, char *argv[], flags *flagStruct, values *value,
               char pattern[SIZE][SIZE]) {
  int opt = 0;
  opterr = 0;
  while ((opt = getopt_long(argc, argv, "e:ivclhnsf:o", NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        while (*pattern[value->countPattern] != 0) {
          value->countPattern += 1;
        }
        strcpy(pattern[value->countPattern], optarg);
        value->countPattern += 1;
        flagStruct->flagE = 1;
        break;
      case 'i':
        flagStruct->flagI = 1;
        break;
      case 'v':
        flagStruct->flagV = 1;
        break;
      case 'c':
        flagStruct->flagC = 1;
        break;
      case 'h':
        flagStruct->flagH = 1;
        break;
      case 'l':
        flagStruct->flagL = 1;
        break;
      case 'n':
        flagStruct->flagN = 1;
        break;
      case 's':
        flagStruct->flagS = 1;
        break;
      case 'f':
        while (*pattern[value->countPattern] != 0) {
          value->countPattern += 1;
        }
        readPatternsFromFile(optarg, pattern, value);
        flagStruct->flagF = 1;
        break;
      case 'o':
        flagStruct->flagO = 1;
        break;
      default:
        printf("Invalid flag is specified.");
        flagStruct->error = 1;
        break;
    }
  }

  return optind;
}

void processFile(values value, flags flagsStruct, char pattern[SIZE][SIZE]) {
  FILE *file;
  char string[SIZE] = " ";
  int countLines = 0;
  int countMatchedLines = 0;
  int regular = REG_EXTENDED;
  int stop = 0;
  int resultRegex = 243;
  regex_t rx;
  if (flagsStruct.flagV == 1 || flagsStruct.flagC == 1 ||
      flagsStruct.flagL == 1) {
    flagsStruct.flagO = 0;
  }
  if (access(value.path, F_OK) == 0) {
    file = fopen(value.path, "r");
    if (value.countPattern == 0 && flagsStruct.flagE == 0 &&
        flagsStruct.flagF == 0) {
      value.countPattern = 1;
    }
    if (flagsStruct.flagI == 1) {
      regular = REG_ICASE;
    }
    while ((fgets(string, SIZE, file)) && (stop == 0)) {
      int findline = 0;
      countLines++;
      int patternNoMatch = 0;
      if (strchr(string, '\n') == NULL) {
        strcat(string, "\n");
      }

      for (int i = 0; i < value.countPattern; i++) {
        int match = 0;

        regcomp(&rx, pattern[i], regular | REG_NEWLINE);

        resultRegex = regexec(&rx, string, 0, 0, 0);

        if (resultRegex == 0 && flagsStruct.flagV == 0) {
          match = 1;
        }

        if (resultRegex == REG_NOMATCH && flagsStruct.flagV == 1) {
          patternNoMatch++;
          if (patternNoMatch == value.countPattern) {
            match = 1;
          }
        }
        if (flagsStruct.flagL == 1 && match == 1 && flagsStruct.flagC == 0) {
          printf("%s\n", value.path);
          match = 0;
          stop = 1;
        }
        if (flagsStruct.flagC == 1 && match == 1) {
          countMatchedLines++;
          match = 0;
        }
        if (findline == 0 && match == 1) {
          printingString(value, flagsStruct, countLines, string);
          findline++;
        }
        if (flagsStruct.flagO == 1) {
          flag_o(string, rx);
        }
        regfree(&rx);
      }
    }
    if (flagsStruct.flagC == 1) {
      flagC_L(value, flagsStruct, countMatchedLines);
    }
    fclose(file);

  } else if (flagsStruct.flagS == 0) {
    printf("There is no file: %s\n", value.path);
  }
}

void printingString(values value, flags flagStruct, int countLine,
                    char *string) {
  if (value.countFiles >= 1 && flagStruct.flagH == 0) {
    printf("%s:", value.path);
  }
  if (flagStruct.flagN == 1) {
    printf("%d:", countLine);
  }
  if (flagStruct.flagO == 0) {
    printf("%s", string);
  }
}

void flagC_L(values value, flags flagStruct, int countMatchedLines) {
  if (value.countFiles >= 1 && flagStruct.flagH == 0) {
    printf("%s:", value.path);
  }
  if (flagStruct.flagL == 0) {
    printf("%d\n", countMatchedLines);
  } else if (flagStruct.flagL == 1) {
    if (countMatchedLines > 0) {
      printf("1\n");
      printf("%s\n", value.path);
    } else {
      printf("0\n");
    }
  }
}

void readPatternsFromFile(char *fileName, char pattern[SIZE][SIZE],
                          values *value) {
  FILE *file;
  int length = 0;

  if (access(fileName, F_OK) == 0) {
    file = fopen(fileName, "r");
    while ((!feof(file))) {
      fgets(pattern[value->countPattern], SIZE, file);
      length = strlen(pattern[value->countPattern]);
      if (pattern[value->countPattern][0] != '\n' &&
          pattern[value->countPattern][length - 1] == '\n') {
        pattern[value->countPattern][length - 1] = '\0';
      }
      value->countPattern += 1;
    }
    fclose(file);
  } else {
    printf("Error with the file");
  }
}

void flag_o(char *string, regex_t rx) {
  regmatch_t pmatch[1];
  while (regexec(&rx, string, 1, pmatch, 0) == 0) {
    for (int j = 0; j < pmatch->rm_eo; j++) {
      if (j >= pmatch->rm_so) {
        printf("%c", string[j]);
      }
      string[j] = 127;
    }
    printf("\n");
  }
}