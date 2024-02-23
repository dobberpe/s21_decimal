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

START_TEST(s21_int_to_decimal_pos) {
    // 56
    s21_decimal dec_check = {{0x38, 0x0, 0x0, 0x0}}, result;
    int src = 56;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_int_to_decimal_neg) {
    // -56
    s21_decimal dec_check = {{0x38, 0x0, 0x0, 0x80000000}}, result;
    int src = -56;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_int_to_decimal_zero) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    int src = 0;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


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
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_zero) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.0;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks) {
    // 89756573578
    s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 89756573578;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks_neg) {
    // -89756573578
    s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -89756573578;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value) {
    // 0.000756765987677
    s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0xf0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.000756765987677;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value_neg) {
    // -0.000756765987677
    s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0x800f0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.000756765987677;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int) {
    // 43467987
    s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 43467987;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_neg) {
    // -43467987
    s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -43467987;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int) {
    // 43467986
    s21_decimal dec_1 = {{0x29744d2, 0x0, 0x0, 0x0}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 43467986;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int_neg) {
    // -43467986
    s21_decimal dec_1 = {{0x29744d2, 0x0, 0x0, 0x80000000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -43467986;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac) {
    // 0.64772348105907440185546875
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.64772348105907440185546875;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_neg) {
    // -0.64772348105907440185546875
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.64772348105907440185546875;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac) {
    // 0.6477234661579132080078125
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 0.64772348105907440185546875;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac_neg) {
    // -0.6477234661579132080078125
    s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -0.64772348105907440185546875;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int) {
    // 11875002.75
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x20000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.75;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_neg) {
    // -11875002.75
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x80020000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.75;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int) {
    // 11875002.5
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x10000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.5;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int_neg) {
    // -11875002.5
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x80010000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.5;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int) {
    // 2716749.1875
    printf("WITH\n");
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x20000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.75;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_neg) {
    // -2716749.1875
    s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x80020000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.75;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int) {
    // 2716749.125
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x10000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = 11875002.5;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int_neg) {
    // -2716749.125
    s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x80010000}};
    float res;
    int errno = s21_from_decimal_to_float(dec_1, &res);
    float check = -11875002.5;
    ck_assert_float_eq(res, check);
    ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_float_to_decimal_pos) {
    // 21758100.1210
    s21_decimal dec_check = {{0x14c0094, 0x0, 0x0, 0x0}}, result;
    float src = 21758100.1210;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_float_to_decimal_neg) {
    // -3.862393
    s21_decimal dec_check = {{0x3aef79, 0x0, 0x0, 0x80060000}}, result;
    float src = -3.862393;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_zero) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = 0.0;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_overflow) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = powf(2, 96);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 1);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_neg_overflow) {
    // 0
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}}, result;
    float src = powf(2, -94);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 1);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_8) {
    // 1208925819614629174706176 to
    // 1208926000000000000000000
    s21_decimal dec_check = {{0xfeb80000, 0x280db89, 0x10000, 0x0}}, result;
    float src = powf(2, 80);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_8_neg) {
    // -1208925819614629174706176 to
    // -1208926000000000000000000
    s21_decimal dec_check = {{0xfeb80000, 0x280db89, 0x10000, 0x80000000}}, result;
    float src = -powf(2, 80);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_6) {
    // 38685626227668133590597632 to
    // 38685630000000000000000000
    s21_decimal dec_check = {{0x88380000, 0x345a03d8, 0x200000, 0x0}}, result;
    float src = powf(2, 85);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_6_neg) {
    // -38685626227668133590597632 to
    // -38685630000000000000000000
    s21_decimal dec_check = {{0x88380000, 0x345a03d8, 0x200000, 0x80000000}}, result;
    float src = -powf(2, 85);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_5) {
    // 8589934592 to
    // 8589935000
    s21_decimal dec_check = {{0x198, 0x2, 0x0, 0x0}}, result;
    float src = powf(2, 33);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_rounding_5_neg) {
    // -8589934592 to
    // -8589935000
    s21_decimal dec_check = {{0x198, 0x2, 0x0, 0x80000000}}, result;
    float src = -powf(2, 33);
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_only_frac) {
    // 0.000386549
    s21_decimal dec_check = {{0x3afb92, 0x0, 0x0, 0xa0000}}, result;
    float src = 0.000386549;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_float_to_decimal_only_frac_neg) {
    // 0.000386549
    s21_decimal dec_check = {{0x3afb92, 0x0, 0x0, 0x800a0000}}, result;
    float src = -0.000386549;
    int return_value = s21_from_float_to_decimal(src, &result);
    ck_assert_int_eq(return_value, 0);
    // printf("\n%s\n\n", dectostr(result));
    // printf("\n%s\n\n", dectostr(dec_check));
    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_converter_cases(void) {
  Suite *c = suite_create("s21_converter_cases");
  TCase *tc = tcase_create("s21_converter_tc");
  tcase_add_test(tc, s21_to_int_pos);
  tcase_add_test(tc, s21_to_int_neg);
  tcase_add_test(tc, s21_to_int_zero);
  tcase_add_test(tc, s21_to_int_failure);
  tcase_add_test(tc, s21_int_to_decimal_pos);
  tcase_add_test(tc, s21_int_to_decimal_neg);
  tcase_add_test(tc, s21_int_to_decimal_zero);
  tcase_add_test(tc, s21_dec_to_float_pos);
  tcase_add_test(tc, s21_dec_to_float_neg);
  tcase_add_test(tc, s21_dec_to_float_zero);
  tcase_add_test(tc, s21_float_to_decimal_pos);
  tcase_add_test(tc, s21_float_to_decimal_neg);
  tcase_add_test(tc, s21_float_to_decimal_zero);
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
  tcase_add_test(tc, s21_dec_to_float_two_blocks);
  tcase_add_test(tc, s21_dec_to_float_two_blocks_neg);
  tcase_add_test(tc, s21_dec_to_float_small_value);
  tcase_add_test(tc, s21_dec_to_float_small_value_neg);
  tcase_add_test(tc, s21_dec_to_float_round_up_only_int);
  tcase_add_test(tc, s21_dec_to_float_round_up_only_int_neg);
  tcase_add_test(tc, s21_dec_to_float_round_down_only_int);
  tcase_add_test(tc, s21_dec_to_float_round_down_only_int_neg);
  tcase_add_test(tc, s21_dec_to_float_round_up_only_frac);
  tcase_add_test(tc, s21_dec_to_float_round_up_only_frac_neg);
  tcase_add_test(tc, s21_dec_to_float_round_down_only_frac);
  tcase_add_test(tc, s21_dec_to_float_round_down_only_frac_neg);
  tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int);
  tcase_add_test(tc, s21_dec_to_float_round_up_frac_to_int_neg);
  tcase_add_test(tc, s21_dec_to_float_round_down_frac_to_int);
  tcase_add_test(tc, s21_dec_to_float_round_down_frac_to_int_neg);
  tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int);
  tcase_add_test(tc, s21_dec_to_float_round_up_frac_with_int_neg);
  tcase_add_test(tc, s21_dec_to_float_round_down_frac_with_int);
  tcase_add_test(tc, s21_dec_to_float_round_down_frac_with_int_neg);
    suite_add_tcase(c, tc);
  return c;
}