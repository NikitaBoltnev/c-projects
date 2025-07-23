#include "../s21_matrix.h"

/**
 * @brief Calculates the matrix of cofactors (matrix of algebraic complements).
 *
 * The cofactor matrix is formed by replacing each element A[i][j] with its
 * algebraic complement, which is the minor of A[i][j] multiplied by (-1)^(i+j).
 * For a 1x1 matrix, the cofactor is defined as 1.
 *
 * @param A Pointer to the source square matrix
 * @param result Pointer to the matrix where the result will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or invalid
 *         - MATRIX_CALC_ERROR (2) if calculation failed (e.g., memory
 * allocation or determinant error)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;

  if (A->rows != A->columns) return MATRIX_CALC_ERROR;

  int err = s21_create_matrix(A->rows, A->columns, result);
  if (err) {
    return err;
  }

  if (A->rows == 1) {
    result->matrix[0][0] = 1;  // Cofactor of 1x1 matrix is always 1
  } else {
    for (int i = 0; i < A->rows && !err; i++) {
      for (int j = 0; j < A->columns && !err; j++) {
        matrix_t submatrix = {0};
        double minor = 0;

        err = s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix);
        if (!err) {
          // Exclude row i and column j
          err = s21_create_submatrix(A, i, j, &submatrix);
        }
        if (!err) {
          // Compute minor determinant
          err = s21_determinant(&submatrix, &minor);
        }
        if (!err) {
          // Apply cofactor sign: (-1)^(i + j)
          result->matrix[i][j] = minor * pow(-1, i + j);
        }
        s21_remove_matrix(&submatrix);
      }
    }
  }
  if (err) {
    s21_remove_matrix(result);
  }

  return err;
}