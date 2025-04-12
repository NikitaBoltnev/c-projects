#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_zeroing_decimal(result);
  decimal_context ctx = {0};
  s21_init_decimal_context(&ctx, value_1, value_2);

  s21_transfer_to_big_decimal(value_1, &ctx.big_value_1);
  s21_transfer_to_big_decimal(value_2, &ctx.big_value_2);
  s21_installation_same_scale(&ctx.big_value_1, &ctx.big_value_2,
                              &ctx.scale_first, &ctx.scale_second);

  // handle division and check for division by zero or perform division
  if (s21_checking_decimal_for_zero(&value_2)) {
    ctx.flag = 3;  // division by zero
  } else {
    s21_division(ctx.big_value_1, ctx.big_value_2, &ctx.big_result,
                 &ctx.scale_result);
    if (ctx.sign_first != ctx.sign_second) {
      ctx.sign_result = 1;  // result is negative for different signs
    }
  }

  // finalizes the result
  s21_finalize_result(&ctx, result);

  return ctx.flag;
}