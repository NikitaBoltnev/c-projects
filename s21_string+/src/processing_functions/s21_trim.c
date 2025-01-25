#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars);

void *s21_trim(const char *src, const char *trim_chars) {
  char *output = s21_NULL;

  if (src != s21_NULL) {
    int len_src = s21_strlen(src);
    s21_size_t index_count = 0;
    output = malloc(sizeof(char) * (len_src + 1));
    if (trim_chars == s21_NULL) {
      for (s21_size_t i = 0; src[i] != '\0'; i++) {
        output[index_count] = src[i];

        index_count++;
      }
      output[index_count] = '\0';
    } else {
      for (s21_size_t j = 0; src[j] != '\0'; j++) {
        int flag = 0;
        for (s21_size_t k = 0; trim_chars[k] != '\0'; k++) {
          if (src[j] == trim_chars[k]) {
            flag = 1;
            break;
          }
        }
        if (!flag) {
          output[index_count] = src[j];
          index_count++;
        }
      }
      output[index_count] = '\0';
    }
  } else {
    output = s21_NULL;
  }
  return output;
}
