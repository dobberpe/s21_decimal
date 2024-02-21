#include "s21_decimal_test.h"

START_TEST(s21_is_less_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_less(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_less_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_less(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_less_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_less(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_less_or_equal(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_less_or_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_less_or_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_greater_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_greater(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_greater_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_greater(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_greater_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_greater(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_greater_or_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_greater_or_equal(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_greater_or_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_equal_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_equal(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_equal_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_equal(dec_1, dec_2), 0);
}
END_TEST

START_TEST(s21_is_equal_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_gr) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    ck_assert_int_eq(s21_is_not_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_less) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x0}};
    ck_assert_int_eq(s21_is_not_equal(dec_1, dec_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_eq) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    s21_decimal dec_2 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x80000000}};
    ck_assert_int_eq(s21_is_not_equal(dec_1, dec_2), 0);
}
END_TEST

Suite *s21_compare_cases(void) {
  Suite *c = suite_create("s21_compare_cases");
  TCase *tc = tcase_create("s21_compare_tc");

  tcase_add_test(tc, s21_is_less_gr);
  tcase_add_test(tc, s21_is_less_less);
  tcase_add_test(tc, s21_is_less_eq);
  
    tcase_add_test(tc, s21_is_less_or_equal_gr);
  tcase_add_test(tc, s21_is_less_or_equal_less);
  tcase_add_test(tc, s21_is_less_or_equal_eq);

    tcase_add_test(tc, s21_is_greater_gr);
  tcase_add_test(tc, s21_is_greater_less);
  tcase_add_test(tc, s21_is_greater_eq);

  tcase_add_test(tc, s21_is_greater_or_equal_gr);
  tcase_add_test(tc, s21_is_greater_or_equal_less);
  tcase_add_test(tc, s21_is_greater_or_equal_eq);
  
    tcase_add_test(tc, s21_is_equal_gr);
  tcase_add_test(tc, s21_is_equal_less);
  tcase_add_test(tc, s21_is_equal_eq);

    tcase_add_test(tc, s21_is_not_equal_gr);
  tcase_add_test(tc, s21_is_not_equal_less);
  tcase_add_test(tc, s21_is_not_equal_eq);
    suite_add_tcase(c, tc);
  return c;
}