#ifndef S21_CAT_H_
#define S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int squeezeBlank;     // s
  int showEnds;         // e
  int showTabs;         // t
  int numberNonBlank;   // b
  int number;           // n
  int showNonPrintable; // v
} Flags;

void parseShortFlags(char *fileName[], int amountFiles, char flagNoGNU[],
                     int *errorFlag);
void removeDuplicates(char flags[], int arraySize);
void parseLongFlags(char *fileName[], int amountFiles, char flagGNU[],
                    int *errorFlag);
void removeDuplicatesForGNU(char *flagsGNU, int size, int *errorFlag);
void validateFlags(const char flags[], int *errorFlag);
void concatenateFlags(char flags[], const char flagGNU[]);
void processFiles(const char flags[], const char *fileName[], int fileCount);
Flags parseFlags(const char flags[]);
void processFileWithFlags(FILE *f, const Flags *flags);

#endif