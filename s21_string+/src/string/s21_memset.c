#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *res = (unsigned char *)str;
  unsigned char symbol = (unsigned char)c;
  if (res != s21_NULL && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      res[i] = symbol;
    }
  }
  return res;
}