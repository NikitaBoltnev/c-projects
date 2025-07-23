#include "test_s21_matrix.h"

START_TEST(correct_mult_matrix_1) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;

  matrix_2.matrix[0][0] = 5;
  matrix_2.matrix[0][1] = 6;
  matrix_2.matrix[1][0] = 7;
  matrix_2.matrix[1][1] = 8;

  ck_assert_int_eq(0, s21_mult_matrix(&matrix_1, &matrix_2, &res));

  ck_assert_double_eq(res.matrix[0][0], 19);
  ck_assert_double_eq(res.matrix[0][1], 22);
  ck_assert_double_eq(res.matrix[1][0], 43);
  ck_assert_double_eq(res.matrix[1][1], 50);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(correct_mult_matrix_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;

  matrix_2.matrix[0][0] = 0;
  matrix_2.matrix[0][1] = 0;
  matrix_2.matrix[1][0] = 0;
  matrix_2.matrix[1][1] = 0;

  ck_assert_int_eq(0, s21_mult_matrix(&matrix_1, &matrix_2, &res));

  ck_assert_double_eq(res.matrix[0][0], 0);
  ck_assert_double_eq(res.matrix[0][1], 0);
  ck_assert_double_eq(res.matrix[1][0], 0);
  ck_assert_double_eq(res.matrix[1][1], 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(wrong_mult_matrix_1) {
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix_2);

  ck_assert_int_eq(1, s21_mult_matrix(&matrix_1, &matrix_2, &res));

  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_mult_matrix_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  ck_assert_int_eq(1, s21_mult_matrix(&matrix_1, &matrix_2, NULL));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(wrong_mult_matrix_3) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(3, 2, &matrix_2);

  ck_assert_int_eq(2, s21_mult_matrix(&matrix_1, &matrix_2, &res));

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, correct_mult_matrix_1);
  tcase_add_test(tc, correct_mult_matrix_2);
  tcase_add_test(tc, wrong_mult_matrix_1);
  tcase_add_test(tc, wrong_mult_matrix_2);
  tcase_add_test(tc, wrong_mult_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}