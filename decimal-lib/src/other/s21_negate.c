#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;

  // set the sign
  if (s21_get_sign(value.bits[3])) {
    s21_set_bit_zero(127, result);
  } else {
    s21_set_sign(result, 1);
  }
  return 0;
}