#include "s21_decimal_test.h"

START_TEST(invalid_dec_s21_add_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_add(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST


START_TEST(s21_add_2) {
  // 4831804634358541057233
  s21_decimal dec_1 = {{0x7305fcd1, 0xeec26af3, 0x105, 0x0}};
  // -6013
  s21_decimal dec_2 = {{0x177d, 0x0, 0x0, 0x80000000}};
  // 4831804634358541051220
  s21_decimal dec_check = {{0x7305e554, 0xeec26af3, 0x105, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_3) {
  // -961637177269
  s21_decimal dec_1 = {{0xe60ad7b5, 0xdf, 0x0, 0x80000000}};
  // 92
  s21_decimal dec_2 = {{0x5c, 0x0, 0x0, 0x0}};
  // -961637177177
  s21_decimal dec_check = {{0xe60ad759, 0xdf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // -77646074
  s21_decimal dec_1 = {{0x4a0c8fa, 0x0, 0x0, 0x80000000}};
  // -8821.451060
  s21_decimal dec_2 = {{0xdcca934, 0x2, 0x0, 0x80060000}};
  // -77654895.451060
  s21_decimal dec_check = {{0x70755bb4, 0x46a0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -17463315424438175847
  s21_decimal dec_1 = {{0x9a3cc867, 0xf25a28da, 0x0, 0x80000000}};
  // 96111374
  s21_decimal dec_2 = {{0x5ba8b0e, 0x0, 0x0, 0x0}};
  // -17463315424342064473
  s21_decimal dec_check = {{0x94823d59, 0xf25a28da, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // -578.8
  s21_decimal dec_1 = {{0x169c, 0x0, 0x0, 0x80010000}};
  // 211205860925
  s21_decimal dec_2 = {{0x2cd9ae3d, 0x31, 0x0, 0x0}};
  // 211205860346.2
  s21_decimal dec_check = {{0xc080b7c6, 0x1eb, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // 840820.587472209888685
  s21_decimal dec_1 = {{0x9454c5ad, 0x94bacd72, 0x2d, 0xf0000}};
  // -183856369.573841674112393
  s21_decimal dec_2 = {{0x4a030d89, 0xdfaf1e9d, 0x26ee, 0x800f0000}};
  // -183015548.986369464223708
  s21_decimal dec_check = {{0xb5ae47dc, 0x4af4512a, 0x26c1, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_8) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // 8127874082536932421479296
  s21_decimal dec_2 = {{0xe9d2b80, 0xefd898d7, 0x6b924, 0x0}};
  // 8127874082536932421479299
  s21_decimal dec_check = {{0xe9d2b83, 0xefd898d7, 0x6b924, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_9) {
  // 3465693720370468229323098895
  s21_decimal dec_1 = {{0xe2bf0b0f, 0xa2d2926, 0xb32c131, 0x0}};
  // -677816853835893543596476.090
  s21_decimal dec_2 = {{0xeb5046ba, 0x46184c7c, 0x230ad4d, 0x80030000}};
  // 3465015903516632335779502418.9
  s21_decimal dec_check = {{0x3544fd3d, 0x25102a1d, 0x6ff5f095, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_10) {
  // 66094127.83
  s21_decimal dec_1 = {{0x89f3a2af, 0x1, 0x0, 0x20000}};
  // 79228162514264337593268628992
  s21_decimal dec_2 = {{0xef96ee00, 0xffffffff, 0xffffffff, 0x0}};
  // 79228162514264337593334723120
  s21_decimal dec_check = {{0xf3877230, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_11) {
  // 370322396791982295.13647954
  s21_decimal dec_1 = {{0x51983752, 0xbc50e7fe, 0x1ea1e1, 0x80000}};
  // 34247.8843135217145510437005
  s21_decimal dec_2 = {{0xbd208d, 0x49b241ca, 0x11b4ab7, 0x160000}};
  // 370322396792016543.02079306171
  s21_decimal dec_check = {{0x6c79c9bb, 0x9c166442, 0x77a859c7, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_12) {
  // 0.308
  s21_decimal dec_1 = {{0x134, 0x0, 0x0, 0x30000}};
  // -7.6
  s21_decimal dec_2 = {{0x4c, 0x0, 0x0, 0x80010000}};
  // -7.292
  s21_decimal dec_check = {{0x1c7c, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_13) {
  // -29182.892
  s21_decimal dec_1 = {{0x1bd4bac, 0x0, 0x0, 0x80030000}};
  // 26486062738361675313614
  s21_decimal dec_2 = {{0x858a71ce, 0xcff5635d, 0x59b, 0x0}};
  // 26486062738361675284431.108
  s21_decimal dec_check = {{0xa30f4104, 0x568c2551, 0x15e8a4, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_add_15) {
  // -4761437456500368032597667
  s21_decimal dec_1 = {{0x8fbf06a3, 0xaae7640, 0x3f046, 0x80000000}};
  // 771800
  s21_decimal dec_2 = {{0xbc6d8, 0x0, 0x0, 0x0}};
  // -4761437456500368031825867
  s21_decimal dec_check = {{0x8fb33fcb, 0xaae7640, 0x3f046, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_16) {
  // 970218217446333991086.203563
  s21_decimal dec_1 = {{0xefe422ab, 0xf4ff0792, 0x3228bb2, 0x60000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 970218217446333991083.203563
  s21_decimal dec_check = {{0xefb65beb, 0xf4ff0792, 0x3228bb2, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_17) {
  // -9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x80000000}};
  // 5812434731.95
  s21_decimal dec_2 = {{0x54cf8d2b, 0x87, 0x0, 0x20000}};
  // 5812434722.95
  s21_decimal dec_check = {{0x54cf89a7, 0x87, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_18) {
  // 9848783588.2138482
  s21_decimal dec_1 = {{0x3873ab72, 0x15de62a, 0x0, 0x70000}};
  // 4554769178944683
  s21_decimal dec_2 = {{0xd6f1e4ab, 0x102e89, 0x0, 0x0}};
  // 4554779027728271.2138482
  s21_decimal dec_check = {{0x32ea32f2, 0x26918ea7, 0x9a5, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_19) {
  // 7745795989552896025
  s21_decimal dec_1 = {{0xdbf21819, 0x6b7e9869, 0x0, 0x0}};
  // 3.9
  s21_decimal dec_2 = {{0x27, 0x0, 0x0, 0x10000}};
  // 7745795989552896028.9
  s21_decimal dec_check = {{0x9774f121, 0x32f1f422, 0x4, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_20) {
  // -9712.76427312726831418
  s21_decimal dec_1 = {{0xd98713a, 0xa72b0c99, 0x34, 0x80110000}};
  // 71281883880607503134
  s21_decimal dec_2 = {{0xc840d31e, 0xdd3c1fb8, 0x3, 0x0}};
  // 71281883880607493421.235726873
  s21_decimal dec_check = {{0xa2c46a19, 0x1c572cd4, 0xe652fe0c, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_21) {
  // -1.050725644991191857015
  s21_decimal dec_1 = {{0xed303777, 0xf5bf5f22, 0x38, 0x80150000}};
  // 6438651720781856435936
  s21_decimal dec_2 = {{0xbc22eee0, 0xa3e0a9c, 0x15d, 0x0}};
  // 6438651720781856435934.9492744
  s21_decimal dec_check = {{0x5dce5c08, 0xc64cd958, 0xd00b475b, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_22) {
  // 85916.738
  s21_decimal dec_1 = {{0x51efc42, 0x0, 0x0, 0x30000}};
  // 362699650
  s21_decimal dec_2 = {{0x159e5b82, 0x0, 0x0, 0x0}};
  // 362785566.738
  s21_decimal dec_check = {{0x77b47012, 0x54, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_23) {
  // 833255.8024833147162
  s21_decimal dec_1 = {{0x3482a11a, 0x73a33160, 0x0, 0xd0000}};
  // -5303003.0
  s21_decimal dec_2 = {{0x3292c8e, 0x0, 0x0, 0x80010000}};
  // -4469747.1975166852838
  s21_decimal dec_check = {{0xadcc3ee6, 0x6c4d51f1, 0x2, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_24) {
  // -1156273649874355871070442277
  s21_decimal dec_1 = {{0x7925325, 0x28b93489, 0x3bc7278, 0x80000000}};
  // -8550972457761053
  s21_decimal dec_2 = {{0x6bd4391d, 0x1e6110, 0x0, 0x80000000}};
  // -1156273649882906843528203330
  s21_decimal dec_check = {{0x73668c42, 0x28d79599, 0x3bc7278, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_25) {
  // 109518127584.08579
  s21_decimal dec_1 = {{0x9d1c8d83, 0x26e89d, 0x0, 0x50000}};
  // -461793.2375882017
  s21_decimal dec_2 = {{0x2adc7921, 0x1067fc, 0x0, 0x800a0000}};
  // 109517665790.8482017983
  s21_decimal dec_check = {{0x86918abf, 0x5ea117df, 0x3b, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_26) {
  // 632783353.7728641
  s21_decimal dec_1 = {{0x8e36d081, 0x167b21, 0x0, 0x70000}};
  // -325007198
  s21_decimal dec_2 = {{0x135f375e, 0x0, 0x0, 0x80000000}};
  // 307776155.7728641
  s21_decimal dec_check = {{0x345a0d81, 0xaef35, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_27) {
  // 337655123.452383871931688211
  s21_decimal dec_1 = {{0xe06a513, 0xeb7e5b23, 0x1174d40, 0x120000}};
  // 90.463
  s21_decimal dec_2 = {{0x1615f, 0x0, 0x0, 0x30000}};
  // 337655213.915383871931688211
  s21_decimal dec_check = {{0xea302513, 0xd2eb7e57, 0x1174d45, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_28) {
  // 46174907123205971
  s21_decimal dec_1 = {{0x589d8753, 0xa40bd5, 0x0, 0x0}};
  // 64637017.814250358
  s21_decimal dec_2 = {{0x7628b376, 0xe5a306, 0x0, 0x90000}};
  // 46174907187842988.814250358
  s21_decimal dec_check = {{0x4bde3176, 0xbbff97e6, 0x2631ea, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_29) {
  // -47933.88318732302496
  s21_decimal dec_1 = {{0x888bb8a0, 0x42858947, 0x0, 0x800e0000}};
  // 10337087810359067909436370925
  s21_decimal dec_2 = {{0xc3fa6fed, 0xee8943c, 0x2166a37d, 0x0}};
  // 10337087810359067909436322991
  s21_decimal dec_check = {{0xc3f9b4af, 0xee8943c, 0x2166a37d, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_30) {
  // 46843635302
  s21_decimal dec_1 = {{0xe8192666, 0xa, 0x0, 0x0}};
  // -825189795102083
  s21_decimal dec_2 = {{0x789bfd83, 0x2ee81, 0x0, 0x80000000}};
  // -825142951466781
  s21_decimal dec_check = {{0x9082d71d, 0x2ee76, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_31) {
  // -9368996796031102784828627
  s21_decimal dec_1 = {{0xf7b6f4d3, 0x5581e5d3, 0x7bff6, 0x80000000}};
  // -359705650271
  s21_decimal dec_2 = {{0xc020a45f, 0x53, 0x0, 0x80000000}};
  // -9368996796031462490478898
  s21_decimal dec_check = {{0xb7d79932, 0x5581e627, 0x7bff6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_32) {
  // -4.809230464
  s21_decimal dec_1 = {{0x1ea70880, 0x1, 0x0, 0x80090000}};
  // -15984195656039
  s21_decimal dec_2 = {{0x9c4dd967, 0xe89, 0x0, 0x80000000}};
  // -15984195656043.809230464
  s21_decimal dec_check = {{0x11284e80, 0x81468d46, 0x362, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_33) {
  // 9454
  s21_decimal dec_1 = {{0x24ee, 0x0, 0x0, 0x0}};
  // -53791654360850
  s21_decimal dec_2 = {{0x58733712, 0x30ec, 0x0, 0x80000000}};
  // -53791654351396
  s21_decimal dec_check = {{0x58731224, 0x30ec, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_34) {
  // -644813487221702390557376335
  s21_decimal dec_1 = {{0xc062ff4f, 0x2f479816, 0x2156091, 0x80000000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -644813487221702390557376330
  s21_decimal dec_check = {{0xc062ff4a, 0x2f479816, 0x2156091, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_35) {
  // 89567
  s21_decimal dec_1 = {{0x15ddf, 0x0, 0x0, 0x0}};
  // -9966212956375353809296
  s21_decimal dec_2 = {{0x68965990, 0x44fd1890, 0x21c, 0x80000000}};
  // -9966212956375353719729
  s21_decimal dec_check = {{0x6894fbb1, 0x44fd1890, 0x21c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_37) {
  // 99770000310668025.046460
  s21_decimal dec_1 = {{0x9beea5bc, 0x8ae4d66f, 0x1520, 0x60000}};
  // -493841791064460.54
  s21_decimal dec_2 = {{0x3529fae6, 0xaf72a6, 0x0, 0x80020000}};
  // 99276158519603564.506460
  s21_decimal dec_check = {{0xe415ed5c, 0xc57659f2, 0x1505, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_38) {
  // -7.04
  s21_decimal dec_1 = {{0x2c0, 0x0, 0x0, 0x80020000}};
  // -22.8
  s21_decimal dec_2 = {{0xe4, 0x0, 0x0, 0x80010000}};
  // -29.84
  s21_decimal dec_check = {{0xba8, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_39) {
  // -653804303603
  s21_decimal dec_1 = {{0x39c5f4f3, 0x98, 0x0, 0x80000000}};
  // 381098746564.01145
  s21_decimal dec_2 = {{0xa55456f9, 0x8764ba, 0x0, 0x50000}};
  // -272705557038.98855
  s21_decimal dec_check = {{0x98ef2e7, 0x60e26d, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_40) {
  // -553320194902
  s21_decimal dec_1 = {{0xd4742356, 0x80, 0x0, 0x80000000}};
  // -851
  s21_decimal dec_2 = {{0x353, 0x0, 0x0, 0x80000000}};
  // -553320195753
  s21_decimal dec_check = {{0xd47426a9, 0x80, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_42) {
  // -1214558653621.35
  s21_decimal dec_1 = {{0xa5b5f6d7, 0x6e76, 0x0, 0x80020000}};
  // 355.508064533575165288478244
  s21_decimal dec_2 = {{0xd7d7624, 0xcb9052df, 0x12611c2, 0x180000}};
  // -1214558653265.8419354664248347
  s21_decimal dec_check = {{0xab11241b, 0x3daeb6a4, 0x273e97fd, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_44) {
  // 80230558363125152.362
  s21_decimal dec_1 = {{0x6551fa6a, 0x596c33c0, 0x4, 0x30000}};
  // -655434952320
  s21_decimal dec_2 = {{0x9af7ae80, 0x98, 0x0, 0x80000000}};
  // 80229902928172832.362
  s21_decimal dec_check = {{0xdd0566a, 0x5969dfa3, 0x4, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_45) {
  // -9071649262
  s21_decimal dec_1 = {{0x1cb661ee, 0x2, 0x0, 0x80000000}};
  // 63556273
  s21_decimal dec_2 = {{0x3c9cab1, 0x0, 0x0, 0x0}};
  // -9008092989
  s21_decimal dec_check = {{0x18ec973d, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_46) {
  // -54108405
  s21_decimal dec_1 = {{0x339a0f5, 0x0, 0x0, 0x80000000}};
  // 980947029695764707.1337265
  s21_decimal dec_2 = {{0x9d3ddb31, 0x7349c9e4, 0x81d3c, 0x70000}};
  // 980947029641656302.1337265
  s21_decimal dec_check = {{0xaaa5d2b1, 0x7347ddc7, 0x81d3c, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_47) {
  // -39.0
  s21_decimal dec_1 = {{0x186, 0x0, 0x0, 0x80010000}};
  // -4.920043857503
  s21_decimal dec_2 = {{0x8977665f, 0x479, 0x0, 0x800c0000}};
  // -43.920043857503
  s21_decimal dec_check = {{0xee9cd65f, 0x27f1, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_48) {
  // 52174551632.55961518235678
  s21_decimal dec_1 = {{0xf71e601e, 0xcfa7071a, 0x450d6, 0xe0000}};
  // -1600611291834540647440072
  s21_decimal dec_2 = {{0xdc26dec8, 0x4fdef16f, 0x152f1, 0x80000000}};
  // -1600611291834488472888439.4404
  s21_decimal dec_check = {{0x563479a4, 0xf4b54701, 0x33b7f23f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_49) {
  // -5629981
  s21_decimal dec_1 = {{0x55e81d, 0x0, 0x0, 0x80000000}};
  // -0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80010000}};
  // -5629981.4
  s21_decimal dec_check = {{0x35b1126, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_50) {
  // 23894040.9889851
  s21_decimal dec_1 = {{0xa641043b, 0xd950, 0x0, 0x70000}};
  // 2.2865
  s21_decimal dec_2 = {{0x5951, 0x0, 0x0, 0x40000}};
  // 23894043.2754851
  s21_decimal dec_check = {{0xa79de8a3, 0xd950, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_51) {
  // -2237497556827816995
  s21_decimal dec_1 = {{0x5486c423, 0x1f0d302c, 0x0, 0x80000000}};
  // -93792146485.6864
  s21_decimal dec_2 = {{0xdbbd7120, 0x35508, 0x0, 0x80040000}};
  // -2237497650619963480.6864
  s21_decimal dec_check = {{0xac0b0850, 0xf32d18ae, 0x4bc, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_52) {
  // 125290271078477
  s21_decimal dec_1 = {{0x6a19f84d, 0x71f3, 0x0, 0x0}};
  // 979076019954212
  s21_decimal dec_2 = {{0xe660a224, 0x37a76, 0x0, 0x0}};
  // 1104366291032689
  s21_decimal dec_check = {{0x507a9a71, 0x3ec6a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_53) {
  // 67522725907114936
  s21_decimal dec_1 = {{0xbbf5abb8, 0xefe38f, 0x0, 0x0}};
  // 9.78401919746
  s21_decimal dec_2 = {{0xcd4c8302, 0xe3, 0x0, 0xb0000}};
  // 67522725907114945.78401919746
  s21_decimal dec_check = {{0x57bb4302, 0x9a6a6c4b, 0x15d15956, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_54) {
  // -11212815017332903166087517.96
  s21_decimal dec_1 = {{0x5c06c8b4, 0x1e1d3fe, 0x39f8098, 0x80020000}};
  // -94.271
  s21_decimal dec_2 = {{0x1703f, 0x0, 0x0, 0x80030000}};
  // -11212815017332903166087612.231
  s21_decimal dec_check = {{0x98454747, 0x12d247ef, 0x243b05f0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_55) {
  // 808047409821134
  s21_decimal dec_1 = {{0x32d2f5ce, 0x2deea, 0x0, 0x0}};
  // 242665
  s21_decimal dec_2 = {{0x3b3e9, 0x0, 0x0, 0x0}};
  // 808047410063799
  s21_decimal dec_check = {{0x32d6a9b7, 0x2deea, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_56) {
  // -14544793
  s21_decimal dec_1 = {{0xddef99, 0x0, 0x0, 0x80000000}};
  // 0.17819892599151234
  s21_decimal dec_2 = {{0x104eda82, 0x3f4f19, 0x0, 0x110000}};
  // -14544792.82180107400848766
  s21_decimal dec_check = {{0xad2b257e, 0x7ad9554c, 0x133ff, 0x80110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_57) {
  // -50456947816
  s21_decimal dec_1 = {{0xbf77ec68, 0xb, 0x0, 0x80000000}};
  // 343545915269785447145
  s21_decimal dec_2 = {{0xec01eae9, 0x9fa845c0, 0x12, 0x0}};
  // 343545915219328499329
  s21_decimal dec_check = {{0x2c89fe81, 0x9fa845b5, 0x12, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_58) {
  // 682845397041060
  s21_decimal dec_1 = {{0x5553bfa4, 0x26d0b, 0x0, 0x0}};
  // -9.598757980401175053392621
  s21_decimal dec_2 = {{0x4de2daed, 0xb678777b, 0x7f09d, 0x80180000}};
  // 682845397041050.40124201959882
  s21_decimal dec_check = {{0x41881ca, 0xb7d9e2e4, 0xdca3a5ba, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_59) {
  // -243357177960.1558
  s21_decimal dec_1 = {{0x15756496, 0x8a552, 0x0, 0x80040000}};
  // 442.9077230627418
  s21_decimal dec_2 = {{0xe703aa5a, 0xfbc38, 0x0, 0xd0000}};
  // -243357177517.2480769372582
  s21_decimal dec_check = {{0xce96b1a6, 0x30b5ff82, 0x20354, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_60) {
  // 9185991723.3454
  s21_decimal dec_1 = {{0xcdbc5d2e, 0x538b, 0x0, 0x40000}};
  // -7676398209449651465184
  s21_decimal dec_2 = {{0x931debe0, 0x236cec31, 0x1a0, 0x80000000}};
  // -7676398209440465473460.6546
  s21_decimal dec_check = {{0xf31180d2, 0xcec9fcf6, 0x3f7f67, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_61) {
  // 3916463
  s21_decimal dec_1 = {{0x3bc2af, 0x0, 0x0, 0x0}};
  // -9355.601533
  s21_decimal dec_2 = {{0x2da3267d, 0x2, 0x0, 0x80060000}};
  // 3907107.398467
  s21_decimal dec_check = {{0xb1bfa343, 0x38d, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_62) {
  // -668097204208622706826226570
  s21_decimal dec_1 = {{0xf6c52b8a, 0x3005871, 0x228a316, 0x80000000}};
  // 73459092.6622133914
  s21_decimal dec_2 = {{0x44898e9a, 0xa31ca8e, 0x0, 0xa0000}};
  // -668097204208622706752767477.34
  s21_decimal dec_check = {{0xaf2b53d6, 0x2c228c82, 0xd7dfb499, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_63) {
  // -84986959090053
  s21_decimal dec_1 = {{0x9181d185, 0x4d4b, 0x0, 0x80000000}};
  // 9.11
  s21_decimal dec_2 = {{0x38f, 0x0, 0x0, 0x20000}};
  // -84986959090043.89
  s21_decimal dec_check = {{0xd6b5d465, 0x1e3184, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_64) {
  // 99507.4756058163024454062
  s21_decimal dec_1 = {{0x676361ae, 0x1c5146e3, 0xd2b7, 0x130000}};
  // -4669490159
  s21_decimal dec_2 = {{0x1652c3ef, 0x1, 0x0, 0x80000000}};
  // -4669390651.5243941836975545938
  s21_decimal dec_check = {{0x10349e52, 0x487afbb5, 0x96e04b50, 0x80130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_65) {
  // 816
  s21_decimal dec_1 = {{0x330, 0x0, 0x0, 0x0}};
  // 182.0865976194
  s21_decimal dec_2 = {{0xf411d782, 0x1a7, 0x0, 0xa0000}};
  // 998.0865976194
  s21_decimal dec_check = {{0xd9f89782, 0x913, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_66) {
  // 9656921104.28
  s21_decimal dec_1 = {{0xd7bc365c, 0xe0, 0x0, 0x20000}};
  // 611.21882469895691
  s21_decimal dec_2 = {{0x3c9f0e0b, 0xd92607, 0x0, 0xe0000}};
  // 9656921715.49882469895691
  s21_decimal dec_check = {{0x3950ce0b, 0x470b6036, 0xcc7e, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_67) {
  // -84096599477317309315052524.4
  s21_decimal dec_1 = {{0x5a88873c, 0xed0cb8fd, 0x2b7a179, 0x80010000}};
  // 46246851543095919192
  s21_decimal dec_2 = {{0xbe754258, 0x81cdd273, 0x2, 0x0}};
  // -84096553230465766219133332.4
  s21_decimal dec_check = {{0xe9f3efcc, 0xdb028077, 0x2b7a160, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_68) {
  // 51380470009774.75816380
  s21_decimal dec_1 = {{0x6b92cbbc, 0x88b9dcd9, 0x116, 0x80000}};
  // -78543580913490190
  s21_decimal dec_2 = {{0x7fbc590e, 0x1170af8, 0x0, 0x80000000}};
  // -78492200443480415.24183620
  s21_decimal dec_check = {{0x9f188244, 0x123b7869, 0x67e23, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_69) {
  // 69888997.6428755924949238
  s21_decimal dec_1 = {{0x3e618f6, 0xe6cb3c29, 0x93fe, 0x100000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 69888997.6428755924949238
  s21_decimal dec_check = {{0x3e618f6, 0xe6cb3c29, 0x93fe, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_70) {
  // -9858445069017390830741
  s21_decimal dec_1 = {{0xa2e4d495, 0x6d68a5fd, 0x216, 0x80000000}};
  // 9695224042182733142123512719.8
  s21_decimal dec_2 = {{0x7b1239e, 0xa254cf04, 0x3945037c, 0x10000}};
  // 9695214183737664124732681978.8
  s21_decimal dec_check = {{0xaac0d5cc, 0x5c3e531b, 0x3944ee9c, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_71) {
  // 39030.7658759016465600805
  s21_decimal dec_1 = {{0xb5b09125, 0x9ede36b8, 0x52a6, 0x130000}};
  // 5457346566211356055176.24250
  s21_decimal dec_2 = {{0xd439a3ba, 0x3f5671f, 0x1c36bcf, 0x50000}};
  // 5457346566211356094207.0083759
  s21_decimal dec_check = {{0xc6aa30af, 0x8bdc48c9, 0xb0561cdd, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_72) {
  // -8.8124791936
  s21_decimal dec_1 = {{0x84a59c80, 0x14, 0x0, 0x800a0000}};
  // 802570465556
  s21_decimal dec_2 = {{0xdced7114, 0xba, 0x0, 0x0}};
  // 802570465547.1875208064
  s21_decimal dec_check = {{0x5fec3380, 0x1306b625, 0x1b3, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_73) {
  // 383731826329474009692.2821
  s21_decimal dec_1 = {{0x810cb4c5, 0x709beb0f, 0x32c95, 0x40000}};
  // 91770093473.0733108136991
  s21_decimal dec_2 = {{0x641d0c1f, 0xaad7ddaa, 0xc254, 0xd0000}};
  // 383731826421244103165.35541081
  s21_decimal dec_check = {{0x2706ad59, 0x49e95702, 0x7bfd8d7f, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_74) {
  // 6674701167785774
  s21_decimal dec_1 = {{0xf816772e, 0x17b69a, 0x0, 0x0}};
  // -84785061
  s21_decimal dec_2 = {{0x50db7a5, 0x0, 0x0, 0x80000000}};
  // 6674701083000713
  s21_decimal dec_check = {{0xf308bf89, 0x17b69a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_75) {
  // -3013813106076
  s21_decimal dec_1 = {{0xb542759c, 0x2bd, 0x0, 0x80000000}};
  // 6314.48
  s21_decimal dec_2 = {{0x9a298, 0x0, 0x0, 0x20000}};
  // -3013813099761.52
  s21_decimal dec_check = {{0xcdec4e58, 0x1121a, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_76) {
  // 54582237.93
  s21_decimal dec_1 = {{0x4555e2b1, 0x1, 0x0, 0x20000}};
  // -887310183861368206
  s21_decimal dec_2 = {{0x3aa4b58e, 0xc505be9, 0x0, 0x80000000}};
  // -887310183806785968.07
  s21_decimal dec_check = {{0xa30108c7, 0xcf63e719, 0x4, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_77) {
  // 72953.70119729908652
  s21_decimal dec_1 = {{0xab800bac, 0x653e5c78, 0x0, 0xe0000}};
  // -39405420487805319811.76537
  s21_decimal dec_2 = {{0x64e94ed9, 0x36669755, 0x34271, 0x80050000}};
  // -39405420487805246858.064172701
  s21_decimal dec_check = {{0xfe26169d, 0x777355b, 0x7f53665d, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_78) {
  // 96.19443662
  s21_decimal dec_1 = {{0x3d5d0fce, 0x2, 0x0, 0x80000}};
  // 3.139319265704
  s21_decimal dec_2 = {{0xee0279a8, 0x2da, 0x0, 0xc0000}};
  // 99.333755885704
  s21_decimal dec_check = {{0xf13bd888, 0x5a57, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_79) {
  // -8192234704113473865827
  s21_decimal dec_1 = {{0x4eeec863, 0x1a184b12, 0x1bc, 0x80000000}};
  // -423455454377239734233177
  s21_decimal dec_2 = {{0x8d7da859, 0x90f120f2, 0x59ab, 0x80000000}};
  // -431647689081353208099004
  s21_decimal dec_check = {{0xdc6c70bc, 0xab096c04, 0x5b67, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_80) {
  // -54350341764.4367175121377586
  s21_decimal dec_1 = {{0xb74c1932, 0x4ee3f6fc, 0x1c19353, 0x80100000}};
  // -9855.7511286
  s21_decimal dec_2 = {{0xf27c4676, 0x16, 0x0, 0x80070000}};
  // -54350351620.1878461121377586
  s21_decimal dec_check = {{0x5be13532, 0xa6a69552, 0x1c19358, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_81) {
  // 18150005442114510087517540
  s21_decimal dec_1 = {{0xfc83f564, 0xc43c80f5, 0xf0369, 0x0}};
  // -8065798062823761300166.50
  s21_decimal dec_2 = {{0x1ccf358a, 0xc766d2db, 0xaacc, 0x80020000}};
  // 18141939644051686326217373.50
  s21_decimal dec_check = {{0x86bca586, 0xe03b8d3b, 0x5dcaa83, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_83) {
  // -6395126535020645345916433
  s21_decimal dec_1 = {{0xe36ff611, 0x810ea0bd, 0x54a38, 0x80000000}};
  // 25748111353603407.079421
  s21_decimal dec_2 = {{0xfd59e7fd, 0xced368c2, 0x573, 0x60000}};
  // -6395126509272533992313025.9206
  s21_decimal dec_check = {{0xf6269706, 0x56224cf2, 0xcea33f23, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_84) {
  // -10669030
  s21_decimal dec_1 = {{0xa2cbe6, 0x0, 0x0, 0x80000000}};
  // -5040031548553.50
  s21_decimal dec_2 = {{0x6102c5b6, 0x1ca63, 0x0, 0x80020000}};
  // -5040042217583.50
  s21_decimal dec_check = {{0xa09a6b8e, 0x1ca63, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_85) {
  // -832793
  s21_decimal dec_1 = {{0xcb519, 0x0, 0x0, 0x80000000}};
  // -45046847132
  s21_decimal dec_2 = {{0x7d00569c, 0xa, 0x0, 0x80000000}};
  // -45047679925
  s21_decimal dec_check = {{0x7d0d0bb5, 0xa, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_86) {
  // 624537683795784597209540
  s21_decimal dec_1 = {{0x6e9781c4, 0x417425cd, 0x8440, 0x0}};
  // -910077.04803942
  s21_decimal dec_2 = {{0x61eaaa66, 0x52c5, 0x0, 0x80080000}};
  // 624537683795784596299462.95196
  s21_decimal dec_check = {{0xbde6539c, 0xda2e96ca, 0xc9cc8bdf, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_87) {
  // -570599107892022376
  s21_decimal dec_1 = {{0x8f0f0c68, 0x7eb2cdd, 0x0, 0x80000000}};
  // 1466697971754
  s21_decimal dec_2 = {{0x7e02f82a, 0x155, 0x0, 0x0}};
  // -570597641194050622
  s21_decimal dec_check = {{0x110c143e, 0x7eb2b88, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_88) {
  // -97060588334
  s21_decimal dec_1 = {{0x99430b2e, 0x16, 0x0, 0x80000000}};
  // -2201995866901751718
  s21_decimal dec_2 = {{0x38ea7a6, 0x1e8f0f93, 0x0, 0x80000000}};
  // -2201995963962340052
  s21_decimal dec_check = {{0x9cd1b2d4, 0x1e8f0fa9, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_89) {
  // -44925.7
  s21_decimal dec_1 = {{0x6dae9, 0x0, 0x0, 0x80010000}};
  // 30568780863866467
  s21_decimal dec_2 = {{0xec9b8663, 0x6c9a24, 0x0, 0x0}};
  // 30568780863821541.3
  s21_decimal dec_check = {{0x3e0c64f5, 0x43e0571, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_90) {
  // 55229992718.43066
  s21_decimal dec_1 = {{0x79b164fa, 0x139f23, 0x0, 0x50000}};
  // 187270450
  s21_decimal dec_2 = {{0xb298532, 0x0, 0x0, 0x0}};
  // 55417263168.43066
  s21_decimal dec_check = {{0xb48ed03a, 0x13b02b, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_91) {
  // 5345888389234613595723
  s21_decimal dec_1 = {{0x3e50ae4b, 0xcd1ace47, 0x121, 0x0}};
  // 1118104896689672667978
  s21_decimal dec_2 = {{0xccc5c34a, 0x9cd28f90, 0x3c, 0x0}};
  // 6463993285924286263701
  s21_decimal dec_check = {{0xb167195, 0x69ed5dd8, 0x15e, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_92) {
  // -13.370371563035
  s21_decimal dec_1 = {{0x83f5e1b, 0xc29, 0x0, 0x800c0000}};
  // -7898896209085275095365
  s21_decimal dec_2 = {{0x6f74c145, 0x33349c04, 0x1ac, 0x80000000}};
  // -7898896209085275095378.3703716
  s21_decimal dec_check = {{0xec8f38a4, 0x105ac8d8, 0xff3a2357, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_93) {
  // 5944839.215159100
  s21_decimal dec_1 = {{0xbdaa973c, 0x151ecc, 0x0, 0x90000}};
  // 2077487295873926
  s21_decimal dec_2 = {{0xb44bc386, 0x76176, 0x0, 0x0}};
  // 2077487301818765.215159100
  s21_decimal dec_check = {{0x68e533c, 0xcff2b4b4, 0x1b7ec, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_94) {
  // -1933296001.46
  s21_decimal dec_1 = {{0x3579692, 0x2d, 0x0, 0x80020000}};
  // 508
  s21_decimal dec_2 = {{0x1fc, 0x0, 0x0, 0x0}};
  // -1933295493.46
  s21_decimal dec_check = {{0x356d022, 0x2d, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_95) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 71880221
  s21_decimal dec_2 = {{0x448ce1d, 0x0, 0x0, 0x0}};
  // 71880213
  s21_decimal dec_check = {{0x448ce15, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_96) {
  // 3006206.364377515948664633260
  s21_decimal dec_1 = {{0xf62337ac, 0x8f551fb4, 0x9b6acf5, 0x150000}};
  // 77258614433964.517423040
  s21_decimal dec_2 = {{0x19e6f7c0, 0x32a84e02, 0x105c, 0x90000}};
  // 77258617440170.881800555948665
  s21_decimal dec_check = {{0xea376a79, 0x97ce0892, 0xf9a2d49b, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_98) {
  // -1.235967530738641965277
  s21_decimal dec_1 = {{0x297290dd, 0x7ec0c5, 0x43, 0x80150000}};
  // 891
  s21_decimal dec_2 = {{0x37b, 0x0, 0x0, 0x0}};
  // 889.764032469261358034723
  s21_decimal dec_check = {{0xad6d6f23, 0x34710ee8, 0xbc6a, 0x150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_99) {
  // 362349640012699
  s21_decimal dec_1 = {{0x1993d39b, 0x1498e, 0x0, 0x0}};
  // 564304228515901742043.200
  s21_decimal dec_2 = {{0xbc1cd040, 0xfe57a745, 0x777e, 0x30000}};
  // 564304590865541754742.200
  s21_decimal dec_check = {{0xa58f65b8, 0x35efa59, 0x777f, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_100) {
  // -2.15362989
  s21_decimal dec_1 = {{0xcd62dad, 0x0, 0x0, 0x80080000}};
  // -996364272.965
  s21_decimal dec_2 = {{0xfbf04545, 0xe7, 0x0, 0x80030000}};
  // -996364275.11862989
  s21_decimal dec_check = {{0x8c8896cd, 0x161facd, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_101) {
  // 11728593
  s21_decimal dec_1 = {{0xb2f6d1, 0x0, 0x0, 0x0}};
  // 8479897070
  s21_decimal dec_2 = {{0xf970f5ee, 0x1, 0x0, 0x0}};
  // 8491625663
  s21_decimal dec_check = {{0xfa23ecbf, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_102) {
  // 54281324.2208
  s21_decimal dec_1 = {{0x6230c360, 0x7e, 0x0, 0x40000}};
  // -6542450405330341608803768
  s21_decimal dec_2 = {{0xaecfcdb8, 0xf277e417, 0x5696a, 0x80000000}};
  // -6542450405330341554522443.7792
  s21_decimal dec_check = {{0x33232020, 0x6b3ddc9e, 0xd365e19f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_103) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // 3735.33
  s21_decimal dec_2 = {{0x5b31d, 0x0, 0x0, 0x20000}};
  // 3738.33
  s21_decimal dec_check = {{0x5b449, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_104) {
  // -70018999152173895
  s21_decimal dec_1 = {{0xa3fe6347, 0xf8c1e8, 0x0, 0x80000000}};
  // -5842289940410037205
  s21_decimal dec_2 = {{0x3cfa73d5, 0x5113fbbf, 0x0, 0x80000000}};
  // -5912308939562211100
  s21_decimal dec_check = {{0xe0f8d71c, 0x520cbda7, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_105) {
  // -99603274
  s21_decimal dec_1 = {{0x5efd34a, 0x0, 0x0, 0x80000000}};
  // -4748547305925078741.64
  s21_decimal dec_2 = {{0xf03f4b74, 0xbdeee595, 0x19, 0x80020000}};
  // -4748547306024682015.64
  s21_decimal dec_check = {{0x41edd45c, 0xbdeee598, 0x19, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_106) {
  // -6170659.1246501
  s21_decimal dec_1 = {{0x2f7398a5, 0x381f, 0x0, 0x80070000}};
  // 898.8
  s21_decimal dec_2 = {{0x231c, 0x0, 0x0, 0x10000}};
  // -6169760.3246501
  s21_decimal dec_check = {{0x17b999a5, 0x381d, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_107) {
  // 500
  s21_decimal dec_1 = {{0x1f4, 0x0, 0x0, 0x0}};
  // -3196579.8065423538
  s21_decimal dec_2 = {{0x56a6c4b2, 0x7190b9, 0x0, 0x800a0000}};
  // -3196079.8065423538
  s21_decimal dec_check = {{0x2f6d74b2, 0x718c2d, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_109) {
  // 358.2708012
  s21_decimal dec_1 = {{0xd58bc92c, 0x0, 0x0, 0x70000}};
  // -0.967
  s21_decimal dec_2 = {{0x3c7, 0x0, 0x0, 0x80030000}};
  // 357.3038012
  s21_decimal dec_check = {{0xd4f83bbc, 0x0, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_110) {
  // 8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // -67975.66
  s21_decimal dec_2 = {{0x67b8fe, 0x0, 0x0, 0x80020000}};
  // -67967.66
  s21_decimal dec_check = {{0x67b5de, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_111) {
  // 636385616317984611
  s21_decimal dec_1 = {{0xa8cd2f63, 0x8d4e558, 0x0, 0x0}};
  // -1119779256290025147027815888
  s21_decimal dec_2 = {{0x3c65fdd0, 0x1e629fcc, 0x39e427b, 0x80000000}};
  // -1119779255653639530709831277
  s21_decimal dec_check = {{0x9398ce6d, 0x158dba73, 0x39e427b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_112) {
  // -59213
  s21_decimal dec_1 = {{0xe74d, 0x0, 0x0, 0x80000000}};
  // -17797661582899226964992.88
  s21_decimal dec_2 = {{0x84f15058, 0x51179f71, 0x178e1, 0x80020000}};
  // -17797661582899227024205.88
  s21_decimal dec_check = {{0x854baa6c, 0x51179f71, 0x178e1, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_113) {
  // 96609343861044932593
  s21_decimal dec_1 = {{0x2525eff1, 0x3cb95662, 0x5, 0x0}};
  // 252266389422345832573
  s21_decimal dec_2 = {{0x7148487d, 0xace6409d, 0xd, 0x0}};
  // 348875733283390765166
  s21_decimal dec_check = {{0x966e386e, 0xe99f96ff, 0x12, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_114) {
  // -80.408234373
  s21_decimal dec_1 = {{0xb8b44985, 0x12, 0x0, 0x80090000}};
  // -842591.4865
  s21_decimal dec_2 = {{0xf63941f1, 0x1, 0x0, 0x80040000}};
  // -842671.894734373
  s21_decimal dec_check = {{0xd6f2a625, 0x2fe67, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_115) {
  // 54.414
  s21_decimal dec_1 = {{0xd48e, 0x0, 0x0, 0x30000}};
  // -103141.276
  s21_decimal dec_2 = {{0x625cf9c, 0x0, 0x0, 0x80030000}};
  // -103086.862
  s21_decimal dec_check = {{0x624fb0e, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_116) {
  // 80522385474
  s21_decimal dec_1 = {{0xbf821842, 0x12, 0x0, 0x0}};
  // -3816598873852876391572568901
  s21_decimal dec_2 = {{0xfac3fb45, 0x86dfb392, 0xc55043f, 0x80000000}};
  // -3816598873852876311050183427
  s21_decimal dec_check = {{0x3b41e303, 0x86dfb380, 0xc55043f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_117) {
  // -8.2
  s21_decimal dec_1 = {{0x52, 0x0, 0x0, 0x80010000}};
  // -8715.27
  s21_decimal dec_2 = {{0xd4c67, 0x0, 0x0, 0x80020000}};
  // -8723.47
  s21_decimal dec_check = {{0xd4f9b, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_118) {
  // -55237768576511.832411
  s21_decimal dec_1 = {{0xac38f15b, 0xfe93f9db, 0x2, 0x80060000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // -55237768576509.832411
  s21_decimal dec_check = {{0xac1a6cdb, 0xfe93f9db, 0x2, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_119) {
  // -329.08151
  s21_decimal dec_1 = {{0x1f62377, 0x0, 0x0, 0x80050000}};
  // -1470403752386
  s21_decimal dec_2 = {{0x5ae4b1c2, 0x156, 0x0, 0x80000000}};
  // -1470403752715.08151
  s21_decimal dec_check = {{0x37b2c8b7, 0x20a6471, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_120) {
  // 280036.683792
  s21_decimal dec_1 = {{0x337cb010, 0x41, 0x0, 0x60000}};
  // 78129
  s21_decimal dec_2 = {{0x13131, 0x0, 0x0, 0x0}};
  // 358165.683792
  s21_decimal dec_check = {{0x64569e50, 0x53, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_121) {
  // 76.78503145610944471407929
  s21_decimal dec_1 = {{0xd4dc9d39, 0x7d561fea, 0x659fc, 0x170000}};
  // -6248
  s21_decimal dec_2 = {{0x1868, 0x0, 0x0, 0x80000000}};
  // -6171.21496854389055528592071
  s21_decimal dec_check = {{0x4f2362c7, 0x60fc6da5, 0x1fe788f, 0x80170000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_122) {
  // -0.4059675656311251738357004
  s21_decimal dec_1 = {{0x5d80ed0c, 0x7553ab9e, 0x35bab, 0x80190000}};
  // -648
  s21_decimal dec_2 = {{0x288, 0x0, 0x0, 0x80000000}};
  // -648.4059675656311251738357004
  s21_decimal dec_check = {{0xad80ed0c, 0x57f6ea99, 0x14f37d0b, 0x80190000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_123) {
  // -6673191.188122
  s21_decimal dec_1 = {{0xb930b69a, 0x611, 0x0, 0x80060000}};
  // -554647141257587080
  s21_decimal dec_2 = {{0xe6582988, 0x7b280a2, 0x0, 0x80000000}};
  // -554647141264260271.188122
  s21_decimal dec_check = {{0x78e8289a, 0x7b55ad58, 0x7573, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_124) {
  // 1304.4886864
  s21_decimal dec_1 = {{0x9892d50, 0x3, 0x0, 0x70000}};
  // 7926458.7666161
  s21_decimal dec_2 = {{0x399752f1, 0x4817, 0x0, 0x70000}};
  // 7927763.2553025
  s21_decimal dec_check = {{0x43208041, 0x481a, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_126) {
  // -4747889298829179153593783172
  s21_decimal dec_1 = {{0x6825d384, 0xa024f1a7, 0xf575caa, 0x80000000}};
  // -150.052
  s21_decimal dec_2 = {{0x24a24, 0x0, 0x0, 0x80030000}};
  // -4747889298829179153593783322.1
  s21_decimal dec_check = {{0x117a4905, 0x4171708a, 0x99699eaa, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_127) {
  // 370
  s21_decimal dec_1 = {{0x172, 0x0, 0x0, 0x0}};
  // -540160406549403127255.0356192
  s21_decimal dec_2 = {{0xa73054e0, 0x22c10ab3, 0x11741a27, 0x80070000}};
  // -540160406549403126885.0356192
  s21_decimal dec_check = {{0xcaa6cfe0, 0x22c10ab2, 0x11741a27, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_128) {
  // 81329334958550
  s21_decimal dec_1 = {{0xf61eb9d6, 0x49f7, 0x0, 0x0}};
  // 43483417584420691033770570
  s21_decimal dec_2 = {{0x6538ca4a, 0xca652a66, 0x23f7f8, 0x0}};
  // 43483417584502020368729120
  s21_decimal dec_check = {{0x5b578420, 0xca65745e, 0x23f7f8, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_129) {
  // 79.6
  s21_decimal dec_1 = {{0x31c, 0x0, 0x0, 0x10000}};
  // 14019523503027478
  s21_decimal dec_2 = {{0xae517516, 0x31ceae, 0x0, 0x0}};
  // 14019523503027557.6
  s21_decimal dec_check = {{0xcf2e95f8, 0x1f212d2, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_130) {
  // -551147113088348645
  s21_decimal dec_1 = {{0x169cf1e5, 0x7a61161, 0x0, 0x80000000}};
  // -1911259473.25017786592712097
  s21_decimal dec_2 = {{0x7d96d5a1, 0x5d8b4b71, 0x9e187e, 0x80110000}};
  // -551147114999608118.25017786593
  s21_decimal dec_check = {{0xc67a10e1, 0x355e0ce7, 0xb215d221, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_132) {
  // -886.40599492
  s21_decimal dec_1 = {{0xa36435c4, 0x14, 0x0, 0x80080000}};
  // -2718861908147.53
  s21_decimal dec_2 = {{0x6fd2a621, 0xf747, 0x0, 0x80020000}};
  // -2718861909033.93599492
  s21_decimal dec_check = {{0xa2d14004, 0xbd2dca1c, 0xe, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_133) {
  // -36459502
  s21_decimal dec_1 = {{0x22c53ee, 0x0, 0x0, 0x80000000}};
  // -6488.05552286207088853844
  s21_decimal dec_2 = {{0xf6550354, 0xd1c87d29, 0x8963, 0x80140000}};
  // -36465990.05552286207088853844
  s21_decimal dec_check = {{0x3f350354, 0x333de93a, 0xbc86560, 0x80140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_134) {
  // 10288952.574
  s21_decimal dec_1 = {{0x6544f4fe, 0x2, 0x0, 0x30000}};
  // -742857489736347
  s21_decimal dec_2 = {{0xfccb629b, 0x2a39f, 0x0, 0x80000000}};
  // -742857479447394.426
  s21_decimal dec_check = {{0x1534387a, 0xa4f28f1, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_135) {
  // 328104.517926623531705632
  s21_decimal dec_1 = {{0x5cf32520, 0x94e0ea06, 0x457a, 0x120000}};
  // 13427256317007345
  s21_decimal dec_2 = {{0xbb1555f1, 0x2fb404, 0x0, 0x0}};
  // 13427256317335449.517926623532
  s21_decimal dec_check = {{0x65eba92c, 0x7d1e1757, 0x2b62c41f, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_136) {
  // 46744625893139568635308242
  s21_decimal dec_1 = {{0x3d7e68d2, 0x3f4cf812, 0x26aa8f, 0x0}};
  // -3788.75606180604823199
  s21_decimal dec_2 = {{0xc7be469f, 0x89f48c73, 0x14, 0x80110000}};
  // 46744625893139568635304453.244
  s21_decimal dec_check = {{0x358fa47c, 0x44a90740, 0x970a3f8f, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_137) {
  // -754137520768052.599370
  s21_decimal dec_1 = {{0xf58b9a4a, 0xe1c2af8b, 0x28, 0x80060000}};
  // 56277231603
  s21_decimal dec_2 = {{0x1a6267f3, 0xd, 0x0, 0x0}};
  // -754081243536449.599370
  s21_decimal dec_check = {{0xe6e7f78a, 0xe0fabfb3, 0x28, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_138) {
  // -9942600284780081.0036512622353
  s21_decimal dec_1 = {{0x72030711, 0x74ef7f6a, 0x4143430e, 0x800d0000}};
  // 443888131.718888863094532986
  s21_decimal dec_2 = {{0x33e7eb7a, 0xd666e51d, 0x16f2cf7, 0x120000}};
  // -9942599840891949.2847623991408
  s21_decimal dec_check = {{0x3843f070, 0xd3151fa2, 0x4143421d, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_139) {
  // -83947909701458724309.4
  s21_decimal dec_1 = {{0xe0283a56, 0x821cdefb, 0x2d, 0x80010000}};
  // -8298659873.68
  s21_decimal dec_2 = {{0x37de0d28, 0xc1, 0x0, 0x80020000}};
  // -83947909709757384183.08
  s21_decimal dec_check = {{0xf9705484, 0x1520b697, 0x1c7, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_140) {
  // 9948709698165
  s21_decimal dec_1 = {{0x5d4eba75, 0x90c, 0x0, 0x0}};
  // 34697330977212088
  s21_decimal dec_2 = {{0xe78d06b8, 0x7b4509, 0x0, 0x0}};
  // 34707279686910253
  s21_decimal dec_check = {{0x44dbc12d, 0x7b4e16, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_141) {
  // -3449067059864779741528
  s21_decimal dec_1 = {{0xad25d958, 0xf96bb901, 0xba, 0x80000000}};
  // -77
  s21_decimal dec_2 = {{0x4d, 0x0, 0x0, 0x80000000}};
  // -3449067059864779741605
  s21_decimal dec_check = {{0xad25d9a5, 0xf96bb901, 0xba, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_142) {
  // -31579515268
  s21_decimal dec_1 = {{0x5a492984, 0x7, 0x0, 0x80000000}};
  // 35240479632
  s21_decimal dec_2 = {{0x347f0b90, 0x8, 0x0, 0x0}};
  // 3660964364
  s21_decimal dec_check = {{0xda35e20c, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_143) {
  // -1760216
  s21_decimal dec_1 = {{0x1adbd8, 0x0, 0x0, 0x80000000}};
  // 31.247676898850
  s21_decimal dec_2 = {{0x6aae7e22, 0x1c6b, 0x0, 0xc0000}};
  // -1760184.752323101150
  s21_decimal dec_check = {{0xd54701de, 0x186d6eb4, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_144) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -5.744
  s21_decimal dec_2 = {{0x1670, 0x0, 0x0, 0x80030000}};
  // -4.744
  s21_decimal dec_check = {{0x1288, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_145) {
  // -135324
  s21_decimal dec_1 = {{0x2109c, 0x0, 0x0, 0x80000000}};
  // -239411767230916063520
  s21_decimal dec_2 = {{0xaf41f120, 0xfa8175d6, 0xc, 0x80000000}};
  // -239411767230916198844
  s21_decimal dec_check = {{0xaf4401bc, 0xfa8175d6, 0xc, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_146) {
  // 20455365
  s21_decimal dec_1 = {{0x1381fc5, 0x0, 0x0, 0x0}};
  // 14.1429
  s21_decimal dec_2 = {{0x22875, 0x0, 0x0, 0x40000}};
  // 20455379.1429
  s21_decimal dec_check = {{0xa05b27c5, 0x2f, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_147) {
  // -1022952318.925478142585675637
  s21_decimal dec_1 = {{0x2f6d1f75, 0x538f3d1e, 0x34e2a94, 0x80120000}};
  // -617644777418811875669855813
  s21_decimal dec_2 = {{0xb7084e45, 0x799f80f2, 0x1fee75e, 0x80000000}};
  // -617644777418811876692808131.93
  s21_decimal dec_check = {{0x5083f089, 0x824e5ee7, 0xc79260e7, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_148) {
  // -4677733825
  s21_decimal dec_1 = {{0x16d08dc1, 0x1, 0x0, 0x80000000}};
  // 0.7048862231201763745558
  s21_decimal dec_2 = {{0x2882df16, 0x1e9d44ce, 0x17e, 0x160000}};
  // -4677733824.2951137768798236254
  s21_decimal dec_check = {{0x6e752e5e, 0x4e0a4c06, 0x97254eab, 0x80130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_149) {
  // -8.341046907491354074144054
  s21_decimal dec_1 = {{0xbb6bdd36, 0xf13c2da, 0x6e649, 0x80180000}};
  // -3037545907257368561523
  s21_decimal dec_2 = {{0xe916c773, 0xaa6ae50a, 0xa4, 0x80000000}};
  // -3037545907257368561531.3410469
  s21_decimal dec_check = {{0x5581d9a5, 0xd6214f8e, 0x6225fda7, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_150) {
  // -91928934
  s21_decimal dec_1 = {{0x57ab966, 0x0, 0x0, 0x80000000}};
  // -326.70060972556938
  s21_decimal dec_2 = {{0x530f428a, 0x74113f, 0x0, 0x800e0000}};
  // -91929260.70060972556938
  s21_decimal dec_check = {{0xbc04c28a, 0x597a3282, 0x1f2, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_151) {
  // -850723221724173944807312
  s21_decimal dec_1 = {{0x10c4df90, 0xcc5ab155, 0xb425, 0x80000000}};
  // -39008683362734079211760
  s21_decimal dec_2 = {{0x5f07f8f0, 0xaa3af98b, 0x842, 0x80000000}};
  // -889731905086908024019072
  s21_decimal dec_check = {{0x6fccd880, 0x7695aae0, 0xbc68, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_152) {
  // -895174.5730034720
  s21_decimal dec_1 = {{0xb85bbc20, 0x1fcd90, 0x0, 0x800a0000}};
  // 3026048067363180104366.9401144
  s21_decimal dec_2 = {{0xd686be38, 0x5721e57a, 0x61c6e208, 0x70000}};
  // 3026048067363179209192.3671109
  s21_decimal dec_check = {{0x98e6e845, 0x5721dd56, 0x61c6e208, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_153) {
  // 615.3
  s21_decimal dec_1 = {{0x1809, 0x0, 0x0, 0x10000}};
  // 67935.790487
  s21_decimal dec_2 = {{0xd149e597, 0xf, 0x0, 0x60000}};
  // 68551.090487
  s21_decimal dec_check = {{0xf5f6a137, 0xf, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_154) {
  // -71985402242970979069
  s21_decimal dec_1 = {{0xe9e48afd, 0xe6ff85f1, 0x3, 0x80000000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // -71985402242970979069
  s21_decimal dec_check = {{0xe9e48afd, 0xe6ff85f1, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_155) {
  // -256354327360.66990
  s21_decimal dec_1 = {{0x4de58dae, 0x5b134a, 0x0, 0x80050000}};
  // -325946416945
  s21_decimal dec_2 = {{0xe3eb9f31, 0x4b, 0x0, 0x80000000}};
  // -582300744305.66990
  s21_decimal dec_check = {{0xb5adb24e, 0xcedff1, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_156) {
  // -30
  s21_decimal dec_1 = {{0x1e, 0x0, 0x0, 0x80000000}};
  // -77228307585725072
  s21_decimal dec_2 = {{0x90407290, 0x1125ebc, 0x0, 0x80000000}};
  // -77228307585725102
  s21_decimal dec_check = {{0x904072ae, 0x1125ebc, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_157) {
  // -589262800614078.8658
  s21_decimal dec_1 = {{0x7b8a3fb2, 0x51c6d1f3, 0x0, 0x80040000}};
  // -532473556751461211700011
  s21_decimal dec_2 = {{0xfdf7fb2b, 0x7308aba3, 0x70c1, 0x80000000}};
  // -532473557340724012314089.8658
  s21_decimal dec_check = {{0x224d7f62, 0xd47787e4, 0x1134849d, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_158) {
  // 881218466.74984818826356446
  s21_decimal dec_1 = {{0x910526de, 0xe1636106, 0x48e486, 0x110000}};
  // 321215299304785
  s21_decimal dec_2 = {{0xc3cfbd51, 0x12424, 0x0, 0x0}};
  // 321216180523251.74984818826356
  s21_decimal dec_check = {{0x8b881c74, 0xcdd4c104, 0x67ca6133, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_159) {
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // -96531.2285639269520919
  s21_decimal dec_2 = {{0x61119617, 0x54662958, 0x34, 0x80100000}};
  // -96525.2285639269520919
  s21_decimal dec_check = {{0xc28b9617, 0x5390ffa9, 0x34, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_160) {
  // 7.3214
  s21_decimal dec_1 = {{0x11dfe, 0x0, 0x0, 0x40000}};
  // 150887.477
  s21_decimal dec_2 = {{0x8fe5c35, 0x0, 0x0, 0x30000}};
  // 150894.7984
  s21_decimal dec_check = {{0x59f0b810, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_161) {
  // 335
  s21_decimal dec_1 = {{0x14f, 0x0, 0x0, 0x0}};
  // -39799242.08871818125
  s21_decimal dec_2 = {{0x3ec8438d, 0x373b87fb, 0x0, 0x800b0000}};
  // -39798907.08871818125
  s21_decimal dec_check = {{0x6b2eab8d, 0x373b6983, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_162) {
  // 3569065657.2
  s21_decimal dec_1 = {{0x4f54333c, 0x8, 0x0, 0x10000}};
  // 17623
  s21_decimal dec_2 = {{0x44d7, 0x0, 0x0, 0x0}};
  // 3569083280.2
  s21_decimal dec_check = {{0x4f56e3a2, 0x8, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_163) {
  // -8729591789276614
  s21_decimal dec_1 = {{0x79a24dc6, 0x1f0384, 0x0, 0x80000000}};
  // -603
  s21_decimal dec_2 = {{0x25b, 0x0, 0x0, 0x80000000}};
  // -8729591789277217
  s21_decimal dec_check = {{0x79a25021, 0x1f0384, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_164) {
  // -140846975206558709995011
  s21_decimal dec_1 = {{0xae825603, 0x546f6f1b, 0x1dd3, 0x80000000}};
  // 0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
  // -140846975206558709995010.9
  s21_decimal dec_check = {{0xd1175c1d, 0x4c5a5714, 0x12a41, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_165) {
  // -73642769
  s21_decimal dec_1 = {{0x463b311, 0x0, 0x0, 0x80000000}};
  // 574278984905712957914508121
  s21_decimal dec_2 = {{0x1d166b59, 0x2702315d, 0x1db084e, 0x0}};
  // 574278984905712957840865352
  s21_decimal dec_check = {{0x18b2b848, 0x2702315d, 0x1db084e, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_166) {
  // -2393924084
  s21_decimal dec_1 = {{0x8eb061f4, 0x0, 0x0, 0x80000000}};
  // 2301764497570
  s21_decimal dec_2 = {{0xebdaf0a2, 0x217, 0x0, 0x0}};
  // 2299370573486
  s21_decimal dec_check = {{0x5d2a8eae, 0x217, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_167) {
  // 16571297
  s21_decimal dec_1 = {{0xfcdba1, 0x0, 0x0, 0x0}};
  // 30104519682680670203
  s21_decimal dec_2 = {{0x9befc7fb, 0xa1c8bd26, 0x1, 0x0}};
  // 30104519682697241500
  s21_decimal dec_check = {{0x9ceca39c, 0xa1c8bd26, 0x1, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_168) {
  // 7756
  s21_decimal dec_1 = {{0x1e4c, 0x0, 0x0, 0x0}};
  // -2742598.5
  s21_decimal dec_2 = {{0x1a27cc1, 0x0, 0x0, 0x80010000}};
  // -2734842.5
  s21_decimal dec_check = {{0x1a14dc9, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_169) {
  // 31928.02401
  s21_decimal dec_1 = {{0xbe4e4c61, 0x0, 0x0, 0x50000}};
  // 49338778593519780879
  s21_decimal dec_2 = {{0x664c40f, 0xacb68db9, 0x2, 0x0}};
  // 49338778593519812807.02401
  s21_decimal dec_check = {{0x3ff7afc1, 0xe007362, 0x414ca, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_170) {
  // 23459492881930955794428528
  s21_decimal dec_1 = {{0x6c9c3270, 0xa84b5bed, 0x1367bd, 0x0}};
  // -83623679145446436638
  s21_decimal dec_2 = {{0x23936f1e, 0x8882fd20, 0x4, 0x80000000}};
  // 23459409258251810347991890
  s21_decimal dec_check = {{0x4908c352, 0x1fc85ecd, 0x1367b9, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_171) {
  // -285723589948267
  s21_decimal dec_1 = {{0x3515336b, 0x103dd, 0x0, 0x80000000}};
  // 2.3274245695749650513
  s21_decimal dec_2 = {{0xe6527851, 0x42febb25, 0x1, 0x130000}};
  // -285723589948264.67257543042503
  s21_decimal dec_check = {{0xea6025c7, 0xc2e68579, 0x5c52805c, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_172) {
  // -4130523659923
  s21_decimal dec_1 = {{0xb6653e93, 0x3c1, 0x0, 0x80000000}};
  // -9.1558
  s21_decimal dec_2 = {{0x165a6, 0x0, 0x0, 0x80040000}};
  // -4130523659932.1558
  s21_decimal dec_check = {{0xd2ddb3d6, 0x92bee4, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_173) {
  // -18.099
  s21_decimal dec_1 = {{0x46b3, 0x0, 0x0, 0x80030000}};
  // 0.97
  s21_decimal dec_2 = {{0x61, 0x0, 0x0, 0x20000}};
  // -17.129
  s21_decimal dec_check = {{0x42e9, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_174) {
  // 19647456.8248183990870260808
  s21_decimal dec_1 = {{0x34e2bc48, 0xafc7beef, 0xa2851b, 0x130000}};
  // -37073060047089527.44
  s21_decimal dec_2 = {{0x4c598aa8, 0x3372ff2b, 0x0, 0x80020000}};
  // -37073060027442070.615181600913
  s21_decimal dec_check = {{0x2595a891, 0x1f3584c5, 0x77ca1dd3, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_175) {
  // 71023359.3242
  s21_decimal dec_1 = {{0x5d38959a, 0xa5, 0x0, 0x40000}};
  // 62714759674623000
  s21_decimal dec_2 = {{0xdc947418, 0xdecebd, 0x0, 0x0}};
  // 62714759745646359.3242
  s21_decimal dec_check = {{0xc42f7f1a, 0xff6bd91d, 0x21, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_176) {
  // -4863160.859453
  s21_decimal dec_1 = {{0x4af9bb3d, 0x46c, 0x0, 0x80060000}};
  // -2.076841
  s21_decimal dec_2 = {{0x1fb0a9, 0x0, 0x0, 0x80060000}};
  // -4863162.936294
  s21_decimal dec_check = {{0x4b196be6, 0x46c, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_177) {
  // 464792425865680
  s21_decimal dec_1 = {{0xeb7021d0, 0x1a6b9, 0x0, 0x0}};
  // -62432405216983513201
  s21_decimal dec_2 = {{0x878bf871, 0x626c75c3, 0x3, 0x80000000}};
  // -62431940424557647521
  s21_decimal dec_check = {{0x9c1bd6a1, 0x626acf09, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_178) {
  // -318951991316059.90021230539
  s21_decimal dec_1 = {{0x4ca36fcb, 0x35a2ec26, 0x1a6212, 0x800b0000}};
  // 6.76553503901807234
  s21_decimal dec_2 = {{0xc79cf282, 0x96399d3, 0x0, 0x110000}};
  // -318951991316053.13467726637193
  s21_decimal dec_check = {{0xfb272889, 0x84680e48, 0x670f1721, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_179) {
  // 759522084678
  s21_decimal dec_1 = {{0xd70b4746, 0xb0, 0x0, 0x0}};
  // -698456350495276369936271
  s21_decimal dec_2 = {{0xf5db7f8f, 0x6506731b, 0x93e7, 0x80000000}};
  // -698456350494516847851593
  s21_decimal dec_check = {{0x1ed03849, 0x6506726b, 0x93e7, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_180) {
  // -51291714882169910484304089
  s21_decimal dec_1 = {{0x11bc80d9, 0x6f6f0530, 0x2a6d71, 0x80000000}};
  // 32222703649337
  s21_decimal dec_2 = {{0x6ece0239, 0x1d4e, 0x0, 0x0}};
  // -51291714882137687780654752
  s21_decimal dec_check = {{0xa2ee7ea0, 0x6f6ee7e1, 0x2a6d71, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_181) {
  // -13479402134609283968
  s21_decimal dec_1 = {{0x12074b80, 0xbb1074d3, 0x0, 0x80000000}};
  // 9572187
  s21_decimal dec_2 = {{0x920f5b, 0x0, 0x0, 0x0}};
  // -13479402134599711781
  s21_decimal dec_check = {{0x11753c25, 0xbb1074d3, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_182) {
  // -32848991120154670597
  s21_decimal dec_1 = {{0xe2c7b605, 0xc7df0f61, 0x1, 0x80000000}};
  // -38.947
  s21_decimal dec_2 = {{0x9823, 0x0, 0x0, 0x80030000}};
  // -32848991120154670635.947
  s21_decimal dec_check = {{0xdc1f9bab, 0xbf54165d, 0x6f4, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_183) {
  // -7897116460037655414799337
  s21_decimal dec_1 = {{0xb93d7be9, 0x8a86a807, 0x68847, 0x80000000}};
  // 64
  s21_decimal dec_2 = {{0x40, 0x0, 0x0, 0x0}};
  // -7897116460037655414799273
  s21_decimal dec_check = {{0xb93d7ba9, 0x8a86a807, 0x68847, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_184) {
  // 7075316183613218714148285
  s21_decimal dec_1 = {{0x24d5ddbd, 0xa8ab5c7a, 0x5da41, 0x0}};
  // -680259700
  s21_decimal dec_2 = {{0x288bf074, 0x0, 0x0, 0x80000000}};
  // 7075316183613218033888585
  s21_decimal dec_check = {{0xfc49ed49, 0xa8ab5c79, 0x5da41, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_185) {
  // -0.51839381188722
  s21_decimal dec_1 = {{0xcbe6b072, 0x2f25, 0x0, 0x800e0000}};
  // 11183.94
  s21_decimal dec_2 = {{0x1110ba, 0x0, 0x0, 0x20000}};
  // 11183.42160618811278
  s21_decimal dec_check = {{0x1506ef8e, 0xf852645, 0x0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_186) {
  // -1617615550203341370364439
  s21_decimal dec_1 = {{0x6e791217, 0x1d5c3f70, 0x1568b, 0x80000000}};
  // -5891093631254.0556
  s21_decimal dec_2 = {{0x384b6d8c, 0xd14b2f, 0x0, 0x80040000}};
  // -1617615550209232463995693.0556
  s21_decimal dec_check = {{0x919e0ffc, 0xe43f630a, 0x34449a2a, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_187) {
  // -58804747211748134287
  s21_decimal dec_1 = {{0x36e3cd8f, 0x30146e07, 0x3, 0x80000000}};
  // 829614801749664701
  s21_decimal dec_2 = {{0x46b1e3bd, 0xb836244, 0x0, 0x0}};
  // -57975132409998469586
  s21_decimal dec_check = {{0xf031e9d2, 0x24910bc2, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_188) {
  // -9108184663091261651550
  s21_decimal dec_1 = {{0xd796ba5e, 0xc1743dd9, 0x1ed, 0x80000000}};
  // -32002
  s21_decimal dec_2 = {{0x7d02, 0x0, 0x0, 0x80000000}};
  // -9108184663091261683552
  s21_decimal dec_check = {{0xd7973760, 0xc1743dd9, 0x1ed, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_189) {
  // 78743130663222276895
  s21_decimal dec_1 = {{0xa388731f, 0x44c7cc23, 0x4, 0x0}};
  // 67324899.5608938732412799
  s21_decimal dec_2 = {{0x73d95f7f, 0xe6b3f046, 0x8e90, 0x100000}};
  // 78743130663289601794.560893873
  s21_decimal dec_check = {{0xc35a23b1, 0xac24214a, 0xfe6eca82, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_190) {
  // 32428125349
  s21_decimal dec_1 = {{0x8cddeca5, 0x7, 0x0, 0x0}};
  // -3552475980146203
  s21_decimal dec_2 = {{0x44dea61b, 0xc9ef5, 0x0, 0x80000000}};
  // -3552443552020854
  s21_decimal dec_check = {{0xb800b976, 0xc9eed, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_191) {
  // -19404793642
  s21_decimal dec_1 = {{0x849da72a, 0x4, 0x0, 0x80000000}};
  // -6947576036159129403365286.60
  s21_decimal dec_2 = {{0x62ff3d14, 0x28d8e907, 0x23eb0a5, 0x80020000}};
  // -6947576036159148808158928.60
  s21_decimal dec_check = {{0x3094897c, 0x28d8eacb, 0x23eb0a5, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_192) {
  // 683367238524908.370781831
  s21_decimal dec_1 = {{0xdec1e687, 0x6987f399, 0x90b5, 0x90000}};
  // 9115
  s21_decimal dec_2 = {{0x239b, 0x0, 0x0, 0x0}};
  // 683367238534023.370781831
  s21_decimal dec_check = {{0x1f183487, 0x6987fbe4, 0x90b5, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_193) {
  // 407011618612114224577
  s21_decimal dec_1 = {{0xfd5f5c1, 0x106bbeb0, 0x16, 0x0}};
  // -0.83295133177236631215
  s21_decimal dec_2 = {{0xe40b2eaf, 0x83f3c24e, 0x4, 0x80140000}};
  // 407011618612114224576.16704867
  s21_decimal dec_check = {{0xfebca563, 0xa167137b, 0x83833645, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_194) {
  // -1681
  s21_decimal dec_1 = {{0x691, 0x0, 0x0, 0x80000000}};
  // -30421131137430885
  s21_decimal dec_2 = {{0x8b1cb565, 0x6c13db, 0x0, 0x80000000}};
  // -30421131137432566
  s21_decimal dec_check = {{0x8b1cbbf6, 0x6c13db, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_195) {
  // 85051
  s21_decimal dec_1 = {{0x14c3b, 0x0, 0x0, 0x0}};
  // -9656404442305883.9195
  s21_decimal dec_2 = {{0xd776569b, 0x3c1866c8, 0x5, 0x80040000}};
  // -9656404442220832.9195
  s21_decimal dec_check = {{0xa4c495eb, 0x3c1866c8, 0x5, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_196) {
  // -189712048530
  s21_decimal dec_1 = {{0x2bb82192, 0x2c, 0x0, 0x80000000}};
  // 4036583780.2
  s21_decimal dec_2 = {{0x65fdcdea, 0x9, 0x0, 0x10000}};
  // -185675464749.8
  s21_decimal dec_check = {{0x4f3381ca, 0x1b0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_197) {
  // 694927
  s21_decimal dec_1 = {{0xa9a8f, 0x0, 0x0, 0x0}};
  // 27535
  s21_decimal dec_2 = {{0x6b8f, 0x0, 0x0, 0x0}};
  // 722462
  s21_decimal dec_check = {{0xb061e, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_198) {
  // -3107817490692434448872451.736
  s21_decimal dec_1 = {{0x50512e98, 0xc13e75d9, 0xa0ab9f3, 0x80030000}};
  // -6980948294412559072
  s21_decimal dec_2 = {{0xb3d462e0, 0x60e14f7c, 0x0, 0x80000000}};
  // -3107824471640728861431523.736
  s21_decimal dec_check = {{0xc5f36998, 0x315cf4f7, 0xa0abb6e, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_199) {
  // 4295770606810327.3978468771
  s21_decimal dec_1 = {{0x656f19a3, 0xe9860ab2, 0x2388a5, 0xa0000}};
  // 71134071.07470
  s21_decimal dec_2 = {{0x381a918e, 0x678, 0x0, 0x50000}};
  // 4295770677944398.4725468771
  s21_decimal dec_check = {{0xefc86663, 0xf3653b4d, 0x2388a5, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_200) {
  // 20408432371080784264616158690
  s21_decimal dec_1 = {{0x4fcf25e2, 0xaffda49a, 0x41f175a7, 0x0}};
  // -959966.722006551
  s21_decimal dec_2 = {{0xab761e17, 0x36915, 0x0, 0x80090000}};
  // 20408432371080784264615198723
  s21_decimal dec_check = {{0x4fc08003, 0xaffda49a, 0x41f175a7, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_201) {
  // 1554.442
  s21_decimal dec_1 = {{0x17b80a, 0x0, 0x0, 0x30000}};
  // -59272.69813775800943353
  s21_decimal dec_2 = {{0x925b42f9, 0x51648b9b, 0x141, 0x80110000}};
  // -57718.25613775800943353
  s21_decimal dec_check = {{0x4f94c2f9, 0xe42bcf49, 0x138, 0x80110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_202) {
  // -61109215
  s21_decimal dec_1 = {{0x3a473df, 0x0, 0x0, 0x80000000}};
  // -146421509371283
  s21_decimal dec_2 = {{0x6a0db593, 0x852b, 0x0, 0x80000000}};
  // -146421570480498
  s21_decimal dec_check = {{0x6db22972, 0x852b, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_203) {
  // 4937368
  s21_decimal dec_1 = {{0x4b5698, 0x0, 0x0, 0x0}};
  // -90309019039518136
  s21_decimal dec_2 = {{0x7dd4db8, 0x140d793, 0x0, 0x80000000}};
  // -90309019034580768
  s21_decimal dec_check = {{0x791f720, 0x140d793, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_204) {
  // -29868308945475086997715.629
  s21_decimal dec_1 = {{0x884afaad, 0x45b93a8c, 0x18b4dc, 0x80030000}};
  // -94401290234
  s21_decimal dec_2 = {{0xfac15ffa, 0x15, 0x0, 0x80000000}};
  // -29868308945569488287949.629
  s21_decimal dec_check = {{0xba9e33d, 0x45b99068, 0x18b4dc, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_205) {
  // 400562139
  s21_decimal dec_1 = {{0x17e017db, 0x0, 0x0, 0x0}};
  // -51470344387830
  s21_decimal dec_2 = {{0xdf97fcf6, 0x2ecf, 0x0, 0x80000000}};
  // -51469943825691
  s21_decimal dec_check = {{0xc7b7e51b, 0x2ecf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_206) {
  // 12521743403822279317
  s21_decimal dec_1 = {{0x616aea95, 0xadc62b48, 0x0, 0x0}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 12521743403822279322
  s21_decimal dec_check = {{0x616aea9a, 0xadc62b48, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_207) {
  // 0.485382274
  s21_decimal dec_1 = {{0x1cee5882, 0x0, 0x0, 0x90000}};
  // -3327186418927
  s21_decimal dec_2 = {{0xabc3bcef, 0x306, 0x0, 0x80000000}};
  // -3327186418926.514617726
  s21_decimal dec_check = {{0x12ec3d7e, 0x5dfcb3d3, 0xb4, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_208) {
  // -42002937.2054213606940
  s21_decimal dec_1 = {{0xe9c9be1c, 0xc5141878, 0x16, 0x800d0000}};
  // 261803500794332
  s21_decimal dec_2 = {{0xe0aa71dc, 0xee1b, 0x0, 0x0}};
  // 261803458791394.7945786393060
  s21_decimal dec_check = {{0x5957c1e4, 0x6496b729, 0x8759663, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_209) {
  // 0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x10000}};
  // 513
  s21_decimal dec_2 = {{0x201, 0x0, 0x0, 0x0}};
  // 513.6
  s21_decimal dec_check = {{0x1410, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_210) {
  // 77722708.205241826205
  s21_decimal dec_1 = {{0xf2c6fb9d, 0x369e8751, 0x4, 0xc0000}};
  // 695214896169.798
  s21_decimal dec_2 = {{0x54edc346, 0x2784b, 0x0, 0x30000}};
  // 695292618878.003241826205
  s21_decimal dec_check = {{0x28f8379d, 0xe36ddb5e, 0x933b, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_211) {
  // 96774.3258457
  s21_decimal dec_1 = {{0x51fe3f59, 0xe1, 0x0, 0x70000}};
  // 274274008500750.162
  s21_decimal dec_2 = {{0xefcf4752, 0x3ce6ac1, 0x0, 0x30000}};
  // 274274008597524.4878457
  s21_decimal dec_check = {{0xe2d03279, 0xaf2a3888, 0x94, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_212) {
  // 4.999417
  s21_decimal dec_1 = {{0x4c48f9, 0x0, 0x0, 0x60000}};
  // -89224853413450233
  s21_decimal dec_2 = {{0xcd851f9, 0x13cfd88, 0x0, 0x80000000}};
  // -89224853413450228.000583
  s21_decimal dec_check = {{0xc8816747, 0xe39535ff, 0x12e4, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_213) {
  // 1828.0
  s21_decimal dec_1 = {{0x4768, 0x0, 0x0, 0x10000}};
  // -480.7
  s21_decimal dec_2 = {{0x12c7, 0x0, 0x0, 0x80010000}};
  // 1347.3
  s21_decimal dec_check = {{0x34a1, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_214) {
  // -5.38
  s21_decimal dec_1 = {{0x21a, 0x0, 0x0, 0x80020000}};
  // 217310603367119
  s21_decimal dec_2 = {{0x9151d2cf, 0xc5a4, 0x0, 0x0}};
  // 217310603367113.62
  s21_decimal dec_check = {{0xc3f656c2, 0x4d3448, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_215) {
  // 741436181849967182
  s21_decimal dec_1 = {{0x72ca0a4e, 0xa4a1c47, 0x0, 0x0}};
  // -21154331631072
  s21_decimal dec_2 = {{0x606c1de0, 0x133d, 0x0, 0x80000000}};
  // 741415027518336110
  s21_decimal dec_check = {{0x125dec6e, 0xa4a090a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_216) {
  // -539
  s21_decimal dec_1 = {{0x21b, 0x0, 0x0, 0x80000000}};
  // 4798648269505
  s21_decimal dec_2 = {{0x45b9bac1, 0x45d, 0x0, 0x0}};
  // 4798648268966
  s21_decimal dec_check = {{0x45b9b8a6, 0x45d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_218) {
  // -491269
  s21_decimal dec_1 = {{0x77f05, 0x0, 0x0, 0x80000000}};
  // -63.68777477650000146578
  s21_decimal dec_2 = {{0x84907092, 0x408adcb1, 0x159, 0x80140000}};
  // -491332.68777477650000146578
  s21_decimal dec_check = {{0x63e07092, 0xd665ed29, 0x28a45f, 0x80140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_219) {
  // 972448259162
  s21_decimal dec_1 = {{0x6a6edc5a, 0xe2, 0x0, 0x0}};
  // 6.3
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x10000}};
  // 972448259168.3
  s21_decimal dec_check = {{0x28549bc3, 0x8d8, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_220) {
  // 353883604650696485949
  s21_decimal dec_1 = {{0x5f89ac3d, 0x2f1f1f79, 0x13, 0x0}};
  // -337661085817
  s21_decimal dec_2 = {{0x9e2b4879, 0x4e, 0x0, 0x80000000}};
  // 353883604313035400132
  s21_decimal dec_check = {{0xc15e63c4, 0x2f1f1f2a, 0x13, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_221) {
  // 241704892447997059
  s21_decimal dec_1 = {{0xaed63c83, 0x35ab551, 0x0, 0x0}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 241704892447997059
  s21_decimal dec_check = {{0xaed63c83, 0x35ab551, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_222) {
  // -4577.848285137
  s21_decimal dec_1 = {{0xdd0557d1, 0x429, 0x0, 0x80090000}};
  // 94211768529714641.80
  s21_decimal dec_2 = {{0xa77f25f4, 0x82bebe6e, 0x0, 0x20000}};
  // 94211768529710063.951714863
  s21_decimal dec_check = {{0xebaa9a2f, 0x34a77ccc, 0x4dee1e, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_223) {
  // -9743
  s21_decimal dec_1 = {{0x260f, 0x0, 0x0, 0x80000000}};
  // 7503745992628
  s21_decimal dec_2 = {{0x1a1d47b4, 0x6d3, 0x0, 0x0}};
  // 7503745982885
  s21_decimal dec_check = {{0x1a1d21a5, 0x6d3, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_224) {
  // 938.0
  s21_decimal dec_1 = {{0x24a4, 0x0, 0x0, 0x10000}};
  // 0.86426465429
  s21_decimal dec_2 = {{0x1f6b3495, 0x14, 0x0, 0xb0000}};
  // 938.86426465429
  s21_decimal dec_check = {{0xa3194495, 0x5563, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_225) {
  // -192877332776390216409917920
  s21_decimal dec_1 = {{0x5003a9e0, 0x29353cdb, 0x9f8b5d, 0x80000000}};
  // 0.270074310775242443
  s21_decimal dec_2 = {{0x9cb77ecb, 0x3bf7f27, 0x0, 0x120000}};
  // -192877332776390216409917919.73
  s21_decimal dec_check = {{0x416e5b65, 0x18cbc5ab, 0x3e527064, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_226) {
  // 1.39717371952732628701821
  s21_decimal dec_1 = {{0xd985d27d, 0x180a80a5, 0x1d96, 0x170000}};
  // 394
  s21_decimal dec_2 = {{0x18a, 0x0, 0x0, 0x0}};
  // 395.39717371952732628701821
  s21_decimal dec_check = {{0x3a85d27d, 0x5fab3e05, 0x20b4dc, 0x170000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_227) {
  // 97602658.82189796
  s21_decimal dec_1 = {{0xfcd23fe4, 0x22ace8, 0x0, 0x80000}};
  // 465.13842
  s21_decimal dec_2 = {{0x2c5beb2, 0x0, 0x0, 0x50000}};
  // 97603123.96031796
  s21_decimal dec_check = {{0xd1432734, 0x22acf3, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_228) {
  // -684
  s21_decimal dec_1 = {{0x2ac, 0x0, 0x0, 0x80000000}};
  // -21629276636.16260486395
  s21_decimal dec_2 = {{0x88cab4fb, 0x40a6b260, 0x75, 0x800b0000}};
  // -21629277320.16260486395
  s21_decimal dec_check = {{0x267e94fb, 0x40a6f096, 0x75, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_229) {
  // 66862809
  s21_decimal dec_1 = {{0x3fc3ed9, 0x0, 0x0, 0x0}};
  // -9744761306.049624996537
  s21_decimal dec_2 = {{0xdb80fab9, 0x43bac9e4, 0x210, 0x800c0000}};
  // -9677898497.049624996537
  s21_decimal dec_check = {{0xe1b66ab9, 0xa3d25f5c, 0x20c, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_230) {
  // -71113556575169734968088
  s21_decimal dec_1 = {{0xa45f0318, 0x12d93158, 0xf0f, 0x80000000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // -71113556575169734968088
  s21_decimal dec_check = {{0xa45f0318, 0x12d93158, 0xf0f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_231) {
  // -307344150254393
  s21_decimal dec_1 = {{0x22e65339, 0x11787, 0x0, 0x80000000}};
  // 0.2744
  s21_decimal dec_2 = {{0xab8, 0x0, 0x0, 0x40000}};
  // -307344150254392.7256
  s21_decimal dec_check = {{0x4512d7d8, 0x2aa70ec3, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_232) {
  // 2100136
  s21_decimal dec_1 = {{0x200ba8, 0x0, 0x0, 0x0}};
  // -442857285416899
  s21_decimal dec_2 = {{0xbf2ef7c3, 0x192c6, 0x0, 0x80000000}};
  // -442857283316763
  s21_decimal dec_check = {{0xbf0eec1b, 0x192c6, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_233) {
  // 7724762
  s21_decimal dec_1 = {{0x75deda, 0x0, 0x0, 0x0}};
  // -75
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x80000000}};
  // 7724687
  s21_decimal dec_check = {{0x75de8f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_234) {
  // 4901517.38
  s21_decimal dec_1 = {{0x1d371f3a, 0x0, 0x0, 0x20000}};
  // -279953178659038666.7799556
  s21_decimal dec_2 = {{0x50de4404, 0xec1874db, 0x250d2, 0x80070000}};
  // -279953178654137149.3999556
  s21_decimal dec_check = {{0x14d863c4, 0xec184847, 0x250d2, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_235) {
  // -29972923525936001981.7725
  s21_decimal dec_1 = {{0xe8b524fd, 0x5aba0ad6, 0x3f78, 0x80040000}};
  // 196525786945433
  s21_decimal dec_2 = {{0x39b85799, 0xb2bd, 0x0, 0x0}};
  // -29972727000149056548.7725
  s21_decimal dec_check = {{0x37d75c6d, 0x3f740b38, 0x3f78, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_236) {
  // -1.69
  s21_decimal dec_1 = {{0xa9, 0x0, 0x0, 0x80020000}};
  // 617677947357856829290
  s21_decimal dec_2 = {{0x217c8f6a, 0x7c00e486, 0x21, 0x0}};
  // 617677947357856829288.31
  s21_decimal dec_check = {{0x14a804bf, 0x70594465, 0xd14, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_237) {
  // -1322433014.816051044
  s21_decimal dec_1 = {{0x75c0f64, 0x125a39d2, 0x0, 0x80090000}};
  // 249849900
  s21_decimal dec_2 = {{0xee4682c, 0x0, 0x0, 0x0}};
  // -1072583114.816051044
  s21_decimal dec_check = {{0xfeb15764, 0xee294a8, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_238) {
  // -283858909180769908748.20377397
  s21_decimal dec_1 = {{0xaa757b35, 0x10d708f5, 0x5bb84236, 0x80080000}};
  // 65.7023466860
  s21_decimal dec_2 = {{0xf9a67d6c, 0x98, 0x0, 0xa0000}};
  // -283858909180769908682.50142728
  s21_decimal dec_check = {{0x22d7a808, 0x10d708f4, 0x5bb84236, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_239) {
  // -9451982789
  s21_decimal dec_1 = {{0x3361cfc5, 0x2, 0x0, 0x80000000}};
  // -0.0436286
  s21_decimal dec_2 = {{0x6a83e, 0x0, 0x0, 0x80070000}};
  // -9451982789.0436286
  s21_decimal dec_check = {{0x5da3f8be, 0x14fcd48, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_240) {
  // -1602780467548625461.95788
  s21_decimal dec_1 = {{0xa82e954c, 0xb0b91e0f, 0x21f0, 0x80050000}};
  // -9587754682.81
  s21_decimal dec_2 = {{0x3b78a0f9, 0xdf, 0x0, 0x80020000}};
  // -1602780477136380144.76788
  s21_decimal dec_check = {{0xf76361f4, 0xb0bc860f, 0x21f0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_241) {
  // -25040403196.540310127072756597
  s21_decimal dec_1 = {{0x1727c375, 0x47b48c50, 0x50e8efa1, 0x80120000}};
  // 78549564071157548047
  s21_decimal dec_2 = {{0x6b21c40f, 0x42181c59, 0x4, 0x0}};
  // 78549564046117144850.459689873
  s21_decimal dec_check = {{0x70628391, 0x545866fe, 0xfdcead2f, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_242) {
  // -46009823597075561727927196
  s21_decimal dec_1 = {{0x3cf8239c, 0x88f48746, 0x260ef5, 0x80000000}};
  // 496553609660751919646
  s21_decimal dec_2 = {{0xf717ba1e, 0xeb10cd21, 0x1a, 0x0}};
  // -46009327043465900976007550
  s21_decimal dec_check = {{0x45e0697e, 0x9de3ba24, 0x260eda, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_243) {
  // 52056030328.723121852759713756
  s21_decimal dec_1 = {{0x51f0a7dc, 0xab2c5f37, 0xa833bd32, 0x120000}};
  // -0.63
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x80020000}};
  // 52056030328.093121852759713756
  s21_decimal dec_check = {{0xd171a7dc, 0xa26e298d, 0xa833bd32, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_244) {
  // 46
  s21_decimal dec_1 = {{0x2e, 0x0, 0x0, 0x0}};
  // 3469822110433856
  s21_decimal dec_2 = {{0xea538240, 0xc53c8, 0x0, 0x0}};
  // 3469822110433902
  s21_decimal dec_check = {{0xea53826e, 0xc53c8, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_245) {
  // -285206
  s21_decimal dec_1 = {{0x45a16, 0x0, 0x0, 0x80000000}};
  // 1939.851729423669566955025
  s21_decimal dec_2 = {{0x2298de11, 0x92adf7e1, 0x19ac7, 0x150000}};
  // -283266.148270576330433044975
  s21_decimal dec_check = {{0x3f2721ef, 0xaad601e4, 0xea4ff0, 0x80150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_246) {
  // 40472.36542637082810
  s21_decimal dec_1 = {{0x3ddd08ba, 0x382aac31, 0x0, 0xe0000}};
  // 142000643320676813602
  s21_decimal dec_2 = {{0x9de30b22, 0xb2a7a0bf, 0x7, 0x0}};
  // 142000643320676854074.36542637
  s21_decimal dec_check = {{0x306b92ad, 0xe9bff6f4, 0x2de20495, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_247) {
  // -310691649.62580
  s21_decimal dec_1 = {{0xda8a8314, 0x1c41, 0x0, 0x80050000}};
  // 282046.4
  s21_decimal dec_2 = {{0x2b0970, 0x0, 0x0, 0x10000}};
  // -310409603.22580
  s21_decimal dec_check = {{0x4969dc14, 0x1c3b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_248) {
  // -2205477780802084875
  s21_decimal dec_1 = {{0x44b9a00b, 0x1e9b6e5b, 0x0, 0x80000000}};
  // 51692002.09
  s21_decimal dec_2 = {{0x341bbc51, 0x1, 0x0, 0x20000}};
  // -2205477780750392872.91
  s21_decimal dec_check = {{0xa466c7fb, 0xf4b71ba5, 0xb, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_249) {
  // -7955779881
  s21_decimal dec_1 = {{0xda339129, 0x1, 0x0, 0x80000000}};
  // 443.772
  s21_decimal dec_2 = {{0x6c57c, 0x0, 0x0, 0x30000}};
  // -7955779437.228
  s21_decimal dec_check = {{0x596842ac, 0x73c, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_250) {
  // -0.4833742751565889
  s21_decimal dec_1 = {{0x6fa48841, 0x112c43, 0x0, 0x80100000}};
  // 153359839
  s21_decimal dec_2 = {{0x92415df, 0x0, 0x0, 0x0}};
  // 153359838.5166257248434111
  s21_decimal dec_check = {{0xbe7a77bf, 0x88f8c43a, 0x144c0, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_251) {
  // 79228162514264337593366322733
  s21_decimal dec_1 = {{0xf5699e2d, 0xffffffff, 0xffffffff, 0x0}};
  // -68727875803485907704.92
  s21_decimal dec_2 = {{0xe234c93c, 0x931672bc, 0x174, 0x80020000}};
  // 79228162445536461789880415028
  s21_decimal dec_check = {{0xab787334, 0x46358917, 0xfffffffc, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_252) {
  // -452701
  s21_decimal dec_1 = {{0x6e85d, 0x0, 0x0, 0x80000000}};
  // 92514197831.603195639672
  s21_decimal dec_2 = {{0x9a1a7778, 0x34681e9d, 0x1397, 0xc0000}};
  // 92513745130.603195639672
  s21_decimal dec_check = {{0x63a3a778, 0x2e1fcd74, 0x1397, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_253) {
  // -282172718582105827483922
  s21_decimal dec_1 = {{0xeb3ca112, 0x9d1d1749, 0x3bc0, 0x80000000}};
  // -20481656331
  s21_decimal dec_2 = {{0xc4cd460b, 0x4, 0x0, 0x80000000}};
  // -282172718582126309140253
  s21_decimal dec_check = {{0xb009e71d, 0x9d1d174e, 0x3bc0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_254) {
  // -87859379511648.279
  s21_decimal dec_1 = {{0xe1fa6017, 0x13823a3, 0x0, 0x80030000}};
  // 52545.9778484973805
  s21_decimal dec_2 = {{0x705a30ed, 0x74acee2, 0x0, 0xd0000}};
  // -87859379459102.3011515026195
  s21_decimal dec_check = {{0x3a374b13, 0xa98c3d8, 0x2d6c179, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_255) {
  // 4968823
  s21_decimal dec_1 = {{0x4bd177, 0x0, 0x0, 0x0}};
  // -952.3
  s21_decimal dec_2 = {{0x2533, 0x0, 0x0, 0x80010000}};
  // 4967870.7
  s21_decimal dec_check = {{0x2f60973, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_257) {
  // -15
  s21_decimal dec_1 = {{0xf, 0x0, 0x0, 0x80000000}};
  // 4886613046907863867436447.3
  s21_decimal dec_2 = {{0xa7f0c839, 0x3da38bad, 0x286bce, 0x10000}};
  // 4886613046907863867436432.3
  s21_decimal dec_check = {{0xa7f0c7a3, 0x3da38bad, 0x286bce, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_258) {
  // -4769290676572054265849895
  s21_decimal dec_1 = {{0xc160e827, 0xc400d54e, 0x3f1ef, 0x80000000}};
  // -2524.2756945
  s21_decimal dec_2 = {{0xe095e751, 0x5, 0x0, 0x80070000}};
  // -4769290676572054265852419.2757
  s21_decimal dec_check = {{0xdaed9ff5, 0x608c5461, 0x9a1aa5d8, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_259) {
  // 742804908984318359047832.56304
  s21_decimal dec_1 = {{0x1ce58af0, 0x44bae4e8, 0xf00361c8, 0x50000}};
  // -1.970134337
  s21_decimal dec_2 = {{0x756ddd41, 0x0, 0x0, 0x80090000}};
  // 742804908984318359047830.59291
  s21_decimal dec_check = {{0x1ce2895b, 0x44bae4e8, 0xf00361c8, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_261) {
  // 218632580908.08532725
  s21_decimal dec_1 = {{0xa753def5, 0x2f69e565, 0x1, 0x80000}};
  // -504914986279905361943992
  s21_decimal dec_2 = {{0x1e3c5db8, 0x7f0a6353, 0x6aeb, 0x80000000}};
  // -504914986279686729363083.91467
  s21_decimal dec_check = {{0x685e3e2b, 0x3981077e, 0xa32596b9, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_262) {
  // -4376615
  s21_decimal dec_1 = {{0x42c827, 0x0, 0x0, 0x80000000}};
  // -38403129439944726414.62794795
  s21_decimal dec_2 = {{0x2197fa2b, 0xd85bc8f5, 0xc68a1e5, 0x80080000}};
  // -38403129439949103029.62794795
  s21_decimal dec_check = {{0x23d5412b, 0xd85d5702, 0xc68a1e5, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_263) {
  // -814253766778735154055
  s21_decimal dec_1 = {{0xae45d387, 0x240a7ec8, 0x2c, 0x80000000}};
  // 2892277142864318288198470
  s21_decimal dec_2 = {{0x45597b46, 0xa878560a, 0x26476, 0x0}};
  // 2891462889097539553044415
  s21_decimal dec_check = {{0x9713a7bf, 0x846dd741, 0x2644a, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_264) {
  // 1900
  s21_decimal dec_1 = {{0x76c, 0x0, 0x0, 0x0}};
  // 41821465257798338.77
  s21_decimal dec_2 = {{0x73bdb415, 0x3a09f81b, 0x0, 0x20000}};
  // 41821465257800238.77
  s21_decimal dec_check = {{0x73c09a45, 0x3a09f81b, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_265) {
  // -373155
  s21_decimal dec_1 = {{0x5b1a3, 0x0, 0x0, 0x80000000}};
  // 80346465180008579293
  s21_decimal dec_2 = {{0x2cb400dd, 0x5b07fc63, 0x4, 0x0}};
  // 80346465180008206138
  s21_decimal dec_check = {{0x2cae4f3a, 0x5b07fc63, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_266) {
  // 24545704710339260897371752
  s21_decimal dec_1 = {{0xb16d2668, 0x5190385d, 0x144dc1, 0x0}};
  // -403726.44614879492
  s21_decimal dec_2 = {{0xd4e9b904, 0x8f6eb4, 0x0, 0x800b0000}};
  // 24545704710339260896968025.554
  s21_decimal dec_check = {{0xfa4da5d2, 0x9b5c2dfc, 0x4f4fbb26, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_267) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -70
  s21_decimal dec_2 = {{0x46, 0x0, 0x0, 0x80000000}};
  // -71
  s21_decimal dec_check = {{0x47, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_268) {
  // -31
  s21_decimal dec_1 = {{0x1f, 0x0, 0x0, 0x80000000}};
  // 7264
  s21_decimal dec_2 = {{0x1c60, 0x0, 0x0, 0x0}};
  // 7233
  s21_decimal dec_check = {{0x1c41, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_269) {
  // 948231407204988636
  s21_decimal dec_1 = {{0xdf5276dc, 0xd28cb70, 0x0, 0x0}};
  // -363
  s21_decimal dec_2 = {{0x16b, 0x0, 0x0, 0x80000000}};
  // 948231407204988273
  s21_decimal dec_check = {{0xdf527571, 0xd28cb70, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_270) {
  // -7975845740337234
  s21_decimal dec_1 = {{0x4c22d852, 0x1c55fd, 0x0, 0x80000000}};
  // 5004361974987.2916
  s21_decimal dec_2 = {{0x32774514, 0xb1ca68, 0x0, 0x40000}};
  // -7970841378362246.7084
  s21_decimal dec_check = {{0xdeaabe0c, 0x522d2c05, 0x4, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_271) {
  // -35478353011314903576668630
  s21_decimal dec_1 = {{0xcafee9d6, 0x5edc9c84, 0x1d58d5, 0x80000000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -35478353011314903576668625
  s21_decimal dec_check = {{0xcafee9d1, 0x5edc9c84, 0x1d58d5, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_272) {
  // -239828512
  s21_decimal dec_1 = {{0xe4b7e20, 0x0, 0x0, 0x80000000}};
  // -195742070092839991562238
  s21_decimal dec_2 = {{0xccb6cffe, 0x32e9ef80, 0x2973, 0x80000000}};
  // -195742070092840231390750
  s21_decimal dec_check = {{0xdb024e1e, 0x32e9ef80, 0x2973, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_273) {
  // 5251141892.8826745115046756549
  s21_decimal dec_1 = {{0x10e6c0c5, 0x25825355, 0xa9ac6d7c, 0x130000}};
  // -0.462583340320854
  s21_decimal dec_2 = {{0x93adc856, 0x1a4b7, 0x0, 0x800f0000}};
  // 5251141892.4200911711838216549
  s21_decimal dec_check = {{0x5c852165, 0xe550105c, 0xa9ac6d7b, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_275) {
  // 518951.9676
  s21_decimal dec_1 = {{0x3551c93c, 0x1, 0x0, 0x40000}};
  // -75.165693077642018615
  s21_decimal dec_2 = {{0xf4e3ff37, 0x13222f9b, 0x4, 0x80120000}};
  // 518876.801906922357981385
  s21_decimal dec_check = {{0x240300c9, 0x5e27bf3a, 0x6de0, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_276) {
  // -30336
  s21_decimal dec_1 = {{0x7680, 0x0, 0x0, 0x80000000}};
  // 0.571
  s21_decimal dec_2 = {{0x23b, 0x0, 0x0, 0x30000}};
  // -30335.429
  s21_decimal dec_check = {{0x1cee1c5, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_277) {
  // -8747507623329805
  s21_decimal dec_1 = {{0xd48f000d, 0x1f13cf, 0x0, 0x80000000}};
  // -89
  s21_decimal dec_2 = {{0x59, 0x0, 0x0, 0x80000000}};
  // -8747507623329894
  s21_decimal dec_check = {{0xd48f0066, 0x1f13cf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_279) {
  // -59.6
  s21_decimal dec_1 = {{0x254, 0x0, 0x0, 0x80010000}};
  // -7321863
  s21_decimal dec_2 = {{0x6fb907, 0x0, 0x0, 0x80000000}};
  // -7321922.6
  s21_decimal dec_check = {{0x45d3c9a, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_280) {
  // -91.77650
  s21_decimal dec_1 = {{0x8c0a32, 0x0, 0x0, 0x80050000}};
  // 45118816
  s21_decimal dec_2 = {{0x2b07560, 0x0, 0x0, 0x0}};
  // 45118724.22350
  s21_decimal dec_check = {{0x808d91ce, 0x41a, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_281) {
  // -975409293618296754
  s21_decimal dec_1 = {{0xa8bbb7b2, 0xd895995, 0x0, 0x80000000}};
  // 848715116
  s21_decimal dec_2 = {{0x32965d6c, 0x0, 0x0, 0x0}};
  // -975409292769581638
  s21_decimal dec_check = {{0x76255a46, 0xd895995, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_282) {
  // 25253549453044418.6190
  s21_decimal dec_1 = {{0xf8ba524e, 0xb0a24e48, 0xd, 0x40000}};
  // -9022556821050837515077
  s21_decimal dec_2 = {{0xe0d93b45, 0x1d210930, 0x1e9, 0x80000000}};
  // -9022531567501384470658.3810
  s21_decimal dec_check = {{0x2ce0e502, 0x29d4b706, 0x4aa1f4, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_283) {
  // 8500713187327205.567543
  s21_decimal dec_1 = {{0x54b5ec37, 0xd318052a, 0x1cc, 0x60000}};
  // -2640499646340573183435
  s21_decimal dec_2 = {{0x4a703dcb, 0x244b3661, 0x8f, 0x80000000}};
  // -2640491145627385856229.432457
  s21_decimal dec_check = {{0xd62cdc89, 0xd36e04ec, 0x88829bf, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_284) {
  // 33120568
  s21_decimal dec_1 = {{0x1f96138, 0x0, 0x0, 0x0}};
  // -863329
  s21_decimal dec_2 = {{0xd2c61, 0x0, 0x0, 0x80000000}};
  // 32257239
  s21_decimal dec_check = {{0x1ec34d7, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_285) {
  // -33482953611886687278180751854
  s21_decimal dec_1 = {{0x21e59ee, 0x5ca87907, 0x6c307338, 0x80000000}};
  // -3854420060586152023042
  s21_decimal dec_2 = {{0xa933d402, 0xf2d2df82, 0xd0, 0x80000000}};
  // -33482957466306747864332774896
  s21_decimal dec_check = {{0xab522df0, 0x4f7b5889, 0x6c307409, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_286) {
  // -628355075000392616086600
  s21_decimal dec_1 = {{0xf0118c48, 0x326618fc, 0x850f, 0x80000000}};
  // -1402597450661861607631
  s21_decimal dec_2 = {{0xe0bd48cf, 0x8f32618, 0x4c, 0x80000000}};
  // -629757672451054477694231
  s21_decimal dec_check = {{0xd0ced517, 0x3b593f15, 0x855b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_287) {
  // 14460.464081778619
  s21_decimal dec_1 = {{0x28e1b7bb, 0x335fb7, 0x0, 0xc0000}};
  // -9555074807243
  s21_decimal dec_2 = {{0xb6d6f5cb, 0x8b0, 0x0, 0x80000000}};
  // -9555074792782.535918221381
  s21_decimal dec_check = {{0xce51f845, 0xa47647c6, 0x7e75d, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_288) {
  // 14886364143345076
  s21_decimal dec_1 = {{0xbec2ddb4, 0x34e311, 0x0, 0x0}};
  // 7071295041836639305
  s21_decimal dec_2 = {{0xea76449, 0x62224960, 0x0, 0x0}};
  // 7086181405979984381
  s21_decimal dec_check = {{0xcd6a41fd, 0x62572c71, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_289) {
  // -170437238370940
  s21_decimal dec_1 = {{0x30cb27c, 0x9b03, 0x0, 0x80000000}};
  // 6742.8
  s21_decimal dec_2 = {{0x10764, 0x0, 0x0, 0x10000}};
  // -170437238364197.2
  s21_decimal dec_check = {{0x1e7df174, 0x60e1e, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_290) {
  // -651142891.2
  s21_decimal dec_1 = {{0x841c8530, 0x1, 0x0, 0x80010000}};
  // -968117428760386250554871
  s21_decimal dec_2 = {{0x1ed3df7, 0xc03fd79a, 0xcd01, 0x80000000}};
  // -968117428760386901697762.2
  s21_decimal dec_check = {{0x9760f0d6, 0x827e6c05, 0x80211, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_291) {
  // 1269.392856701231
  s21_decimal dec_1 = {{0x8e4dd92f, 0x48281, 0x0, 0xc0000}};
  // -187387782972839
  s21_decimal dec_2 = {{0x9e3d45a7, 0xaa6d, 0x0, 0x80000000}};
  // -187387782971569.607143298769
  s21_decimal dec_check = {{0x76af96d1, 0x11db31e6, 0x9b00e8, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_292) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 3312580005185512444331
  s21_decimal dec_2 = {{0x481a91ab, 0x93484bea, 0xb3, 0x0}};
  // 3312580005185512444323
  s21_decimal dec_check = {{0x481a91a3, 0x93484bea, 0xb3, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_293) {
  // -53522343457204807312709393
  s21_decimal dec_1 = {{0x1fb59711, 0xd79deb9, 0x2c45cc, 0x80000000}};
  // 632569365071099612641339.8960
  s21_decimal dec_2 = {{0x3f94a3b0, 0xedce6f1b, 0x14707dbb, 0x40000}};
  // -52889774092133707700068053.104
  s21_decimal dec_check = {{0x56fa7070, 0xa5dfc4d4, 0xaae5654e, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_294) {
  // 29665952635977
  s21_decimal dec_1 = {{0x24919c49, 0x1afb, 0x0, 0x0}};
  // 57328615211758033242873338501
  s21_decimal dec_2 = {{0x93331a85, 0xe89f3daa, 0xb93d1e79, 0x0}};
  // 57328615211758062908825974478
  s21_decimal dec_check = {{0xb7c4b6ce, 0xe89f58a5, 0xb93d1e79, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_295) {
  // -680910189616209767765949
  s21_decimal dec_1 = {{0x895517bd, 0x3720af24, 0x9030, 0x80000000}};
  // -783812574.316714126895010
  s21_decimal dec_2 = {{0x12aa67a2, 0x9096640d, 0xa5fa, 0x800f0000}};
  // -680910189616210551578523.31671
  s21_decimal dec_check = {{0x65a5e97, 0x3f3f6757, 0xdc03921e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_296) {
  // -63428138652028490442.1
  s21_decimal dec_1 = {{0x2fd23be5, 0x626c2879, 0x22, 0x80010000}};
  // 505567524
  s21_decimal dec_2 = {{0x1e225924, 0x0, 0x0, 0x0}};
  // -63428138651522922918.1
  s21_decimal dec_check = {{0x27ac07d, 0x626c2878, 0x22, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_297) {
  // 54825093500037787777362237
  s21_decimal dec_1 = {{0x31b1e93d, 0x462319c6, 0x2d59aa, 0x0}};
  // -39698
  s21_decimal dec_2 = {{0x9b12, 0x0, 0x0, 0x80000000}};
  // 54825093500037787777322539
  s21_decimal dec_check = {{0x31b14e2b, 0x462319c6, 0x2d59aa, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_298) {
  // -21.657167
  s21_decimal dec_1 = {{0x14a764f, 0x0, 0x0, 0x80060000}};
  // 781361712904
  s21_decimal dec_2 = {{0xecc98f08, 0xb5, 0x0, 0x0}};
  // 781361712882.342833
  s21_decimal dec_check = {{0x89715bb1, 0xad7f456, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_300) {
  // -56317799067064180
  s21_decimal dec_1 = {{0x67ec9774, 0xc814bd, 0x0, 0x80000000}};
  // 207.73800093112028912
  s21_decimal dec_2 = {{0xd0eb4ef0, 0x204b5d1e, 0x1, 0x110000}};
  // -56317799067063972.261999068880
  s21_decimal dec_check = {{0xb17ac6d0, 0xe7d84398, 0xb5f8fdd4, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_301) {
  // -768812848438229456.6271671899
  s21_decimal dec_1 = {{0xbf3f5e5b, 0x4178bdc4, 0x18d77888, 0x800a0000}};
  // 2.86309108
  s21_decimal dec_2 = {{0x1110baf4, 0x0, 0x0, 0x80000}};
  // -768812848438229453.7640761099
  s21_decimal dec_check = {{0x14b6570b, 0x4178bdbe, 0x18d77888, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_302) {
  // -27637124366
  s21_decimal dec_1 = {{0x6f4d0d0e, 0x6, 0x0, 0x80000000}};
  // 4517218672499299206052
  s21_decimal dec_2 = {{0x4a5443a4, 0xe1009163, 0xf4, 0x0}};
  // 4517218672471662081686
  s21_decimal dec_check = {{0xdb073696, 0xe100915c, 0xf4, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_303) {
  // -2893640755540525821857208904
  s21_decimal dec_1 = {{0xaca59a48, 0xad6f7146, 0x9599043, 0x80000000}};
  // 57661239
  s21_decimal dec_2 = {{0x36fd737, 0x0, 0x0, 0x0}};
  // -2893640755540525821799547665
  s21_decimal dec_check = {{0xa935c311, 0xad6f7146, 0x9599043, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_304) {
  // -780880027323081638081
  s21_decimal dec_1 = {{0x159b40c1, 0x54e32792, 0x2a, 0x80000000}};
  // 68
  s21_decimal dec_2 = {{0x44, 0x0, 0x0, 0x0}};
  // -780880027323081638013
  s21_decimal dec_check = {{0x159b407d, 0x54e32792, 0x2a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_305) {
  // 803.7
  s21_decimal dec_1 = {{0x1f65, 0x0, 0x0, 0x10000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // 799.7
  s21_decimal dec_check = {{0x1f3d, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_306) {
  // -3453942166
  s21_decimal dec_1 = {{0xcddef996, 0x0, 0x0, 0x80000000}};
  // -26398.162514660
  s21_decimal dec_2 = {{0x4d1972e4, 0x1802, 0x0, 0x80090000}};
  // -3453968564.162514660
  s21_decimal dec_check = {{0xf445cee4, 0x2feef61b, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_308) {
  // 154.6221761593176807793060
  s21_decimal dec_1 = {{0x829161a4, 0xd982deff, 0x1476c, 0x160000}};
  // 5548602276896301829002310837
  s21_decimal dec_2 = {{0xe94734b5, 0x24b9189e, 0x11edb23c, 0x0}};
  // 5548602276896301829002310991.6
  s21_decimal dec_check = {{0x1cc8151c, 0x6f3af635, 0xb348f659, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_309) {
  // 82
  s21_decimal dec_1 = {{0x52, 0x0, 0x0, 0x0}};
  // 235854090042441683651
  s21_decimal dec_2 = {{0xfabb52c3, 0xc9220d48, 0xc, 0x0}};
  // 235854090042441683733
  s21_decimal dec_check = {{0xfabb5315, 0xc9220d48, 0xc, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_310) {
  // -338890935244740
  s21_decimal dec_1 = {{0x31d017c4, 0x13438, 0x0, 0x80000000}};
  // -72709468694518896
  s21_decimal dec_2 = {{0x65581c70, 0x10250e0, 0x0, 0x80000000}};
  // -73048359629763636
  s21_decimal dec_check = {{0x97283434, 0x1038518, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_311) {
  // 2990.226229293642827264308
  s21_decimal dec_1 = {{0x69017134, 0x7d1b8502, 0x27934, 0x150000}};
  // -48939326332540452613
  s21_decimal dec_2 = {{0xfdfe7f05, 0xa72b6a01, 0x2, 0x80000000}};
  // -48939326332540449622.773770706
  s21_decimal dec_check = {{0x28dca9d2, 0x7c620211, 0x9e21a974, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_312) {
  // 285
  s21_decimal dec_1 = {{0x11d, 0x0, 0x0, 0x0}};
  // -23
  s21_decimal dec_2 = {{0x17, 0x0, 0x0, 0x80000000}};
  // 262
  s21_decimal dec_check = {{0x106, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_313) {
  // -275358506698036.9072180
  s21_decimal dec_1 = {{0xb9198034, 0x45ab554c, 0x95, 0x80070000}};
  // 662351466565746363679668979
  s21_decimal dec_2 = {{0x47807af3, 0xf331b323, 0x223e260, 0x0}};
  // 662351466565471005172970942.09
  s21_decimal dec_check = {{0x186cfe41, 0xff082612, 0xd6046dde, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_314) {
  // -788925431923.90809
  s21_decimal dec_1 = {{0x9c68dc99, 0x1184859, 0x0, 0x80050000}};
  // 19855448
  s21_decimal dec_2 = {{0x12ef858, 0x0, 0x0, 0x0}};
  // -788905576475.90809
  s21_decimal dec_check = {{0x50b79599, 0x118468b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_315) {
  // 96.14028865361
  s21_decimal dec_1 = {{0x70c67f51, 0x8be, 0x0, 0xb0000}};
  // 50216.2427307213843024299
  s21_decimal dec_2 = {{0x1e1b49ab, 0x479c7958, 0x6a56, 0x130000}};
  // 50312.3830193749943024299
  s21_decimal dec_check = {{0x1867aab, 0x65c1a8eb, 0x6a8a, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_316) {
  // -79331.345490868169
  s21_decimal dec_1 = {{0x3b8977c9, 0x119d770, 0x0, 0x800c0000}};
  // -612
  s21_decimal dec_2 = {{0x264, 0x0, 0x0, 0x80000000}};
  // -79943.345490868169
  s21_decimal dec_check = {{0x9623b7c9, 0x11c040c, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_317) {
  // 2011039644559856429
  s21_decimal dec_1 = {{0xdb37d32d, 0x1be8a5e6, 0x0, 0x0}};
  // 210987715589783725780
  s21_decimal dec_2 = {{0xd434a6d4, 0x700af177, 0xb, 0x0}};
  // 212998755234343582209
  s21_decimal dec_check = {{0xaf6c7a01, 0x8bf3975e, 0xb, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_318) {
  // -91305399187615353445
  s21_decimal dec_1 = {{0xed0d8a65, 0xf31df0cd, 0x4, 0x80000000}};
  // -92316092
  s21_decimal dec_2 = {{0x580a1bc, 0x0, 0x0, 0x80000000}};
  // -91305399187707669537
  s21_decimal dec_check = {{0xf28e2c21, 0xf31df0cd, 0x4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_319) {
  // -429860805304043814143
  s21_decimal dec_1 = {{0x82e1bcff, 0x4d845cec, 0x17, 0x80000000}};
  // 9274782263938843572750396
  s21_decimal dec_2 = {{0x194cc83c, 0xf438fde7, 0x7ac02, 0x0}};
  // 9274352403133539528936253
  s21_decimal dec_check = {{0x966b0b3d, 0xa6b4a0fa, 0x7abeb, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_320) {
  // -245265033978650143041
  s21_decimal dec_1 = {{0x98da941, 0x4bbc70ef, 0xd, 0x80000000}};
  // -3124766157627646993849
  s21_decimal dec_2 = {{0x462ae5b9, 0x64d778a4, 0xa9, 0x80000000}};
  // -3370031191606297136890
  s21_decimal dec_check = {{0x4fb88efa, 0xb093e993, 0xb6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_321) {
  // -60490288096667563772795684780
  s21_decimal dec_1 = {{0xa9e807ac, 0x6f1df8cc, 0xc37464c0, 0x80000000}};
  // 5793270
  s21_decimal dec_2 = {{0x5865f6, 0x0, 0x0, 0x0}};
  // -60490288096667563772789891510
  s21_decimal dec_check = {{0xa98fa1b6, 0x6f1df8cc, 0xc37464c0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_322) {
  // 5023561.64363
  s21_decimal dec_1 = {{0xf6c2bf0b, 0x74, 0x0, 0x50000}};
  // 717309249880915841018
  s21_decimal dec_2 = {{0xa5e60ffa, 0xe2aa624c, 0x26, 0x0}};
  // 717309249880920864579.64363
  s21_decimal dec_check = {{0x22e3974b, 0x3c3e3519, 0x3b559d, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_323) {
  // -48843.54
  s21_decimal dec_1 = {{0x4a8782, 0x0, 0x0, 0x80020000}};
  // -6309075174160
  s21_decimal dec_2 = {{0xf22f4310, 0x5bc, 0x0, 0x80000000}};
  // -6309075223003.54
  s21_decimal dec_check = {{0x9ac0b9c2, 0x23dce, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_324) {
  // -651.258543761
  s21_decimal dec_1 = {{0xa208be91, 0x97, 0x0, 0x80090000}};
  // -30.235
  s21_decimal dec_2 = {{0x761b, 0x0, 0x0, 0x80030000}};
  // -681.493543761
  s21_decimal dec_check = {{0xac2e3b51, 0x9e, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_325) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // 77575
  s21_decimal dec_2 = {{0x12f07, 0x0, 0x0, 0x0}};
  // 77579
  s21_decimal dec_check = {{0x12f0b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_326) {
  // -46048361
  s21_decimal dec_1 = {{0x2bea469, 0x0, 0x0, 0x80000000}};
  // 0.33
  s21_decimal dec_2 = {{0x21, 0x0, 0x0, 0x20000}};
  // -46048360.67
  s21_decimal dec_check = {{0x127838e3, 0x1, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_328) {
  // -92292656
  s21_decimal dec_1 = {{0x5804630, 0x0, 0x0, 0x80000000}};
  // 5636299599196594783033048
  s21_decimal dec_2 = {{0x92f696d8, 0x69dbe22e, 0x4a988, 0x0}};
  // 5636299599196594690740392
  s21_decimal dec_check = {{0x8d7650a8, 0x69dbe22e, 0x4a988, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_329) {
  // 506575296078509.555191
  s21_decimal dec_1 = {{0x1be4bdf7, 0x7624fbd5, 0x1b, 0x60000}};
  // -2727916109438499136
  s21_decimal dec_2 = {{0x9825b940, 0x25db813f, 0x0, 0x80000000}};
  // -2727409534142420626.444809
  s21_decimal dec_check = {{0x820c1209, 0x2ac7a380, 0x2418d, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_330) {
  // -9357948151640937069802.833669
  s21_decimal dec_1 = {{0x52764705, 0xcd009f18, 0x1e3cb699, 0x80060000}};
  // 521094261412779485166294
  s21_decimal dec_2 = {{0x3f4dfad6, 0x93967733, 0x6e58, 0x0}};
  // 511736313261138548096491.16633
  s21_decimal dec_check = {{0x87d2f5d9, 0xe322828f, 0xa559d5f0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_331) {
  // 5331684016165946133.40
  s21_decimal dec_1 = {{0x4bed345c, 0xe732ac6c, 0x1c, 0x20000}};
  // -5905912221.05220258022893734
  s21_decimal dec_2 = {{0x90b928a6, 0x4d88b885, 0x1e8868e, 0x80110000}};
  // 5331684010260033912.3477974198
  s21_decimal dec_check = {{0x7a848cb6, 0x770f5406, 0xac46a80d, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_332) {
  // 3853453264036806.5688149
  s21_decimal dec_1 = {{0xf1eeb255, 0xf61137b5, 0x828, 0x70000}};
  // 44.18776131
  s21_decimal dec_2 = {{0x7612c43, 0x1, 0x0, 0x80000}};
  // 3853453264036850.75657621
  s21_decimal dec_check = {{0x7ab42395, 0x9cac2d1c, 0x5199, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_333) {
  // -0.56
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x80020000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -7.56
  s21_decimal dec_check = {{0x2f4, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_334) {
  // -2.984952669769583584
  s21_decimal dec_1 = {{0x60f84be0, 0x296caea3, 0x0, 0x80120000}};
  // -69618.44
  s21_decimal dec_2 = {{0x6a3ab4, 0x0, 0x0, 0x80020000}};
  // -69621.424952669769583584
  s21_decimal dec_check = {{0xaeac4be0, 0x2f5cc455, 0xebe, 0x80120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_335) {
  // -54940068606313872.19
  s21_decimal dec_1 = {{0x997e2c53, 0x4c3ea221, 0x0, 0x80020000}};
  // -781502673356363950699
  s21_decimal dec_2 = {{0xc8346a6b, 0x5d873cd6, 0x2a, 0x80000000}};
  // -781557613424970264571.19
  s21_decimal dec_check = {{0xcdf7be1f, 0xd5126607, 0x108c, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_336) {
  // 519438990778
  s21_decimal dec_1 = {{0xf0f9fdba, 0x78, 0x0, 0x0}};
  // 135.0990057908571766389328190
  s21_decimal dec_2 = {{0x6699c93e, 0xca1f4387, 0x45d8345, 0x190000}};
  // 519438990913.09900579085717664
  s21_decimal dec_check = {{0xdf8390a0, 0x1bb9981e, 0xa7d6fc7c, 0x110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_337) {
  // 7526835444857078117632443057
  s21_decimal dec_1 = {{0x658e02b1, 0x101031e8, 0x18520d67, 0x0}};
  // -30541898775786787511608048
  s21_decimal dec_2 = {{0x95fa22f0, 0xa675472a, 0x19437f, 0x80000000}};
  // 7496293546081291330120835009
  s21_decimal dec_check = {{0xcf93dfc1, 0x699aeabd, 0x1838c9e7, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_338) {
  // -71041632521915374279966
  s21_decimal dec_1 = {{0x3bec9d1e, 0x2cb39ffb, 0xf0b, 0x80000000}};
  // -616970191163959502460
  s21_decimal dec_2 = {{0xf4a7667c, 0x722e7003, 0x21, 0x80000000}};
  // -71658602713079333782426
  s21_decimal dec_check = {{0x3094039a, 0x9ee20fff, 0xf2c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_339) {
  // 834173293520936088176439391.80
  s21_decimal dec_1 = {{0x1a2e56c, 0x52ed7ddd, 0xd893295, 0x20000}};
  // -45467673808739
  s21_decimal dec_2 = {{0x448bcf63, 0x295a, 0x0, 0x80000000}};
  // 834173293520890620502630652.80
  s21_decimal dec_check = {{0x3b05e2c0, 0x52dd569a, 0xd893295, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_340) {
  // -442
  s21_decimal dec_1 = {{0x1ba, 0x0, 0x0, 0x80000000}};
  // -30837917
  s21_decimal dec_2 = {{0x1d68c9d, 0x0, 0x0, 0x80000000}};
  // -30838359
  s21_decimal dec_check = {{0x1d68e57, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_342) {
  // 3459504
  s21_decimal dec_1 = {{0x34c9b0, 0x0, 0x0, 0x0}};
  // -37359.415333460914
  s21_decimal dec_2 = {{0xb7f79bb2, 0x84ba30, 0x0, 0x800c0000}};
  // 3422144.584666539086
  s21_decimal dec_check = {{0x5313644e, 0x2f7de65e, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_343) {
  // 8290213456546784237
  s21_decimal dec_1 = {{0x1da263ed, 0x730cc137, 0x0, 0x0}};
  // -2430495527171177978
  s21_decimal dec_2 = {{0xfd36bdfa, 0x21badacd, 0x0, 0x80000000}};
  // 5859717929375606259
  s21_decimal dec_check = {{0x206ba5f3, 0x5151e669, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_344) {
  // 2574
  s21_decimal dec_1 = {{0xa0e, 0x0, 0x0, 0x0}};
  // -311897459333191
  s21_decimal dec_2 = {{0x49451847, 0x11bab, 0x0, 0x80000000}};
  // -311897459330617
  s21_decimal dec_check = {{0x49450e39, 0x11bab, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_345) {
  // 0.934046576337833
  s21_decimal dec_1 = {{0xaa62e3a9, 0x35182, 0x0, 0xf0000}};
  // 78372797524318671891.0
  s21_decimal dec_2 = {{0x6a4848be, 0x7c69191d, 0x2a, 0x10000}};
  // 78372797524318671891.934046576
  s21_decimal dec_check = {{0x13716970, 0xfb4cfb03, 0xfd3c756a, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_346) {
  // -103
  s21_decimal dec_1 = {{0x67, 0x0, 0x0, 0x80000000}};
  // 47645053980.2385805
  s21_decimal dec_2 = {{0xd9f6dd8d, 0x69cb13d, 0x0, 0x70000}};
  // 47645053877.2385805
  s21_decimal dec_check = {{0x9c92500d, 0x69cb13d, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_347) {
  // -6.3094028155313804665
  s21_decimal dec_1 = {{0x1df95579, 0x6b9b0452, 0x3, 0x80130000}};
  // -96.0236551782310047781274
  s21_decimal dec_2 = {{0x8fee119a, 0x871c66b7, 0xcb56, 0x80160000}};
  // -102.3330579937623852446274
  s21_decimal dec_check = {{0xa5e3f242, 0xdca5477c, 0xd8b2, 0x80160000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_348) {
  // 5737522
  s21_decimal dec_1 = {{0x578c32, 0x0, 0x0, 0x0}};
  // -4.4
  s21_decimal dec_2 = {{0x2c, 0x0, 0x0, 0x80010000}};
  // 5737517.6
  s21_decimal dec_check = {{0x36b79c8, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_349) {
  // 9710.523570898360
  s21_decimal dec_1 = {{0x7406c5b8, 0x227fab, 0x0, 0xc0000}};
  // -70484.650979256880923
  s21_decimal dec_2 = {{0x37fecf1b, 0xd22bc89f, 0x3, 0x800f0000}};
  // -60774.127408358520923
  s21_decimal dec_check = {{0xfd8a785b, 0x4b6912e1, 0x3, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_350) {
  // 0.7850751
  s21_decimal dec_1 = {{0x77caff, 0x0, 0x0, 0x70000}};
  // -79228162514264337592963431488
  s21_decimal dec_2 = {{0xdd65fc40, 0xffffffff, 0xffffffff, 0x80000000}};
  // -79228162514264337592963431487
  s21_decimal dec_check = {{0xdd65fc3f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_351) {
  // -485864203347490071706312929
  s21_decimal dec_1 = {{0x2c53a0e1, 0x3d7822d8, 0x191e5bf, 0x80000000}};
  // 69689
  s21_decimal dec_2 = {{0x11039, 0x0, 0x0, 0x0}};
  // -485864203347490071706243240
  s21_decimal dec_check = {{0x2c5290a8, 0x3d7822d8, 0x191e5bf, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_352) {
  // -280.865
  s21_decimal dec_1 = {{0x44921, 0x0, 0x0, 0x80030000}};
  // 2.52
  s21_decimal dec_2 = {{0xfc, 0x0, 0x0, 0x20000}};
  // -278.345
  s21_decimal dec_check = {{0x43f49, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_353) {
  // 0.5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -9902
  s21_decimal dec_2 = {{0x26ae, 0x0, 0x0, 0x80000000}};
  // -9901.5
  s21_decimal dec_check = {{0x182c7, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_355) {
  // -33905821076445361380344291337
  s21_decimal dec_1 = {{0x91e96009, 0x8ca1c2a1, 0x6d8e3ce3, 0x80000000}};
  // -0.29759172
  s21_decimal dec_2 = {{0x1c616c4, 0x0, 0x0, 0x80080000}};
  // -33905821076445361380344291337
  s21_decimal dec_check = {{0x91e96009, 0x8ca1c2a1, 0x6d8e3ce3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_356) {
  // 21268389209978
  s21_decimal dec_1 = {{0xeec8a77a, 0x1357, 0x0, 0x0}};
  // -381878480137015838713404
  s21_decimal dec_2 = {{0xddad263c, 0xac8405b6, 0x50dd, 0x80000000}};
  // -381878480115747449503426
  s21_decimal dec_check = {{0xeee47ec2, 0xac83f25e, 0x50dd, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_357) {
  // 82911616236855168169
  s21_decimal dec_1 = {{0xcf430ca9, 0x7ea13bae, 0x4, 0x0}};
  // 25.85
  s21_decimal dec_2 = {{0xa19, 0x0, 0x0, 0x20000}};
  // 82911616236855168194.85
  s21_decimal dec_check = {{0xf630fc1d, 0x76fb5048, 0x1c1, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_358) {
  // -66770258847032344.3
  s21_decimal dec_1 = {{0x7161e8f3, 0x94427f7, 0x0, 0x80010000}};
  // -50.696686169510
  s21_decimal dec_2 = {{0xbdf86da6, 0x2e1b, 0x0, 0x800c0000}};
  // -66770258847032394.996686169510
  s21_decimal dec_check = {{0x3116a5a6, 0xf7f62757, 0xd7bf1048, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_359) {
  // -5035606748319011.290049154925
  s21_decimal dec_1 = {{0xa0a80f6d, 0xd0c51013, 0x10455b34, 0x800c0000}};
  // 6741572.17008
  s21_decimal dec_2 = {{0xf6e6c4f0, 0x9c, 0x0, 0x50000}};
  // -5035606741577439.119969154925
  s21_decimal dec_check = {{0x760f76d, 0x73362fe8, 0x10455b34, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_360) {
  // 4822
  s21_decimal dec_1 = {{0x12d6, 0x0, 0x0, 0x0}};
  // -9025.596858
  s21_decimal dec_2 = {{0x19f7adba, 0x2, 0x0, 0x80060000}};
  // -4203.596858
  s21_decimal dec_check = {{0xfa8dcc3a, 0x0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_361) {
  // 1.27
  s21_decimal dec_1 = {{0x7f, 0x0, 0x0, 0x20000}};
  // 53977772784103090931.81563949
  s21_decimal dec_2 = {{0xf26b242d, 0x979ed84d, 0x1170efcc, 0x80000}};
  // 53977772784103090933.08563949
  s21_decimal dec_check = {{0xf9fd01ed, 0x979ed84d, 0x1170efcc, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_362) {
  // 47333805030160930201126510195
  s21_decimal dec_1 = {{0xff9f1e73, 0x4908b1b5, 0x98f19b18, 0x0}};
  // 2.70520261
  s21_decimal dec_2 = {{0x101fcfc5, 0x0, 0x0, 0x80000}};
  // 47333805030160930201126510198
  s21_decimal dec_check = {{0xff9f1e76, 0x4908b1b5, 0x98f19b18, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_363) {
  // 93
  s21_decimal dec_1 = {{0x5d, 0x0, 0x0, 0x0}};
  // -6462849683508468
  s21_decimal dec_2 = {{0x739f4cf4, 0x16f5ed, 0x0, 0x80000000}};
  // -6462849683508375
  s21_decimal dec_check = {{0x739f4c97, 0x16f5ed, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_364) {
  // -7558
  s21_decimal dec_1 = {{0x1d86, 0x0, 0x0, 0x80000000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // -7567
  s21_decimal dec_check = {{0x1d8f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_365) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // 92615065808153493526359185
  s21_decimal dec_2 = {{0x40652c91, 0xc717a2af, 0x4c9c00, 0x0}};
  // 92615065808153493526359192
  s21_decimal dec_check = {{0x40652c98, 0xc717a2af, 0x4c9c00, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_366) {
  // -529.257
  s21_decimal dec_1 = {{0x81369, 0x0, 0x0, 0x80030000}};
  // 0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x10000}};
  // -528.657
  s21_decimal dec_check = {{0x81111, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_367) {
  // -0.95977322090602
  s21_decimal dec_1 = {{0x7630906a, 0x574a, 0x0, 0x800e0000}};
  // -1962034605
  s21_decimal dec_2 = {{0x74f245ad, 0x0, 0x0, 0x80000000}};
  // -1962034605.95977322090602
  s21_decimal dec_check = {{0xc0dd06a, 0x35fe498e, 0x298c, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_368) {
  // 0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};
  // 11390755191
  s21_decimal dec_2 = {{0xa6f12177, 0x2, 0x0, 0x0}};
  // 11390755191.3
  s21_decimal dec_check = {{0x856b4ea9, 0x1a, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_370) {
  // 29714371.247399885224439
  s21_decimal dec_1 = {{0x26fa39f7, 0xd1bd3006, 0x64a, 0xf0000}};
  // 2552751.472652558
  s21_decimal dec_2 = {{0xc4ba310e, 0x911b6, 0x0, 0x90000}};
  // 32267122.720052443224439
  s21_decimal dec_check = {{0x35fe1977, 0x34484358, 0x6d5, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_371) {
  // -8.294
  s21_decimal dec_1 = {{0x2066, 0x0, 0x0, 0x80030000}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // -2.294
  s21_decimal dec_check = {{0x8f6, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_372) {
  // 445.40958940753753
  s21_decimal dec_1 = {{0x239e6f59, 0x9e3dc4, 0x0, 0xe0000}};
  // 35033758014641
  s21_decimal dec_2 = {{0xeeb39cb1, 0x1fdc, 0x0, 0x0}};
  // 35033758015086.40958940753753
  s21_decimal dec_check = {{0xc724af59, 0xc05e6ad7, 0xb51ecae, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_373) {
  // 6.91973345
  s21_decimal dec_1 = {{0x293eace1, 0x0, 0x0, 0x80000}};
  // -98124873382293063948
  s21_decimal dec_2 = {{0xdc2c90c, 0x51c19474, 0x5, 0x80000000}};
  // -98124873382293063941.08026655
  s21_decimal dec_check = {{0xadf0df1f, 0x7acff96f, 0x1fb4b304, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_374) {
  // -743848968173481993812.08407235
  s21_decimal dec_1 = {{0x2141cc3, 0x7954cb6f, 0xf059be98, 0x80080000}};
  // 17728268501.98395985169610
  s21_decimal dec_2 = {{0xd9758cca, 0x22d8d83a, 0x17769, 0xe0000}};
  // -743848968155753725310.10011250
  s21_decimal dec_check = {{0x63ba8072, 0x60ba72ce, 0xf059be98, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_375) {
  // 1638593343884315594
  s21_decimal dec_1 = {{0xf18b4bca, 0x16bd73f6, 0x0, 0x0}};
  // 33463.62624284
  s21_decimal dec_2 = {{0x22c1691c, 0x30b, 0x0, 0x80000}};
  // 1638593343884349057.62624284
  s21_decimal dec_check = {{0xaaff31c, 0x50f8f021, 0x878a90, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_376) {
  // 628
  s21_decimal dec_1 = {{0x274, 0x0, 0x0, 0x0}};
  // 464159960230217
  s21_decimal dec_2 = {{0xa98c6949, 0x1a626, 0x0, 0x0}};
  // 464159960230845
  s21_decimal dec_check = {{0xa98c6bbd, 0x1a626, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_377) {
  // 5.2
  s21_decimal dec_1 = {{0x34, 0x0, 0x0, 0x10000}};
  // -0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80010000}};
  // 4.6
  s21_decimal dec_check = {{0x2e, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_378) {
  // 336354.8611042295655617191
  s21_decimal dec_1 = {{0xe13ad2a7, 0x55e7c2a8, 0x2c842, 0x130000}};
  // -29775846457.730917390566
  s21_decimal dec_2 = {{0x4892d8e6, 0x26e1021c, 0x64e, 0x800c0000}};
  // -29775510102.869813161000438281
  s21_decimal dec_check = {{0x5fc0a09, 0x5101885, 0x6035b985, 0x80120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_379) {
  // 36180290649409051438847401
  s21_decimal dec_1 = {{0x3cb795a9, 0x7c752226, 0x1ded79, 0x0}};
  // -87657.853423705718213878
  s21_decimal dec_2 = {{0xf63f4cf6, 0xf116e9a5, 0x128f, 0x80120000}};
  // 36180290649409051438759743.147
  s21_decimal dec_check = {{0x27e70eab, 0x298d655d, 0x74e7a28e, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_380) {
  // -961.1193438286006682419036451
  s21_decimal dec_1 = {{0x9bb18123, 0x4c645068, 0x1f0e3160, 0x80190000}};
  // 6540782108838126516158
  s21_decimal dec_2 = {{0x7ee977be, 0x93961170, 0x162, 0x0}};
  // 6540782108838126515196.8806562
  s21_decimal dec_check = {{0x1cd606a2, 0x140bfd39, 0xd35814de, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_381) {
  // -232573408019391087197658286
  s21_decimal dec_1 = {{0x4bb99cae, 0xb63bbda7, 0xc06155, 0x80000000}};
  // 93804387487197666.232
  s21_decimal dec_2 = {{0x33839bb8, 0x15cc216c, 0x5, 0x30000}};
  // -232573407925586699710460619.77
  s21_decimal dec_check = {{0xf5c0d799, 0xad281201, 0x4b26057a, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_382) {
  // -165979826298834174098
  s21_decimal dec_1 = {{0xb70cc092, 0xff6ecc9e, 0x8, 0x80000000}};
  // -57241993305703.51
  s21_decimal dec_2 = {{0x3b8e06f, 0x145621, 0x0, 0x80020000}};
  // -165979883540827479801.51
  s21_decimal dec_check = {{0x84b41977, 0xc75c4420, 0x383, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_383) {
  // -75.0
  s21_decimal dec_1 = {{0x2ee, 0x0, 0x0, 0x80010000}};
  // -7321433024046602128
  s21_decimal dec_2 = {{0x751c9790, 0x659af48b, 0x0, 0x80000000}};
  // -7321433024046602203.0
  s21_decimal dec_check = {{0x931dee8e, 0xf80d8d72, 0x3, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_384) {
  // -99757.9571
  s21_decimal dec_1 = {{0x3b75db33, 0x0, 0x0, 0x80040000}};
  // -8489759028876097284
  s21_decimal dec_2 = {{0x28d33704, 0x75d1aedb, 0x0, 0x80000000}};
  // -8489759028876197041.9571
  s21_decimal dec_check = {{0xf60ae773, 0x4ebe50ea, 0x11fa, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_385) {
  // 811941176207161077.5
  s21_decimal dec_1 = {{0xa7682597, 0x70adf1fa, 0x0, 0x10000}};
  // 3463
  s21_decimal dec_2 = {{0xd87, 0x0, 0x0, 0x0}};
  // 811941176207164540.5
  s21_decimal dec_check = {{0xa768acdd, 0x70adf1fa, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_386) {
  // 9902915340
  s21_decimal dec_1 = {{0x4e427f0c, 0x2, 0x0, 0x0}};
  // 21381291
  s21_decimal dec_2 = {{0x14640ab, 0x0, 0x0, 0x0}};
  // 9924296631
  s21_decimal dec_check = {{0x4f88bfb7, 0x2, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_387) {
  // 196.863099
  s21_decimal dec_1 = {{0xbbbe47b, 0x0, 0x0, 0x60000}};
  // 1.33
  s21_decimal dec_2 = {{0x85, 0x0, 0x0, 0x20000}};
  // 198.193099
  s21_decimal dec_check = {{0xbd02fcb, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_388) {
  // 402173381685578
  s21_decimal dec_1 = {{0x498db14a, 0x16dc6, 0x0, 0x0}};
  // -57842585932885385514964636
  s21_decimal dec_2 = {{0x5a89d69c, 0xddd4f491, 0x2fd8a4, 0x80000000}};
  // -57842585932483212133279058
  s21_decimal dec_check = {{0x10fc2552, 0xddd386cb, 0x2fd8a4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_389) {
  // -458
  s21_decimal dec_1 = {{0x1ca, 0x0, 0x0, 0x80000000}};
  // 1188425057658686559586
  s21_decimal dec_2 = {{0xf225562, 0x6cb5f565, 0x40, 0x0}};
  // 1188425057658686559128
  s21_decimal dec_check = {{0xf225398, 0x6cb5f565, 0x40, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_390) {
  // 877392341762689245363443.86933
  s21_decimal dec_1 = {{0x12319d75, 0x4e67027c, 0x1b803187, 0x50000}};
  // 0.3188
  s21_decimal dec_2 = {{0xc74, 0x0, 0x0, 0x40000}};
  // 877392341762689245363444.18813
  s21_decimal dec_check = {{0x123219fd, 0x4e67027c, 0x1b803187, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_391) {
  // -49.697057172509324794384105
  s21_decimal dec_1 = {{0x58b3cee9, 0xde1ce788, 0x291bc2, 0x80180000}};
  // 63976757647023259
  s21_decimal dec_2 = {{0xa96e9c9b, 0xe34a85, 0x0, 0x0}};
  // 63976757647023209.302942827491
  s21_decimal dec_check = {{0x364043e3, 0x795be7d7, 0xceb85565, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_392) {
  // -33122749063890600427370
  s21_decimal dec_1 = {{0x41977f6a, 0x967badc3, 0x703, 0x80000000}};
  // 105952084941.51
  s21_decimal dec_2 = {{0xe3a37c47, 0x9a2, 0x0, 0x20000}};
  // -33122749063784648342428.49
  s21_decimal dec_check = {{0xbb8a4921, 0xc84fd6a2, 0x2bd66, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_393) {
  // -838279738680804038.553907
  s21_decimal dec_1 = {{0x3cda3133, 0x3c5645c9, 0xb183, 0x80060000}};
  // -18996934299950
  s21_decimal dec_2 = {{0x1185512e, 0x1147, 0x0, 0x80000000}};
  // -838298735615103988.553907
  s21_decimal dec_check = {{0xbece58b3, 0x43f8f0e1, 0xb184, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_394) {
  // -91402660.73
  s21_decimal dec_1 = {{0x20cd6459, 0x2, 0x0, 0x80020000}};
  // 5812764138897
  s21_decimal dec_2 = {{0x63bddd91, 0x549, 0x0, 0x0}};
  // 5812672736236.27
  s21_decimal dec_check = {{0xd55d284b, 0x210a8, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_395) {
  // 1802589939741445280211762710
  s21_decimal dec_1 = {{0x4f557e16, 0x703b9a75, 0x5d31144, 0x0}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // 1802589939741445280211762710.4
  s21_decimal dec_check = {{0x1956ece0, 0x62540895, 0x3a3eacac, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_396) {
  // 201234584932.62736
  s21_decimal dec_1 = {{0xcb24ab90, 0x477e2d, 0x0, 0x50000}};
  // 6827654929521669081
  s21_decimal dec_2 = {{0xe31573d9, 0x5ec0b3fb, 0x0, 0x0}};
  // 6827655130756254013.62736
  s21_decimal dec_check = {{0x6709a930, 0xcae9b78e, 0x9094, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_397) {
  // 8059732296575.7291667808
  s21_decimal dec_1 = {{0x14302160, 0x308bc670, 0x1111, 0xa0000}};
  // -7150.491
  s21_decimal dec_2 = {{0x6d1b9b, 0x0, 0x0, 0x80030000}};
  // 8059732289425.2381667808
  s21_decimal dec_check = {{0x8b6d81e0, 0x308b8567, 0x1111, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_398) {
  // -481151144.773212685839138738
  s21_decimal dec_1 = {{0x4ce47fb2, 0xd2a65017, 0x18dffb7, 0x80120000}};
  // 6609440599515840
  s21_decimal dec_2 = {{0x4f1922c0, 0x177b40, 0x0, 0x0}};
  // 6609440118364695.2267873141609
  s21_decimal dec_check = {{0x40524369, 0x9f368bfc, 0xd59001db, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_399) {
  // -554234.309802768
  s21_decimal dec_1 = {{0xbb287b10, 0x1f812, 0x0, 0x80090000}};
  // 612295244823139916675.43743768
  s21_decimal dec_2 = {{0x35289d18, 0x32ef141b, 0xc5d7e025, 0x80000}};
  // 612295244823139362441.12763491
  s21_decimal dec_check = {{0xef3e2a63, 0x32eee1b2, 0xc5d7e025, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_400) {
  // 22265981
  s21_decimal dec_1 = {{0x153c07d, 0x0, 0x0, 0x0}};
  // -0.0413007971228134376230747
  s21_decimal dec_2 = {{0x65384f5b, 0x34fcd5f9, 0x5775, 0x80190000}};
  // 22265980.958699202877186562377
  s21_decimal dec_check = {{0x2e5ad949, 0x65aa264c, 0x47f1fcde, 0x150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_401) {
  // 330
  s21_decimal dec_1 = {{0x14a, 0x0, 0x0, 0x0}};
  // 26.24426
  s21_decimal dec_2 = {{0x280baa, 0x0, 0x0, 0x50000}};
  // 356.24426
  s21_decimal dec_check = {{0x21f95ea, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_402) {
  // -27363382292514723.65815
  s21_decimal dec_1 = {{0x4f6818f7, 0x565241c3, 0x94, 0x80050000}};
  // 185160446911914
  s21_decimal dec_2 = {{0x6aa25aa, 0xa867, 0x0, 0x0}};
  // -27178221845602809.65815
  s21_decimal dec_check = {{0xefaf92b7, 0x555c0d37, 0x93, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_403) {
  // 6.3248502
  s21_decimal dec_1 = {{0x3c51876, 0x0, 0x0, 0x70000}};
  // -8104536292890.17726791
  s21_decimal dec_2 = {{0xfa055747, 0xef4db1de, 0x2b, 0x80080000}};
  // -8104536292883.85241771
  s21_decimal dec_check = {{0xd45262ab, 0xef4db1de, 0x2b, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_404) {
  // -786158251319
  s21_decimal dec_1 = {{0xaaeed37, 0xb7, 0x0, 0x80000000}};
  // 80087727570966651223
  s21_decimal dec_2 = {{0x1fb9a157, 0x5770c3e7, 0x4, 0x0}};
  // 80087726784808399904
  s21_decimal dec_check = {{0x150ab420, 0x5770c330, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_405) {
  // -25044675956132
  s21_decimal dec_1 = {{0x2b038da4, 0x16c7, 0x0, 0x80000000}};
  // -0.849
  s21_decimal dec_2 = {{0x351, 0x0, 0x0, 0x80030000}};
  // -25044675956132.849
  s21_decimal dec_check = {{0x5e14bf1, 0x58fa00, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_406) {
  // -0.02632
  s21_decimal dec_1 = {{0xa48, 0x0, 0x0, 0x80050000}};
  // 0.9778818421100
  s21_decimal dec_2 = {{0xceff916c, 0x8e4, 0x0, 0xd0000}};
  // 0.9515618421100
  s21_decimal dec_check = {{0x870e496c, 0x8a7, 0x0, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_407) {
  // -3793527.7747
  s21_decimal dec_1 = {{0xd51e66b3, 0x8, 0x0, 0x80040000}};
  // 160327137
  s21_decimal dec_2 = {{0x98e65e1, 0x0, 0x0, 0x0}};
  // 156533609.2253
  s21_decimal dec_check = {{0x754d3e5d, 0x16c, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_408) {
  // 84933414
  s21_decimal dec_1 = {{0x50ffb26, 0x0, 0x0, 0x0}};
  // -99898534667920022008408
  s21_decimal dec_2 = {{0x3a5d7258, 0x82aa9b5a, 0x1527, 0x80000000}};
  // -99898534667919937074994
  s21_decimal dec_check = {{0x354d7732, 0x82aa9b5a, 0x1527, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_409) {
  // 6307237
  s21_decimal dec_1 = {{0x603da5, 0x0, 0x0, 0x0}};
  // 878936962
  s21_decimal dec_2 = {{0x34638382, 0x0, 0x0, 0x0}};
  // 885244199
  s21_decimal dec_check = {{0x34c3c127, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_410) {
  // 71.687691135485052616524128519
  s21_decimal dec_1 = {{0x7fe76107, 0x7a672935, 0xe7a2ab13, 0x1b0000}};
  // 28107405866071
  s21_decimal dec_2 = {{0x43f13457, 0x1990, 0x0, 0x0}};
  // 28107405866142.687691135485053
  s21_decimal dec_check = {{0x165b847d, 0x26729174, 0x5ad1e6b5, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_411) {
  // -560401641243220238
  s21_decimal dec_1 = {{0xd5d9190e, 0x7c6f252, 0x0, 0x80000000}};
  // -61002106503546528.848
  s21_decimal dec_2 = {{0x766fe450, 0x4e9304a9, 0x3, 0x80030000}};
  // -621403747746766766.848
  s21_decimal dec_check = {{0xce79c300, 0xafb5983c, 0x21, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_412) {
  // 6.5
  s21_decimal dec_1 = {{0x41, 0x0, 0x0, 0x10000}};
  // 176735159
  s21_decimal dec_2 = {{0xa88c3b7, 0x0, 0x0, 0x0}};
  // 176735165.5
  s21_decimal dec_check = {{0x6957a567, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_413) {
  // -268224860566804301206711
  s21_decimal dec_1 = {{0x7addd4b7, 0x7fb3214a, 0x38cc, 0x80000000}};
  // 571.81513239667
  s21_decimal dec_2 = {{0x9bc8cc73, 0x3401, 0x0, 0xb0000}};
  // -268224860566804301206139.18487
  s21_decimal dec_check = {{0xb94b3717, 0xb4ac45ba, 0x56ab0a5a, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_414) {
  // -1.67449930932054682619
  s21_decimal dec_1 = {{0xb4d06bfb, 0x13d5a8fe, 0x9, 0x80140000}};
  // -36573825658265195451469187
  s21_decimal dec_2 = {{0x88474d83, 0xfce2ef9, 0x1e40cf, 0x80000000}};
  // -36573825658265195451469188.674
  s21_decimal dec_check = {{0x5686ce42, 0xbd677ebc, 0x762d28d5, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_415) {
  // 714355000
  s21_decimal dec_1 = {{0x2a943138, 0x0, 0x0, 0x0}};
  // 187867558586958264779194
  s21_decimal dec_2 = {{0x8e15c1ba, 0x521d31da, 0x27c8, 0x0}};
  // 187867558586958979134194
  s21_decimal dec_check = {{0xb8a9f2f2, 0x521d31da, 0x27c8, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_416) {
  // 2029926637705.8163641151
  s21_decimal dec_1 = {{0xce744b3f, 0x6ce953cf, 0x44c, 0xa0000}};
  // 35.49754255
  s21_decimal dec_2 = {{0xd394f38f, 0x0, 0x0, 0x80000}};
  // 2029926637741.3139066651
  s21_decimal dec_check = {{0x74a36f1b, 0x6ce95422, 0x44c, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_417) {
  // -99678983057205303.63
  s21_decimal dec_1 = {{0x65b0b5bb, 0x8a5516b2, 0x0, 0x80020000}};
  // -64
  s21_decimal dec_2 = {{0x40, 0x0, 0x0, 0x80000000}};
  // -99678983057205367.63
  s21_decimal dec_check = {{0x65b0cebb, 0x8a5516b2, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_418) {
  // 962640393631288914
  s21_decimal dec_1 = {{0x74d5ce52, 0xd5bfc56, 0x0, 0x0}};
  // -53818258.7
  s21_decimal dec_2 = {{0x201403bb, 0x0, 0x0, 0x80010000}};
  // 962640393577470655.3
  s21_decimal dec_check = {{0x70460b79, 0x8597db60, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_419) {
  // 0.5703779
  s21_decimal dec_1 = {{0x570863, 0x0, 0x0, 0x70000}};
  // -75526914610.79
  s21_decimal dec_2 = {{0x7f7ddbd7, 0x6de, 0x0, 0x80020000}};
  // -75526914610.2196221
  s21_decimal dec_check = {{0x6b3be7fd, 0xa7b4149, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_420) {
  // 632372015413
  s21_decimal dec_1 = {{0x3c4f3135, 0x93, 0x0, 0x0}};
  // -449145186213223732.6005
  s21_decimal dec_2 = {{0x9ec0d6b5, 0x7b6a77e0, 0xf3, 0x80040000}};
  // -449144553841208319.6005
  s21_decimal dec_check = {{0xc94eb065, 0x7b54007c, 0xf3, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_421) {
  // 3909844144954830
  s21_decimal dec_1 = {{0x87631dce, 0xde3fb, 0x0, 0x0}};
  // 477854910292879606
  s21_decimal dec_2 = {{0x562ee8f6, 0x6a1ae82, 0x0, 0x0}};
  // 481764754437834436
  s21_decimal dec_check = {{0xdd9206c4, 0x6af927d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_422) {
  // 72.259792520908960008
  s21_decimal dec_1 = {{0xf034f108, 0xeace5a72, 0x3, 0x120000}};
  // -2477944957331661101482342
  s21_decimal dec_2 = {{0x2b104166, 0xaa513a17, 0x20cb9, 0x80000000}};
  // -2477944957331661101482269.7402
  s21_decimal dec_check = {{0x2aef99ba, 0x4ed2902, 0x5011148d, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_423) {
  // 5232574990828592
  s21_decimal dec_1 = {{0xcd96c430, 0x1296ff, 0x0, 0x0}};
  // -2665.46
  s21_decimal dec_2 = {{0x41132, 0x0, 0x0, 0x80020000}};
  // 5232574990825926.54
  s21_decimal dec_check = {{0x4ee0918e, 0x742fbec, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_424) {
  // -3.4
  s21_decimal dec_1 = {{0x22, 0x0, 0x0, 0x80010000}};
  // -60980381.4058
  s21_decimal dec_2 = {{0xfb23c4aa, 0x8d, 0x0, 0x80040000}};
  // -60980384.8058
  s21_decimal dec_check = {{0xfb24497a, 0x8d, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_425) {
  // -743695404123912
  s21_decimal dec_1 = {{0x14624708, 0x2a463, 0x0, 0x80000000}};
  // -57667280797628008685269
  s21_decimal dec_2 = {{0x2a66ded5, 0x26494f18, 0xc36, 0x80000000}};
  // -57667281541323412809181
  s21_decimal dec_check = {{0x3ec925dd, 0x264bf37b, 0xc36, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_426) {
  // 752919764769908385
  s21_decimal dec_1 = {{0x737b26a1, 0xa72e889, 0x0, 0x0}};
  // -766353963064611880106140
  s21_decimal dec_2 = {{0x6a80f89c, 0x21af61f3, 0xa248, 0x80000000}};
  // -766353210144847110197755
  s21_decimal dec_check = {{0xf705d1fb, 0x173c7969, 0xa248, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_428) {
  // -29081232.2824
  s21_decimal dec_1 = {{0xb5c3e408, 0x43, 0x0, 0x80040000}};
  // 9.0164562
  s21_decimal dec_2 = {{0x55fcd52, 0x0, 0x0, 0x70000}};
  // -29081223.2659438
  s21_decimal dec_check = {{0xffd2f1ee, 0x1087d, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_429) {
  // 9126596
  s21_decimal dec_1 = {{0x8b42c4, 0x0, 0x0, 0x0}};
  // -15328317592838169879350129024
  s21_decimal dec_2 = {{0x2378b180, 0xbc328890, 0x31874981, 0x80000000}};
  // -15328317592838169879341002428
  s21_decimal dec_check = {{0x22ed6ebc, 0xbc328890, 0x31874981, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_430) {
  // 26453956248
  s21_decimal dec_1 = {{0x28c75698, 0x6, 0x0, 0x0}};
  // -86783808593616190.4616315938
  s21_decimal dec_2 = {{0x67dc9c22, 0xe8297270, 0x2cddbdc, 0x800a0000}};
  // -86783782139659942.4616315938
  s21_decimal dec_check = {{0x46353c22, 0x90f01ff4, 0x2cddbce, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_431) {
  // 191641617027691942797.9217719
  s21_decimal dec_1 = {{0x90830b37, 0xc2914818, 0x63138e8, 0x70000}};
  // 6416598743765859353743
  s21_decimal dec_2 = {{0x9dc6c48f, 0xd83220db, 0x15b, 0x0}};
  // 6608240360793551296540.9217719
  s21_decimal dec_check = {{0x9ff91cb7, 0xbd48125e, 0xd5861545, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_432) {
  // 6869921501329189960941070.0
  s21_decimal dec_1 = {{0xc277ec8c, 0xe8849430, 0x38d39f, 0x10000}};
  // -17464279
  s21_decimal dec_2 = {{0x10a7bd7, 0x0, 0x0, 0x80000000}};
  // 6869921501329189943476791.0
  s21_decimal dec_check = {{0xb80f1626, 0xe8849430, 0x38d39f, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_433) {
  // 0.03220102533654
  s21_decimal dec_1 = {{0xbd115216, 0x2ed, 0x0, 0xe0000}};
  // -8246487213
  s21_decimal dec_2 = {{0xeb8768ad, 0x1, 0x0, 0x80000000}};
  // -8246487212.96779897466346
  s21_decimal dec_check = {{0xcf8bedea, 0x4bf85b3d, 0xaea0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_434) {
  // -68853149776937275573187
  s21_decimal dec_1 = {{0x988f43c3, 0x89670a80, 0xe94, 0x80000000}};
  // 795
  s21_decimal dec_2 = {{0x31b, 0x0, 0x0, 0x0}};
  // -68853149776937275572392
  s21_decimal dec_check = {{0x988f40a8, 0x89670a80, 0xe94, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_435) {
  // -5814295488876
  s21_decimal dec_1 = {{0xbf04696c, 0x549, 0x0, 0x80000000}};
  // -4030418962113.950
  s21_decimal dec_2 = {{0xa88659e, 0xe51a5, 0x0, 0x80030000}};
  // -9844714450989.950
  s21_decimal dec_check = {{0x33c4337e, 0x22f9b7, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_436) {
  // 599683581716954585353
  s21_decimal dec_1 = {{0xd1039909, 0x8248104f, 0x20, 0x0}};
  // -20483.315250
  s21_decimal dec_2 = {{0xc4e69632, 0x4, 0x0, 0x80060000}};
  // 599683581716954564869.684750
  s21_decimal dec_check = {{0x60fafe0e, 0x1ae5e708, 0x1f00bf0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_437) {
  // 8159876
  s21_decimal dec_1 = {{0x7c8284, 0x0, 0x0, 0x0}};
  // -78340052
  s21_decimal dec_2 = {{0x4ab5fd4, 0x0, 0x0, 0x80000000}};
  // -70180176
  s21_decimal dec_check = {{0x42edd50, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_438) {
  // 66.14925211
  s21_decimal dec_1 = {{0x8a47bf9b, 0x1, 0x0, 0x80000}};
  // -56038276
  s21_decimal dec_2 = {{0x3571384, 0x0, 0x0, 0x80000000}};
  // -56038209.85074789
  s21_decimal dec_check = {{0x3f334465, 0x13e8a5, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_440) {
  // 560920144885273024217422
  s21_decimal dec_1 = {{0xed2b414e, 0x8abf72db, 0x76c7, 0x0}};
  // 7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x0}};
  // 560920144885273024217429
  s21_decimal dec_check = {{0xed2b4155, 0x8abf72db, 0x76c7, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_441) {
  // -3.517
  s21_decimal dec_1 = {{0xdbd, 0x0, 0x0, 0x80030000}};
  // 9457768.09762
  s21_decimal dec_2 = {{0x34b0d722, 0xdc, 0x0, 0x50000}};
  // 9457764.58062
  s21_decimal dec_check = {{0x34ab794e, 0xdc, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_442) {
  // 72676325645.2138995
  s21_decimal dec_1 = {{0xc8a2c7f3, 0xa15fb54, 0x0, 0x70000}};
  // -9.0455558953823915885
  s21_decimal dec_2 = {{0x4a144f6d, 0xe752b39d, 0x4, 0x80130000}};
  // 72676325636.168343604617608412
  s21_decimal dec_check = {{0xb300fcdc, 0x265ecac3, 0xead47293, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_443) {
  // -4211684813.05750242570
  s21_decimal dec_1 = {{0x23fd850a, 0xd4e3064d, 0x16, 0x800b0000}};
  // 34303021
  s21_decimal dec_2 = {{0x20b6c2d, 0x0, 0x0, 0x0}};
  // -4177381792.05750242570
  s21_decimal dec_check = {{0x4536bd0a, 0xa54824b7, 0x16, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_444) {
  // -458719896242346
  s21_decimal dec_1 = {{0xc7788aa, 0x1a134, 0x0, 0x80000000}};
  // 453300734.46
  s21_decimal dec_2 = {{0x8de20766, 0xa, 0x0, 0x20000}};
  // -458719442941611.54
  s21_decimal dec_check = {{0x50cf5b02, 0xa2f84a, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_445) {
  // -977.9164
  s21_decimal dec_1 = {{0x9537dc, 0x0, 0x0, 0x80040000}};
  // -8148274386633801997
  s21_decimal dec_2 = {{0x1bb8c10d, 0x71147c62, 0x0, 0x80000000}};
  // -8148274386633802974.9164
  s21_decimal dec_check = {{0xe18a43ac, 0x303ab85a, 0x1141, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_446) {
  // 73850
  s21_decimal dec_1 = {{0x1207a, 0x0, 0x0, 0x0}};
  // 55609804594.738489557525000606
  s21_decimal dec_2 = {{0x7024f19e, 0xa7ce6102, 0xb3af5a2b, 0x120000}};
  // 55609878444.738489557525000606
  s21_decimal dec_check = {{0xb5ccf19e, 0x126f8ef0, 0xb3af69cf, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_447) {
  // -4670
  s21_decimal dec_1 = {{0x123e, 0x0, 0x0, 0x80000000}};
  // -0.61
  s21_decimal dec_2 = {{0x3d, 0x0, 0x0, 0x80020000}};
  // -4670.61
  s21_decimal dec_check = {{0x72075, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_448) {
  // 4544313.20295116499
  s21_decimal dec_1 = {{0xcd008ed3, 0x64e76e0, 0x0, 0xb0000}};
  // -914471710734
  s21_decimal dec_2 = {{0xeac2f00e, 0xd4, 0x0, 0x80000000}};
  // -914467166420.79704883501
  s21_decimal dec_check = {{0x7300212d, 0x56211880, 0x135d, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_449) {
  // 70
  s21_decimal dec_1 = {{0x46, 0x0, 0x0, 0x0}};
  // 35817102
  s21_decimal dec_2 = {{0x222868e, 0x0, 0x0, 0x0}};
  // 35817172
  s21_decimal dec_check = {{0x22286d4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_450) {
  // -4162089523901029943.3784823587
  s21_decimal dec_1 = {{0x77ddcf23, 0xf2428909, 0x867bff63, 0x800a0000}};
  // 806.047
  s21_decimal dec_2 = {{0xc4c9f, 0x0, 0x0, 0x30000}};
  // -4162089523901029137.3314823587
  s21_decimal dec_check = {{0xbe6a55a3, 0xf24281b4, 0x867bff63, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_452) {
  // -800.6386239771494
  s21_decimal dec_1 = {{0xfc19366, 0x1c71c4, 0x0, 0x800d0000}};
  // -484.9830726581040209
  s21_decimal dec_2 = {{0xaea33451, 0x434e0f59, 0x0, 0x80100000}};
  // -1285.6216966352534209
  s21_decimal dec_check = {{0x3acafac1, 0xb26a7537, 0x0, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_454) {
  // 36033760424327274022127293
  s21_decimal dec_1 = {{0x9c1946bd, 0x111620ad, 0x1dce72, 0x0}};
  // -673995333695308158539106
  s21_decimal dec_2 = {{0x3e4d1562, 0x5c39778f, 0x8eb9, 0x80000000}};
  // 35359765090631965863588187
  s21_decimal dec_check = {{0x5dcc315b, 0xb4dca91e, 0x1d3fb8, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_455) {
  // -10969648821468.865482
  s21_decimal dec_1 = {{0xc26f23ca, 0x983c057b, 0x0, 0x80060000}};
  // 6022981.0536104610160310
  s21_decimal dec_2 = {{0xdadedeb6, 0x1087c35f, 0xcc1, 0x100000}};
  // -10969642798487.811871538983969
  s21_decimal dec_check = {{0x9844b421, 0xacef0e63, 0x2371e037, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_456) {
  // 194861070822782
  s21_decimal dec_1 = {{0xa0e82d7e, 0xb139, 0x0, 0x0}};
  // 5257.6
  s21_decimal dec_2 = {{0xcd60, 0x0, 0x0, 0x10000}};
  // 194861070828039.6
  s21_decimal dec_check = {{0x4912944c, 0x6ec40, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_457) {
  // 553562377.9623099477
  s21_decimal dec_1 = {{0xa2a3dc55, 0x4cd27c7f, 0x0, 0xa0000}};
  // 56.7731930704
  s21_decimal dec_2 = {{0x2f75c650, 0x84, 0x0, 0xa0000}};
  // 553562434.7355030181
  s21_decimal dec_check = {{0xd219a2a5, 0x4cd27d03, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_458) {
  // -35453109086437958
  s21_decimal dec_1 = {{0x3547c246, 0x7df46a, 0x0, 0x80000000}};
  // 83167976.90196976900
  s21_decimal dec_2 = {{0x58fae504, 0x736b336f, 0x0, 0xb0000}};
  // -35453109003269981.09803023100
  s21_decimal dec_check = {{0xeb588afc, 0x3783eda, 0xb749cc9, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_459) {
  // -1457831461.9427765178684
  s21_decimal dec_1 = {{0xfbe9513c, 0x4ac1c325, 0x316, 0x800d0000}};
  // -49869927098.65109
  s21_decimal dec_2 = {{0xb8f80e95, 0x11b7a4, 0x0, 0x80050000}};
  // -51327758560.5938665178684
  s21_decimal dec_check = {{0xde53463c, 0xd56b6766, 0x6cb0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_461) {
  // 551730
  s21_decimal dec_1 = {{0x86b32, 0x0, 0x0, 0x0}};
  // -4336210965510
  s21_decimal dec_2 = {{0x9a507406, 0x3f1, 0x0, 0x80000000}};
  // -4336210413780
  s21_decimal dec_check = {{0x9a4808d4, 0x3f1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_463) {
  // 35082.9837
  s21_decimal dec_1 = {{0x14e93d0d, 0x0, 0x0, 0x40000}};
  // 50868
  s21_decimal dec_2 = {{0xc6b4, 0x0, 0x0, 0x0}};
  // 85950.9837
  s21_decimal dec_check = {{0x333b144d, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_464) {
  // -6221459495906816002797661086
  s21_decimal dec_1 = {{0xdba0eb9e, 0x131b6a11, 0x141a454b, 0x80000000}};
  // 14032623.43757243
  s21_decimal dec_2 = {{0x7986bdbb, 0x4fc42, 0x0, 0x80000}};
  // -6221459495906816002783628462.6
  s21_decimal dec_check = {{0x8bebfed2, 0xbf1224b2, 0xc906b4ee, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_465) {
  // -894075675689290
  s21_decimal dec_1 = {{0x370d414a, 0x32d28, 0x0, 0x80000000}};
  // -7271397520313
  s21_decimal dec_2 = {{0x110f3b9, 0x69d, 0x0, 0x80000000}};
  // -901347073209603
  s21_decimal dec_check = {{0x381e3503, 0x333c5, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_467) {
  // -31614086384410
  s21_decimal dec_1 = {{0xba638b1a, 0x1cc0, 0x0, 0x80000000}};
  // -5597
  s21_decimal dec_2 = {{0x15dd, 0x0, 0x0, 0x80000000}};
  // -31614086390007
  s21_decimal dec_check = {{0xba63a0f7, 0x1cc0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_468) {
  // 4371501298513885074457666133
  s21_decimal dec_1 = {{0x22f4a255, 0x3e5c6e72, 0xe200568, 0x0}};
  // 2929.949321
  s21_decimal dec_2 = {{0xaea37a89, 0x0, 0x0, 0x60000}};
  // 4371501298513885074457669062.9
  s21_decimal dec_check = {{0x5d8ec9c5, 0x6f9c5075, 0x8d403612, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_469) {
  // -3.8097737626
  s21_decimal dec_1 = {{0xdecd579a, 0x8, 0x0, 0x800a0000}};
  // 2644681687321300341
  s21_decimal dec_2 = {{0x84c44d75, 0x24b3cbfb, 0x0, 0x0}};
  // 2644681687321300337.1902262374
  s21_decimal dec_check = {{0xae35dc66, 0x7693baf9, 0x55744b4f, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_470) {
  // 2604664712977660420159693
  s21_decimal dec_1 = {{0x4501f8cd, 0x28327c16, 0x2278f, 0x0}};
  // -929273955261844305234
  s21_decimal dec_2 = {{0x64783552, 0x60444ace, 0x32, 0x80000000}};
  // 2603735439022398575854459
  s21_decimal dec_check = {{0xe089c37b, 0xc7ee3147, 0x2275c, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_471) {
  // 23047499.474341
  s21_decimal dec_1 = {{0x2a04e5a5, 0x14f6, 0x0, 0x60000}};
  // 2542700000404229206311
  s21_decimal dec_2 = {{0xcfae3127, 0xd70d1290, 0x89, 0x0}};
  // 2542700000404252253810.474341
  s21_decimal dec_check = {{0xdf863d65, 0x388a39e9, 0x83745ab, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_472) {
  // -19
  s21_decimal dec_1 = {{0x13, 0x0, 0x0, 0x80000000}};
  // -92228905094.81324
  s21_decimal dec_2 = {{0x889eb56c, 0x20c42b, 0x0, 0x80050000}};
  // -92228905113.81324
  s21_decimal dec_check = {{0x88bbb34c, 0x20c42b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_473) {
  // -335930329192621085703371560
  s21_decimal dec_1 = {{0xed5d7b28, 0xa2be9485, 0x115e003, 0x80000000}};
  // -628263431
  s21_decimal dec_2 = {{0x25728a07, 0x0, 0x0, 0x80000000}};
  // -335930329192621086331634991
  s21_decimal dec_check = {{0x12d0052f, 0xa2be9486, 0x115e003, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_474) {
  // -627
  s21_decimal dec_1 = {{0x273, 0x0, 0x0, 0x80000000}};
  // 292398997.01
  s21_decimal dec_2 = {{0xced57635, 0x6, 0x0, 0x20000}};
  // 292398370.01
  s21_decimal dec_check = {{0xced48149, 0x6, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_475) {
  // 7274
  s21_decimal dec_1 = {{0x1c6a, 0x0, 0x0, 0x0}};
  // -4820933333718728060968
  s21_decimal dec_2 = {{0x207e3028, 0x57e3cc9e, 0x105, 0x80000000}};
  // -4820933333718728053694
  s21_decimal dec_check = {{0x207e13be, 0x57e3cc9e, 0x105, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_476) {
  // 313976908765053961134239
  s21_decimal dec_1 = {{0xd084609f, 0xb8ea98db, 0x427c, 0x0}};
  // -288.2285302496842668
  s21_decimal dec_2 = {{0x2ca753ac, 0x27ffef36, 0x0, 0x80100000}};
  // 313976908765053961133950.77147
  s21_decimal dec_check = {{0xfc36d01b, 0xf77e690b, 0x65738fa8, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_477) {
  // -1506235068773679
  s21_decimal dec_1 = {{0xae38f52f, 0x559e9, 0x0, 0x80000000}};
  // -6759626508357482217161677
  s21_decimal dec_2 = {{0xef5f43cd, 0x1657d2f7, 0x59768, 0x80000000}};
  // -6759626509863717285935356
  s21_decimal dec_check = {{0x9d9838fc, 0x165d2ce1, 0x59768, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_478) {
  // -86431076152532545199302
  s21_decimal dec_1 = {{0xc6365cc6, 0x70228542, 0x124d, 0x80000000}};
  // -3118788276299935991.5
  s21_decimal dec_2 = {{0xe91ae9ab, 0xb0d19e21, 0x1, 0x80010000}};
  // -86434194940808845135293.5
  s21_decimal dec_check = {{0xa73a8967, 0x122ad2bd, 0xb708, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_479) {
  // -39747718.685167686588397194260
  s21_decimal dec_1 = {{0xbd570c14, 0x7d758069, 0x806e8ad3, 0x80150000}};
  // 361340963397.2945702631481813
  s21_decimal dec_2 = {{0xfffba1d5, 0xc2fd3208, 0xbacf140, 0x100000}};
  // 361301215678.60940257655978411
  s21_decimal dec_check = {{0xb086f9ab, 0xcd509044, 0x74be22d6, 0x110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_480) {
  // 58901140277617625773
  s21_decimal dec_1 = {{0xc8da0aad, 0x316ae302, 0x3, 0x0}};
  // 6334.133
  s21_decimal dec_2 = {{0x60a6b5, 0x0, 0x0, 0x30000}};
  // 58901140277617632107.133
  s21_decimal dec_check = {{0x941a5a7d, 0x986c2e0, 0xc79, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_481) {
  // 52
  s21_decimal dec_1 = {{0x34, 0x0, 0x0, 0x0}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // 58
  s21_decimal dec_check = {{0x3a, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_482) {
  // -77955454
  s21_decimal dec_1 = {{0x4a5817e, 0x0, 0x0, 0x80000000}};
  // 768219196314096.71821232405
  s21_decimal dec_2 = {{0xf7c28915, 0x9ba238cc, 0x3f8bac, 0xb0000}};
  // 768219118358642.71821232405
  s21_decimal dec_check = {{0xda545915, 0x2f72e18f, 0x3f8bac, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_483) {
  // 22045861554186185465465
  s21_decimal dec_1 = {{0x44a9de79, 0x1bc9e78d, 0x4ab, 0x0}};
  // 1191897843666787179999
  s21_decimal dec_2 = {{0x98eb1ddf, 0x9ce7c5de, 0x40, 0x0}};
  // 23237759397852972645464
  s21_decimal dec_check = {{0xdd94fc58, 0xb8b1ad6b, 0x4eb, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_484) {
  // 60526484478925
  s21_decimal dec_1 = {{0x6b9b5bcd, 0x370c, 0x0, 0x0}};
  // -944.44356783
  s21_decimal dec_2 = {{0xfd5284af, 0x15, 0x0, 0x80080000}};
  // 60526484477980.55643217
  s21_decimal dec_check = {{0x6a8da851, 0x1d5eeef7, 0x148, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_485) {
  // 743280.76519
  s21_decimal dec_1 = {{0x4e4c70e7, 0x11, 0x0, 0x50000}};
  // -240246312462
  s21_decimal dec_2 = {{0xefcbce0e, 0x37, 0x0, 0x80000000}};
  // -240245569181.23481
  s21_decimal dec_check = {{0xcfdabd9, 0x555a35, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_486) {
  // -30517889382706789568540030
  s21_decimal dec_1 = {{0xe6c0ed7e, 0x1932101f, 0x193e6a, 0x80000000}};
  // -866.29863411371589
  s21_decimal dec_2 = {{0xdb934e45, 0x133c566, 0x0, 0x800e0000}};
  // -30517889382706789568540896.299
  s21_decimal dec_check = {{0x61acec2b, 0x6b8efc9d, 0x629bce72, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_487) {
  // -63135345075280368
  s21_decimal dec_1 = {{0x7fbd9f0, 0xe04d43, 0x0, 0x80000000}};
  // -77
  s21_decimal dec_2 = {{0x4d, 0x0, 0x0, 0x80000000}};
  // -63135345075280445
  s21_decimal dec_check = {{0x7fbda3d, 0xe04d43, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_488) {
  // 162166651218389
  s21_decimal dec_1 = {{0x5da3e9d5, 0x937d, 0x0, 0x0}};
  // 79802933473034182.141
  s21_decimal dec_2 = {{0xfe551dfd, 0x537cf92d, 0x4, 0x30000}};
  // 79965100124252571.141
  s21_decimal dec_check = {{0xc69e8605, 0x55bd1ae3, 0x4, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_489) {
  // -80158195653382994700693
  s21_decimal dec_1 = {{0xfa38a995, 0x626e2a6d, 0x10f9, 0x80000000}};
  // -32962502517448070994
  s21_decimal dec_2 = {{0x94695752, 0xc9725565, 0x1, 0x80000000}};
  // -80191158155900442771687
  s21_decimal dec_check = {{0x8ea200e7, 0x2be07fd3, 0x10fb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_490) {
  // -197534320795277965220
  s21_decimal dec_1 = {{0x7e99b7a4, 0xb556e22e, 0xa, 0x80000000}};
  // -350782213062.905
  s21_decimal dec_2 = {{0xd93400f9, 0x13f08, 0x0, 0x80030000}};
  // -197534321146060178282.905
  s21_decimal dec_check = {{0x61a95999, 0x5b64c4a7, 0x29d4, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_491) {
  // -400750511184124.460
  s21_decimal dec_1 = {{0x76af9a2c, 0x58fc077, 0x0, 0x80030000}};
  // -5378162268791.69809857116734
  s21_decimal dec_2 = {{0xd30ffa3e, 0x143a800e, 0x1bcdf04, 0x800e0000}};
  // -406128673452916.15809857116734
  s21_decimal dec_check = {{0x670fda3e, 0x54dfb5df, 0x833a2d2e, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_492) {
  // -33921179095859045718
  s21_decimal dec_1 = {{0x6315a556, 0xd6c03caa, 0x1, 0x80000000}};
  // 93163075665304855742068067
  s21_decimal dec_2 = {{0x11053563, 0x739b4130, 0x4d100c, 0x0}};
  // 93163041744125759883022349
  s21_decimal dec_check = {{0xadef900d, 0x9cdb0485, 0x4d100a, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_493) {
  // -706
  s21_decimal dec_1 = {{0x2c2, 0x0, 0x0, 0x80000000}};
  // 10082316193379201345071
  s21_decimal dec_2 = {{0x4fe8662f, 0x903ea77a, 0x222, 0x0}};
  // 10082316193379201344365
  s21_decimal dec_check = {{0x4fe8636d, 0x903ea77a, 0x222, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_494) {
  // 2133438.468896781549
  s21_decimal dec_1 = {{0xe8bef4ed, 0x1d9b7efb, 0x0, 0xc0000}};
  // 265.592
  s21_decimal dec_2 = {{0x40d78, 0x0, 0x0, 0x30000}};
  // 2133704.060896781549
  s21_decimal dec_check = {{0xdd8fa4ed, 0x1d9c7089, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_495) {
  // -29766430349891
  s21_decimal dec_1 = {{0x8981da43, 0x1b12, 0x0, 0x80000000}};
  // 8189.05657516517
  s21_decimal dec_2 = {{0x54d221e5, 0x2e8ca, 0x0, 0xb0000}};
  // -29766430341701.94342483483
  s21_decimal dec_check = {{0xcbdc961b, 0x24686715, 0x27654, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_496) {
  // -84201563834293194708981058
  s21_decimal dec_1 = {{0x45b39542, 0xebfa7cab, 0x45a65f, 0x80000000}};
  // -94548267155190653
  s21_decimal dec_2 = {{0xe5e9f37d, 0x14fe725, 0x0, 0x80000000}};
  // -84201563928841461864171711
  s21_decimal dec_check = {{0x2b9d88bf, 0xed4a63d1, 0x45a65f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_497) {
  // 7708.8
  s21_decimal dec_1 = {{0x12d20, 0x0, 0x0, 0x10000}};
  // -23.78693445460149437
  s21_decimal dec_2 = {{0xf633c4bd, 0x2102d115, 0x0, 0x80110000}};
  // 7685.01306554539850563
  s21_decimal dec_check = {{0xeeec3b43, 0xa9191a9d, 0x29, 0x110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_498) {
  // 82942955812461418634389
  s21_decimal dec_1 = {{0xdbf7dc95, 0x58bdacd1, 0x1190, 0x0}};
  // -167654956
  s21_decimal dec_2 = {{0x9fe362c, 0x0, 0x0, 0x80000000}};
  // 82942955812461250979433
  s21_decimal dec_check = {{0xd1f9a669, 0x58bdacd1, 0x1190, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_499) {
  // 45039214736994083
  s21_decimal dec_1 = {{0x5b5c6f23, 0xa002ed, 0x0, 0x0}};
  // -34848575784910845792011298
  s21_decimal dec_2 = {{0x3d64c422, 0x1425c4c7, 0x1cd379, 0x80000000}};
  // -34848575739871631055017215
  s21_decimal dec_check = {{0xe20854ff, 0x1385c1d9, 0x1cd379, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_500) {
  // 4717272025.8165672041491370900
  s21_decimal dec_1 = {{0xa7169394, 0x4c36ae3f, 0x986c5c11, 0x130000}};
  // 0.4889926
  s21_decimal dec_2 = {{0x4a9d46, 0x0, 0x0, 0x70000}};
  // 4717272026.3055598041491370900
  s21_decimal dec_check = {{0xa708f394, 0x90133009, 0x986c5c11, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_add_1) {
  // -202675274639644590064819
  s21_decimal dec_1 = {{0x3ff3c4b3, 0xc749121, 0x2aeb, 0x80000000}};
  // -79228162514264337592757167561
  s21_decimal dec_2 = {{0xd11aa5c9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_2) {
  // -56201483090127245652681607
  s21_decimal dec_1 = {{0x73026387, 0x80cf2b8c, 0x2e7d20, 0x80000000}};
  // -79228162514264337592885560739
  s21_decimal dec_2 = {{0xd8c1c5a3, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_3) {
  // 79228162514264337592497703714
  s21_decimal dec_1 = {{0xc1a38b22, 0xffffffff, 0xffffffff, 0x0}};
  // 1536359373961865
  s21_decimal dec_2 = {{0x8abb7a89, 0x5754f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_4) {
  // 61312862022358586
  s21_decimal dec_1 = {{0x2101563a, 0xd9d3b9, 0x0, 0x0}};
  // 79228162514264337591717855519
  s21_decimal dec_2 = {{0x9328011f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_5) {
  // -8351285459468
  s21_decimal dec_1 = {{0x6f673a0c, 0x798, 0x0, 0x80000000}};
  // -79228162514264337592169113732
  s21_decimal dec_2 = {{0xae0da884, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_6) {
  // -79228162514264337592164249246
  s21_decimal dec_1 = {{0xadc36e9e, 0xffffffff, 0xffffffff, 0x80000000}};
  // -15245502623
  s21_decimal dec_2 = {{0x8cb3e89f, 0x3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_7) {
  // -79228162514264337592133584787
  s21_decimal dec_1 = {{0xabef8793, 0xffffffff, 0xffffffff, 0x80000000}};
  // -17426849358434035.86604527
  s21_decimal dec_2 = {{0x281c0def, 0x23c16912, 0x17107, 0x80080000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_8) {
  // 361129410743229733998660477
  s21_decimal dec_1 = {{0xa7478b7d, 0x9574a308, 0x12ab820, 0x0}};
  // 79228162514264337592530149079
  s21_decimal dec_2 = {{0xc3929ed7, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_9) {
  // -79228162514264337592458598169
  s21_decimal dec_1 = {{0xbf4ed719, 0xffffffff, 0xffffffff, 0x80000000}};
  // -6571436936032518616
  s21_decimal dec_2 = {{0x8c1981d8, 0x5b326f13, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_10) {
  // 86540280279278119802
  s21_decimal dec_1 = {{0x691d6b7a, 0xb0fcd667, 0x4, 0x0}};
  // 79228162514264337591653558750
  s21_decimal dec_2 = {{0x8f52e9de, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_11) {
  // 79228162514264337591973940650
  s21_decimal dec_1 = {{0xa26b8daa, 0xffffffff, 0xffffffff, 0x0}};
  // 562165998562979521
  s21_decimal dec_2 = {{0x49262ec1, 0x7cd36ff, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_12) {
  // -1409883000171366
  s21_decimal dec_1 = {{0xf7666b66, 0x50247, 0x0, 0x80000000}};
  // -79228162514264337591980226634
  s21_decimal dec_2 = {{0xa2cb784a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_13) {
  // -31592636314
  s21_decimal dec_1 = {{0x5b115f9a, 0x7, 0x0, 0x80000000}};
  // -79228162514264337593288985867
  s21_decimal dec_2 = {{0xf0cd8d0b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_14) {
  // 1542942134234
  s21_decimal dec_1 = {{0x3e848fda, 0x167, 0x0, 0x0}};
  // 79228162514264337593237045709
  s21_decimal dec_2 = {{0xedb501cd, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_15) {
  // -3943748060.5546570319
  s21_decimal dec_1 = {{0x79f5e24f, 0x234e13a9, 0x2, 0x800a0000}};
  // -79228162514264337591823169754
  s21_decimal dec_2 = {{0x996ef8da, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_16) {
  // -80744424089927099
  s21_decimal dec_1 = {{0x3b793dbb, 0x11edca0, 0x0, 0x80000000}};
  // -79228162514264337592410789634
  s21_decimal dec_2 = {{0xbc755702, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_17) {
  // -84393056591295.729944
  s21_decimal dec_1 = {{0x119ed118, 0x93305dd6, 0x4, 0x80060000}};
  // -79228162514264337593493519883
  s21_decimal dec_2 = {{0xfcfe7e0b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_18) {
  // 79228162514264337592536801952
  s21_decimal dec_1 = {{0xc3f822a0, 0xffffffff, 0xffffffff, 0x0}};
  // 514008818436.6366
  s21_decimal dec_2 = {{0xa57e51e, 0x1242e2, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_19) {
  // -79228162514264337593314327583
  s21_decimal dec_1 = {{0xf2503c1f, 0xffffffff, 0xffffffff, 0x80000000}};
  // -19106277272505521
  s21_decimal dec_2 = {{0xd5ceccb1, 0x43e10e, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_20) {
  // 121451755485788212333.430452
  s21_decimal dec_1 = {{0x2100c6b4, 0xdb84b18d, 0x647668, 0x60000}};
  // 79228162514264337591695049658
  s21_decimal dec_2 = {{0x91cc03ba, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_21) {
  // -79228162514264337593036204723
  s21_decimal dec_1 = {{0xe1bc6ab3, 0xffffffff, 0xffffffff, 0x80000000}};
  // -84303773688273934928
  s21_decimal dec_2 = {{0x4a7d9a50, 0x91f32b82, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_22) {
  // 79033436310806006126914490984
  s21_decimal dec_1 = {{0x861ed268, 0x5bc8b246, 0xff5eed1f, 0x0}};
  // 44432501973646327573185050887
  s21_decimal dec_2 = {{0x56703907, 0x708f9008, 0x8f91b446, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_23) {
  // -79228162514264337592671383679
  s21_decimal dec_1 = {{0xcbfdb07f, 0xffffffff, 0xffffffff, 0x80000000}};
  // -57756064008536057847
  s21_decimal dec_2 = {{0x583e7f7, 0x2186c236, 0x3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_24) {
  // -93263408711429147
  s21_decimal dec_1 = {{0x7ac96c1b, 0x14b5693, 0x0, 0x80000000}};
  // -79228162514264337593444297495
  s21_decimal dec_2 = {{0xfa0f6b17, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_25) {
  // 3948864905868.676087671100
  s21_decimal dec_1 = {{0x285be93c, 0x653ed09d, 0x34434, 0xc0000}};
  // 79228162514264337593409446242
  s21_decimal dec_2 = {{0xf7fba162, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_26) {
  // 585089039474679887621811
  s21_decimal dec_1 = {{0xdb6eeb3, 0xbd89dba2, 0x7be5, 0x0}};
  // 79228162514264337592456993287
  s21_decimal dec_2 = {{0xbf365a07, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_27) {
  // -79228162514264337593113689594
  s21_decimal dec_1 = {{0xe65abdfa, 0xffffffff, 0xffffffff, 0x80000000}};
  // -37289510769716721833.6
  s21_decimal dec_2 = {{0x82aeb6a0, 0x36f58cc4, 0x14, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_28) {
  // 79228162514264337592619682251
  s21_decimal dec_1 = {{0xc8e8c9cb, 0xffffffff, 0xffffffff, 0x0}};
  // 58143016206866186779435
  s21_decimal dec_2 = {{0x7183b2b, 0xf071013e, 0xc4f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_29) {
  // 27687646436.5221753261
  s21_decimal dec_1 = {{0xc324b1ad, 0x26ecd62, 0xf, 0xa0000}};
  // 79228162514264337593353245230
  s21_decimal dec_2 = {{0xf4a2122e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_30) {
  // 79228162514264337591595874371
  s21_decimal dec_1 = {{0x8be2b843, 0xffffffff, 0xffffffff, 0x0}};
  // 865900578845
  s21_decimal dec_2 = {{0x9bb2481d, 0xc9, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_31) {
  // 79228162514264337592760291785
  s21_decimal dec_1 = {{0xd14a51c9, 0xffffffff, 0xffffffff, 0x0}};
  // 25157194723813297985976843438
  s21_decimal dec_2 = {{0x685cbcae, 0xa8f34b38, 0x51498b32, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_32) {
  // 79228162514264337591654861724
  s21_decimal dec_1 = {{0x8f66cb9c, 0xffffffff, 0xffffffff, 0x0}};
  // 81981443758675780934213416
  s21_decimal dec_2 = {{0x1c729f28, 0xf8a942eb, 0x43d03e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_33) {
  // 79228162514264337592349065106
  s21_decimal dec_1 = {{0xb8c77f92, 0xffffffff, 0xffffffff, 0x0}};
  // 9604591521712
  s21_decimal dec_2 = {{0x3e440fb0, 0x8bc, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_34) {
  // 1894838506203057512211
  s21_decimal dec_1 = {{0x650c5f13, 0xb82aae1b, 0x66, 0x0}};
  // 79228162514264337593325475759
  s21_decimal dec_2 = {{0xf2fa57af, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_35) {
  // 79228162514264337593503513497
  s21_decimal dec_1 = {{0xfd96fb99, 0xffffffff, 0xffffffff, 0x0}};
  // 109025368457462578787905697
  s21_decimal dec_2 = {{0x950ff0a1, 0x111f178b, 0x5a2f05, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_36) {
  // 1825047582092165607172
  s21_decimal dec_1 = {{0x75176f04, 0xef9f8265, 0x62, 0x0}};
  // 79228162514264337593074946193
  s21_decimal dec_2 = {{0xe40b9091, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_37) {
  // -79228162514264337593240328424
  s21_decimal dec_1 = {{0xede718e8, 0xffffffff, 0xffffffff, 0x80000000}};
  // -13355693912636875275683884927
  s21_decimal dec_2 = {{0x63bdef7f, 0xc1b19bf6, 0x2b279231, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_38) {
  // -79228162514264337591863649793
  s21_decimal dec_1 = {{0x9bd8a601, 0xffffffff, 0xffffffff, 0x80000000}};
  // -894082724769020587
  s21_decimal dec_2 = {{0x49abbaab, 0xc686b80, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_39) {
  // -739359460269140521722558298
  s21_decimal dec_1 = {{0xa4ffb75a, 0xa750bb24, 0x2639574, 0x80000000}};
  // -78834434459853165419097481848
  s21_decimal dec_2 = {{0x697fe278, 0x66e5ebb3, 0xfeba50d7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_40) {
  // 79228162514264337592095089638
  s21_decimal dec_1 = {{0xa9a423e6, 0xffffffff, 0xffffffff, 0x0}};
  // 3273060350042286016
  s21_decimal dec_2 = {{0x4afa7c0, 0x2d6c3f0c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_41) {
  // -79228162514264337593013628435
  s21_decimal dec_1 = {{0xe063ee13, 0xffffffff, 0xffffffff, 0x80000000}};
  // -399645587071366408.7
  s21_decimal dec_2 = {{0xb6699257, 0x37764370, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_42) {
  // 79228162514264337591799020063
  s21_decimal dec_1 = {{0x97fe7a1f, 0xffffffff, 0xffffffff, 0x0}};
  // 4637971107556106248805
  s21_decimal dec_2 = {{0x56bd2265, 0x6cc7654c, 0xfb, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_43) {
  // -79228162514264337593202956588
  s21_decimal dec_1 = {{0xebacd92c, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3176866077647431512986
  s21_decimal dec_2 = {{0xcbafb39a, 0x37df91dc, 0xac, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_44) {
  // 60180481540382463860
  s21_decimal dec_1 = {{0x72731774, 0x432c051c, 0x3, 0x0}};
  // 79228162514264337593103841449
  s21_decimal dec_2 = {{0xe5c478a9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_45) {
  // -16198209765.500947
  s21_decimal dec_1 = {{0x9b11e813, 0x398c2f, 0x0, 0x80060000}};
  // -79228162514264337593399206230
  s21_decimal dec_2 = {{0xf75f6156, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_46) {
  // 6445435908109534357909832335
  s21_decimal dec_1 = {{0x5b7a828f, 0xb59cabd8, 0x14d38a24, 0x0}};
  // 79228162514264337592736887769
  s21_decimal dec_2 = {{0xcfe533d9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_47) {
  // -79228162514264337592730512842
  s21_decimal dec_1 = {{0xcf83edca, 0xffffffff, 0xffffffff, 0x80000000}};
  // -7271610045069699312
  s21_decimal dec_2 = {{0x318aa8f0, 0x64e9f2cf, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_48) {
  // -5132756499681005367032
  s21_decimal dec_1 = {{0x4fb56ef8, 0x3f4e39f3, 0x116, 0x80000000}};
  // -79228162514264337592566109409
  s21_decimal dec_2 = {{0xc5b754e1, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_49) {
  // -87299068250803
  s21_decimal dec_1 = {{0xe5f3cab3, 0x4f65, 0x0, 0x80000000}};
  // -79228162514264337592346589212
  s21_decimal dec_2 = {{0xb8a1b81c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_50) {
  // -8871431818.67959824
  s21_decimal dec_1 = {{0xc264610, 0xc4fc406, 0x0, 0x80080000}};
  // -79228162514264337592554193721
  s21_decimal dec_2 = {{0xc5018339, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_51) {
  // 79228162514264337592586781985
  s21_decimal dec_1 = {{0xc6f2c521, 0xffffffff, 0xffffffff, 0x0}};
  // 3475310238002686
  s21_decimal dec_2 = {{0xb8386dfe, 0xc58c6, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_52) {
  // -559835438835
  s21_decimal dec_1 = {{0x58cadef3, 0x82, 0x0, 0x80000000}};
  // -79228162514264337593524567492
  s21_decimal dec_2 = {{0xfed83dc4, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_53) {
  // 2450548970896900197734606
  s21_decimal dec_1 = {{0x1b2058ce, 0x86a179d5, 0x206ec, 0x0}};
  // 79228162514264337591479186469
  s21_decimal dec_2 = {{0x84ee3425, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_54) {
  // 455991640766397543244019738
  s21_decimal dec_1 = {{0xb82ab81a, 0x60b176f5, 0x1792ffc, 0x0}};
  // 79228162514264337592929705083
  s21_decimal dec_2 = {{0xdb635c7b, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_55) {
  // -79228162514264337592905605733
  s21_decimal dec_1 = {{0xd9f3a265, 0xffffffff, 0xffffffff, 0x80000000}};
  // -4151287652.6494127
  s21_decimal dec_2 = {{0xc2f761af, 0x937bbd, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_56) {
  // -79228162514264337591666773858
  s21_decimal dec_1 = {{0x901c8f62, 0xffffffff, 0xffffffff, 0x80000000}};
  // -490632599665157.028421136
  s21_decimal dec_2 = {{0xd9fb9e10, 0x3f1c1889, 0x67e5, 0x80090000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_57) {
  // -79228162514264337592238126186
  s21_decimal dec_1 = {{0xb22ab46a, 0xffffffff, 0xffffffff, 0x80000000}};
  // -4003915263282
  s21_decimal dec_2 = {{0x3bf26d32, 0x3a4, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_58) {
  // 79228162514264337592823186728
  s21_decimal dec_1 = {{0xd50a0528, 0xffffffff, 0xffffffff, 0x0}};
  // 15423718569344963820
  s21_decimal dec_2 = {{0x96714ec, 0xd60c0e52, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_59) {
  // -1806223479301042623
  s21_decimal dec_1 = {{0x44b571bf, 0x1910feaf, 0x0, 0x80000000}};
  // -79228162514264337593181045343
  s21_decimal dec_2 = {{0xea5e825f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_60) {
  // -79228162514264337592323189088
  s21_decimal dec_1 = {{0xb73ca960, 0xffffffff, 0xffffffff, 0x80000000}};
  // -5172269915849387962127587043
  s21_decimal dec_2 = {{0xdba796e3, 0xf8e66fbc, 0x10b666c1, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_61) {
  // -2437510843002347186202770025
  s21_decimal dec_1 = {{0x3de27a69, 0x926efaa8, 0x7e042ff, 0x80000000}};
  // -76816852586309755091965202967
  s21_decimal dec_2 = {{0x975c5217, 0xe0f84de9, 0xf8356942, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_62) {
  // 79228162514264337592791262511
  s21_decimal dec_1 = {{0xd322e52f, 0xffffffff, 0xffffffff, 0x0}};
  // 10245670732233
  s21_decimal dec_2 = {{0x819081c9, 0x951, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_63) {
  // -704734503805909844
  s21_decimal dec_1 = {{0x204ffb54, 0x9c7b84c, 0x0, 0x80000000}};
  // -79228162514264337591934658777
  s21_decimal dec_2 = {{0xa01428d9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_64) {
  // 79228162514264337591587842492
  s21_decimal dec_1 = {{0x8b6829bc, 0xffffffff, 0xffffffff, 0x0}};
  // 30503425710192228420162.9
  s21_decimal dec_2 = {{0x84b9e69d, 0xf0b1b570, 0x4097, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_65) {
  // 73290740401960840960280
  s21_decimal dec_1 = {{0x35d59918, 0x1957f499, 0xf85, 0x0}};
  // 79228162514264337592222867610
  s21_decimal dec_2 = {{0xb141e09a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_66) {
  // 79228162514264337591798386833
  s21_decimal dec_1 = {{0x97f4d091, 0xffffffff, 0xffffffff, 0x0}};
  // 395439639423326027890132463
  s21_decimal dec_2 = {{0x8e8d85ef, 0xceb7302e, 0x1471999, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_67) {
  // 79228162514264337593472347419
  s21_decimal dec_1 = {{0xfbbb6d1b, 0xffffffff, 0xffffffff, 0x0}};
  // 8258608335
  s21_decimal dec_2 = {{0xec405ccf, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_68) {
  // 79228162514264337592720042298
  s21_decimal dec_1 = {{0xcee4293a, 0xffffffff, 0xffffffff, 0x0}};
  // 4767539497907665021
  s21_decimal dec_2 = {{0xf16e387d, 0x4229b3e9, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_69) {
  // -79228162514264337593202806376
  s21_decimal dec_1 = {{0xebaa8e68, 0xffffffff, 0xffffffff, 0x80000000}};
  // -32106586800999937843012
  s21_decimal dec_2 = {{0xa68b9f44, 0x80661b85, 0x6cc, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_70) {
  // -79228162514264337593286014914
  s21_decimal dec_1 = {{0xf0a037c2, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3336063670469509.9702756320302
  s21_decimal dec_2 = {{0xeac5242e, 0x89585924, 0x6bcb459b, 0x800d0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_71) {
  // -163207401275
  s21_decimal dec_1 = {{0xffeb4f3b, 0x25, 0x0, 0x80000000}};
  // -79228162514264337592331638592
  s21_decimal dec_2 = {{0xb7bd9740, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_72) {
  // 79228162514264337592175784884
  s21_decimal dec_1 = {{0xae7373b4, 0xffffffff, 0xffffffff, 0x0}};
  // 47220367314
  s21_decimal dec_2 = {{0xfe8d9fd2, 0xa, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_73) {
  // -42521305692973747386070
  s21_decimal dec_1 = {{0x74fb6d6, 0x15a8603a, 0x901, 0x80000000}};
  // -79228162514264337592045854807
  s21_decimal dec_2 = {{0xa6b4e057, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_74) {
  // 79228162514264337592563810684
  s21_decimal dec_1 = {{0xc594417c, 0xffffffff, 0xffffffff, 0x0}};
  // 5006746759.7596177623334427
  s21_decimal dec_2 = {{0xbfaabe1b, 0xdb64e17b, 0x296a32, 0x100000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_75) {
  // 37702696197866391915372020095
  s21_decimal dec_1 = {{0x68f9017f, 0x507b917d, 0x79d2f078, 0x0}};
  // 53588810778148095471226961463
  s21_decimal dec_2 = {{0xd37bbe37, 0x54427482, 0xad27a015, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_76) {
  // -120530004212450984820007
  s21_decimal dec_1 = {{0x949d7d27, 0xf1d2abe4, 0x1985, 0x80000000}};
  // -79228162514264337592704304427
  s21_decimal dec_2 = {{0xcdf4052b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_77) {
  // -79228162514264337592299179656
  s21_decimal dec_1 = {{0xb5ce4e88, 0xffffffff, 0xffffffff, 0x80000000}};
  // -29048540467923109933681061
  s21_decimal dec_2 = {{0xefbb09a5, 0x88bd9490, 0x180744, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_78) {
  // 209982272559715738
  s21_decimal dec_1 = {{0xad0d159a, 0x2ea01c3, 0x0, 0x0}};
  // 79228162514264337591789125719
  s21_decimal dec_2 = {{0x97678057, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_79) {
  // -79228162514264337592188532660
  s21_decimal dec_1 = {{0xaf35f7b4, 0xffffffff, 0xffffffff, 0x80000000}};
  // -5847974695325
  s21_decimal dec_2 = {{0x9674519d, 0x551, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_80) {
  // -79228162514264337592350221989
  s21_decimal dec_1 = {{0xb8d926a5, 0xffffffff, 0xffffffff, 0x80000000}};
  // -517225216407029204081699
  s21_decimal dec_2 = {{0x9e9f5c23, 0xd5cd598c, 0x6d86, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_81) {
  // 17147244418011
  s21_decimal dec_1 = {{0x676993db, 0xf98, 0x0, 0x0}};
  // 79228162514264337592875546935
  s21_decimal dec_2 = {{0xd828f937, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_82) {
  // 4527023294731967
  s21_decimal dec_1 = {{0xbf5f56bf, 0x10154d, 0x0, 0x0}};
  // 79228162514264337592187412799
  s21_decimal dec_2 = {{0xaf24e13f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_83) {
  // -4273868127995578
  s21_decimal dec_1 = {{0x779606ba, 0xf2f0f, 0x0, 0x80000000}};
  // -79228162514264337593275190883
  s21_decimal dec_2 = {{0xeffb0e63, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_84) {
  // -574711371118
  s21_decimal dec_1 = {{0xcf77956e, 0x85, 0x0, 0x80000000}};
  // -79228162514264337592750888026
  s21_decimal dec_2 = {{0xd0bad45a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_85) {
  // -40362373340836310023012
  s21_decimal dec_1 = {{0xb4cffb64, 0xc73e078, 0x88c, 0x80000000}};
  // -79228162514264337593042103497
  s21_decimal dec_2 = {{0xe2166cc9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_86) {
  // -3140080602676606845212969551
  s21_decimal dec_1 = {{0x3cac4a4f, 0x8f614d4f, 0xa2569ee, 0x80000000}};
  // -79228162514264337593270724732
  s21_decimal dec_2 = {{0xefb6e87c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_87) {
  // 11902133706086391802168
  s21_decimal dec_1 = {{0x82e8e938, 0x3749397a, 0x285, 0x0}};
  // 79228162514264337592109190444
  s21_decimal dec_2 = {{0xaa7b4d2c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_88) {
  // 108628943798633885.260350
  s21_decimal dec_1 = {{0xf50ada3e, 0xc96e8c0b, 0x1700, 0x60000}};
  // 79228162514264337593290759505
  s21_decimal dec_2 = {{0xf0e89d51, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_89) {
  // -79228162514264337591429780341
  s21_decimal dec_1 = {{0x81fc5375, 0xffffffff, 0xffffffff, 0x80000000}};
  // -7361979383939975554539
  s21_decimal dec_2 = {{0x435b25eb, 0x17fcdc41, 0x18f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_90) {
  // 35551788067808
  s21_decimal dec_1 = {{0x8bb2ebe0, 0x2055, 0x0, 0x0}};
  // 79228162514264337591850445945
  s21_decimal dec_2 = {{0x9b0f2c79, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_91) {
  // -79228162514264337591628944279
  s21_decimal dec_1 = {{0x8ddb5397, 0xffffffff, 0xffffffff, 0x80000000}};
  // -2516185815070455875.64256
  s21_decimal dec_2 = {{0x14ea36e0, 0x45485c47, 0x3548, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_92) {
  // 91146770526347619568916628
  s21_decimal dec_1 = {{0xb9cf1894, 0x54bb720d, 0x4b6514, 0x0}};
  // 79228162514264337592314160728
  s21_decimal dec_2 = {{0xb6b2e658, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_93) {
  // 79228162514264337593337291944
  s21_decimal dec_1 = {{0xf3aea4a8, 0xffffffff, 0xffffffff, 0x0}};
  // 79228162514264337591892528438
  s21_decimal dec_2 = {{0x9d914d36, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_94) {
  // 79228162514264337591493450372
  s21_decimal dec_1 = {{0x85c7da84, 0xffffffff, 0xffffffff, 0x0}};
  // 1452216547834849.4904773
  s21_decimal dec_2 = {{0xe2b69dc5, 0x3f87f0d3, 0x313, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_95) {
  // -48521041894181007843857.63990
  s21_decimal dec_1 = {{0x37742a96, 0x2a26e747, 0xfad9107, 0x80050000}};
  // -79228162514264337592189889315
  s21_decimal dec_2 = {{0xaf4aab23, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_96) {
  // -79228162514264337591547558828
  s21_decimal dec_1 = {{0x89017bac, 0xffffffff, 0xffffffff, 0x80000000}};
  // -73118232928724263755
  s21_decimal dec_2 = {{0xa0e1234b, 0xf6b82573, 0x3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_97) {
  // 79228162514264337593042264599
  s21_decimal dec_1 = {{0xe218e217, 0xffffffff, 0xffffffff, 0x0}};
  // 837126763
  s21_decimal dec_2 = {{0x31e58a6b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_98) {
  // -5864557236322030822445.801
  s21_decimal dec_1 = {{0x415952e9, 0x48e996f9, 0x4d9de, 0x80030000}};
  // -79228162514264337592989856776
  s21_decimal dec_2 = {{0xdef93408, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_99) {
  // -79228162514264337592047521243
  s21_decimal dec_1 = {{0xa6ce4ddb, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3180018477827.4446245
  s21_decimal dec_2 = {{0x3cd51ba5, 0xb950f392, 0x1, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_100) {
  // 79228162514264337592107060194
  s21_decimal dec_1 = {{0xaa5acbe2, 0xffffffff, 0xffffffff, 0x0}};
  // 12770325648144900923052
  s21_decimal dec_2 = {{0x18dd9eac, 0x47de9ce7, 0x2b4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_101) {
  // 94373563148890890790425143
  s21_decimal dec_1 = {{0x8de6d237, 0x1c0c3521, 0x4e1061, 0x0}};
  // 79228162514264337591697297622
  s21_decimal dec_2 = {{0x91ee50d6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_102) {
  // 4453015196388470139
  s21_decimal dec_1 = {{0x6026ad7b, 0x3dcc49ba, 0x0, 0x0}};
  // 79228162514264337592875070641
  s21_decimal dec_2 = {{0xd821b4b1, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_103) {
  // 79228162514264337592379393649
  s21_decimal dec_1 = {{0xba964671, 0xffffffff, 0xffffffff, 0x0}};
  // 84476996039910759465
  s21_decimal dec_2 = {{0xeaf61c29, 0x945a9451, 0x4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_104) {
  // 79228162514264337592295994727
  s21_decimal dec_1 = {{0xb59db567, 0xffffffff, 0xffffffff, 0x0}};
  // 5524928519.7718
  s21_decimal dec_2 = {{0xba04af96, 0x323f, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_105) {
  // 517824618223
  s21_decimal dec_1 = {{0x90c09eef, 0x78, 0x0, 0x0}};
  // 79228162514264337592596468149
  s21_decimal dec_2 = {{0xc78691b5, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_106) {
  // -36678878713.30281
  s21_decimal dec_1 = {{0xb1a587e9, 0xd07ec, 0x0, 0x80050000}};
  // -79228162514264337592256357962
  s21_decimal dec_2 = {{0xb340e64a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_107) {
  // -79228162514264337591767282091
  s21_decimal dec_1 = {{0x961a31ab, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3999352011319415.2
  s21_decimal dec_2 = {{0x7aa14a8, 0x8e15e5, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_108) {
  // 79228162514264337593057619814
  s21_decimal dec_1 = {{0xe3032f66, 0xffffffff, 0xffffffff, 0x0}};
  // 58518599175504828
  s21_decimal dec_2 = {{0x1c9c03bc, 0xcfe65b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_109) {
  // -79228162514264337592586602161
  s21_decimal dec_1 = {{0xc6f006b1, 0xffffffff, 0xffffffff, 0x80000000}};
  // -366109163156151.1199
  s21_decimal dec_2 = {{0xd61111f, 0x32cecf71, 0x0, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_110) {
  // -79228162514264337591745781287
  s21_decimal dec_1 = {{0x94d21e27, 0xffffffff, 0xffffffff, 0x80000000}};
  // -6870343312.5418440066
  s21_decimal dec_2 = {{0xd25f1582, 0xb973a06b, 0x3, 0x800a0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_111) {
  // -5309073391.674917248794388331
  s21_decimal dec_1 = {{0x7588676b, 0x41c73f7e, 0x11279005, 0x80120000}};
  // -79228162514264337591989153713
  s21_decimal dec_2 = {{0xa353afb1, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_112) {
  // -545425628417.0875202
  s21_decimal dec_1 = {{0x4bf27142, 0x4bb16931, 0x0, 0x80070000}};
  // -79228162514264337591508442314
  s21_decimal dec_2 = {{0x86ac9cca, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_113) {
  // -79228162514264337592389146773
  s21_decimal dec_1 = {{0xbb2b1895, 0xffffffff, 0xffffffff, 0x80000000}};
  // -68029468331139
  s21_decimal dec_2 = {{0x584b4c83, 0x3ddf, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_114) {
  // -728326574
  s21_decimal dec_1 = {{0x2b6961ae, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593389276670
  s21_decimal dec_2 = {{0xf6c7ddfe, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_115) {
  // 905656973968183550976717
  s21_decimal dec_1 = {{0x6f6a2cd, 0xc34fb7c4, 0xbfc7, 0x0}};
  // 79228162514264337593120706373
  s21_decimal dec_2 = {{0xe6c5cf45, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_116) {
  // 79228162514264337592454442063
  s21_decimal dec_1 = {{0xbf0f6c4f, 0xffffffff, 0xffffffff, 0x0}};
  // 619105358373533
  s21_decimal dec_2 = {{0xb2f6e29d, 0x23312, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_117) {
  // 15831205723561330497181
  s21_decimal dec_1 = {{0x9c04569d, 0x361d2041, 0x35a, 0x0}};
  // 79228162514264337593522891553
  s21_decimal dec_2 = {{0xfebeab21, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_118) {
  // -79228162514264337591649957901
  s21_decimal dec_1 = {{0x8f1bf80d, 0xffffffff, 0xffffffff, 0x80000000}};
  // -67104064162.9611854896
  s21_decimal dec_2 = {{0x87378c30, 0x608f443c, 0x24, 0x800a0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_119) {
  // -9642135774124116
  s21_decimal dec_1 = {{0xadb15854, 0x224178, 0x0, 0x80000000}};
  // -79228162514264337591664140646
  s21_decimal dec_2 = {{0x8ff46166, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_120) {
  // 5110436720995514146681462674
  s21_decimal dec_1 = {{0x31931f92, 0xc33d2469, 0x10834111, 0x0}};
  // 79228162514264337592737629142
  s21_decimal dec_2 = {{0xcff083d6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_121) {
  // -3587287073692976.908
  s21_decimal dec_1 = {{0x56d2070c, 0x31c89a96, 0x0, 0x80030000}};
  // -79228162514264337592713402325
  s21_decimal dec_2 = {{0xce7ed7d5, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_122) {
  // -79228162514264337593516954344
  s21_decimal dec_1 = {{0xfe6412e8, 0xffffffff, 0xffffffff, 0x80000000}};
  // -531069683715457
  s21_decimal dec_2 = {{0x4bd94d81, 0x1e301, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_123) {
  // 28552104351419393934448306
  s21_decimal dec_1 = {{0x544556b2, 0xada7d3b5, 0x179e24, 0x0}};
  // 79228162514264337593095701804
  s21_decimal dec_2 = {{0xe548452c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_124) {
  // 832426946.559836835365942138
  s21_decimal dec_1 = {{0xfdf2737a, 0x31dd4412, 0x2b09143, 0x120000}};
  // 79228162514264337593253897283
  s21_decimal dec_2 = {{0xeeb62443, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_125) {
  // -79228162514264337592818325147
  s21_decimal dec_1 = {{0xd4bfd69b, 0xffffffff, 0xffffffff, 0x80000000}};
  // -121029499404211735
  s21_decimal dec_2 = {{0x3f54d617, 0x1adfbb0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_126) {
  // -79228162514264337592622035905
  s21_decimal dec_1 = {{0xc90cb3c1, 0xffffffff, 0xffffffff, 0x80000000}};
  // -724672295769.5302767
  s21_decimal dec_2 = {{0x9f18bc6f, 0x64918822, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_127) {
  // -24222206018250585759
  s21_decimal dec_1 = {{0xf227b69f, 0x50269009, 0x1, 0x80000000}};
  // -79228162514264337592430135490
  s21_decimal dec_2 = {{0xbd9c88c2, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_128) {
  // -1929889838811.9
  s21_decimal dec_1 = {{0x5ffba497, 0x118d, 0x0, 0x80010000}};
  // -79228162514264337593086695616
  s21_decimal dec_2 = {{0xe4bed8c0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_129) {
  // 79228162514264337591423304704
  s21_decimal dec_1 = {{0x81998400, 0xffffffff, 0xffffffff, 0x0}};
  // 81883432513284
  s21_decimal dec_2 = {{0xf8e86f04, 0x4a78, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_130) {
  // -79228162514264337592404086525
  s21_decimal dec_1 = {{0xbc0f0efd, 0xffffffff, 0xffffffff, 0x80000000}};
  // -51047080591488866333874016288
  s21_decimal dec_2 = {{0xf6115020, 0xd1160fae, 0xa4f127c7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_131) {
  // -79228162514264337593185918161
  s21_decimal dec_1 = {{0xeaa8dcd1, 0xffffffff, 0xffffffff, 0x80000000}};
  // -38759316898768.281387911250
  s21_decimal dec_2 = {{0x553c852, 0xc77f37ad, 0x200f9a, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_132) {
  // -79228162514264337592235411851
  s21_decimal dec_1 = {{0xb201498b, 0xffffffff, 0xffffffff, 0x80000000}};
  // -615106797262
  s21_decimal dec_2 = {{0x3738dece, 0x8f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_133) {
  // 24512385362889098051301
  s21_decimal dec_1 = {{0x294ebee5, 0xd1aec75d, 0x530, 0x0}};
  // 79228162514264337593238256135
  s21_decimal dec_2 = {{0xedc77a07, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_134) {
  // 30857132686.310354790
  s21_decimal dec_1 = {{0xaa9faf66, 0xac3a8eb0, 0x1, 0x90000}};
  // 79228162514264337591617688707
  s21_decimal dec_2 = {{0x8d2f9483, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_135) {
  // -2930727968986369035
  s21_decimal dec_1 = {{0x64bc0c0b, 0x28ac098f, 0x0, 0x80000000}};
  // -79228162514264337593503576172
  s21_decimal dec_2 = {{0xfd97f06c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_136) {
  // 79228162514264337592706408383
  s21_decimal dec_1 = {{0xce141fbf, 0xffffffff, 0xffffffff, 0x0}};
  // 6492150244668717494.18351
  s21_decimal dec_2 = {{0x77ff9d6f, 0x459e800, 0x897a, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_137) {
  // -918712536251.778
  s21_decimal dec_1 = {{0x6e5fbd82, 0x34390, 0x0, 0x80030000}};
  // -79228162514264337592027757711
  s21_decimal dec_2 = {{0xa5a0bc8f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_138) {
  // 79228162514264337592467682854
  s21_decimal dec_1 = {{0xbfd97626, 0xffffffff, 0xffffffff, 0x0}};
  // 56202126347573
  s21_decimal dec_2 = {{0x93c6cd35, 0x331d, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_139) {
  // -79228162514264337592964181643
  s21_decimal dec_1 = {{0xdd716e8b, 0xffffffff, 0xffffffff, 0x80000000}};
  // -784541599912969153823680
  s21_decimal dec_2 = {{0x46e443c0, 0x15d9994d, 0xa622, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_140) {
  // -2558723467628364906264
  s21_decimal dec_1 = {{0x2c673f18, 0xb56bdd1c, 0x8a, 0x80000000}};
  // -79228162514264337592754746949
  s21_decimal dec_2 = {{0xd0f5b645, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_141) {
  // -79228162514264337592548583820
  s21_decimal dec_1 = {{0xc4abe98c, 0xffffffff, 0xffffffff, 0x80000000}};
  // -668077014831.67973
  s21_decimal dec_2 = {{0x232a20e5, 0xed5940, 0x0, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_142) {
  // -3033982203158
  s21_decimal dec_1 = {{0x676e7516, 0x2c2, 0x0, 0x80000000}};
  // -79228162514264337592797531082
  s21_decimal dec_2 = {{0xd3828bca, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_143) {
  // -17928829044
  s21_decimal dec_1 = {{0x2ca43874, 0x4, 0x0, 0x80000000}};
  // -79228162514264337592084380569
  s21_decimal dec_2 = {{0xa900bb99, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_144) {
  // -79228162514264337593118272729
  s21_decimal dec_1 = {{0xe6a0acd9, 0xffffffff, 0xffffffff, 0x80000000}};
  // -37733478290721243687950
  s21_decimal dec_2 = {{0xf18c6c0e, 0x893478df, 0x7fd, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_145) {
  // 79228162514264337592324625493
  s21_decimal dec_1 = {{0xb7529455, 0xffffffff, 0xffffffff, 0x0}};
  // 7798973706751694613087867
  s21_decimal dec_2 = {{0x8aa5867b, 0x3638950a, 0x6737f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_146) {
  // 5015132478.40795683903294
  s21_decimal dec_1 = {{0x1a1ad73e, 0x166fb423, 0x6a33, 0xe0000}};
  // 79228162514264337593437702935
  s21_decimal dec_2 = {{0xf9aacb17, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_147) {
  // 8055840445800
  s21_decimal dec_1 = {{0xa5821568, 0x753, 0x0, 0x0}};
  // 79228162514264337592230562507
  s21_decimal dec_2 = {{0xb1b74acb, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_148) {
  // 602202919320.19
  s21_decimal dec_1 = {{0x211bdf73, 0x36c5, 0x0, 0x20000}};
  // 79228162514264337591806376138
  s21_decimal dec_2 = {{0x986eb8ca, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_149) {
  // 79228162514264337591915447862
  s21_decimal dec_1 = {{0x9eef0636, 0xffffffff, 0xffffffff, 0x0}};
  // 180883869966892515083976725
  s21_decimal dec_2 = {{0xede48015, 0x3d41c009, 0x959fa6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_150) {
  // -4174420674
  s21_decimal dec_1 = {{0xf8d09ac2, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593502631087
  s21_decimal dec_2 = {{0xfd8984af, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_151) {
  // -79228162514264337591646082585
  s21_decimal dec_1 = {{0x8ee0d619, 0xffffffff, 0xffffffff, 0x80000000}};
  // -8694621186256045925944063
  s21_decimal dec_2 = {{0xaa034aff, 0x5be46686, 0x73128, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_152) {
  // -79228162514264337593017563749
  s21_decimal dec_1 = {{0xe09ffa65, 0xffffffff, 0xffffffff, 0x80000000}};
  // -90881295165
  s21_decimal dec_2 = {{0x28f2833d, 0x15, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_153) {
  // 72087702368454328179054374768
  s21_decimal dec_1 = {{0x6d7c6f70, 0xde4af5ce, 0xe8ed8cbf, 0x0}};
  // 9942506338316616505935344443
  s21_decimal dec_2 = {{0x7e95333b, 0x99021fe0, 0x20203f9c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_154) {
  // 79228162514264337592589698818
  s21_decimal dec_1 = {{0xc71f4702, 0xffffffff, 0xffffffff, 0x0}};
  // 16790277454469782995
  s21_decimal dec_2 = {{0xd9ebddd3, 0xe9030c62, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_155) {
  // 79228162514264337591837223394
  s21_decimal dec_1 = {{0x9a4569e2, 0xffffffff, 0xffffffff, 0x0}};
  // 7187975902
  s21_decimal dec_2 = {{0xac6fcede, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_156) {
  // 57533591345595
  s21_decimal dec_1 = {{0x954659bb, 0x3453, 0x0, 0x0}};
  // 79228162514264337592243599920
  s21_decimal dec_2 = {{0xb27e3a30, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_157) {
  // 79228162514264337591981479875
  s21_decimal dec_1 = {{0xa2de97c3, 0xffffffff, 0xffffffff, 0x0}};
  // 189970005947
  s21_decimal dec_2 = {{0x3b183fbb, 0x2c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_158) {
  // 56920269968.76301
  s21_decimal dec_1 = {{0x4f33640d, 0x1438de, 0x0, 0x50000}};
  // 79228162514264337592287315549
  s21_decimal dec_2 = {{0xb519465d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_159) {
  // 2804970475.687
  s21_decimal dec_1 = {{0x1544d0a7, 0x28d, 0x0, 0x30000}};
  // 79228162514264337593032320137
  s21_decimal dec_2 = {{0xe1812489, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_160) {
  // -174650919896799
  s21_decimal dec_1 = {{0x160a46df, 0x9ed8, 0x0, 0x80000000}};
  // -79228162514264337592137017530
  s21_decimal dec_2 = {{0xac23e8ba, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_161) {
  // -98272935659969.8965034
  s21_decimal dec_1 = {{0xa93cc22a, 0x461c071a, 0x35, 0x80070000}};
  // -79228162514264337593360073132
  s21_decimal dec_2 = {{0xf50a41ac, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_162) {
  // 720926712952893448918943
  s21_decimal dec_1 = {{0xb154179f, 0x83f2853a, 0x98a9, 0x0}};
  // 79228162514264337592144375192
  s21_decimal dec_2 = {{0xac942d98, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_163) {
  // 89454441188799
  s21_decimal dec_1 = {{0xbc30cdbf, 0x515b, 0x0, 0x0}};
  // 79228162514264337591673845314
  s21_decimal dec_2 = {{0x90887642, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_164) {
  // 79228162514264337592864160054
  s21_decimal dec_1 = {{0xd77b3936, 0xffffffff, 0xffffffff, 0x0}};
  // 8846166028726
  s21_decimal dec_2 = {{0xa89571b6, 0x80b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_165) {
  // 275593902.879286611084899
  s21_decimal dec_1 = {{0x56070663, 0xf9b48da2, 0x3a5b, 0xf0000}};
  // 79228162514264337593328365126
  s21_decimal dec_2 = {{0xf3266e46, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_166) {
  // -5250030881
  s21_decimal dec_1 = {{0x38ed1d21, 0x1, 0x0, 0x80000000}};
  // -79228162514264337592298054399
  s21_decimal dec_2 = {{0xb5bd22ff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_add_cases(void) {
  Suite *c = suite_create("s21_add_cases");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, invalid_dec_s21_add_1);
  tcase_add_test(tc, invalid_dec_s21_add_2);
  tcase_add_test(tc, invalid_dec_s21_add_3);
  tcase_add_test(tc, invalid_dec_s21_add_4);
  tcase_add_test(tc, invalid_dec_s21_add_5);
  tcase_add_test(tc, invalid_dec_s21_add_6);
  tcase_add_test(tc, invalid_dec_s21_add_7);
  tcase_add_test(tc, invalid_dec_s21_add_8);
  tcase_add_test(tc, invalid_dec_s21_add_9);
  tcase_add_test(tc, invalid_dec_s21_add_10);
  tcase_add_test(tc, invalid_dec_s21_add_11);
  tcase_add_test(tc, invalid_dec_s21_add_12);
  tcase_add_test(tc, invalid_dec_s21_add_13);
  tcase_add_test(tc, invalid_dec_s21_add_14);
  tcase_add_test(tc, invalid_dec_s21_add_15);
  tcase_add_test(tc, invalid_dec_s21_add_16);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
  tcase_add_test(tc, s21_add_10);
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_12);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);
  tcase_add_test(tc, s21_add_17);
  tcase_add_test(tc, s21_add_18);
  tcase_add_test(tc, s21_add_19);
  tcase_add_test(tc, s21_add_20);
  tcase_add_test(tc, s21_add_21);
  tcase_add_test(tc, s21_add_22);
  tcase_add_test(tc, s21_add_23);
  tcase_add_test(tc, s21_add_24);
  tcase_add_test(tc, s21_add_25);
  tcase_add_test(tc, s21_add_26);
  tcase_add_test(tc, s21_add_27);
  tcase_add_test(tc, s21_add_28);
  tcase_add_test(tc, s21_add_29);
  tcase_add_test(tc, s21_add_30);
  tcase_add_test(tc, s21_add_31);
  tcase_add_test(tc, s21_add_32);
  tcase_add_test(tc, s21_add_33);
  tcase_add_test(tc, s21_add_34);
  tcase_add_test(tc, s21_add_35);
  tcase_add_test(tc, s21_add_37);
  tcase_add_test(tc, s21_add_38);
  tcase_add_test(tc, s21_add_39);
  tcase_add_test(tc, s21_add_40);
  tcase_add_test(tc, s21_add_42);
  tcase_add_test(tc, s21_add_44);
  tcase_add_test(tc, s21_add_45);
  tcase_add_test(tc, s21_add_46);
  tcase_add_test(tc, s21_add_47);
  tcase_add_test(tc, s21_add_48);
  tcase_add_test(tc, s21_add_49);
  tcase_add_test(tc, s21_add_50);
  tcase_add_test(tc, s21_add_51);
  tcase_add_test(tc, s21_add_52);
  tcase_add_test(tc, s21_add_53);
  tcase_add_test(tc, s21_add_54);
  tcase_add_test(tc, s21_add_55);
  tcase_add_test(tc, s21_add_56);
  tcase_add_test(tc, s21_add_57);
  tcase_add_test(tc, s21_add_58);
  tcase_add_test(tc, s21_add_59);
  tcase_add_test(tc, s21_add_60);
  tcase_add_test(tc, s21_add_61);
  tcase_add_test(tc, s21_add_62);
  tcase_add_test(tc, s21_add_63);
  tcase_add_test(tc, s21_add_64);
  tcase_add_test(tc, s21_add_65);
  tcase_add_test(tc, s21_add_66);
  tcase_add_test(tc, s21_add_67);
  tcase_add_test(tc, s21_add_68);
  tcase_add_test(tc, s21_add_69);
  tcase_add_test(tc, s21_add_70);
  tcase_add_test(tc, s21_add_71);
  tcase_add_test(tc, s21_add_72);
  tcase_add_test(tc, s21_add_73);
  tcase_add_test(tc, s21_add_74);
  tcase_add_test(tc, s21_add_75);
  tcase_add_test(tc, s21_add_76);
  tcase_add_test(tc, s21_add_77);
  tcase_add_test(tc, s21_add_78);
  tcase_add_test(tc, s21_add_79);
  tcase_add_test(tc, s21_add_80);
  tcase_add_test(tc, s21_add_81);
  tcase_add_test(tc, s21_add_83);
  tcase_add_test(tc, s21_add_84);
  tcase_add_test(tc, s21_add_85);
  tcase_add_test(tc, s21_add_86);
  tcase_add_test(tc, s21_add_87);
  tcase_add_test(tc, s21_add_88);
  tcase_add_test(tc, s21_add_89);
  tcase_add_test(tc, s21_add_90);
  tcase_add_test(tc, s21_add_91);
  tcase_add_test(tc, s21_add_92);
  tcase_add_test(tc, s21_add_93);
  tcase_add_test(tc, s21_add_94);
  tcase_add_test(tc, s21_add_95);
  tcase_add_test(tc, s21_add_96);
  tcase_add_test(tc, s21_add_98);
  tcase_add_test(tc, s21_add_99);
  tcase_add_test(tc, s21_add_100);
  tcase_add_test(tc, s21_add_101);
  tcase_add_test(tc, s21_add_102);
  tcase_add_test(tc, s21_add_103);
  tcase_add_test(tc, s21_add_104);
  tcase_add_test(tc, s21_add_105);
  tcase_add_test(tc, s21_add_106);
  tcase_add_test(tc, s21_add_107);
  tcase_add_test(tc, s21_add_109);
  tcase_add_test(tc, s21_add_110);
  tcase_add_test(tc, s21_add_111);
  tcase_add_test(tc, s21_add_112);
  tcase_add_test(tc, s21_add_113);
  tcase_add_test(tc, s21_add_114);
  tcase_add_test(tc, s21_add_115);
  tcase_add_test(tc, s21_add_116);
  tcase_add_test(tc, s21_add_117);
  tcase_add_test(tc, s21_add_118);
  tcase_add_test(tc, s21_add_119);
  tcase_add_test(tc, s21_add_120);
  tcase_add_test(tc, s21_add_121);
  tcase_add_test(tc, s21_add_122);
  tcase_add_test(tc, s21_add_123);
  tcase_add_test(tc, s21_add_124);
  tcase_add_test(tc, s21_add_126);
  tcase_add_test(tc, s21_add_127);
  tcase_add_test(tc, s21_add_128);
  tcase_add_test(tc, s21_add_129);
  tcase_add_test(tc, s21_add_130);
  tcase_add_test(tc, s21_add_132);
  tcase_add_test(tc, s21_add_133);
  tcase_add_test(tc, s21_add_134);
  tcase_add_test(tc, s21_add_135);
  tcase_add_test(tc, s21_add_136);
  tcase_add_test(tc, s21_add_137);
  tcase_add_test(tc, s21_add_138);
  tcase_add_test(tc, s21_add_139);
  tcase_add_test(tc, s21_add_140);
  tcase_add_test(tc, s21_add_141);
  tcase_add_test(tc, s21_add_142);
  tcase_add_test(tc, s21_add_143);
  tcase_add_test(tc, s21_add_144);
  tcase_add_test(tc, s21_add_145);
  tcase_add_test(tc, s21_add_146);
  tcase_add_test(tc, s21_add_147);
  tcase_add_test(tc, s21_add_148);
  tcase_add_test(tc, s21_add_149);
  tcase_add_test(tc, s21_add_150);
  tcase_add_test(tc, s21_add_151);
  tcase_add_test(tc, s21_add_152);
  tcase_add_test(tc, s21_add_153);
  tcase_add_test(tc, s21_add_154);
  tcase_add_test(tc, s21_add_155);
  tcase_add_test(tc, s21_add_156);
  tcase_add_test(tc, s21_add_157);
  tcase_add_test(tc, s21_add_158);
  tcase_add_test(tc, s21_add_159);
  tcase_add_test(tc, s21_add_160);
  tcase_add_test(tc, s21_add_161);
  tcase_add_test(tc, s21_add_162);
  tcase_add_test(tc, s21_add_163);
  tcase_add_test(tc, s21_add_164);
  tcase_add_test(tc, s21_add_165);
  tcase_add_test(tc, s21_add_166);
  tcase_add_test(tc, s21_add_167);
  tcase_add_test(tc, s21_add_168);
  tcase_add_test(tc, s21_add_169);
  tcase_add_test(tc, s21_add_170);
  tcase_add_test(tc, s21_add_171);
  tcase_add_test(tc, s21_add_172);
  tcase_add_test(tc, s21_add_173);
  tcase_add_test(tc, s21_add_174);
  tcase_add_test(tc, s21_add_175);
  tcase_add_test(tc, s21_add_176);
  tcase_add_test(tc, s21_add_177);
  tcase_add_test(tc, s21_add_178);
  tcase_add_test(tc, s21_add_179);
  tcase_add_test(tc, s21_add_180);
  tcase_add_test(tc, s21_add_181);
  tcase_add_test(tc, s21_add_182);
  tcase_add_test(tc, s21_add_183);
  tcase_add_test(tc, s21_add_184);
  tcase_add_test(tc, s21_add_185);
  tcase_add_test(tc, s21_add_186);
  tcase_add_test(tc, s21_add_187);
  tcase_add_test(tc, s21_add_188);
  tcase_add_test(tc, s21_add_189);
  tcase_add_test(tc, s21_add_190);
  tcase_add_test(tc, s21_add_191);
  tcase_add_test(tc, s21_add_192);
  tcase_add_test(tc, s21_add_193);
  tcase_add_test(tc, s21_add_194);
  tcase_add_test(tc, s21_add_195);
  tcase_add_test(tc, s21_add_196);
  tcase_add_test(tc, s21_add_197);
  tcase_add_test(tc, s21_add_198);
  tcase_add_test(tc, s21_add_199);
  tcase_add_test(tc, s21_add_200);
  tcase_add_test(tc, s21_add_201);
  tcase_add_test(tc, s21_add_202);
  tcase_add_test(tc, s21_add_203);
  tcase_add_test(tc, s21_add_204);
  tcase_add_test(tc, s21_add_205);
  tcase_add_test(tc, s21_add_206);
  tcase_add_test(tc, s21_add_207);
  tcase_add_test(tc, s21_add_208);
  tcase_add_test(tc, s21_add_209);
  tcase_add_test(tc, s21_add_210);
  tcase_add_test(tc, s21_add_211);
  tcase_add_test(tc, s21_add_212);
  tcase_add_test(tc, s21_add_213);
  tcase_add_test(tc, s21_add_214);
  tcase_add_test(tc, s21_add_215);
  tcase_add_test(tc, s21_add_216);
  tcase_add_test(tc, s21_add_218);
  tcase_add_test(tc, s21_add_219);
  tcase_add_test(tc, s21_add_220);
  tcase_add_test(tc, s21_add_221);
  tcase_add_test(tc, s21_add_222);
  tcase_add_test(tc, s21_add_223);
  tcase_add_test(tc, s21_add_224);
  tcase_add_test(tc, s21_add_225);
  tcase_add_test(tc, s21_add_226);
  tcase_add_test(tc, s21_add_227);
  tcase_add_test(tc, s21_add_228);
  tcase_add_test(tc, s21_add_229);
  tcase_add_test(tc, s21_add_230);
  tcase_add_test(tc, s21_add_231);
  tcase_add_test(tc, s21_add_232);
  tcase_add_test(tc, s21_add_233);
  tcase_add_test(tc, s21_add_234);
  tcase_add_test(tc, s21_add_235);
  tcase_add_test(tc, s21_add_236);
  tcase_add_test(tc, s21_add_237);
  tcase_add_test(tc, s21_add_238);
  tcase_add_test(tc, s21_add_239);
  tcase_add_test(tc, s21_add_240);
  tcase_add_test(tc, s21_add_241);
  tcase_add_test(tc, s21_add_242);
  tcase_add_test(tc, s21_add_243);
  tcase_add_test(tc, s21_add_244);
  tcase_add_test(tc, s21_add_245);
  tcase_add_test(tc, s21_add_246);
  tcase_add_test(tc, s21_add_247);
  tcase_add_test(tc, s21_add_248);
  tcase_add_test(tc, s21_add_249);
  tcase_add_test(tc, s21_add_250);
  tcase_add_test(tc, s21_add_251);
  tcase_add_test(tc, s21_add_252);
  tcase_add_test(tc, s21_add_253);
  tcase_add_test(tc, s21_add_254);
  tcase_add_test(tc, s21_add_255);
  tcase_add_test(tc, s21_add_257);
  tcase_add_test(tc, s21_add_258);
  tcase_add_test(tc, s21_add_259);
  tcase_add_test(tc, s21_add_261);
  tcase_add_test(tc, s21_add_262);
  tcase_add_test(tc, s21_add_263);
  tcase_add_test(tc, s21_add_264);
  tcase_add_test(tc, s21_add_265);
  tcase_add_test(tc, s21_add_266);
  tcase_add_test(tc, s21_add_267);
  tcase_add_test(tc, s21_add_268);
  tcase_add_test(tc, s21_add_269);
  tcase_add_test(tc, s21_add_270);
  tcase_add_test(tc, s21_add_271);
  tcase_add_test(tc, s21_add_272);
  tcase_add_test(tc, s21_add_273);
  tcase_add_test(tc, s21_add_275);
  tcase_add_test(tc, s21_add_276);
  tcase_add_test(tc, s21_add_277);
  tcase_add_test(tc, s21_add_279);
  tcase_add_test(tc, s21_add_280);
  tcase_add_test(tc, s21_add_281);
  tcase_add_test(tc, s21_add_282);
  tcase_add_test(tc, s21_add_283);
  tcase_add_test(tc, s21_add_284);
  tcase_add_test(tc, s21_add_285);
  tcase_add_test(tc, s21_add_286);
  tcase_add_test(tc, s21_add_287);
  tcase_add_test(tc, s21_add_288);
  tcase_add_test(tc, s21_add_289);
  tcase_add_test(tc, s21_add_290);
  tcase_add_test(tc, s21_add_291);
  tcase_add_test(tc, s21_add_292);
  tcase_add_test(tc, s21_add_293);
  tcase_add_test(tc, s21_add_294);
  tcase_add_test(tc, s21_add_295);
  tcase_add_test(tc, s21_add_296);
  tcase_add_test(tc, s21_add_297);
  tcase_add_test(tc, s21_add_298);
  tcase_add_test(tc, s21_add_300);
  tcase_add_test(tc, s21_add_301);
  tcase_add_test(tc, s21_add_302);
  tcase_add_test(tc, s21_add_303);
  tcase_add_test(tc, s21_add_304);
  tcase_add_test(tc, s21_add_305);
  tcase_add_test(tc, s21_add_306);
  tcase_add_test(tc, s21_add_308);
  tcase_add_test(tc, s21_add_309);
  tcase_add_test(tc, s21_add_310);
  tcase_add_test(tc, s21_add_311);
  tcase_add_test(tc, s21_add_312);
  tcase_add_test(tc, s21_add_313);
  tcase_add_test(tc, s21_add_314);
  tcase_add_test(tc, s21_add_315);
  tcase_add_test(tc, s21_add_316);
  tcase_add_test(tc, s21_add_317);
  tcase_add_test(tc, s21_add_318);
  tcase_add_test(tc, s21_add_319);
  tcase_add_test(tc, s21_add_320);
  tcase_add_test(tc, s21_add_321);
  tcase_add_test(tc, s21_add_322);
  tcase_add_test(tc, s21_add_323);
  tcase_add_test(tc, s21_add_324);
  tcase_add_test(tc, s21_add_325);
  tcase_add_test(tc, s21_add_326);
  tcase_add_test(tc, s21_add_328);
  tcase_add_test(tc, s21_add_329);
  tcase_add_test(tc, s21_add_330);
  tcase_add_test(tc, s21_add_331);
  tcase_add_test(tc, s21_add_332);
  tcase_add_test(tc, s21_add_333);
  tcase_add_test(tc, s21_add_334);
  tcase_add_test(tc, s21_add_335);
  tcase_add_test(tc, s21_add_336);
  tcase_add_test(tc, s21_add_337);
  tcase_add_test(tc, s21_add_338);
  tcase_add_test(tc, s21_add_339);
  tcase_add_test(tc, s21_add_340);
  tcase_add_test(tc, s21_add_342);
  tcase_add_test(tc, s21_add_343);
  tcase_add_test(tc, s21_add_344);
  tcase_add_test(tc, s21_add_345);
  tcase_add_test(tc, s21_add_346);
  tcase_add_test(tc, s21_add_347);
  tcase_add_test(tc, s21_add_348);
  tcase_add_test(tc, s21_add_349);
  tcase_add_test(tc, s21_add_350);
  tcase_add_test(tc, s21_add_351);
  tcase_add_test(tc, s21_add_352);
  tcase_add_test(tc, s21_add_353);
  tcase_add_test(tc, s21_add_355);
  tcase_add_test(tc, s21_add_356);
  tcase_add_test(tc, s21_add_357);
  tcase_add_test(tc, s21_add_358);
  tcase_add_test(tc, s21_add_359);
  tcase_add_test(tc, s21_add_360);
  tcase_add_test(tc, s21_add_361);
  tcase_add_test(tc, s21_add_362);
  tcase_add_test(tc, s21_add_363);
  tcase_add_test(tc, s21_add_364);
  tcase_add_test(tc, s21_add_365);
  tcase_add_test(tc, s21_add_366);
  tcase_add_test(tc, s21_add_367);
  tcase_add_test(tc, s21_add_368);
  tcase_add_test(tc, s21_add_370);
  tcase_add_test(tc, s21_add_371);
  tcase_add_test(tc, s21_add_372);
  tcase_add_test(tc, s21_add_373);
  tcase_add_test(tc, s21_add_374);
  tcase_add_test(tc, s21_add_375);
  tcase_add_test(tc, s21_add_376);
  tcase_add_test(tc, s21_add_377);
  tcase_add_test(tc, s21_add_378);
  tcase_add_test(tc, s21_add_379);
  tcase_add_test(tc, s21_add_380);
  tcase_add_test(tc, s21_add_381);
  tcase_add_test(tc, s21_add_382);
  tcase_add_test(tc, s21_add_383);
  tcase_add_test(tc, s21_add_384);
  tcase_add_test(tc, s21_add_385);
  tcase_add_test(tc, s21_add_386);
  tcase_add_test(tc, s21_add_387);
  tcase_add_test(tc, s21_add_388);
  tcase_add_test(tc, s21_add_389);
  tcase_add_test(tc, s21_add_390);
  tcase_add_test(tc, s21_add_391);
  tcase_add_test(tc, s21_add_392);
  tcase_add_test(tc, s21_add_393);
  tcase_add_test(tc, s21_add_394);
  tcase_add_test(tc, s21_add_395);
  tcase_add_test(tc, s21_add_396);
  tcase_add_test(tc, s21_add_397);
  tcase_add_test(tc, s21_add_398);
  tcase_add_test(tc, s21_add_399);
  tcase_add_test(tc, s21_add_400);
  tcase_add_test(tc, s21_add_401);
  tcase_add_test(tc, s21_add_402);
  tcase_add_test(tc, s21_add_403);
  tcase_add_test(tc, s21_add_404);
  tcase_add_test(tc, s21_add_405);
  tcase_add_test(tc, s21_add_406);
  tcase_add_test(tc, s21_add_407);
  tcase_add_test(tc, s21_add_408);
  tcase_add_test(tc, s21_add_409);
  tcase_add_test(tc, s21_add_410);
  tcase_add_test(tc, s21_add_411);
  tcase_add_test(tc, s21_add_412);
  tcase_add_test(tc, s21_add_413);
  tcase_add_test(tc, s21_add_414);
  tcase_add_test(tc, s21_add_415);
  tcase_add_test(tc, s21_add_416);
  tcase_add_test(tc, s21_add_417);
  tcase_add_test(tc, s21_add_418);
  tcase_add_test(tc, s21_add_419);
  tcase_add_test(tc, s21_add_420);
  tcase_add_test(tc, s21_add_421);
  tcase_add_test(tc, s21_add_422);
  tcase_add_test(tc, s21_add_423);
  tcase_add_test(tc, s21_add_424);
  tcase_add_test(tc, s21_add_425);
  tcase_add_test(tc, s21_add_426);
  tcase_add_test(tc, s21_add_428);
  tcase_add_test(tc, s21_add_429);
  tcase_add_test(tc, s21_add_430);
  tcase_add_test(tc, s21_add_431);
  tcase_add_test(tc, s21_add_432);
  tcase_add_test(tc, s21_add_433);
  tcase_add_test(tc, s21_add_434);
  tcase_add_test(tc, s21_add_435);
  tcase_add_test(tc, s21_add_436);
  tcase_add_test(tc, s21_add_437);
  tcase_add_test(tc, s21_add_438);
  tcase_add_test(tc, s21_add_440);
  tcase_add_test(tc, s21_add_441);
  tcase_add_test(tc, s21_add_442);
  tcase_add_test(tc, s21_add_443);
  tcase_add_test(tc, s21_add_444);
  tcase_add_test(tc, s21_add_445);
  tcase_add_test(tc, s21_add_446);
  tcase_add_test(tc, s21_add_447);
  tcase_add_test(tc, s21_add_448);
  tcase_add_test(tc, s21_add_449);
  tcase_add_test(tc, s21_add_450);
  tcase_add_test(tc, s21_add_452);
  tcase_add_test(tc, s21_add_454);
  tcase_add_test(tc, s21_add_455);
  tcase_add_test(tc, s21_add_456);
  tcase_add_test(tc, s21_add_457);
  tcase_add_test(tc, s21_add_458);
  tcase_add_test(tc, s21_add_459);
  tcase_add_test(tc, s21_add_461);
  tcase_add_test(tc, s21_add_463);
  tcase_add_test(tc, s21_add_464);
  tcase_add_test(tc, s21_add_465);
  tcase_add_test(tc, s21_add_467);
  tcase_add_test(tc, s21_add_468);
  tcase_add_test(tc, s21_add_469);
  tcase_add_test(tc, s21_add_470);
  tcase_add_test(tc, s21_add_471);
  tcase_add_test(tc, s21_add_472);
  tcase_add_test(tc, s21_add_473);
  tcase_add_test(tc, s21_add_474);
  tcase_add_test(tc, s21_add_475);
  tcase_add_test(tc, s21_add_476);
  tcase_add_test(tc, s21_add_477);
  tcase_add_test(tc, s21_add_478);
  tcase_add_test(tc, s21_add_479);
  tcase_add_test(tc, s21_add_480);
  tcase_add_test(tc, s21_add_481);
  tcase_add_test(tc, s21_add_482);
  tcase_add_test(tc, s21_add_483);
  tcase_add_test(tc, s21_add_484);
  tcase_add_test(tc, s21_add_485);
  tcase_add_test(tc, s21_add_486);
  tcase_add_test(tc, s21_add_487);
  tcase_add_test(tc, s21_add_488);
  tcase_add_test(tc, s21_add_489);
  tcase_add_test(tc, s21_add_490);
  tcase_add_test(tc, s21_add_491);
  tcase_add_test(tc, s21_add_492);
  tcase_add_test(tc, s21_add_493);
  tcase_add_test(tc, s21_add_494);
  tcase_add_test(tc, s21_add_495);
  tcase_add_test(tc, s21_add_496);
  tcase_add_test(tc, s21_add_497);
  tcase_add_test(tc, s21_add_498);
  tcase_add_test(tc, s21_add_499);
  tcase_add_test(tc, s21_add_500);
  tcase_add_test(tc, fail_s21_add_1);
  tcase_add_test(tc, fail_s21_add_2);
  tcase_add_test(tc, fail_s21_add_3);
  tcase_add_test(tc, fail_s21_add_4);
  tcase_add_test(tc, fail_s21_add_5);
  tcase_add_test(tc, fail_s21_add_6);
  tcase_add_test(tc, fail_s21_add_7);
  tcase_add_test(tc, fail_s21_add_8);
  tcase_add_test(tc, fail_s21_add_9);
  tcase_add_test(tc, fail_s21_add_10);
  tcase_add_test(tc, fail_s21_add_11);
  tcase_add_test(tc, fail_s21_add_12);
  tcase_add_test(tc, fail_s21_add_13);
  tcase_add_test(tc, fail_s21_add_14);
  tcase_add_test(tc, fail_s21_add_15);
  tcase_add_test(tc, fail_s21_add_16);
  tcase_add_test(tc, fail_s21_add_17);
  tcase_add_test(tc, fail_s21_add_18);
  tcase_add_test(tc, fail_s21_add_19);
  tcase_add_test(tc, fail_s21_add_20);
  tcase_add_test(tc, fail_s21_add_21);
  tcase_add_test(tc, fail_s21_add_22);
  tcase_add_test(tc, fail_s21_add_23);
  tcase_add_test(tc, fail_s21_add_24);
  tcase_add_test(tc, fail_s21_add_25);
  tcase_add_test(tc, fail_s21_add_26);
  tcase_add_test(tc, fail_s21_add_27);
  tcase_add_test(tc, fail_s21_add_28);
  tcase_add_test(tc, fail_s21_add_29);
  tcase_add_test(tc, fail_s21_add_30);
  tcase_add_test(tc, fail_s21_add_31);
  tcase_add_test(tc, fail_s21_add_32);
  tcase_add_test(tc, fail_s21_add_33);
  tcase_add_test(tc, fail_s21_add_34);
  tcase_add_test(tc, fail_s21_add_35);
  tcase_add_test(tc, fail_s21_add_36);
  tcase_add_test(tc, fail_s21_add_37);
  tcase_add_test(tc, fail_s21_add_38);
  tcase_add_test(tc, fail_s21_add_39);
  tcase_add_test(tc, fail_s21_add_40);
  tcase_add_test(tc, fail_s21_add_41);
  tcase_add_test(tc, fail_s21_add_42);
  tcase_add_test(tc, fail_s21_add_43);
  tcase_add_test(tc, fail_s21_add_44);
  tcase_add_test(tc, fail_s21_add_45);
  tcase_add_test(tc, fail_s21_add_46);
  tcase_add_test(tc, fail_s21_add_47);
  tcase_add_test(tc, fail_s21_add_48);
  tcase_add_test(tc, fail_s21_add_49);
  tcase_add_test(tc, fail_s21_add_50);
  tcase_add_test(tc, fail_s21_add_51);
  tcase_add_test(tc, fail_s21_add_52);
  tcase_add_test(tc, fail_s21_add_53);
  tcase_add_test(tc, fail_s21_add_54);
  tcase_add_test(tc, fail_s21_add_55);
  tcase_add_test(tc, fail_s21_add_56);
  tcase_add_test(tc, fail_s21_add_57);
  tcase_add_test(tc, fail_s21_add_58);
  tcase_add_test(tc, fail_s21_add_59);
  tcase_add_test(tc, fail_s21_add_60);
  tcase_add_test(tc, fail_s21_add_61);
  tcase_add_test(tc, fail_s21_add_62);
  tcase_add_test(tc, fail_s21_add_63);
  tcase_add_test(tc, fail_s21_add_64);
  tcase_add_test(tc, fail_s21_add_65);
  tcase_add_test(tc, fail_s21_add_66);
  tcase_add_test(tc, fail_s21_add_67);
  tcase_add_test(tc, fail_s21_add_68);
  tcase_add_test(tc, fail_s21_add_69);
  tcase_add_test(tc, fail_s21_add_70);
  tcase_add_test(tc, fail_s21_add_71);
  tcase_add_test(tc, fail_s21_add_72);
  tcase_add_test(tc, fail_s21_add_73);
  tcase_add_test(tc, fail_s21_add_74);
  tcase_add_test(tc, fail_s21_add_75);
  tcase_add_test(tc, fail_s21_add_76);
  tcase_add_test(tc, fail_s21_add_77);
  tcase_add_test(tc, fail_s21_add_78);
  tcase_add_test(tc, fail_s21_add_79);
  tcase_add_test(tc, fail_s21_add_80);
  tcase_add_test(tc, fail_s21_add_81);
  tcase_add_test(tc, fail_s21_add_82);
  tcase_add_test(tc, fail_s21_add_83);
  tcase_add_test(tc, fail_s21_add_84);
  tcase_add_test(tc, fail_s21_add_85);
  tcase_add_test(tc, fail_s21_add_86);
  tcase_add_test(tc, fail_s21_add_87);
  tcase_add_test(tc, fail_s21_add_88);
  tcase_add_test(tc, fail_s21_add_89);
  tcase_add_test(tc, fail_s21_add_90);
  tcase_add_test(tc, fail_s21_add_91);
  tcase_add_test(tc, fail_s21_add_92);
  tcase_add_test(tc, fail_s21_add_93);
  tcase_add_test(tc, fail_s21_add_94);
  tcase_add_test(tc, fail_s21_add_95);
  tcase_add_test(tc, fail_s21_add_96);
  tcase_add_test(tc, fail_s21_add_97);
  tcase_add_test(tc, fail_s21_add_98);
  tcase_add_test(tc, fail_s21_add_99);
  tcase_add_test(tc, fail_s21_add_100);
  tcase_add_test(tc, fail_s21_add_101);
  tcase_add_test(tc, fail_s21_add_102);
  tcase_add_test(tc, fail_s21_add_103);
  tcase_add_test(tc, fail_s21_add_104);
  tcase_add_test(tc, fail_s21_add_105);
  tcase_add_test(tc, fail_s21_add_106);
  tcase_add_test(tc, fail_s21_add_107);
  tcase_add_test(tc, fail_s21_add_108);
  tcase_add_test(tc, fail_s21_add_109);
  tcase_add_test(tc, fail_s21_add_110);
  tcase_add_test(tc, fail_s21_add_111);
  tcase_add_test(tc, fail_s21_add_112);
  tcase_add_test(tc, fail_s21_add_113);
  tcase_add_test(tc, fail_s21_add_114);
  tcase_add_test(tc, fail_s21_add_115);
  tcase_add_test(tc, fail_s21_add_116);
  tcase_add_test(tc, fail_s21_add_117);
  tcase_add_test(tc, fail_s21_add_118);
  tcase_add_test(tc, fail_s21_add_119);
  tcase_add_test(tc, fail_s21_add_120);
  tcase_add_test(tc, fail_s21_add_121);
  tcase_add_test(tc, fail_s21_add_122);
  tcase_add_test(tc, fail_s21_add_123);
  tcase_add_test(tc, fail_s21_add_124);
  tcase_add_test(tc, fail_s21_add_125);
  tcase_add_test(tc, fail_s21_add_126);
  tcase_add_test(tc, fail_s21_add_127);
  tcase_add_test(tc, fail_s21_add_128);
  tcase_add_test(tc, fail_s21_add_129);
  tcase_add_test(tc, fail_s21_add_130);
  tcase_add_test(tc, fail_s21_add_131);
  tcase_add_test(tc, fail_s21_add_132);
  tcase_add_test(tc, fail_s21_add_133);
  tcase_add_test(tc, fail_s21_add_134);
  tcase_add_test(tc, fail_s21_add_135);
  tcase_add_test(tc, fail_s21_add_136);
  tcase_add_test(tc, fail_s21_add_137);
  tcase_add_test(tc, fail_s21_add_138);
  tcase_add_test(tc, fail_s21_add_139);
  tcase_add_test(tc, fail_s21_add_140);
  tcase_add_test(tc, fail_s21_add_141);
  tcase_add_test(tc, fail_s21_add_142);
  tcase_add_test(tc, fail_s21_add_143);
  tcase_add_test(tc, fail_s21_add_144);
  tcase_add_test(tc, fail_s21_add_145);
  tcase_add_test(tc, fail_s21_add_146);
  tcase_add_test(tc, fail_s21_add_147);
  tcase_add_test(tc, fail_s21_add_148);
  tcase_add_test(tc, fail_s21_add_149);
  tcase_add_test(tc, fail_s21_add_150);
  tcase_add_test(tc, fail_s21_add_151);
  tcase_add_test(tc, fail_s21_add_152);
  tcase_add_test(tc, fail_s21_add_153);
  tcase_add_test(tc, fail_s21_add_154);
  tcase_add_test(tc, fail_s21_add_155);
  tcase_add_test(tc, fail_s21_add_156);
  tcase_add_test(tc, fail_s21_add_157);
  tcase_add_test(tc, fail_s21_add_158);
  tcase_add_test(tc, fail_s21_add_159);
  tcase_add_test(tc, fail_s21_add_160);
  tcase_add_test(tc, fail_s21_add_161);
  tcase_add_test(tc, fail_s21_add_162);
  tcase_add_test(tc, fail_s21_add_163);
  tcase_add_test(tc, fail_s21_add_164);
  tcase_add_test(tc, fail_s21_add_165);
  tcase_add_test(tc, fail_s21_add_166);

  suite_add_tcase(c, tc);
  return c;
}
