#include "../s21_matrix.h"

/**
 * @brief Computes the determinant of a square matrix.
 *
 * This function calculates the determinant of a given square matrix A and
 * stores the result in 'result'. It handles matrices of size 1x1, 2x2, and
 * larger using recursion.
 *
 * @param A Pointer to the input matrix
 * @param result Pointer where the computed determinant will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or matrix data is
 * invalid
 *         - MATRIX_CALC_ERROR (2) if calculation resulted in infinity or NaN
 */
int s21_determinant(matrix_t *A, double *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;

  if (A->rows != A->columns) return MATRIX_CALC_ERROR;

  double det = 0;
  int err = MATRIX_OK;

  switch (A->rows) {
    case 1:
      det = A->matrix[0][0];
      break;
    case 2:
      err = s21_calculate_det_2x2(A, &det);
      break;
    default:
      err = s21_calculate_det(A, &det);
      break;
  }

  if (!err) *result = det;

  return err;
}

/**
 * @brief Calculates the determinant of a 2x2 matrix.
 *
 * Uses the standard formula: det = ad - bc for a matrix [[a, b], [c, d]].
 *
 * @param A Pointer to a 2x2 matrix
 * @param result Pointer where the computed determinant will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_CALC_ERROR (2) if calculation resulted in infinity or NaN
 */
int s21_calculate_det_2x2(matrix_t *A, double *result) {
  int err = MATRIX_OK;
  double det =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  // Check if determinant is finite (not NaN or infinity)
  if (!isfinite(det))
    err = MATRIX_CALC_ERROR;
  else
    *result = det;

  return err;
}

/**
 * @brief Recursively computes the determinant of a matrix using cofactor
 * expansion.
 *
 * This function uses Laplace expansion along the first row to compute the
 * determinant. For each element in the first row, it creates a submatrix,
 * computes its determinant, and accumulates the result with proper sign.
 *
 * @param A Pointer to a square matrix (size > 2)
 * @param result Pointer where the computed determinant will be stored
 *
 *  @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or matrix data is
 * invalid
 *         - MATRIX_CALC_ERROR (2) if calculation resulted in infinity or NaN
 */
int s21_calculate_det(matrix_t *A, double *result) {
  int err = MATRIX_OK;
  double det = 0;

  for (int j = 0; j < A->columns && !err; j++) {
    matrix_t submatrix = {0};
    double minor_det = 0;

    // Create a submatrix for minor calculation
    err = s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix);

    // Fill the submatrix by excluding current column
    if (!err) err = s21_create_submatrix(A, 0, j, &submatrix);

    // Recursively compute determinant of the submatrix
    if (!err) err = s21_determinant(&submatrix, &minor_det);

    if (!err) {
      // Apply cofactor sign (+/-) and multiply by the corresponding element
      minor_det *= (j % 2 ? -1 : 1) * A->matrix[0][j];
      if (!isfinite(minor_det))  // Check for NaN or infinity
        err = MATRIX_CALC_ERROR;
      else
        // Accumulate total determinant
        det += minor_det;
    }

    if (!isfinite(det))  // Check for NaN or infinity
      err = MATRIX_CALC_ERROR;

    s21_remove_matrix(&submatrix);
  }

  if (!err) *result = det;

  return err;
}