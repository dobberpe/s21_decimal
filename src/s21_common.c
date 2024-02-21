#include "s21_decimal.h"



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

// Разность мантисс, мантисса value_1 >= value_2
void mantiss_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    clear_decimal(result);
    for (int i = 0; i < 96; i++) {
        int bit_1 = get_bit(value_1, i);
        int bit_2 = get_bit(value_2, i);
        set_bit(result, i, bit_1 ^ bit_2);
        if (bit_1 < bit_2) {
            int j = 1;
            while (!get_bit(value_1, i + j)) set_bit(&value_1, i + j++, 1);
            set_bit(&value_1, i + j, 0);
        }
    }
}

// Сравнение мантисс, возвращает: 1 - первая больше, 0 - равны, -1 - вторая больше
int mantiss_compare(s21_decimal value_1, s21_decimal value_2) {
    int result = 0, i = 96;
    while (!result && i--)
        result = get_bit(value_1, i) - get_bit(value_2, i);
    return result;
}

// Сдвиг мантиссы, пока что только влево
int mantiss_shift(s21_decimal dec, s21_decimal *result, int shift) {
    clear_decimal(result);
    int overflow = 0;
    for (int i = 95; i > 95 - shift; i--) {
        if (get_bit(dec, i)) overflow = 1;
    }
    if (!overflow) {
        for (int i = 95; i >= shift; i--)
            set_bit(result, i, get_bit(dec, i - shift));
    }
    return overflow;
}

s21_decimal mantiss_shift_right(s21_decimal dec, int shift) {
    for (int i = 0; i <= 95 - shift; i++) set_bit(&dec, i, get_bit(dec, i + shift));
    for (int i = 95 - shift + 1; i <= 95; i++) set_bit(&dec, i, 0);
    return dec;
}

// Умножение мантисс
int mantiss_multiply(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    clear_decimal(result);
    int overflow = 0;
    for (int i = 95; i >= 0 && !overflow; i--) {
        if (get_bit(value_1, i)) {
            s21_decimal tmp = {0};
            overflow = mantiss_shift(value_2, &tmp, i) || mantiss_sum(*result, tmp, result);
        }
    }
    return overflow;
}

// Деление мантисс остатком, мантисса value_2 != 0, возвращает остаток от деления
s21_decimal mantiss_division(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    clear_decimal(result);
    while (mantiss_compare(value_1, value_2) != -1) {
        int shift = 0;
        s21_decimal tmp = {0};
        int overflow = 0;
        while (mantiss_compare(value_1, tmp) != -1 && !overflow) {
                overflow = mantiss_shift(value_2, &tmp, shift++);
        }
        s21_decimal add = {0};
        add.bits[0] = 1;
        mantiss_shift(add, &add, (shift - 2));
        mantiss_sum(*result, add, result);
        mantiss_shift(value_2, &tmp, (shift - 2));
        mantiss_sub(value_1, tmp, &value_1);
    }
    return value_1;
}

s21_decimal mantiss_dev_by_10_with_round(s21_decimal dec) {
    // printf("be4 = %s\n", dectostr(dec));
    static bool round_factor = true, more_than_5 = false;
    s21_decimal ten = {0};
    ten.bits[0] = 10;
    s21_decimal rem = mantiss_division(dec, ten, &dec);
        // printf("rem = %s\n", dectostr(rem));
    if (((rem.bits[0] == 5 && get_bit(dec, 0)) && round_factor) || rem.bits[0] > 5 || (rem.bits[0] == 5 && more_than_5 && round_factor)) {
        ten.bits[0] = 1;
        mantiss_sum(dec, ten, &dec);
        
        s21_decimal tmp;
        ten.bits[0] = 10;
        rem = mantiss_division(dec, ten, &tmp);

        if (rem.bits[0] == 5 || !rem.bits[0]) round_factor = false;
    } else {
        if (rem.bits[0]) round_factor = true;
    }
    if (!more_than_5 && rem.bits[0]) more_than_5 = true;
    // printf("aft = %s\n\n", dectostr(dec));
    return dec;
}

