#include "s21_string_test.h"

START_TEST(memcmp_1) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst for test";
  s21_size_t n = 14;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst1 for test";
  s21_size_t n = 0;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst1 for test";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "Tekst for test";
  char str2[] = "\0";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "Tekst for test";
  char str2[] = "Tekst1 for test";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

END_TEST

START_TEST(memcmp_6) {
  char str1[] = "12345";
  char str2[] = "12345";
  s21_size_t n = 0;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "12345";
  char str2[] = "12345";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "12345";
  char str2[] = "12345";
  s21_size_t n = 5;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "12345";
  char str2[] = "12345";
  s21_size_t n = 6;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "123f5";
  char str2[] = "12345";
  s21_size_t n = 2;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_11) {
  char str1[] = "12345G";
  char str2[] = "\0";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_12) {
  char str1[] = "12345G";
  char str2[] = " ";
  s21_size_t n = 1;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_13) {
  char str1[] = "12345\0 67";
  char str2[] = "12345\0 67";
  s21_size_t n = 9;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_14) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_15) {
  char str1[] = "12345\0 67";
  char str2[] = "12345\0 76";
  s21_size_t n = 9;
  int res1 = memcmp(str1, str2, n);
  int res2 = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_memcmp() {  // почему указатель
  Suite *test = suite_create("S21_MEMCMP");
  TCase *second_group = tcase_create("s21_memcmp");
  tcase_add_test(second_group, memcmp_1);
  tcase_add_test(second_group, memcmp_2);
  tcase_add_test(second_group, memcmp_3);
  tcase_add_test(second_group, memcmp_4);
  tcase_add_test(second_group, memcmp_5);
  tcase_add_test(second_group, memcmp_6);
  tcase_add_test(second_group, memcmp_7);
  tcase_add_test(second_group, memcmp_8);
  tcase_add_test(second_group, memcmp_9);
  tcase_add_test(second_group, memcmp_10);
  tcase_add_test(second_group, memcmp_11);
  tcase_add_test(second_group, memcmp_12);
  tcase_add_test(second_group, memcmp_13);
  tcase_add_test(second_group, memcmp_14);
  tcase_add_test(second_group, memcmp_15);

  suite_add_tcase(test, second_group);

  return test;
}