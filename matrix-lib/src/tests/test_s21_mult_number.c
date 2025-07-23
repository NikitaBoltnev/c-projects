#include "test_s21_matrix.h"

START_TEST(correct_mult_number_1) {
  matrix_t matrix = {0};
  matrix_t res = {0};
  double num = 5;

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 124;
  matrix.matrix[0][1] = 537;
  matrix.matrix[1][0] = 894;
  matrix.matrix[1][1] = 657;

  ck_assert_int_eq(0, s21_mult_number(&matrix, num, &res));

  ck_assert_double_eq(res.matrix[0][0], 620);
  ck_assert_double_eq(res.matrix[0][1], 2685);
  ck_assert_double_eq(res.matrix[1][0], 4470);
  ck_assert_double_eq(res.matrix[1][1], 3285);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(correct_mult_number_2) {
  matrix_t matrix = {0};
  matrix_t res = {0};
  double num = 5;

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = -6;
  matrix.matrix[0][1] = -7;
  matrix.matrix[1][0] = -8;
  matrix.matrix[1][1] = -9;

  ck_assert_int_eq(0, s21_mult_number(&matrix, num, &res));

  ck_assert_double_eq(res.matrix[0][0], -30);
  ck_assert_double_eq(res.matrix[0][1], -35);
  ck_assert_double_eq(res.matrix[1][0], -40);
  ck_assert_double_eq(res.matrix[1][1], -45);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(correct_mult_number_3) {
  matrix_t matrix = {0};
  matrix_t res = {0};
  double num = 0;

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 124;
  matrix.matrix[0][1] = 537;
  matrix.matrix[1][0] = 894;
  matrix.matrix[1][1] = 657;

  ck_assert_int_eq(0, s21_mult_number(&matrix, num, &res));

  ck_assert_double_eq(res.matrix[0][0], 0);
  ck_assert_double_eq(res.matrix[0][1], 0);
  ck_assert_double_eq(res.matrix[1][0], 0);
  ck_assert_double_eq(res.matrix[1][1], 0);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(wrong_mult_number_1) {
  matrix_t matrix = {0};
  double num = 5;

  s21_create_matrix(2, 2, &matrix);

  ck_assert_int_eq(1, s21_mult_number(&matrix, num, NULL));

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_mult_number_2) {
  matrix_t res = {0};
  double num = 5;

  ck_assert_int_eq(1, s21_mult_number(NULL, num, &res));
}
END_TEST

START_TEST(wrong_mult_number_3) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t res = {0};
  double num = 5;

  ck_assert_int_eq(1, s21_mult_number(&matrix, num, &res));
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_mult_number_1);
  tcase_add_test(tc, correct_mult_number_2);
  tcase_add_test(tc, correct_mult_number_3);
  tcase_add_test(tc, wrong_mult_number_1);
  tcase_add_test(tc, wrong_mult_number_2);
  tcase_add_test(tc, wrong_mult_number_3);

  suite_add_tcase(s, tc);

  return s;
}