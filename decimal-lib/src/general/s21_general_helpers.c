#include "../s21_decimal.h"

int s21_checking_big_decimal_for_zero(s21_big_decimal *value) {
  // checking that the mantissa in the big decimal is zero

  int check_zero = 1;

  for (int i = 0; i < 7; i++) {
    if (value->bits[i] != 0) {
      check_zero = 0;
    }
  }

  // removing the scale if the mantissa is zero
  if (check_zero == 1) {
    s21_zeroing_big_decimal(value);
  }

  return check_zero;
}

int s21_checking_decimal_for_zero(s21_decimal *value) {
  // checking that the mantissa in the decimal is zero

  int check_zero = 1;

  for (int i = 0; i < 3; i++) {
    if (value->bits[i] != 0) {
      check_zero = 0;
    }
  }

  // removing the scale if the mantissa is zero
  if (check_zero == 1) {
    s21_zeroing_decimal(value);
  }

  return check_zero;
}

void s21_dividing_by_ten_big(s21_big_decimal *num) {
  // dividing a big decimal by ten

  uint64_t remainder = 0;

  for (int i = 6; i >= 0; i--) {
    uint64_t value = ((uint64_t)remainder << 32) | (uint32_t)num->bits[i];
    uint64_t div = value / 10;
    remainder = value % 10;
    num->bits[i] = (int32_t)div;
  }
}

void s21_extract_remainder(s21_big_decimal *value, int *scale,
                           s21_big_decimal *remainder,
                           s21_decimal *normalized_remainder) {
  INIT_TEN_BIG_DECIMAL(ten);
  s21_big_decimal temp_value = *value;
  int temp_scale = *scale;

  // saving the remainder
  while (temp_scale > 0) {
    temp_scale--;  // dropping the scale
    s21_dividing_by_ten_big(&temp_value);
  }

  // restoring the original size of the mantissa
  temp_scale = *scale;
  while (temp_scale > 0) {
    temp_scale--;
    s21_multiplication(temp_value, ten, &temp_value);
  }

  // get the remainder
  s21_subtraction(*value, temp_value, remainder);
  s21_normalizing_decimal(*remainder, *scale, normalized_remainder);

  // discarding the remainder
  while (*scale > 0) {
    (*scale)--;
    s21_dividing_by_ten_big(value);
  }
}

int s21_get_bit(int number_bit, s21_decimal decimal) {
  // get any bit in a decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // get the bit
  unsigned int res = decimal.bits[bit_group] & (1 << number_bit);
  res >>= number_bit;

  return res;
}

int s21_get_bit_big(int number_bit, s21_big_decimal decimal) {
  // get any bit in a big decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // get the bit
  unsigned int res = decimal.bits[bit_group] & (1 << number_bit);
  res >>= number_bit;

  return res;
}

int s21_get_scale(int number) {
  // get the scale

  int scale = (number >> 16) & 0xFF;  // getting only 8 bits
  return scale;
}

int s21_get_sign(int number) {
  // get the sign

  int sign = (number >> 31) & 1;  // &1 to avoid the negative
  return sign;
}

void s21_installation_same_scale(s21_big_decimal *value_1,
                                 s21_big_decimal *value_2, int *scale_first,
                                 int *scale_second) {
  // bringing two big decimals to the same scale

  if (*scale_first > *scale_second) {
    while (*scale_second < *scale_first) {
      INIT_TEN_BIG_DECIMAL(ten);
      s21_big_decimal temp_res = {0};

      // multiply value_2 by 10 using addition and bitwise shifts
      while (ten.bits[0] != 0) {
        if (s21_get_bit_big(0, ten) == 1) {
          s21_addition(*value_2, temp_res, &temp_res);
        }

        s21_shift_left(value_2);
        ten.bits[0] = ten.bits[0] >> 1;
      }

      *value_2 = temp_res;
      (*scale_second)++;
    }

    // recursively call the function
  } else if (*scale_first < *scale_second) {
    s21_installation_same_scale(value_2, value_1, scale_second, scale_first);
  }
}

void s21_normalizing_decimal(s21_big_decimal big_result, int scale_result,
                             s21_decimal *result) {
  // normalization of big decimal and setting the scale

  for (int i = 0; i < 3; i++) {
    result->bits[i] = big_result.bits[i];
  }
  s21_set_scale(result, scale_result);
}

void s21_set_bit_one_big(int number_bit, s21_big_decimal *decimal) {
  // set any bit to one in a big decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // set the bit
  decimal->bits[bit_group] = decimal->bits[bit_group] | (1 << number_bit);
}

void s21_set_bit_one(int number_bit, s21_decimal *decimal) {
  // set any bit to one in a decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // set the bit
  decimal->bits[bit_group] = decimal->bits[bit_group] | (1 << number_bit);
}

void s21_set_bit_zero(int number_bit, s21_decimal *decimal) {
  // set any bit to zero in a decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // set the bit
  decimal->bits[bit_group] = decimal->bits[bit_group] & ~(1 << number_bit);
}

void s21_set_bit_zero_big(int number_bit, s21_big_decimal *decimal) {
  // set any bit to zero in a big decimal

  // define the array element and the bit number
  int bit_group = number_bit / 32;
  number_bit %= 32;

  // set the bit
  decimal->bits[bit_group] = decimal->bits[bit_group] & ~(1 << number_bit);
}

void s21_set_scale(s21_decimal *decimal, int scale) {
  // setting the scale in decimal

  decimal->bits[3] |= scale << 16;
}

void s21_set_sign(s21_decimal *decimal, int sign) {
  // setting the sign in decimal

  decimal->bits[3] |= sign << 31;
}

void s21_shift_left(s21_big_decimal *decimal) {
  // bitwise shift to the left for a big decimal

  int carry = 0;
  int last_bit = 31;

  // shift each 32 bit block left by 1
  // moving the highest bit to the next block
  for (int i = 0; i < 7; i++) {
    int old_carry = s21_get_bit_big(last_bit, *decimal);
    decimal->bits[i] = (decimal->bits[i] << 1) | carry;
    carry = old_carry;
    last_bit += 32;
  }
}

void s21_transfer_to_big_decimal(s21_decimal normal, s21_big_decimal *big) {
  // conversion from a  decimal to a big decimal

  for (int i = 0; i < 3; i++) {
    big->bits[i] = normal.bits[i];
  }
}

void s21_zeroing_big_decimal(s21_big_decimal *value) {
  // zeroing all big decimal bits

  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0;
  }
}

void s21_zeroing_decimal(s21_decimal *value) {
  // zeroing all decimal bits

  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}