#include "../s21_matrix.h"

/**
 * @brief Transposes a matrix and stores the result in another matrix.
 *
 * The transpose of a matrix is obtained by swapping rows with columns.
 *
 * @param A Pointer to the source matrix
 * @param result Pointer to the matrix where the transposed result will be
 * stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or matrix data is
 * invalid
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;

  int err = s21_create_matrix(A->columns, A->rows, result);
  if (err) return err;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return MATRIX_OK;
}