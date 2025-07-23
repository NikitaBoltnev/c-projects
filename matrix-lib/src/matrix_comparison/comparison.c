#include "../s21_matrix.h"

/**
 * @brief Compares two matrices for equality with tolerance for floating-point
 * errors.
 *
 * Matrices are considered equal if they have the same dimensions and all
 * corresponding elements differ by no more than 1e-7.
 *
 * @param A Pointer to the first matrix
 * @param B Pointer to the second matrix
 *
 * @return int SUCCESS (1) if matrices are equal, FAILURE (0) otherwise
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_checking_correctness_matrix(A)) return FAILURE;
  if (s21_checking_correctness_matrix(B)) return FAILURE;

  int is_equal = SUCCESS;

  if (s21_checking_same_size_matrix(A, B)) is_equal = FAILURE;

  if (is_equal) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        // Check if the absolute difference between elements is greater than
        // allowed epsilon (1e-7)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) is_equal = FAILURE;
      }
    }
  }

  return is_equal;
}