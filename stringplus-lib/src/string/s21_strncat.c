#include "../s21_string.h"
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *res = dest;
  if (res != s21_NULL && n > 0) {
    s21_size_t i = 0;

    while (res[i] != '\0') {
      i++;
    }

    for (s21_size_t j = 0; j < n && src[j] != '\0'; j++) {
      res[i++] = src[j];
    }
    res[i] = '\0';
  }
  return dest;
}