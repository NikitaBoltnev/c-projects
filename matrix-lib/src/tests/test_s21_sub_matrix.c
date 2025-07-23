#include "test_s21_matrix.h"

START_TEST(correct_sub_matrix) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t matrix_result = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  matrix_1.matrix[0][0] = 5;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 2;

  matrix_2.matrix[0][0] = 2;
  matrix_2.matrix[0][1] = 3;
  matrix_2.matrix[1][0] = 4;
  matrix_2.matrix[1][1] = 5;

  ck_assert_int_eq(0, s21_sub_matrix(&matrix_1, &matrix_2, &matrix_result));

  ck_assert_double_eq(3, matrix_result.matrix[0][0]);
  ck_assert_double_eq(1, matrix_result.matrix[0][1]);
  ck_assert_double_eq(-1, matrix_result.matrix[1][0]);
  ck_assert_double_eq(-3, matrix_result.matrix[1][1]);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(wrong_sub_matrix_1) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t matrix_result = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(9, 2, &matrix_2);

  ck_assert_int_eq(2, s21_sub_matrix(&matrix_1, &matrix_2, &matrix_result));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_sub_matrix_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t matrix_result = {0};

  s21_create_matrix(9, 2, &matrix_2);

  ck_assert_int_eq(1, s21_sub_matrix(&matrix_1, &matrix_2, &matrix_result));

  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_sub_matrix_3) {
  matrix_t matrix = {0};
  matrix_t matrix_result = {0};

  s21_create_matrix(9, 2, &matrix);

  ck_assert_int_eq(1, s21_sub_matrix(&matrix, NULL, &matrix_result));

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_sub_matrix_4) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(9, 2, &matrix_2);

  ck_assert_int_eq(1, s21_sub_matrix(&matrix_1, &matrix_2, NULL));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *s21_sub_matrix_suite() {
  Suite *s = suite_create("s21_sub_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_sub_matrix);
  tcase_add_test(tc, wrong_sub_matrix_1);
  tcase_add_test(tc, wrong_sub_matrix_2);
  tcase_add_test(tc, wrong_sub_matrix_3);
  tcase_add_test(tc, wrong_sub_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}
