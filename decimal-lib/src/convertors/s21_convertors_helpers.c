#include "../s21_decimal.h"

void s21_delete_extra_zeroes(int *ch, int *check_dot, char *number) {
  if (*ch == 8) {
    for (int i = *ch - 1; i >= 0; i--) {
      if (number[i] != '0' && *check_dot == 0) {
        *check_dot = 1;
      } else if (number[i] == '0' && *check_dot == 0) {
        while (number[i] == '0') {
          (*ch)--;
          i--;
        }
        *check_dot = 1;

        if (number[i] == '.') {
          (*ch)--;
        }
      }
    }
  }
}

void s21_dot_check(char *number, int *ch, int *temp, int *scale_check) {
  for (int i = 0; i < 8; i++) {
    if (number[i] ==
        '.') {  // find where the dot is, temp - exact index postion for dot
      *temp = i;
      if (i != 7) {  // if there is a dot we make ch = 8 cos we need an extra
        // char for a dot
        *ch = 8;
      }
    }
    if (*temp != 0) {  // if it is not an int , make it = 8 cos we need an extra
      // char for dot
      *scale_check = 8;
    }
  }
}

void s21_scale_check(int *scale, int *ch, int *scale_check, int *check) {
  if (*scale_check ==
      8) {  // we ensure that it has a dot so it is a float not an int
    for (int i = 0; i < *check; i++) {
      (*scale)++;  // in chech we already have a number without extra zeroes (a
                   // ready number) and we count all the symbols
    }
    *scale = *ch - *scale - 1;  // -1 so as not to include the dot
    if (*scale < 0) {
      *scale = 0;
    }
  }
}

void s21_dividing_by_ten(s21_decimal *value, unsigned *rest) {
  // dividing a decimal by ten

  uint64_t p_rest = 0;
  int div = 10;
  *rest = 0;
  for (int i = 2; i >= 0; i--) {
    p_rest = *rest * 4294967296 + value->bits[i];
    value->bits[i] = p_rest / div;
    *rest = p_rest - div * value->bits[i];
  }
}
