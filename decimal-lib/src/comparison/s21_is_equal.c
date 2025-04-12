#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  // compares two decimals and returns 1 if they are equal
  // and 0 otherwise

  int sign_1 = s21_get_sign(value_1.bits[3]),
      sign_2 = s21_get_sign(value_2.bits[3]);
  int result = TRUE;
  int scale_1 = s21_get_scale(value_1.bits[3]),
      scale_2 = s21_get_scale(value_2.bits[3]);
  INIT_ZERO_BIG_DECIMAL(b_value_1);
  INIT_ZERO_BIG_DECIMAL(b_value_2);

  s21_transfer_to_big_decimal(value_1, &b_value_1);
  s21_transfer_to_big_decimal(value_2, &b_value_2);

  // check if both decimals are zero, have the same sign
  // and compare their scaled values
  if (s21_checking_decimal_for_zero(&value_1) &&
      s21_checking_decimal_for_zero(&value_2)) {
    result = TRUE;
  } else if (sign_1 != sign_2) {
    result = FALSE;
  } else {
    s21_installation_same_scale(&b_value_1, &b_value_2, &scale_1, &scale_2);
    result = s21_b_is_equal(b_value_1, b_value_2);
  }

  return result;
}