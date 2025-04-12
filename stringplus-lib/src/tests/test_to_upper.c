#include "s21_string_test.h"

START_TEST(to_upper_1) {
  char str_input[30] = "1234";
  char str_output[30] = "1234";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_2) {
  char str_input[30] = "*72^^pi9))";
  char str_output[30] = "*72^^PI9))";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_3) {
  char str_input[30] = "Hello!";
  char str_output[30] = "HELLO!";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_4) {
  char str_input[30] = "HELLO!";
  char str_output[30] = "HELLO!";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_5) {
  char str_input[30] = "HeLlO\nhihi haha!";
  char str_output[30] = "HELLO\nHIHI HAHA!";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_6) {
  char str_input[30] = "HeLlO\n\t\thihi haha!";
  char str_output[30] = "HELLO\n\t\tHIHI HAHA!";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_7) {
  char str_input[30] = "";
  char str_output[30] = "";
  char *res = s21_to_upper(str_input);
  ck_assert_pstr_eq(res, str_output);
  if (res) free(res);
}
END_TEST

Suite *test_to_upper() {
  Suite *test = suite_create("S21_to_upper");
  TCase *add_upper = tcase_create("s21_to_upper");
  tcase_add_test(add_upper, to_upper_1);
  tcase_add_test(add_upper, to_upper_2);
  tcase_add_test(add_upper, to_upper_3);
  tcase_add_test(add_upper, to_upper_4);
  tcase_add_test(add_upper, to_upper_5);
  tcase_add_test(add_upper, to_upper_6);
  tcase_add_test(add_upper, to_upper_7);

  suite_add_tcase(test, add_upper);
  return test;
}
