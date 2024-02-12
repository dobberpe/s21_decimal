#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    s21_bits_4 last_int = {dst->bits[3]};
    last_int.bits[2] = 0;
    last_int.bits[3] = (unsigned)(src < 0) << 7;
    dst->bits[0] = src;

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

int s21_from_decimal_to_float(s21_decimal src, float *dst) {}