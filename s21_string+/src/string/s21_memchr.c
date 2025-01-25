#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *result = s21_NULL;
  if (str != s21_NULL && n > 0) {
    const unsigned char *string = (const unsigned char *)str;
    unsigned char ch = (unsigned char)c;
    for (s21_size_t i = 0; i < n; i++) {
      if (string[i] == ch) {
        result = (char *)(string + i);
        i = n;
      }
    }
  }
  return result;
}
