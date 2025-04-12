#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  s21_zeroing_decimal(result);

  int scale = s21_get_scale(value.bits[3]);
  INIT_ZERO_BIG_DECIMAL(temp);
  s21_transfer_to_big_decimal(value, &temp);

  // remove all decimal places
  while (scale > 0) {
    s21_dividing_by_ten_big(&temp);
    scale--;
  }
  s21_normalizing_decimal(temp, 0, result);
  s21_set_sign(result, s21_get_sign(value.bits[3]));

  return 0;
}