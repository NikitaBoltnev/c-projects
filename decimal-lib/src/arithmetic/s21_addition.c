#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_zeroing_decimal(result);
  decimal_context ctx = {0};
  s21_init_decimal_context(&ctx, value_1, value_2);

  s21_transfer_to_big_decimal(value_1, &ctx.big_value_1);
  s21_transfer_to_big_decimal(value_2, &ctx.big_value_2);
  s21_installation_same_scale(&ctx.big_value_1, &ctx.big_value_2,
                              &ctx.scale_first, &ctx.scale_second);
  ctx.scale_result = ctx.scale_second;

  // sign comparison and arithmetic operation
  if (ctx.sign_first == ctx.sign_second) {  // both numbers have the same sign
    s21_addition(ctx.big_value_1, ctx.big_value_2, &ctx.big_result);
    ctx.sign_result = ctx.sign_first;  // sign equals either term's sign
  } else {  // if one number is positive and the other is negative
    if (s21_b_is_greater_or_equal(ctx.big_value_1, ctx.big_value_2)) {
      s21_subtraction(ctx.big_value_1, ctx.big_value_2, &ctx.big_result);
      ctx.sign_result = ctx.sign_first;
    } else {
      s21_subtraction(ctx.big_value_2, ctx.big_value_1, &ctx.big_result);
      ctx.sign_result = ctx.sign_second;
    }
  }

  // finalizes the result
  s21_finalize_result(&ctx, result);

  return ctx.flag;
}