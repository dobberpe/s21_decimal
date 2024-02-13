#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {}

int s21_round(s21_decimal value, s21_decimal *result) {}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int res = 0;
    s21_decimal ten = {0b1010, 0, 0, 0};
    s21_bits_4 sign_n_exp = {value.bits[3]};
    int e = sign_n_exp.bits[2];
    
    if (e) {
        s21_pow(ten, e, &ten); //при 1 в степени e 10 может переполниться ?
        res = s21_mul(value, ten, &value);
    }

    return res;
}

int s21_negate(s21_decimal value, s21_decimal *result) {}