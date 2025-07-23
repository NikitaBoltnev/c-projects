#include "../s21_matrix.h"

/**
 * @brief Computes the inverse of a square matrix A if it exists.
 *
 * The matrix must be square and have a non-zero determinant. If successful,
 * the inverse is stored in 'result'. Otherwise, an error code is returned.
 *
 * @param A Pointer to the source square matrix
 * @param result Pointer to the matrix where the inverse will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or invalid
 *         - MATRIX_CALC_ERROR (2) if matrix is singular or calculation failed
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;

  if (A->rows != A->columns) return MATRIX_CALC_ERROR;

  int err = MATRIX_OK;
  double det = 0;

  err = s21_determinant(A, &det);
  if (err) return err;

  if (fabs(det) < 1e-6)
    // Check if determinant is effectively zero to avoid division by near-zero
    // values
    return MATRIX_CALC_ERROR;

  // Compute inverse using adjugate matrix and determinant
  err = s21_finalize_inverse(A, result, det);

  return err;
}

/**
 * @brief Finalizes matrix inversion using the adjugate method.
 *
 * This function computes the inverse using the formula: inv(A) = (1/det(A)) *
 * adj(A), where adj(A) is the adjugate (transpose of the cofactor matrix).
 *
 * @param A Pointer to the original matrix
 * @param result Pointer to the matrix where the inverse will be stored
 * @param det Determinant of matrix A (must be non-zero)
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if input is invalid
 *         - MATRIX_CALC_ERROR (2) if calculation failed (e.g., division by zero
 * or NaN)
 */
int s21_finalize_inverse(matrix_t *A, matrix_t *result, double det) {
  // Create cofactor matrix to compute adjugate
  matrix_t cofactors = {0};
  int err = s21_calc_complements(A, &cofactors);

  if (!err) {
    // Adjugate matrix is the transpose of the cofactor matrix
    err = s21_transpose(&cofactors, result);
  }

  for (int i = 0; i < A->rows && !err; i++) {
    for (int j = 0; j < A->columns && !err; j++) {
      // Scale by inverse of determinant: inv(A) = (1/det(A)) * adj(A)
      double value = (1 / det) * (result->matrix[i][j]);
      // Ensure scaled value is finite (not NaN or infinity)
      if (!isfinite(value)) {
        err = MATRIX_CALC_ERROR;
      } else {
        result->matrix[i][j] = value;
      }
    }
  }

  s21_remove_matrix(&cofactors);

  if (err && result->matrix != NULL) {
    s21_remove_matrix(result);
  }

  return err;
}