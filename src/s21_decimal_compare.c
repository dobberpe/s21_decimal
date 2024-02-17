#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int result;
    if (sign_1 == sign_2) {
        s21_decimal res;
        s21_sub(value_1, value_2, &res);
        result = get_sign(res) && !zero_check(res);
    } else {
        result = sign_1 && !(zero_check(value_1) && zero_check(value_2));
    }
    return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int result;
    if (sign_1 == sign_2) {
        s21_decimal res;
        s21_sub(value_1, value_2, &res);
        result = get_sign(res) || zero_check(res);
    } else {
        result = sign_1 || (zero_check(value_1) && zero_check(value_2));
    }
    return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    return !s21_is_less_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return !s21_is_less(value_1, value_2);
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int result;
    if (sign_1 == sign_2) {
        s21_decimal res;
        s21_sub(value_1, value_2, &res);
        result = zero_check(res);
    } else {
        result = zero_check(value_1) && zero_check(value_2);
    }
    return result;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2){
    return !s21_is_equal(value_1, value_2);
}