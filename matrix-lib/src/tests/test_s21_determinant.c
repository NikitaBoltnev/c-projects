#include "test_s21_matrix.h"

START_TEST(correct_determinant_1) {
  matrix_t matrix = {0};
  double res = 0;

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;

  ck_assert_int_eq(0, s21_determinant(&matrix, &res));

  ck_assert_double_eq(-2, res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_determinant_2) {
  matrix_t matrix = {0};
  double res = 0;

  s21_create_matrix(3, 3, &matrix);

  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 6;
  matrix.matrix[1][0] = 99;
  matrix.matrix[1][1] = 88;
  matrix.matrix[1][2] = 77;
  matrix.matrix[2][0] = 12;
  matrix.matrix[2][1] = 38;
  matrix.matrix[2][2] = 52;

  ck_assert_int_eq(0, s21_determinant(&matrix, &res));

  ck_assert_double_eq(1716, res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_determinant_3) {
  matrix_t matrix = {0};
  double res = 0;

  s21_create_matrix(3, 3, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 2;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 3;
  matrix.matrix[2][1] = 6;
  matrix.matrix[2][2] = 9;

  ck_assert_int_eq(0, s21_determinant(&matrix, &res));

  ck_assert_double_eq(0, res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_determinant_1) {
  matrix_t matrix = {0};
  double res = 0;

  s21_create_matrix(4, 3, &matrix);

  ck_assert_int_eq(2, s21_determinant(&matrix, &res));

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_determinant_2) {
  double res = 0;

  ck_assert_int_eq(1, s21_determinant(NULL, &res));
}
END_TEST

START_TEST(wrong_determinant_3) {
  matrix_t matrix = {NULL, 0, 0};
  double res = 0;

  ck_assert_int_eq(1, s21_determinant(&matrix, &res));
}
END_TEST

START_TEST(wrong_determinant_4) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 3, &matrix);

  ck_assert_int_eq(1, s21_determinant(&matrix, NULL));

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_determinant_1);
  tcase_add_test(tc, correct_determinant_2);
  tcase_add_test(tc, correct_determinant_3);
  tcase_add_test(tc, wrong_determinant_1);
  tcase_add_test(tc, wrong_determinant_2);
  tcase_add_test(tc, wrong_determinant_3);
  tcase_add_test(tc, wrong_determinant_4);

  suite_add_tcase(s, tc);

  return s;
}