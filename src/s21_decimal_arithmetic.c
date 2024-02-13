#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (get_exp(value_1) > get_exp(value_2))
        decimal_switch(&value_1, &value_2);

    int exp_1 = get_exp(value_1);
    int exp_2 = get_exp(value_2);
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int overflow = 0;

    // нормализация
    while (!overflow && (exp_1 != exp_2) && (exp_1 < 29)) {
        s21_decimal tmp = {0};
        overflow = mantiss_mult_by_10(value_1, &tmp);
        if (!overflow) {
            exp_1++;
            value_1 = tmp;
        }
    }
    set_sign(&value_1, sign_1);
    while (exp_1 != exp_2) {
        value_2 = mantiss_dev_by_10_with_rownd(value_2);
        exp_2--;
    }
    set_sign(&value_2, sign_2);


    if (mantiss_compare(value_1, value_2) == -1 || (mantiss_compare(value_1, value_2) == 0 && sign_1))
        decimal_switch(&value_1, &value_2);

    
    if (get_sign(value_1) == get_sign(value_2)) {
        // сложение
        overflow = mantiss_sum(value_1, value_2, result);
        while (exp_1 && overflow) {
            value_1 = mantiss_dev_by_10_with_rownd(value_1);
            value_2 = mantiss_dev_by_10_with_rownd(value_2);
            overflow = mantiss_sum(value_1, value_2, result);
            exp_1--;
        }
    } else {
        // вычитание
        overflow = 0;
        mantiss_sub(value_1, value_2, result);
    }

    // экспонента
    set_exp(result, exp_1);
    // знак
    set_sign(result, get_sign(value_1));

    // DEBUG
    if (overflow) {
        clear_mantiss(result);
        printf("decimal overflow!\n");
    }
    return overflow;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    set_sign(&value_2, !get_sign(value_2));
    int overflow = s21_add(value_1, value_2, result);
    return overflow;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int is_zero = zero_check(value_1) || zero_check(value_2);
    int exp_1 = get_exp(value_1);
    int exp_2 = get_exp(value_2);
    int new_sign = get_sign(value_1) ^ get_sign(value_2);
    int new_exp = exp_1 + exp_2;
    int to_small = 0;
    while (new_exp > 28 && !is_zero && !to_small) {
        if (exp_1 > exp_2) {
            value_1 = mantiss_dev_by_10_with_rownd(value_1);
            exp_1--;
            
        } else {
            value_2 = mantiss_dev_by_10_with_rownd(value_2);
            exp_2--;
        }
        to_small = zero_check(value_1) || zero_check(value_2);
        new_exp--;
    }

    int overflow = mantiss_multiply(value_1, value_2, result);
    while (overflow && new_exp && !to_small) {
        if (mantiss_prev_nulls(value_2) > mantiss_prev_nulls(value_1)) {
            value_1 = mantiss_dev_by_10_with_rownd(value_1);
            exp_1--;
            
        } else {
            value_2 = mantiss_dev_by_10_with_rownd(value_2);
            exp_2--;
        }
        to_small = zero_check(value_1) || zero_check(value_2);
        new_exp--;
        overflow = mantiss_multiply(value_1, value_2, result);
    }
    
    if (!is_zero) set_exp(result, new_exp);
    set_sign(result, new_sign);

    if (overflow) {
        clear_mantiss(result);
        printf("decimal overflow!\n");
    } else if (to_small) {
        clear_mantiss(result);
        printf("decimal to small!\n");
    }

    return overflow ? overflow : to_small + to_small;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}