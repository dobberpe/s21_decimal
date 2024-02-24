#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdio.h>  // <<<<<<<<<<<<<<<<<<<<<<<<<==========================<<<< УДАЛИТЬ ПЕРЕД СДАЧЕЙ

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct {
    unsigned bits[4];
} s21_decimal;

typedef union {
    unsigned last_int;
    char bits[4];
} s21_bits_4;

typedef union {
    float full;
    unsigned bits;
} f_bits;

// арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_pow(s21_decimal value, int power, s21_decimal *result);

// операторы сравнения
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// конверторы
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int exp_from_str(char* f_str);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// прочие функции
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// конвертер в строку
char* dectostr(const s21_decimal dec);
char *calculate_decimal(char *str, const unsigned *bits);
char *utoa(unsigned d);
int ulen(unsigned d);
char *raise_power_of_2(char *str, int n);
char *stradd(char *l_str, char *r_str);
char *add_width(char *str, int num, char value, bool right_alignment);

// общие функции
int get_bit(s21_decimal dec, int pos);
void set_bit(s21_decimal *dec, int pos, int bit);
int get_exp(s21_decimal dec);
void set_exp(s21_decimal *dec, int exp);
int get_sign(s21_decimal dec);
void set_sign(s21_decimal *dec, int sign);
int mantiss_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void mantiss_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int mantiss_multiply(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal mantiss_division(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int mantiss_shift(s21_decimal dec, s21_decimal *result, int shift);
int mantiss_compare(s21_decimal value_1, s21_decimal value_2);
int mantiss_prev_nulls(s21_decimal dec);
void clear_decimal(s21_decimal *dec);
s21_decimal mantiss_dev_by_10_with_round(s21_decimal dec);
int mantiss_mult_by_10(s21_decimal dec, s21_decimal *result);
void decimal_switch(s21_decimal *value_1, s21_decimal *value_2);
int zero_check(s21_decimal dec);
int decimal_validation(s21_decimal *dec);
int exponent_eval(s21_decimal *result, int new_exp);
int mantiss_round(s21_decimal *result, s21_decimal remainder, s21_decimal value_2);

#endif