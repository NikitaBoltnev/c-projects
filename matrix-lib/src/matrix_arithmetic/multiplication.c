
#include "../s21_matrix.h"

/**
 * @brief Multiplies a matrix by a  number and stores the result in another
 * matrix.
 *
 * If successful, each element of matrix A is multiplied by 'number' and stored
 * in 'result'. If an overflow or NaN occurs during multiplication,
 * MATRIX_CALC_ERROR is returned.
 *
 * @param A Pointer to the source matrix
 * @param number Value to multiply with each element of A
 * @param result Pointer to the matrix where the result will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if A or result is NULL or matrix data is
 * invalid
 *         - MATRIX_CALC_ERROR (2) if calculation resulted in infinity or NaN
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;

  int err = s21_create_matrix(A->rows, A->columns, result);
  if (err) return err;

  for (int i = 0; i < A->rows && !err; i++) {
    for (int j = 0; j < A->columns && !err; j++) {
      double mul = number * A->matrix[i][j];
      // Check for infinity or NaN values resulting from multiplication
      if (!isfinite(mul)) {
        err = MATRIX_CALC_ERROR;
      } else {
        result->matrix[i][j] = mul;
      }
    }
  }

  if (err) {
    s21_remove_matrix(result);
  }

  return err;
}

/**
 * @brief Multiplies two matrices A and B and stores the result in matrix
 * 'result'.
 *
 * The number of columns in matrix A must match the number of rows in matrix B.
 * If successful, the resulting matrix will have dimensions A.rows x B.columns.
 * If an overflow or NaN occurs during multiplication, MATRIX_CALC_ERROR is
 * returned.
 *
 * @param A Pointer to the first input matrix
 * @param B Pointer to the second input matrix
 * @param result Pointer to the matrix where the result will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) if any matrix is NULL or invalid
 *         - MATRIX_CALC_ERROR (2) if matrices cannot be multiplied or
 * calculation error occurred
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (result == NULL) return MATRIX_INVALID_ERROR;

  if (s21_checking_correctness_matrix(A)) return MATRIX_INVALID_ERROR;
  if (s21_checking_correctness_matrix(B)) return MATRIX_INVALID_ERROR;

  if (s21_check_matrix_mult(A, B)) return MATRIX_CALC_ERROR;

  int err = s21_create_matrix(A->rows, B->columns, result);
  if (err) return err;

  int common_dim = A->columns;
  for (int i = 0; i < A->rows && !err; i++) {
    for (int j = 0; j < B->columns && !err; j++) {
      double mul = 0;
      // Multiply row i of A with column j of B
      for (int k = 0; k < common_dim && !err; k++)
        mul += A->matrix[i][k] * B->matrix[k][j];
      // Check for infinity or NaN values resulting from multiplication
      if (!isfinite(mul)) {
        err = MATRIX_CALC_ERROR;
      } else {
        result->matrix[i][j] = mul;
      }
    }
  }

  if (err) {
    s21_remove_matrix(result);
  }

  return err;
}

/**
 * @brief Checks if two matrices can be multiplied.
 *
 * Matrices can be multiplied only if the number of columns in A equals the
 * number of rows in B.
 *
 * @param A Pointer to the first matrix
 * @param B Pointer to the second matrix
 *
 * @return int MATRIX_OK (0) if matrices can be multiplied,
 *         MATRIX_CALC_ERROR (2) if they cannot
 */
int s21_check_matrix_mult(matrix_t *A, matrix_t *B) {
  int check = MATRIX_OK;
  if (A->columns != B->rows) check = MATRIX_CALC_ERROR;

  return check;
}