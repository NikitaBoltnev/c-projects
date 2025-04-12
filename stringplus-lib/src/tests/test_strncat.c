#include "s21_string_test.h"

START_TEST(strncat_1) {
  char str1[25] = "Tekst for test";
  char str2[25] = "Tekst for test";
  char str3[] = "New new new";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_2) {
  char str1[20] = "Tekst for test";
  char str2[20] = "Tekst for test";
  char str3[] = "New new new";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_3) {
  char str1[20] = "Tekst for test";
  char str2[20] = "Tekst for test";
  char str3[] = "New new new";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_4) {
  char str1[30] = "Tekst for test";
  char str2[30] = "Tekst for test";
  char str3[] = "New new new";
  s21_size_t n = sizeof(str3);
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_5) {
  char str1[30] = "Tekst \0for test";
  char str2[30] = "Tekst \0for test";
  char str3[] = "New new new";
  s21_size_t n = 9;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_6) {
  char str1[30] = "";
  char str2[30] = "";
  char str3[] = "New new new";
  s21_size_t n = 9;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_7) {
  char str1[30] = "Tekst for test";
  char str2[30] = "Tekst for test";
  char str3[] = "";
  s21_size_t n = 9;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_8) {
  char str1[30] = "Tekst for test";
  char str2[30] = "Tekst for test";
  char str3[] = "\0";
  s21_size_t n = 9;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_9) {
  char str1[30] = "Tekst for test";
  char str2[30] = "Tekst for test";
  char str3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_10) {
  char str1[30] = "\n\0\n\n\0";
  char str2[30] = "\n\0\n\n\0";
  char str3[] = "$f$";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_11) {
  char str1[70] = "Tekst for test\0\0";
  char str2[70] = "Tekst for test\0\0";
  char str3[] = "New new new new new new";
  s21_size_t n = sizeof(str3);
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_12) {
  char str1[25] = "Tekst for test";
  char str2[25] = "Tekst for test";
  char str3[] = "\0\0";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_13) {
  char str1[25] = "Tekst for test";
  char str2[25] = "Tekst for test";
  char str3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_14) {
  char str1[25] = "Tekst for test";
  char str2[25] = "Tekst for test";
  char str3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_15) {
  char str1[25] = "";
  char str2[25] = "";
  char str3[] = "";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_16) {
  char str1[25] = "";
  char str2[25] = "";
  char str3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_17) {
  char str1[25] = "\0Start test";
  char str2[25] = "\0Start test";
  char str3[] = "\0New";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

Suite *test_strncat() {
  Suite *test = suite_create("S21_STRNCAT");
  TCase *fifth_group = tcase_create("s21_strncat");
  tcase_add_test(fifth_group, strncat_1);
  tcase_add_test(fifth_group, strncat_2);
  tcase_add_test(fifth_group, strncat_3);
  tcase_add_test(fifth_group, strncat_4);
  tcase_add_test(fifth_group, strncat_5);
  tcase_add_test(fifth_group, strncat_6);
  tcase_add_test(fifth_group, strncat_7);
  tcase_add_test(fifth_group, strncat_8);
  tcase_add_test(fifth_group, strncat_9);
  tcase_add_test(fifth_group, strncat_10);
  tcase_add_test(fifth_group, strncat_11);
  tcase_add_test(fifth_group, strncat_12);
  tcase_add_test(fifth_group, strncat_13);
  tcase_add_test(fifth_group, strncat_14);
  tcase_add_test(fifth_group, strncat_15);
  tcase_add_test(fifth_group, strncat_16);
  tcase_add_test(fifth_group, strncat_17);
  suite_add_tcase(test, fifth_group);
  return test;
}