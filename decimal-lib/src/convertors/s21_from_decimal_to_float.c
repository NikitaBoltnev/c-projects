#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;

  if (dst == NULL) {
    result = 1;
  } else {
    int sign = src.bits[3] & 0x80000000;
    int scale = (src.bits[3] >> 16) & 0xFF;

    double result = 0.0;
    for (int i = 0; i < 96; i++) {
      if (s21_get_bit(i, src)) {
        result += pow(2.0, i);
      }
    }

    while (scale > 0) {
      unsigned rest = 0;
      s21_dividing_by_ten(&src, &rest);
      result /= 10.0;
      scale--;
    }

    if (sign) {
      result = -result;
    }
    *dst = (float)result;
  }

  return result;
}