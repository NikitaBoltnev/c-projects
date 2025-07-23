#include "test_s21_matrix.h"

START_TEST(correct_transpose_1) {
  matrix_t matrix = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;

  ck_assert_int_eq(0, s21_transpose(&matrix, &res));

  ck_assert_double_eq(res.matrix[0][0], 1);
  ck_assert_double_eq(res.matrix[0][1], 3);
  ck_assert_double_eq(res.matrix[1][0], 2);
  ck_assert_double_eq(res.matrix[1][1], 4);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(correct_transpose_2) {
  matrix_t matrix = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 6;

  ck_assert_int_eq(0, s21_transpose(&matrix, &res));

  ck_assert_double_eq(res.matrix[0][0], 1);
  ck_assert_double_eq(res.matrix[0][1], 3);
  ck_assert_double_eq(res.matrix[0][2], 5);
  ck_assert_double_eq(res.matrix[1][0], 2);
  ck_assert_double_eq(res.matrix[1][1], 4);
  ck_assert_double_eq(res.matrix[1][2], 6);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(wrong_transpose_1) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t res = {0};

  ck_assert_int_eq(1, s21_transpose(&matrix, &res));
}
END_TEST

START_TEST(wrong_transpose_2) {
  matrix_t res = {0};

  ck_assert_int_eq(1, s21_transpose(NULL, &res));
}
END_TEST

START_TEST(wrong_transpose_3) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 2, &matrix);

  ck_assert_int_eq(1, s21_transpose(&matrix, NULL));

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_transpose_1);
  tcase_add_test(tc, correct_transpose_2);
  tcase_add_test(tc, wrong_transpose_1);
  tcase_add_test(tc, wrong_transpose_2);
  tcase_add_test(tc, wrong_transpose_3);

  suite_add_tcase(s, tc);

  return s;
}