#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *output = s21_NULL;

  if (str != s21_NULL && src != s21_NULL) {  // 1st check
    int len_str = s21_strlen(str);
    int len_src = s21_strlen(src);

    if ((int)start_index >= 0 && (int)start_index <= len_src) {  // 2nd check
      output = malloc(sizeof(char) * (len_src + len_str + 1));
      if (src[0] == '\0' && str[0] == '\0') {
        output[0] = '\0';
      } else if (output != s21_NULL) {
        int index_count = 0;
        int index_src = 0;

        while (index_src < (int)start_index) {
          output[index_count] = src[index_src];
          index_count++;
          index_src++;
        }

        for (s21_size_t index_str = 0; str[index_str] != '\0'; index_str++) {
          output[index_count] = str[index_str];
          index_count++;
        }

        while (src[index_src] != '\0') {
          output[index_count] = src[index_src];
          index_count++;
          index_src++;
        }

        output[index_count] = '\0';
      }
    } else {  // 1st check
      output = s21_NULL;
    }
  } else {  // 2nd check
    output = s21_NULL;
  }
  if (output != s21_NULL &&
      (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src))) {
    free(output);
    output = s21_NULL;
  }
  return output;
}
