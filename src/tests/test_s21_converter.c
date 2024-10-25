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
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_zero) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 0.0;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks) {
  // 89756573578
  s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x0}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 89756573578;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_two_blocks_neg) {
  // -89756573578
  s21_decimal dec_1 = {{0xe5e89f8a, 0x14, 0x0, 0x80000000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -89756573578;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value) {
  // 0.000756765987677
  s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0xf0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 0.000756765987677;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_small_value_neg) {
  // -0.000756765987677
  s21_decimal dec_1 = {{0x32c4935d, 0xb0, 0x0, 0x800f0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -0.000756765987677;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int) {
  // 695487777
  s21_decimal dec_1 = {{0x29744d21, 0x0, 0x0, 0x0}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 695487777;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_neg) {
  // -695487777
  s21_decimal dec_1 = {{0x29744d21, 0x0, 0x0, 0x80000000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -695487777;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_2) {
  // 43467987
  s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x0}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 43467987;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_int_neg_2) {
  // -43467987
  s21_decimal dec_1 = {{0x29744d3, 0x0, 0x0, 0x80000000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -43467987;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int) {
  // 695487776
  s21_decimal dec_1 = {{0x29744d20, 0x0, 0x0, 0x0}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 695487776;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_int_neg) {
  // -695487776
  s21_decimal dec_1 = {{0x29744d20, 0x0, 0x0, 0x80000000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -695487776;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac) {
  // 0.6477234698832035064697265625
  s21_decimal dec_1 = {{0xf9db1dd9, 0x9bcdd061, 0x14edd7cc, 0x1c0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 0.6477234698832035064697265625;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_neg) {
  // -0.6477234698832035064697265625
  s21_decimal dec_1 = {{0xf9db1dd9, 0x9bcdd061, 0x14edd7cc, 0x801c0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -0.6477234698832035064697265625;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_2) {
  // 0.64772348105907440185546875
  s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 0.64772348105907440185546875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_only_frac_neg_2) {
  // -0.64772348105907440185546875
  s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -0.64772348105907440185546875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac) {
  // 0.6477234661579132080078125
  s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x1a0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 0.64772348105907440185546875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_only_frac_neg) {
  // -0.6477234661579132080078125
  s21_decimal dec_1 = {{0x9dc4987b, 0x6d3e294, 0x359414, 0x801a0000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -0.64772348105907440185546875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int) {
  // 11875002.75
  s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x20000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 11875002.75;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_neg) {
  // -11875002.75
  s21_decimal dec_1 = {{0x46c7d0f3, 0x0, 0x0, 0x80020000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -11875002.75;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_2) {
  // 11875002.5078125
  s21_decimal dec_1 = {{0xa50fd56d, 0x6c00, 0x0, 0x70000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 11875002.5078125;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_to_int_neg_2) {
  // -11875002.5078125
  s21_decimal dec_1 = {{0xa50fd56d, 0x6c00, 0x0, 0x80070000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -11875002.5078125;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int) {
  // 11875002.5
  s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x10000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 11875002.5;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_to_int_neg) {
  // -11875002.5
  s21_decimal dec_1 = {{0x713fb49, 0x0, 0x0, 0x80010000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -11875002.5;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int) {
  // 2716749.12890625
  s21_decimal dec_1 = {{0x3ead5f01, 0xf716, 0x0, 0x80000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 2716749.12890625;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_neg) {
  // -2716749.12890625
  s21_decimal dec_1 = {{0x3ead5f01, 0xf716, 0x0, 0x80080000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -2716749.12890625;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_2) {
  // 2716749.1875
  s21_decimal dec_1 = {{0x534f0723, 0x6, 0x0, 0x40000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 2716749.1875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_up_frac_with_int_neg_2) {
  // -2716749.1875
  s21_decimal dec_1 = {{0x534f0723, 0x6, 0x0, 0x80040000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -2716749.1875;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int) {
  // 2716749.125
  s21_decimal dec_1 = {{0xa1ee4d45, 0x0, 0x0, 0x30000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = 2716749.125;
  ck_assert_float_eq(check, res);
  ck_assert_int_eq(errno, 0);
}
END_TEST

START_TEST(s21_dec_to_float_round_down_frac_with_int_neg) {
  // -2716749.125
  s21_decimal dec_1 = {{0xa1ee4d45, 0x0, 0x0, 0x80030000}};
  float res;
  int errno = s21_from_decimal_to_float(dec_1, &res);
  float check = -2716749.125;
  ck_assert_float_eq(check, res);
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
  s21_decimal dec_check = {{0xfeb80000, 0x280db89, 0x10000, 0x80000000}},
              result;
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
  s21_decimal dec_check = {{0x88380000, 0x345a03d8, 0x200000, 0x80000000}},
              result;
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