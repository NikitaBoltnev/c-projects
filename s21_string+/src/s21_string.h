#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_NULL ((void *)0)

typedef unsigned long s21_size_t;

typedef struct Format {
  int flagPlus;
  int flagMinus;
  int flagSpace;
  int width;
  int accuracy;
  char length;

} Flags;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str_1, const char *str_2);
char *s21_strrchr(const char *str_1, int symbol);
char *s21_strerror(int errnum);

int s21_sprintf(char *str, const char *format, ...);
void readFlags(Flags *flag, const char *tempC);
int readIntegerFromStr(const char **tempC);
void readLength(Flags *flag, const char *tempC);
void zeroingFlags(Flags *flag);
int fillingStringWithChar(char **res, char c, int check, Flags *flag);
int processing_flags(long long value, int base, Flags *flag, int check,
                     char **res);
void reverse_string(char *str);
int processingFlagsForU(unsigned long num, Flags *flag, char **res, int check);
int processingFlagsForF(Flags *flag, double num, char **final, int checkFinal);
int spec_s(char **res, char *s, int check, Flags *flag);
void s21_errors_sprintf(char **str, Flags *flag, const char *format,
                        s21_size_t *check);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif