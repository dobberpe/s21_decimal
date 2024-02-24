#include "s21_decimal_test.h"

START_TEST(invalid_dec_s21_div_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_div_2) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_1) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x10000}};
  s21_decimal dec_2 = {{0x4098aafb, 0xb2078939, 0x1d, 0x80000000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal dec_1 = {{0x186e6f36, 0x1, 0x0, 0x80020000}};
  s21_decimal dec_2 = {{0x7b1a, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xe5c1e595, 0x64aa4dc7, 0x303d53fc, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal dec_1 = {{0x46f24128, 0xd05, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0xfa886186, 0xc2666bfb, 0x496d1c25, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal dec_1 = {{0x86420f, 0x39cc5215, 0x14c, 0x800a0000}};
  s21_decimal dec_2 = {{0x57cb5d97, 0x4, 0x0, 0x40000}};
  s21_decimal dec_check = {{0xb9c10b74, 0xe2f51693, 0x6a297825, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal dec_1 = {{0xe137ec91, 0xf4d0b718, 0x19a, 0x10000}};
  s21_decimal dec_2 = {{0x3c088720, 0x1, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x28419153, 0xffc78721, 0x2e32aee6, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal dec_1 = {{0x195ba61f, 0xf8eab, 0x0, 0x80070000}};
  s21_decimal dec_2 = {{0x45160806, 0x11, 0x0, 0x50000}};
  s21_decimal dec_check = {{0xc03f6744, 0x3997ccbb, 0xbec25ac4, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal dec_1 = {{0x36eab8, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0xedf16712, 0x44ca, 0x0, 0x800b0000}};
  s21_decimal dec_check = {{0xa5f160c8, 0xbac3a4f6, 0x99befcc2, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal dec_1 = {{0x15d, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x6d1, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_9) {
  s21_decimal dec_1 = {{0xe5c66, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x179, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x5cadd5e6, 0x4abbad85, 0x50aa1200, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_10) {
  s21_decimal dec_1 = {{0x30e1805, 0x2d362, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x9967b412, 0x2ff9, 0x0, 0x0}};
  s21_decimal dec_check = {{0x1e7d74b3, 0x450a0f97, 0x30b880ac, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal dec_1 = {{0xa2904dd5, 0xf859f04b, 0x2734a, 0x0}};
  s21_decimal dec_2 = {{0x39b8c1a, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x11205340, 0x2fcb9ad6, 0x9e24bc74, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_12) {
  s21_decimal dec_1 = {{0xab5b49c3, 0x5a59720, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x55dcccbb, 0x5a5161, 0x0, 0x80040000}};
  s21_decimal dec_check = {{0x6c77a8f5, 0x591891ac, 0x33b781a5, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_13) {
  s21_decimal dec_1 = {{0x8b990a74, 0xe916fe65, 0x319a720, 0x130000}};
  s21_decimal dec_2 = {{0x1a49, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x5f9ed198, 0x65e8ddc9, 0x2e128394, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_15) {
  s21_decimal dec_1 = {{0xca250, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x1081d, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0xc92e43a5, 0x516a5952, 0x27919857, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_16) {
  s21_decimal dec_1 = {{0xb047880c, 0xad43b6df, 0x44795027, 0x0}};
  s21_decimal dec_2 = {{0x29b8500b, 0xaa82d0, 0x0, 0x0}};
  s21_decimal dec_check = {{0xb9f2bd26, 0x9b52d745, 0x8eab876c, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_18) {
  s21_decimal dec_1 = {{0xb4c9de75, 0x27bbc8a1, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x3c5, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0xa2da5dae, 0x120bbc19, 0x5fddffde, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_19) {
  s21_decimal dec_1 = {{0x9f4258a2, 0x5c0899c5, 0xacb3c22f, 0x0}};
  s21_decimal dec_2 = {{0x7efd41f0, 0x78aff87a, 0x0, 0xe0000}};
  s21_decimal dec_check = {{0x35e09eae, 0x2424c4b3, 0xc696e6ab, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_20) {
  s21_decimal dec_1 = {{0x3311a8d3, 0x13d4965, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x8dac4aab, 0x9025d925, 0x2679e024, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_21) {
  s21_decimal dec_1 = {{0x4b17e5b3, 0xa7e43c60, 0x60, 0x80000000}};
  s21_decimal dec_2 = {{0x11, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x7d6c502d, 0x6d55a523, 0x21e397e4, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_22) {
  s21_decimal dec_1 = {{0x9d2a59c2, 0xd5685b15, 0x23702ef, 0x80110000}};
  s21_decimal dec_2 = {{0x38772756, 0x0, 0x0, 0x80060000}};
  s21_decimal dec_check = {{0x3128a783, 0x3e5bd54c, 0xe9cd73b3, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_23) {
  s21_decimal dec_1 = {{0xa7758e3, 0x70df41d, 0x0, 0x50000}};
  s21_decimal dec_2 = {{0x4828c545, 0x9b2f0459, 0x4, 0xc0000}};
  s21_decimal dec_check = {{0xf6ae84f5, 0xcf8b70e3, 0xc14e5c21, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_24) {
  s21_decimal dec_1 = {{0xaa3f61e5, 0x6f15, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x547ec3ca, 0xde2b, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_25) {
  s21_decimal dec_1 = {{0x23dd, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0xe52b2224, 0xdf7f9cb8, 0x10c505e, 0x80170000}};
  s21_decimal dec_check = {{0x77e70741, 0x60a75e36, 0x5b747b0e, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_26) {
  s21_decimal dec_1 = {{0xd155fadd, 0x3b45266f, 0xda, 0x80000000}};
  s21_decimal dec_2 = {{0xcd39, 0x0, 0x0, 0x80040000}};
  s21_decimal dec_check = {{0xc2ef5c31, 0xaa530552, 0xf796ed16, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_28) {
  s21_decimal dec_1 = {{0x3c46325a, 0x1b, 0x0, 0x10000}};
  s21_decimal dec_2 = {{0x38b12c, 0x0, 0x0, 0x80060000}};
  s21_decimal dec_check = {{0x562c183e, 0xf7f78e27, 0x65bb1549, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_29) {
  s21_decimal dec_1 = {{0x5674d536, 0xf002e871, 0x21a12ef, 0x800a0000}};
  s21_decimal dec_2 = {{0xac0c7841, 0xc3, 0x0, 0x0}};
  s21_decimal dec_check = {{0xfc7fee24, 0x87458bad, 0xfa198bf7, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_30) {
  s21_decimal dec_1 = {{0x8c3485a9, 0x12626e0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x8fca62, 0x424a87a2, 0x108c, 0x80100000}};
  s21_decimal dec_check = {{0x556ab9c3, 0x5ffb06b3, 0x223c24f3, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_31) {
  s21_decimal dec_1 = {{0x79a7b77c, 0x660d5c2b, 0xf1, 0x90000}};
  s21_decimal dec_2 = {{0xb1b2e, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x2061a76d, 0xacb72509, 0xc5af00bd, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_32) {
  s21_decimal dec_1 = {{0xfd095745, 0xb5d91a4c, 0x1675543d, 0x80030000}};
  s21_decimal dec_2 = {{0x2b21a11, 0x671f189, 0x0, 0x110000}};
  s21_decimal dec_check = {{0x41e6b940, 0x8e4a45d2, 0x305ba5ef, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_33) {
  s21_decimal dec_1 = {{0x11ed0, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x346ea0, 0x0, 0x0, 0x80030000}};
  s21_decimal dec_check = {{0x3878dc6b, 0xd0b6bf8b, 0x450b1011, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_34) {
  s21_decimal dec_1 = {{0xaee150e, 0x2a7f5b51, 0x118547, 0x80000000}};
  s21_decimal dec_2 = {{0x5fe9f7, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x8bbb5178, 0xb6b6805c, 0x6ce14333, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_36) {
  s21_decimal dec_1 = {{0xf39483ad, 0x8686a, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x13a62, 0x0, 0x0, 0x80040000}};
  s21_decimal dec_check = {{0x9888e2cb, 0xdce844f7, 0x5f039b7a, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_37) {
  s21_decimal dec_1 = {{0x56c2955e, 0x53504c4a, 0x1e2, 0x800c0000}};
  s21_decimal dec_2 = {{0x16395d19, 0x6fb569be, 0x101c, 0x800d0000}};
  s21_decimal dec_check = {{0x38308333, 0xdef4843f, 0x25c953f5, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_38) {
  s21_decimal dec_1 = {{0x335, 0x0, 0x0, 0x80010000}};
  s21_decimal dec_2 = {{0x2c7, 0x0, 0x0, 0x30000}};
  s21_decimal dec_check = {{0xf0fd7ac7, 0x9c0320fd, 0x254f8d14, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_39) {
  s21_decimal dec_1 = {{0xa3c7f2f7, 0x5760, 0x0, 0x0}};
  s21_decimal dec_2 = {{0xb8357234, 0xafad160, 0x29bec55, 0x801a0000}};
  s21_decimal dec_check = {{0xe3ee1e2a, 0xee48a857, 0x2671c77c, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_40) {
  s21_decimal dec_1 = {{0x5f8464, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x2fc232, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_41) {
  s21_decimal dec_1 = {{0xd9302408, 0xa8ebd373, 0x0, 0x50000}};
  s21_decimal dec_2 = {{0x3684c850, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xe55761de, 0xa9b27c5c, 0x2affc2ee, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_42) {
  s21_decimal dec_1 = {{0xaa337d63, 0x88bac348, 0x25, 0x80020000}};
  s21_decimal dec_2 = {{0x5754cd9, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x50dd562a, 0x74521e8, 0xf44eabd3, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_43) {
  s21_decimal dec_1 = {{0x813866b7, 0xef424c44, 0x8fc2, 0x80140000}};
  s21_decimal dec_2 = {{0x40f, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x2806820e, 0x28100b54, 0xd320e9f9, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_44) {
  s21_decimal dec_1 = {{0x2de, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0xf83eadd8, 0x66560, 0x0, 0xe0000}};
  s21_decimal dec_check = {{0x7115f7b4, 0xad1e35e2, 0x83bca5c9, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_45) {
  s21_decimal dec_1 = {{0xda5c824d, 0x151c3f6, 0x0, 0xe0000}};
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xd7ec9aab, 0x3e56f451, 0x66660d42, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_46) {
  s21_decimal dec_1 = {{0xa2d85a80, 0x205ac2ff, 0x1e5, 0x80000000}};
  s21_decimal dec_2 = {{0x43903, 0x0, 0x0, 0x80020000}};
  s21_decimal dec_check = {{0xdaae5dce, 0xeb7b96b7, 0x687cd16f, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_47) {
  s21_decimal dec_1 = {{0x3ad7e31f, 0x9dca1c6d, 0xc06, 0x80000000}};
  s21_decimal dec_2 = {{0x43547341, 0x54, 0x0, 0x0}};
  s21_decimal dec_check = {{0x9118438f, 0xc9db2029, 0x32b41fa1, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_48) {
  s21_decimal dec_1 = {{0x49086a35, 0x10183, 0x0, 0x80020000}};
  s21_decimal dec_2 = {{0x7483f603, 0x2d, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xcd590cb5, 0x9b88ea5e, 0x2edc8ba1, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_49) {
  s21_decimal dec_1 = {{0x424663f8, 0x4ea8158, 0xcce1c21, 0x80000000}};
  s21_decimal dec_2 = {{0x1b90, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x4233627a, 0xc68aded0, 0xb57a792c, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_51) {
  s21_decimal dec_1 = {{0x1d481fce, 0x1e2574, 0x0, 0x800a0000}};
  s21_decimal dec_2 = {{0x20, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xbe8ad2f7, 0x24ccb83d, 0x0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_52) {
  s21_decimal dec_1 = {{0xc154d87f, 0x1d851950, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x5a46c854, 0x5a70a, 0x0, 0x0}};
  s21_decimal dec_check = {{0xc5bb7e4, 0x3610016d, 0x2b32f8c5, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_53) {
  s21_decimal dec_1 = {{0xebffed6c, 0xa90b020, 0x89a1a83b, 0x80000000}};
  s21_decimal dec_2 = {{0xc04b7520, 0x588d875, 0x15b1c5a2, 0x0}};
  s21_decimal dec_check = {{0x370ce3eb, 0x12ff25c5, 0xccfd1fb2, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_56) {
  s21_decimal dec_1 = {{0x4618487b, 0x1, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x3504460b, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xea6c8e17, 0xc0e0e6, 0xc6be30ae, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_57) {
  s21_decimal dec_1 = {{0xb4dada68, 0xbcd69ff0, 0x39, 0x80000000}};
  s21_decimal dec_2 = {{0xc6978d77, 0xcf84, 0x0, 0x80030000}};
  s21_decimal dec_check = {{0xc601bf83, 0xc4c3cb5f, 0x96d3fdce, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_58) {
  s21_decimal dec_1 = {{0xdd15563a, 0xb0e80be4, 0x5e4a15d, 0x80000000}};
  s21_decimal dec_2 = {{0x27ac5f5e, 0x1, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x19313303, 0x522cf679, 0x76cc6814, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_59) {
  s21_decimal dec_1 = {{0x41ded826, 0x3444a183, 0x8c49fe6f, 0x0}};
  s21_decimal dec_2 = {{0x103bafcd, 0xf41327a4, 0x3139830, 0x0}};
  s21_decimal dec_check = {{0x40ff04f8, 0x9be1174d, 0x93571adb, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_61) {
  s21_decimal dec_1 = {{0xc576648d, 0x26b9c1bb, 0x0, 0x800b0000}};
  s21_decimal dec_2 = {{0x2b, 0x0, 0x0, 0x20000}};
  s21_decimal dec_check = {{0x17a7ab89, 0xc9f9bf8d, 0xd1afaeda, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_63) {
  s21_decimal dec_1 = {{0xbb11f259, 0x48, 0x0, 0x80070000}};
  s21_decimal dec_2 = {{0xa, 0x0, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0xbb11f259, 0x48, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_64) {
  s21_decimal dec_1 = {{0x17ad91b, 0xfe92f36a, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x713, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x9e5122bb, 0xa2df8038, 0x20baaec7, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_65) {
  s21_decimal dec_1 = {{0x15e186c4, 0xbe75d0b, 0xb83f824, 0x20000}};
  s21_decimal dec_2 = {{0x5063bebd, 0xfbef40e5, 0x3, 0x0}};
  s21_decimal dec_check = {{0x8460ce0a, 0x938d0912, 0x9cafaec5, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_66) {
  s21_decimal dec_1 = {{0xb1279888, 0xa05dda55, 0x2, 0x0}};
  s21_decimal dec_2 = {{0x29d4b050, 0xa2, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x51a50fb1, 0xa3582a10, 0xe0c47ccb, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_69) {
  s21_decimal dec_1 = {{0x2e09a3a9, 0x71da9ba5, 0x4362, 0x60000}};
  s21_decimal dec_2 = {{0x23b5ee19, 0x805, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xa7c6f019, 0x7425553e, 0x7499d7bc, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_70) {
  s21_decimal dec_1 = {{0xd0dd1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x833a7eb7, 0x0, 0x0, 0x800a0000}};
  s21_decimal dec_check = {{0x7838101, 0x79813986, 0x7d8e2509, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_71) {
  s21_decimal dec_1 = {{0xacb0, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x9ea0c, 0x0, 0x0, 0x20000}};
  s21_decimal dec_check = {{0xf28c7860, 0xc583811d, 0xdbd8f987, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_72) {
  s21_decimal dec_1 = {{0xd164b65d, 0x1799, 0x0, 0x70000}};
  s21_decimal dec_2 = {{0x20f45553, 0x1406, 0x0, 0xe0000}};
  s21_decimal dec_check = {{0x4edad06e, 0x22a8692a, 0x261569c2, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_73) {
  s21_decimal dec_1 = {{0x172d32be, 0x16, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x56ac9021, 0x52dd1a4e, 0xe4, 0x800b0000}};
  s21_decimal dec_check = {{0x92de73d3, 0x9a985553, 0x48c98e18, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_77) {
  s21_decimal dec_1 = {{0x170fcd8c, 0x550782f5, 0xdf9ad406, 0xd0000}};
  s21_decimal dec_2 = {{0xb5233752, 0x823, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0xffe6f82c, 0xae2fa68d, 0xf9da5b25, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_78) {
  s21_decimal dec_1 = {{0xc6bfcd68, 0x720e62d, 0x28f934e3, 0x80000000}};
  s21_decimal dec_2 = {{0x4652fd17, 0xb6b9ff7e, 0x64c7, 0xc0000}};
  s21_decimal dec_check = {{0xadb3a8bb, 0xabc5285, 0x5617d1bb, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_79) {
  s21_decimal dec_1 = {{0x488730d7, 0xc0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x58ab2, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x2fbf5fe, 0x4e72ce0f, 0x49794d98, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_80) {
  s21_decimal dec_1 = {{0x4026de01, 0xd6fbf113, 0x1abd8e, 0x80000000}};
  s21_decimal dec_2 = {{0xfadbaf3e, 0x29091de9, 0x7, 0x800c0000}};
  s21_decimal dec_check = {{0x3d376000, 0xb5245b3, 0x4f150553, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_81) {
  s21_decimal dec_1 = {{0xb1cc2bfd, 0x3874cc4e, 0x5c6b, 0x0}};
  s21_decimal dec_2 = {{0x9c385, 0x0, 0x0, 0x20000}};
  s21_decimal dec_check = {{0xfc10bff4, 0x7b8f8359, 0xdc62d206, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_82) {
  s21_decimal dec_1 = {{0x4f59e411, 0x456086ef, 0x11, 0x70000}};
  s21_decimal dec_2 = {{0x3ca7f5d, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0xb1c6a651, 0xfe895a8e, 0xa1da9d40, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_83) {
  s21_decimal dec_1 = {{0x9bed11a5, 0x56d53e1d, 0x0, 0x80040000}};
  s21_decimal dec_2 = {{0x141e97e, 0x0, 0x0, 0x50000}};
  s21_decimal dec_check = {{0xceee45f9, 0x8b924d3b, 0x5fd4d3ca, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_84) {
  s21_decimal dec_1 = {{0x16c0f880, 0xe69d2ca6, 0x8312c5e1, 0x0}};
  s21_decimal dec_2 = {{0x25b0c2c, 0x0, 0x0, 0x80060000}};
  s21_decimal dec_check = {{0x2cc948f6, 0x405f7927, 0x212a4bb7, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_85) {
  s21_decimal dec_1 = {{0x5abf2c6e, 0xcc871253, 0x83a2445, 0x80000000}};
  s21_decimal dec_2 = {{0x7dd1c87, 0x4c3b0dfe, 0x1bb2de, 0x0}};
  s21_decimal dec_check = {{0x37349c34, 0x874f9e02, 0xf5b0c9fe, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_86) {
  s21_decimal dec_1 = {{0xa8e47eea, 0xa79d02ce, 0x2b, 0x0}};
  s21_decimal dec_2 = {{0x70ac0, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x196836bf, 0x2174a704, 0x3861a4f7, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_87) {
  s21_decimal dec_1 = {{0xdb3c151a, 0x52cb1321, 0x205, 0x0}};
  s21_decimal dec_2 = {{0x94eb00bf, 0x26358860, 0x19777, 0x80040000}};
  s21_decimal dec_check = {{0x42588b4a, 0x3e1a04d6, 0xa03f68c2, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_88) {
  s21_decimal dec_1 = {{0x9ef81bed, 0x1, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0xb88ed2b4, 0xa9609109, 0x1ed, 0x80130000}};
  s21_decimal dec_check = {{0xf4095a20, 0x98e237b2, 0xf7074a45, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_89) {
  s21_decimal dec_1 = {{0x635ea1c6, 0x865ecb8d, 0x0, 0x130000}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x635ea1c6, 0x865ecb8d, 0x0, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_90) {
  s21_decimal dec_1 = {{0x196a126d, 0x0, 0x0, 0x20000}};
  s21_decimal dec_2 = {{0x3c, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x2a5b740b, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_91) {
  s21_decimal dec_1 = {{0x43f243a, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x9aaf1fd3, 0x1, 0x0, 0x70000}};
  s21_decimal dec_check = {{0xfcf43f63, 0xf8c9fd27, 0x21696571, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_92) {
  s21_decimal dec_1 = {{0xfc99272d, 0xbe40e38a, 0x1, 0x80000000}};
  s21_decimal dec_2 = {{0x69e83622, 0x7b691469, 0x682, 0x80090000}};
  s21_decimal dec_check = {{0xe1a7f276, 0x9a0d494, 0x21cc7ea7, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_93) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x15c7, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_95) {
  s21_decimal dec_1 = {{0x131fd0, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x2d7f, 0x0, 0x0, 0x50000}};
  s21_decimal dec_check = {{0x57ecd562, 0xd889532b, 0x22c54013, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_96) {
  s21_decimal dec_1 = {{0x806ce481, 0x7a006c4e, 0x0, 0xa0000}};
  s21_decimal dec_2 = {{0xc64a3675, 0x7035f1ff, 0x298a4ea, 0x80160000}};
  s21_decimal dec_check = {{0x1ab596ef, 0x74696810, 0x235a2c9f, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_97) {
  s21_decimal dec_1 = {{0x1566, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0xc8cc46c7, 0x1, 0x0, 0x80070000}};
  s21_decimal dec_check = {{0x15256890, 0x1219738, 0xe6f5fa09, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_98) {
  s21_decimal dec_1 = {{0xc7a488fc, 0x40c23973, 0x1, 0x80000000}};
  s21_decimal dec_2 = {{0x381, 0x0, 0x0, 0x30000}};
  s21_decimal dec_check = {{0x1a0bb24d, 0x321dcfc, 0x53420e31, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_99) {
  s21_decimal dec_1 = {{0xc71d52c4, 0xa3caebbc, 0xd875, 0x0}};
  s21_decimal dec_2 = {{0x2fca01c7, 0x0, 0x0, 0x0}};
  s21_decimal dec_check = {{0x2e3d5054, 0xce2a2c2a, 0x29320207, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_div_cases(void) {
  Suite *c = suite_create("s21_div_cases");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, invalid_dec_s21_div_1);
  tcase_add_test(tc, invalid_dec_s21_div_2);
  tcase_add_test(tc, invalid_dec_s21_div_3);
  tcase_add_test(tc, invalid_dec_s21_div_4);
  tcase_add_test(tc, invalid_dec_s21_div_5);
  tcase_add_test(tc, invalid_dec_s21_div_6);
  tcase_add_test(tc, invalid_dec_s21_div_7);
  tcase_add_test(tc, invalid_dec_s21_div_8);
  tcase_add_test(tc, invalid_dec_s21_div_9);
  tcase_add_test(tc, invalid_dec_s21_div_10);
  tcase_add_test(tc, invalid_dec_s21_div_11);
  tcase_add_test(tc, invalid_dec_s21_div_12);
  tcase_add_test(tc, invalid_dec_s21_div_13);
  tcase_add_test(tc, invalid_dec_s21_div_14);
  tcase_add_test(tc, invalid_dec_s21_div_15);
  tcase_add_test(tc, invalid_dec_s21_div_16);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_9);
  tcase_add_test(tc, s21_div_10);
  tcase_add_test(tc, s21_div_11);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_18);
  tcase_add_test(tc, s21_div_19);
  tcase_add_test(tc, s21_div_20);
  tcase_add_test(tc, s21_div_21);
  tcase_add_test(tc, s21_div_22);
  tcase_add_test(tc, s21_div_23);
  tcase_add_test(tc, s21_div_24);
  tcase_add_test(tc, s21_div_25);
  tcase_add_test(tc, s21_div_26);
  tcase_add_test(tc, s21_div_28);
  tcase_add_test(tc, s21_div_29);
  tcase_add_test(tc, s21_div_30);
  tcase_add_test(tc, s21_div_31);
  tcase_add_test(tc, s21_div_32);
  tcase_add_test(tc, s21_div_33);
  tcase_add_test(tc, s21_div_34);
  tcase_add_test(tc, s21_div_36);
  tcase_add_test(tc, s21_div_37);
  tcase_add_test(tc, s21_div_38);
  tcase_add_test(tc, s21_div_39);
  tcase_add_test(tc, s21_div_40);
  tcase_add_test(tc, s21_div_41);
  tcase_add_test(tc, s21_div_42);
  tcase_add_test(tc, s21_div_43);
  tcase_add_test(tc, s21_div_44);
  tcase_add_test(tc, s21_div_45);
  tcase_add_test(tc, s21_div_46);
  tcase_add_test(tc, s21_div_47);
  tcase_add_test(tc, s21_div_48);
  tcase_add_test(tc, s21_div_49);
  tcase_add_test(tc, s21_div_51);
  tcase_add_test(tc, s21_div_52);
  tcase_add_test(tc, s21_div_53);
  tcase_add_test(tc, s21_div_56);
  tcase_add_test(tc, s21_div_57);
  tcase_add_test(tc, s21_div_58);
  tcase_add_test(tc, s21_div_59);
  tcase_add_test(tc, s21_div_61);
  tcase_add_test(tc, s21_div_63);
  tcase_add_test(tc, s21_div_64);
  tcase_add_test(tc, s21_div_65);
  tcase_add_test(tc, s21_div_66);
  tcase_add_test(tc, s21_div_69);
  tcase_add_test(tc, s21_div_70);
  tcase_add_test(tc, s21_div_71);
  tcase_add_test(tc, s21_div_72);
  tcase_add_test(tc, s21_div_73);
  tcase_add_test(tc, s21_div_77);
  tcase_add_test(tc, s21_div_78);
  tcase_add_test(tc, s21_div_79);
  tcase_add_test(tc, s21_div_80);
  tcase_add_test(tc, s21_div_81);
  tcase_add_test(tc, s21_div_82);
  tcase_add_test(tc, s21_div_83);
  tcase_add_test(tc, s21_div_84);
  tcase_add_test(tc, s21_div_85);
  tcase_add_test(tc, s21_div_86);
  tcase_add_test(tc, s21_div_87);
  tcase_add_test(tc, s21_div_88);
  tcase_add_test(tc, s21_div_89);
  tcase_add_test(tc, s21_div_90);
  tcase_add_test(tc, s21_div_91);
  tcase_add_test(tc, s21_div_92);
  tcase_add_test(tc, s21_div_93);
  tcase_add_test(tc, s21_div_95);
  tcase_add_test(tc, s21_div_96);
  tcase_add_test(tc, s21_div_97);
  tcase_add_test(tc, s21_div_98);
  tcase_add_test(tc, s21_div_99);

  suite_add_tcase(c, tc);
  return c;
}
