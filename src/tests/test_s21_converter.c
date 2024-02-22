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
  
    suite_add_tcase(c, tc);
  return c;
}