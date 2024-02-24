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

START_TEST(fail_s21_add_1) {
  // -202675274639644590064819
  s21_decimal dec_1 = {{0x3ff3c4b3, 0xc749121, 0x2aeb, 0x80000000}};
  // -79228162514264337592757167561
  s21_decimal dec_2 = {{0xd11aa5c9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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

  suite_add_tcase(c, tc);
  return c;
}
