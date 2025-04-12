#include "../s21_decimal.h"

int s21_b_is_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  // compares two big decimals
  // and returns 1 if the first decimal is larger

  int result = FALSE;

  for (int i = 223; i >= 0; i--) {
    int bit_1 = s21_get_bit_big(i, value_1);
    int bit_2 = s21_get_bit_big(i, value_2);

    if (bit_1 != bit_2) {
      result = bit_1 > bit_2;
      break;
    }
  }

  return result;
}

int s21_b_is_greater_or_equal(s21_big_decimal value_1,
                              s21_big_decimal value_2) {
  // If value_1 is greater than value_2 or they are equal, returns 1

  return s21_b_is_greater(value_1, value_2) || s21_b_is_equal(value_1, value_2);
}

int s21_b_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  // compares two big decimals
  // and returns 1 if the first decimal is larger
  int result = TRUE;
  for (int i = 0; i < 7; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      result = FALSE;
      break;
    }
  }

  return result;
}