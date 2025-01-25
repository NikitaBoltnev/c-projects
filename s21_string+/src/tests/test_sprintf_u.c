#include "s21_string_test.h"

START_TEST(sprintf_u_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New %u New";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-u New %-u New%-uNew";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-u New %-u New%-uNew";
  unsigned int a = 017;
  unsigned int b = 012;
  unsigned int c = 07464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-u New %-u New %-u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%lu New %lu New %hu New %hu";
  long unsigned int a = 3088675747373646;
  long unsigned b = 33030030303;
  unsigned short c = 22600;
  unsigned short d = 120;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%3u New %5u New %10u";
  unsigned int a = 3015;
  unsigned int b = 01234;
  unsigned int c = 99;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%.2u New %.4u New %0.3u New %.u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 38;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-10.5u New %-.8u New %-7u New %-.u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%u New %3.u New %5.7u New %10u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%u New %3.u New %5.7u New %10u New %.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 3261;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New %lu";
  unsigned long int a = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  char format_str[100] = "% u";
  unsigned int u = 5;
  int res1 = sprintf(str1, format_str, u);
  int res2 = s21_sprintf(str2, format_str, u);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_u_13) {
  char str1[1024];
  char str2[1024];
  char *str3 = "%+u New %+3.u New %+5.7u New %+10u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  int res1 = sprintf(str1, str3, a, b, c, d);
  int res2 = s21_sprintf(str2, str3, a, b, c, d);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_u_14) {
  char str1[1024];
  char str2[1024];
  char *str3 = "% u New % 3.u New % 5.7u New % 10u New %.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 23;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_u_15) {
  char str1[1024];
  char str2[1024];
  char *str3 = "%+u New %+3.u New %+5.7u New %+10u New %+.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 3261;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_u_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%- u New %-15u New %-15u New %-u";
  unsigned int a = -3231;
  unsigned int b = -3231;
  unsigned int c = 3231;
  unsigned int d = 3231;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%u New %u New%uNew";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_18) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int a = UINT_MAX;
  char *str3 = "%+-15.20u";
  int res1 = s21_sprintf(str1, str3, a);
  int res2 = sprintf(str2, str3, a);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_19) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned long int a = ULLONG_MAX;
  char *str3 = "|%+ 15.20lu|\n";
  int res1 = s21_sprintf(str1, str3, a);
  int res2 = sprintf(str2, str3, a);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_20) {
  char str1[1024];
  char str2[1024];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_21) {
  char str1[1024];
  char str2[1024];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_22) {
  char str1[1024];
  char str2[1024];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_23) {
  char str1[1024];
  char str2[1024];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_u_24) {
  char str1[1024];
  char str2[1024];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_u_25) {
  char str1[1024];
  char str2[1024];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_26) {
  char str1[1024];
  char str2[1024];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_27) {
  char str1[1024];
  char str2[1024];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_28) {
  char str1[1024];
  char str2[1024];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_29) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_30) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_u() {
  Suite *test = suite_create("S21_SPRINTF_U");
  TCase *second_group_sprintf = tcase_create("s21_sprintf_u");
  tcase_add_test(second_group_sprintf, sprintf_u_1);
  tcase_add_test(second_group_sprintf, sprintf_u_2);
  tcase_add_test(second_group_sprintf, sprintf_u_3);
  tcase_add_test(second_group_sprintf, sprintf_u_4);
  tcase_add_test(second_group_sprintf, sprintf_u_5);
  tcase_add_test(second_group_sprintf, sprintf_u_6);
  tcase_add_test(second_group_sprintf, sprintf_u_7);
  tcase_add_test(second_group_sprintf, sprintf_u_8);
  tcase_add_test(second_group_sprintf, sprintf_u_9);
  tcase_add_test(second_group_sprintf, sprintf_u_10);
  tcase_add_test(second_group_sprintf, sprintf_u_11);
  tcase_add_test(second_group_sprintf, sprintf_u_12);
  tcase_add_test(second_group_sprintf, sprintf_u_13);
  tcase_add_test(second_group_sprintf, sprintf_u_14);
  tcase_add_test(second_group_sprintf, sprintf_u_15);
  tcase_add_test(second_group_sprintf, sprintf_u_16);
  tcase_add_test(second_group_sprintf, sprintf_u_17);
  tcase_add_test(second_group_sprintf, sprintf_u_18);
  tcase_add_test(second_group_sprintf, sprintf_u_19);
  tcase_add_test(second_group_sprintf, sprintf_u_20);
  tcase_add_test(second_group_sprintf, sprintf_u_21);
  tcase_add_test(second_group_sprintf, sprintf_u_22);
  tcase_add_test(second_group_sprintf, sprintf_u_23);
  tcase_add_test(second_group_sprintf, sprintf_u_24);
  tcase_add_test(second_group_sprintf, sprintf_u_25);
  tcase_add_test(second_group_sprintf, sprintf_u_26);
  tcase_add_test(second_group_sprintf, sprintf_u_27);
  tcase_add_test(second_group_sprintf, sprintf_u_28);
  tcase_add_test(second_group_sprintf, sprintf_u_29);
  tcase_add_test(second_group_sprintf, sprintf_u_30);

  suite_add_tcase(test, second_group_sprintf);
  return test;
}