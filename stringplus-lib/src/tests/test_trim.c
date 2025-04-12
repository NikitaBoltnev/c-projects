#include "s21_string_test.h"
START_TEST(test_trim_1) {
  char src[30] = "He^*llo";
  char *trim = s21_NULL;
  char right[] = "He^*llo";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_2) {
  char src[30] = "He^*llo";
  char trim[] = "^";
  char right[] = "He*llo";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_3) {
  char src[30] = " He^*llo ";
  char trim[] = " ^";
  char right[] = "He*llo";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_4) {
  char src[30] = "Hi hi";
  char trim[] = "Hi hi";
  char right[] = "";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_5) {
  char *src = s21_NULL;
  char trim[] = "Hi hi";
  char *right = s21_NULL;
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_6) {
  char src[] = "";
  char trim[] = "";
  char right[] = "";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_7) {
  char src[] = " hi ";
  char trim[] = "";
  char right[] = " hi ";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_8) {
  char *src = s21_NULL;
  char *trim = s21_NULL;
  char *right = s21_NULL;
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_9) {
  char src[] = "!^hihi^!";
  char trim[] = "!^";
  char right[] = "hihi";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, right);
  if (res) free(res);
}
END_TEST

Suite *test_trim() {
  Suite *test = suite_create("S21_trim");
  TCase *add_lower = tcase_create("s21_trim");
  tcase_add_test(add_lower, test_trim_1);
  tcase_add_test(add_lower, test_trim_2);
  tcase_add_test(add_lower, test_trim_3);
  tcase_add_test(add_lower, test_trim_4);
  tcase_add_test(add_lower, test_trim_5);
  tcase_add_test(add_lower, test_trim_6);
  tcase_add_test(add_lower, test_trim_7);
  tcase_add_test(add_lower, test_trim_8);
  tcase_add_test(add_lower, test_trim_9);

  suite_add_tcase(test, add_lower);
  return test;
}
