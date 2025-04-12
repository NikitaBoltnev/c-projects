#include "s21_string_test.h"

START_TEST(sprintf_d_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%d New %d New %d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%+d New %+d New %+d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-2d New %-2d New %-2d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%ld New %ld New %hd New %hd";
  long int a = 3088675747373646;
  long b = 33030030303;
  short int c = 22600;
  short d = -120;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%3d New %5d New %10d";
  int a = -3015;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%6.5d New %.23d New %3.d New %d %.6d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -38;
  int e = -100;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-10.5d New %-.8d New %-7d New %-.d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%d New %.d New %.0d New %d New %.d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -2939;
  int e = -0123;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "% d New % 3.d New % 5.7d New % 10d New %.d";
  int a = -32;
  int b = -8899;
  int c = -91918;
  int d = -32311;
  int e = -23;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%+d New %+3.d New %+5.7d New %+10d New %+.d";
  int a = 32;
  int b = 8899;
  int c = 91918;
  int d = 32311;
  int e = 3261;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_d_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 123;
  char *str3 = "%d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *str3 = "%d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *str3 = "%+dn";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *str3 = "% d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 0;
  char *str3 = "%+d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 5346457;
  char *str3 = "%15d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 6878;
  char *str3 = "%1d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_18) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -315;
  char *str3 = "%4d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_19) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -14566;
  char *str3 = "%.1d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_20) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 56368;
  char *str3 = "%.10d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_21) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -67567;
  char *str3 = "%.6d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_22) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 99999;
  char *str3 = "%15.10d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_23) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12;
  char *str3 = "%d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_24) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;

  char *str3 = "%d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_25) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;

  char *str3 = "%-d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_26) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *str3 = "%+-20.15d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_27) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *str3 = "%+-15.20d";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_d() {
  Suite *test = suite_create("S21_SPRINTF_D");
  TCase *fourt_group_sprintf = tcase_create("s21_sprintf_d");

  tcase_add_test(fourt_group_sprintf, sprintf_d_1);
  tcase_add_test(fourt_group_sprintf, sprintf_d_2);
  tcase_add_test(fourt_group_sprintf, sprintf_d_3);
  tcase_add_test(fourt_group_sprintf, sprintf_d_4);
  tcase_add_test(fourt_group_sprintf, sprintf_d_5);
  tcase_add_test(fourt_group_sprintf, sprintf_d_6);
  tcase_add_test(fourt_group_sprintf, sprintf_d_7);
  tcase_add_test(fourt_group_sprintf, sprintf_d_8);
  tcase_add_test(fourt_group_sprintf, sprintf_d_9);
  tcase_add_test(fourt_group_sprintf, sprintf_d_10);
  tcase_add_test(fourt_group_sprintf, sprintf_d_11);
  tcase_add_test(fourt_group_sprintf, sprintf_d_12);
  tcase_add_test(fourt_group_sprintf, sprintf_d_13);
  tcase_add_test(fourt_group_sprintf, sprintf_d_14);
  tcase_add_test(fourt_group_sprintf, sprintf_d_15);
  tcase_add_test(fourt_group_sprintf, sprintf_d_16);
  tcase_add_test(fourt_group_sprintf, sprintf_d_17);
  tcase_add_test(fourt_group_sprintf, sprintf_d_18);
  tcase_add_test(fourt_group_sprintf, sprintf_d_19);
  tcase_add_test(fourt_group_sprintf, sprintf_d_20);
  tcase_add_test(fourt_group_sprintf, sprintf_d_21);
  tcase_add_test(fourt_group_sprintf, sprintf_d_22);
  tcase_add_test(fourt_group_sprintf, sprintf_d_23);
  tcase_add_test(fourt_group_sprintf, sprintf_d_24);
  tcase_add_test(fourt_group_sprintf, sprintf_d_25);
  tcase_add_test(fourt_group_sprintf, sprintf_d_26);
  tcase_add_test(fourt_group_sprintf, sprintf_d_27);

  suite_add_tcase(test, fourt_group_sprintf);
  return test;
}