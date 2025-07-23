#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdlib.h>

#define MATRIX_OK 0
#define MATRIX_INVALID_ERROR 1
#define MATRIX_CALC_ERROR 2
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// matrix_algebra
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calculate_det_2x2(matrix_t *A, double *result);
int s21_calculate_det(matrix_t *A, double *result);
int s21_create_submatrix(matrix_t *A, int rows, int columns, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_finalize_inverse(matrix_t *A, matrix_t *result, double det);

// matrix_arithmetic
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_check_matrix_mult(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// matrix_comparison
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// matrix_core
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// matrix_transformations
int s21_transpose(matrix_t *A, matrix_t *result);

// matrix_validation
int s21_checking_correctness_matrix(matrix_t *matrix);
int s21_checking_same_size_matrix(matrix_t *A, matrix_t *B);

#endif