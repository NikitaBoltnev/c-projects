#include "s21_string_test.h"

START_TEST(sprintf_f_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%f New %.f New %4f New %4.f New %5.10f!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "%f New %.f New %3f New %4.f New %5.10f$";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %25f!\nNew; %-15f!\nNew: %+15f";
  double num = 8364.4366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %-+ 25.5f!\nNew: %- 20.4f\nNew: %+ 16.6f!";
  double num = 837564.4753366;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: % 15f!\nNew: %-26f!\nNew: %+ 18f!";
  double num = -947.6785643;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_f_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %+- 10.2f!\nNew: %- 25.7f\nNew: %+- 18.4f!";
  double num = -947.6785643;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_f_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %10.5fNew: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %15.1fNew: %16.2fNew: %18.3f!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %10.4fNew: %25.5f!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %+ 18.0fNew: %+10.fNew: %+25.f!";
  double num = 48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %-15.4f!New: %-26.1f!New: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %15.13lf!New: %26.15lf!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %18.7f!New: %10.15f!New: %25.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %15.13lf!New: %26.15lf!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %18.7f!New: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %- 23.14f!New: %+ 25.15f!";
  double num = 365289.346;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
}
END_TEST

START_TEST(sprintf_f_18) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: % 15f!New: % -26f!New: %- 18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_19) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %+- 14f!New: %+ 10f!New: % +25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_20) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: % 14f!New: % -27f!New: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_21) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "New: %+- 16f!New: %+ 44f!New: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_22) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 123.34634;
  char *format = "!%f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_23) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -4534123.34634;
  char *format = "!%f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_24) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "!%f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_25) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487;
  char *format = "!%.0f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_26) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487.635;
  char *format = "!%.0f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_27) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "!%15.0f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_28) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "!%f!\n";
  int res1 = s21_sprintf(str1, format, 20, 2, x);
  int res2 = sprintf(str2, format, 20, 2, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_29) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00005;
  char *format = "!%+13f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_30) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "!%.0f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_31) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  char *format = "!%-+8.3f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_32) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -94634.452463574563;
  char *format = "!%+10f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_33) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  char *format = "!%+10.f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_34) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  char *format = "!%+ 30.10f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_35) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 4.1111e-30;
  char *format = "!%40.35f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_36) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "!%.2f!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_37) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 123.12345;
  char *format = "!%lf!\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_f() {
  Suite *test = suite_create("S21_SPRINTF_F");
  TCase *third_group_sprintf = tcase_create("s21_sprintf_f");
  tcase_add_test(third_group_sprintf, sprintf_f_1);
  tcase_add_test(third_group_sprintf, sprintf_f_2);
  tcase_add_test(third_group_sprintf, sprintf_f_3);
  tcase_add_test(third_group_sprintf, sprintf_f_4);
  tcase_add_test(third_group_sprintf, sprintf_f_5);
  tcase_add_test(third_group_sprintf, sprintf_f_6);
  tcase_add_test(third_group_sprintf, sprintf_f_7);
  tcase_add_test(third_group_sprintf, sprintf_f_8);
  tcase_add_test(third_group_sprintf, sprintf_f_9);
  tcase_add_test(third_group_sprintf, sprintf_f_10);
  tcase_add_test(third_group_sprintf, sprintf_f_11);
  tcase_add_test(third_group_sprintf, sprintf_f_12);
  tcase_add_test(third_group_sprintf, sprintf_f_13);
  tcase_add_test(third_group_sprintf, sprintf_f_14);
  tcase_add_test(third_group_sprintf, sprintf_f_15);
  tcase_add_test(third_group_sprintf, sprintf_f_16);
  tcase_add_test(third_group_sprintf, sprintf_f_17);
  tcase_add_test(third_group_sprintf, sprintf_f_18);
  tcase_add_test(third_group_sprintf, sprintf_f_19);
  tcase_add_test(third_group_sprintf, sprintf_f_20);
  tcase_add_test(third_group_sprintf, sprintf_f_21);
  tcase_add_test(third_group_sprintf, sprintf_f_22);
  tcase_add_test(third_group_sprintf, sprintf_f_23);
  tcase_add_test(third_group_sprintf, sprintf_f_24);
  tcase_add_test(third_group_sprintf, sprintf_f_25);
  tcase_add_test(third_group_sprintf, sprintf_f_26);
  tcase_add_test(third_group_sprintf, sprintf_f_27);
  tcase_add_test(third_group_sprintf, sprintf_f_28);
  tcase_add_test(third_group_sprintf, sprintf_f_29);
  tcase_add_test(third_group_sprintf, sprintf_f_30);
  tcase_add_test(third_group_sprintf, sprintf_f_31);
  tcase_add_test(third_group_sprintf, sprintf_f_32);
  tcase_add_test(third_group_sprintf, sprintf_f_33);
  tcase_add_test(third_group_sprintf, sprintf_f_34);
  tcase_add_test(third_group_sprintf, sprintf_f_35);
  tcase_add_test(third_group_sprintf, sprintf_f_36);
  tcase_add_test(third_group_sprintf, sprintf_f_37);

  suite_add_tcase(test, third_group_sprintf);
  return test;
}