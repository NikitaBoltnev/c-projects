#include "../s21_string.h"

void *s21_to_upper(const char *str);

void *s21_to_upper(const char *str) {
  char *letters_to_upper = s21_NULL;  // change to small s21
  if (str != s21_NULL) {
    letters_to_upper = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t i = 0;
    for (; str[i] != '\0'; i++)
      if (str[i] >= 'a' && str[i] <= 'z') {
        letters_to_upper[i] = str[i] - 32;
      } else {
        letters_to_upper[i] = str[i];
      }
    letters_to_upper[i] = '\0';
  } else {
    letters_to_upper = s21_NULL;
  }
  return letters_to_upper;
}
