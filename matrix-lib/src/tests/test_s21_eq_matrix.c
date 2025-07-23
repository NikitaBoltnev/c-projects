#include "test_s21_matrix.h"

START_TEST(correct_eq_matrix) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = i * j;
      matrix_2.matrix[i][j] = i * j;
    }
  }

  ck_assert_int_eq(1, s21_eq_matrix(&matrix_1, &matrix_2));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_eq_matrix_1) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = i * j;
      matrix_2.matrix[i][j] = i * j;
    }
  }

  ck_assert_int_eq(0, s21_eq_matrix(&matrix_1, &matrix_2));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_eq_matrix_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = i * j;
      matrix_2.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(0, s21_eq_matrix(&matrix_1, &matrix_2));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_eq_matrix_3) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {NULL, 3, 3};

  s21_create_matrix(3, 3, &matrix_1);

  ck_assert_int_eq(0, s21_eq_matrix(&matrix_1, &matrix_2));

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(wrong_eq_matrix_4) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 3, &matrix);

  ck_assert_int_eq(0, s21_eq_matrix(&matrix, NULL));

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_eq_matrix);
  tcase_add_test(tc, wrong_eq_matrix_1);
  tcase_add_test(tc, wrong_eq_matrix_2);
  tcase_add_test(tc, wrong_eq_matrix_3);
  tcase_add_test(tc, wrong_eq_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}