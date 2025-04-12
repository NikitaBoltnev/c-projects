#include "s21_string_test.h"

START_TEST(memset_1) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = '1';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = '1';
  s21_size_t n = sizeof(str1) - 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = '1';
  s21_size_t n = strlen(str2);
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str1[] = "Tekst\0 for test";
  char str2[] = "Tekst\0 for test";
  int c = '$';
  s21_size_t n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = 64;
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_6) {
  char str1[] = "";
  char str2[] = "";
  int c = 'a';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_7) {
  char str1[] = " ";
  char str2[] = " ";
  int c = 'a';
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_8) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = ' ';
  s21_size_t n = 3;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_9) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = '\0';
  s21_size_t n = 3;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_10) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  int c = 33;
  s21_size_t n = 14;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_11) {
  char str1[] = "";
  char str2[] = "";
  int c = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

Suite *test_memset() {
  Suite *test = suite_create("S21_MEMSET");
  TCase *fourth_group = tcase_create("s21_memset");
  tcase_add_test(fourth_group, memset_1);
  tcase_add_test(fourth_group, memset_2);
  tcase_add_test(fourth_group, memset_3);
  tcase_add_test(fourth_group, memset_4);
  tcase_add_test(fourth_group, memset_5);
  tcase_add_test(fourth_group, memset_6);
  tcase_add_test(fourth_group, memset_7);
  tcase_add_test(fourth_group, memset_8);
  tcase_add_test(fourth_group, memset_9);
  tcase_add_test(fourth_group, memset_10);
  tcase_add_test(fourth_group, memset_11);
  suite_add_tcase(test, fourth_group);
  return test;
}