int mantiss_mult_by_10(s21_decimal dec, s21_decimal *result) {
    s21_decimal ten = {0};
    ten.bits[0] = 10;
    int overflow = mantiss_multiply(dec, ten, result);
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

void decimal_switch(s21_decimal *value_1, s21_decimal *value_2) {
    s21_decimal switch_val = *value_1;
    *value_1 = *value_2;
    *value_2 = switch_val;
}

int zero_check(s21_decimal dec) {
    return !(dec.bits[0] + dec.bits[1] + dec.bits[2]);
}

int decimal_valid(s21_decimal *dec) {
    return (dec == NULL) || get_exp(*dec) > 28 || get_exp(*dec) < 0 || dec->bits[3] << 16;
}

int exponent_eval(s21_decimal *result, int new_exp) {
    int overflow = 0;
    s21_decimal tmp;
    while (new_exp < 0 && !overflow) {
      overflow = mantiss_mult_by_10(*result, result);
      new_exp++;
    }
    if (new_exp == 29) {
      if (!mantiss_mult_by_10(*result, &tmp))
        *result = mantiss_dev_by_10_with_round(*result);
      new_exp--;
    }
    set_exp(result, new_exp);
    return overflow;
}

int mantiss_round(s21_decimal *result, s21_decimal remainder, s21_decimal value_2) {
    s21_decimal tmp = {0};
    mantiss_mult_by_10(remainder, &remainder);
    mantiss_division(remainder, value_2, &tmp);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_decimal round = mantiss_division(tmp, ten, &tmp);
    if (round.bits[0] >= 5) {
        ten.bits[0] = 1;
        mantiss_sum(*result, ten, result);
    }
    return 0;
}

// int main() {
//     s21_decimal dec1 = {{0xfe6d9ab0, 0x11, 0x0, 0x80000000}};
//     s21_decimal dec2 = {{0xccfae07f, 0xf95b851a, 0x24681264, 0x80180000}};
//     s21_decimal dec_check = {{0xdd3539f4, 0xf1893fda, 0xdda0e74b, 0x160000}};

//     s21_decimal res = {0};
//     s21_decimal dec3 = {0};

//     // s21_decimal dec_1 = {0}, dec_2 = {0};
//     // dec_1.bits[0] = 10;
//     // dec_2.bits[0] = 3;
//     // set_exp(&dec_1, 0);
//     // set_exp(&dec_2, 0); 

//     // s21_decimal dec1 = {{1, 0, 0, 0}};
//     // printf("%d %d %d %d\n", dec1.bits[0], dec1.bits[1], dec1.bits[2], dec1.bits[3]);
//     // s21_decimal dec2 = {0};
//     // set_exp(&dec1, 0);
//     // set_exp(&dec2, 0);
//     // set_sign(&dec1, 0);
//     // set_sign(&dec2, 0);
//     // dec1.bits[0] = 2097152;
//     // dec2.bits[0] = 2048;
//     // s21_mul(dec1, dec2, &dec2);
//     // dec1.bits[0] = 78125;
//     // set_exp(&dec1, 7);
//     // dec1.bits[2] = 0b11111111111111111111111111111111;
//     // dec1.bits[1] = 0b11111111111111111111111111111111;
//     // dec1.bits[0] = 0b11111111111111111111111111111111;
//     // dec2.bits[2] = 0b01111111111111111111111111111111;
//     // dec2.bits[1] = 0b11111111111111111111111111111111;
//     // dec2.bits[0] = 0b11111111111111111111111111111110;
//     printf("%s\n", dectostr(dec1));
//     printf("%s\n", dectostr(dec2));
//     printf("err = %d\n", s21_div(dec1, dec2, &res));
//     printf("%s\n", dectostr(res));

//     printf("%s\n", dectostr(dec_check));
//     dec3.bits[0] = 0b11111111111111111111111111111111;
//     dec3.bits[1] = 0b11111111111111111111111111111111;
//     dec3.bits[2] = 0b11111111111111111111111111111111;
//     printf("%s\n", dectostr(dec3));
//     return 0;
// }