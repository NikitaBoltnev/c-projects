#include <check.h>

#include "../s21_decimal.h"

// addition tests

START_TEST(add_1) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {0};
  s21_decimal standard = {{8, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_2) {
  s21_decimal value_1 = {{5192, 0, 0, 0}};
  s21_decimal value_2 = {{1219, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {0};
  s21_decimal standard = {{6411, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_3) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{2147483647, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFE, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_5) {
  s21_decimal value_1 = {{1234, 0, 0, 0}};
  s21_decimal value_2 = {{8394281, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{8393047, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_6) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  s21_decimal value_2 = {{1234567, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_7) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{12, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12333, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_8) {
  s21_decimal value_1 = {{4192, 0, 0, 0}};
  s21_decimal value_2 = {{12, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{4180, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_9) {
  s21_decimal value_1 = {{525252, 0, 0, 0}};
  s21_decimal value_2 = {{525252, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_10) {
  s21_decimal value_1 = {{91, 0, 0, 0}};
  s21_decimal value_2 = {{97, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{6, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_11) {
  s21_decimal value_1 = {{789, 0, 0, 0}};
  s21_decimal value_2 = {{567, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1356, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_12) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{2147483647, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFE, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_13) {
  s21_decimal value_1 = {{345, 0, 0, 0}};
  s21_decimal value_2 = {{678, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {0};
  s21_decimal standard = {{1023, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_14) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{1234, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x04D1, 1, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_15) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFE, 1, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_16) {
  s21_decimal value_1 = {{0, 5, 0, 0}};
  s21_decimal value_2 = {{0, 3, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 8, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_17) {
  s21_decimal value_1 = {{0, 1234, 0, 0}};
  s21_decimal value_2 = {{0, 8394281, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 8393047, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_18) {
  s21_decimal value_1 = {{0, 4192, 0, 0}};
  s21_decimal value_2 = {{0, 12, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 4180, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_19) {
  s21_decimal value_1 = {{0, 789, 0, 0}};
  s21_decimal value_2 = {{0, 567, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 1356, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_20) {
  s21_decimal value_1 = {{0, 1234567, 0, 0}};
  s21_decimal value_2 = {{0, 1234567, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_21) {
  s21_decimal value_1 = {{0, 2147483647, 0, 0}};
  s21_decimal value_2 = {{0, 2147483647, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0xFFFFFFFE, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_22) {
  s21_decimal value_1 = {{0, 2147483647, 0, 0}};
  s21_decimal value_2 = {{0, 2147483647, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0xFFFFFFFE, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_23) {
  s21_decimal value_1 = {{0, 4192, 0, 0}};
  s21_decimal value_2 = {{0, 12, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 4180, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_24) {
  s21_decimal value_1 = {{1234, 567, 890, 0}};
  s21_decimal value_2 = {{2731, 12, 3821, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{3965, 579, 4711, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_25) {
  s21_decimal value_1 = {{89, 4192, 0, 0}};
  s21_decimal value_2 = {{0, 12, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{89, 4204, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_26) {
  s21_decimal value_1 = {{455, 98, 0, 0}};
  s21_decimal value_2 = {{123, 99, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFEB4, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_27) {
  s21_decimal value_1 = {{12, 34, 56, 0}};
  s21_decimal value_2 = {{12, 34, 56, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_28) {
  s21_decimal value_1 = {{12, 98, 0, 0}};
  s21_decimal value_2 = {{89, 42, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{101, 140, 0, 0}};
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_29) {
  s21_decimal value_1 = {{637, 0, 0, 0}};
  s21_decimal value_2 = {{3729, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{37927, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_30) {
  s21_decimal value_1 = {{2812, 4192, 0, 0}};
  s21_decimal value_2 = {{2147483647, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 7);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x0000714, 0x00001254, 0, 0}};
  s21_set_scale(&standard, 10);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_31) {
  s21_decimal value_1 = {{12, 0, 0, 0}};
  s21_decimal value_2 = {{58, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 28);
  s21_set_scale(&value_2, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 27);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_32) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_33) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{342, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 4);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12642, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  s21_set_scale(&standard, 4);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_34) {
  s21_decimal value_1 = {{52, 0, 0, 0}};
  s21_decimal value_2 = {{21, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{31, 0, 0, 0}};
  s21_set_sign(&standard, 1);
  s21_set_scale(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_35) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};

  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_36) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 15, 0}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_37) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{6, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_38) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12345, 0, 0, 0}};
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_39) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1234, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1234, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_40) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_41) {
  s21_decimal value_1 = {{0, 0, 791, 0}};
  s21_decimal value_2 = {{0, 0, 461, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 1252, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_42) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{4, 5, 6, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 7, 9, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_43) {
  s21_decimal value_1 = {{1712, 383, 4, 0}};
  s21_decimal value_2 = {{1712, 383, 4, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 4);
  s21_set_scale(&value_2, 4);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_44) {
  s21_decimal value_1 = {{192, 0, 72, 0}};
  s21_decimal value_2 = {{192, 0, 72, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_45) {
  s21_decimal value_1 = {{3, 0, 4, 0}};
  s21_decimal value_2 = {{192, 0, 72, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{162, 0, 32, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_46) {
  s21_decimal value_1 = {{53, 0, 0, 0}};
  s21_decimal value_2 = {{980, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{927, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_47) {
  s21_decimal value_1 = {{750, 0, 0, 0}};
  s21_decimal value_2 = {{100, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{650, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_48) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(add_49) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{8, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_add(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// subtraction tests

START_TEST(sub_1) {
  s21_decimal value_1 = {{9, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{6, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_2) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_3) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{8, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_4) {
  s21_decimal value_1 = {{924562, 0, 0, 0}};
  s21_decimal value_2 = {{82492, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{842070, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_5) {
  s21_decimal value_1 = {{18393, 0, 0, 0}};
  s21_decimal value_2 = {{18393, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_6) {
  s21_decimal value_1 = {{9283, 0, 0, 0}};
  s21_decimal value_2 = {{173849, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{164566, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_7) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{2147483647, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2147483647, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{2147483647, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2147483647, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_11) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x8000000E, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_12) {
  s21_decimal value_1 = {{8921, 0, 0, 0}};
  s21_decimal value_2 = {{90, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{9011, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_13) {
  s21_decimal value_1 = {{1234, 0, 0, 0}};
  s21_decimal value_2 = {{52, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1182, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_14) {
  s21_decimal value_1 = {{7423, 0, 0, 0}};
  s21_decimal value_2 = {{821, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 3);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{74677, 0, 0, 0}};
  s21_set_scale(&standard, 3);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_15) {
  s21_decimal value_1 = {{12, 0, 0, 0}};
  s21_decimal value_2 = {{12, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 3);
  s21_set_scale(&value_2, 3);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_16) {
  s21_decimal value_1 = {{92, 0, 0, 0}};
  s21_decimal value_2 = {{108, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 25);
  s21_set_scale(&value_2, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{91892, 0, 0, 0}};
  s21_set_scale(&standard, 28);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_17) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{89, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{88995, 0, 0, 0}};
  s21_set_scale(&standard, 5);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_18) {
  s21_decimal value_1 = {{0, 92, 0, 0}};
  s21_decimal value_2 = {{0, 89, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 3, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_19) {
  s21_decimal value_1 = {{0, 52, 0, 0}};
  s21_decimal value_2 = {{0, 931, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 879, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_20) {
  s21_decimal value_1 = {{123456, 1, 0, 0}};
  s21_decimal value_2 = {{0, 2, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFE1DC0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal value_1 = {{1819, 234, 0, 0}};
  s21_decimal value_2 = {{89123513, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFAB05C55, 2339, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_22) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 2147483647, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 2147483647, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_23) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 2147483647, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 2147483647, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_24) {
  s21_decimal value_1 = {{0, 100, 0, 0}};
  s21_decimal value_2 = {{0, 50, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 150, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_25) {
  s21_decimal value_1 = {{0, 123456, 0, 0}};
  s21_decimal value_2 = {{0, 12345, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 4);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 6, 0, 0}};
  s21_set_scale(&standard, 5);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_26) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{6, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_27) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_28) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_29) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 8);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFA0A1EFF, 100000000, 0, 0}};
  s21_set_scale(&standard, 8);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_30) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFC17, 1000, 0, 0}};
  s21_set_scale(&standard, 5);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_31) {
  s21_decimal value_1 = {{50, 0, 0, 0}};
  s21_decimal value_2 = {{50, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_32) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{6, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_33) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{189, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_34) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 3, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_35) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_36) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_37) {
  s21_decimal value_1 = {{1234, 0, 0, 0}};
  s21_decimal value_2 = {{1234, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_38) {
  s21_decimal value_1 = {{9, 1, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFBF, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{74, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_39) {
  s21_decimal value_1 = {{0, 0, 45, 0}};
  s21_decimal value_2 = {{0, 0, 90, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 45, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_40) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{82, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1312, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_41) {
  s21_decimal value_1 = {{90, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{110, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_42) {
  s21_decimal value_1 = {{0, 34, 0, 0}};
  s21_decimal value_2 = {{0, 34, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_43) {
  s21_decimal value_1 = {{1892, 0, 0, 0}};
  s21_decimal value_2 = {{12, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1772, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 1);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(sub_44) {
  s21_decimal value_1 = {{8, 0, 0, 0}};
  s21_decimal value_2 = {{34, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{26, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_sub(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// multiplication tests

START_TEST(mul_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{10, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{150, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_3) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{25, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_4) {
  s21_decimal value_1 = {{3, 0, 0, 0}};
  s21_decimal value_2 = {{9, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{27, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_5) {
  s21_decimal value_1 = {{8, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{16, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_6) {
  s21_decimal value_1 = {{152, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_7) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{38, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_8) {
  s21_decimal value_1 = {{291, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_9) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 3);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{61725, 0, 0, 0}};
  s21_set_scale(&standard, 3);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_10) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_11) {
  s21_decimal value_1 = {{0, 24, 0, 0}};
  s21_decimal value_2 = {{0, 19, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 456, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_12) {
  s21_decimal value_1 = {{0, 19, 0, 0}};
  s21_decimal value_2 = {{0, 32, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 608, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_13) {
  s21_decimal value_1 = {{0, 82, 0, 0}};
  s21_decimal value_2 = {{0, 95, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 7790, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_14) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_15) {
  s21_decimal value_1 = {{3, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{6, 0, 0, 0}};
  s21_set_scale(&standard, 15);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_16) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x7FFFFFFD, 1, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_17) {
  s21_decimal value_1 = {{2147483647, 0, 0, 0}};
  s21_decimal value_2 = {{36, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 3);
  s21_set_scale(&value_2, 9);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFDC, 17, 0, 0}};
  s21_set_scale(&standard, 12);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_18) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{52, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 15);
  s21_set_scale(&value_2, 15);
  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 28);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_19) {
  s21_decimal value_1 = {{290, 0, 183, 0}};
  s21_decimal value_2 = {{21, 932, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_20) {
  s21_decimal value_1 = {{481, 34, 821, 0}};
  s21_decimal value_2 = {{0, 0, 5, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_21) {
  s21_decimal value_1 = {{1263, 0, 921, 0}};
  s21_decimal value_2 = {{0, 0, 3, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_22) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_23) {
  s21_decimal value_1 = {{1462, 0, 2, 0}};
  s21_decimal value_2 = {{0, 4, 5, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 12);
  s21_set_scale(&value_2, 7);
  s21_decimal result = {{0}};
  s21_decimal standard = {{93355375, 1918751201, 18, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_24) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 28);
  s21_set_scale(&value_2, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_25) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0xFFFFFFFE, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_26) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_27) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_28) {
  s21_decimal value_1 = {{123456u, 123u, 0, 0}};
  s21_decimal value_2 = {{654321u, 654u, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 3);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xC7E2ACA0, 0x3429346F, 0x1F6C, 0}};
  s21_set_scale(&standard, 4);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_29) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_30) {
  s21_decimal value_1 = {{30, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_31) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{100, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_32) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{200, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_33) {
  s21_decimal value_1 = {{9403, 0, 0, 0}};
  s21_decimal value_2 = {{202, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1899406, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_34) {
  s21_decimal value_1 = {{32768, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{65536, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(mul_35) {
  s21_decimal value_1 = {{32768, 0, 0, 0}};
  s21_decimal value_2 = {{32768, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1073741824, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_mul(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// division tests

START_TEST(div_1) {
  s21_decimal value_1 = {{9, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{3, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_2) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_3) {
  s21_decimal value_1 = {{6, 0, 0, 0}};
  s21_decimal value_2 = {{6, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_4) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{45, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_5) {
  s21_decimal value_1 = {{12, 0, 0, 0}};
  s21_decimal value_2 = {{80, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{15, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_6) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_7) {
  s21_decimal value_1 = {{16, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{32, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 1);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_8) {
  s21_decimal value_1 = {{70, 0, 0, 0}};
  s21_decimal value_2 = {{140, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 1);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_9) {
  s21_decimal value_1 = {{492, 0, 0, 0}};
  s21_decimal value_2 = {{82, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{6, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_10) {
  s21_decimal value_1 = {{4, 0, 0, 0}};
  s21_decimal value_2 = {{16, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{25, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 1);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_11) {
  s21_decimal value_1 = {{11, 0, 0, 0}};
  s21_decimal value_2 = {{4, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{275, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_12) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 1);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_13) {
  s21_decimal value_1 = {{123, 123, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 3);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_14) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 3);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_15) {
  s21_decimal value_1 = {{82, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 4);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 3);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{36, 91, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_17) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{9212, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_18) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_19) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{45, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_20) {
  s21_decimal value_1 = {{166666, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{55555, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_21) {
  s21_decimal value_1 = {{82, 0, 0, 0}};
  s21_decimal value_2 = {{9, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{9, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_22) {
  s21_decimal value_1 = {{55, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{55, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(div_23) {
  s21_decimal value_1 = {{55, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{550, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_div(value_1, value_2, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// less tests

START_TEST(less_1) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_1.bits[0] = 255;
  value_2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_1.bits[0] = 256;
  value_2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_4) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_1.bits[0] = 257;
  value_2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_5) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_1.bits[0] = 257;
  value_2.bits[0] = 256;
  value_1.bits[2] = 256;
  value_2.bits[2] = 257;
  s21_set_scale(&value_1, 11);
  s21_set_scale(&value_2, 10);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_6) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_1.bits[0] = 257;
  value_2.bits[0] = 257;
  value_1.bits[2] = 256;
  value_2.bits[2] = 257;
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 11);
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_7) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  value_2.bits[2] = 257;
  s21_set_scale(&value_1, 13);
  s21_set_scale(&value_2, 13);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_8) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_bit_one(83, &value_1);
  s21_set_scale(&value_1, 12);
  s21_set_scale(&value_2, 11);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_9) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_bit_one(83, &value_1);
  s21_set_bit_one(83, &value_2);
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 11);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_10) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_bit_one(83, &value_1);
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 10);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_11) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  s21_set_bit_one(83, &value_1);
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_12) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 0);
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(less_13) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_14) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(less_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2, 1);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_17) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_18) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 2);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_19) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(less_20) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  int error = s21_is_less(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

// less or equal tests

START_TEST(less_or_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 1);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_9) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(less_or_equal_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(less_or_equal_11) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2, 1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(less_or_equal_12) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(less_or_equal_13) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(less_or_equal_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_scale(&value_2, 2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);  // 1
}
END_TEST

START_TEST(less_or_equal_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

// greater tests

START_TEST(greater_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 1);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_9) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 0);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_11) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(greater_12) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_13) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  int error_2 = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error_2, 0);
}
END_TEST

START_TEST(greater_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(greater_16) {
  s21_decimal value_1 = {{234, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_scale(&value_1, 2);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_17) {
  s21_decimal value_1 = {{52, 0, 0, 0}};
  s21_decimal value_2 = {{55, 0, 0, 0}};
  s21_set_scale(&value_1, 27);
  s21_set_scale(&value_2, 28);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_18) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  s21_set_scale(&value_1, 10);
  s21_set_scale(&value_2, 10);
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

// greater or equal tests

START_TEST(greater_or_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_9) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_or_equal_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(greater_or_equal_11) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_or_equal_12) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_or_equal_13) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_or_equal_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(greater_or_equal_15) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{12u, 0, 0, 0}};
  s21_set_scale(&value_1, 4);
  s21_set_scale(&value_2, 1);
  int error = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

// equal tests

START_TEST(equal_1) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_set_sign(&val2, 1);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val2);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val2, 1);
  s21_set_bit_one(33, &val1);
  s21_set_bit_one(33, &val2);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(3, &val2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(4, &val2);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(4, &val2);
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_9) {
  s21_decimal val1 = {{0, 982, 0, 0}};
  s21_decimal val2 = {{0, 982, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_10) {
  s21_decimal val1 = {{0, 0, 91, 0}};
  s21_decimal val2 = {{0, 0, 910, 0}};
  s21_set_scale(&val1, 13);
  s21_set_scale(&val2, 14);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_11) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}

END_TEST

// not equal tests

START_TEST(not_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 0);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val2);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val2, 1);
  s21_set_bit_one(33, &val1);
  s21_set_bit_one(33, &val2);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(3, &val2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(4, &val2);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit_one(3, &val1);
  s21_set_bit_one(4, &val2);
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_9) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_10) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int error = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(not_equal_11) {
  s21_decimal value_1 = {{0, 0, 0, 80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int error = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

// truncate tests

START_TEST(truncate_1) {
  s21_decimal value_1 = {{52, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_2) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_set_scale(&value_1, 5);
  s21_set_sign(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1234, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal value_1 = {{128, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_4) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 3);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_5) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 6);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_6) {
  s21_decimal value_1 = {{999999, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 3);
  s21_decimal result = {{0}};
  s21_decimal standard = {{999, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_7) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1234567, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 28);

  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);

  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_9) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_10) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(truncate_11) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_truncate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// floor tests

START_TEST(floor_1) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal value_1 = {{178932, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_4) {
  s21_decimal value_1 = {{178932, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_5) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{123456, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_7) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12345679, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x9999999A, 0x99999999, 429496729, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 3);

  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);

  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_10) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{7, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_11) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{8, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(floor_12) {
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0x99999999, 0x99999999, 429496729, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_floor(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// negate tests

START_TEST(negate_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&standard, 28);
  s21_set_sign(&standard, 0);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_3) {
  s21_decimal value_1 = {{0, 0, 52, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 52, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);

  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_4) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 3);
  s21_decimal result = {{0}};
  s21_decimal standard = {{123456, 0, 0, 0}};
  s21_set_scale(&standard, 3);
  s21_set_sign(&standard, 1);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_5) {
  s21_decimal value_1 = {{987654, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 2);
  s21_decimal result = {{0}};
  s21_decimal standard = {{987654, 0, 0, 0}};
  s21_set_scale(&standard, 2);
  s21_set_sign(&standard, 0);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_6) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 0);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_7) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{123456789, 0, 0, 0}};
  s21_set_scale(&standard, 28);
  s21_set_sign(&standard, 1);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_8) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0xFFFFFFFF, 0, 0}};
  s21_set_scale(&standard, 5);
  s21_set_sign(&standard, 1);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(negate_9) {
  s21_decimal value_1 = {{54321, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 7);
  s21_decimal result = {{0}};
  s21_decimal standard = {{54321, 0, 0, 0}};
  s21_set_scale(&standard, 7);
  s21_set_sign(&standard, 0);
  int flag = s21_negate(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

// round tests

START_TEST(round_1) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_2) {
  s21_decimal value_1 = {{0, 9, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{0, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 28);
  s21_decimal result = {{0}};
  s21_decimal standard = {{8, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_4) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 8);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_5) {
  s21_decimal value_1 = {{178932, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 5);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_6) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);

  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_7) {
  s21_decimal value_1 = {{12345675, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 6);
  s21_decimal result = {{0}};
  s21_decimal standard = {{12, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 10);
  s21_decimal result = {{0}};
  s21_decimal standard = {{1844674407, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);
  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}

START_TEST(round_9) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{2, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);

  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_10) {
  s21_decimal value_1 = {{25, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{3, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 0);

  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_11) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{4, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);

  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_12) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_scale(&value_1, 1);
  s21_decimal result = {{0}};
  s21_decimal standard = {{5, 0, 0, 0}};
  s21_set_scale(&standard, 0);
  s21_set_sign(&standard, 1);

  int flag = s21_round(value_1, &result);
  int equally = s21_is_equal(result, standard);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equally, 1);
}
END_TEST

START_TEST(round_13) {
  s21_decimal value = {{249, 0, 0, 0}};
  s21_set_scale(&value, 2);
  s21_decimal expected = {{2, 0, 0, 0}};
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(round_14) {
  s21_decimal value = {{251, 0, 0, 0}};
  s21_set_scale(&value, 2);
  s21_set_sign(&value, 1);
  s21_decimal expected = {{3, 0, 0, 0}};
  s21_set_sign(&expected, 1);
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(round_15) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_set_scale(&value, 5);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(round_16) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_set_scale(&value, 10);
  s21_set_sign(&value, 1);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_set_sign(&expected, 1);
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(round_17) {
  s21_decimal value = {{1, 0, 0, 0}};
  s21_set_scale(&value, 7);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(round_18) {
  s21_decimal value = {{99999995, 0, 0, 0}};
  s21_set_scale(&value, 1);
  s21_decimal expected = {{10000000, 0, 0, 0}};
  s21_decimal result = {{0}};
  int flag = s21_round(value, &result);
  int equal = s21_is_equal(result, expected);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

// from decimal to float tests

START_TEST(decflo_1) {
  s21_decimal decimal = {{1523, 0, 0, 0}};
  s21_set_sign(&decimal, 1);
  s21_set_scale(&decimal, 2);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = -15.23;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decflo_2) {
  s21_decimal decimal = {{1523, 0, 0, 0}};
  s21_set_sign(&decimal, 0);
  s21_set_scale(&decimal, 2);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = 15.23;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decflo_3) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  s21_set_sign(&decimal, 0);
  s21_set_scale(&decimal, 0);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = 0;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decflo_4) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  s21_set_sign(&decimal, 1);
  s21_set_scale(&decimal, 0);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = 0;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decflo_5) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&decimal, 0);
  s21_set_scale(&decimal, 0);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = 79228162514264337593543950335.0;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decflo_6) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&decimal, 1);
  s21_set_scale(&decimal, 0);
  float res = 0.0;
  int flag = s21_from_decimal_to_float(decimal, &res);
  float standart = -79228162514264337593543950335.0;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

// from decimal to int tests

START_TEST(decint_1) {
  s21_decimal decimal = {{15, 0, 0, 0}};
  s21_set_sign(&decimal, 1);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  int standart = -15;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decint_2) {
  s21_decimal decimal = {{15, 0, 0, 0}};
  s21_set_sign(&decimal, 0);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  int standart = 15;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decint_3) {
  s21_decimal decimal = {{1234, 0, 0, 0}};
  s21_set_scale(&decimal, 2);
  s21_set_sign(&decimal, 0);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  int standart = 12;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decint_4) {
  s21_decimal decimal = {{1234, 0, 0, 0}};
  s21_set_scale(&decimal, 2);
  s21_set_sign(&decimal, 1);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  int standart = -12;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decint_5) {
  s21_decimal decimal = {{1234, 0, 0, 0}};
  s21_set_scale(&decimal, 28);
  s21_set_sign(&decimal, 0);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(decint_6) {
  s21_decimal decimal = {{1234, 0, 0, 0}};
  s21_set_scale(&decimal, 1);
  s21_set_sign(&decimal, 0);
  int res = 123;
  int flag = s21_from_decimal_to_int(decimal, &res);
  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(decint_7) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&decimal, 0);
  s21_set_sign(&decimal, 0);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(decint_8) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  s21_set_sign(&decimal, 1);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  int standart = 0;
  ck_assert_int_eq(0, flag);
  ck_assert_int_eq(res, standart);
}
END_TEST

START_TEST(decint_9) {
  s21_decimal decimal = {{0, 15, 0, 0}};
  s21_set_scale(&decimal, 0);
  s21_set_sign(&decimal, 1);
  int res = 0;
  int flag = s21_from_decimal_to_int(decimal, &res);
  ck_assert_int_eq(1, flag);
}
END_TEST

// from float to decimal tests

START_TEST(flodec_1) {
  float value = 34.56;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3456, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 2);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_2) {
  float value = 34.5623234;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3456232, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 5);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_3) {
  float value = 345235954;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3452359, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_4) {
  float value = 200000000;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{2000000, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_5) {
  float value = 2000;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{2000, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_6) {
  float value = 2000.000;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{2000, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_7) {
  float value = 0.00000000000000000000000000001;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{0, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(1, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_8) {
  float value = 0.00000001;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{0, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_9) {
  float value = 0.2343;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{2343, 0, 0, 0}};
  s21_set_sign(&standart, 0);
  s21_set_scale(&standart, 4);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_10) {
  float value = -34.56;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3456, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  s21_set_scale(&standart, 2);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_11) {
  float value = -34.5623234;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3456232, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  s21_set_scale(&standart, 5);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_12) {
  float value = -345235954;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{3452359, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_13) {
  float value = -2000000000;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{2000000, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(flodec_14) {
  float value = -0.00000001;
  s21_decimal decimal = {{0}};
  int res = s21_from_float_to_decimal(value, &decimal);
  s21_decimal standart = {{0, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  s21_set_scale(&standart, 0);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

// from_int_to_decimal tests

START_TEST(intdec_1) {
  int value = -15;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{15, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_2) {
  int value = 15;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{15, 0, 0, 0}};
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_3) {
  int value = -2147483648;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{-2147483648, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_4) {
  int value = 2147483647;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{2147483647, 0, 0, 0}};
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_5) {
  int value = 0;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{0, 0, 0, 0}};
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_6) {
  int value = 1000;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{1000, 0, 0, 0}};
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

START_TEST(intdec_7) {
  int value = -1000;
  s21_decimal decimal = {{0}};
  int res = s21_from_int_to_decimal(value, &decimal);
  s21_decimal standart = {{1000, 0, 0, 0}};
  s21_set_sign(&standart, 1);
  int equally = s21_is_equal(decimal, standart);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, equally);
}
END_TEST

Suite* s21_decimal_tests() {
  Suite* suite = suite_create("s21_decimal_suite");

  // arithmetic addition
  TCase* tcase_arithmetic_add = tcase_create("s21_arithmetic_add_tcase");
  tcase_add_test(tcase_arithmetic_add, add_1);
  tcase_add_test(tcase_arithmetic_add, add_2);
  tcase_add_test(tcase_arithmetic_add, add_3);
  tcase_add_test(tcase_arithmetic_add, add_4);
  tcase_add_test(tcase_arithmetic_add, add_5);
  tcase_add_test(tcase_arithmetic_add, add_6);
  tcase_add_test(tcase_arithmetic_add, add_7);
  tcase_add_test(tcase_arithmetic_add, add_8);
  tcase_add_test(tcase_arithmetic_add, add_9);
  tcase_add_test(tcase_arithmetic_add, add_10);
  tcase_add_test(tcase_arithmetic_add, add_11);
  tcase_add_test(tcase_arithmetic_add, add_12);
  tcase_add_test(tcase_arithmetic_add, add_13);
  tcase_add_test(tcase_arithmetic_add, add_14);
  tcase_add_test(tcase_arithmetic_add, add_15);
  tcase_add_test(tcase_arithmetic_add, add_16);
  tcase_add_test(tcase_arithmetic_add, add_17);
  tcase_add_test(tcase_arithmetic_add, add_18);
  tcase_add_test(tcase_arithmetic_add, add_19);
  tcase_add_test(tcase_arithmetic_add, add_20);
  tcase_add_test(tcase_arithmetic_add, add_21);
  tcase_add_test(tcase_arithmetic_add, add_22);
  tcase_add_test(tcase_arithmetic_add, add_23);
  tcase_add_test(tcase_arithmetic_add, add_24);
  tcase_add_test(tcase_arithmetic_add, add_25);
  tcase_add_test(tcase_arithmetic_add, add_26);
  tcase_add_test(tcase_arithmetic_add, add_27);
  tcase_add_test(tcase_arithmetic_add, add_28);
  tcase_add_test(tcase_arithmetic_add, add_29);
  tcase_add_test(tcase_arithmetic_add, add_30);
  tcase_add_test(tcase_arithmetic_add, add_31);
  tcase_add_test(tcase_arithmetic_add, add_32);
  tcase_add_test(tcase_arithmetic_add, add_33);
  tcase_add_test(tcase_arithmetic_add, add_34);
  tcase_add_test(tcase_arithmetic_add, add_35);
  tcase_add_test(tcase_arithmetic_add, add_36);
  tcase_add_test(tcase_arithmetic_add, add_37);
  tcase_add_test(tcase_arithmetic_add, add_38);
  tcase_add_test(tcase_arithmetic_add, add_39);
  tcase_add_test(tcase_arithmetic_add, add_40);
  tcase_add_test(tcase_arithmetic_add, add_41);
  tcase_add_test(tcase_arithmetic_add, add_42);
  tcase_add_test(tcase_arithmetic_add, add_43);
  tcase_add_test(tcase_arithmetic_add, add_44);
  tcase_add_test(tcase_arithmetic_add, add_45);
  tcase_add_test(tcase_arithmetic_add, add_46);
  tcase_add_test(tcase_arithmetic_add, add_47);
  tcase_add_test(tcase_arithmetic_add, add_48);
  tcase_add_test(tcase_arithmetic_add, add_49);
  suite_add_tcase(suite, tcase_arithmetic_add);

  // arithmetic subtraction
  TCase* tcase_arithmetic_sub = tcase_create("s21_arithmetic_sub_tcase");
  tcase_add_test(tcase_arithmetic_sub, sub_1);
  tcase_add_test(tcase_arithmetic_sub, sub_2);
  tcase_add_test(tcase_arithmetic_sub, sub_3);
  tcase_add_test(tcase_arithmetic_sub, sub_4);
  tcase_add_test(tcase_arithmetic_sub, sub_5);
  tcase_add_test(tcase_arithmetic_sub, sub_6);
  tcase_add_test(tcase_arithmetic_sub, sub_7);
  tcase_add_test(tcase_arithmetic_sub, sub_8);
  tcase_add_test(tcase_arithmetic_sub, sub_9);
  tcase_add_test(tcase_arithmetic_sub, sub_10);
  tcase_add_test(tcase_arithmetic_sub, sub_11);
  tcase_add_test(tcase_arithmetic_sub, sub_12);
  tcase_add_test(tcase_arithmetic_sub, sub_13);
  tcase_add_test(tcase_arithmetic_sub, sub_14);
  tcase_add_test(tcase_arithmetic_sub, sub_15);
  tcase_add_test(tcase_arithmetic_sub, sub_16);
  tcase_add_test(tcase_arithmetic_sub, sub_17);
  tcase_add_test(tcase_arithmetic_sub, sub_18);
  tcase_add_test(tcase_arithmetic_sub, sub_19);
  tcase_add_test(tcase_arithmetic_sub, sub_20);
  tcase_add_test(tcase_arithmetic_sub, sub_21);
  tcase_add_test(tcase_arithmetic_sub, sub_22);
  tcase_add_test(tcase_arithmetic_sub, sub_23);
  tcase_add_test(tcase_arithmetic_sub, sub_24);
  tcase_add_test(tcase_arithmetic_sub, sub_25);
  tcase_add_test(tcase_arithmetic_sub, sub_26);
  tcase_add_test(tcase_arithmetic_sub, sub_27);
  tcase_add_test(tcase_arithmetic_sub, sub_28);
  tcase_add_test(tcase_arithmetic_sub, sub_29);
  tcase_add_test(tcase_arithmetic_sub, sub_30);
  tcase_add_test(tcase_arithmetic_sub, sub_31);
  tcase_add_test(tcase_arithmetic_sub, sub_32);
  tcase_add_test(tcase_arithmetic_sub, sub_33);
  tcase_add_test(tcase_arithmetic_sub, sub_34);
  tcase_add_test(tcase_arithmetic_sub, sub_35);
  tcase_add_test(tcase_arithmetic_sub, sub_36);
  tcase_add_test(tcase_arithmetic_sub, sub_37);
  tcase_add_test(tcase_arithmetic_sub, sub_38);
  tcase_add_test(tcase_arithmetic_sub, sub_39);
  tcase_add_test(tcase_arithmetic_sub, sub_40);
  tcase_add_test(tcase_arithmetic_sub, sub_41);
  tcase_add_test(tcase_arithmetic_sub, sub_42);
  tcase_add_test(tcase_arithmetic_sub, sub_43);
  tcase_add_test(tcase_arithmetic_sub, sub_44);
  suite_add_tcase(suite, tcase_arithmetic_sub);

  // arithmetic multiplication
  TCase* tcase_arithmetic_mul = tcase_create("s21_arithmetic_mul_tcase");
  tcase_add_test(tcase_arithmetic_mul, mul_1);
  tcase_add_test(tcase_arithmetic_mul, mul_2);
  tcase_add_test(tcase_arithmetic_mul, mul_3);
  tcase_add_test(tcase_arithmetic_mul, mul_4);
  tcase_add_test(tcase_arithmetic_mul, mul_5);
  tcase_add_test(tcase_arithmetic_mul, mul_6);
  tcase_add_test(tcase_arithmetic_mul, mul_7);
  tcase_add_test(tcase_arithmetic_mul, mul_8);
  tcase_add_test(tcase_arithmetic_mul, mul_9);
  tcase_add_test(tcase_arithmetic_mul, mul_10);
  tcase_add_test(tcase_arithmetic_mul, mul_11);
  tcase_add_test(tcase_arithmetic_mul, mul_12);
  tcase_add_test(tcase_arithmetic_mul, mul_13);
  tcase_add_test(tcase_arithmetic_mul, mul_14);
  tcase_add_test(tcase_arithmetic_mul, mul_15);
  tcase_add_test(tcase_arithmetic_mul, mul_16);
  tcase_add_test(tcase_arithmetic_mul, mul_17);
  tcase_add_test(tcase_arithmetic_mul, mul_18);
  tcase_add_test(tcase_arithmetic_mul, mul_19);
  tcase_add_test(tcase_arithmetic_mul, mul_20);
  tcase_add_test(tcase_arithmetic_mul, mul_21);
  tcase_add_test(tcase_arithmetic_mul, mul_22);
  tcase_add_test(tcase_arithmetic_mul, mul_23);
  tcase_add_test(tcase_arithmetic_mul, mul_24);
  tcase_add_test(tcase_arithmetic_mul, mul_25);
  tcase_add_test(tcase_arithmetic_mul, mul_26);
  tcase_add_test(tcase_arithmetic_mul, mul_27);
  tcase_add_test(tcase_arithmetic_mul, mul_28);
  tcase_add_test(tcase_arithmetic_mul, mul_29);
  tcase_add_test(tcase_arithmetic_mul, mul_30);
  tcase_add_test(tcase_arithmetic_mul, mul_31);
  tcase_add_test(tcase_arithmetic_mul, mul_32);
  tcase_add_test(tcase_arithmetic_mul, mul_33);
  tcase_add_test(tcase_arithmetic_mul, mul_34);
  tcase_add_test(tcase_arithmetic_mul, mul_35);
  suite_add_tcase(suite, tcase_arithmetic_mul);

  // arithmetic division
  TCase* tcase_arithmetic_div = tcase_create("s21_arithmetic_mul_tcase");
  tcase_add_test(tcase_arithmetic_div, div_1);
  tcase_add_test(tcase_arithmetic_div, div_2);
  tcase_add_test(tcase_arithmetic_div, div_3);
  tcase_add_test(tcase_arithmetic_div, div_4);
  tcase_add_test(tcase_arithmetic_div, div_5);
  tcase_add_test(tcase_arithmetic_div, div_6);
  tcase_add_test(tcase_arithmetic_div, div_7);
  tcase_add_test(tcase_arithmetic_div, div_8);
  tcase_add_test(tcase_arithmetic_div, div_9);
  tcase_add_test(tcase_arithmetic_div, div_10);
  tcase_add_test(tcase_arithmetic_div, div_11);
  tcase_add_test(tcase_arithmetic_div, div_12);
  tcase_add_test(tcase_arithmetic_div, div_13);
  tcase_add_test(tcase_arithmetic_div, div_14);
  tcase_add_test(tcase_arithmetic_div, div_15);
  tcase_add_test(tcase_arithmetic_div, div_16);
  tcase_add_test(tcase_arithmetic_div, div_17);
  tcase_add_test(tcase_arithmetic_div, div_18);
  tcase_add_test(tcase_arithmetic_div, div_19);
  tcase_add_test(tcase_arithmetic_div, div_20);
  tcase_add_test(tcase_arithmetic_div, div_21);
  tcase_add_test(tcase_arithmetic_div, div_22);
  tcase_add_test(tcase_arithmetic_div, div_23);
  suite_add_tcase(suite, tcase_arithmetic_div);

  // comparison less
  TCase* tcase_comparison_less = tcase_create("s21_comparison_less_tcase");
  tcase_add_test(tcase_comparison_less, less_1);
  tcase_add_test(tcase_comparison_less, less_2);
  tcase_add_test(tcase_comparison_less, less_3);
  tcase_add_test(tcase_comparison_less, less_4);
  tcase_add_test(tcase_comparison_less, less_5);
  tcase_add_test(tcase_comparison_less, less_6);
  tcase_add_test(tcase_comparison_less, less_7);
  tcase_add_test(tcase_comparison_less, less_8);
  tcase_add_test(tcase_comparison_less, less_9);
  tcase_add_test(tcase_comparison_less, less_10);
  tcase_add_test(tcase_comparison_less, less_11);
  tcase_add_test(tcase_comparison_less, less_12);
  tcase_add_test(tcase_comparison_less, less_13);
  tcase_add_test(tcase_comparison_less, less_14);
  tcase_add_test(tcase_comparison_less, less_15);
  tcase_add_test(tcase_comparison_less, less_16);
  tcase_add_test(tcase_comparison_less, less_17);
  tcase_add_test(tcase_comparison_less, less_18);
  tcase_add_test(tcase_comparison_less, less_19);
  tcase_add_test(tcase_comparison_less, less_20);
  ;
  suite_add_tcase(suite, tcase_comparison_less);

  // comparison less or equal
  TCase* tcase_comparison_less_or_equal =
      tcase_create("s21_comparison_less__or_equal_tcase");
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_1);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_2);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_3);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_4);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_5);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_6);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_7);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_8);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_9);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_10);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_11);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_12);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_13);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_14);
  tcase_add_test(tcase_comparison_less_or_equal, less_or_equal_15);
  suite_add_tcase(suite, tcase_comparison_less_or_equal);

  // comparison greater
  TCase* tcase_comparison_greater =
      tcase_create("s21_comparison_greater_tcase");
  tcase_add_test(tcase_comparison_greater, greater_1);
  tcase_add_test(tcase_comparison_greater, greater_2);
  tcase_add_test(tcase_comparison_greater, greater_3);
  tcase_add_test(tcase_comparison_greater, greater_4);
  tcase_add_test(tcase_comparison_greater, greater_5);
  tcase_add_test(tcase_comparison_greater, greater_6);
  tcase_add_test(tcase_comparison_greater, greater_7);
  tcase_add_test(tcase_comparison_greater, greater_8);
  tcase_add_test(tcase_comparison_greater, greater_9);
  tcase_add_test(tcase_comparison_greater, greater_10);
  tcase_add_test(tcase_comparison_greater, greater_11);
  tcase_add_test(tcase_comparison_greater, greater_12);
  tcase_add_test(tcase_comparison_greater, greater_13);
  tcase_add_test(tcase_comparison_greater, greater_14);
  tcase_add_test(tcase_comparison_greater, greater_15);
  tcase_add_test(tcase_comparison_greater, greater_16);
  tcase_add_test(tcase_comparison_greater, greater_17);
  tcase_add_test(tcase_comparison_greater, greater_18);
  suite_add_tcase(suite, tcase_comparison_greater);

  // comparison greater or equal
  TCase* tcase_comparison_greater_or_equal =
      tcase_create("s21_comparison_greater_or_equal_tcase");
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_1);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_2);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_3);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_4);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_5);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_6);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_7);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_8);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_9);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_10);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_11);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_12);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_13);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_14);
  tcase_add_test(tcase_comparison_greater_or_equal, greater_or_equal_15);
  suite_add_tcase(suite, tcase_comparison_greater_or_equal);

  // comparison equal
  TCase* tcase_comparison_equal = tcase_create("s21_comparison_equal_tcase");
  tcase_add_test(tcase_comparison_equal, equal_1);
  tcase_add_test(tcase_comparison_equal, equal_2);
  tcase_add_test(tcase_comparison_equal, equal_3);
  tcase_add_test(tcase_comparison_equal, equal_4);
  tcase_add_test(tcase_comparison_equal, equal_5);
  tcase_add_test(tcase_comparison_equal, equal_6);
  tcase_add_test(tcase_comparison_equal, equal_7);
  tcase_add_test(tcase_comparison_equal, equal_8);
  tcase_add_test(tcase_comparison_equal, equal_9);
  tcase_add_test(tcase_comparison_equal, equal_10);
  tcase_add_test(tcase_comparison_equal, equal_11);
  suite_add_tcase(suite, tcase_comparison_equal);

  // comparison not equal
  TCase* tcase_comparison_not_equal =
      tcase_create("s21_comparison_not_equal_tcase");
  tcase_add_test(tcase_comparison_not_equal, not_equal_1);
  tcase_add_test(tcase_comparison_not_equal, not_equal_2);
  tcase_add_test(tcase_comparison_not_equal, not_equal_3);
  tcase_add_test(tcase_comparison_not_equal, not_equal_4);
  tcase_add_test(tcase_comparison_not_equal, not_equal_5);
  tcase_add_test(tcase_comparison_not_equal, not_equal_6);
  tcase_add_test(tcase_comparison_not_equal, not_equal_7);
  tcase_add_test(tcase_comparison_not_equal, not_equal_8);
  tcase_add_test(tcase_comparison_not_equal, not_equal_9);
  tcase_add_test(tcase_comparison_not_equal, not_equal_10);
  tcase_add_test(tcase_comparison_not_equal, not_equal_11);
  suite_add_tcase(suite, tcase_comparison_not_equal);

  // other floor
  TCase* tcase_other_floor = tcase_create("s21_other_floor_tcase");
  tcase_add_test(tcase_other_floor, floor_1);
  tcase_add_test(tcase_other_floor, floor_2);
  tcase_add_test(tcase_other_floor, floor_3);
  tcase_add_test(tcase_other_floor, floor_4);
  tcase_add_test(tcase_other_floor, floor_5);
  tcase_add_test(tcase_other_floor, floor_6);
  tcase_add_test(tcase_other_floor, floor_7);
  tcase_add_test(tcase_other_floor, floor_8);
  tcase_add_test(tcase_other_floor, floor_9);
  tcase_add_test(tcase_other_floor, floor_10);
  tcase_add_test(tcase_other_floor, floor_11);
  tcase_add_test(tcase_other_floor, floor_12);
  suite_add_tcase(suite, tcase_other_floor);

  // other negate
  TCase* tcase_other_negate = tcase_create("s21_other_negate_tcase");
  tcase_add_test(tcase_other_negate, negate_1);
  tcase_add_test(tcase_other_negate, negate_2);
  tcase_add_test(tcase_other_negate, negate_3);
  tcase_add_test(tcase_other_negate, negate_4);
  tcase_add_test(tcase_other_negate, negate_5);
  tcase_add_test(tcase_other_negate, negate_6);
  tcase_add_test(tcase_other_negate, negate_7);
  tcase_add_test(tcase_other_negate, negate_8);
  tcase_add_test(tcase_other_negate, negate_9);
  suite_add_tcase(suite, tcase_other_negate);

  // other truncate
  TCase* tcase_other_truncate = tcase_create("s21_other_truncate_tcase");
  tcase_add_test(tcase_other_truncate, truncate_1);
  tcase_add_test(tcase_other_truncate, truncate_2);
  tcase_add_test(tcase_other_truncate, truncate_3);
  tcase_add_test(tcase_other_truncate, truncate_4);
  tcase_add_test(tcase_other_truncate, truncate_5);
  tcase_add_test(tcase_other_truncate, truncate_6);
  tcase_add_test(tcase_other_truncate, truncate_7);
  tcase_add_test(tcase_other_truncate, truncate_8);
  tcase_add_test(tcase_other_truncate, truncate_9);
  tcase_add_test(tcase_other_truncate, truncate_10);
  tcase_add_test(tcase_other_truncate, truncate_11);
  suite_add_tcase(suite, tcase_other_truncate);

  // other round
  TCase* tcase_other_round = tcase_create("s21_other_round_tcase");
  tcase_add_test(tcase_other_round, round_1);
  tcase_add_test(tcase_other_round, round_2);
  tcase_add_test(tcase_other_round, round_3);
  tcase_add_test(tcase_other_round, round_4);
  tcase_add_test(tcase_other_round, round_5);
  tcase_add_test(tcase_other_round, round_6);
  tcase_add_test(tcase_other_round, round_7);
  tcase_add_test(tcase_other_round, round_8);
  tcase_add_test(tcase_other_round, round_9);
  tcase_add_test(tcase_other_round, round_10);
  tcase_add_test(tcase_other_round, round_11);
  tcase_add_test(tcase_other_round, round_12);
  tcase_add_test(tcase_other_round, round_13);
  tcase_add_test(tcase_other_round, round_14);
  tcase_add_test(tcase_other_round, round_15);
  tcase_add_test(tcase_other_round, round_16);
  tcase_add_test(tcase_other_round, round_17);
  tcase_add_test(tcase_other_round, round_18);
  suite_add_tcase(suite, tcase_other_round);

  // conversion from decimal to float
  TCase* tcase_conversion_decflo = tcase_create("s21_conversion_decflo_tcase");
  tcase_add_test(tcase_conversion_decflo, decflo_1);
  tcase_add_test(tcase_conversion_decflo, decflo_2);
  tcase_add_test(tcase_conversion_decflo, decflo_3);
  tcase_add_test(tcase_conversion_decflo, decflo_4);
  tcase_add_test(tcase_conversion_decflo, decflo_5);
  tcase_add_test(tcase_conversion_decflo, decflo_6);
  suite_add_tcase(suite, tcase_conversion_decflo);

  // conversion from decimal to int
  TCase* tcase_conversion_decint = tcase_create("s21_conversion_decint_tcase");
  tcase_add_test(tcase_conversion_decint, decint_1);
  tcase_add_test(tcase_conversion_decint, decint_2);
  tcase_add_test(tcase_conversion_decint, decint_3);
  tcase_add_test(tcase_conversion_decint, decint_4);
  tcase_add_test(tcase_conversion_decint, decint_5);
  tcase_add_test(tcase_conversion_decint, decint_6);
  tcase_add_test(tcase_conversion_decint, decint_7);
  tcase_add_test(tcase_conversion_decint, decint_8);
  tcase_add_test(tcase_conversion_decint, decint_9);
  suite_add_tcase(suite, tcase_conversion_decint);

  // conversion from float to decimal
  TCase* tcase_conversion_flodec = tcase_create("s21_conversion_flodec_tcase");
  tcase_add_test(tcase_conversion_flodec, flodec_1);
  tcase_add_test(tcase_conversion_flodec, flodec_2);
  tcase_add_test(tcase_conversion_flodec, flodec_3);
  tcase_add_test(tcase_conversion_flodec, flodec_4);
  tcase_add_test(tcase_conversion_flodec, flodec_5);
  tcase_add_test(tcase_conversion_flodec, flodec_6);
  tcase_add_test(tcase_conversion_flodec, flodec_7);
  tcase_add_test(tcase_conversion_flodec, flodec_8);
  tcase_add_test(tcase_conversion_flodec, flodec_9);
  tcase_add_test(tcase_conversion_flodec, flodec_10);
  tcase_add_test(tcase_conversion_flodec, flodec_11);
  tcase_add_test(tcase_conversion_flodec, flodec_12);
  tcase_add_test(tcase_conversion_flodec, flodec_13);
  tcase_add_test(tcase_conversion_flodec, flodec_14);
  suite_add_tcase(suite, tcase_conversion_flodec);

  // conversion from int to decimal
  TCase* tcase_conversion_intdec = tcase_create("s21_conversion_intdec_tcase");
  tcase_add_test(tcase_conversion_intdec, intdec_1);
  tcase_add_test(tcase_conversion_intdec, intdec_2);
  tcase_add_test(tcase_conversion_intdec, intdec_3);
  tcase_add_test(tcase_conversion_intdec, intdec_4);
  tcase_add_test(tcase_conversion_intdec, intdec_5);
  tcase_add_test(tcase_conversion_intdec, intdec_6);
  tcase_add_test(tcase_conversion_intdec, intdec_7);
  suite_add_tcase(suite, tcase_conversion_intdec);

  return suite;
}

int main() {
  int error = 0;
  Suite* decimal = s21_decimal_tests();
  SRunner* test = srunner_create(decimal);
  srunner_run_all(test, CK_VERBOSE);
  error += srunner_ntests_failed(test);
  srunner_free(test);

  printf("Count of errors in the tests: %d\n", error);
}