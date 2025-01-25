#ifndef S21_GREP_H_
#define S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1024

typedef struct {
  int flagE;  // -e
  int flagI;  // -i
  int flagV;  // -v
  int flagC;  // -c
  int flagL;  // -l
  int flagN;  // -n
  int flagH;  // -h
  int flagS;  // -s
  int flagF;  // -f
  int flagO;  // -o
  int error;  // неправильный флаг
} flags;

typedef struct {
  char *path;
  int countFiles;
  int countPattern;
} values;

int findPattern(int optInd, char *argv[], char patterns[SIZE][SIZE]);
int parseInput(int argc, char *argv[], flags *flagStruct, values *value,
               char pattern[SIZE][SIZE]);
void processFile(values value, flags flagsStruct, char pattern[SIZE][SIZE]);
void printingString(values value, flags flagStruct, int countLine,
                    char *string);
void flagC_L(values value, flags flagStruct, int countMatchedLines);
void readPatternsFromFile(char *fileName, char pattern[SIZE][SIZE],
                          values *value);
void flag_o(char *string, regex_t rx);
#endif