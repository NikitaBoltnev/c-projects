#include "s21_string_test.h"

START_TEST(test_strstr_1) {
  char haystack_1[] = "Hello, world!";
  char needle_1[] = "world";
  ck_assert_pstr_eq(s21_strstr(haystack_1, needle_1),
                    strstr(haystack_1, needle_1));
}
END_TEST

START_TEST(test_strstr_2) {
  char haystack_2[] = "This is a test string";
  char needle_2[] = "test";
  ck_assert_pstr_eq(s21_strstr(haystack_2, needle_2),
                    strstr(haystack_2, needle_2));
}
END_TEST

START_TEST(test_strstr_3) {
  char haystack_3[] = "No needle here";
  char needle_3[] = "needle";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_4) {
  char haystack_4[] = "Short";
  char needle_4[] = "ThisIsTooLong";
  ck_assert_pstr_eq(s21_strstr(haystack_4, needle_4),
                    strstr(haystack_4, needle_4));
}
END_TEST

START_TEST(test_strstr_5) {
  char haystack_5[] = "RepeatRepeatRepeat";
  char needle_5[] = "Repeat";
  ck_assert_pstr_eq(s21_strstr(haystack_5, needle_5),
                    strstr(haystack_5, needle_5));
}
END_TEST

START_TEST(test_strstr_6) {
  char haystack_6[] = "EmptyNeedle";
  char needle_6[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack_6, needle_6),
                    strstr(haystack_6, needle_6));
}
END_TEST

START_TEST(test_strstr_7) {
  char haystack_1[] = "Hello, world!";
  char needle_1[] = "Hello, world!";
  ck_assert_pstr_eq(s21_strstr(haystack_1, needle_1),
                    strstr(haystack_1, needle_1));
}
END_TEST

START_TEST(test_strstr_8) {
  char haystack_3[] = "No needle here";
  char needle_3[] = "needley";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_9) {
  char haystack_3[] = "";
  char needle_3[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_10) {
  char haystack_3[] = "Hello";
  char needle_3[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_11) {
  char haystack_3[] = "";
  char needle_3[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_12) {
  char haystack_3[] = "Hello";
  char needle_3[] = "\0";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_13) {
  char haystack_3[] = "HelloTest";
  char needle_3[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

START_TEST(test_strstr_14) {
  char haystack_3[] = "TestHello";
  char needle_3[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(haystack_3, needle_3),
                    strstr(haystack_3, needle_3));
}
END_TEST

Suite *test_strstr(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_strstr");
  core = tcase_create("Core");

  tcase_add_test(core, test_strstr_1);
  tcase_add_test(core, test_strstr_2);
  tcase_add_test(core, test_strstr_3);
  tcase_add_test(core, test_strstr_4);
  tcase_add_test(core, test_strstr_5);
  tcase_add_test(core, test_strstr_6);
  tcase_add_test(core, test_strstr_7);
  tcase_add_test(core, test_strstr_8);
  tcase_add_test(core, test_strstr_9);
  tcase_add_test(core, test_strstr_10);
  tcase_add_test(core, test_strstr_11);
  tcase_add_test(core, test_strstr_12);
  tcase_add_test(core, test_strstr_13);
  tcase_add_test(core, test_strstr_14);

  suite_add_tcase(suite, core);

  return (suite);
}
