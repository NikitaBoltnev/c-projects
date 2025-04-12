#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;
  if (!dst) flag = 1;
  s21_zeroing_decimal(dst);
  if (isinf(src) || isnan(src)) flag = 1;
  if (src < 0) {
    s21_set_sign(dst, 1);
  }

  float src_2_0 = fabs(src);
  if (src_2_0 < 1e-28 || src_2_0 > MAX_DECIMAL) {
    flag = 1;
  }

  int check_dot = 0, scale = 0, temp = 0, check = 0;
  int ch = 7;  // don't have a dot = 7
  int scale_check = 7;
  char number[50] = {0};
  snprintf(number, sizeof(number), "%f", src_2_0);

  // find a position of a dot and identify if it is int or float
  s21_dot_check(number, &ch, &temp, &scale_check);

  // Ensure the dot position is at index 6 or earlier so as not to have 1234567.
  for (int k = 0; k <= 6; k++) {
    if (number[k] == '.') {
      check = k;
    }
  }
  s21_delete_extra_zeroes(&ch, &check_dot, number);    // deleting extra 0
  s21_scale_check(&scale, &ch, &scale_check, &check);  // count scale
  s21_set_scale(dst, scale);

  int result = 0;  // counting mantissa
  for (int i = 0; i < ch; i++) {
    if (number[i] != '.') result = result * 10 + (number[i] - '0');
  }
  dst->bits[0] = (result);

  return flag;
}