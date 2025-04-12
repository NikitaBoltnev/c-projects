#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_SCALE 28
#define MAX_DECIMAL 79228162514264337593543950335.0

#define INIT_ZERO_BIG_DECIMAL(zero) \
  s21_big_decimal zero = {{0, 0, 0, 0, 0, 0, 0}}
#define INIT_ONE_BIG_DECIMAL(one) s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}}
#define INIT_TEN_BIG_DECIMAL(ten) s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}}
#define INIT_FIVE_TENTHS_DECIMAL(five_tenths) \
  s21_decimal five_tenths = {{5, 0, 0, 1 << 16}}

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[7];
} s21_big_decimal;

typedef struct {
  int flag;                     // result status or error code
  int sign_first;               // sign of the first decimal value
  int sign_second;              // sign of the second decimal value
  int sign_result;              // sign of the result
  s21_big_decimal big_value_1;  // first value in big decimal format
  s21_big_decimal big_value_2;  // second value in big decimal format
  s21_big_decimal big_result;   // result in big decimal format
  int scale_first;              // scale of the first decimal value
  int scale_second;             // scale of the second decimal value
  int scale_result;             // scale of the result
} decimal_context;

// general helpers
int s21_checking_big_decimal_for_zero(s21_big_decimal *value);
int s21_checking_decimal_for_zero(s21_decimal *value);
void s21_dividing_by_ten_big(s21_big_decimal *num);
void s21_extract_remainder(s21_big_decimal *value, int *scale,
                           s21_big_decimal *remainder,
                           s21_decimal *normalized_remainder);
int s21_get_bit(int number_bit, s21_decimal decimal);
int s21_get_bit_big(int number_bit, s21_big_decimal decimal);
int s21_get_scale(int number);
int s21_get_sign(int number);
void s21_installation_same_scale(s21_big_decimal *value_1,
                                 s21_big_decimal *value_2, int *scale_first,
                                 int *scale_second);
void s21_normalizing_decimal(s21_big_decimal big_result, int scale_result,
                             s21_decimal *result);
void s21_set_bit_one_big(int number_bit, s21_big_decimal *decimal);
void s21_set_bit_one(int number_bit, s21_decimal *decimal);
void s21_set_bit_zero(int number_bit, s21_decimal *decimal);
void s21_set_bit_zero_big(int number_bit, s21_big_decimal *decimal);
void s21_set_scale(s21_decimal *decimal, int scale);
void s21_set_sign(s21_decimal *decimal, int sign);
void s21_shift_left(s21_big_decimal *decimal);
void s21_transfer_to_big_decimal(s21_decimal normal, s21_big_decimal *big);
void s21_zeroing_big_decimal(s21_big_decimal *value);
void s21_zeroing_decimal(s21_decimal *value);

// arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// arithmetic helpers
void s21_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result);
void s21_bank_rounding(s21_big_decimal *value, int *scale);
void s21_calculate_remainder(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result, int *scale_result);
int s21_check_overflow(s21_big_decimal *big_resul);
void s21_division(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result, int *scale_result);
void s21_init_decimal_context(decimal_context *variables, s21_decimal value_1,
                              s21_decimal value_2);
void s21_multiplication(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
void s21_removing_extra_scale(s21_decimal *value);
void s21_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
void s21_finalize_result(decimal_context *ctx, s21_decimal *result);

// comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// comparison helpers
int s21_b_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_b_is_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_b_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);

// convertors
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// convertors helpers
void s21_delete_extra_zeroes(int *ch, int *check_dot, char *number);
void s21_dot_check(char *number, int *ch, int *temp, int *scale_check);
void s21_scale_check(int *scale, int *ch, int *scale_check, int *check);
void s21_dividing_by_ten(s21_decimal *value, unsigned *rest);

// other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif