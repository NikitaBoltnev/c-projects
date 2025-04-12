#include "../s21_string.h"
char *s21_strpbrk(const char *str_1, const char *str_2) {
  s21_size_t i = 0;
  s21_size_t j = 0;
  char *result = s21_NULL;
  int flag = 0;
  for (i = 0; str_1[i] != '\0'; i++) {
    for (j = 0; str_2[j] != '\0'; j++) {
      if (str_1[i] == str_2[j]) {
        result = (char *)(str_1 + i);
        flag = 1;
        break;
      }
    }
    if (flag) {
      break;
    }
  }

  return result;
}
