#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *res = (unsigned char *)dest;
  const unsigned char *cp = (const unsigned char *)src;
  if (dest != s21_NULL && src != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      res[i] = cp[i];
    }
  }
  return res;
}