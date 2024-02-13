#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    s21_bits_4 sign_n_exp;
    sign_n_exp.bits[0] = 0;
    sign_n_exp.bits[1] = 0;
    sign_n_exp.bits[2] = 0;
    sign_n_exp.bits[3] = (unsigned)(src < 0) << 7;
    dst->bits[3] = sign_n_exp.last_int;
    dst->bits[2] = 0;
    dst->bits[1] = 0;
    dst->bits[0] = (unsigned)abs(src);

    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int res = 0;
    f_bits f = {src};
    int e = ((f.bits << 1) >> 24) - 127;
    if (e < -93) {
        res = 1;
        src = 0;
    } else {
        s21_decimal int_part = {0, 0, 0, 0};
        if (e > 0) { // пока для экспоненты в пределах одного инта
            unsigned int_bits = ((f.bits << 9) >> (10 + (22 - e))) | ((unsigned)1 << e);
            int_part.bits[0] = int_bits;
        }

        s21_decimal frac_part = {0, 0, 0, 0};
        e = 1;
        unsigned mask = ((unsigned)1 << 22) >> e;
        s21_decimal five = {0b101, 0, 0, 0};
        s21_decimal tmp;
        s21_bits_4 sign_n_exp = {0, 0, 0, 0};
        while (mask && !res) {
            if (mask & f.bits) {
                sign_n_exp.bits[2] = (unsigned)e;
                if (res = s21_pow(five, e, &tmp)) res = s21_add(frac_part, tmp, &frac_part);
            }
            mask >>= 1;
            ++e;
        }
        if (!res) {
            if ((res = s21_add(int_part, frac_part, dst)) && f.full < 0) set_bit(dst, 127, 1);
        }
    }

    return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    s21_decimal ten = {0b1010, 0, 0, 0};
    s21_decimal max_int = {0xffffffff, 0, 0, 0};
    s21_bits_4 sign_n_exp = {src.bits[3]};
    int e = sign_n_exp.bits[2];
    
    if (e) s21_pow(ten, e, &ten);
    while (src.bits[1] || src.bits[2]) s21_sub(src, max_int, &src);

    sign_n_exp.last_int = src.bits[3];
    *dst = (int)src.bits[0] * (sign_n_exp.bits[3] >> 7 ? -1 : 1);
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    
}