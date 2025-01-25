#include "s21_string_test.h"

START_TEST(test_strrchr_1) {
  char str1[] = "Hello, World!";
  int ch1 = 'W';
  ck_assert_pstr_eq(s21_strchr(str1, ch1), strchr(str1, ch1));
}
END_TEST

START_TEST(test_strrchr_2) {
  char str2[] = "Testing the function";
  int ch2 = 't';
  ck_assert_pstr_eq(s21_strchr(str2, ch2), strchr(str2, ch2));
}
END_TEST

START_TEST(test_strrchr_3) {
  char str3[] = "No ch here";
  int ch3 = 'z';
  ck_assert_pstr_eq(s21_strchr(str3, ch3), strchr(str3, ch3));
}
END_TEST

START_TEST(test_strrchr_4) {
  char str4[] = "End of string\0Hidden";
  int ch4 = '\0';
  ck_assert_pstr_eq(s21_strchr(str4, ch4), strchr(str4, ch4));
}
END_TEST

START_TEST(test_strrchr_5) {
  char str5[] = "     ";
  int ch5 = ' ';
  ck_assert_pstr_eq(s21_strchr(str5, ch5), strchr(str5, ch5));
}
END_TEST

START_TEST(test_strrchr_6) {
  char str6[] = "12345983";
  int ch6 = '3';
  ck_assert_pstr_eq(s21_strchr(str6, ch6), strchr(str6, ch6));
}
END_TEST

START_TEST(test_strrchr_7) {
  char str7[] = "///...///";
  int ch7 = '.';
  ck_assert_pstr_eq(s21_strchr(str7, ch7), strchr(str7, ch7));
}
END_TEST

START_TEST(test_strrchr_8) {
  char str8[] = "4515162342";
  int ch8 = '5';
  ck_assert_pstr_eq(s21_strchr(str8, ch8), strchr(str8, ch8));
}
END_TEST

START_TEST(test_strrchr_9) {
  char str9[] = "hello world";
  int ch9 = 'o';
  ck_assert_pstr_eq(s21_strchr(str9, ch9), strchr(str9, ch9));
}
END_TEST

START_TEST(test_strrchr_10) {
  char str10[] = "privet +++11";
  int ch10 = '+';
  ck_assert_pstr_eq(s21_strchr(str10, ch10), strchr(str10, ch10));
}
END_TEST

START_TEST(test_strrchr_11) {
  char str1[] = "Hello, World!";
  int ch11 = '\0';
  ck_assert_pstr_eq(s21_strchr(str1, ch11), strchr(str1, ch11));
}
END_TEST

START_TEST(test_strrchr_12) {
  char str1[] = "Hello, World!";
  int ch12 = 33;
  ck_assert_pstr_eq(s21_strchr(str1, ch12), strchr(str1, ch12));
}
END_TEST

Suite *test_strchr(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_strchr");
  core = tcase_create("Core");

  tcase_add_test(core, test_strrchr_1);
  tcase_add_test(core, test_strrchr_2);
  tcase_add_test(core, test_strrchr_3);
  tcase_add_test(core, test_strrchr_4);
  tcase_add_test(core, test_strrchr_5);
  tcase_add_test(core, test_strrchr_6);
  tcase_add_test(core, test_strrchr_7);
  tcase_add_test(core, test_strrchr_8);
  tcase_add_test(core, test_strrchr_9);
  tcase_add_test(core, test_strrchr_10);
  tcase_add_test(core, test_strrchr_11);
  tcase_add_test(core, test_strrchr_12);

  suite_add_tcase(suite, core);

  return (suite);
}
