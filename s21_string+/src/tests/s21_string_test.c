#include "s21_string_test.h"

int main() {
  int failed = 0;
  Suite *s21StringTest[] = {test_memchr(),
                            test_memcmp(),
                            test_memcpy(),
                            test_strncpy(),
                            test_strpbrk(),
                            test_memset(),
                            test_strncat(),
                            test_strchr(),
                            test_strncmp(),
                            test_strrchr(),
                            test_strstr(),
                            test_strtok(),
                            test_strcspn(),
                            test_strlen(),
                            test_strerror(),
                            test_sprintf_c(),
                            test_sprintf_u(),
                            test_sprintf_f(),
                            test_sprintf_d(),
                            test_sprintf_s(),
                            test_to_upper(),
                            test_to_lower(),
                            test_insert(),
                            test_trim(),
                            NULL};

  for (int i = 0; s21StringTest[i] != NULL; i++) {
    SRunner *test = srunner_create(s21StringTest[i]);
    srunner_run_all(test, CK_VERBOSE);
    failed += srunner_ntests_failed(test);
    srunner_free(test);
  }
  printf("Count of errors in the tests: %d\n", failed);

  return 0;
}
