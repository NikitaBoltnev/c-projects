#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;
  register int ch;

  if (str == 0) {
    str = last_token;
  }
  do {
    if ((ch = *str++) == '\0') {
      return 0;
    }
  } while (s21_strchr(delim, ch));
  str--;
  last_token = str + s21_strcspn(str, delim);
  if (*last_token != 0) {
    *last_token++ = 0;
  }
  return str;
}
