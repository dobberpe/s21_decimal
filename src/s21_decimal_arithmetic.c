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
        if (mantiss_prev_nulls(value_2) > mantiss_prev_nulls(value_1))
            value_1 = mantiss_dev_by_10_with_rownd(value_1);
        else
            value_2 = mantiss_dev_by_10_with_rownd(value_2);
        to_small = zero_check(value_1) || zero_check(value_2);
        new_exp--;
        overflow = mantiss_multiply(value_1, value_2, result);
    }

    if (!is_zero) set_exp(result, new_exp);
    set_sign(result, new_sign);

    // DEBUG
    if (overflow) {
        clear_mantiss(result);
        printf("decimal overflow!\n");
    } else if (to_small) {
        clear_mantiss(result);
        printf("decimal to small!\n");
    }

    return overflow ? overflow : to_small + to_small;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int dev_by_zero = zero_check(value_2);
    int is_zero = zero_check(value_1);
    int overflow = 0;
    int to_small = 0;
    int new_sign = get_sign(value_1) ^ get_sign(value_2);

    if (!dev_by_zero && !is_zero) {
        int exp_1 = get_exp(value_1);
        int exp_2 = get_exp(value_2);
        int new_exp = exp_1 - exp_2;

        s21_decimal remainder;
        remainder.bits[0] = 1;

        while (new_exp < 29 && !overflow && !zero_check(remainder) && !to_small) {
            s21_decimal tmp = {0};
            remainder = mantiss_devision(value_1, value_2, &tmp);

            if (zero_check(tmp)) {
                value_2 = mantiss_dev_by_10_with_rownd(value_2);
                if (zero_check(value_2)) to_small = 1;
            } else if (!zero_check(remainder)) {

            }
            overflow = mantiss_sum(*result, tmp, result);
            if (!zero_check(remainder) && !overflow) {
                overflow = mantiss_mult_by_10(*result, result);
                new_exp++;
                mantiss_mult_by_10(remainder, &remainder);
                value_1 = remainder;
            }
            printf("%s\n", dectostr(result));
        }
        while (new_exp < 0) {
            overflow = mantiss_mult_by_10(*result, result);
            new_exp++;
        }
        to_small = zero_check(*result) - is_zero;
        set_exp(result, new_exp);
    }

    int errno = dev_by_zero ? 3 : overflow ? overflow : to_small + to_small;
    set_sign(result, new_sign);
        // DEBUG
    if (overflow) {
        printf("decimal overflow!\n");
    } else if (to_small) {
        printf("decimal to small!\n");
    } else if (dev_by_zero) {
        printf("division by zero!\n");
    }
    return errno;
}

int s21_pow(s21_decimal value, int power, s21_decimal *result) {
    int res = 0;
    s21_decimal tmp = {1, 0, 0, 0};

    while (power) {
        if (power & 1) {
            res = s21_mul(*result, value, result);
            --power;
        } else {
            res = s21_mul(value, value, &value);
            power >>= 1;
        }
    }

    return res;
}