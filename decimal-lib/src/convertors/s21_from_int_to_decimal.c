#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (dst == NULL) {
    flag = 1;
  }
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }

  if (src < 0) {
    s21_set_sign(dst, 1);
    src *= (-1);
  }
  s21_set_scale(dst, 0);
  dst->bits[0] = src;

  return flag;
}
