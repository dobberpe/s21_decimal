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
        f.bits = (pos + 127) << 23;                             // выставляю экспоненту
        if ((pos % 32 >= 23 && pos % 32 <= 31) || pos < 23) {
            f.bits |= pos < 23 ? int_part.bits[pos / 32] << (23 - pos) : int_part.bits[pos / 32] >> (pos - 23);
        } else {
            f.bits |= int_part.bits[pos / 32] << (23 - pos % 32);
            f.bits |= int_part.bits[pos / 32 - 1] >> (9 + pos % 32); // 32 - 23 + pos % 32
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
            octuplets &= ~((unsigned)1 << pos);
            f.bits |= octuplets >> (pos - 23);
        } else {                                                // добиваю дробные биты при наличии целых
            int block = 4;
            while (block) {
                s21_mul(frac_part, eights_of_two, &frac_part);
                s21_truncate(frac_part, &int_part);
                s21_sub(frac_part, int_part, &frac_part);
                octuplets |= int_part.bits[0] << (--block * 8);
            }
            f.bits |= octuplets >> (9 + pos);
        }
    }

    f.bits |= get_sign(src) ? (1 << 31) : 0;                    // выставляю знак
    *dst = f.full;
    
    return res;
}

int main() {
//    f_bits f = {powf(2, 24) - 1};
//    s21_decimal d;
//    for (int i = -94; i < 97; ++i) {
//        printf("i: %d\n", i);
//        f.bits = f.bits & ~(0xff << 23);
//        f.bits |= (unsigned)(i + 127) << 23;
//        s21_from_float_to_decimal(f.full, &d);
//        printf("%s\n", dectostr(d));
//        printf("%.*f\n\n", i < 0 ? 28 : 23 - i > 0 ? 23 - i : 0, f.full);
//    }
    float f = powf(2, -93);
    s21_decimal d;
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_from_float_to_decimal(f, &d);
//    printf("%s\n", dectostr(d));
    // for (int i = 0; i < 28; ++i) {
    //     s21_decimal tmp;
    //     s21_pow(ten, i, &tmp);
    //     s21_mul(d, tmp, &tmp);
    //     s21_from_decimal_to_float(tmp, &f);
    //     printf("%s\n%.28f\n\n", dectostr(tmp), f);
    // }
    f = -3.14;
    s21_from_float_to_decimal(f, &d);
    for (int i = 1; i < 10; ++i) {
        s21_decimal tmp;
        s21_from_int_to_decimal(i, &tmp);
        s21_mul(d, tmp, &tmp);
        s21_from_decimal_to_float(tmp, &f);
        printf("%s\n%.28f\n\n", dectostr(tmp), f);
    }
    return 0;
}