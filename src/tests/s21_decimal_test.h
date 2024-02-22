#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"



Suite *s21_add_cases(void);
Suite *s21_sub_cases(void);
Suite *s21_mul_cases(void);
Suite *s21_div_cases(void);
Suite *s21_compare_cases(void);
Suite *s21_other_cases(void);
Suite *s21_dectostr_cases(void);
Suite *s21_converter_cases(void);

#endif