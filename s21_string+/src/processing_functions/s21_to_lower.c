#include "../s21_string.h"

void *s21_to_lower(const char *str);

void *s21_to_lower(const char *str) {
  char *letters_to_lower = s21_NULL;
  if (str != s21_NULL) {
    letters_to_lower = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t i = 0;
    for (i = 0; str[i] != '\0'; i++)
      if (str[i] >= 'A' && str[i] <= 'Z') {
        letters_to_lower[i] = str[i] + 32;
      } else {
        letters_to_lower[i] = str[i];
      }
    letters_to_lower[i] = '\0';
  } else {
    letters_to_lower = s21_NULL;
  }

  return letters_to_lower;
}
