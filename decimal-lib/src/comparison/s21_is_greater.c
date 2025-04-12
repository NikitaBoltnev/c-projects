#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int sign_1 = s21_get_sign(value_1.bits[3]),
      sign_2 = s21_get_sign(value_2.bits[3]);
  int result = FALSE;
  int scale_1 = s21_get_scale(value_1.bits[3]),
      scale_2 = s21_get_scale(value_2.bits[3]);
  INIT_ZERO_BIG_DECIMAL(b_value_1);
  INIT_ZERO_BIG_DECIMAL(b_value_2);

  // zero is less than positive but greater than negative
  if (s21_checking_decimal_for_zero(&value_1) &&
      s21_checking_decimal_for_zero(&value_2)) {
    result = FALSE;
  } else if (s21_checking_decimal_for_zero(&value_1)) {
    result = (sign_2 == 1) ? TRUE : FALSE;
  } else if (s21_checking_decimal_for_zero(&value_2)) {
    result = (sign_1 == 1) ? FALSE : TRUE;
  } else {
    s21_transfer_to_big_decimal(value_1, &b_value_1);
    s21_transfer_to_big_decimal(value_2, &b_value_2);

    // positives always > negatives, same signs need magnitude check
    if (sign_1 != sign_2) {
      if (sign_1 == 0 && sign_2 == 1) {
        result = TRUE;
      } else {
        result = FALSE;
      }
    } else {
      // for same-sign numbers
      s21_installation_same_scale(&b_value_1, &b_value_2, &scale_1, &scale_2);
      if (sign_1 == 0) {
        result = s21_b_is_greater(b_value_1, b_value_2);
      } else {
        result = s21_b_is_greater(b_value_2, b_value_1);
      }
    }
  }
  return result;
}