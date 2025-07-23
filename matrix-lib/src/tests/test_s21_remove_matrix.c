#include "test_s21_matrix.h"

START_TEST(correct_remove_matrix) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 3, &matrix);

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(wrong_remove_matrix) {
  matrix_t matrix = {NULL, 0, 0};

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

Suite *s21_remove_matrix_suite() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_remove_matrix);
  tcase_add_test(tc, wrong_remove_matrix);

  suite_add_tcase(s, tc);

  return s;
}