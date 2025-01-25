#include "s21_string_test.h"

START_TEST(to_lower_1) {
  char str_input[30] = "1234";
  char str_output[30] = "1234";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_2) {
  char str_input[30] = "*72^^PI9))";
  char str_output[30] = "*72^^pi9))";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_3) {
  char str_input[30] = "HEllo!";
  char str_output[30] = "hello!";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_4) {
  char str_input[30] = "hello";
  char str_output[30] = "hello";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_5) {
  char str_input[30] = "HELLO\nHIHI HAHA";
  char str_output[30] = "hello\nhihi haha";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_6) {
  char str_input[30] = "HELLO\n\t\tHIHI HAHA";
  char str_output[30] = "hello\n\t\thihi haha";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_7) {
  char str_input[30] = "";
  char str_output[30] = "";
  char *res = s21_to_lower(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

Suite *test_to_lower() {
  Suite *test = suite_create("S21_to_lower");
  TCase *add_lower = tcase_create("s21_to_lower");
  tcase_add_test(add_lower, to_lower_1);
  tcase_add_test(add_lower, to_lower_2);
  tcase_add_test(add_lower, to_lower_3);
  tcase_add_test(add_lower, to_lower_4);
  tcase_add_test(add_lower, to_lower_5);
  tcase_add_test(add_lower, to_lower_6);
  tcase_add_test(add_lower, to_lower_7);

  suite_add_tcase(test, add_lower);
  return test;
}
