#include "../s21_matrix.h"

/**
 * @brief Adds two matrices and stores the result in a third matrix.
 *
 * The function checks if matrices A and B are valid and have the same
 * dimensions. If successful, the sum is stored in 'result'. If an overflow or
 * NaN occurs, MATRIX_CALC_ERROR is returned.
 *
 * @param A Pointer to the first input matrix
 * @param B Pointer to the second input matrix
 * @param result Pointer to the matrix where the result will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if any matrix is NULL or invalid
 *         - MATRIX_CALC_ERROR (2) if matrices have different sizes or
 * calculation error occurred
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;
  if (s21_checking_correctness_matrix(B)) return MATRIX_INVALID_ERROR;

  if (s21_checking_same_size_matrix(A, B)) return MATRIX_CALC_ERROR;

  int err = s21_create_matrix(A->rows, A->columns, result);
  if (err) return err;

  for (int i = 0; i < A->rows && !err; i++) {
    for (int j = 0; j < A->columns && !err; j++) {
      double sum = 0;
      sum = A->matrix[i][j] + B->matrix[i][j];
      // Check for infinity or NaN values resulting from addition
      if (!isfinite(sum)) {
        err = MATRIX_CALC_ERROR;
      } else {
        result->matrix[i][j] = sum;
      }
    }
  }

  if (err) {
    s21_remove_matrix(result);
  }

  return err;
}
