#include "s21_string_test.h"

START_TEST(memcpy_1) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "New tekst";
  s21_size_t n = 9;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "New tekst";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_3) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "Test";
  s21_size_t n = 5;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "New";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_6) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  char str3[] = "";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_7) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "Tekst";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_8) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "Tekst";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_9) {
  char str1[] = "Tekst\0 for test";
  char str2[] = "Tekst\0 for test";
  char str3[] = "New tekst";
  s21_size_t n = s21_strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(memcpy_10) {
  char str1[] = "Tekst\0 for test";
  char str2[] = "Tekst\0 for test";
  char str3[] = "New";
  s21_size_t n = sizeof(str3);
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

Suite *test_memcpy() {
  Suite *test = suite_create("S21_MEMCPY");
  TCase *third_group = tcase_create("s21_memcpy");
  tcase_add_test(third_group, memcpy_1);
  tcase_add_test(third_group, memcpy_2);
  tcase_add_test(third_group, memcpy_3);
  tcase_add_test(third_group, memcpy_4);
  tcase_add_test(third_group, memcpy_5);
  tcase_add_test(third_group, memcpy_6);
  tcase_add_test(third_group, memcpy_7);
  tcase_add_test(third_group, memcpy_8);
  tcase_add_test(third_group, memcpy_9);
  tcase_add_test(third_group, memcpy_10);
  suite_add_tcase(test, third_group);

  return test;
}