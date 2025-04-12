#include "s21_string_test.h"
START_TEST(strncpy_1) {
  char s1[10] = "Hi there";
  char s2[10] = "Hello";
  char s3[10] = "Hi there";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_2) {
  char s1[10] = "Hi there";
  char s2[10] = " ";
  char s3[10] = "Hi there";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_3) {
  char s1[50] = "";
  char s2[50] = "I can't stop writing code ";
  char s3[50] = "";
  s21_size_t n = s21_strlen(s2);
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_4) {
  char s1[10] = "23\032";
  char s2[10] = "";
  char s3[10] = "23\032";
  s21_size_t n = 8;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_5) {
  char s1[5] = "";
  char s2[5] = "\0";
  char s3[5] = "";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_6) {
  char s1[5] = " ";
  char s2[5] = " ";
  char s3[] = " ";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_7) {
  char s1[5] = "";
  char s2[5] = "\0\0";
  char s3[5] = "";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_8) {
  char s1[15] = "Hello how a u";
  char s2[15] = "Hello";
  char s3[15] = "Hello how a u";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_9) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "Hello";
  s21_size_t n = s21_strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

START_TEST(strncpy_10) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s2, n), s21_strncpy(s3, s2, n));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *test = suite_create("S21_STRNCPY");
  TCase *eigth_group = tcase_create("s21_strncpy");
  tcase_add_test(eigth_group, strncpy_1);
  tcase_add_test(eigth_group, strncpy_2);
  tcase_add_test(eigth_group, strncpy_3);
  tcase_add_test(eigth_group, strncpy_4);
  tcase_add_test(eigth_group, strncpy_5);
  tcase_add_test(eigth_group, strncpy_6);
  tcase_add_test(eigth_group, strncpy_7);
  tcase_add_test(eigth_group, strncpy_8);
  tcase_add_test(eigth_group, strncpy_9);
  tcase_add_test(eigth_group, strncpy_10);

  suite_add_tcase(test, eigth_group);
  return test;
}
