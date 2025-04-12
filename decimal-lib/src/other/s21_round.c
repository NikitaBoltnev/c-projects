#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) return 1;

  s21_zeroing_decimal(result);

  int sign_result = s21_get_sign(value.bits[3]);
  if (sign_result) {
    s21_negate(value, &value);
  }

  INIT_FIVE_TENTHS_DECIMAL(five_tenths);
  INIT_ONE_BIG_DECIMAL(one);
  INIT_ZERO_BIG_DECIMAL(temp_value);
  INIT_ZERO_BIG_DECIMAL(remainder);
  s21_decimal normalized_remainder = {{0}};
  s21_transfer_to_big_decimal(value, &temp_value);
  int scale = s21_get_scale(value.bits[3]);

  // extract remainder and normalize it while reducing scale to zero
  s21_extract_remainder(&temp_value, &scale, &remainder, &normalized_remainder);

  // apply standard mathematical rounding
  if (s21_is_greater(normalized_remainder, five_tenths)) {
    s21_addition(temp_value, one, &temp_value);  // remainder > 0.5 - round up
  }
  // remainder == 0.5
  else if (s21_is_equal(normalized_remainder, five_tenths)) {
    s21_addition(temp_value, one, &temp_value);  //
  }

  s21_normalizing_decimal(temp_value, 0, result);
  s21_set_sign(result, sign_result);

  return 0;
}