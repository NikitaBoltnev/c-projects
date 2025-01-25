#include "s21_string_test.h"

START_TEST(test_insert_1) {
  char src[30] = "Hey, come in!";
  char str[] = "you, ";
  char output[] = "Hey, you, come in!";
  s21_size_t num = 5;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_2) {
  char src[30] = "";
  char str[] = "";
  char *output = s21_NULL;
  s21_size_t num = 5;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_3) {
  char src[30] = "\0";
  char str[] = "\0";
  char output[] = "\0";
  s21_size_t num = 0;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_4) {
  char src[30] = "Hey, come in";
  char str[] = "you";
  char *output = s21_NULL;
  s21_size_t num = -1;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_5) {
  char src[30] = "Hey";
  char str[] = "you";
  char *output = s21_NULL;
  s21_size_t num = 7;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_7) {
  char src[30] = "World";
  char str[] = "Hello ";
  char output[] = "Hello World";
  s21_size_t num = 0;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_8) {
  char src[30] = "World";
  char *str = s21_NULL;
  char *output = s21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_9) {
  char *src = s21_NULL;
  char str[] = "World";
  char *output = s21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_10) {
  char src[] = "";
  char str[] = "";
  char output[] = "";
  s21_size_t num = 0;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_11) {
  char src[] = "Hello\0World";
  char str[] = " ";
  char output[] = "Hello ";
  s21_size_t num = 5;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_12) {
  char src[] = "World";
  char str[] = " Hel\0l0";
  char output[] = "World Hel";
  s21_size_t num = 5;
  char *res = s21_insert(src, str, num);
  ck_assert_pstr_eq(output, res);
  if (res) free(res);
}
END_TEST

Suite *test_insert() {
  Suite *test = suite_create("S21_insert");
  TCase *add_lower = tcase_create("s21_insert");
  tcase_add_test(add_lower, test_insert_1);
  tcase_add_test(add_lower, test_insert_2);
  tcase_add_test(add_lower, test_insert_3);
  tcase_add_test(add_lower, test_insert_4);
  tcase_add_test(add_lower, test_insert_5);
  tcase_add_test(add_lower, test_insert_7);
  tcase_add_test(add_lower, test_insert_8);
  tcase_add_test(add_lower, test_insert_9);
  tcase_add_test(add_lower, test_insert_10);
  tcase_add_test(add_lower, test_insert_11);
  tcase_add_test(add_lower, test_insert_12);

  suite_add_tcase(test, add_lower);
  return test;
}
