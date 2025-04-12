#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  int flag = 0;
  char *null_token = s21_NULL;
  for (; *str != (unsigned char)c; str++) {
    if (*str == '\0') {
      flag++;
      break;
    }
  }
  return (!flag) ? (char *)str : null_token;
}
