#include "s21_string_test.h"

START_TEST(sprintf_s_1) {
  char str1[1024] = "ndnngdfofidfngifdlsfgnfjdnfgd";
  char str2[1024] = "ndnngdfofidfngifdlsfgnfjdnfgd";
  char *str3 = "Hi world";
  char *str4 = "!%s!";
  ck_assert_int_eq(sprintf(str1, str4, str3), s21_sprintf(str2, str4, str3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str4 = "New %s New";
  char *str3 = "test test test \n test";
  ck_assert_int_eq(sprintf(str1, str4, str3), s21_sprintf(str2, str4, str3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%s New %s New %s";
  char *str4 = "test1 test1";
  char *str5 = "test2 test2";
  char *str6 = "test3 test3";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6),
                   s21_sprintf(str2, str3, str4, str5, str6));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%s New %s New %s";
  char *str4 = "test1 test1";
  char *str5 = "test2 test2";
  char *str6 = "test3 test3";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6),
                   s21_sprintf(str2, str3, str4, str5, str6));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New %s New";
  char *str4 = "3wtf80";

  ck_assert_int_eq(sprintf(str1, str3, str4), s21_sprintf(str2, str3, str4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%3s New %5s New %10s";
  char *str4 = "test test";
  char *str5 = "test test test";
  char *str6 = "test test test test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6),
                   s21_sprintf(str2, str3, str4, str5, str6));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%6.5s New %.23s New %3.s New %.0s";
  char *str4 = "test test test";
  char *str5 = "test test test test test test";
  char *str6 = "test";
  char *str7 = "test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7),
                   s21_sprintf(str2, str3, str4, str5, str6, str7));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%-10.5s New %-.8s New %-7s New %-.s";
  char *str4 = "test test test";
  char *str5 = "test test test test test test";
  char *str6 = "test";
  char *str7 = "test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7),
                   s21_sprintf(str2, str3, str4, str5, str6, str7));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%s New %.s New %s New %s New %.s";
  char *str4 = "test test test";
  char *str5 = "test test test test test test";
  char *str6 = "test";
  char *str7 = "test test test";
  char *str8 = "test test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7, str8),
                   s21_sprintf(str2, str3, str4, str5, str6, str7, str8));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%+s New %+3.s New %5.7s New %10s";
  char *str4 = "test test test";
  char *str5 = "test test test test test test";
  char *str6 = "test";
  char *str7 = "test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7),
                   s21_sprintf(str2, str3, str4, str5, str6, str7));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "% s New % 3.s New % 5.7s New % 10s New %.s";
  char *str4 = "test test test";
  char *str5 = "test test test test test test";
  char *str6 = "test";
  char *str7 = "test test test";
  char *str8 = "test test test";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7, str8),
                   s21_sprintf(str2, str3, str4, str5, str6, str7, str8));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%+s New %+3.s New %+5.7s New %+10s New %+.s";
  char *str4 = "\0";
  char *str5 = "\0";
  char *str6 = "\0";
  char *str7 = "\0";
  char *str8 = "\0";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, str7, str8),
                   s21_sprintf(str2, str3, str4, str5, str6, str7, str8));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%s %s %s %% %d";
  char *str4 = "This";
  char *str5 = "\0";
  int c = 65;
  char *str6 = "string";
  ck_assert_int_eq(sprintf(str1, str3, str4, str5, str6, c),
                   s21_sprintf(str2, str3, str4, str5, str6, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  char str3[10] = {'t', 'e', 's', 't'};
  int res1 =
      sprintf(str1, "1:%s 2:%10s 3:%.0s 4:%7.2s 5:%-10.3s 6:%5.3s 7:%-5.0s",
              "test", "test", "test", "test", "test", str3, str3);
  int res2 =
      s21_sprintf(str2, "1:%s 2:%10s 3:%.0s 4:%7.2s 5:%-10.3s 6:%5.3s 7:%-5.0s",
                  "test", "test", "test", "test", "test", str3, str3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_s_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "\0";
  char *str4 = "!%s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%.2s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_18) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%.s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_19) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%10.5s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_20) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%10.2s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_21) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%10.0s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_22) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%-5s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_23) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *str4 = "!%s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_24) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *str4 = "!%-10.6s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_25) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *str4 = "!%s!";
  int res1 = s21_sprintf(str1, str4, str3);
  int res2 = sprintf(str2, str4, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_s() {
  Suite *test = suite_create("S21_SPRINTF_S");
  TCase *fifth_group_sprintf = tcase_create("s21_sprintf_s");
  tcase_add_test(fifth_group_sprintf, sprintf_s_1);
  tcase_add_test(fifth_group_sprintf, sprintf_s_2);
  tcase_add_test(fifth_group_sprintf, sprintf_s_3);
  tcase_add_test(fifth_group_sprintf, sprintf_s_4);
  tcase_add_test(fifth_group_sprintf, sprintf_s_5);
  tcase_add_test(fifth_group_sprintf, sprintf_s_6);
  tcase_add_test(fifth_group_sprintf, sprintf_s_7);
  tcase_add_test(fifth_group_sprintf, sprintf_s_8);
  tcase_add_test(fifth_group_sprintf, sprintf_s_9);
  tcase_add_test(fifth_group_sprintf, sprintf_s_10);
  tcase_add_test(fifth_group_sprintf, sprintf_s_11);
  tcase_add_test(fifth_group_sprintf, sprintf_s_12);
  tcase_add_test(fifth_group_sprintf, sprintf_s_13);
  tcase_add_test(fifth_group_sprintf, sprintf_s_14);
  tcase_add_test(fifth_group_sprintf, sprintf_s_15);
  tcase_add_test(fifth_group_sprintf, sprintf_s_16);
  tcase_add_test(fifth_group_sprintf, sprintf_s_17);
  tcase_add_test(fifth_group_sprintf, sprintf_s_18);
  tcase_add_test(fifth_group_sprintf, sprintf_s_19);
  tcase_add_test(fifth_group_sprintf, sprintf_s_20);
  tcase_add_test(fifth_group_sprintf, sprintf_s_21);
  tcase_add_test(fifth_group_sprintf, sprintf_s_22);
  tcase_add_test(fifth_group_sprintf, sprintf_s_23);
  tcase_add_test(fifth_group_sprintf, sprintf_s_24);
  tcase_add_test(fifth_group_sprintf, sprintf_s_25);

  suite_add_tcase(test, fifth_group_sprintf);
  return test;
}
