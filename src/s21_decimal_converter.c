#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int res = 0;
    if (!dst) res = 1;
    else {
        dst->bits[0] = (unsigned) abs(src);
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        if (src < 0) set_sign(dst, 1);
        set_exp(dst, 0);
    }

    return res;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int res = 0;
    f_bits f = {src};
    if (!dst) res = 1;
    else for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    
    if (isinf(src) || isnan(src) || fabsf(src) > 79228157791897854723898736640.0f || (src != 0.0 && fabsf(src) < 0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f)) {
        res = 1;
    } else if (!res && src) {
        char f_str[32];
        sprintf(f_str, "%.6e", fabsf(src));
        int exp = exp_from_str(f_str);
        if (exp < -22) {
            sprintf(f_str, "%.*e", exp + 28, fabsf(src));
            exp = exp_from_str(f_str);
        }
        
        int sign_digits = 7;
        int i = -1;
        while (f_str[++i]) {
            if (f_str[i] >= '0' && f_str[i] <= '9') {
                s21_decimal tmp = {{0x0, 0x0, 0x0, 0x0}};
                s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
                s21_pow(ten, --sign_digits, &ten);
                s21_from_int_to_decimal(f_str[i] - 48, &tmp);
                s21_mul(tmp, ten, &tmp);
                s21_add(*dst, tmp, dst);
            } else if (f_str[i] != '.') i = strlen(f_str) - 1;
        }

        exp -= 6;
        if (exp > 0) {
            s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
            s21_pow(ten, exp, &ten);
            s21_mul(*dst, ten, dst);
        } else if (exp < 0) {
            if (exp < -28) {
                set_exp(dst, 28);
                exp += 28;
            }
            s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
            s21_pow(ten, -exp, &ten);
            s21_div(*dst, ten, dst);
        }
    }

    if (f.bits & ((unsigned)1 << 31)) set_sign(dst, 1);

    return res;
}

int exp_from_str(char* f_str) {
    int exp = 0;

    int i = -1;
    while (f_str[++i] && !exp) if (f_str[i] == 'e') exp = strtol(f_str + i + 1, NULL, 10);

    return exp;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int res = 0;
    
    if (!dst || decimal_validation(&src)) res = 1;
    else {
        s21_decimal int_part;
        s21_decimal int_max = {{0x7fffffff, 0x0, 0x0, 0x0}};
        s21_decimal int_min = {{0x80000000, 0x0, 0x0, 0x80000000}};
        s21_truncate(src, &int_part);
        if (int_part.bits[1] || int_part.bits[2] || s21_is_greater(int_part, int_max) || s21_is_less(int_part, int_min)) {
            *dst = 0;
            res = 1;
        } else {
            *dst = int_part.bits[0];
            *dst *= get_sign(int_part) ? -1 : 1;
        }
    }

    return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int res = 0;
    if (!dst || decimal_validation(&src)) res = 1;
    else {
        char* d_str = dectostr(src);
        sscanf(d_str, "%f", dst);
        free (d_str);
    }

    return res;
}