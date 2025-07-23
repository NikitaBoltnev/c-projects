#include "test_s21_matrix.h"

int main() {
  int errors = 0;

  SRunner *sr = srunner_create(s21_create_matrix_suite());

  srunner_add_suite(sr, s21_calc_complements_suite());
  srunner_add_suite(sr, s21_determinant_suite());
  srunner_add_suite(sr, s21_eq_matrix_suite());
  srunner_add_suite(sr, s21_inverse_matrix_suite());
  srunner_add_suite(sr, s21_mult_matrix_suite());
  srunner_add_suite(sr, s21_mult_number_suite());
  srunner_add_suite(sr, s21_remove_matrix_suite());
  srunner_add_suite(sr, s21_sub_matrix_suite());
  srunner_add_suite(sr, s21_sum_matrix_suite());
  srunner_add_suite(sr, s21_transpose_suite());

  srunner_run_all(sr, CK_VERBOSE);

  errors = srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("Count of errors in the tests: %d\n", errors);

  return 0;
}