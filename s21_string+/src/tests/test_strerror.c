#include <stdio.h>

#include "../tests/s21_string_test.h"

#ifdef __APPLE__
#define S21_OS_MACOS
#endif

#ifdef __linux__
#define S21_OS_LINUX
#endif

START_TEST(test_strerror_1) {
#ifdef S21_OS_MACOS
  for (int i = 0; i < 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(17), strerror(17));
  ck_assert_str_eq(s21_strerror(-10), strerror(-10));
  ck_assert_str_eq(s21_strerror(0), strerror(0));
#endif

#ifdef S21_OS_LINUX
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(17), strerror(17));
  ck_assert_str_eq(s21_strerror(-10), strerror(-10));
  ck_assert_str_eq(s21_strerror(0), strerror(0));
#endif
}
END_TEST

Suite *test_strerror() {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_strerror");
  core = tcase_create("Core");

  tcase_add_test(core, test_strerror_1);

  suite_add_tcase(suite, core);

  return (suite);
}
