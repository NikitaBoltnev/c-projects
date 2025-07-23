#include "../s21_matrix.h"

/**
 * @brief Checks if the given matrix is valid.
 *
 * This function verifies that:
 * - The matrix pointer is not NULL.
 * - The internal matrix array (matrix->matrix) is not NULL.
 * - The matrix has valid dimensions (rows > 0 and columns > 0).
 *
 * @param matrix Pointer to the matrix to be validated.
 *
 * @return int MATRIX_OK (0) if the matrix is valid,
 *         MATRIX_INVALID_ERROR (1) if the matrix is invalid or NULL.
 */
int s21_checking_correctness_matrix(matrix_t *matrix) {
  int err = MATRIX_OK;

  if (matrix == NULL) {
    err = MATRIX_INVALID_ERROR;
  } else if (matrix->matrix == NULL) {
    err = MATRIX_INVALID_ERROR;
  } else if (matrix->rows <= 0 || matrix->columns <= 0) {
    err = MATRIX_INVALID_ERROR;
  }

  return err;
}

/**
 * @brief Checks if all given matrices have the same dimensions (rows and
 * columns).
 *
 * If less than 2 matrices are provided, the function returns success.
 *
 * @param count Number of matrices to compare
 * @param A First matrix for comparison
 * @param ... Additional matrices to compare with A
 *
 * @return int MATRIX_OK (0) if all matrices match in size,
 *         MATRIX_CALC_ERROR (2) if at least one matrix has different dimensions
 */
int s21_checking_same_size_matrix(matrix_t *A, matrix_t *B) {
  int err = MATRIX_OK;

  if (A->columns != B->columns || A->rows != B->rows) {
    err = MATRIX_CALC_ERROR;
  }

  return err;
}