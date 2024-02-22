#include "s21_decimal_test.h"

START_TEST(s21_dectostr_pos) {
    //     300.06260577433905
    s21_decimal dec_1 = {{0xf6c17931, 0x6a9a88, 0x0, 0xe0000}};
    char *res = dectostr(dec_1);
    ck_assert_str_eq(res, "300.06260577433905");
    free(res);
}
END_TEST

START_TEST(s21_dectostr_neg) {
  // -62608.5874666619884066
  s21_decimal dec_1 = {{0x399d5222, 0xf0afd9dd, 0x21, 0x80100000}};
    char *res = dectostr(dec_1);
    ck_assert_str_eq(res, "-62608.5874666619884066");
    free(res);
}
END_TEST

START_TEST(s21_dectostr_zero) {
    //     0
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    char *res = dectostr(dec_1);
    ck_assert_str_eq(res, "0");
    free(res);
}
END_TEST

Suite *s21_dectostr_cases(void) {
  Suite *c = suite_create("s21_dectostr_cases");
  TCase *tc = tcase_create("s21_dectostr_tc");
  tcase_add_test(tc, s21_dectostr_pos);
  tcase_add_test(tc, s21_dectostr_neg);
  tcase_add_test(tc, s21_dectostr_zero);
  
    suite_add_tcase(c, tc);
  return c;
}