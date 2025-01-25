#include "s21_string_test.h"

START_TEST(memchr_1) {
  char str[] = "Tekst for testing my function";
  int c = 'f';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Tekst for testing my function";
  int c = 'f';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Tekst for testing my function";
  int c = ' ';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Tekst for testing my function";
  int c = ' ';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Tekst for testing my function";
  int c = 102;
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "Tekst for testing my function";
  int c = 102;
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "Tekst for testing my function";
  int c = '1';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "Tekst for testing my function";
  int c = '1';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "Tekst for testing my function";
  int c = 66;
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "Tekst for testing my function";
  int c = 66;
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_11) {
  char str[] = "Tekst for testing my function";
  int c = '\0';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_12) {
  char str[] = "Tekst for testing my function";
  int c = '\0';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_13) {
  char str[] = "525252525252525252";
  int c = '1';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_14) {
  char str[] = "525252525252525252";
  int c = '1';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_15) {
  char str[] = "525252525252525252";
  int c = '2';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_16) {
  char str[] = "525252525252525252";
  int c = '2';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_17) {
  char str[] = "525252525252525252";
  int c = 'N';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_18) {
  char str[] = "525252525252525252";
  int c = 'N';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_19) {
  char str[] = "hi\n\0m";
  int c = 'm';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_20) {
  char str[] = "hi\n\0m";
  int c = 'm';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_21) {
  char str[] = "hi\n\0m";
  int c = '\\';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_22) {
  char str[] = "hi\n\0m";
  int c = '\\';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_23) {
  char str[] = "111111111181111";
  int c = '8';
  s21_size_t n = 2;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_24) {
  char str[] = "111111111181111";
  int c = '8';
  s21_size_t n = 0;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_25) {
  char str[] = "Tekst for testing my function";
  int c = '\0';
  s21_size_t n = 5;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_26) {
  char str[] = "Tekst for testing my function";
  int c = 'i';
  s21_size_t n = 5;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_27)  //
{
  char str[] = "Tekst for testing my function";
  int c = '7';
  s21_size_t n = 15;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_28)  //
{
  char str[] = "Tekst for testing my function l";
  int c = 'l';
  s21_size_t n = 15;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

Suite *test_memchr() {
  Suite *test = suite_create("S21_MEMCHR");
  TCase *first_group = tcase_create("s21_memchr");
  tcase_add_test(first_group, memchr_1);
  tcase_add_test(first_group, memchr_2);
  tcase_add_test(first_group, memchr_3);
  tcase_add_test(first_group, memchr_4);
  tcase_add_test(first_group, memchr_5);
  tcase_add_test(first_group, memchr_6);
  tcase_add_test(first_group, memchr_7);
  tcase_add_test(first_group, memchr_8);
  tcase_add_test(first_group, memchr_9);
  tcase_add_test(first_group, memchr_10);
  tcase_add_test(first_group, memchr_11);
  tcase_add_test(first_group, memchr_12);
  tcase_add_test(first_group, memchr_13);
  tcase_add_test(first_group, memchr_14);
  tcase_add_test(first_group, memchr_15);
  tcase_add_test(first_group, memchr_16);
  tcase_add_test(first_group, memchr_17);
  tcase_add_test(first_group, memchr_18);
  tcase_add_test(first_group, memchr_19);
  tcase_add_test(first_group, memchr_20);
  tcase_add_test(first_group, memchr_21);
  tcase_add_test(first_group, memchr_22);
  tcase_add_test(first_group, memchr_23);
  tcase_add_test(first_group, memchr_24);
  tcase_add_test(first_group, memchr_25);
  tcase_add_test(first_group, memchr_26);
  tcase_add_test(first_group, memchr_27);
  tcase_add_test(first_group, memchr_28);

  suite_add_tcase(test, first_group);

  return test;
}
