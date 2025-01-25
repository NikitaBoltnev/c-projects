#include "../s21_string.h"

char *s21_strrchr(const char *str_1, int symbol) {
  s21_size_t len = s21_strlen(str_1);
  char *result = s21_NULL;
  str_1 = str_1 + len;

  for (int i = (int)len; i >= 0; i--) {
    if (*str_1 == symbol) {
      result = (char *)str_1;
      break;
    }
    str_1--;
  }

  return result;
}
