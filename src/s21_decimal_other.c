#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    int errno = 0;
    if (decimal_valid(&value) || result == NULL) {
        errno = 1;
    } else {
        int sign = get_sign(value);
        int exp = get_exp(value);
        if (sign) {
            s21_decimal one = {1, 0, 0, 0};
            while (exp--) mantiss_mult_by_10(one, &one);
            s21_decimal rem = mantiss_devision(value, one, &value);
            if (!zero_check(rem)) {
                s21_decimal one1 = {1, 0, 0, 0};
                mantiss_sum(value, one1, &value);
            }
            set_sign(&value, sign);
            set_exp(&value, 0);
        } else {
            s21_truncate(value, &value);
        }
        *result = value;
    }
    return errno;
}



int s21_round(s21_decimal value, s21_decimal *result) {
    int errno = 0;
    if (decimal_valid(&value) || result == NULL) {
        errno = 1;
    } else {
        int sign = get_sign(value);
        int exp = get_exp(value);
        int i = exp;
        s21_decimal one = {1, 0, 0, 0};
        while (i--) mantiss_mult_by_10(one, &one);
        s21_decimal rem = mantiss_devision(value, one, &value);
        if (!zero_check(rem)) {
            one = mantiss_dev_by_10_with_rownd(one);
            s21_decimal five = {5, 0, 0, 0};
            mantiss_multiply(one, five, &one);
            if (mantiss_compare(one, rem) != 1) {
                five.bits[0] = 1;
                mantiss_sum(value, five, &value);
            }
        }
        set_sign(&value, sign);
        set_exp(&value, 0);
        *result = value;
    }
    return errno;
}


int s21_truncate(s21_decimal value, s21_decimal *result) {
    int errno = 0;
    if (decimal_valid(&value) || result == NULL) {
        errno = 1;
    } else {
        int sign = get_sign(value);
        int exp = get_exp(value);
        s21_decimal ten = {0};
        ten.bits[0] = 10;
        while (exp--)
            mantiss_devision(value, ten, &value);
        set_exp(&value, 0);
        set_sign(&value, sign);
        *result = value;
    }
    return errno;
}


int s21_negate(s21_decimal value, s21_decimal *result) {
    int errno = 0;
    if (decimal_valid(&value) || result == NULL) {
        errno = 1;
    } else {
        set_sign(&value, get_sign(value) ? 0 : 1);
        *result = value;
    }
    return errno;
}