#include "s21_decimal_test.h"

START_TEST(s21_floor_pos) {
    s21_decimal res = {0};
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    int err = s21_floor(dec_1, &res);
    s21_decimal dec_res = {{0x12c, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_floor_neg) {
    s21_decimal res = {0};
    //     -82918803.9796867183137
    s21_decimal dec_1 = {{0xfebbb221, 0xf34bb0f7, 0x2c, 0x800d0000}};
    int err = s21_floor(dec_1, &res);
    s21_decimal dec_res = {{0x4f13d94, 0x0, 0x0, 0x80000000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_floor_zero) {
    s21_decimal res = {0};
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x70000}};
    int err = s21_floor(dec_1, &res);
    s21_decimal dec_res = {{0x0, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_round_pos) {
    s21_decimal res = {0};
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    int err = s21_round(dec_1, &res);
    s21_decimal dec_res = {{0x12c, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_round_neg) {
    s21_decimal res = {0};
    //     -82918803.9796867183137
    s21_decimal dec_1 = {{0xfebbb221, 0xf34bb0f7, 0x2c, 0x800d0000}};
    int err = s21_round(dec_1, &res);
    s21_decimal dec_res = {{0x4f13d94, 0x0, 0x0, 0x80000000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_round_zero) {
    s21_decimal res = {0};
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x70000}};
    int err = s21_round(dec_1, &res);
    s21_decimal dec_res = {{0x0, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_truncate_pos) {
    s21_decimal res = {0};
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    int err = s21_truncate(dec_1, &res);
    s21_decimal dec_res = {{0x12c, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_truncate_neg) {
    s21_decimal res = {0};
    //     -82918803.9796867183137
    s21_decimal dec_1 = {{0xfebbb221, 0xf34bb0f7, 0x2c, 0x800d0000}};
    int err = s21_truncate(dec_1, &res);
    s21_decimal dec_res = {{0x4f13d93, 0x0, 0x0, 0x80000000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_truncate_zero) {
    s21_decimal res = {0};
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x70000}};
    int err = s21_truncate(dec_1, &res);
    s21_decimal dec_res = {{0x0, 0x0, 0x0, 0x0}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_negate_pos) {
    s21_decimal res = {0};
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    int err = s21_negate(dec_1, &res);
    s21_decimal dec_res = {{0xf6c17931, 0x6a9a88, 0x0, 0x800e0000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_negate_neg) {
    s21_decimal res = {0};
    //     -82918803.9796867183137
    s21_decimal dec_1 = {{0xfebbb221, 0xf34bb0f7, 0x2c, 0x800d0000}};
    int err = s21_negate(dec_1, &res);
    s21_decimal dec_res = {{0xfebbb221, 0xf34bb0f7, 0x2c, 0xd0000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_negate_zero) {
    s21_decimal res = {0};
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x70000}};
    int err = s21_negate(dec_1, &res);
    s21_decimal dec_res = {{0x0, 0x0, 0x0, 0x80070000}};
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(res.bits[0], dec_res.bits[0]);
    ck_assert_int_eq(res.bits[1], dec_res.bits[1]);
    ck_assert_int_eq(res.bits[2], dec_res.bits[2]);
    ck_assert_int_eq(res.bits[3], dec_res.bits[3]);
}
END_TEST

START_TEST(s21_pow_test) {
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_pow(dec_1, 2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_other_cases(void) {
  Suite *c = suite_create("s21_other_cases");
  TCase *tc = tcase_create("s21_other_tc");
  tcase_add_test(tc, s21_floor_pos);
  tcase_add_test(tc, s21_floor_neg);
  tcase_add_test(tc, s21_floor_zero);
  
    tcase_add_test(tc, s21_round_pos);
  tcase_add_test(tc, s21_round_neg);
  tcase_add_test(tc, s21_round_zero);
  
    tcase_add_test(tc, s21_truncate_pos);
  tcase_add_test(tc, s21_truncate_neg);
  tcase_add_test(tc, s21_truncate_zero);
  
    tcase_add_test(tc, s21_negate_pos);
  tcase_add_test(tc, s21_negate_neg);
  tcase_add_test(tc, s21_negate_zero);
  tcase_add_test(tc, s21_pow_test);
  
    suite_add_tcase(c, tc);
  return c;
}