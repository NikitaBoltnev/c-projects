#include "s21_string_test.h"
START_TEST(strpbrk_1) {
  char s1[] = "12345";
  char s2[] = "5";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, there!";
  char s2[] = "There, hello?";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "Hello, there!";
  char s2[] = "Hello, there!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "3";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "";
  char s2[] = "3";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_7) {
  char s1[] = "3";
  char s2[] = "\0";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_8) {
  char s1[] = "\0";
  char s2[] = "\0";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_9) {
  char s1[] = "12\03";
  char s2[] = "\03";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_10) {
  char s1[] = "1234567890123456789000000";
  char s2[] = "098765098765";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *test = suite_create("S21_STRPBRK");
  TCase *twelvth_group = tcase_create("s21_strpbrk");
  tcase_add_test(twelvth_group, strpbrk_1);
  tcase_add_test(twelvth_group, strpbrk_2);
  tcase_add_test(twelvth_group, strpbrk_3);
  tcase_add_test(twelvth_group, strpbrk_4);
  tcase_add_test(twelvth_group, strpbrk_5);
  tcase_add_test(twelvth_group, strpbrk_6);
  tcase_add_test(twelvth_group, strpbrk_7);
  tcase_add_test(twelvth_group, strpbrk_8);
  tcase_add_test(twelvth_group, strpbrk_9);
  tcase_add_test(twelvth_group, strpbrk_10);

  suite_add_tcase(test, twelvth_group);
  return test;
}
