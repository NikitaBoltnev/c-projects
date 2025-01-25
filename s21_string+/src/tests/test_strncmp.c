#include "s21_string_test.h"

START_TEST(strncmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char s1[] = "Hello,#world!";
  char s2[] = "Hello,^world!";
  s21_size_t n = 14;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char s1[] = "";
  char s2[] = " ";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char s1[] = " 123456789";
  char s2[] = " 123456789";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char s1[] = "\0\0";
  char s2[] = "\0\0";
  s21_size_t n = 2;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char s1[] = "jij";
  char s2[] = "pok";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char s1[] = "jij";
  char s2[] = "pok";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "f";
  char s2[] = " ";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char s1[] = " ";
  char s2[] = "f";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char s1[] = " wd";
  char s2[] = " wdw";
  s21_size_t n = 4;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_12) {
  char s1[] = " wd";
  char s2[] = " wdw";
  s21_size_t n = 4;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_13) {
  char s1[] = "";
  char s2[] = "f";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *test = suite_create("S21_STRNCMP");
  TCase *seventh_group = tcase_create("s21_strncmp");
  tcase_add_test(seventh_group, strncmp_1);
  tcase_add_test(seventh_group, strncmp_2);
  tcase_add_test(seventh_group, strncmp_3);
  tcase_add_test(seventh_group, strncmp_4);
  tcase_add_test(seventh_group, strncmp_5);
  tcase_add_test(seventh_group, strncmp_6);
  tcase_add_test(seventh_group, strncmp_7);
  tcase_add_test(seventh_group, strncmp_8);
  tcase_add_test(seventh_group, strncmp_9);
  tcase_add_test(seventh_group, strncmp_10);
  tcase_add_test(seventh_group, strncmp_11);
  tcase_add_test(seventh_group, strncmp_12);
  tcase_add_test(seventh_group, strncmp_13);

  suite_add_tcase(test, seventh_group);
  return test;
}
