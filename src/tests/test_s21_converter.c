#include "s21_decimal_test.h"

START_TEST(s21_to_int_pos) {
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(res, 300);
    ck_assert_int_eq(errno, 0);
}
END_TEST


START_TEST(s21_to_int_neg) {
    // -62608.5874666619884066
    s21_decimal dec_1 = {{0x399d5222, 0xf0afd9dd, 0x21, 0x80100000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(res, -62608);
    ck_assert_int_eq(errno, 0);

}
END_TEST

START_TEST(s21_to_int_zero) {
    //     0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(errno, 0);

}
END_TEST

START_TEST(s21_to_int_failure) {
    // 2101970847525601134.671422
    s21_decimal dec_1 = {{0x91b6763e, 0x116671af, 0x1bd1c, 0x60000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_null_pointer) {
    // 792281625.14264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x140000}};
    int errno = s21_from_decimal_to_int(dec_1, NULL);
    ck_assert_int_eq(errno, 1);
}

START_TEST(s21_to_int_invalid_exp_n_extra_bits) {
    // степень 154 (показатель степени должен быть от 0 до 28)
    // биты 0-15 не нули
    // биты 24-30 не нули
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0xa00}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_exp) {
    // степень 29 (показатель степени должен быть от 0 до 28)
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x1d0000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_exp2) {
    // степень 29 (показатель степени должен быть от 0 до 28)
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x1d0000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_extra_bits) {
    // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x1c0001}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_extra_bits2) {
    // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x1c8000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_extra_bits3) {
    // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x11c0000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_extra_bits4) {
    // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x401c0000}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

START_TEST(s21_to_int_invalid_exp_n_extra_bits2) {
    // Просто все единицы
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}};
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);
    ck_assert_int_eq(errno, 1);
}
END_TEST

void test_from_decimal_to_int(s21_decimal dec_1, int check) {
    int res;
    int errno = s21_from_decimal_to_int(dec_1, &res);

    ck_assert_int_eq(res, check);
    ck_assert_int_eq(errno, 0);
}

START_TEST(s21_to_int_1) {
    // 792281625.14264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x140000}};
    int res = 792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_2) {
    // -792281625.14264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80140000}};
    int res = -792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_3) {
    // 79228162.514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x150000}};
    int res = 79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_4) {
    // -79228162.514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80150000}};
    int res = -79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_5) {
    // 7922816.2514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x160000}};
    int res = 7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_6) {
    // -7922816.2514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80160000}};
    int res = -7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_7) {
    // 792281.62514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x170000}};
    int res = 792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_8) {
    // -792281.62514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80170000}};
    int res = -792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_9) {
    // 79228.162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x180000}};
    int res = 79228;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_10) {
    // -79228.162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80180000}};
    int res = -79228;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_11) {
    // 7922.8162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x190000}};
    int res = 7922;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_12) {
    // -7922.8162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80190000}};
    int res = -7922;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_13) {
    // 792.28162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x1A0000}};
    int res = 792;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_14) {
    // -792.28162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801A0000}};
    int res = -792;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_15) {
    // 79.228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x1B0000}};
    int res = 79;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_16) {
    // -79.228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801B0000}};
    int res = -79;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_17) {
    // 7.9228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_18) {
    // -7.9228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_19) {
    // 792281625.14264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x140000}};
    int res = 792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_20) {
    // -792281625.14264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80140000}};
    int res = -792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_21) {
    // 79228162.514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x150000}};
    int res = 79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_22) {
    // -79228162.514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80150000}};
    int res = -79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_23) {
    // 7922816.2514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x160000}};
    int res = 7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_24) {
    // -7922816.2514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80160000}};
    int res = -7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_25) {
    // 792281.62514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x170000}};
    int res = 792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_26) {
    // -792281.62514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80170000}};
    int res = -792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_27) {
    // 79228.162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x180000}};
    int res = 79228;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_28) {
    // -79228.162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80180000}};
    int res = -79228;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_29) {
    // 7922.8162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x190000}};
    int res = 7922;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_30) {
    // -7922.8162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x80190000}};
    int res = -7922;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_31) {
    // 792.28162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x1A0000}};
    int res = 792;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_32) {
    // -792.28162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x801A0000}};
    int res = -792;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_33) {
    // 79.228162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x1B0000}};
    int res = 79;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_34) {
    // -79.228162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x801B0000}};
    int res = -79;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_35) {
    // 7.9228162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_36) {
    // -7.9228162514264337593543950334
    s21_decimal dec_1 = {{0xFFFFFFFE, 0xffffffff, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_37) {
    // 528187750.09509558395695966890
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
    int res = 528187750;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_38) {
    // -528187750.09509558395695966890
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
    int res = -528187750;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_39) {
    // 5.2818775009509558395695966890
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
    int res = 5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_40) {
    // -5.2818775009509558395695966890
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
    int res = -5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_41) {
    // 528187750.09509558392832655360
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
    int res = 528187750;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_42) {
    // -528187750.09509558392832655360
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
    int res = -528187750;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_43) {
    // 5.2818775009509558392832655360
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
    int res = 5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_44) {
    // -5.2818775009509558392832655360
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
    int res = -5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_45) {
    // 528187749.97211729016086244010
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
    int res = 528187749;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_46) {
    // -528187749.97211729016086244010
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
    int res = -528187749;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_47) {
    // 5.2818774997211729016086244010
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
    int res = 5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_48) {
    // -5.2818774997211729016086244010
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
    int res = -5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_49) {
    // 528187749.97211729013222932480
    s21_decimal dec_1 = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
    int res = 528187749;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_50) {
    // -528187749.97211729013222932480
    s21_decimal dec_1 = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
    int res = -528187749;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_51) {
    // 5.2818774997211729013222932480
    s21_decimal dec_1 = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
    int res = 5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_52) {
    // -5.2818774997211729013222932480
    s21_decimal dec_1 = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
    int res = -5;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_53) {
    // 122978293.82473034410
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
    int res = 122978293;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_54) {
    // -122978293.82473034410
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
    int res = -122978293;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_55) {
    // 1.2297829382473034410
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_56) {
    // -1.2297829382473034410
    s21_decimal dec_1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_57) {
    // 122978293.79609722880
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
    int res = 122978293;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_58) {
    // -122978293.79609722880
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
    int res = -122978293;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_59) {
    // 1.2297829379609722880
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_60) {
    // -1.2297829379609722880
    s21_decimal dec_1 = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_61) {
    // 286331153.0
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
    int res = 286331153;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_62) {
    // -286331153.0
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
    int res = -286331153;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_63) {
    // 286331.1530
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
    int res = 286331;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_64) {
    // -286331.1530
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
    int res = -286331;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_65) {
    // 2.863311530
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_66) {
    // -2.863311530
    s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_67) {
    // 264093875.04754779197847983445
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
    int res = 264093875;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_68) {
    // -264093875.04754779197847983445
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
    int res = -264093875;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_69) {
    // 2.6409387504754779197847983445
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_70) {
    // -2.6409387504754779197847983445
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_71) {
    // 264093875.04754779196416327680
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x55555555, 0x140000}};
    int res = 264093875;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_72) {
    // -264093875.04754779196416327680
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
    int res = -264093875;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_73) {
    // 2.6409387504754779196416327680
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_74) {
    // -2.6409387504754779196416327680
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_75) {
    // 264093874.98605864508043122005
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x55555555, 0x140000}};
    int res = 264093874;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_76) {
    // -264093874.98605864508043122005
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
    int res = -264093874;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_77) {
    // 2.6409387498605864508043122005
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_78) {
    // -2.6409387498605864508043122005
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_79) {
    // 264093874.98605864506611466240
    s21_decimal dec_1 = {{0x0, 0x0, 0x55555555, 0x140000}};
    int res = 264093874;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_80) {
    // -264093874.98605864506611466240
    s21_decimal dec_1 = {{0x0, 0x0, 0x55555555, 0x80140000}};
    int res = -264093874;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_81) {
    // 2.6409387498605864506611466240
    s21_decimal dec_1 = {{0x0, 0x0, 0x55555555, 0x1C0000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_82) {
    // -2.6409387498605864506611466240
    s21_decimal dec_1 = {{0x0, 0x0, 0x55555555, 0x801C0000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_83) {
    // 6148914.691236517205
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
    int res = 6148914;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_84) {
    // -6148914.691236517205
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
    int res = -6148914;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_85) {
    // 6.148914691236517205
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x0, 0x120000}};
    int res = 6;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_86) {
    // -6.148914691236517205
    s21_decimal dec_1 = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
    int res = -6;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_87) {
    // 6148914.689804861440
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0xC0000}};
    int res = 6148914;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_88) {
    // -6148914.689804861440
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x800C0000}};
    int res = -6148914;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_89) {
    // 6.148914689804861440
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x120000}};
    int res = 6;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_90) {
    // -6.148914689804861440
    s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x80120000}};
    int res = -6;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_91) {
    // 1431655765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x0}};
    int res = 1431655765;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_92) {
    // -1431655765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
    int res = -1431655765;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_93) {
    // 143165576.5
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x10000}};
    int res = 143165576;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_94) {
    // -143165576.5
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80010000}};
    int res = -143165576;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_95) {
    // 143165.5765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x40000}};
    int res = 143165;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_96) {
    // -143165.5765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80040000}};
    int res = -143165;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_97) {
    // 1.431655765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x90000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_98) {
    // -1.431655765
    s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80090000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_99) {
    // 184467440.78004518913
    s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0xB0000}};
    int res = 184467440;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_100) {
    // -184467440.78004518913
    s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0x800B0000}};
    int res = -184467440;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_101) {
    // 1.8446744078004518913
    s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_102) {
    // -1.8446744078004518913
    s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_103) {
    // 18446744.078004518912
    s21_decimal dec_1 = {{0x0, 0x1, 0x1, 0xC0000}};
    int res = 18446744;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_104) {
    // -18446744.078004518912
    s21_decimal dec_1 = {{0x0, 0x1, 0x1, 0x800C0000}};
    int res = -18446744;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_105) {
    // 1.8446744078004518912
    s21_decimal dec_1 = {{0x0, 0x1, 0x1, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_106) {
    // -1.8446744078004518912
    s21_decimal dec_1 = {{0x0, 0x1, 0x1, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_107) {
    // 1844674.4073709551617
    s21_decimal dec_1 = {{0x1, 0x0, 0x1, 0xD0000}};
    int res = 1844674;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_108) {
    // -1844674.4073709551617
    s21_decimal dec_1 = {{0x1, 0x0, 0x1, 0x800D0000}};
    int res = -1844674;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_109) {
    // 1.8446744073709551617
    s21_decimal dec_1 = {{0x1, 0x0, 0x1, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_110) {
    // -1.8446744073709551617
    s21_decimal dec_1 = {{0x1, 0x0, 0x1, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_111) {
    // 184467.44073709551616
    s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0xE0000}};
    int res = 184467;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_112) {
    // -184467.44073709551616
    s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x800E0000}};
    int res = -184467;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_113) {
    // 1.8446744073709551616
    s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_114) {
    // -1.8446744073709551616
    s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_115) {
    // 429496729.7
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x10000}};
    int res = 429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_116) {
    // -429496729.7
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80010000}};
    int res = -429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_117) {
    // 42949672.97
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x20000}};
    int res = 42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_118) {
    // -42949672.97
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80020000}};
    int res = -42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_119) {
    // 429496.7297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x40000}};
    int res = 429496;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_120) {
    // -429496.7297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80040000}};
    int res = -429496;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_121) {
    // 4.294967297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x90000}};
    int res = 4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_122) {
    // -4.294967297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80090000}};
    int res = -4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_123) {
    // 42.94967297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80000}};
    int res = 42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_124) {
    // -42.94967297
    s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80080000}};
    int res = -42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_125) {
    // 429496729.6
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x10000}};
    int res = 429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_126) {
    // -429496729.6
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80010000}};
    int res = -429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_127) {
    // 42949672.96
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x20000}};
    int res = 42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_128) {
    // -42949672.96
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80020000}};
    int res = -42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_129) {
    // 4294967.296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x30000}};
    int res = 4294967;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_130) {
    // -4294967.296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80030000}};
    int res = -4294967;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_131) {
    // 4.294967296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x90000}};
    int res = 4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_132) {
    // -4.294967296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80090000}};
    int res = -4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_133) {
    // 42.94967296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80000}};
    int res = 42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_134) {
    // -42.94967296
    s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80080000}};
    int res = -42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_135) {
    // 1
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_136) {
    // -1
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_137) {
    // 0.1
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x10000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_138) {
    // -0.1
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80010000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_139) {
    // 0.0000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0xD0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_140) {
    // -0.0000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x800D0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_141) {
    // 0.00000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0xE0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_142) {
    // -0.00000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x800E0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_143) {
    // 0.000000000000000000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_144) {
    // -0.000000000000000000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x801B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_145) {
    // 0.0000000000000000000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_146) {
    // -0.0000000000000000000000000001
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_147) {
    // 396140812.66355540835774234624
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x80000000, 0x140000}};
    int res = 396140812;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_148) {
    // -396140812.66355540835774234624
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x80000000, 0x80140000}};
    int res = -396140812;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_149) {
    // 3.9614081266355540835774234624
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_150) {
    // -3.9614081266355540835774234624
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_151) {
    // 39614081.266355540833626750976
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x80000000, 0x150000}};
    int res = 39614081;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_152) {
    // -39614081.266355540833626750976
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x80000000, 0x80150000}};
    int res = -39614081;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_153) {
    // 3.9614081266355540833626750976
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_154) {
    // -3.9614081266355540833626750976
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_155) {
    // 3961408.1257132168798919458816
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x80000000, 0x160000}};
    int res = 3961408;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_156) {
    // -3961408.1257132168798919458816
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x80000000, 0x80160000}};
    int res = -3961408;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_157) {
    // 3.9614081257132168798919458816
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_158) {
    // -3.9614081257132168798919458816
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_159) {
    // 396140.81257132168796771975168
    s21_decimal dec_1 = {{0x0, 0x0, 0x80000000, 0x170000}};
    int res = 396140;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_160) {
    // -396140.81257132168796771975168
    s21_decimal dec_1 = {{0x0, 0x0, 0x80000000, 0x80170000}};
    int res = -396140;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_161) {
    // 3.9614081257132168796771975168
    s21_decimal dec_1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_162) {
    // -3.9614081257132168796771975168
    s21_decimal dec_1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_163) {
    // 922337203.9002259456
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x0, 0xA0000}};
    int res = 922337203;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_164) {
    // -922337203.9002259456
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x0, 0x800A0000}};
    int res = -922337203;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_165) {
    // 9.223372039002259456
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x0, 0x120000}};
    int res = 9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_166) {
    // -9.223372039002259456
    s21_decimal dec_1 = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
    int res = -9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_167) {
    // 92233720.36854775808
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x0, 0xB0000}};
    int res = 92233720;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_168) {
    // -92233720.36854775808
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x0, 0x800B0000}};
    int res = -92233720;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_169) {
    // 9.223372036854775808
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x0, 0x120000}};
    int res = 9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_170) {
    // -9.223372036854775808
    s21_decimal dec_1 = {{0x0, 0x80000000, 0x0, 0x80120000}};
    int res = -9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_171) {
    // -2147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80000000}};
    int res = -2147483648;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_172) {
    // 214748364.8
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x10000}};
    int res = 214748364;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_173) {
    // -214748364.8
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80010000}};
    int res = -214748364;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_174) {
    // 21474836.48
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x20000}};
    int res = 21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_175) {
    // -21474836.48
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80020000}};
    int res = -21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_176) {
    // 214748.3648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x40000}};
    int res = 214748;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_177) {
    // -214748.3648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80040000}};
    int res = -214748;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_178) {
    // 21.47483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80000}};
    int res = 21;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_179) {
    // -21.47483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80080000}};
    int res = -21;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_180) {
    // 2.147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x90000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_181) {
    // -2.147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80090000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_182) {
    // 1560647.67562212695305426944
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x811800, 0x140000}};
    int res = 1560647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_183) {
    // -1560647.67562212695305426944
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x811800, 0x80140000}};
    int res = -1560647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_184) {
    // 1.56064767562212695305426944
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_185) {
    // -1.56064767562212695305426944
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_186) {
    // 15606476.7562212695296966656
    s21_decimal dec_1 = {{0x0, 0x811800, 0x811800, 0x130000}};
    int res = 15606476;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_187) {
    // -15606476.7562212695296966656
    s21_decimal dec_1 = {{0x0, 0x811800, 0x811800, 0x80130000}};
    int res = -15606476;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_188) {
    // 1.56064767562212695296966656
    s21_decimal dec_1 = {{0x0, 0x811800, 0x811800, 0x1A0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_189) {
    // -1.56064767562212695296966656
    s21_decimal dec_1 = {{0x0, 0x811800, 0x811800, 0x801A0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_190) {
    // 156064.767525876035030685696
    s21_decimal dec_1 = {{0x811800, 0x0, 0x811800, 0x150000}};
    int res = 156064;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_191) {
    // -156064.767525876035030685696
    s21_decimal dec_1 = {{0x811800, 0x0, 0x811800, 0x80150000}};
    int res = -156064;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_192) {
    // 1.56064767525876035030685696
    s21_decimal dec_1 = {{0x811800, 0x0, 0x811800, 0x1A0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_193) {
    // -1.56064767525876035030685696
    s21_decimal dec_1 = {{0x811800, 0x0, 0x811800, 0x801A0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_194) {
    // 15606.4767525876035022225408
    s21_decimal dec_1 = {{0x0, 0x0, 0x811800, 0x160000}};
    int res = 15606;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_195) {
    // -15606.4767525876035022225408
    s21_decimal dec_1 = {{0x0, 0x0, 0x811800, 0x80160000}};
    int res = -15606;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_196) {
    // 1.56064767525876035022225408
    s21_decimal dec_1 = {{0x0, 0x0, 0x811800, 0x1A0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_197) {
    // -1.56064767525876035022225408
    s21_decimal dec_1 = {{0x0, 0x0, 0x811800, 0x801A0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_198) {
    // 363366602.83201536
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x0, 0x80000}};
    int res = 363366602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_199) {
    // -363366602.83201536
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x0, 0x80080000}};
    int res = -363366602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_200) {
    // 3.6336660283201536
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x0, 0x100000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_201) {
    // -3.6336660283201536
    s21_decimal dec_1 = {{0x811800, 0x811800, 0x0, 0x80100000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_202) {
    // 3633666.0274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0xA0000}};
    int res = 3633666;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_203) {
    // -3633666.0274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x800A0000}};
    int res = -3633666;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_204) {
    // 363366602.74741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x80000}};
    int res = 363366602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_205) {
    // -363366602.74741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x80080000}};
    int res = -363366602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_206) {
    // 36.336660274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0xF0000}};
    int res = 36;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_207) {
    // -36.336660274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x800F0000}};
    int res = -36;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_208) {
    // 3.6336660274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x100000}};
    int res = 3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_209) {
    // -3.6336660274741248
    s21_decimal dec_1 = {{0x0, 0x811800, 0x0, 0x80100000}};
    int res = -3;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_210) {
    // 8460288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x0}};
    int res = 8460288;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_211) {
    // -8460288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80000000}};
    int res = -8460288;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_212) {
    // 846028.8
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x10000}};
    int res = 846028;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_213) {
    // -846028.8
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80010000}};
    int res = -846028;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_214) {
    // 84602.88
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x20000}};
    int res = 84602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_215) {
    // -84602.88
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80020000}};
    int res = -84602;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_216) {
    // 8460.288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x30000}};
    int res = 8460;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_217) {
    // -8460.288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80030000}};
    int res = -8460;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_218) {
    // 84.60288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x50000}};
    int res = 84;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_219) {
    // -84.60288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80050000}};
    int res = -84;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_220) {
    // 8.460288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x60000}};
    int res = 8;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_221) {
    // -8.460288
    s21_decimal dec_1 = {{0x811800, 0x0, 0x0, 0x80060000}};
    int res = -8;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_222) {
    // 792281625.14264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x140000}};
    int res = 792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_223) {
    // -792281625.14264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80140000}};
    int res = -792281625;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_224) {
    // 7.9228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_225) {
    // -7.9228162514264337593543950335
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_226) {
    // 79228162.514264337589248983040
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0xffffffff, 0x150000}};
    int res = 79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_227) {
    // -79228162.514264337589248983040
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0xffffffff, 0x80150000}};
    int res = -79228162;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_228) {
    // 7.9228162514264337589248983040
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_229) {
    // -7.9228162514264337589248983040
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_230) {
    // 7922816.2495817593524129366015
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0xffffffff, 0x160000}};
    int res = 7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_231) {
    // -7922816.2495817593524129366015
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0xffffffff, 0x80160000}};
    int res = -7922816;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_232) {
    // 7.9228162495817593524129366015
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_233) {
    // -7.9228162495817593524129366015
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_234) {
    // 792281.62495817593519834398720
    s21_decimal dec_1 = {{0x0, 0x0, 0xffffffff, 0x170000}};
    int res = 792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_235) {
    // -792281.62495817593519834398720
    s21_decimal dec_1 = {{0x0, 0x0, 0xffffffff, 0x80170000}};
    int res = -792281;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_236) {
    // 7.9228162495817593519834398720
    s21_decimal dec_1 = {{0x0, 0x0, 0xffffffff, 0x1C0000}};
    int res = 7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_237) {
    // -7.9228162495817593519834398720
    s21_decimal dec_1 = {{0x0, 0x0, 0xffffffff, 0x801C0000}};
    int res = -7;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_238) {
    // 184467440.73709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0xB0000}};
    int res = 184467440;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_239) {
    // -184467440.73709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0x800B0000}};
    int res = -184467440;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_240) {
    // 184.46744073709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0x110000}};
    int res = 184;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_241) {
    // -184.46744073709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0x80110000}};
    int res = -184;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_242) {
    // 1.8446744073709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_243) {
    // -1.8446744073709551615
    s21_decimal dec_1 = {{0xffffffff, 0xffffffff, 0x0, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_244) {
    // 18446744.069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0xC0000}};
    int res = 18446744;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_245) {
    // -18446744.069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0x800C0000}};
    int res = -18446744;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_246) {
    // 184.46744069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0x110000}};
    int res = 184;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_247) {
    // -184.46744069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0x80110000}};
    int res = -184;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_248) {
    // 1.8446744069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0x130000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_249) {
    // -1.8446744069414584320
    s21_decimal dec_1 = {{0x0, 0xffffffff, 0x0, 0x80130000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_250) {
    // 429496729.5
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x10000}};
    int res = 429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_251) {
    // -429496729.5
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80010000}};
    int res = -429496729;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_252) {
    // 42949672.95
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x20000}};
    int res = 42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_253) {
    // -42949672.95
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80020000}};
    int res = -42949672;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_254) {
    // 42949.67295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x50000}};
    int res = 42949;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_255) {
    // -42949.67295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80050000}};
    int res = -42949;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_256) {
    // 42.94967295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80000}};
    int res = 42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_257) {
    // -42.94967295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80080000}};
    int res = -42;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_258) {
    // 4.294967295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x90000}};
    int res = 4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_259) {
    // -4.294967295
    s21_decimal dec_1 = {{0xffffffff, 0x0, 0x0, 0x80090000}};
    int res = -4;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_260) {
    // 1.0
    s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x10000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_261) {
    // -1.0
    s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x80010000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_262) {
    // 1.00
    s21_decimal dec_1 = {{0x64, 0x0, 0x0, 0x20000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_263) {
    // -1.00
    s21_decimal dec_1 = {{0x64, 0x0, 0x0, 0x80020000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_264) {
    // 1.000
    s21_decimal dec_1 = {{0x3E8, 0x0, 0x0, 0x30000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_265) {
    // -1.000
    s21_decimal dec_1 = {{0x3E8, 0x0, 0x0, 0x80030000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_266) {
    // 1.0000000000
    s21_decimal dec_1 = {{0x540BE400, 0x2, 0x0, 0xA0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_267) {
    // -1.0000000000
    s21_decimal dec_1 = {{0x540BE400, 0x2, 0x0, 0x800A0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_268) {
    // 1.0000000000000000
    s21_decimal dec_1 = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_269) {
    // -1.0000000000000000
    s21_decimal dec_1 = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_270) {
    // 1.00000000000000000000000
    s21_decimal dec_1 = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_271) {
    // -1.00000000000000000000000
    s21_decimal dec_1 = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_272) {
    // 1.000000000000000000000000000
    s21_decimal dec_1 = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_273) {
    // -1.000000000000000000000000000
    s21_decimal dec_1 = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_274) {
    // 1.0000000000000000000000000000
    s21_decimal dec_1 = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_275) {
    // -1.0000000000000000000000000000
    s21_decimal dec_1 = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_276) {
    // 1.1
    s21_decimal dec_1 = {{0xB, 0x0, 0x0, 0x10000}};
    int res = 1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_277) {
    // -1.1
    s21_decimal dec_1 = {{0xB, 0x0, 0x0, 0x80010000}};
    int res = -1;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_278) {
    // 12.12
    s21_decimal dec_1 = {{0x4BC, 0x0, 0x0, 0x20000}};
    int res = 12;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_279) {
    // -12.12
    s21_decimal dec_1 = {{0x4BC, 0x0, 0x0, 0x80020000}};
    int res = -12;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_280) {
    // 123.123
    s21_decimal dec_1 = {{0x1E0F3, 0x0, 0x0, 0x30000}};
    int res = 123;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_281) {
    // -123.123
    s21_decimal dec_1 = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
    int res = -123;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_282) {
    // 1234.1234
    s21_decimal dec_1 = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
    int res = 1234;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_283) {
    // -1234.1234
    s21_decimal dec_1 = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
    int res = -1234;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_284) {
    // 12345.12345
    s21_decimal dec_1 = {{0x499529D9, 0x0, 0x0, 0x50000}};
    int res = 12345;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_285) {
    // -12345.12345
    s21_decimal dec_1 = {{0x499529D9, 0x0, 0x0, 0x80050000}};
    int res = -12345;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_286) {
    // 123456.123456
    s21_decimal dec_1 = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
    int res = 123456;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_287) {
    // -123456.123456
    s21_decimal dec_1 = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
    int res = -123456;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_288) {
    // 1234567.1234567
    s21_decimal dec_1 = {{0x73593407, 0xB3A, 0x0, 0x70000}};
    int res = 1234567;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_289) {
    // -1234567.1234567
    s21_decimal dec_1 = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
    int res = -1234567;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_290) {
    // 1234567890.1234567890
    s21_decimal dec_1 = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
    int res = 1234567890;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_291) {
    // -1234567890.1234567890
    s21_decimal dec_1 = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
    int res = -1234567890;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_292) {
    // 99
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x0}};
    int res = 99;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_293) {
    // -99
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x80000000}};
    int res = -99;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_294) {
    // 9.9
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x10000}};
    int res = 9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_295) {
    // -9.9
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x80010000}};
    int res = -9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_296) {
    // 99.99
    s21_decimal dec_1 = {{0x270F, 0x0, 0x0, 0x20000}};
    int res = 99;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_297) {
    // -99.99
    s21_decimal dec_1 = {{0x270F, 0x0, 0x0, 0x80020000}};
    int res = -99;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_298) {
    // 999.999
    s21_decimal dec_1 = {{0xF423F, 0x0, 0x0, 0x30000}};
    int res = 999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_299) {
    // -999.999
    s21_decimal dec_1 = {{0xF423F, 0x0, 0x0, 0x80030000}};
    int res = -999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_300) {
    // 9999.9999
    s21_decimal dec_1 = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};
    int res = 9999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_301) {
    // -9999.9999
    s21_decimal dec_1 = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};
    int res = -9999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_302) {
    // 99999.99999
    s21_decimal dec_1 = {{0x540BE3FF, 0x2, 0x0, 0x50000}};
    int res = 99999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_303) {
    // -99999.99999
    s21_decimal dec_1 = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};
    int res = -99999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_304) {
    // 999999.999999
    s21_decimal dec_1 = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};
    int res = 999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_305) {
    // -999999.999999
    s21_decimal dec_1 = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};
    int res = -999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_306) {
    // 9999999.9999999
    s21_decimal dec_1 = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};
    int res = 9999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_307) {
    // -9999999.9999999
    s21_decimal dec_1 = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};
    int res = -9999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_308) {
    // 99999999.99999999
    s21_decimal dec_1 = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};
    int res = 99999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_309) {
    // -99999999.99999999
    s21_decimal dec_1 = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};
    int res = -99999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_310) {
    // 999999999.999999999
    s21_decimal dec_1 = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};
    int res = 999999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_311) {
    // -999999999.999999999
    s21_decimal dec_1 = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};
    int res = -999999999;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_312) {
    // 9
    s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
    int res = 9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_313) {
    // -9
    s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x80000000}};
    int res = -9;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_314) {
    // 0.9
    s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x10000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_315) {
    // -0.9
    s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x80010000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_316) {
    // 0.99
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x20000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_317) {
    // -0.99
    s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x80020000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_318) {
    // 0.999
    s21_decimal dec_1 = {{0x3E7, 0x0, 0x0, 0x30000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_319) {
    // -0.999
    s21_decimal dec_1 = {{0x3E7, 0x0, 0x0, 0x80030000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_320) {
    // 0.9999
    s21_decimal dec_1 = {{0x270F, 0x0, 0x0, 0x40000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_321) {
    // -0.9999
    s21_decimal dec_1 = {{0x270F, 0x0, 0x0, 0x80040000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_322) {
    // 0.99999
    s21_decimal dec_1 = {{0x1869F, 0x0, 0x0, 0x50000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_323) {
    // -0.99999
    s21_decimal dec_1 = {{0x1869F, 0x0, 0x0, 0x80050000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_324) {
    // 0.999999
    s21_decimal dec_1 = {{0xF423F, 0x0, 0x0, 0x60000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_325) {
    // -0.999999
    s21_decimal dec_1 = {{0xF423F, 0x0, 0x0, 0x80060000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_326) {
    // 0.9999999
    s21_decimal dec_1 = {{0x98967F, 0x0, 0x0, 0x70000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_327) {
    // -0.9999999
    s21_decimal dec_1 = {{0x98967F, 0x0, 0x0, 0x80070000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_328) {
    // 0.99999999
    s21_decimal dec_1 = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_329) {
    // -0.99999999
    s21_decimal dec_1 = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_330) {
    // 0.999999999
    s21_decimal dec_1 = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_331) {
    // -0.999999999
    s21_decimal dec_1 = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_332) {
    // 0.9999999999
    s21_decimal dec_1 = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_333) {
    // -0.9999999999
    s21_decimal dec_1 = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_334) {
    // 0.99999999999999999999
    s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_335) {
    // -0.99999999999999999999
    s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_336) {
    // -0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x80000000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_337) {
    // 0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_338) {
    // -0.0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x80010000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_339) {
    // 0.0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x10000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_340) {
    // -0.00
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x80020000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_341) {
    // 0.00
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x20000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_342) {
    // -0.00000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x800E0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_343) {
    // 0.00000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0xE0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_344) {
    // -0.000000000000000000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x801B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_345) {
    // 0.000000000000000000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x1B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_346) {
    // -0.0000000000000000000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_347) {
    // 0.0000000000000000000000000000
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_348) {
    // 2147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
    int res = 2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_349) {
    // -2147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x80000000}};
    int res = -2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_350) {
    // 2147483646.00
    s21_decimal dec_1 = {{0xFFFFFF38, 0x31, 0x0, 0x20000}};
    int res = 2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_351) {
    // -2147483646.00
    s21_decimal dec_1 = {{0xFFFFFF38, 0x31, 0x0, 0x80020000}};
    int res = -2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_352) {
    // 2147483646.99
    s21_decimal dec_1 = {{0xFFFFFF9B, 0x31, 0x0, 0x20000}};
    int res = 2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_353) {
    // -2147483646.99
    s21_decimal dec_1 = {{0xFFFFFF9B, 0x31, 0x0, 0x80020000}};
    int res = -2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_354) {
    // 2147483646.999999999999999999
    s21_decimal dec_1 = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x120000}};
    int res = 2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_355) {
    // -2147483646.999999999999999999
    s21_decimal dec_1 = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x80120000}};
    int res = -2147483646;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_356) {
    // 21474836.46
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x20000}};
    int res = 21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_357) {
    // -21474836.46
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x80020000}};
    int res = -21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_358) {
    // 214.7483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x70000}};
    int res = 214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_359) {
    // -214.7483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x80070000}};
    int res = -214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_360) {
    // 2.147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x90000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_361) {
    // -2.147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x80090000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_362) {
    // 0.2147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0xA0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_363) {
    // -0.2147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x800A0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_364) {
    // 0.0000000000000000002147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_365) {
    // -0.0000000000000000002147483646
    s21_decimal dec_1 = {{0x7FFFFFFE, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_366) {
    // 2147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
    int res = 2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_367) {
    // -2147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
    int res = -2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_368) {
    // 2147483647.00
    s21_decimal dec_1 = {{0xFFFFFF9C, 0x31, 0x0, 0x20000}};
    int res = 2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_369) {
    // -2147483647.00
    s21_decimal dec_1 = {{0xFFFFFF9C, 0x31, 0x0, 0x80020000}};
    int res = -2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_370) {
    // 2147483647.99
    s21_decimal dec_1 = {{0xffffffff, 0x31, 0x0, 0x20000}};
    int res = 2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_371) {
    // -2147483647.99
    s21_decimal dec_1 = {{0xffffffff, 0x31, 0x0, 0x80020000}};
    int res = -2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_372) {
    // 2147483647.999999999999999999
    s21_decimal dec_1 = {{0xffffffff, 0xD3B1FFFF, 0x6F05B59, 0x120000}};
    int res = 2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_373) {
    // -2147483647.999999999999999999
    s21_decimal dec_1 = {{0xffffffff, 0xD3B1FFFF, 0x6F05B59, 0x80120000}};
    int res = -2147483647;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_374) {
    // 21474836.47
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x20000}};
    int res = 21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_375) {
    // -21474836.47
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x80020000}};
    int res = -21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_376) {
    // 214.7483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x70000}};
    int res = 214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_377) {
    // -214.7483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x80070000}};
    int res = -214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_378) {
    // 2.147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x90000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_379) {
    // -2.147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x80090000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_380) {
    // 0.2147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0xA0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_381) {
    // -0.2147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x800A0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_382) {
    // 0.0000000000000000002147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_383) {
    // -0.0000000000000000002147483647
    s21_decimal dec_1 = {{0x7FFFFFFF, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_384) {
    // -2147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80000000}};
    int res = -2147483648;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_385) {
    // -2147483648.00
    s21_decimal dec_1 = {{0x0, 0x32, 0x0, 0x80020000}};
    int res = -2147483648;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_386) {
    // -2147483648.99
    s21_decimal dec_1 = {{0x63, 0x32, 0x0, 0x80020000}};
    int res = -2147483648;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_387) {
    // -2147483648.999999999999999999
    s21_decimal dec_1 = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
    int res = -2147483648;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_388) {
    // 21474836.48
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x20000}};
    int res = 21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_389) {
    // -21474836.48
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80020000}};
    int res = -21474836;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_390) {
    // 214.7483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x70000}};
    int res = 214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_391) {
    // -214.7483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80070000}};
    int res = -214;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_392) {
    // 2.147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x90000}};
    int res = 2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_393) {
    // -2.147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x80090000}};
    int res = -2;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_394) {
    // 0.2147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0xA0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_395) {
    // -0.2147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x800A0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_396) {
    // 0.0000000000000000002147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_397) {
    // -0.0000000000000000002147483648
    s21_decimal dec_1 = {{0x80000000, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_398) {
    // -202378.6784
    s21_decimal dec_1 = {{0x78A08920, 0x0, 0x0, 0x80040000}};
    int res = -202378;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_399) {
    // 202378.6784
    s21_decimal dec_1 = {{0x78A08920, 0x0, 0x0, 0x40000}};
    int res = 202378;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_400) {
    // 1157199323
    s21_decimal dec_1 = {{0x44F975DB, 0x0, 0x0, 0x0}};
    int res = 1157199323;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_401) {
    // -1157199323
    s21_decimal dec_1 = {{0x44F975DB, 0x0, 0x0, 0x80000000}};
    int res = -1157199323;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_402) {
    // -1047971123
    s21_decimal dec_1 = {{0x3E76C533, 0x0, 0x0, 0x80000000}};
    int res = -1047971123;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_403) {
    // 1047971123
    s21_decimal dec_1 = {{0x3E76C533, 0x0, 0x0, 0x0}};
    int res = 1047971123;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_404) {
    // 1635973982
    s21_decimal dec_1 = {{0x6182FB5E, 0x0, 0x0, 0x0}};
    int res = 1635973982;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_405) {
    // -1635973982
    s21_decimal dec_1 = {{0x6182FB5E, 0x0, 0x0, 0x80000000}};
    int res = -1635973982;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_406) {
    // 1664922502
    s21_decimal dec_1 = {{0x633CB386, 0x0, 0x0, 0x0}};
    int res = 1664922502;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_407) {
    // -1664922502
    s21_decimal dec_1 = {{0x633CB386, 0x0, 0x0, 0x80000000}};
    int res = -1664922502;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_408) {
    // -1562427032
    s21_decimal dec_1 = {{0x5D20BE98, 0x0, 0x0, 0x80000000}};
    int res = -1562427032;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_409) {
    // 1562427032
    s21_decimal dec_1 = {{0x5D20BE98, 0x0, 0x0, 0x0}};
    int res = 1562427032;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_410) {
    // 18415446
    s21_decimal dec_1 = {{0x118FF56, 0x0, 0x0, 0x0}};
    int res = 18415446;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_411) {
    // -18415446
    s21_decimal dec_1 = {{0x118FF56, 0x0, 0x0, 0x80000000}};
    int res = -18415446;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_412) {
    // 2043799125
    s21_decimal dec_1 = {{0x79D1E655, 0x0, 0x0, 0x0}};
    int res = 2043799125;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_413) {
    // -2043799125
    s21_decimal dec_1 = {{0x79D1E655, 0x0, 0x0, 0x80000000}};
    int res = -2043799125;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_414) {
    // -699081605
    s21_decimal dec_1 = {{0x29AB2385, 0x0, 0x0, 0x80000000}};
    int res = -699081605;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_415) {
    // 699081605
    s21_decimal dec_1 = {{0x29AB2385, 0x0, 0x0, 0x0}};
    int res = 699081605;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_416) {
    // 7206047.80
    s21_decimal dec_1 = {{0x2AF38E6C, 0x0, 0x0, 0x20000}};
    int res = 7206047;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_417) {
    // -7206047.80
    s21_decimal dec_1 = {{0x2AF38E6C, 0x0, 0x0, 0x80020000}};
    int res = -7206047;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_418) {
    // -405011.4826
    s21_decimal dec_1 = {{0xF167D90A, 0x0, 0x0, 0x80040000}};
    int res = -405011;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_419) {
    // 405011.4826
    s21_decimal dec_1 = {{0xF167D90A, 0x0, 0x0, 0x40000}};
    int res = 405011;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_420) {
    // 0.0000000002899686912
    s21_decimal dec_1 = {{0xACD5B600, 0x0, 0x0, 0x130000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_421) {
    // -0.0000000002899686912
    s21_decimal dec_1 = {{0xACD5B600, 0x0, 0x0, 0x80130000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_422) {
    // -806251761
    s21_decimal dec_1 = {{0x300E6CF1, 0x0, 0x0, 0x80000000}};
    int res = -806251761;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_423) {
    // 806251761
    s21_decimal dec_1 = {{0x300E6CF1, 0x0, 0x0, 0x0}};
    int res = 806251761;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_424) {
    // -961415253
    s21_decimal dec_1 = {{0x394E0855, 0x0, 0x0, 0x80000000}};
    int res = -961415253;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_425) {
    // 961415253
    s21_decimal dec_1 = {{0x394E0855, 0x0, 0x0, 0x0}};
    int res = 961415253;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_426) {
    // 1362812644
    s21_decimal dec_1 = {{0x513ADEE4, 0x0, 0x0, 0x0}};
    int res = 1362812644;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_427) {
    // -1362812644
    s21_decimal dec_1 = {{0x513ADEE4, 0x0, 0x0, 0x80000000}};
    int res = -1362812644;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_428) {
    // 744018023
    s21_decimal dec_1 = {{0x2C58D067, 0x0, 0x0, 0x0}};
    int res = 744018023;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_429) {
    // -744018023
    s21_decimal dec_1 = {{0x2C58D067, 0x0, 0x0, 0x80000000}};
    int res = -744018023;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_430) {
    // -669134488
    s21_decimal dec_1 = {{0x27E22E98, 0x0, 0x0, 0x80000000}};
    int res = -669134488;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_431) {
    // 669134488
    s21_decimal dec_1 = {{0x27E22E98, 0x0, 0x0, 0x0}};
    int res = 669134488;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_432) {
    // 1135755779
    s21_decimal dec_1 = {{0x43B24203, 0x0, 0x0, 0x0}};
    int res = 1135755779;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_433) {
    // -1135755779
    s21_decimal dec_1 = {{0x43B24203, 0x0, 0x0, 0x80000000}};
    int res = -1135755779;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_434) {
    // -1066687460
    s21_decimal dec_1 = {{0x3F945BE4, 0x0, 0x0, 0x80000000}};
    int res = -1066687460;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_435) {
    // 1066687460
    s21_decimal dec_1 = {{0x3F945BE4, 0x0, 0x0, 0x0}};
    int res = 1066687460;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_436) {
    // 1775.200759
    s21_decimal dec_1 = {{0x69CF69F7, 0x0, 0x0, 0x60000}};
    int res = 1775;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_437) {
    // -1775.200759
    s21_decimal dec_1 = {{0x69CF69F7, 0x0, 0x0, 0x80060000}};
    int res = -1775;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_438) {
    // 2049377039
    s21_decimal dec_1 = {{0x7A27030F, 0x0, 0x0, 0x0}};
    int res = 2049377039;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_439) {
    // -2049377039
    s21_decimal dec_1 = {{0x7A27030F, 0x0, 0x0, 0x80000000}};
    int res = -2049377039;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_440) {
    // 644156872
    s21_decimal dec_1 = {{0x26650DC8, 0x0, 0x0, 0x0}};
    int res = 644156872;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_441) {
    // -644156872
    s21_decimal dec_1 = {{0x26650DC8, 0x0, 0x0, 0x80000000}};
    int res = -644156872;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_442) {
    // 411899256
    s21_decimal dec_1 = {{0x188D1578, 0x0, 0x0, 0x0}};
    int res = 411899256;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_443) {
    // -411899256
    s21_decimal dec_1 = {{0x188D1578, 0x0, 0x0, 0x80000000}};
    int res = -411899256;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_444) {
    // -0.0000000000000000321044217
    s21_decimal dec_1 = {{0x1322BEF9, 0x0, 0x0, 0x80190000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_445) {
    // 0.0000000000000000321044217
    s21_decimal dec_1 = {{0x1322BEF9, 0x0, 0x0, 0x190000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_446) {
    // 0.000000000000000003809359548
    s21_decimal dec_1 = {{0xE30E36BC, 0x0, 0x0, 0x1B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_447) {
    // -0.000000000000000003809359548
    s21_decimal dec_1 = {{0xE30E36BC, 0x0, 0x0, 0x801B0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_448) {
    // -0.000000000002807144663
    s21_decimal dec_1 = {{0xA751A0D7, 0x0, 0x0, 0x80150000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_449) {
    // 0.000000000002807144663
    s21_decimal dec_1 = {{0xA751A0D7, 0x0, 0x0, 0x150000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_450) {
    // 1802612012
    s21_decimal dec_1 = {{0x6B71AD2C, 0x0, 0x0, 0x0}};
    int res = 1802612012;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_451) {
    // -1802612012
    s21_decimal dec_1 = {{0x6B71AD2C, 0x0, 0x0, 0x80000000}};
    int res = -1802612012;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_452) {
    // 1498496264
    s21_decimal dec_1 = {{0x59513D08, 0x0, 0x0, 0x0}};
    int res = 1498496264;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_453) {
    // -1498496264
    s21_decimal dec_1 = {{0x59513D08, 0x0, 0x0, 0x80000000}};
    int res = -1498496264;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_454) {
    // 0.000000001060195434
    s21_decimal dec_1 = {{0x3F314C6A, 0x0, 0x0, 0x120000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_455) {
    // -0.000000001060195434
    s21_decimal dec_1 = {{0x3F314C6A, 0x0, 0x0, 0x80120000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_456) {
    // -346.3980837
    s21_decimal dec_1 = {{0xCE782725, 0x0, 0x0, 0x80070000}};
    int res = -346;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_457) {
    // 346.3980837
    s21_decimal dec_1 = {{0xCE782725, 0x0, 0x0, 0x70000}};
    int res = 346;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_458) {
    // -0.0000000000000000000791281307
    s21_decimal dec_1 = {{0x2F29FE9B, 0x0, 0x0, 0x801C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

START_TEST(s21_to_int_459) {
    // 0.0000000000000000000791281307
    s21_decimal dec_1 = {{0x2F29FE9B, 0x0, 0x0, 0x1C0000}};
    int res = 0;

    test_from_decimal_to_int(dec_1, res);
}

void s21_to_int_fail(s21_decimal decimal) {
    int result;
    int code = s21_from_decimal_to_int(decimal, &result);

    ck_assert_int_eq(code, 1);
}

START_TEST(s21_to_int_fail1) {
    // 79228162514264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail2) {
    // -79228162514264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail3) {
    // 7922816251426433759354395033.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail4) {
    // -7922816251426433759354395033.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail5) {
    // 792281625142643375935439503.35
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail6) {
    // -792281625142643375935439503.35
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail7) {
    // 79228162514264337593543950.335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail8) {
    // -79228162514264337593543950.335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail9) {
    // 7922816251426433759354395.0335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail10) {
    // -7922816251426433759354395.0335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail11) {
    // 792281625142643375935439.50335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail12) {
    // -792281625142643375935439.50335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail13) {
    // 79228162514264337593543.950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail14) {
    // -79228162514264337593543.950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail15) {
    // 7922816251426433759354.3950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail16) {
    // -7922816251426433759354.3950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail17) {
    // 792281625142643375935.43950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail18) {
    // -792281625142643375935.43950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail19) {
    // 79228162514264337593.543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail20) {
    // -79228162514264337593.543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail21) {
    // 7922816251426433759.3543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail22) {
    // -7922816251426433759.3543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail23) {
    // 792281625142643375.93543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail24) {
    // -792281625142643375.93543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail25) {
    // 79228162514264337.593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail26) {
    // -79228162514264337.593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail27) {
    // 7922816251426433.7593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail28) {
    // -7922816251426433.7593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail29) {
    // 792281625142643.37593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail30) {
    // -792281625142643.37593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail31) {
    // 79228162514264.337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail32) {
    // -79228162514264.337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail33) {
    // 7922816251426.4337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail34) {
    // -7922816251426.4337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail35) {
    // 792281625142.64337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail36) {
    // -792281625142.64337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail37) {
    // 79228162514.264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail38) {
    // -79228162514.264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail39) {
    // 7922816251.4264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail40) {
    // -7922816251.4264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail41) {
    // 79228162514264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail42) {
    // -79228162514264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail43) {
    // 7922816251426433759354395033.4
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail44) {
    // -7922816251426433759354395033.4
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail45) {
    // 792281625142643375935439503.34
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail46) {
    // -792281625142643375935439503.34
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail47) {
    // 79228162514264337593543950.334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail48) {
    // -79228162514264337593543950.334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail49) {
    // 7922816251426433759354395.0334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail50) {
    // -7922816251426433759354395.0334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail51) {
    // 792281625142643375935439.50334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail52) {
    // -792281625142643375935439.50334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail53) {
    // 79228162514264337593543.950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail54) {
    // -79228162514264337593543.950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail55) {
    // 7922816251426433759354.3950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail56) {
    // -7922816251426433759354.3950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail57) {
    // 792281625142643375935.43950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail58) {
    // -792281625142643375935.43950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail59) {
    // 79228162514264337593.543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail60) {
    // -79228162514264337593.543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail61) {
    // 7922816251426433759.3543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail62) {
    // -7922816251426433759.3543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail63) {
    // 792281625142643375.93543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail64) {
    // -792281625142643375.93543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail65) {
    // 79228162514264337.593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail66) {
    // -79228162514264337.593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail67) {
    // 7922816251426433.7593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail68) {
    // -7922816251426433.7593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail69) {
    // 792281625142643.37593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail70) {
    // -792281625142643.37593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail71) {
    // 79228162514264.337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail72) {
    // -79228162514264.337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail73) {
    // 7922816251426.4337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail74) {
    // -7922816251426.4337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail75) {
    // 792281625142.64337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail76) {
    // -792281625142.64337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail77) {
    // 79228162514.264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail78) {
    // -79228162514.264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail79) {
    // 7922816251.4264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail80) {
    // -7922816251.4264337593543950334
    s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail81) {
    // 52818775009509558395695966890
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail82) {
    // -52818775009509558395695966890
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail83) {
    // 5281877500950955839569596689.0
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail84) {
    // -5281877500950955839569596689.0
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail85) {
    // 52818775009509558392832655360
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail86) {
    // -52818775009509558392832655360
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail87) {
    // 5281877500950955839283265536.0
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail88) {
    // -5281877500950955839283265536.0
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail89) {
    // 52818774997211729016086244010
    s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail90) {
    // -52818774997211729016086244010
    s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail91) {
    // 5281877499721172901608624401.0
    s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail92) {
    // -5281877499721172901608624401.0
    s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail93) {
    // 52818774997211729013222932480
    s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail94) {
    // -52818774997211729013222932480
    s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail95) {
    // 5281877499721172901322293248.0
    s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail96) {
    // -5281877499721172901322293248.0
    s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail97) {
    // 12297829382473034410
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail98) {
    // -12297829382473034410
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail99) {
    // 1229782938247303441.0
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail100) {
    // -1229782938247303441.0
    s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail101) {
    // 12297829379609722880
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail102) {
    // -12297829379609722880
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail103) {
    // 1229782937960972288.0
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail104) {
    // -1229782937960972288.0
    s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail105) {
    // 2863311530
    s21_decimal decimal = {{0xaaaaaaaa, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail106) {
    // -2863311530
    s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail107) {
    // 26409387504754779197847983445
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail108) {
    // -26409387504754779197847983445
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail109) {
    // 2640938750475477919784798344.5
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail110) {
    // -2640938750475477919784798344.5
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail111) {
    // 26409387504754779196416327680
    s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail112) {
    // -26409387504754779196416327680
    s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail113) {
    // 2640938750475477919641632768.0
    s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail114) {
    // -2640938750475477919641632768.0
    s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail115) {
    // 26409387498605864508043122005
    s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail116) {
    // -26409387498605864508043122005
    s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail117) {
    // 2640938749860586450804312200.5
    s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail118) {
    // -2640938749860586450804312200.5
    s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail119) {
    // 26409387498605864506611466240
    s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail120) {
    // -26409387498605864506611466240
    s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail121) {
    // 2640938749860586450661146624.0
    s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail122) {
    // -2640938749860586450661146624.0
    s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail123) {
    // 6148914691236517205
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail124) {
    // -6148914691236517205
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail125) {
    // 614891469123651720.5
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail126) {
    // -614891469123651720.5
    s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail127) {
    // 6148914689804861440
    s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail128) {
    // -6148914689804861440
    s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail129) {
    // 614891468980486144.0
    s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail130) {
    // -614891468980486144.0
    s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail131) {
    // 18446744078004518913
    s21_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail132) {
    // -18446744078004518913
    s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail133) {
    // 1844674407800451891.3
    s21_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail134) {
    // -1844674407800451891.3
    s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail135) {
    // 18446744078004518912
    s21_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail136) {
    // -18446744078004518912
    s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail137) {
    // 1844674407800451891.2
    s21_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail138) {
    // -1844674407800451891.2
    s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail139) {
    // 18446744073709551617
    s21_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail140) {
    // -18446744073709551617
    s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail141) {
    // 1844674407370955161.7
    s21_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail142) {
    // -1844674407370955161.7
    s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail143) {
    // 18446744073709551616
    s21_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail144) {
    // -18446744073709551616
    s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail145) {
    // 1844674407370955161.6
    s21_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail146) {
    // -1844674407370955161.6
    s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail147) {
    // 4294967297
    s21_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail148) {
    // -4294967297
    s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail149) {
    // 4294967296
    s21_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail150) {
    // -4294967296
    s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail151) {
    // 39614081266355540835774234624
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail152) {
    // -39614081266355540835774234624
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail153) {
    // 3961408126635554083577423462.4
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail154) {
    // -3961408126635554083577423462.4
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail155) {
    // 39614081266355540833626750976
    s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail156) {
    // -39614081266355540833626750976
    s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail157) {
    // 3961408126635554083362675097.6
    s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail158) {
    // -3961408126635554083362675097.6
    s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail159) {
    // 39614081257132168798919458816
    s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail160) {
    // -39614081257132168798919458816
    s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail161) {
    // 3961408125713216879891945881.6
    s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail162) {
    // -3961408125713216879891945881.6
    s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail163) {
    // 39614081257132168796771975168
    s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail164) {
    // -39614081257132168796771975168
    s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail165) {
    // 3961408125713216879677197516.8
    s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail166) {
    // -3961408125713216879677197516.8
    s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail167) {
    // 9223372039002259456
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail168) {
    // -9223372039002259456
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail169) {
    // 922337203900225945.6
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail170) {
    // -922337203900225945.6
    s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail171) {
    // 9223372036854775808
    s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail172) {
    // -9223372036854775808
    s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail173) {
    // 922337203685477580.8
    s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail174) {
    // -922337203685477580.8
    s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail175) {
    // 2147483648
    s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail176) {
    // 156064767562212695305426944
    s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail177) {
    // -156064767562212695305426944
    s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail178) {
    // 15606476756221269530542694.4
    s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail179) {
    // -15606476756221269530542694.4
    s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail180) {
    // 156064767562212695296966656
    s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail181) {
    // -156064767562212695296966656
    s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail182) {
    // 15606476756221269529696665.6
    s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail183) {
    // -15606476756221269529696665.6
    s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail184) {
    // 156064767525876035030685696
    s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail185) {
    // -156064767525876035030685696
    s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail186) {
    // 15606476752587603503068569.6
    s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail187) {
    // -15606476752587603503068569.6
    s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail188) {
    // 156064767525876035022225408
    s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail189) {
    // -156064767525876035022225408
    s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail190) {
    // 15606476752587603502222540.8
    s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail191) {
    // -15606476752587603502222540.8
    s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail192) {
    // 36336660283201536
    s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail193) {
    // -36336660283201536
    s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail194) {
    // 3633666028320153.6
    s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail195) {
    // -3633666028320153.6
    s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail196) {
    // 36336660274741248
    s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail197) {
    // -36336660274741248
    s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail198) {
    // 3633666027474124.8
    s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail199) {
    // -3633666027474124.8
    s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail200) {
    // 79228162514264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail201) {
    // -79228162514264337593543950335
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail202) {
    // 7922816251426433759354395033.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail203) {
    // -7922816251426433759354395033.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail204) {
    // 79228162514264337589248983040
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail205) {
    // -79228162514264337589248983040
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail206) {
    // 7922816251426433758924898304.0
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail207) {
    // -7922816251426433758924898304.0
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail208) {
    // 79228162495817593524129366015
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail209) {
    // -79228162495817593524129366015
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail210) {
    // 7922816249581759352412936601.5
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail211) {
    // -7922816249581759352412936601.5
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail212) {
    // 79228162495817593519834398720
    s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail213) {
    // -79228162495817593519834398720
    s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail214) {
    // 7922816249581759351983439872.0
    s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail215) {
    // -7922816249581759351983439872.0
    s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail216) {
    // 18446744073709551615
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail217) {
    // -18446744073709551615
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail218) {
    // 1844674407370955161.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail219) {
    // -1844674407370955161.5
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail220) {
    // 18446744073709551.615
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail221) {
    // -18446744073709551.615
    s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail222) {
    // 18446744069414584320
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail223) {
    // -18446744069414584320
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail224) {
    // 1844674406941458432.0
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail225) {
    // -1844674406941458432.0
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail226) {
    // 18446744069414584.320
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail227) {
    // -18446744069414584.320
    s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail228) {
    // 4294967295
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail229) {
    // -4294967295
    s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail230) {
    // 12345678901234.12345678901234
    s21_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail231) {
    // -12345678901234.12345678901234
    s21_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail232) {
    // 9999999999.9999999999
    s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail233) {
    // -9999999999.9999999999
    s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail234) {
    // 2147483648
    s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail235) {
    // 2147483648.00
    s21_decimal decimal = {{0x0, 0x32, 0x0, 0x20000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail236) {
    // 2147483648.99
    s21_decimal decimal = {{0x63, 0x32, 0x0, 0x20000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail237) {
    // 2147483648.999999999999999999
    s21_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x120000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail238) {
    // 3436350754
    s21_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail239) {
    // -3436350754
    s21_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail240) {
    // -2467171175
    s21_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail241) {
    // 2467171175
    s21_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail242) {
    // -2296067528
    s21_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail243) {
    // 2296067528
    s21_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail244) {
    // 3848964437
    s21_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail245) {
    // -3848964437
    s21_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail246) {
    // -3182863462
    s21_decimal decimal = {{0xBDB6A466, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail247) {
    // 3182863462
    s21_decimal decimal = {{0xBDB6A466, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail248) {
    // -48847109575696535634899575831
    s21_decimal decimal = {{0x26532417, 0x149403E0, 0x9DD561CC, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail249) {
    // 48847109575696535634899575831
    s21_decimal decimal = {{0x26532417, 0x149403E0, 0x9DD561CC, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail250) {
    // -3318846837
    s21_decimal decimal = {{0xC5D19575, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail251) {
    // 3318846837
    s21_decimal decimal = {{0xC5D19575, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail252) {
    // -2313332038
    s21_decimal decimal = {{0x89E2A546, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail253) {
    // 2313332038
    s21_decimal decimal = {{0x89E2A546, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail254) {
    // 3374693184
    s21_decimal decimal = {{0xC925BB40, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail255) {
    // -3374693184
    s21_decimal decimal = {{0xC925BB40, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail256) {
    // 4020511056
    s21_decimal decimal = {{0xEFA42150, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail257) {
    // -4020511056
    s21_decimal decimal = {{0xEFA42150, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail258) {
    // 3004972040
    s21_decimal decimal = {{0xB31C3C08, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail259) {
    // -3004972040
    s21_decimal decimal = {{0xB31C3C08, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail260) {
    // -2859313295
    s21_decimal decimal = {{0xAA6DA88F, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail261) {
    // 2859313295
    s21_decimal decimal = {{0xAA6DA88F, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail262) {
    // 3559609781
    s21_decimal decimal = {{0xD42B55B5, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail263) {
    // -3559609781
    s21_decimal decimal = {{0xD42B55B5, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail264) {
    // -2633735568
    s21_decimal decimal = {{0x9CFB9D90, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail265) {
    // 2633735568
    s21_decimal decimal = {{0x9CFB9D90, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail266) {
    // 3849297796
    s21_decimal decimal = {{0xE56F9F84, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail267) {
    // -3849297796
    s21_decimal decimal = {{0xE56F9F84, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail268) {
    // -66249387729842137051875589617
    s21_decimal decimal = {{0x75E13DF1, 0x206039BC, 0xD6103589, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail269) {
    // 66249387729842137051875589617
    s21_decimal decimal = {{0x75E13DF1, 0x206039BC, 0xD6103589, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail270) {
    // 4000259692
    s21_decimal decimal = {{0xEE6F1E6C, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail271) {
    // -4000259692
    s21_decimal decimal = {{0xEE6F1E6C, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail272) {
    // 299970448737931080006163233.37
    s21_decimal decimal = {{0xA9C59909, 0x3FD3888, 0x60ECF955, 0x20000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail273) {
    // -299970448737931080006163233.37
    s21_decimal decimal = {{0xA9C59909, 0x3FD3888, 0x60ECF955, 0x80020000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail274) {
    // -3238025630
    s21_decimal decimal = {{0xC100599E, 0x0, 0x0, 0x80000000}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_to_int_fail275) {
    // 3238025630
    s21_decimal decimal = {{0xC100599E, 0x0, 0x0, 0x0}};

    s21_to_int_fail(decimal);
}

START_TEST(s21_int_to_decimal_pos) {
    // 56
    s21_decimal dec_check = {{0x38, 0x0, 0x0, 0x0}}, result;
    int src = 56;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST


START_TEST(s21_int_to_decimal_neg) {
    // -56
    s21_decimal dec_check = {{0x38, 0x0, 0x0, 0x80000000}}, result;
    int src = -56;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_zero) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    int src = 0;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_min) {
    // -2147483648
    s21_decimal dec_check = {{0x80000000, 0x0, 0x0, 0x80000000}}, result;
    int src = -2147483648;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_null_pointer) {
    int src = -2147483648;
    int return_value = s21_from_int_to_decimal(src, NULL);

    ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_int_to_decimal_1) {
    s21_decimal dec_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}}, result;
    int src = -2147483647;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_2) {
    s21_decimal dec_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}}, result;
    int src = -214748364;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_3) {
    s21_decimal dec_check = {{0x346DC, 0x0, 0x0, 0x80000000}}, result;
    int src = -214748;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_4) {
    s21_decimal dec_check = {{0x3E8, 0x0, 0x0, 0x80000000}}, result;
    int src = -1000;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_5) {
    s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x80000000}}, result;
    int src = -1;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_6) {
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    int src = 0;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_7) {
    s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}}, result;
    int src = 1;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_8) {
    s21_decimal dec_check = {{0x3E8, 0x0, 0x0, 0x0}}, result;
    int src = 1000;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_9) {
    s21_decimal dec_check = {{0x346DC, 0x0, 0x0, 0x0}}, result;
    int src = 214748;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_10) {
    s21_decimal dec_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}}, result;
    int src = 214748364;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_11) {
    s21_decimal dec_check = {{0x7FFFFFFE, 0x0, 0x0, 0x0}}, result;
    int src = 2147483646;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_int_to_decimal_12) {
    s21_decimal dec_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}}, result;
    int src = 2147483647;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}

START_TEST(s21_dec_to_float_pos) {
    // 3.862393
    s21_decimal dec_1 = {{0x3aef79, 0x0, 0x0, 0x60000}};
    float eps = 0.0000001;
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 3.862393;
    ck_assert_float_lt(fabsf(check - res), eps);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_neg) {
    // -0.565402
    s21_decimal dec_1 = {{0x8a09a, 0x0, 0x0, 0x80060000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.565402;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_zero) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.0;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks) {
    // 89756573578
    s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 89756573578;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks_neg) {
    // -89756573578
    s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -89756573578;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value) {
    // 0.000756765987677
    s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0xf0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.000756765987677;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value_neg) {
    // -0.000756765987677
    s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0x800f0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.000756765987677;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int) {
    // 695487777
    s21_decimal dec_1 = {{0x29744d21, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 695487777;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_neg) {
    // -695487777
    s21_decimal dec_1 = {{0x29744d21, 0x0, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -695487777;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_2) {
    // 43467987
    s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 43467987;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_neg_2) {
    // -43467987
    s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -43467987;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int) {
    // 695487776
    s21_decimal dec_1 = {{0x29744d20, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 695487776;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int_neg) {
    // -695487776
    s21_decimal dec_1 = {{0x29744d20, 0x0, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -695487776;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac) {
    // 0.6477234698832035064697265625
    s21_decimal dec_1 = {{0xf9db1dd9, 0x9bcdd061, 0x14edd7cc, 0x1c0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.6477234698832035064697265625;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_neg) {
    // -0.6477234698832035064697265625
    s21_decimal dec_1 = {{0xf9db1dd9, 0x9bcdd061, 0x14edd7cc, 0x801c0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.6477234698832035064697265625;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_2) {
    // 0.64772348105907440185546875
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.64772348105907440185546875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_neg_2) {
    // -0.64772348105907440185546875
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.64772348105907440185546875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac) {
    // 0.6477234661579132080078125
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.64772348105907440185546875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac_neg) {
    // -0.6477234661579132080078125
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.64772348105907440185546875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int) {
    // 11875002.75
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x20000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.75;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_neg) {
    // -11875002.75
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x80020000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.75;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_2) {
    // 11875002.5078125
    s21_decimal dec_1 = {{0xa50fd56d, 0x6c00, 0x0, 0x70000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.5078125;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_neg_2) {
    // -11875002.5078125
    s21_decimal dec_1 = {{0xa50fd56d, 0x6c00, 0x0, 0x80070000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.5078125;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int) {
    // 11875002.5
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x10000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.5;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int_neg) {
    // -11875002.5
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x80010000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.5;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int) {
    // 2716749.12890625
    s21_decimal dec_1 = {{0x3ead5f01, 0xf716, 0x0, 0x80000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 2716749.12890625;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_neg) {
    // -2716749.12890625
    s21_decimal dec_1 = {{0x3ead5f01, 0xf716, 0x0, 0x80080000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -2716749.12890625;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_2) {
    // 2716749.1875
    s21_decimal dec_1 = {{0x534f0723, 0x6, 0x0, 0x40000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 2716749.1875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_neg_2) {
    // -2716749.1875
    s21_decimal dec_1 = {{0x534f0723, 0x6, 0x0, 0x80040000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -2716749.1875;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int) {
    // 2716749.125
    s21_decimal dec_1 = {{0xa1ee4d45, 0x0, 0x0, 0x30000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 2716749.125;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int_neg) {
    // -2716749.125
    s21_decimal dec_1 = {{0xa1ee4d45, 0x0, 0x0, 0x80030000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -2716749.125;
    ck_assert_float_eq(res, res);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_float_to_decimal_pos) {
    // 21758100.1210
    s21_decimal dec_check = {{0x14c0094, 0x0, 0x0, 0x0}}, result;
    float src = 21758100.1210;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST


START_TEST(s21_float_to_decimal_neg) {
    // -3.862393
    s21_decimal dec_check = {{0x3aef79, 0x0, 0x0, 0x80060000}}, result;
    float src = -3.862393;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_zero) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = 0.0;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_zero_neg) {
    // -0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}}, result;
    float src = -0.0;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
    ck_assert_int_eq(get_sign(result), get_sign(dec_check));
}
END_TEST

START_TEST(s21_float_to_decimal_overflow) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = powf(2, 96);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 1);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_neg_overflow) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = powf(2, -94);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 1);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_8) {
    // 1208925819614629174706176 to
    // 1208926000000000000000000
    s21_decimal dec_check = {{0xfeb80000, 0x280db89, 0x10000, 0x0}}, result;
    float src = powf(2, 80);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_8_neg) {
    // -1208925819614629174706176 to
    // -1208926000000000000000000
    s21_decimal dec_check = {{0xfeb80000, 0x280db89, 0x10000, 0x80000000}}, result;
    float src = -powf(2, 80);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_6) {
    // 38685626227668133590597632 to
    // 38685630000000000000000000
    s21_decimal dec_check = {{0x88380000, 0x345a03d8, 0x200000, 0x0}}, result;
    float src = powf(2, 85);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_6_neg) {
    // -38685626227668133590597632 to
    // -38685630000000000000000000
    s21_decimal dec_check = {{0x88380000, 0x345a03d8, 0x200000, 0x80000000}}, result;
    float src = -powf(2, 85);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_5) {
    // 8589934592 to
    // 8589935000
    s21_decimal dec_check = {{0x198, 0x2, 0x0, 0x0}}, result;
    float src = powf(2, 33);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_5_neg) {
    // -8589934592 to
    // -8589935000
    s21_decimal dec_check = {{0x198, 0x2, 0x0, 0x80000000}}, result;
    float src = -powf(2, 33);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_only_frac) {
    // 0.000386549
    s21_decimal dec_check = {{0x3afb92, 0x0, 0x0, 0xa0000}}, result;
    float src = 0.000386549;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_only_frac_neg) {
    // 0.000386549
    s21_decimal dec_check = {{0x3afb92, 0x0, 0x0, 0x800a0000}}, result;
    float src = -0.000386549;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(s21_is_equal(dec_check, result), 1);
}
END_TEST

Suite *s21_converter_cases(void) {
  Suite *c = suite_create("s21_converter_cases");
  TCase *tc = tcase_create("s21_converter_tc");
  tcase_add_test(tc, s21_to_int_pos);
  tcase_add_test(tc, s21_to_int_neg);
  tcase_add_test(tc, s21_to_int_zero);
  tcase_add_test(tc, s21_to_int_failure);
  tcase_add_test(tc, s21_to_int_null_pointer);
  tcase_add_test(tc, s21_to_int_invalid_exp_n_extra_bits);
  tcase_add_test(tc, s21_to_int_invalid_exp);
  tcase_add_test(tc, s21_to_int_invalid_exp2);
  tcase_add_test(tc, s21_to_int_invalid_extra_bits);
  tcase_add_test(tc, s21_to_int_invalid_extra_bits2);
  tcase_add_test(tc, s21_to_int_invalid_extra_bits3);
  tcase_add_test(tc, s21_to_int_invalid_extra_bits4);
  tcase_add_test(tc, s21_to_int_invalid_exp_n_extra_bits2);
  tcase_add_test(tc, s21_int_to_decimal_pos);
  tcase_add_test(tc, s21_int_to_decimal_neg);
  tcase_add_test(tc, s21_int_to_decimal_zero);
    tcase_add_test(tc, s21_int_to_decimal_min);
    tcase_add_test(tc, s21_int_to_decimal_null_pointer);
  tcase_add_test(tc, s21_dec_to_float_pos);
  tcase_add_test(tc, s21_dec_to_float_neg);
  tcase_add_test(tc, s21_dec_to_float_zero);
    tcase_add_test(tc, s21_dec_to_float_two_blocks);
    tcase_add_test(tc, s21_dec_to_float_two_blocks_neg);
    tcase_add_test(tc, s21_dec_to_float_small_value);
    tcase_add_test(tc, s21_dec_to_float_small_value_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_int);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_int_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_int_2);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_int_neg_2);
    tcase_add_test(tc, s21_dec_to_float_round_down_only_int);
    tcase_add_test(tc, s21_dec_to_float_round_down_only_int_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_frac);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_frac_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_frac_2);
    tcase_add_test(tc, s21_dec_to_float_round_up_only_frac_neg_2);
    tcase_add_test(tc, s21_dec_to_float_round_down_only_frac);
    tcase_add_test(tc, s21_dec_to_float_round_down_only_frac_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int_2);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int_neg_2);
    tcase_add_test(tc, s21_dec_to_float_round_down_frac_to_int);
    tcase_add_test(tc, s21_dec_to_float_round_down_frac_to_int_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int_neg);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int_2);
    tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int_neg_2);
    tcase_add_test(tc, s21_dec_to_float_round_down_frac_with_int);
    tcase_add_test(tc, s21_dec_to_float_round_down_frac_with_int_neg);
  tcase_add_test(tc, s21_float_to_decimal_pos);
  tcase_add_test(tc, s21_float_to_decimal_neg);
  tcase_add_test(tc, s21_float_to_decimal_zero);
  tcase_add_test(tc, s21_float_to_decimal_zero_neg);
  tcase_add_test(tc, s21_float_to_decimal_overflow);
  tcase_add_test(tc, s21_float_to_decimal_neg_overflow);
  tcase_add_test(tc, s21_float_to_decimal_rounding_8);
  tcase_add_test(tc, s21_float_to_decimal_rounding_8_neg);
  tcase_add_test(tc, s21_float_to_decimal_rounding_6);
  tcase_add_test(tc, s21_float_to_decimal_rounding_6_neg);
  tcase_add_test(tc, s21_float_to_decimal_rounding_5);
  tcase_add_test(tc, s21_float_to_decimal_rounding_5_neg);
  tcase_add_test(tc, s21_float_to_decimal_only_frac);
  tcase_add_test(tc, s21_float_to_decimal_only_frac_neg);
    suite_add_tcase(c, tc);
  return c;
}