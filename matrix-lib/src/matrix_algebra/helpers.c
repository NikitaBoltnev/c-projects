#include "../s21_matrix.h"

/**
 * @brief Creates a submatrix by excluding a specific row and column from the
 * original matrix.
 *
 * This function fills 'result' with elements from 'A', skipping the specified
 * row and column. The result matrix must already have memory allocated with
 * dimensions (A.rows - 1) x (A.columns - 1).
 *
 * @param A Pointer to the source matrix
 * @param row Row index to exclude
 * @param col Column index to exclude
 * @param result Pointer to the pre-allocated matrix where the submatrix will be
 * stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if result has incorrect dimensions or
 * input is invalid
 */
int s21_create_submatrix(matrix_t *A, int rows, int columns, matrix_t *result) {
  if (result->rows != A->rows - 1 || result->columns != A->columns - 1)
    return MATRIX_INVALID_ERROR;

  int result_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == rows) continue;

    int result_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == columns) continue;

      result->matrix[result_i][result_j] = A->matrix[i][j];
      result_j++;
    }
    result_i++;
  }

  return MATRIX_OK;
}