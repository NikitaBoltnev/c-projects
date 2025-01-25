#include "s21_string_test.h"
START_TEST(strrchr_1) {
  char s1[] = "12345";
  int sym = '5';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_2) {
  char s1[] = "12345";
  int sym = '9';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_3) {
  char s1[] = "12";
  int sym = '\0';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST
START_TEST(strrchr_4) {
  char s1[] = "\0\0\0";
  int sym = '\0';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_5) {
  char s1[] = "Hello, my name is Kate";
  int sym = 'm';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_6) {
  char s1[] = "Hello, my name is Kate";
  int sym = '\0';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_7) {
  char s1[] = "Hello, my name is Kate";
  int sym = '0';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_8) {
  char s1[] = " ";
  int sym = '^';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

START_TEST(strrchr_9) {
  char s1[] = "hello\n";
  int sym = '\n';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}

START_TEST(strrchr_10) {
  char s1[] = "hello\t";
  int sym = '\t';
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}

START_TEST(strrchr_11) {
  char s1[] = "Hello, my name is Kate";
  int sym = 33;
  ck_assert_pstr_eq(strrchr(s1, sym), s21_strrchr(s1, sym));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *test = suite_create("S21_STRRCHR");
  TCase *thirteenth_group = tcase_create("s21_strrchr");
  tcase_add_test(thirteenth_group, strrchr_1);
  tcase_add_test(thirteenth_group, strrchr_2);
  tcase_add_test(thirteenth_group, strrchr_3);
  tcase_add_test(thirteenth_group, strrchr_4);
  tcase_add_test(thirteenth_group, strrchr_5);
  tcase_add_test(thirteenth_group, strrchr_6);
  tcase_add_test(thirteenth_group, strrchr_7);
  tcase_add_test(thirteenth_group, strrchr_8);
  tcase_add_test(thirteenth_group, strrchr_9);
  tcase_add_test(thirteenth_group, strrchr_10);
  tcase_add_test(thirteenth_group, strrchr_11);

  suite_add_tcase(test, thirteenth_group);
  return test;
}
