#include "s21_string_test.h"

START_TEST(sprintf_c_1) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "new %% %c %% %cnew new%% %c";
  char a = 'a';
  char b = '\0';
  char c = '\n';
  int res1 = s21_sprintf(str1, str3, a, b, c);
  int res2 = sprintf(str2, str3, a, b, c);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "new %% %c %% %cnew new%% %c";
  char a = 'E';
  char b = '\0';
  char c = 'C';
  ck_assert_int_eq(s21_sprintf(str1, str3, a, b, c),
                   sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "new %% %+c %% %-cnew new%% % c";
  char a = 'a';
  char b = 'b';
  char c = 'C';
  int res1 = s21_sprintf(str1, str3, a, b, c);
  int res2 = sprintf(str2, str3, a, b, c);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_4) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "%lc new %c new %c new %c new %c";
  int a = 'A';
  int b = 'B';
  int c = 'C';
  int d = 'D';
  int e = 'E';
  ck_assert_int_eq(s21_sprintf(str1, str3, a, b, c, d, e),
                   sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_5) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "new %% %+ c %% %- cnew new%% % c";
  int a = 'a';
  int b = 'b';
  int c = 'C';
  int res1 = s21_sprintf(str1, str3, a, b, c);
  int res2 = sprintf(str2, str3, a, b, c);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_6) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "%2.3c new %-2.3c new %2.1lc new %-2.10lc new %-lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_7) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "%c new %c new %c new %c new %c";
  int res1 = sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c');
  int res2 = s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_c_8) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "%c new %c new %c new %c new %c";
  char a = '\0';
  int res1 = sprintf(str1, str3, a, a, a, a, a);
  int res2 = s21_sprintf(str2, str3, a, a, a, a, a);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_c_9) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 = "%c new %c new %c new %c new %c";
  int res1 = sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_c_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  char *str3 = "|%c|\n";
  int res1 = s21_sprintf(str1, str3, c);
  int res2 = sprintf(str2, str3, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '\0';
  char *str3 = "%c\n";
  int res1 = s21_sprintf(str1, str3, c);
  int res2 = sprintf(str2, str3, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = 'A';
  char *str3 = "%lc";
  int res1 = s21_sprintf(str1, str3, (unsigned long)c);
  int res2 = sprintf(str2, str3, (unsigned long)c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%%\n%d";
  int res1 = s21_sprintf(str1, str3, 1);
  int res2 = sprintf(str2, str3, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%%%%%% %d";
  int res1 = s21_sprintf(str1, str3, 1);
  int res2 = sprintf(str2, str3, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_c() {
  Suite *test = suite_create("S21_SPRINTF_C");
  TCase *first_group_sprintf = tcase_create("s21_sprintf_c");
  tcase_add_test(first_group_sprintf, sprintf_c_1);
  tcase_add_test(first_group_sprintf, sprintf_c_2);
  tcase_add_test(first_group_sprintf, sprintf_c_3);
  tcase_add_test(first_group_sprintf, sprintf_c_4);
  tcase_add_test(first_group_sprintf, sprintf_c_5);
  tcase_add_test(first_group_sprintf, sprintf_c_6);
  tcase_add_test(first_group_sprintf, sprintf_c_7);
  tcase_add_test(first_group_sprintf, sprintf_c_8);
  tcase_add_test(first_group_sprintf, sprintf_c_9);
  tcase_add_test(first_group_sprintf, sprintf_c_10);
  tcase_add_test(first_group_sprintf, sprintf_c_11);
  tcase_add_test(first_group_sprintf, sprintf_c_12);
  tcase_add_test(first_group_sprintf, sprintf_c_13);
  tcase_add_test(first_group_sprintf, sprintf_c_14);

  suite_add_tcase(test, first_group_sprintf);
  return test;
}