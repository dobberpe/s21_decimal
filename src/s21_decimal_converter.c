#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) { // протестировано работает
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

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {   // переводит, но пока без округления
//     int res = 0;                                               // до 7 значащих
//     f_bits f = {src};
//     int e = ((f.bits << 1) >> 24) - 127;
//     if (!dst) res = 1;
//     else for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    
//     if (!res && src && f.bits && (e < -93 || e > 95)) {
//         res = 1;
//     } else if (!res && src && f.bits) {
//         if (e % 32 >= 23 && e % 32 <= 31) {
//             unsigned int_bits = (f.bits << 9) >> 9;
//             int_bits = (int_bits << (e % (32 * (e / 32) + 23))) | ((unsigned)1 << (e % 32));
//             dst->bits[e / 32] = int_bits;
//         } else if (e > 31) {                                    // нужно проверить пограничные случаи
//             unsigned int_bits = (f.bits << 9) >> 9;
//             int_bits = (int_bits >> (24 - e % (e > 63 ? 63 : 31))) | ((unsigned)1 << (e % (e > 63 ? 63 : 31) - 1));
//             dst->bits[e / 32] = int_bits;
//             int_bits = f.bits << (9 + e % (e > 63 ? 63 : 31) - 1);
//             dst->bits[e / 32 - 1] = int_bits;
//         } else {
//             s21_decimal int_part = {0};
//             s21_decimal frac_part = {0};
//             s21_decimal two = {{2, 0, 0, 0}};
//             s21_decimal tmp;
//             if (e >= 0) {
//                 unsigned int_bits = (f.bits << 9) >> 9;
//                 int_bits = (int_bits >> 23 - e) | ((unsigned)1 << e);
//                 int_part.bits[0] = int_bits;
//             } else {
//                 if (!(res = s21_pow(two, e, &tmp))) {
//                     res = s21_add(frac_part, tmp, &frac_part);
//                 }
//                 --e;
//             }

//             unsigned mask = ((unsigned)1 << 22) >> (e > 0 ? e : 0);
//             e = e >= 0 ? -1 : e;
//             while (mask && e > -94 && !res) {
//                 if (mask & f.bits) {
//                     if (!(res = s21_pow(two, e, &tmp))) {       // декомпозировать вложенность!!!
//                         res = s21_add(frac_part, tmp, &frac_part);
//                     }
//                 }
//                 mask >>= 1;
//                 --e;
//             }
//             if (!res) {
//                 // printf("\nexp: %d\n", e);
//                 // printf("\nmask:\n");
//                 // unsigned m = (unsigned)1 << 31;
//                 // while (m) {
//                 //     printf(m & mask ? "1" : "0");
//                 //     m >>= 1;
//                 // }
//                 // printf("\n");
//                 // printf("\nf.bits:\n");
//                 // m = (unsigned)1 << 31;
//                 // while (m) {
//                 //     printf(m & f.bits ? "1" : "0");
//                 //     m >>= 1;
//                 // }
//                 // printf("\n");
//                 // if (e == -94) {
//                 //     s21_decimal round_up = {{0x1, 0x0, 0x0, 0x0}};
//                 //     set_exp(&round_up, get_exp(frac_part));
//                 //     f_bits dub = {f.full};
//                 //     unsigned m = (unsigned)1 << 22;
//                 //     while (m > mask) {
//                 //         dub.bits &= ~m;
//                 //         m >>= 1;
//                 //     }
//                 //     printf("\ndub:\n");
//                 //     m = (unsigned)1 << 31;
//                 //     while (m) {
//                 //         printf(m & dub.bits ? "1" : "0");
//                 //         m >>= 1;
//                 //     }
//                 //     dub.full -= powf(2, (int)(((f.bits << 1) >> 24) - 127));
//                 //     char str_f[32] = {0};
//                 //     sprintf(str_f, "%.28f", dub.full);
//                 //     printf("\n%s\n\n", str_f);
//                 //     if (str_f[strlen(str_f) - 1] > '5') s21_add(frac_part, round_up, &frac_part);
//                 // }
//                 if (e == -94) {
//                     char str_f[32] = {0};
//                     sprintf(str_f, "%.28f", src);
//                     char* remainder = dectostr(frac_part);
//                     // printf("\nf:\n%s\nd:\n%s\n\n", str_f, remainder);   // FREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//                     if (str_f[strlen(str_f) - 1] != remainder[strlen(remainder) - 1]) {
//                         s21_decimal round_up = {{abs((str_f[strlen(str_f) - 2] > '0' ? ('9' + 1) : str_f[strlen(str_f) - 1]) - remainder[strlen(remainder) - 1]), 0x0, 0x0, 0x0}};
//                         set_exp(&round_up, get_exp(frac_part));
//                         // printf("add\n");
//                         if (str_f[strlen(str_f) - 1] > remainder[strlen(remainder) - 1] || str_f[strlen(str_f) - 2] > '0') s21_add(frac_part, round_up, &frac_part);
//                         else s21_sub(frac_part, round_up, &frac_part);
//                     }
//                 }
//                 res = s21_add(int_part, frac_part, dst);
//             }
//         }
//     }

//     if (!res) {
//         if (f.bits & ((unsigned)1 << 31)) set_sign(dst, 1);
//         // printf("\n%s\n\n", dectostr(*dst));
//         round_to_7_significant(dst);
//     } else if (dst) for (int i = 0; i < 4; ++i) dst->bits[i] = 0;

//     return res;
// }

int exp_from_str(char* f_str) {
    int exp = 0;

    int i = -1;
    while (f_str[++i] && !exp) if (f_str[i] == 'e') exp = strtol(f_str + i + 1, NULL, 10);

    return exp;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int res = 0;
    f_bits f = {src};
    // int e = ((f.bits << 1) >> 24) - 127;
    if (!dst) res = 1;
    else for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    
    if (isinf(src) || isnan(src) || fabsf(src) > 79228157791897854723898736640.0f || fabsf(src) < 0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f) {
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
        // printf("\nf_str:\n%s\n", f_str);
        while (f_str[++i]) {
            if (f_str[i] >= '0' && f_str[i] <= '9') {
                // printf("char: %c\npow: %d\n\n", f_str[i], sign_digits - 1);
                s21_decimal tmp = {{0x0, 0x0, 0x0, 0x0}};
                s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
                s21_pow(ten, --sign_digits, &ten);
                s21_from_int_to_decimal(f_str[i] - 48, &tmp);
                s21_mul(tmp, ten, &tmp);
                // printf("%s + %s\n\n", dectostr(*dst), dectostr(tmp));
                s21_add(*dst, tmp, dst);
            } else if (f_str[i] != '.') i = strlen(f_str) - 1;
        }
        // printf("res: %s\n\n", dectostr(*dst));

        exp -= 6;
        if (exp > 0) {
            s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
            s21_pow(ten, exp, &ten);
            s21_mul(*dst, ten, dst);
        } else if (exp < 0) {
            // if (exp < -28) {
            //     set_exp(dst, 28);
            //     exp += 28;
            // }
            // s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
            // s21_pow(ten, -exp, &ten);
            // s21_div(*dst, ten, dst);
            set_exp(dst, -exp);
        }
    }

    if (f.bits & ((unsigned)1 << 31)) set_sign(dst, 1);

    return res;
}

// void round_to_7_significant(s21_decimal *dst) {
//     int exp = get_exp(*dst);
//     int sign = get_sign(*dst);
//     set_sign(dst, 0);
//     set_exp(dst, 0);
//     s21_decimal max = {{10000000, 0, 0, 0}};
//     while (s21_is_greater_or_equal(*dst, max)) {
//         *dst = mantiss_dev_by_10_with_round(*dst);
//         --exp;
//     }
//     while (exp < 0) {
//         mantiss_mult_by_10(*dst, dst);
//         ++exp;
//     }
//     set_exp(dst, exp);
//     set_sign(dst, sign);
// }

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
    f_bits f;
    f.bits = 0;
    s21_decimal int_part;
    s21_decimal frac_part;
    s21_truncate(src, &int_part);
    s21_sub(src, int_part, &frac_part);

    s21_decimal zero = {0, 0, 0, 0};
    s21_decimal two = {2, 0, 0, 0};
    int pos = -1;
    if (s21_is_not_equal(int_part, zero)) {
        pos = 95 - mantiss_prev_nulls(int_part);
        set_bit(&int_part, pos, 0);
        f.bits = (pos + 127) << 23;                             // выставляю экспоненту
        if ((pos % 32 >= 23 && pos % 32 <= 31) || pos < 23) {
            f.bits |= pos < 23 ? int_part.bits[pos / 32] << (23 - pos) : int_part.bits[pos / 32] >> (pos - 23);
        } else {
            f.bits |= int_part.bits[pos / 32] << (23 - pos % 32);
            f.bits |= int_part.bits[pos / 32 - 1] >> (9 + pos % 32); // 32 - 23 + pos % 32
        }
        if (pos > 24 && get_bit(int_part, pos - 24)) {                                         // округление
            for (int i = 1; i < 25; ++i) set_bit(&int_part, pos - i, 0);
            f.bits |= s21_is_not_equal(int_part, zero) || s21_is_not_equal(frac_part, zero) ? 1 : 0;
        } else if (pos > 22 && s21_is_not_equal(frac_part, zero)) {
            s21_decimal half = {5, 0, 0, 0x10000};
            set_sign(&frac_part, 0);
            f.bits |= (pos == 24 && get_bit(int_part, pos - 24)) || (pos == 23 && s21_is_greater(frac_part, half)) ? 1 : 0;
        }
    }
    if (pos < 23 && s21_is_not_equal(frac_part, zero)) {        // если pos < 23 => дробная часть может влезть, если она существует
        s21_decimal eights_of_two = {256, 0, 0, 0};
        unsigned octuplets = 0;
        if (pos == -1) {                                        // pos = -1 когда целая 0 => мнимый бит дробный
            pos = 4;                                            // мы можем получить 23 бита двоичного представления +1 на префиксный декримент
            bool sign_bits = false;
            int e = -1;
            while (pos) {
                s21_mul(frac_part, eights_of_two, &frac_part);  // умножаем дробь на 16 пока не получим первый значащий квартоль
                s21_truncate(frac_part, &int_part);             // записываем целую часть после умножения
                s21_sub(frac_part, int_part, &frac_part);       // записываем хвост после умножения
                if (!sign_bits && int_part.bits[0]) sign_bits = true;
                if (sign_bits) octuplets |= int_part.bits[0] << (--pos * 8);
                else e -= 8;
            }
            unsigned mask = (unsigned)1 << 31;
            pos = 31;
            while (!(mask & octuplets)) {
                --pos;
                mask >>= 1;
            }                                                   // первый значащий на позиции 24-31
            f.bits |= (unsigned)(e + pos + 96) << 23;
            octuplets &= ~((unsigned)1 << pos);                 // зануляем мнимый бит
            f.bits |= octuplets >> (pos - 23);
            mask = (unsigned)1 << (pos - 24);                   // округление
            if (pos == 24) f.bits |= (mask & octuplets) && s21_is_not_equal(frac_part, zero) ? 1 : 0;
            else {
                bool first_extra_bit = mask & octuplets;
                octuplets <<= (55 - pos); // 24 -> 31   25 -> 30   31 -> 24
                f.bits |= first_extra_bit && (octuplets || s21_is_not_equal(frac_part, zero)) ? 1 : 0;
            }
        } else {                                                // добиваю дробные биты при наличии целых
            int block = 4;
            while (block) {
                s21_mul(frac_part, eights_of_two, &frac_part);
                s21_truncate(frac_part, &int_part);
                s21_sub(frac_part, int_part, &frac_part);
                octuplets |= int_part.bits[0] << (--block * 8);
            }
            f.bits |= octuplets >> (9 + pos);
            unsigned mask = (unsigned)1 << (8 + pos);           // округление
            bool first_extra_bit = mask & octuplets;
            octuplets <<= (24 - pos);
            f.bits |= first_extra_bit && (octuplets || s21_is_not_equal(frac_part, zero)) ? 1 : 0;
        }
    }

    f.bits |= get_sign(src) ? (1 << 31) : 0;                    // выставляю знак
    *dst = f.full;
    
    return res;
}

