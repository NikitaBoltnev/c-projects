#include "test_s21_matrix.h"

START_TEST(correct_create_matrix_1) {
  matrix_t matrix = {0};

  int err = s21_create_matrix(3, 3, &matrix);

  ck_assert_int_eq(0, err);
  ck_assert_int_eq(3, matrix.rows);
  ck_assert_int_eq(3, matrix.columns);

  ck_assert_ptr_nonnull(matrix.matrix);

  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      ck_assert_double_eq(0, matrix.matrix[i][j]);
    }
  }

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_create_matrix_2) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 3, &matrix);

  int err = s21_create_matrix(3, 3, &matrix);

  ck_assert_int_eq(0, err);
  ck_assert_int_eq(3, matrix.rows);
  ck_assert_int_eq(3, matrix.columns);

  ck_assert_ptr_nonnull(matrix.matrix);

  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      ck_assert_double_eq(0, matrix.matrix[i][j]);
    }
  }

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_create_matrix_1) {
  int err = s21_create_matrix(3, 3, NULL);

  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(wrong_create_matrix_2) {
  matrix_t matrix = {0};

  int err = s21_create_matrix(-3, 3, &matrix);

  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(wrong_create_matrix_3) {
  matrix_t matrix = {0};

  int err = s21_create_matrix(3, -3, &matrix);

  ck_assert_int_eq(1, err);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_create_matrix_1);
  tcase_add_test(tc, correct_create_matrix_2);
  tcase_add_test(tc, wrong_create_matrix_1);
  tcase_add_test(tc, wrong_create_matrix_2);
  tcase_add_test(tc, wrong_create_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}
