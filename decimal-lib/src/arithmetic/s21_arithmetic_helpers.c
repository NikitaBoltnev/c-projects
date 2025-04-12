#include "../s21_decimal.h"

void s21_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result) {
  // performing the addition

  int carry = 0;

  // bitwise addition
  for (int i = 0; i < 224; i++) {
    int bit_1 = s21_get_bit_big(i, value_1);
    int bit_2 = s21_get_bit_big(i, value_2);
    int sum = bit_1 + bit_2 + carry;

    // if sum is even, write 0 to result, if odd, write 1
    if (sum % 2 == 1) {
      s21_set_bit_one_big(i, result);
    } else {
      s21_set_bit_zero_big(i, result);
    }

    carry = sum / 2;
  }
}

void s21_bank_rounding(s21_big_decimal *value, int *scale) {
  // performing of bank rounding

  INIT_FIVE_TENTHS_DECIMAL(five_tenths);
  INIT_ONE_BIG_DECIMAL(one);
  INIT_ZERO_BIG_DECIMAL(remainder);
  s21_decimal normalized_remainder = {0};

  // extract remainder and normalize it while reducing scale to zero
  s21_extract_remainder(value, scale, &remainder, &normalized_remainder);

  // checking the remainder and choosing rounding
  if (s21_is_greater(normalized_remainder, five_tenths)) {
    s21_addition(*value, one, value);  // remainder > 0.5 result is plus one
  } else if (s21_is_equal(normalized_remainder, five_tenths)) {
    if (s21_get_bit_big(0, *value)) {    // remainder == 0.5, and number is odd
      s21_addition(*value, one, value);  // result is plus one
    }
  }
}

void s21_calculate_remainder(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result, int *scale_result) {
  // calculations for the remainder

  *scale_result = 0;
  s21_big_decimal remainder = value_1;

  if (!s21_checking_big_decimal_for_zero(&remainder)) {
    INIT_ZERO_BIG_DECIMAL(zero);
    INIT_TEN_BIG_DECIMAL(ten);
    INIT_ONE_BIG_DECIMAL(one);

    // calculate the remainder and scale the result by multiplying by 10 and
    // counting digits
    while (s21_b_is_greater(remainder, zero) && *scale_result < MAX_SCALE) {
      s21_multiplication(remainder, ten, &remainder);
      INIT_ZERO_BIG_DECIMAL(digit);
      while (s21_b_is_greater_or_equal(remainder, value_2)) {
        s21_subtraction(remainder, value_2, &remainder);
        s21_addition(digit, one, &digit);
      }

      s21_multiplication(*result, ten, result);
      s21_addition(*result, digit, result);
      (*scale_result)++;
    }
  }
}

int s21_check_overflow(s21_big_decimal *big_result) {
  // checks that the correct normalization of a large decimal is not possible

  int flag = 0;
  if (big_result->bits[3] != 0 || big_result->bits[4] != 0 ||
      big_result->bits[5] != 0 || big_result->bits[6] != 0) {
    flag = 1;
  }
  return flag;
}

void s21_division(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result, int *scale_result) {
  // performing division

  // calculations for the whole part
  while (s21_b_is_greater_or_equal(value_1, value_2)) {
    INIT_ONE_BIG_DECIMAL(res);
    s21_big_decimal temp = value_2;
    int shift = 0;

    while (s21_b_is_greater_or_equal(value_1, temp)) {
      s21_shift_left(&temp);
      shift++;
    }

    if (shift > 0) {
      shift--;
      temp = value_2;
      for (int i = 0; i < shift; i++) {
        s21_shift_left(&res);
        s21_shift_left(&temp);
      }
    }

    s21_addition(*result, res, result);
    s21_subtraction(value_1, temp, &value_1);
  }

  s21_calculate_remainder(value_1, value_2, result, scale_result);
}

void s21_init_decimal_context(decimal_context *variables, s21_decimal value_1,
                              s21_decimal value_2) {
  // initializes decimal_context for arithmetic operations

  variables->flag = 0;  // return value

  variables->sign_first = s21_get_sign(value_1.bits[3]);   // first sign
  variables->sign_second = s21_get_sign(value_2.bits[3]);  // second sign
  variables->sign_result = 0;                              // result sign

  variables->big_value_1 = (s21_big_decimal){0};  // first big decimal
  variables->big_value_2 = (s21_big_decimal){0};  // second big decimal
  variables->big_result = (s21_big_decimal){0};   // result big decimal

  variables->scale_first = s21_get_scale(value_1.bits[3]);   // first scale
  variables->scale_second = s21_get_scale(value_2.bits[3]);  // second scale
  variables->scale_result = 0;                               // result scale
}

void s21_multiplication(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  // performing multiplication

  INIT_ZERO_BIG_DECIMAL(res);

  // multiplication by a column in reverse order
  for (int i = 223; i >= 0; i--) {
    if (s21_get_bit_big(i, value_1)) {
      s21_addition(value_2, res, &res);
    }

    if (i) {  // shift it until then i != 0
      s21_shift_left(&res);
    }
  }

  *result = res;
}

void s21_removing_extra_scale(s21_decimal *value) {
  // Removes fractional part if the number is integer

  s21_decimal temp = *value;
  s21_truncate(temp, &temp);
  if (s21_is_equal(temp, *value)) {
    *value = temp;
  }
}

void s21_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  // performing the subtraction

  INIT_ZERO_BIG_DECIMAL(two_complement);
  INIT_ONE_BIG_DECIMAL(one);

  // invert all the bits and then add one to get the two's complement,
  // which is the negative version of the number value_2
  for (int i = 0; i < 7; i++) {
    value_2.bits[i] = ~value_2.bits[i];
  }
  s21_addition(value_2, one, &two_complement);

  // add value_1 and the negative version of value_2
  s21_addition(value_1, two_complement, result);
}

void s21_finalize_result(decimal_context *ctx, s21_decimal *result) {
  // finalizes the result of a decimal operation.

  // bank rounding
  if (s21_check_overflow(&ctx->big_result)) {
    s21_bank_rounding(&ctx->big_result, &ctx->scale_result);
  }

  // normalizing or set the error flag
  if (s21_check_overflow(&ctx->big_result)) {
    ctx->flag = ctx->sign_result ? 2 : 1;
  } else {
    s21_normalizing_decimal(ctx->big_result, ctx->scale_result, result);
    s21_removing_extra_scale(result);
  }

  // set result sign
  s21_set_sign(result, ctx->sign_result);
  if (ctx->flag == 1 || ctx->flag == 2 ||
      s21_checking_decimal_for_zero(result)) {
    s21_set_bit_zero(127, result);
  }
}