// int main() {
//     // -3.862393
//     s21_decimal dec_check = {{0x3aef79, 0x0, 0x0, 0x80060000}}, result;
//     float src = -3.862393;
//     int return_value = s21_from_float_to_decimal(src, &result);
//     printf("%s\n", dectostr(result));
//     printf("%s\n", dectostr(dec_check));
//     // f_bits f = {powf(2, 24) - 1};
//     // s21_decimal d;
//     // for (int i = -94; i < 97; ++i) {
//     //     printf("i: %d\n", i);
//     //     f.bits = f.bits & ~(0xff << 23);
//     //     f.bits |= (unsigned)(i + 127) << 23;
//     //     s21_from_float_to_decimal(f.full, &d);
//     //     printf("%s\n", dectostr(d));
//     //     printf("%.*f\n\n", i < 0 ? 28 : 23 - i > 0 ? 23 - i : 0, f.full);
//     // }
// //    float f = powf(2, -93);
// //    s21_decimal d;
// //    s21_decimal ten = {{10, 0, 0, 0}};
// //    s21_from_float_to_decimal(f, &d);
// //    printf("%s\n", dectostr(d));
//     // for (int i = 0; i < 28; ++i) {
//     //     s21_decimal tmp;
//     //     s21_pow(ten, i, &tmp);
//     //     s21_mul(d, tmp, &tmp);
//     //     s21_from_decimal_to_float(tmp, &f);
//     //     printf("%s\n%.28f\n\n", dectostr(tmp), f);
//     // }
// //    f = -3.14;
// //    s21_from_float_to_decimal(f, &d);
// //    for (int i = 1; i < 10; ++i) {
// //        s21_decimal tmp;
// //        s21_from_int_to_decimal(i, &tmp);
// //        s21_mul(d, tmp, &tmp);
// //        s21_from_decimal_to_float(tmp, &f);
// //        printf("%s\n%.28f\n\n", dectostr(tmp), f);
// //    }
//     return 0;
// }
