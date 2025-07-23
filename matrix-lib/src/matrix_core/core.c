#include "../s21_matrix.h"

/**
 * @brief Creates a matrix of given dimensions and initializes all elements to 0
 *
 * Memory is allocated dynamically and must be freed using s21_remove_matrix()
 *
 * @param rows Number of rows in the matrix (must be > 0)
 * @param columns Number of columns in the matrix (must be > 0)
 * @param result Pointer to matrix structure where result will be stored
 *
 * @return int Error code:
 *         - MATRIX_OK (0) if successful
 *         - MATRIX_INVALID_ERROR (1) on invalid input or memory allocation
 * failure
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) return MATRIX_INVALID_ERROR;

  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (result->matrix == NULL) return MATRIX_INVALID_ERROR;

  int err = MATRIX_OK;
  result->rows = rows;
  result->columns = columns;

  for (int i = 0; i < rows && !err; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));

    if (result->matrix[i] == NULL) {
      result->rows = i;
      s21_remove_matrix(result);
      err = MATRIX_INVALID_ERROR;
    }
  }

  return err;
}

/**
 * @brief Frees memory allocated for a matrix and resets its fields
 *
 * This function safely frees all memory associated with the matrix,
 * including individual row pointers and the matrix array itself.
 *
 * @param A Pointer to matrix to be removed
 */
void s21_remove_matrix(matrix_t *A) {
  if (A == NULL) return;
  if (A->matrix == NULL) return;

  if (A->rows > 0) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }

    free(A->matrix);
    A->matrix = NULL;
  }

  A->rows = 0;
  A->columns = 0;
}
