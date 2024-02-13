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

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    s21_decimal integer;
    s21_decimal ten = {0b1010, 0, 0, 0};
    s21_decimal max_int = {0xffffffff, 0, 0, 0};
    s21_bits_4 last_int = {src.bits[3]};
    int e = last_int.bits[2];
    while (--e >= 0) {
        s21_mul(src, ten, &integer);
        for (int i = 0; i < 4; ++i) src.bits[i] = integer.bits[i];
    }
    while (src.bits[1]) {
        s21_sub(src, max_int, &integer);
        for (int i = 0; i < 4; ++i) src.bits[i] = integer.bits[i];
    }
    last_int.last_int = src.bits[3];
    *dst = (int)src.bits[0] * (last_int.bits[3] >> 7 ? -1 : 1);
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {}