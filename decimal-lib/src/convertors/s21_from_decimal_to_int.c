#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  if (dst == NULL) {
    flag = 1;
  } else if (src.bits[1] == 0 && src.bits[2] == 0 && src.bits[0] >= 0) {
    *dst = src.bits[0];

    if (s21_get_sign(src.bits[3]) == 1) {
      *dst *= -1;
    }

    *dst /= pow(10, s21_get_scale(src.bits[3]));  // rounding from 13.45 to 13
  } else {
    flag = 1;
  }

  return flag;
}
