#include "test_s21_matrix.h"

START_TEST(correct_calc_complements_1) {
  matrix_t matrix = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;

  ck_assert_int_eq(0, s21_calc_complements(&matrix, &res));

  ck_assert_double_eq(4, res.matrix[0][0]);
  ck_assert_double_eq(-3, res.matrix[0][1]);
  ck_assert_double_eq(-2, res.matrix[1][0]);
  ck_assert_double_eq(1, res.matrix[1][1]);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(correct_calc_complements_2) {
  matrix_t matrix = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 5;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 0;
  matrix.matrix[2][2] = 6;

  ck_assert_int_eq(0, s21_calc_complements(&matrix, &res));

  ck_assert_double_eq(24, res.matrix[0][0]);
  ck_assert_double_eq(5, res.matrix[0][1]);
  ck_assert_double_eq(-4, res.matrix[0][2]);
  ck_assert_double_eq(-12, res.matrix[1][0]);
  ck_assert_double_eq(3, res.matrix[1][1]);
  ck_assert_double_eq(2, res.matrix[1][2]);
  ck_assert_double_eq(-2, res.matrix[2][0]);
  ck_assert_double_eq(-5, res.matrix[2][1]);
  ck_assert_double_eq(4, res.matrix[2][2]);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(wrong_calc_complements_1) {
  matrix_t matrix = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 2, &matrix);

  ck_assert_int_eq(2, s21_calc_complements(&matrix, &res));

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_calc_complements_2) {
  matrix_t matrix = {0};

  s21_create_matrix(3, 2, &matrix);

  ck_assert_int_eq(1, s21_calc_complements(&matrix, NULL));

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(wrong_calc_complements_3) {
  matrix_t res = {0};

  ck_assert_int_eq(1, s21_calc_complements(NULL, &res));
}
END_TEST

START_TEST(wrong_calc_complements_4) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t res = {0};

  ck_assert_int_eq(1, s21_calc_complements(&matrix, &res));
}
END_TEST

Suite *s21_calc_complements_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_calc_complements_1);
  tcase_add_test(tc, correct_calc_complements_2);
  tcase_add_test(tc, wrong_calc_complements_1);
  tcase_add_test(tc, wrong_calc_complements_2);
  tcase_add_test(tc, wrong_calc_complements_3);
  tcase_add_test(tc, wrong_calc_complements_4);

  suite_add_tcase(s, tc);

  return s;
}
