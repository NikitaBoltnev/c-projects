#include "s21_string_test.h"
START_TEST(strlen_1) {
  char str[] = "Hello,world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] = "28']@&he*l*l*owhyg wunuhwhu *^$@@sw wduwhuwhuh ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "28']@&he*l*l*owhyg wunuhwhu *^$@@sw wduwhuwhuh ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "\n\t\t\n okoksl;\n\n**\t \t ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] = "\0\0\0\n kmk";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "I was going throughghhthhh 73849 *** jem \n\t\0 mf4mrfrg";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = " ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  char str[] = "          riju ij4ijri90990&&^@%$!±Q";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] =
      "          riju ij4ijri90990&&^@%$!±Q  \n\n\t\0 434***          )";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_10) {
  char str[] = "  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_strlen(void) {
  Suite *test = suite_create("S21_STRLEN");
  TCase *eleventh_group = tcase_create("s21_strlen");
  tcase_add_test(eleventh_group, strlen_1);
  tcase_add_test(eleventh_group, strlen_2);
  tcase_add_test(eleventh_group, strlen_3);
  tcase_add_test(eleventh_group, strlen_4);
  tcase_add_test(eleventh_group, strlen_5);
  tcase_add_test(eleventh_group, strlen_6);
  tcase_add_test(eleventh_group, strlen_7);
  tcase_add_test(eleventh_group, strlen_8);
  tcase_add_test(eleventh_group, strlen_9);
  tcase_add_test(eleventh_group, strlen_10);
  tcase_add_test(eleventh_group, strlen_11);

  suite_add_tcase(test, eleventh_group);
  return test;
}
