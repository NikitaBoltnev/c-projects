#include "s21_string_test.h"

START_TEST(strcspn_1) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] = "1234567";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "1234567";
  char s2[] = "76";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "1234562er7";
  char s2[] = "76";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "";
  char s2[] = "4";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "4";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "13\0\0";
  char s2[] = "2\0";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "13\0\0a";
  char s2[] = "a";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "99";
  char s2[] = "9";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "123456";
  char s2[] = "123456";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "v";
  char s2[] = "vjfjjfm bv fjflsvvlwkf";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_13) {
  char s1[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  char s2[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_14) {
  char s1[] = "kkdjfk";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_15) {
  char s1[] = "67";
  char s2[] = "1234567";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_16) {
  char s1[] = "67";
  char s2[] = "6\07kfkdjfos";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *test = suite_create("S21_STRCSPN");
  TCase *ninth_group = tcase_create("s21_strcspn");
  tcase_add_test(ninth_group, strcspn_1);
  tcase_add_test(ninth_group, strcspn_2);
  tcase_add_test(ninth_group, strcspn_3);
  tcase_add_test(ninth_group, strcspn_4);
  tcase_add_test(ninth_group, strcspn_5);
  tcase_add_test(ninth_group, strcspn_6);
  tcase_add_test(ninth_group, strcspn_7);
  tcase_add_test(ninth_group, strcspn_8);
  tcase_add_test(ninth_group, strcspn_9);
  tcase_add_test(ninth_group, strcspn_10);
  tcase_add_test(ninth_group, strcspn_11);
  tcase_add_test(ninth_group, strcspn_12);
  tcase_add_test(ninth_group, strcspn_13);
  tcase_add_test(ninth_group, strcspn_14);
  tcase_add_test(ninth_group, strcspn_15);
  tcase_add_test(ninth_group, strcspn_16);

  suite_add_tcase(test, ninth_group);
  return test;
}
