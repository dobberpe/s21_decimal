#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    s21_bits_4 sign_and_exp;
    sign_and_exp.bits[0] = 0;
    sign_and_exp.bits[1] = 0;
    sign_and_exp.bits[2] = 0;
    sign_and_exp.bits[3] = (unsigned)(src < 0) << 7;
    dst->bits[3] = sign_and_exp.last_int;
    dst->bits[2] = 0;
    dst->bits[1] = 0;
    dst->bits[0] = (unsigned)abs(src);

    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int res = 0;
    f_bits f = {src};
    int e = (int)((unsigned)((f.bits << 1) >> 23)) - 127;
    if (e < -93) {
        res = 1;
        src = 0;
    }

    return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    s21_bits_4 last_int = {src.bits[3]};
    int e = last_int.bits[2];
    s21_decimal power_of_10 = s21_from_float_to_decimal(pow(10, e));
    s21_decimal integer;
    s21_mul(src, power_of_10, &integer);
    f_bits f = {*dst};
}