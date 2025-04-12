#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_zeroing_decimal(result);
  decimal_context ctx = {0};
  s21_init_decimal_context(&ctx, value_1, value_2);

  s21_transfer_to_big_decimal(value_1, &ctx.big_value_1);
  s21_transfer_to_big_decimal(value_2, &ctx.big_value_2);
  s21_installation_same_scale(&ctx.big_value_1, &ctx.big_value_2,
                              &ctx.scale_first, &ctx.scale_second);

  // arithmetic operation
  s21_multiplication(ctx.big_value_1, ctx.big_value_2, &ctx.big_result);
  ctx.scale_result = ctx.scale_first + ctx.scale_second;

  // processing if the scale > 28
  while (ctx.scale_result > 28) {
    s21_dividing_by_ten_big(&ctx.big_result);
    ctx.scale_result--;
  }

  // definition of the sign
  if (ctx.sign_first != ctx.sign_second) {
    ctx.sign_result = 1;  // result is negative for different signs
  }

  // finalizes the result
  s21_finalize_result(&ctx, result);

  return ctx.flag;
}