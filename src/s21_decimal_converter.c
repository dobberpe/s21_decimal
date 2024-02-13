#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    dst->bits[0] = (unsigned)abs(src);
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (src < 0) set_sign(dst, 1);
    set_exp(dst, 0);

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
    int res = 0;
    s21_decimal ten = {0b1010, 0, 0, 0};
    s21_decimal max_int = {0xffffffff, 0, 0, 0};
    int e = get_exp(src);
    
    res = s21_truncate(src, &src);
    while (src.bits[1] || src.bits[2]) s21_sub(src, max_int, &src);

    *dst = (int)src.bits[0] * (get_sign(src) ? -1 : 1);

    return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    s21_decimal int_part;
    s21_decimal frac_part;
    s21_decimal ten = {0b1010, 0, 0, 0};
    int e = get_exp(src);
    int res = s21_truncate(src, &int_part);
    res = s21_pow(ten, e, &ten);
    res = s21_mul(src, ten, &src);
    res = s21_sub(src, int_part, &frac_part);
    unsigned j = 96;
    unsigned pos = 0;
    f_bits f = {0.0};
    for (int i = 2; i >= 0 && !pos; --i) {
        unsigned mask = 1 << 31;
        while (mask && !pos) {
            if (mask & int_part.bits[i]) pos = j;
            mask >>= 1;
            --j;
        }
    }
    set_bit(&int_part, pos - 1, 0);
    unsigned exp = pos - 1;
    f.bits |= exp << 23;
    int shift = 0;
    while (pos) {
        f.bits |= src.bits[(pos - 1) / 32] >> (9 + 32 * shift);
        pos -= 32;
        ++shift;
    }

    return res;
}