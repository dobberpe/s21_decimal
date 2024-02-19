#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (decimal_valid(&value_1) || decimal_valid(&value_2) || result == NULL)
    return 1;
  if (get_exp(value_1) > get_exp(value_2)) decimal_switch(&value_1, &value_2);
  int exp_1 = get_exp(value_1);
  int exp_2 = get_exp(value_2);
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  int overflow = 0;
  while (!overflow && (exp_1 != exp_2) && (exp_1 < 29)) {
    s21_decimal tmp = {0};
    overflow = mantiss_mult_by_10(value_1, &tmp);
    if (!overflow) {
      exp_1++;
      value_1 = tmp;
    }
  }
  set_sign(&value_1, sign_1);
  while (exp_1 != exp_2) {
    value_2 = mantiss_dev_by_10_with_rownd(value_2);
    exp_2--;
  }
  set_sign(&value_2, sign_2);
  if (mantiss_compare(value_1, value_2) == -1 ||
      (mantiss_compare(value_1, value_2) == 0 && sign_1))
    decimal_switch(&value_1, &value_2);
  if (get_sign(value_1) == get_sign(value_2)) {
    overflow = mantiss_sum(value_1, value_2, result);
    while (exp_1 && overflow) {
      value_1 = mantiss_dev_by_10_with_rownd(value_1);
      value_2 = mantiss_dev_by_10_with_rownd(value_2);
      overflow = mantiss_sum(value_1, value_2, result);
      exp_1--;
    }
  } else {
    overflow = 0;
    mantiss_sub(value_1, value_2, result);
  }
  set_exp(result, exp_1);
  set_sign(result, get_sign(value_1));
  if (overflow && get_sign(*result)) overflow++;
  return overflow;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (decimal_valid(&value_1) || decimal_valid(&value_2) || result == NULL)
    return 1;
  set_sign(&value_2, !get_sign(value_2));
  int overflow = s21_add(value_1, value_2, result);
  return overflow;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (decimal_valid(&value_1) || decimal_valid(&value_2) || result == NULL)
    return 1;
  clear_mantiss(result);
  int overflow = 0;
  int new_sign = get_sign(value_1) ^ get_sign(value_2);
  int new_exp = get_exp(value_1) + get_exp(value_2);
  s21_decimal ten = {0}, exp = {0};
  ten.bits[0] = 10;
  exp.bits[0] = 1;
  value_2.bits[3] = 0;
  while (!zero_check(value_2) && !overflow) {
    s21_decimal tmp = {0}, tmp2 = {0};
    s21_decimal rem = mantiss_devision(value_2, ten, &value_2);
    mantiss_multiply(rem, exp, &rem);
    overflow = mantiss_multiply(value_1, rem, &tmp);
    while (overflow && !zero_check(value_1) && new_exp > 0) {
      if (exp.bits[0] == 1) {
        value_1 = mantiss_dev_by_10_with_rownd(value_1);
      } else {
        rem = mantiss_dev_by_10_with_rownd(rem);
        exp = mantiss_dev_by_10_with_rownd(exp);
      }
      *result = mantiss_dev_by_10_with_rownd(*result);
      new_exp--;
      overflow = mantiss_multiply(value_1, rem, &tmp);
    }
    mantiss_mult_by_10(exp, &exp);
    if (!overflow) {
      overflow = mantiss_sum(*result, tmp, &tmp2);
      while (overflow && !zero_check(tmp) && !zero_check(*result) &&
             new_exp > 0) {
        tmp = mantiss_dev_by_10_with_rownd(tmp);
        *result = mantiss_dev_by_10_with_rownd(*result);
        exp = mantiss_dev_by_10_with_rownd(exp);
        overflow = mantiss_sum(*result, tmp, &tmp2);
        new_exp--;
      }
      *result = tmp2;
    }
  }
  set_sign(result, new_sign);
  set_exp(result, new_exp);
  if (new_sign && overflow) overflow++;
  return overflow;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (decimal_valid(&value_1) || decimal_valid(&value_2) || result == NULL)
    return 1;
  if (zero_check(value_2)) return 3;
  clear_mantiss(result);
  int overflow = 0, cont = 1;
  int new_sign = get_sign(value_1) ^ get_sign(value_2);
  if (!zero_check(value_1)) {
    int new_exp = get_exp(value_1) - get_exp(value_2);
    s21_decimal remainder = {1, 0, 0, 0};
    while (new_exp <= 28 && !overflow && !zero_check(remainder) && cont) {
      s21_decimal tmp = {0};
      remainder = mantiss_devision(value_1, value_2, &tmp);
      while (zero_check(tmp) && new_exp <= 28 && !overflow) {
        if (!mantiss_mult_by_10(value_1, &tmp)) {
          value_1 = tmp;
          if (!mantiss_mult_by_10(*result, &tmp))
            *result = tmp;
          else
            break;
        } else {
          value_2 = mantiss_dev_by_10_with_rownd(value_2);
        }
        new_exp++;
        if (zero_check(value_2)) overflow = 1;
        remainder = mantiss_devision(value_1, value_2, &tmp);
      }
      if (zero_check(tmp) && zero_check(*result) && new_exp >= 28) overflow = 1;
      if (!mantiss_sum(*result, tmp, &tmp)) *result = tmp;
      if (mantiss_mult_by_10(*result, &tmp)) {
        mantiss_mult_by_10(remainder, &remainder);
        mantiss_devision(remainder, value_2, &tmp);
        s21_decimal ten = {10, 0, 0, 0};
        s21_decimal round = mantiss_devision(tmp, ten, &tmp);
        if (round.bits[0] >= 5) {
          ten.bits[0] = 1;
          mantiss_sum(*result, ten, result);
        }
        cont = 0;
      }
      if (!zero_check(remainder) && !mantiss_mult_by_10(*result, &tmp) &&
          !overflow && new_exp <= 28 && cont) {
        *result = tmp;
        new_exp++;
        if (mantiss_mult_by_10(remainder, &tmp))
          new_exp--;
        else
          remainder = tmp;
        value_1 = remainder;
      }  
    }
    overflow = overflow ? overflow : exponent_eval(result, new_exp);
  }
  set_sign(result, new_sign);
  if (overflow) clear_mantiss(result);
  return overflow ? overflow + new_sign : 0;
}

int s21_pow(s21_decimal value, int power, s21_decimal *result) {
    int res = 0;
    result->bits[0] = 1;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;

    while (power) {
        if (power & 1) {
            res = power > 0 ? s21_mul(*result, value, result) : s21_div(*result, value, result);
            power += power > 0 ? -1 : 1;
        } else {
            res = s21_mul(value, value, &value);
            power >>= 1;
        }
    }

    return res;
}