#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) { // протестировано работает
    dst->bits[0] = (unsigned)abs(src);
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (src < 0) set_sign(dst, 1);
    set_exp(dst, 0);

    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {   // переводит, но пока без округления
    int res = 0;                                               // до 7 значащих
    f_bits f = {src};
    int e = ((f.bits << 1) >> 24) - 127;
    
    for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    
    if (f.bits && (e < -93 || e > 95)) {
        res = 1;
    } else if (f.bits) {
        if (e % 32 >= 23 && e % 32 <= 31) {
            unsigned int_bits = (f.bits << 9) >> 9;
            int_bits = (int_bits << (e % (32 * (e / 32) + 23))) | ((unsigned)1 << (e % 32));
            dst->bits[e / 32] = int_bits;
        } else if (e > 31) { // нужно проверить пограничные случаи
            unsigned int_bits = (f.bits << 9) >> 9;
            int_bits = (int_bits >> (24 - e % (e > 63 ? 63 : 31))) | ((unsigned)1 << (e % (e > 63 ? 63 : 31) - 1));
            dst->bits[e / 32] = int_bits;
            int_bits = f.bits << (9 + e % (e > 63 ? 63 : 31) - 1);
            dst->bits[e / 32 - 1] = int_bits;
        } else { // пока для экспоненты в пределах одного инта
            s21_decimal int_part = {0};
            s21_decimal frac_part = {0};
            s21_decimal two = {{2, 0, 0, 0}};
            s21_decimal tmp;
            if (e >= 0) {
                unsigned int_bits = (f.bits << 9) >> 9;
                int_bits = (int_bits >> 23 - e) | ((unsigned)1 << e);
                int_part.bits[0] = int_bits;
            } else {
                if (!(res = s21_pow(two, e, &tmp))) {
                    res = s21_add(frac_part, tmp, &frac_part);
                }
                --e;
            }

            unsigned mask = ((unsigned)1 << 22) >> (e > 0 ? e : 0);
            e = e >= 0 ? -1 : e;
            while (mask && e > -94 && !res) {
                if (mask & f.bits) {
                    if (!(res = s21_pow(two, e, &tmp))) { // декомпозировать вложенность!!!
                        res = s21_add(frac_part, tmp, &frac_part);
                    }
                }
                mask >>= 1;
                --e;
            }
            if (!res) {
                if (!(res = s21_add(int_part, frac_part, dst)) && f.full < 0) set_sign(dst, 1);
            }
        }
    }

    return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) { // нужен truncate
    int res = 0;
    s21_decimal int_part;
    s21_truncate(src, &int_part);
    if (int_part.bits[1] || int_part.bits[2]) {
        *dst = 0;
        res = 1;
    } else {
        *dst = int_part.bits[0];
        *dst *= get_sign(int_part) ? -1 : 1;
    }

    return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int res = 0;
    f_bits f;
    f.bits = 0;
    s21_decimal int_part;
    s21_decimal frac_part;
    s21_truncate(src, &int_part);
    s21_sub(src, int_part, &frac_part);

    s21_decimal zero = {0, 0, 0, 0};
    int pos = -1;
    if (s21_is_not_equal(int_part, zero)) {
        pos = 95 - mantiss_prev_nulls(int_part);
        set_bit(&int_part, pos, 0);
        f.bits = (pos + 127) << 23;
        f.bits |= get_sign(int_part) ? (1 << 31) : 0;
        if ((pos % 32 >= 23 && pos % 32 <= 31) || pos < 23) {
            f.bits |= pos < 23 ? int_part.bits[pos / 32] << (23 - pos) : int_part.bits[pos / 32] >> (pos - 23);
        } else {
            f.bits |= int_part.bits[pos / 32] << (23 - pos % 32);
            f.bits |= int_part.bits[pos / 32 - 1] >> (9 + pos % 32); // 32 - 23 + pos % 32
        }
    }
    if (pos < 23 && s21_is_not_equal(frac_part, zero)) {
        s21_decimal two = {2, 0, 0, 0};
        if (pos == -1) {
            pos = 24;
            bool sign_bits = false;
            while (pos) {
                s21_mul(frac_part, two, &frac_part);
                s21_truncate(frac_part, &int_part);
                s21_sub(frac_part, int_part, &frac_part);
                f.bits |= pos != 24 ? (frac_part.bits[0] << (pos - 1)) : 0;
                if ((sign_bits = frac_part.bits[0] ? true : sign_bits)) --pos;
            }
        } else {
            pos = 23 - pos;
            while (pos) {
                s21_mul(frac_part, two, &frac_part);
                s21_truncate(frac_part, &int_part);
                s21_sub(frac_part, int_part, &frac_part);
                f.bits |= frac_part.bits[0] /*<< pos*/;
                --pos;
            }
        }
    }
    return res;
}

// int main() {
//     f_bits f = {powf(2, 24) - 1};
//     s21_decimal d;
//     for (int i = -94; i < 97; ++i) {
//         printf("i: %d\n", i);
//         f.bits = f.bits & ~(0xff << 23);
//         f.bits |= (unsigned)(i + 127) << 23;
//         s21_from_float_to_decimal(f.full, &d);
//         printf("%s\n", dectostr(d));
//         printf("%.*f\n\n", i < 0 ? 28 : 23 - i > 0 ? 23 - i : 0, f.full);
//     }
//     // float x = 1e-23;
//     // s21_from_float_to_decimal(x, &d);
//     // printf("%s\n", dectostr(d));
//     // return 0;
// };
