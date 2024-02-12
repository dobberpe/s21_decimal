#include "s21_decimal.h"

#include <stdio.h>

// Возвращет количество предстоящих нулей в мантиссе
int mantiss_prev_nulls(s21_decimal dec) {
    int i = 95;
    for (; i >= 0 && !get_bit(dec, i); i--);
    return 95 - i; 
}

// Установливает все биты decimal в 0
void clear_decimal(s21_decimal *dec) {
    for (int i = 0; i < 4; i++) dec->bits[i] = 0;
}

// Получить бит мантиссы, pos = 0-95
int get_bit(s21_decimal dec, int pos) {
    return (dec.bits[pos / 32] & (1 << (pos % 32))) ? 1 : 0;
}

// Установить бит мантиссы, pos = 0-95, bit = 0 | 1
void set_bit(s21_decimal *dec, int pos, int bit) {
    if (bit)
        dec->bits[pos / 32] |= (1 << (pos % 32));
    else
        dec->bits[pos / 32] &= ~(1 << (pos % 32));
}

// Сумма мантисс, при переполнении возвращает 1
int mantiss_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    clear_decimal(result);
    int overflow = 0;
    for (int i = 0; i < 96; i++) {
        int bit_1 = get_bit(value_1, i);
        int bit_2 = get_bit(value_2, i);
        set_bit(result, i, bit_1 ^ bit_2 ^ overflow);
        overflow = (bit_1 + bit_2 + overflow) > 1;
    }
    return overflow;
}

// Сдвиг мантиссы, пока что только влево
int mantiss_shift(s21_decimal dec, s21_decimal *result, int shift) {
    int overflow = 0;
    for (int i = 95; i > 95 - shift; i--) {
        if (get_bit(dec, i)) overflow = 1;
    }
    if (!overflow) {
        for (int i = 95; i >= shift; i--)
            set_bit(result, i, get_bit(dec, i - shift));
        for (int i = shift - 1; i >= 0; i--)
            set_bit(result, i, 0);
    }
    return overflow;
}

// Умножение мантисс
int mantiss_multiply(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    clear_decimal(result);
    int overflow = 0;
    for (int i = 95; i >= 0 && !overflow; i--) {
        if (get_bit(value_1, i)) {
            s21_decimal tmp = {0};
            overflow = mantiss_shift(value_2, &tmp, i);
            overflow = mantiss_sum(*result, tmp, result);
        }
    }
    return overflow;
}

// Установить экспоненту: exp = 0-28
void set_exp(s21_decimal *dec, int exp) {
    int sign = dec->bits[3] & (1 << 31);
    dec->bits[3] = (exp << 16);
    dec->bits[3] |= sign;
}

// Считать экспоненту
int get_exp(s21_decimal dec) {
    dec.bits[3] &= ~(1 << 31);
    return dec.bits[3] >> 16;
}

// Получить знак числа
int get_sign(s21_decimal dec) {
    return dec.bits[3] >> 31;
}

// Установить знак числа 0 - положительное, 1 - отрицательное
void set_sign(s21_decimal *dec, int sign) {
    if (sign)
        dec->bits[3] |= (1 << 31);
    else
        dec->bits[3] &= ~(1 << 31);
}


// Частично работающий сумматор. Без переполнения и отрицательных чисел.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (get_exp(value_1) > get_exp(value_2)) {
        s21_decimal switch_val = value_1;
        value_1 = value_2;
        value_2 = switch_val;
    }
    int exp_1 = get_exp(value_1);
    int exp_2 = get_exp(value_2);
    int diff = exp_2 - exp_1;
    if (diff) {
        s21_decimal tmp = {0}, ten = {0};
        tmp.bits[0] = 1;
        ten.bits[0] = 10;
        for (int i = 0; i < diff; i++) mantiss_multiply(tmp, ten, &tmp);
        mantiss_multiply(value_1, tmp, &value_1);
    }
    mantiss_sum(value_1, value_2, result);
    set_exp(result, exp_2);
    return 0;
}



int main() {
    s21_decimal dec1 = {0};
    s21_decimal dec2 = {0};
    s21_decimal res = {0};
    set_exp(&dec1, 0);
    set_exp(&dec2, 1);
    dec1.bits[2] = 0b11111111111111111111111111111111;
    dec1.bits[1] = 0b11111111111111111111111111111111;
    dec1.bits[0] = 0b11111111111111111111111111111111;
    dec2.bits[0] = 1222;
    // dec1.bits[1] = 1;
    // dec2.bits[1] = 1;
    // dec1.bits[2] = 1;
    // dec2.bits[2] = 1;
    printf("%d\n", mantiss_prev_nulls(dec1));
    printf("%s\n", dectostr(dec1));
    printf("%s\n", dectostr(dec2));
    // mantiss_sum(dec1, dec2, &res);
    // mantiss_multiply(res, dec2, &res);
    // s21_add(dec1, dec2, &res);
    // printf("%d\n", get_exp(res));

    // printf("%s\n", dectostr(res));

    // set_exp(&res, 10);
    // printf("%d\n", get_exp(res));
    return 0;
}