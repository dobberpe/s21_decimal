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


START_TEST(s21_div_101) {
    s21_decimal dec_1 = {{0xba609b00, 0x142044f, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x9a02d183, 0x793, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x1754b0ff, 0xd9e6b65c, 0x23281442, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_103) {
    s21_decimal dec_1 = {{0x5897463a, 0x565, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x82a26d18, 0x6e3343, 0x0, 0x80090000}};
    s21_decimal dec_check = {{0x760a4418, 0x2208c510, 0x3dcd3bb7, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_104) {
    s21_decimal dec_1 = {{0xf20110ca, 0x57e, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x385, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x698071a7, 0xc4459488, 0xd8b4f53e, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_105) {
    s21_decimal dec_1 = {{0x46901247, 0x1aa195, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x1e5, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x384c093d, 0x4fd128f7, 0x31f0a6a5, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_106) {
    s21_decimal dec_1 = {{0xa318bc5f, 0x4aef50fd, 0x34, 0x0}};
    s21_decimal dec_2 = {{0xea1063e9, 0xf6c8ed2e, 0x10, 0xe0000}};
    s21_decimal dec_check = {{0x81904185, 0x77ccc30d, 0x639a6a29, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_107) {
    s21_decimal dec_1 = {{0xa57e6bd8, 0x30dfe, 0x0, 0x80040000}};
    s21_decimal dec_2 = {{0x1c1, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0x70de458f, 0x86bdfd7c, 0x3de01714, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_108) {
    s21_decimal dec_1 = {{0x5fc70708, 0xde8473ca, 0x4270bd, 0x0}};
    s21_decimal dec_2 = {{0x786f, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xbf23d942, 0xa2b1ce1, 0x542dde23, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_109) {
    s21_decimal dec_1 = {{0x6b0686f7, 0x13, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x26347db7, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xc8f9eab3, 0x9ac437aa, 0x2a0acf28, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_110) {
    s21_decimal dec_1 = {{0x32926674, 0xa44e39, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x7e1aef, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x1afd3cf9, 0x46435d8a, 0xb4d12cd2, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_div_113) {
    s21_decimal dec_1 = {{0x44d105f2, 0x5fc90c7c, 0x1f082002, 0x1b0000}};
    s21_decimal dec_2 = {{0x254c5, 0x0, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x87c2fe3f, 0x38af3384, 0xcb1f8916, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_114) {
    s21_decimal dec_1 = {{0xe52d8b28, 0xfb86ca62, 0x3baffc, 0x0}};
    s21_decimal dec_2 = {{0x22f0557d, 0x1a89d5a7, 0x0, 0x120000}};
    s21_decimal dec_check = {{0x4a049152, 0xaa3ed8c0, 0x79ec7b2f, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_115) {
    s21_decimal dec_1 = {{0x13abe98b, 0xb8e4b86d, 0x48573, 0x30000}};
    s21_decimal dec_2 = {{0x101046b9, 0x2e810ca, 0xe0, 0x80000000}};
    s21_decimal dec_check = {{0x11a046d1, 0x6fe5dbe9, 0x2abd68ec, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_117) {
    s21_decimal dec_1 = {{0xd0567a66, 0x114668d, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0xcff32623, 0x4a6, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x233e5df7, 0x74698c01, 0x3126c2d1, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_118) {
    s21_decimal dec_1 = {{0x2f5cfd0, 0x0, 0x0, 0x70000}};
    s21_decimal dec_2 = {{0x79, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0x7821d9eb, 0x372cf049, 0x849f49ad, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_119) {
    s21_decimal dec_1 = {{0x33838e11, 0x35c36e6b, 0x1633, 0x0}};
    s21_decimal dec_2 = {{0x4510411f, 0x24c60af, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8a48cb7a, 0x5ce837e7, 0xcc8a307b, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_120) {
    s21_decimal dec_1 = {{0xd1d36a85, 0x52d8acf7, 0xd38f2d4, 0x0}};
    s21_decimal dec_2 = {{0xeba9ec5, 0x7d9, 0x0, 0xd0000}};
    s21_decimal dec_check = {{0xa935dd43, 0x1381c30f, 0x993c54de, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_121) {
    s21_decimal dec_1 = {{0x6a837293, 0x2a912105, 0x1, 0x80000000}};
    s21_decimal dec_2 = {{0x4352ab5a, 0x17892bf9, 0x1084, 0x80140000}};
    s21_decimal dec_check = {{0xa59a7a8c, 0xe286a526, 0x5920f3c4, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_122) {
    s21_decimal dec_1 = {{0xb823fc1a, 0x6c5fc918, 0x46152d, 0x80000000}};
    s21_decimal dec_2 = {{0x240dbad, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x2e8cbb5d, 0xcde34b85, 0x4869f6e2, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_123) {
    s21_decimal dec_1 = {{0x921e5f2, 0x3df4346, 0x1c2363, 0x130000}};
    s21_decimal dec_2 = {{0x230, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0xb3e241c6, 0xb95b8c87, 0xc446d6ac, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_124) {
    s21_decimal dec_1 = {{0x4962401f, 0x1d2205, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xea74f116, 0xe6e, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x57ba68f6, 0x8384fb79, 0xa6f6716e, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_126) {
    s21_decimal dec_1 = {{0x14abf941, 0xe2f943ea, 0x957b, 0x80000000}};
    s21_decimal dec_2 = {{0x8b9eb9af, 0x16, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0xd3052dc9, 0x6ba6151a, 0xeb8eb8fe, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_127) {
    s21_decimal dec_1 = {{0xbd612b26, 0x4c3b8e92, 0x12cb, 0x0}};
    s21_decimal dec_2 = {{0x4f879aa3, 0x2e6a, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xed374cf9, 0xb8ce1533, 0x38316302, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_128) {
    s21_decimal dec_1 = {{0x686d1ee4, 0x5b7e803b, 0xb, 0x80000000}};
    s21_decimal dec_2 = {{0xf48eb0c8, 0x11497cc, 0x0, 0x800c0000}};
    s21_decimal dec_check = {{0x2aa2e1fe, 0x2e1a8bcf, 0x56f3a255, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_129) {
    s21_decimal dec_1 = {{0xe9d54a63, 0x80c6edde, 0x863a4204, 0x0}};
    s21_decimal dec_2 = {{0xd75d599e, 0x60738cad, 0xe09, 0x800a0000}};
    s21_decimal dec_check = {{0xee1bd224, 0x241c4925, 0xca7f4f73, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_130) {
    s21_decimal dec_1 = {{0xc1eeed1e, 0x1d0b34f2, 0x17, 0x0}};
    s21_decimal dec_2 = {{0x248, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x2bf329ba, 0xf919d09c, 0xebe6f987, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_131) {
    s21_decimal dec_1 = {{0x8a9ae2, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x10f, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x827cb198, 0xd21c4868, 0x6c4e2c1d, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_132) {
    s21_decimal dec_1 = {{0x521c4553, 0xc9430e85, 0x455522, 0x80000000}};
    s21_decimal dec_2 = {{0x424afe4c, 0x303b9e6a, 0x2, 0x80000000}};
    s21_decimal dec_check = {{0xb31f34ae, 0x8170f703, 0x4316b080, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_133) {
    s21_decimal dec_1 = {{0x752130d8, 0x4b6e8564, 0x1245aab, 0x80000}};
    s21_decimal dec_2 = {{0x9268b, 0x0, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x7c7b5c00, 0x11678c82, 0xbe6ecd7e, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_134) {
    s21_decimal dec_1 = {{0x52c4ee09, 0x3bec1b4f, 0x4c00, 0x80040000}};
    s21_decimal dec_2 = {{0xd705af13, 0xb9003981, 0x1, 0x800e0000}};
    s21_decimal dec_check = {{0x8505941e, 0x63f1fe16, 0x247e6cea, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_135) {
    s21_decimal dec_1 = {{0x34addf6e, 0x369, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x128e, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8189435e, 0x768cd484, 0xff1e8757, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_136) {
    s21_decimal dec_1 = {{0x19c556b4, 0x1f247ff9, 0x1c5, 0x0}};
    s21_decimal dec_2 = {{0x12f85f0, 0x0, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0xd8fd81eb, 0x9963f5ad, 0x87c6a9de, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_137) {
    s21_decimal dec_1 = {{0x6f4ca5b, 0xc9cff61f, 0x36ea, 0x80000000}};
    s21_decimal dec_2 = {{0x43b349f7, 0xe956317f, 0xd280527, 0x1b0000}};
    s21_decimal dec_check = {{0x97a47028, 0xd490a83d, 0xcdcdce57, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_138) {
    s21_decimal dec_1 = {{0x24e17450, 0xb852fd61, 0xda, 0x80000000}};
    s21_decimal dec_2 = {{0x3b3976de, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xb5675e36, 0xdbcd7407, 0x833442d4, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_139) {
    s21_decimal dec_1 = {{0x372c8370, 0x181669bd, 0x13, 0x0}};
    s21_decimal dec_2 = {{0xcb25c, 0x0, 0x0, 0x40000}};
    s21_decimal dec_check = {{0x239e022a, 0x63c84f0c, 0x88c67bf6, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_140) {
    s21_decimal dec_1 = {{0x341f676c, 0x3e82b3bb, 0x9609f8, 0x80000000}};
    s21_decimal dec_2 = {{0x416b2ed7, 0xbcc031b0, 0x17e, 0x50000}};
    s21_decimal dec_check = {{0xa8322218, 0xad526535, 0x53033375, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_141) {
    s21_decimal dec_1 = {{0xbbc1b81b, 0xc50c1d2, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x1fdc670, 0x0, 0x0, 0x40000}};
    s21_decimal dec_check = {{0x72876af8, 0x680178b6, 0x55d4200e, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_142) {
    s21_decimal dec_1 = {{0x9d225131, 0x3eb5b8a0, 0x1d9f1, 0x20000}};
    s21_decimal dec_2 = {{0x34507, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xbe8ed5ae, 0xbc6a88e6, 0x21bfd854, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_143) {
    s21_decimal dec_1 = {{0xb1079e2e, 0x7d2998c1, 0x3565f1a6, 0x80000000}};
    s21_decimal dec_2 = {{0x5621aaa2, 0xfebf2b68, 0x2, 0x80000000}};
    s21_decimal dec_check = {{0x9c3ef127, 0x8c9cc70b, 0x60a6034e, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_144) {
    s21_decimal dec_1 = {{0x17e49d0b, 0x2, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x27e, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xb8328ee, 0x3eb540ca, 0x2d88c142, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_145) {
    s21_decimal dec_1 = {{0x170178c1, 0x14d749, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xd281d1f4, 0x369fd, 0x0, 0x0}};
    s21_decimal dec_check = {{0xf1020364, 0x95632b89, 0xc53f4850, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_div_146) {
//     s21_decimal dec_1 = {{0xfe6d9ab0, 0x11, 0x0, 0x80000000}};
//     s21_decimal dec_2 = {{0xccfae07f, 0xf95b851a, 0x24681264, 0x80180000}};
//     s21_decimal dec_check = {{0xdd3539f4, 0xf1893fda, 0xdda0e74b, 0x160000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_147) {
    s21_decimal dec_1 = {{0x82a7b8a6, 0x7ed, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xc48cdc, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x3fc2090f, 0xaad1755f, 0xdaa78057, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_148) {
    s21_decimal dec_1 = {{0x72c9f34, 0x19affc, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xf, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x5a1dbf78, 0x111ffd, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_149) {
    s21_decimal dec_1 = {{0x60, 0x0, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x30, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_150) {
    s21_decimal dec_1 = {{0xa7883c55, 0x1, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3086b6, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0x2b863c9a, 0x82338dd9, 0x48320e8d, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_152) {
    s21_decimal dec_1 = {{0x7f003, 0x0, 0x0, 0x40000}};
    s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x7f003, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_153) {
    s21_decimal dec_1 = {{0xdb94e842, 0x6f274098, 0x0, 0x80010000}};
    s21_decimal dec_2 = {{0xa68879fb, 0x39218265, 0x61d69, 0x170000}};
    s21_decimal dec_check = {{0xe848cce8, 0xb25fbd67, 0x23023285, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_154) {
    s21_decimal dec_1 = {{0xc434f7c9, 0x3101, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x5f2b4aa5, 0xb021539b, 0x0, 0x800e0000}};
    s21_decimal dec_check = {{0x5a6337e1, 0x6ba013e7, 0x892f23b0, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_155) {
    s21_decimal dec_1 = {{0x6bb1395d, 0x67, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x2b1, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x4c004d48, 0x93aff97f, 0xd04f2582, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_156) {
    s21_decimal dec_1 = {{0x49e0be19, 0x75da771b, 0x25, 0x80020000}};
    s21_decimal dec_2 = {{0x44635a07, 0x5414, 0x0, 0x10000}};
    s21_decimal dec_check = {{0xead059aa, 0xe4ee141e, 0xf186a74a, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_157) {
    s21_decimal dec_1 = {{0x85e31cc8, 0x610b4760, 0x0, 0x60000}};
    s21_decimal dec_2 = {{0xb6a96a3c, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x69884d66, 0x360c4bed, 0x49bac2ff, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_158) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x10255, 0x0, 0x0, 0x80000000}};
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


START_TEST(s21_div_160) {
    s21_decimal dec_1 = {{0xdb26792e, 0x848e5d2, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xc85de1e6, 0x11, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xcbb0467b, 0xd889ad07, 0xfc8f1786, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_161) {
    s21_decimal dec_1 = {{0x3ff6a0, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xb3cdc904, 0x137d4, 0x0, 0x80000}};
    s21_decimal dec_check = {{0x32dcbfe6, 0xa8c1c926, 0x27814bed, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_163) {
    s21_decimal dec_1 = {{0xb767d45c, 0xd3ce08f, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xad4a956b, 0x8d0f, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x61ba19d1, 0xaec2ce58, 0xc6b92116, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_164) {
    s21_decimal dec_1 = {{0x55893467, 0xeb8c9567, 0xcc41, 0x80070000}};
    s21_decimal dec_2 = {{0x27b080ab, 0xb2, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xc1e7b5a2, 0xcdacd28f, 0x28bb7f46, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_165) {
    s21_decimal dec_1 = {{0x2cd4b662, 0x1, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x5d9ea131, 0xf6a6aae2, 0x3054658, 0x80150000}};
    s21_decimal dec_check = {{0x79e392f5, 0x64659046, 0xae730525, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_166) {
    s21_decimal dec_1 = {{0x1d725ce8, 0xa9efd3e, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x2093f147, 0x42f3, 0x0, 0x0}};
    s21_decimal dec_check = {{0x5e6a50a0, 0xad4cd084, 0x21980317, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_167) {
    s21_decimal dec_1 = {{0xe31ea4c9, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x393f622f, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x95d88b62, 0xc175c676, 0x8030edbe, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_168) {
    s21_decimal dec_1 = {{0x7b911da0, 0x156ef3b6, 0x52b91, 0x80000000}};
    s21_decimal dec_2 = {{0xf442efdd, 0x92211fb1, 0x1, 0x80000000}};
    s21_decimal dec_check = {{0x3016001f, 0xcfbfe12b, 0x45b2b061, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_169) {
    s21_decimal dec_1 = {{0x3aaaac8, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x17349, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x16f76d55, 0xceac1503, 0xd11fcdca, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_170) {
    s21_decimal dec_1 = {{0xe321cb79, 0x5ba5fc9b, 0x32b8f7f, 0x80000000}};
    s21_decimal dec_2 = {{0xb31eb109, 0x3e8, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x592ed5e4, 0xd7917fe1, 0x49c26789, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_div_173) {
    s21_decimal dec_1 = {{0x64f7d952, 0xbe996b1, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xc1a0fca7, 0xe0380e2b, 0x1796663, 0x140000}};
    s21_decimal dec_check = {{0xb4e0d6d3, 0x21312df7, 0x3cca84e0, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_174) {
    s21_decimal dec_1 = {{0x281f4, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x18855, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x14cbfaf4, 0xb890bae4, 0x34debd47, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_176) {
    s21_decimal dec_1 = {{0xc4b3c66c, 0x1d2645, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x5f64641f, 0xbc09b520, 0x2a2023, 0x190000}};
    s21_decimal dec_check = {{0xd818843, 0xd8220b34, 0x340ece74, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_177) {
    s21_decimal dec_1 = {{0xa7d2fd15, 0x627264ea, 0x8d925a60, 0x80000000}};
    s21_decimal dec_2 = {{0x2f0ea806, 0x3b31, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0x3862d35e, 0x9cef18a5, 0xd986d8fe, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_178) {
    s21_decimal dec_1 = {{0xae250478, 0x388cb, 0x0, 0x800d0000}};
    s21_decimal dec_2 = {{0x6f86f948, 0x37e51d25, 0x0, 0x80110000}};
    s21_decimal dec_check = {{0xa53d7f96, 0x56d55982, 0x4fcf6680, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_179) {
    s21_decimal dec_1 = {{0x8b379498, 0xfc305, 0x0, 0x90000}};
    s21_decimal dec_2 = {{0xc1e, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x316da538, 0xf6e047b9, 0x2e368804, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_180) {
    s21_decimal dec_1 = {{0x38d8b6da, 0x412dac, 0x0, 0x80090000}};
    s21_decimal dec_2 = {{0x8506, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xf0ad7834, 0x76925710, 0xae132348, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_182) {
    s21_decimal dec_1 = {{0xa87caaa9, 0x1ada59, 0x0, 0x50000}};
    s21_decimal dec_2 = {{0x392cb2b9, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x10ddb28c, 0xeb9658dc, 0xfe9b29cc, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_184) {
    s21_decimal dec_1 = {{0xb11a4342, 0x4b0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x383c, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x3cb003fc, 0xac48a095, 0x73bf3f08, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_185) {
    s21_decimal dec_1 = {{0x370ddbc2, 0x75769177, 0xbfc8ec2, 0x60000}};
    s21_decimal dec_2 = {{0x1ee2f21, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x7009ef6d, 0xc11bd985, 0x2502b3e3, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_186) {
    s21_decimal dec_1 = {{0xea, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x4c3538d, 0x0, 0x0, 0x80070000}};
    s21_decimal dec_check = {{0x5f824ba2, 0x29b34f86, 0x5e9e5a0f, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_187) {
    s21_decimal dec_1 = {{0x708e716c, 0x636, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xcdcc3d96, 0x22427, 0x0, 0x800e0000}};
    s21_decimal dec_check = {{0xa5417858, 0xe8fdbd76, 0x249f0e0c, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_188) {
    s21_decimal dec_1 = {{0x286aebd8, 0xb244b28e, 0xa2738542, 0x80000000}};
    s21_decimal dec_2 = {{0x4f60b240, 0xfe59c29b, 0x4, 0x130000}};
    s21_decimal dec_check = {{0x5b0d5e6, 0x25a49497, 0xb05b74b9, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_189) {
    s21_decimal dec_1 = {{0xd42bf509, 0xa30a6da3, 0x443c1b5, 0xe0000}};
    s21_decimal dec_2 = {{0x6eca89cb, 0x21e9d7, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0xd5a10a66, 0x34ec5866, 0x2cad0dda, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_190) {
    s21_decimal dec_1 = {{0xf1dea045, 0xa4ba1983, 0x9f83, 0x80090000}};
    s21_decimal dec_2 = {{0x5968bfad, 0x1, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xd12aafe1, 0xdaf4f49d, 0x2a006845, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_191) {
    s21_decimal dec_1 = {{0xe5936d50, 0x18661, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xcac87d6d, 0x80, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xbb898d9e, 0xd2d2ac17, 0xfaba23a9, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_192) {
    s21_decimal dec_1 = {{0xc10df0df, 0x9ca1242, 0x87ad, 0x80000000}};
    s21_decimal dec_2 = {{0x75d92bb9, 0x85f7695e, 0x0, 0x100000}};
    s21_decimal dec_check = {{0x254d4d60, 0x1542d59a, 0xd675db56, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_193) {
    s21_decimal dec_1 = {{0xc5ebad2a, 0xdfafb315, 0x12f4f0e9, 0x80000000}};
    s21_decimal dec_2 = {{0x8f91f5c8, 0xc121e, 0x0, 0x0}};
    s21_decimal dec_check = {{0xfb8d8f7c, 0x62d1e970, 0x37cb5861, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_194) {
    s21_decimal dec_1 = {{0x84fb0029, 0xd6275bdc, 0x3473a0, 0x80100000}};
    s21_decimal dec_2 = {{0xe9a0c, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_check = {{0x9883a922, 0x3c3e0055, 0xd61bdf44, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_195) {
    s21_decimal dec_1 = {{0x5bde9064, 0xd949e205, 0xe4e63f65, 0x130000}};
    s21_decimal dec_2 = {{0x261a5b9, 0x0, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0x6e88c10, 0x1aad3ca, 0x394a7bd6, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_196) {
    s21_decimal dec_1 = {{0xf88f66f3, 0x1f, 0x0, 0x80020000}};
    s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0xdacd02bf, 0x9f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_197) {
    s21_decimal dec_1 = {{0x3b56ed3c, 0x4648401b, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xcfdf9, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x3f1ad4be, 0x9da74a89, 0xc030369d, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_198) {
    s21_decimal dec_1 = {{0x2dd0c628, 0x11e7b23, 0x0, 0x800d0000}};
    s21_decimal dec_2 = {{0x175, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x1c3a1079, 0xbc51d814, 0x45da7476, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_199) {
    s21_decimal dec_1 = {{0xc754b035, 0xbb90c88f, 0x31a76, 0x0}};
    s21_decimal dec_2 = {{0x152, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x80c027ed, 0x2d6bcc69, 0x23dd949d, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_200) {
    s21_decimal dec_1 = {{0x4fe3a401, 0x6fe190f6, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x2528203a, 0x73, 0x0, 0x80080000}};
    s21_decimal dec_check = {{0x7ba8c814, 0x8715c802, 0x34ac64b8, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_201) {
    s21_decimal dec_1 = {{0xadd55a21, 0xd4f48c94, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x375fcca7, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x24f024ab, 0xa75ef2d0, 0x355ed73a, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_202) {
    s21_decimal dec_1 = {{0xb5bff3e9, 0x715cc34a, 0x40f2ce, 0x80070000}};
    s21_decimal dec_2 = {{0xbf83865e, 0x3d26bac9, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xaa83ad4c, 0x9a4602af, 0x3993869a, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_203) {
    s21_decimal dec_1 = {{0x8e979191, 0x2618928f, 0x12722c09, 0x0}};
    s21_decimal dec_2 = {{0x23c4, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x8651d2fb, 0x765c574c, 0xc9769e2e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_204) {
    s21_decimal dec_1 = {{0x63df3812, 0xd6cb93d, 0x0, 0xb0000}};
    s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x332f62ab, 0x313814cc, 0x34183e26, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_205) {
    s21_decimal dec_1 = {{0x61ce3e5d, 0xd9287e59, 0x2c8ba525, 0x0}};
    s21_decimal dec_2 = {{0xd9efb4fe, 0xe2821598, 0x7063e, 0x80000000}};
    s21_decimal dec_check = {{0xb9854c83, 0xb8575f49, 0x3474bb3f, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_206) {
    s21_decimal dec_1 = {{0xd7fb2093, 0xbe8880, 0x0, 0x80030000}};
    s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x17862e5b, 0x129b5495, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_207) {
    s21_decimal dec_1 = {{0xfd5e18bb, 0xbe51c212, 0x322e, 0x80000000}};
    s21_decimal dec_2 = {{0x16495, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xeb971661, 0x518e4ee3, 0x53e20983, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_208) {
    s21_decimal dec_1 = {{0xfc0a800a, 0x5efdeecd, 0x1, 0x60000}};
    s21_decimal dec_2 = {{0x3458d01d, 0x878, 0x0, 0x0}};
    s21_decimal dec_check = {{0x2ed68415, 0xa2545a4d, 0x57c18dcb, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_209) {
    s21_decimal dec_1 = {{0x2342d6d8, 0x73fa35c, 0x1267f1b7, 0x800e0000}};
    s21_decimal dec_2 = {{0xad66cc6b, 0x98af59f, 0x1, 0x100000}};
    s21_decimal dec_check = {{0xc779bbb0, 0xfa693d11, 0x60318b46, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_210) {
    s21_decimal dec_1 = {{0x87dc31b7, 0xdaaddc, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x12dc5d, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xd112ebe2, 0x243f0ae2, 0xa0e77ff0, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_211) {
    s21_decimal dec_1 = {{0xc3b5a785, 0x5b4a1762, 0x0, 0x80020000}};
    s21_decimal dec_2 = {{0xa090bee2, 0x1d09, 0x0, 0x0}};
    s21_decimal dec_check = {{0x42eda8da, 0xf29b2be1, 0x4292c25f, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_212) {
    s21_decimal dec_1 = {{0xedc5158f, 0x4687, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x4e2c5e95, 0x40c6a666, 0x0, 0xe0000}};
    s21_decimal dec_check = {{0x2078d9df, 0x69628c6e, 0x35af26a1, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_213) {
    s21_decimal dec_1 = {{0x5c5687b3, 0x2a31ec91, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xbdc6638f, 0x5981732b, 0x5cb8, 0xf0000}};
    s21_decimal dec_check = {{0x31d7f58b, 0x96ba8ea0, 0xe05f18f0, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_214) {
    s21_decimal dec_1 = {{0xc3b5655e, 0x105, 0x0, 0x80050000}};
    s21_decimal dec_2 = {{0x2adaf251, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xe081f587, 0x1f093bc8, 0x32866b1a, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_215) {
    s21_decimal dec_1 = {{0xdf833fe9, 0xffffffff, 0xffffffff, 0x80000000}};
    s21_decimal dec_2 = {{0xd0e5d614, 0x16644, 0x0, 0x0}};
    s21_decimal dec_check = {{0x733e872c, 0xa4f233a9, 0x40fcd996, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_216) {
    s21_decimal dec_1 = {{0x86a68cd1, 0x22933b4c, 0x314ac, 0x0}};
    s21_decimal dec_2 = {{0xd6af0c, 0x0, 0x0, 0x80070000}};
    s21_decimal dec_check = {{0x38d17e82, 0xc7dc982f, 0x5588a464, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_217) {
    s21_decimal dec_1 = {{0x6574b252, 0x1f4, 0x0, 0x90000}};
    s21_decimal dec_2 = {{0x2754a94, 0x0, 0x0, 0x60000}};
    s21_decimal dec_check = {{0x72942cf9, 0x988ca25b, 0xa8627cc9, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_218) {
    s21_decimal dec_1 = {{0x7b71ec23, 0x27a2e, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x719bcb0e, 0xe, 0x0, 0xa0000}};
    s21_decimal dec_check = {{0x20ebceb0, 0xa42523cc, 0x2451a51f, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_219) {
    s21_decimal dec_1 = {{0x81d11ef0, 0xfe1e60b1, 0x25f68, 0x0}};
    s21_decimal dec_2 = {{0x1f3, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x22c9b733, 0x6a55cc68, 0xb9bd03a5, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_220) {
    s21_decimal dec_1 = {{0x308f45c8, 0xe8888f32, 0x69b7e, 0x0}};
    s21_decimal dec_2 = {{0x4f87c0c0, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x50f4b868, 0x3b918e07, 0xc16fc1e1, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_221) {
    s21_decimal dec_1 = {{0x68bab3ad, 0x788f6d90, 0x13751, 0x80000000}};
    s21_decimal dec_2 = {{0x8d739, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xc3433a8a, 0xea4bbc18, 0x51fd4576, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_222) {
    s21_decimal dec_1 = {{0x2ed8711e, 0x11a8, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x5a, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0xebbc38e4, 0x40c7c165, 0x45b33d6c, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_223) {
    s21_decimal dec_1 = {{0xf8b26953, 0xcd4ce79a, 0x20af4, 0x0}};
    s21_decimal dec_2 = {{0x9eb4d8a9, 0xdee9cee8, 0xe68, 0x80130000}};
    s21_decimal dec_check = {{0x7ee4d4bf, 0x232a9e84, 0x75441b69, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_224) {
    s21_decimal dec_1 = {{0x514d363a, 0x11, 0x0, 0x80070000}};
    s21_decimal dec_2 = {{0xfe51c, 0x0, 0x0, 0x80060000}};
    s21_decimal dec_check = {{0x791c537b, 0x5b33ef10, 0xe6b60180, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_225) {
    s21_decimal dec_1 = {{0xe1add1a2, 0x9, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x16325c8c, 0x3d811d3, 0x0, 0x80080000}};
    s21_decimal dec_check = {{0x1d0e169d, 0x309c1037, 0x31822f4f, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_226) {
    s21_decimal dec_1 = {{0x86f995, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x10df32a, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_227) {
    s21_decimal dec_1 = {{0x73be2103, 0x567ef4f8, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0xf33b6f87, 0x354, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xda4f70b6, 0x2a5bce1d, 0x36f92e2f, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_228) {
    s21_decimal dec_1 = {{0x35eb4c0d, 0x41d2002d, 0x6a82, 0x80000000}};
    s21_decimal dec_2 = {{0x61, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x66e2c7a2, 0x4cb35361, 0xa78bc265, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_229) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x9cb670f3, 0xd68cb2bb, 0x8e1f3ad, 0x80000000}};
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

START_TEST(s21_div_230) {
    s21_decimal dec_1 = {{0xd9f28d01, 0x111fe905, 0x47ae, 0x800a0000}};
    s21_decimal dec_2 = {{0x274b9f13, 0x0, 0x0, 0x80080000}};
    s21_decimal dec_check = {{0x63e0b7ab, 0x706266f2, 0xa5e75bd6, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_231) {
    s21_decimal dec_1 = {{0x4c25c813, 0x922d224, 0x1878a3da, 0x80000000}};
    s21_decimal dec_2 = {{0xa4404977, 0xe413911e, 0x2c327, 0x80190000}};
    s21_decimal dec_check = {{0xdf761945, 0x917aca58, 0x49478096, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_232) {
    s21_decimal dec_1 = {{0x8963251f, 0x36eb0fb7, 0xb1d6808, 0x120000}};
    s21_decimal dec_2 = {{0x39a, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x43f0b00c, 0x4ac1d41d, 0x788d3d92, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_233) {
    s21_decimal dec_1 = {{0xcc8480ff, 0xba0d16eb, 0x68435, 0x0}};
    s21_decimal dec_2 = {{0x7e1bdd1a, 0x1b97136a, 0x29, 0x80000000}};
    s21_decimal dec_check = {{0xb6d24ccb, 0x3ead1e85, 0x21917096, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_235) {
    s21_decimal dec_1 = {{0x4ea975ec, 0x186, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x18a, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x9972462c, 0x947e12e5, 0x897a2982, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_236) {
    s21_decimal dec_1 = {{0xa965af49, 0xce22599f, 0x1152c, 0x80000000}};
    s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0xf81589a9, 0xe16de48c, 0x3c6b5b25, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_237) {
    s21_decimal dec_1 = {{0x4b65ae55, 0x9bf30948, 0x8d7d3, 0x0}};
    s21_decimal dec_2 = {{0x38e, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8cbcdcb2, 0x61abb6ae, 0x25f5a989, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_238) {
    s21_decimal dec_1 = {{0x398e46e9, 0x12e660d, 0x0, 0x800f0000}};
    s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x9ee4ecc1, 0x1d87f74a, 0x0, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_240) {
    s21_decimal dec_1 = {{0x7f32eede, 0x11af955, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x2ad5710, 0x30, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x87f15c91, 0xfdd8528e, 0x7ccf7983, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_241) {
    s21_decimal dec_1 = {{0x144fb, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x328901, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0x635b8c22, 0xe17a099f, 0x512af6e0, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_242) {
    s21_decimal dec_1 = {{0xae6f97ef, 0x18d0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x1780b580, 0x386df, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x1c95ef74, 0x60612d52, 0x58ced21d, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_243) {
    s21_decimal dec_1 = {{0x382aa518, 0xc026bf99, 0x442e14, 0x80000000}};
    s21_decimal dec_2 = {{0x840853fa, 0x74fa5ecf, 0x12, 0x70000}};
    s21_decimal dec_check = {{0xc9835b96, 0x1cb8ab3a, 0x4e393a6d, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_244) {
    s21_decimal dec_1 = {{0x220f0acf, 0xce863a75, 0x15a20, 0x80000000}};
    s21_decimal dec_2 = {{0x237, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0xce0057e7, 0xe4bd23b4, 0x5d25e8ee, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_245) {
    s21_decimal dec_1 = {{0x38f, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x55, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x925a5a5a, 0x41664f59, 0x22a16e0b, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_246) {
    s21_decimal dec_1 = {{0xd2c4de6f, 0x20e77b, 0x0, 0x80040000}};
    s21_decimal dec_2 = {{0x3a3d464c, 0x3db7, 0x0, 0x90000}};
    s21_decimal dec_check = {{0xfe2d6672, 0x9afc6eae, 0x2c1a0f04, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_247) {
    s21_decimal dec_1 = {{0x376a136, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_2 = {{0x16a2, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xfbcd0318, 0xc4e3c35f, 0x20678760, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_248) {
    s21_decimal dec_1 = {{0xa337e2ec, 0x56a4c58a, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x24f, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x162c4f29, 0x1257b8df, 0x222258f2, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_249) {
    s21_decimal dec_1 = {{0x7b0a6d9, 0x1e8b6, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x8ad4b847, 0x283d0, 0x0, 0x50000}};
    s21_decimal dec_check = {{0xf71480e5, 0x5d027ce9, 0xf5462c2b, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_251) {
    s21_decimal dec_1 = {{0xd179fc66, 0x9efe4824, 0xeee4cd, 0x0}};
    s21_decimal dec_2 = {{0xae586b35, 0x25e6eaae, 0x21, 0x40000}};
    s21_decimal dec_check = {{0x6ec6991a, 0xc6e1a9c7, 0x989c86fb, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_252) {
    s21_decimal dec_1 = {{0xe23ad043, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x36cc71c7, 0x2d7e1f1c, 0x884417b3, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_254) {
    s21_decimal dec_1 = {{0x96923281, 0xac5b1f6e, 0x254282, 0x80000000}};
    s21_decimal dec_2 = {{0x594344, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x42b45b6c, 0xc06d513f, 0xf8cccde2, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_255) {
    s21_decimal dec_1 = {{0x3c8b8cf1, 0x157784f, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x6cb85ba1, 0x433f19, 0x0, 0x0}};
    s21_decimal dec_check = {{0x711cd261, 0x639fe375, 0xa5094d4d, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_257) {
    s21_decimal dec_1 = {{0xa934340d, 0x268, 0x0, 0xa0000}};
    s21_decimal dec_2 = {{0x6f8fd, 0x0, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0x23c3d50e, 0xc58d7890, 0xbb47acde, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_258) {
    s21_decimal dec_1 = {{0x4ffe73ff, 0x1, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x55f6a4f0, 0x34e66592, 0x27f2, 0x170000}};
    s21_decimal dec_check = {{0x96f79c3f, 0x5788599c, 0x608e3bab, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_259) {
    s21_decimal dec_1 = {{0xcf8058be, 0x432c, 0x0, 0x60000}};
    s21_decimal dec_2 = {{0x34, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xa3debb14, 0x165b1fa6, 0x2de51ac9, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_261) {
    s21_decimal dec_1 = {{0x20721d, 0x1, 0x0, 0x80020000}};
    s21_decimal dec_2 = {{0x11fe4a6a, 0x258d, 0x0, 0xa0000}};
    s21_decimal dec_check = {{0x173fb96e, 0x8440c29e, 0x21a1026f, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_262) {
    s21_decimal dec_1 = {{0xf40392a0, 0x494e7da8, 0x240113, 0x0}};
    s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x11bf5b94, 0xfd4593e2, 0xf6bd439b, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_263) {
    s21_decimal dec_1 = {{0x9f1793be, 0x20a3d51c, 0x5, 0x80000000}};
    s21_decimal dec_2 = {{0x299426e, 0x0, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0xf70d7015, 0x99444a81, 0x46197711, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_264) {
    s21_decimal dec_1 = {{0xccff6119, 0xdbacc9d, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xedeee33, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0x531f6579, 0x145b95a4, 0x8020e708, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_265) {
    s21_decimal dec_1 = {{0xb2ce7e68, 0x30cf566, 0x3c37b472, 0x0}};
    s21_decimal dec_2 = {{0x34aa3905, 0xe15bacd, 0xe307496, 0x80040000}};
    s21_decimal dec_check = {{0x53a01660, 0xd40c3a23, 0x89208d72, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_266) {
    s21_decimal dec_1 = {{0x3ca199f3, 0x76e89490, 0x43e4f, 0x80130000}};
    s21_decimal dec_2 = {{0x6e2e2999, 0x1536, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0x3eb85732, 0xdc93c4be, 0x4711a6b0, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_267) {
    s21_decimal dec_1 = {{0x793e0adf, 0x331, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x3da2289d, 0xf04faba8, 0x65e9c1, 0x801b0000}};
    s21_decimal dec_check = {{0xf929add1, 0x5d0242e2, 0x5c146c21, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_269) {
    s21_decimal dec_1 = {{0x32cdf8, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x7ce67b30, 0x9df7a12b, 0xa2f, 0x80130000}};
    s21_decimal dec_check = {{0x3a50eb38, 0xf48a0454, 0xdfa7cca1, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_div_272) {
    s21_decimal dec_1 = {{0x28b41038, 0x2794dee1, 0x1330, 0xf0000}};
    s21_decimal dec_2 = {{0x620133, 0x0, 0x0, 0x80060000}};
    s21_decimal dec_check = {{0x84af72d8, 0x95d47f05, 0x2d95da00, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_273) {
    s21_decimal dec_1 = {{0x425bd090, 0x7c0d519f, 0xc581ef, 0x80000000}};
    s21_decimal dec_2 = {{0x2d8, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_check = {{0xd646b8df, 0xa41a98, 0x69fa28cf, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_274) {
    s21_decimal dec_1 = {{0xefac19ae, 0x62b2eaa9, 0x1b2c92, 0x80000000}};
    s21_decimal dec_2 = {{0x5762d3aa, 0x1c, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x6544795c, 0xbb5d1dd5, 0x573425cd, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_275) {
    s21_decimal dec_1 = {{0x4a5, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x49, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x55eaf58, 0xc54e83e0, 0x34a0d88a, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_276) {
    s21_decimal dec_1 = {{0xfe79c308, 0x1d73ad, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x7cfb5bb5, 0x12, 0x0, 0x0}};
    s21_decimal dec_check = {{0xc2fc0334, 0xa61be1ea, 0x21bbb731, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_277) {
    s21_decimal dec_1 = {{0x246197ea, 0x14e184cd, 0x4c1a0, 0x800a0000}};
    s21_decimal dec_2 = {{0x3570bc6d, 0xcdfa, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x13766ec1, 0x98379e93, 0x5209b1fd, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_278) {
    s21_decimal dec_1 = {{0x3faf50e, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x130a6e20, 0x1a26c1b5, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0x1c0241fd, 0xc655475e, 0x728117e3, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_279) {
    s21_decimal dec_1 = {{0x8059f9, 0x0, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x27c56aec, 0x60cb74ed, 0x1a0df9, 0x80160000}};
    s21_decimal dec_check = {{0x89aea7b, 0xced541a7, 0x564a13d3, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_280) {
    s21_decimal dec_1 = {{0x4c48964f, 0x6d5df8, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xba7db, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xed68cc87, 0xae12d8e, 0x8237a72f, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_281) {
    s21_decimal dec_1 = {{0xe818e3da, 0xcfa7b1ea, 0x1fd, 0x80000000}};
    s21_decimal dec_2 = {{0xb2962086, 0x1, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x79aec58f, 0x4476be8f, 0x29ad3c88, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_282) {
    s21_decimal dec_1 = {{0x52f40e7d, 0xb5a85f56, 0x3d8181, 0x10000}};
    s21_decimal dec_2 = {{0x57b9ac, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x55800f0b, 0x7242308f, 0x29ca3b2d, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_283) {
    s21_decimal dec_1 = {{0xa454, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x26b1, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x102f8e48, 0xc99905d7, 0x893b9584, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_284) {
    s21_decimal dec_1 = {{0xe858756d, 0x8fe8724d, 0x93074ba, 0x0}};
    s21_decimal dec_2 = {{0x3be793d, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x52a598be, 0xd85eb453, 0x924ad3f7, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_div_287) {
    s21_decimal dec_1 = {{0x1962a306, 0x472c4719, 0x401238, 0x80030000}};
    s21_decimal dec_2 = {{0x2c66fa9, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x22d887e8, 0xea158cf, 0x35c13e3b, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_289) {
    s21_decimal dec_1 = {{0x49c92099, 0x3625b2e, 0x1ea, 0xb0000}};
    s21_decimal dec_2 = {{0x1570, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x61c29809, 0xf38eed17, 0x3538494e, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_290) {
    s21_decimal dec_1 = {{0x330d4fee, 0xe122e14f, 0x76605c8f, 0x70000}};
    s21_decimal dec_2 = {{0x71cdff0c, 0x6110b068, 0x61a, 0x80070000}};
    s21_decimal dec_check = {{0xdaebb94a, 0xc0f99b63, 0x2912c02b, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_292) {
    s21_decimal dec_1 = {{0xa66bae68, 0xe595b8d7, 0xab, 0x80000000}};
    s21_decimal dec_2 = {{0x53fb474f, 0x932a7994, 0x16c, 0x130000}};
    s21_decimal dec_check = {{0x848c4cf2, 0xad8f79f3, 0x98598347, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_293) {
    s21_decimal dec_1 = {{0x4f54930f, 0x11e23f5, 0xd9af42b, 0x0}};
    s21_decimal dec_2 = {{0x4eed13df, 0x2d6, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xcafb2e88, 0x6ae62b31, 0x2b9d3564, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_294) {
    s21_decimal dec_1 = {{0x51c858bb, 0xcdfe6fb2, 0x2a, 0x80000000}};
    s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xa370f8bf, 0x3279bf20, 0x3206cf7a, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_295) {
    s21_decimal dec_1 = {{0x32b2c392, 0x7947489b, 0x3c5, 0x80000000}};
    s21_decimal dec_2 = {{0x3291b4a9, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xb14706f7, 0x9b413c90, 0x43d43431, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_296) {
    s21_decimal dec_1 = {{0xa6636435, 0x32aef, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x64c71961, 0x76, 0x0, 0x800a0000}};
    s21_decimal dec_check = {{0x25b90b46, 0x6b66a5fa, 0x38a85b9c, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_298) {
    s21_decimal dec_1 = {{0x87e04fd0, 0x3835c, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x3269953c, 0x1ae3c4, 0x0, 0x90000}};
    s21_decimal dec_check = {{0x4392b56b, 0x2af57d88, 0x2a371545, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_299) {
    s21_decimal dec_1 = {{0x8156da1, 0x46d53d3f, 0x10b, 0x80000000}};
    s21_decimal dec_2 = {{0x530c3ef, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0xf3096d38, 0xa2716ba3, 0xb6f11a24, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_300) {
    s21_decimal dec_1 = {{0x6de75891, 0x7268fe31, 0xaaea8c, 0x0}};
    s21_decimal dec_2 = {{0x8c88250a, 0x679, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x7076250f, 0x23040652, 0x5dc80ea8, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_302) {
    s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x19f, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0x4a062b3, 0xb1814681, 0x4ddc101d, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_304) {
    s21_decimal dec_1 = {{0x622db585, 0x1b4d191b, 0xf9729b1, 0x0}};
    s21_decimal dec_2 = {{0xfe2c5a9e, 0x32, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x3ef9dd4e, 0x70f07d58, 0x472f6eb4, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_305) {
    s21_decimal dec_1 = {{0x74417e11, 0x475, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3f00c9f4, 0x112cd58, 0x0, 0x80000}};
    s21_decimal dec_check = {{0xa17b9164, 0xfabc0581, 0xcccb74ce, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_306) {
    s21_decimal dec_1 = {{0xd6f6b20e, 0x336b7fe2, 0x979439c, 0x80040000}};
    s21_decimal dec_2 = {{0xc6431d1e, 0x7ce, 0x0, 0x50000}};
    s21_decimal dec_check = {{0xa55be5e9, 0xefa488f, 0x6e5b19fc, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_307) {
    s21_decimal dec_1 = {{0x37d1e343, 0x89cbaf3, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x41946ef3, 0xb41044, 0x0, 0x80000}};
    s21_decimal dec_check = {{0x2b82a1cf, 0xb005dd59, 0x279025cd, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_308) {
    s21_decimal dec_1 = {{0x34568609, 0x12e, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x99abd, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x66aba2a2, 0x82d300be, 0x42a13db8, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_309) {
    s21_decimal dec_1 = {{0x426eb94c, 0x4f5a2ea, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x4d6eded5, 0x10, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0xba73d64f, 0x278022a5, 0xa4ead35b, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_311) {
    s21_decimal dec_1 = {{0xab973ce1, 0x3b3191e7, 0x11e, 0x0}};
    s21_decimal dec_2 = {{0x1d949207, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xe4161dd2, 0xf8e2ab52, 0x2260a19d, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_312) {
    s21_decimal dec_1 = {{0x255c213d, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3d2, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x2f0f2e9, 0xd38f816c, 0xcf158cc1, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_313) {
    s21_decimal dec_1 = {{0x102772aa, 0xc96feff7, 0xa07, 0x0}};
    s21_decimal dec_2 = {{0xef17e1b1, 0x2cb85, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x82c1e55f, 0x122fc6a3, 0xc28b001e, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_314) {
    s21_decimal dec_1 = {{0x13a93, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xc94bc396, 0x8ad39d09, 0x46df266, 0x190000}};
    s21_decimal dec_check = {{0xa322773f, 0xb71b2b4e, 0xbdd0b481, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_315) {
    s21_decimal dec_1 = {{0x678ab, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x386, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xab81fc98, 0xa62fd87b, 0x97eccdb5, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_316) {
    s21_decimal dec_1 = {{0xfb57192f, 0x9b86b6f2, 0x429874, 0x0}};
    s21_decimal dec_2 = {{0xbd9e4ee5, 0x2449b990, 0x9a8750a, 0x80110000}};
    s21_decimal dec_check = {{0xf923a4ab, 0x45603184, 0x5708131d, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_317) {
    s21_decimal dec_1 = {{0xc2d0dd03, 0x2fbab3ff, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3a09206, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8ad6dd61, 0x88332dcc, 0xb69ccd3e, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_318) {
    s21_decimal dec_1 = {{0x456d5a57, 0x12, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xe67960dd, 0xd, 0x0, 0x80070000}};
    s21_decimal dec_check = {{0x69bed61a, 0x72371bd6, 0x2a78dab0, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_320) {
    s21_decimal dec_1 = {{0xfef775f6, 0xee3707ff, 0x2f, 0x100000}};
    s21_decimal dec_2 = {{0x2bc, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x5028756e, 0x4a004351, 0x28d00699, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_321) {
    s21_decimal dec_1 = {{0x2ba5aca1, 0x296, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x3d0f8b4f, 0x70a, 0x0, 0xa0000}};
    s21_decimal dec_check = {{0xc70f52fd, 0xaab9e64c, 0x76b7e760, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_322) {
    s21_decimal dec_1 = {{0x130b473d, 0x86cc258, 0xa5, 0x80000000}};
    s21_decimal dec_2 = {{0x167c1f10, 0x7, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0xbdde620e, 0x7f263e90, 0x20502170, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_323) {
    s21_decimal dec_1 = {{0xf5c2a24b, 0x1e665731, 0x8450b4, 0x80000000}};
    s21_decimal dec_2 = {{0xb80881d6, 0x87e2f5b, 0x0, 0x40000}};
    s21_decimal dec_check = {{0x5d4d6884, 0xfd10df01, 0x5474e464, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_324) {
    s21_decimal dec_1 = {{0x1ffdb5a9, 0xb3791ac4, 0x375c4, 0x10000}};
    s21_decimal dec_2 = {{0x3970f4c3, 0xd94cc0c, 0x0, 0x0}};
    s21_decimal dec_check = {{0x5fa92442, 0xbbbc67f8, 0x8a1bd513, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_325) {
    s21_decimal dec_1 = {{0x36f73, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xba295360, 0x6b4, 0x0, 0x800a0000}};
    s21_decimal dec_check = {{0xa8ea2da6, 0x217beb12, 0x62a9799a, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_326) {
    s21_decimal dec_1 = {{0x91744f3a, 0x73090fc9, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x1a2e87c9, 0x1ff44b7f, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_328) {
    s21_decimal dec_1 = {{0xfe1c9f69, 0x274448fb, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x18e, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_check = {{0xc7f4ac24, 0x9704da0e, 0xe5b607c6, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_329) {
    s21_decimal dec_1 = {{0xed693f18, 0x1a69ad97, 0x5ec41, 0x80000000}};
    s21_decimal dec_2 = {{0x3e7, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xbe1995cf, 0x474a40c6, 0xe797f8d0, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_331) {
    s21_decimal dec_1 = {{0x9e809fb6, 0x89882721, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xcf404fdb, 0x44c41390, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_332) {
    s21_decimal dec_1 = {{0xb73594ec, 0x2c317326, 0x0, 0x80040000}};
    s21_decimal dec_2 = {{0x2f7, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x5b4ea51a, 0x982126e9, 0x87911bff, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_333) {
    s21_decimal dec_1 = {{0xb4aa1975, 0x17a78, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xc4f46, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xbd851439, 0x4bc2825, 0xa6ac7e50, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_334) {
    s21_decimal dec_1 = {{0x24cc, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x83, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_check = {{0xfdcd30db, 0x78853e0d, 0xe8593b59, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_335) {
    s21_decimal dec_1 = {{0xaabd8ab3, 0xfd7a2fe0, 0x5f7, 0x0}};
    s21_decimal dec_2 = {{0x69726bb5, 0x3733, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xb80a5ce7, 0x926173b0, 0x960e807b, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_336) {
    s21_decimal dec_1 = {{0x485e567f, 0xad15d3, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x355, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xbce6eebe, 0x79d092c, 0xb88c7ddc, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_337) {
    s21_decimal dec_1 = {{0x6be3268e, 0x3af0d6a0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x4e84f02a, 0x728, 0x0, 0x0}};
    s21_decimal dec_check = {{0x61808217, 0x136ac1c6, 0xae616929, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_339) {
    s21_decimal dec_1 = {{0x4ef3d2e4, 0x52ee8986, 0x10, 0x0}};
    s21_decimal dec_2 = {{0xbbd52577, 0x72304d2a, 0x1a0, 0x110000}};
    s21_decimal dec_check = {{0xc7386f5c, 0x5964cd30, 0x7ea8063c, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_340) {
    s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x40, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x7d, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_341) {
    s21_decimal dec_1 = {{0xcf82f389, 0x3156845b, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x773d6ceb, 0x2b140, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8760213b, 0x4a019b5c, 0x9794a0a8, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_343) {
    s21_decimal dec_1 = {{0x9d003dad, 0xedb301ce, 0x6630, 0x0}};
    s21_decimal dec_2 = {{0x2b4, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xd550904c, 0xf13cd097, 0xe1558fe6, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_344) {
    s21_decimal dec_1 = {{0x6c683525, 0x3c21d0a3, 0x1b08d144, 0x0}};
    s21_decimal dec_2 = {{0xdb034871, 0xed4549a, 0x3521f, 0x80000000}};
    s21_decimal dec_check = {{0x40d13fad, 0xccd8820b, 0x4357300c, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_345) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xa98b2656, 0x89ecbd, 0x0, 0xf0000}};
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_346) {
    s21_decimal dec_1 = {{0xaec44b12, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xbbf43c62, 0x367f, 0x0, 0xa0000}};
    s21_decimal dec_check = {{0xf42efaeb, 0xe0a1dc2e, 0x9e1b6400, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_347) {
    s21_decimal dec_1 = {{0x4da38f, 0x2, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3d8f, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xf0c40011, 0x7623bfb2, 0xb03ac46a, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_348) {
    s21_decimal dec_1 = {{0x26ff5963, 0x2, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x52069c11, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xa39fcd8a, 0x94a93884, 0xd90cc014, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_349) {
    s21_decimal dec_1 = {{0x5e, 0x0, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x1cd33c08, 0xa8b8b385, 0x1483ed3e, 0x801c0000}};
    s21_decimal dec_check = {{0x2e9d21a6, 0xa03387e1, 0x2fd670d9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_350) {
    s21_decimal dec_1 = {{0x79774ff0, 0xe353d4d, 0x11c4944, 0x80000000}};
    s21_decimal dec_2 = {{0x755a479a, 0xf730df12, 0xbb5f, 0x80000000}};
    s21_decimal dec_check = {{0x526dbbe6, 0xcfa5fb34, 0x7d801404, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_351) {
    s21_decimal dec_1 = {{0x376d341, 0xcb84222, 0x0, 0x90000}};
    s21_decimal dec_2 = {{0x22a325, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x823dd512, 0x92741a76, 0x827722ed, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_352) {
    s21_decimal dec_1 = {{0xe6e644ac, 0x55a, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0xd451dcec, 0x31ade25a, 0x0, 0xf0000}};
    s21_decimal dec_check = {{0xc0a43989, 0xbf93048c, 0x35256b73, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_353) {
    s21_decimal dec_1 = {{0x1783365d, 0x92b50b9d, 0x3d1936, 0x80000000}};
    s21_decimal dec_2 = {{0x42319610, 0x853642, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x554ab45f, 0xabd1f07c, 0x3fa6be08, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_354) {
    s21_decimal dec_1 = {{0x276730d5, 0xd138d8d0, 0x70b, 0x0}};
    s21_decimal dec_2 = {{0xc3358082, 0x564a168e, 0x1807d108, 0x130000}};
    s21_decimal dec_check = {{0xc83156b8, 0x3bda7d4e, 0x909130b3, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_355) {
    s21_decimal dec_1 = {{0xe0386f5e, 0x4721d6f, 0x190f279a, 0x110000}};
    s21_decimal dec_2 = {{0x81b6420b, 0x1f351, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0x838a5387, 0x872ef76b, 0x2da5071c, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_356) {
    s21_decimal dec_1 = {{0xeef34, 0x0, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x2fca4, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_358) {
    s21_decimal dec_1 = {{0x49111e38, 0x8ae67a6, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x95b103ef, 0x88528024, 0x0, 0x80000}};
    s21_decimal dec_check = {{0x72988eea, 0xca9a67ee, 0xcdc47b59, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_359) {
    s21_decimal dec_1 = {{0x379c9f98, 0xd54bd, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xaed5b430, 0x1df836d1, 0x0, 0xd0000}};
    s21_decimal dec_check = {{0x769bc0ce, 0x38c2392, 0x3824d874, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_360) {
    s21_decimal dec_1 = {{0x78a01081, 0x75880bc4, 0x19, 0x80000000}};
    s21_decimal dec_2 = {{0xf58c5024, 0x92ba, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x42491c5d, 0xa9b8906e, 0x5e0f48d7, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_361) {
    s21_decimal dec_1 = {{0xb3f5f3d3, 0x3b1, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x8cffee3, 0x14, 0x0, 0x800b0000}};
    s21_decimal dec_check = {{0x78e20acf, 0x920c81df, 0x98862703, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_362) {
    s21_decimal dec_1 = {{0x64a54c64, 0x5f36e078, 0x6b7c9, 0x80100000}};
    s21_decimal dec_2 = {{0x4b4559, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x556864a4, 0xc98ef30e, 0x353272b6, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_363) {
    s21_decimal dec_1 = {{0x9095cb99, 0x19eb04e7, 0x1, 0x80000000}};
    s21_decimal dec_2 = {{0x127d, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xdac83394, 0xda98561e, 0x8aaf1db7, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_364) {
    s21_decimal dec_1 = {{0x486c25a, 0x0, 0x0, 0x20000}};
    s21_decimal dec_2 = {{0x119c5, 0x0, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x3f12a837, 0x897bd4ea, 0x22046c10, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_366) {
    s21_decimal dec_1 = {{0x244af6a4, 0x3559, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x87d7ef00, 0x52b2, 0x0, 0x800d0000}};
    s21_decimal dec_check = {{0xea20e402, 0x9e8df94a, 0xd0718c51, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_367) {
    s21_decimal dec_1 = {{0x941adb7b, 0x26a5395e, 0x511, 0x80000000}};
    s21_decimal dec_2 = {{0x24e7e65d, 0x0, 0x0, 0x50000}};
    s21_decimal dec_check = {{0x9a68ad44, 0x1f91a2c4, 0x7cde8578, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_368) {
    s21_decimal dec_1 = {{0x852744da, 0x8, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x164ad4e, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x950a673f, 0x82841e4b, 0x3295742d, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_369) {
    s21_decimal dec_1 = {{0xd613592f, 0x14, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3488cb07, 0x2aa0, 0x0, 0x800d0000}};
    s21_decimal dec_check = {{0x5f948f6, 0x8ef865f1, 0x3db28a9c, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_370) {
    s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x5f, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xf9435e51, 0x2a2d1c7f, 0xcc12fc6e, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_371) {
    s21_decimal dec_1 = {{0x9eb5e065, 0x146b59be, 0xd7dc36b1, 0x0}};
    s21_decimal dec_2 = {{0xd473, 0x0, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x2a63b9aa, 0x91f400ee, 0x27b08e3a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_372) {
    s21_decimal dec_1 = {{0x83787b1f, 0x74f19f06, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xd382eaea, 0x5b3, 0x0, 0x80070000}};
    s21_decimal dec_check = {{0x4bdabb8b, 0x3d8874f9, 0x2b6d39ae, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_373) {
    s21_decimal dec_1 = {{0xd53dc5fe, 0x7fc5d543, 0x0, 0x80060000}};
    s21_decimal dec_2 = {{0xdf, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x223aa52a, 0x42dd2073, 0x8567cce6, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_374) {
    s21_decimal dec_1 = {{0xcc37d86a, 0xffffffff, 0xffffffff, 0x0}};
    s21_decimal dec_2 = {{0x5ddd33, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x189ec12e, 0x4113ff5f, 0x299db47b, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_375) {
    s21_decimal dec_1 = {{0x76a81caf, 0x11f672f9, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xc0214, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x97acb12c, 0x721efb2a, 0x3524f0dc, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_377) {
    s21_decimal dec_1 = {{0xba5b9181, 0xe8788110, 0x2b2ca7c, 0x80090000}};
    s21_decimal dec_2 = {{0xbbeba7d5, 0xae78fba, 0x22, 0x110000}};
    s21_decimal dec_check = {{0x885bf699, 0xc11dee06, 0x2af84b0c, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_378) {
    s21_decimal dec_1 = {{0xf034e596, 0xedb11971, 0xe, 0x80000000}};
    s21_decimal dec_2 = {{0xbd460bda, 0x306e5c4b, 0xed, 0x80070000}};
    s21_decimal dec_check = {{0xcf7c3f07, 0x5aa09118, 0xcb5e0998, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_379) {
    s21_decimal dec_1 = {{0x8816f09b, 0xbe89b50b, 0x1ecde, 0x80000000}};
    s21_decimal dec_2 = {{0x65aac3d, 0xc, 0x0, 0x80000}};
    s21_decimal dec_check = {{0x785275da, 0x43ba02d3, 0x919e1f18, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_380) {
    s21_decimal dec_1 = {{0x9eec, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x7fa6, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x1397465d, 0x90199529, 0x283a5eeb, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_381) {
    s21_decimal dec_1 = {{0x1bb7, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x2b4df, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_382) {
    s21_decimal dec_1 = {{0x632d0cd0, 0x56ff643, 0x0, 0x80000}};
    s21_decimal dec_2 = {{0x2313853b, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x2aa36d2f, 0xf6028be2, 0xd7207462, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_383) {
    s21_decimal dec_1 = {{0x5f9cb466, 0x3cf2ad70, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x62907, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0xfd71d7e6, 0xe33da512, 0x23264abf, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_384) {
    s21_decimal dec_1 = {{0x92cbbcfa, 0x56f, 0x0, 0x80090000}};
    s21_decimal dec_2 = {{0xf8dad69, 0x280f5f64, 0x0, 0x120000}};
    s21_decimal dec_check = {{0x9c086def, 0xbc16c270, 0x42e6c165, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_386) {
    s21_decimal dec_1 = {{0xee86b038, 0x6c142bd5, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x7fd52114, 0x1, 0x0, 0x0}};
    s21_decimal dec_check = {{0x6f473239, 0xe7252093, 0x2713a8e5, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_388) {
    s21_decimal dec_1 = {{0xdffbe79d, 0x9b6d2e10, 0x39e37e, 0x80000000}};
    s21_decimal dec_2 = {{0x6d286adb, 0x2ccae6f, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xbde1d5a3, 0x158746ab, 0x701867f1, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_389) {
    s21_decimal dec_1 = {{0x93b7479f, 0x1130e04, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3c98fd9f, 0x3f9, 0x0, 0x0}};
    s21_decimal dec_check = {{0x14a261f7, 0xe41cd10c, 0x3942174c, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_390) {
    s21_decimal dec_1 = {{0xda017383, 0x9, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xb3e1c2b8, 0x12, 0x0, 0x40000}};
    s21_decimal dec_check = {{0xc8ef8fae, 0x8443c9a9, 0xaa338bfc, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_391) {
    s21_decimal dec_1 = {{0x13fed4c5, 0x7f8e1762, 0x0, 0x80010000}};
    s21_decimal dec_2 = {{0xad0, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xb69201f4, 0xd58b134d, 0x6b4b06f0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_392) {
    s21_decimal dec_1 = {{0xe0364b40, 0x12a1e73, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x2c4cbd39, 0x951fd, 0x0, 0x800e0000}};
    s21_decimal dec_check = {{0x4f16300e, 0x643abcee, 0x675a4596, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_393) {
    s21_decimal dec_1 = {{0x411820db, 0x5359af8, 0x4, 0x80000}};
    s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x411820db, 0x5359af8, 0x4, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_394) {
    s21_decimal dec_1 = {{0x805bf39c, 0x16794320, 0x1b32c, 0x80000000}};
    s21_decimal dec_2 = {{0xfb629118, 0xb9a6c1, 0x0, 0xc0000}};
    s21_decimal dec_check = {{0x75a73cfd, 0xc6333533, 0x7f11ef18, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_395) {
    s21_decimal dec_1 = {{0x3fb60213, 0x69f7bc5f, 0x7e1f4, 0x0}};
    s21_decimal dec_2 = {{0x38a7dcf3, 0x7574369c, 0x0, 0x0}};
    s21_decimal dec_check = {{0xbe4a599f, 0xc0167b17, 0x2461bd10, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_396) {
    s21_decimal dec_1 = {{0x4163d61f, 0x7c096edf, 0x0, 0x10000}};
    s21_decimal dec_2 = {{0x23bcd, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x576106e1, 0x3ac958dc, 0xc54a5d87, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_397) {
    s21_decimal dec_1 = {{0xfcfa4e20, 0x4957b787, 0x4, 0x80070000}};
    s21_decimal dec_2 = {{0x9c7ca58, 0x4290a03, 0x0, 0x80060000}};
    s21_decimal dec_check = {{0xdd25299f, 0xdd962173, 0x553a1ab2, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_398) {
    s21_decimal dec_1 = {{0xdec0a67a, 0xb4efd197, 0x492738a, 0x0}};
    s21_decimal dec_2 = {{0x17f, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x2a4a764d, 0x492fed2, 0x7760164b, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_399) {
    s21_decimal dec_1 = {{0x53bfb8b1, 0xff948c15, 0x525d8c, 0x80070000}};
    s21_decimal dec_2 = {{0x1534cbe, 0x0, 0x0, 0x80000}};
    s21_decimal dec_check = {{0x36dc483c, 0x6850204b, 0x90b0e55e, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_400) {
    s21_decimal dec_1 = {{0xefb99462, 0x2d78d1fb, 0xadb9254, 0x80000000}};
    s21_decimal dec_2 = {{0x77b1223f, 0x73eb8f28, 0x6022, 0x80000000}};
    s21_decimal dec_check = {{0xac8fec97, 0xd2ef674b, 0xef2a5fad, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_401) {
    s21_decimal dec_1 = {{0xfbc9f1ee, 0xffffffff, 0xffffffff, 0x0}};
    s21_decimal dec_2 = {{0xbaa3562a, 0x3423124a, 0x2, 0x0}};
    s21_decimal dec_check = {{0xf80a6b56, 0x5cc72466, 0x3ef9e063, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_402) {
    s21_decimal dec_1 = {{0x3f86d79a, 0x4c0e45db, 0x12a45, 0x0}};
    s21_decimal dec_2 = {{0x24796b0, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x7a3b842d, 0x322854b8, 0x76ffc916, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_403) {
    s21_decimal dec_1 = {{0xc896395b, 0x4c5b715, 0x921b558, 0x80000000}};
    s21_decimal dec_2 = {{0xde5715, 0x2314af, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x6b29926c, 0xf7185bc7, 0x5c7a841a, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_404) {
    s21_decimal dec_1 = {{0x4ed53330, 0x7c343ba, 0x33, 0x0}};
    s21_decimal dec_2 = {{0xc7fd9773, 0x72637daa, 0x713300b, 0x1c0000}};
    s21_decimal dec_check = {{0x7b68ba96, 0x405b59f8, 0x8ae9ed37, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_406) {
    s21_decimal dec_1 = {{0x25626a, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xe58839d, 0x2a8b6, 0x0, 0xc0000}};
    s21_decimal dec_check = {{0x3c4cc95e, 0x43b3c712, 0x69c57c7f, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_407) {
    s21_decimal dec_1 = {{0x8ec99d69, 0x1601, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x750207, 0x0, 0x0, 0x60000}};
    s21_decimal dec_check = {{0x9f862ba7, 0xff070c39, 0x65f46fc6, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_408) {
    s21_decimal dec_1 = {{0x6b2, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_2 = {{0x3d76, 0x0, 0x0, 0x30000}};
    s21_decimal dec_check = {{0x33990a51, 0x94e33b60, 0x2332fad7, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_409) {
    s21_decimal dec_1 = {{0x11ea34ff, 0x6def1, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x35, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_check = {{0x84993c61, 0xf03e1324, 0x75e7ed58, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_410) {
    s21_decimal dec_1 = {{0x389007e0, 0x936ae92e, 0xfca227, 0x80150000}};
    s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xfe16ae25, 0x1f16b1ca, 0x8cfa7cf1, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_412) {
    s21_decimal dec_1 = {{0x77c3d11e, 0x50d7a229, 0x727848d, 0x80000000}};
    s21_decimal dec_2 = {{0xf164abfc, 0x1f503d91, 0xb625f99, 0x190000}};
    s21_decimal dec_check = {{0xaa497d6a, 0xe3526b71, 0xcb0f979c, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_413) {
    s21_decimal dec_1 = {{0x1302b, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xdec, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0xd8d9c969, 0x71aa66b4, 0x46986936, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_414) {
    s21_decimal dec_1 = {{0x9c097992, 0x11, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x19acdbfa, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x5a8f9bb0, 0xb298f14, 0x38bb9281, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_416) {
    s21_decimal dec_1 = {{0x6e41594a, 0x3340, 0x0, 0x80090000}};
    s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x6e41594a, 0x3340, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_417) {
    s21_decimal dec_1 = {{0x4c8741, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xb9eb628e, 0x1f43, 0x0, 0xc0000}};
    s21_decimal dec_check = {{0x8eb3208a, 0x8028f8e, 0x2f246bd2, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_418) {
    s21_decimal dec_1 = {{0xcae17fc6, 0x4, 0x0, 0xa0000}};
    s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x6570bfe3, 0x2, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_419) {
    s21_decimal dec_1 = {{0x79c2f5b5, 0xa96973ef, 0x163d947, 0x80000000}};
    s21_decimal dec_2 = {{0x5f567269, 0x23df0f55, 0x169e62bc, 0x1b0000}};
    s21_decimal dec_check = {{0xe64a2551, 0xde9b95d7, 0xc692784b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_420) {
    s21_decimal dec_1 = {{0x726b00f7, 0xf1b53591, 0x2babf1, 0x0}};
    s21_decimal dec_2 = {{0xe922835a, 0x767bd8ad, 0x74, 0x80000000}};
    s21_decimal dec_check = {{0xb02cda03, 0x311a5e9c, 0x4f67e80f, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_421) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xcfa73c0c, 0x149d9, 0x0, 0x0}};
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_422) {
    s21_decimal dec_1 = {{0x15f44dc3, 0xcf0f3de1, 0x25, 0x50000}};
    s21_decimal dec_2 = {{0xdb5d8360, 0xdce69d6f, 0x13364e5c, 0x160000}};
    s21_decimal dec_check = {{0xac4f8c78, 0xb02d01d0, 0x25e6d264, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_423) {
    s21_decimal dec_1 = {{0x493976, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x1a7b286, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0xe7bb0953, 0x327c8b90, 0x37d78bcd, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_424) {
    s21_decimal dec_1 = {{0x7504ad, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x96, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x4e031e, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_425) {
    s21_decimal dec_1 = {{0xc2bc3e85, 0x30, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xdc6abc1e, 0x0, 0x0, 0x80060000}};
    s21_decimal dec_check = {{0x8b614960, 0x3a2d1467, 0xb6fd34c4, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_426) {
    s21_decimal dec_1 = {{0x95afffed, 0x118469f, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xb47d, 0x0, 0x0, 0x80050000}};
    s21_decimal dec_check = {{0xd2bfb78f, 0x3182ac4c, 0x372b5292, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_427) {
    s21_decimal dec_1 = {{0x7957cc38, 0x1289380, 0x0, 0x80060000}};
    s21_decimal dec_2 = {{0xf63e7074, 0x9269, 0x0, 0xc0000}};
    s21_decimal dec_check = {{0xd4e794a1, 0xaee8af66, 0xa78dc55d, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_428) {
    s21_decimal dec_1 = {{0x3d6e0ec5, 0x6646c, 0x0, 0x800b0000}};
    s21_decimal dec_2 = {{0xe761faad, 0xfe98d7e3, 0x2, 0x80100000}};
    s21_decimal dec_check = {{0xd963348b, 0xc9a5c7cd, 0x693f2d42, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_429) {
    s21_decimal dec_1 = {{0xb328ec83, 0x671cf444, 0x3f7e049, 0x0}};
    s21_decimal dec_2 = {{0x14f593ef, 0x1f9157, 0x0, 0x40000}};
    s21_decimal dec_check = {{0xe8406115, 0x35c73b41, 0x2ca8ee08, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_430) {
    s21_decimal dec_1 = {{0x661b9825, 0x10adf7ac, 0x0, 0xf0000}};
    s21_decimal dec_2 = {{0x45723f7d, 0x6e28cd9b, 0x898421, 0x80180000}};
    s21_decimal dec_check = {{0xaef0f60, 0x75d430eb, 0xe99967ec, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_431) {
    s21_decimal dec_1 = {{0x466fe, 0x0, 0x0, 0x80020000}};
    s21_decimal dec_2 = {{0x3400a35e, 0x565, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0x4d43671b, 0x8a88af2, 0x9d256c3a, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_432) {
    s21_decimal dec_1 = {{0xeec2cd7b, 0x93, 0x0, 0x10000}};
    s21_decimal dec_2 = {{0xaea8e142, 0x2, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x324f2c3d, 0xefcd1343, 0xb234caed, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_433) {
    s21_decimal dec_1 = {{0xa4e83d49, 0xcfec7e64, 0x1b5, 0x80000000}};
    s21_decimal dec_2 = {{0x2a9a97ce, 0x11, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xc5a3d8e, 0x18204f3, 0x2364d62e, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_434) {
    s21_decimal dec_1 = {{0x767e5b87, 0xbbb88336, 0xc77b62b, 0x80130000}};
    s21_decimal dec_2 = {{0x3a99af60, 0xe548ec46, 0x35, 0x130000}};
    s21_decimal dec_check = {{0x170ec945, 0xc9b820dc, 0x7d6757ba, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_436) {
    s21_decimal dec_1 = {{0x32afa0fc, 0x860, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x96225a0f, 0x1b1f, 0x0, 0x800e0000}};
    s21_decimal dec_check = {{0x69d0f3ee, 0x39e9a9b1, 0x63c78ec0, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_437) {
    s21_decimal dec_1 = {{0x31022a81, 0x88ca270c, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xe85223b7, 0x7f4bba82, 0x1a9, 0x80000}};
    s21_decimal dec_check = {{0xdd0aff46, 0x231f7ccf, 0x2893a3d6, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_438) {
    s21_decimal dec_1 = {{0x638f02ae, 0x1603, 0x0, 0x80030000}};
    s21_decimal dec_2 = {{0xb114, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xa9d1fdc9, 0x4b830cce, 0xac8519a8, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_439) {
    s21_decimal dec_1 = {{0x4273afbb, 0xf0f297e, 0x53df, 0x80000000}};
    s21_decimal dec_2 = {{0x32744bf, 0x6ece12, 0x0, 0xd0000}};
    s21_decimal dec_check = {{0xf00f8a3a, 0x2756067c, 0x29087ab2, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_440) {
    s21_decimal dec_1 = {{0x4f1130d3, 0x12a249d, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x3edc178, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x8cedaefa, 0x8c7b8523, 0x29238d1b, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_441) {
    s21_decimal dec_1 = {{0xb57ef831, 0x0, 0x0, 0x80040000}};
    s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x284cf3cf, 0x3d90ae9a, 0xea4289e5, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_442) {
    s21_decimal dec_1 = {{0xbfbf8f4a, 0xaa78e02e, 0x4ee07183, 0x800f0000}};
    s21_decimal dec_2 = {{0x17c1, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x365b2272, 0xa09baad7, 0x81b5cb4c, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_443) {
    s21_decimal dec_1 = {{0x30eee476, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x3c2aedd, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xcc4c0590, 0x32fdfec2, 0x2a0bab76, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_444) {
    s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x2f69fa4c, 0xcf78ac43, 0xf3bdd0, 0x0}};
    s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_445) {
    s21_decimal dec_1 = {{0x750809f5, 0x15, 0x0, 0x80070000}};
    s21_decimal dec_2 = {{0x5522b746, 0x1, 0x0, 0xb0000}};
    s21_decimal dec_check = {{0x13fc07b7, 0x6aeb3526, 0x34076bfd, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_447) {
    s21_decimal dec_1 = {{0x66bec44e, 0x856, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x28c, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0x6cfb78ef, 0x7ad27196, 0x2d6e3d97, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_448) {
    s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x3139c, 0x0, 0x0, 0x60000}};
    s21_decimal dec_check = {{0xce8fd147, 0x8119cd9a, 0x903a93e9, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_449) {
    s21_decimal dec_1 = {{0x7c3b54a8, 0x2120b, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x1dc6cfe1, 0x628efaa2, 0x1a8, 0x80120000}};
    s21_decimal dec_check = {{0x58c08b6e, 0xa051614a, 0xf08b0fa1, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_450) {
    s21_decimal dec_1 = {{0x9ecfd93a, 0x2fa57, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x6dee182c, 0xb5b951ef, 0x23c5a39, 0x130000}};
    s21_decimal dec_check = {{0xb15a16e0, 0x3bb08058, 0x272471be, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_451) {
    s21_decimal dec_1 = {{0x477ea836, 0x1c50e9dd, 0x3, 0x80000000}};
    s21_decimal dec_2 = {{0x44d2b12e, 0x27eae047, 0xc, 0x80130000}};
    s21_decimal dec_check = {{0x90aaed61, 0x7f489517, 0x52aeec94, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_452) {
    s21_decimal dec_1 = {{0x27e8485c, 0x1606d4f5, 0x36, 0x30000}};
    s21_decimal dec_2 = {{0x52b8ad9e, 0x1d8fe, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x4e9581d3, 0xa07b9d6d, 0x3dfd0710, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_454) {
    s21_decimal dec_1 = {{0x5e, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x1c59, 0x0, 0x0, 0x40000}};
    s21_decimal dec_check = {{0x5765a188, 0x24c9e246, 0x29da7abf, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_div_457) {
    s21_decimal dec_1 = {{0xd86875ca, 0x21e52de0, 0xaa157f7e, 0x0}};
    s21_decimal dec_2 = {{0x49fa9502, 0x2, 0x0, 0x0}};
    s21_decimal dec_check = {{0x85dc4548, 0x4e49918f, 0xad0193e7, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_458) {
    s21_decimal dec_1 = {{0x37d8f4a0, 0x1046ea9, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x137, 0x0, 0x0, 0x80030000}};
    s21_decimal dec_check = {{0xee9062c7, 0x7db33b35, 0x4c294d9e, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_459) {
    s21_decimal dec_1 = {{0x4fc52a93, 0x72b, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x2f99b, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0xd10ef8df, 0x5472d883, 0x82a298e7, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_460) {
    s21_decimal dec_1 = {{0x2596, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xdebd738, 0x7e2ff5ab, 0x0, 0x110000}};
    s21_decimal dec_check = {{0x9331ffe3, 0xfc41e91a, 0x22314435, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_461) {
    s21_decimal dec_1 = {{0xafaaca50, 0xdc, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x810d453, 0xc0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x70c04af7, 0xff8d65ed, 0x25221d44, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_462) {
    s21_decimal dec_1 = {{0x174af80, 0x26a7c3, 0x0, 0x800b0000}};
    s21_decimal dec_2 = {{0x106f, 0x0, 0x0, 0x40000}};
    s21_decimal dec_check = {{0x7f597b39, 0xc6e3d85c, 0x53914194, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_463) {
    s21_decimal dec_1 = {{0x25cddc9a, 0x12fd8d, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x70bcb085, 0x7e2, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xf95fb78d, 0x7e04e591, 0xc73b6a80, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_464) {
    s21_decimal dec_1 = {{0x9c4d9f3a, 0x47dc29eb, 0x21a0b9e, 0x80030000}};
    s21_decimal dec_2 = {{0x1a954810, 0xd7, 0x0, 0x70000}};
    s21_decimal dec_check = {{0x81602b4b, 0x7ab5f5c3, 0xe37e9828, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_466) {
    s21_decimal dec_1 = {{0x97e00837, 0x14, 0x0, 0x70000}};
    s21_decimal dec_2 = {{0x364, 0x0, 0x0, 0x10000}};
    s21_decimal dec_check = {{0x7d481798, 0x5aa1f7ac, 0x20eccc38, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_467) {
    s21_decimal dec_1 = {{0x8990638, 0x3c982c9, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xa893df5c, 0x3480d, 0x0, 0x800d0000}};
    s21_decimal dec_check = {{0x63e86786, 0x584057a8, 0x5f7726de, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_468) {
    s21_decimal dec_1 = {{0x161c6, 0x0, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x5bc5, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0x942dfc19, 0xd7d5d134, 0x7c8ffbbe, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_469) {
    s21_decimal dec_1 = {{0x24b5, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x21d240, 0x0, 0x0, 0x70000}};
    s21_decimal dec_check = {{0x7bf1da24, 0xc23b3229, 0x88fcaf7a, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_470) {
    s21_decimal dec_1 = {{0xe413bae4, 0xdd93, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x416c9b39, 0x12, 0x0, 0x0}};
    s21_decimal dec_check = {{0x744ee0ec, 0x9fc7bfa, 0x64663f9e, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_471) {
    s21_decimal dec_1 = {{0x1ffd0e34, 0x91e1480, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xa6a96a8b, 0x4, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0x4338d186, 0xdc0702c7, 0x6a44ed92, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_472) {
    s21_decimal dec_1 = {{0x23a150, 0x0, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x22, 0x0, 0x0, 0x20000}};
    s21_decimal dec_check = {{0x9e1e1e2, 0xc1fff4b1, 0xdde93519, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_473) {
    s21_decimal dec_1 = {{0x565c0fa, 0xf09b72c6, 0x2ec34797, 0x80000000}};
    s21_decimal dec_2 = {{0xf8d39d, 0xbd528716, 0x54af, 0x110000}};
    s21_decimal dec_check = {{0x397644af, 0x2fa83530, 0x74ee23fc, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_474) {
    s21_decimal dec_1 = {{0x59a2f5b2, 0xd364ce9e, 0x8a336, 0x150000}};
    s21_decimal dec_2 = {{0x319, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x6c1670c4, 0xd0343770, 0x2a8c4058, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_475) {
    s21_decimal dec_1 = {{0xa14fcec7, 0x74e3b82c, 0x64dad, 0x100000}};
    s21_decimal dec_2 = {{0xbb425c5e, 0x1838535a, 0x2, 0x140000}};
    s21_decimal dec_check = {{0x74345c92, 0x6c0a964d, 0x3fb9c204, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_476) {
    s21_decimal dec_1 = {{0x20f1c38a, 0xa8732615, 0xa1eba, 0x0}};
    s21_decimal dec_2 = {{0xb9f02b2a, 0x41a2b, 0x0, 0x800c0000}};
    s21_decimal dec_check = {{0x901acdbf, 0xc5baa256, 0x223c66d7, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_478) {
    s21_decimal dec_1 = {{0x46129087, 0x4403b, 0x0, 0x0}};
    s21_decimal dec_2 = {{0x1c510838, 0x10caf5d, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x32b20214, 0xfca5c78, 0x331ef1ab, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_479) {
    s21_decimal dec_1 = {{0x2bbb9203, 0x9f57a625, 0xf2439, 0x20000}};
    s21_decimal dec_2 = {{0x90f56da4, 0x177ac, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xded26d7d, 0x370dfaeb, 0x8f311669, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_480) {
    s21_decimal dec_1 = {{0xc72f1e13, 0xa92ba304, 0x19c8c9d, 0x0}};
    s21_decimal dec_2 = {{0x5e9fd8f1, 0x1732fcbc, 0x13, 0x80010000}};
    s21_decimal dec_check = {{0x2f55ecfc, 0xe4eb82fd, 0x2dc2d4cf, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_481) {
    s21_decimal dec_1 = {{0x641982ec, 0x82daa6, 0x0, 0x80050000}};
    s21_decimal dec_2 = {{0x2ea5ba5b, 0x2f, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xf62cc82b, 0x944f3c62, 0x3aba8292, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_482) {
    s21_decimal dec_1 = {{0x980e892c, 0x4d817436, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x11632b9f, 0xa35fdd76, 0x20d, 0x80120000}};
    s21_decimal dec_check = {{0x253a4d6, 0x5322780f, 0xba1bde02, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_484) {
    s21_decimal dec_1 = {{0xfeb689a2, 0x1350ddd, 0x0, 0x80070000}};
    s21_decimal dec_2 = {{0x8dcccda9, 0xc1666247, 0xfb2, 0x80110000}};
    s21_decimal dec_check = {{0x52b62d60, 0x73f1afa5, 0x25ea8479, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_486) {
    s21_decimal dec_1 = {{0xac803f5f, 0xea7e0949, 0xff, 0x80000000}};
    s21_decimal dec_2 = {{0x4269f6bd, 0x86a, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xf6769252, 0xff991d4c, 0xa4dc9569, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_488) {
    s21_decimal dec_1 = {{0x2ff3bd71, 0x18925, 0x0, 0x0}};
    s21_decimal dec_2 = {{0xb882ec0c, 0x1, 0x0, 0x90000}};
    s21_decimal dec_check = {{0x75455f75, 0xc6f71687, 0xbcfd2595, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_490) {
    s21_decimal dec_1 = {{0x85e2e03b, 0x38ff859, 0xe4f6a65, 0x80000000}};
    s21_decimal dec_2 = {{0x7b5371ad, 0x555, 0x0, 0x800d0000}};
    s21_decimal dec_check = {{0x70251bbc, 0x27a54b4, 0xf40187ca, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_491) {
    s21_decimal dec_1 = {{0xe9e06295, 0xed9bb5c8, 0x1273, 0x0}};
    s21_decimal dec_2 = {{0x41, 0x0, 0x0, 0x80010000}};
    s21_decimal dec_check = {{0xb4f5daf6, 0x7c787cb, 0x2b517322, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_492) {
    s21_decimal dec_1 = {{0xa6805eec, 0x1a3a55f2, 0x27e5, 0x80060000}};
    s21_decimal dec_2 = {{0x5a, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x80b2cc7, 0x6754333c, 0x43a38229, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_493) {
    s21_decimal dec_1 = {{0x6d83c77b, 0x60504fe2, 0xdd0bffe1, 0x0}};
    s21_decimal dec_2 = {{0xc446dfd6, 0x7ca3fafb, 0x1cbff, 0xc0000}};
    s21_decimal dec_check = {{0xc8bd3f46, 0xe0de8ba, 0x65c20f26, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_494) {
    s21_decimal dec_1 = {{0x2d56343d, 0x56c4de2a, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0x14cb9536, 0x0, 0x0, 0x0}};
    s21_decimal dec_check = {{0x3ca81f31, 0x1bc7e252, 0x39e7d7f3, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_495) {
    s21_decimal dec_1 = {{0xea148c33, 0x9b0d29b6, 0x174c9c, 0x140000}};
    s21_decimal dec_2 = {{0x4f07e3, 0x0, 0x0, 0x60000}};
    s21_decimal dec_check = {{0xf55c982d, 0x9ebe2eab, 0xafb8cea6, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_496) {
    s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
    s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
    s21_decimal dec_check = {{0xa8fa8c25, 0xf986b766, 0x298248da, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_497) {
    s21_decimal dec_1 = {{0x9c41d135, 0x7501b5c, 0x0, 0x80000000}};
    s21_decimal dec_2 = {{0xdd7ef692, 0x0, 0x0, 0x80040000}};
    s21_decimal dec_check = {{0x4287d629, 0xba43e0b2, 0x2dd1a6ac, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


START_TEST(s21_div_499) {
    s21_decimal dec_1 = {{0x2a8bd92f, 0xd9deaa35, 0x8ab7, 0x60000}};
    s21_decimal dec_2 = {{0x8ee2f1f1, 0x135cc8, 0x0, 0x0}};
    s21_decimal dec_check = {{0x67847069, 0x4fcf2754, 0x26d67455, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_500) {
    s21_decimal dec_1 = {{0xdc8d3cd3, 0x6c, 0x0, 0xa0000}};
    s21_decimal dec_2 = {{0x39efacea, 0x2, 0x0, 0x80090000}};
    s21_decimal dec_check = {{0xbedc29a4, 0xfa01c3a8, 0x9dff339a, 0x801c0000}};
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
    tcase_add_test(tc, s21_div_101);
    tcase_add_test(tc, s21_div_103);
  tcase_add_test(tc, s21_div_104);
  tcase_add_test(tc, s21_div_105);
  tcase_add_test(tc, s21_div_106);
  tcase_add_test(tc, s21_div_107);
  tcase_add_test(tc, s21_div_108);
  tcase_add_test(tc, s21_div_109);
  tcase_add_test(tc, s21_div_110);
      tcase_add_test(tc, s21_div_113);
  tcase_add_test(tc, s21_div_114);
  tcase_add_test(tc, s21_div_115);
    tcase_add_test(tc, s21_div_117);
  tcase_add_test(tc, s21_div_118);
  tcase_add_test(tc, s21_div_119);
  tcase_add_test(tc, s21_div_120);
  tcase_add_test(tc, s21_div_121);
  tcase_add_test(tc, s21_div_122);
  tcase_add_test(tc, s21_div_123);
  tcase_add_test(tc, s21_div_124);
    tcase_add_test(tc, s21_div_126);
  tcase_add_test(tc, s21_div_127);
  tcase_add_test(tc, s21_div_128);
  tcase_add_test(tc, s21_div_129);
  tcase_add_test(tc, s21_div_130);
  tcase_add_test(tc, s21_div_131);
  tcase_add_test(tc, s21_div_132);
  tcase_add_test(tc, s21_div_133);
  tcase_add_test(tc, s21_div_134);
  tcase_add_test(tc, s21_div_135);
  tcase_add_test(tc, s21_div_136);
  tcase_add_test(tc, s21_div_137);
  tcase_add_test(tc, s21_div_138);
  tcase_add_test(tc, s21_div_139);
  tcase_add_test(tc, s21_div_140);
  tcase_add_test(tc, s21_div_141);
  tcase_add_test(tc, s21_div_142);
  tcase_add_test(tc, s21_div_143);
  tcase_add_test(tc, s21_div_144);
  tcase_add_test(tc, s21_div_145);
  // tcase_add_test(tc, s21_div_146);
  tcase_add_test(tc, s21_div_147);
  tcase_add_test(tc, s21_div_148);
  tcase_add_test(tc, s21_div_149);
  tcase_add_test(tc, s21_div_150);
    tcase_add_test(tc, s21_div_152);
  tcase_add_test(tc, s21_div_153);
  tcase_add_test(tc, s21_div_154);
  tcase_add_test(tc, s21_div_155);
  tcase_add_test(tc, s21_div_156);
  tcase_add_test(tc, s21_div_157);
  tcase_add_test(tc, s21_div_158);
    tcase_add_test(tc, s21_div_160);
  tcase_add_test(tc, s21_div_161);
    tcase_add_test(tc, s21_div_163);
  tcase_add_test(tc, s21_div_164);
  tcase_add_test(tc, s21_div_165);
  tcase_add_test(tc, s21_div_166);
  tcase_add_test(tc, s21_div_167);
  tcase_add_test(tc, s21_div_168);
  tcase_add_test(tc, s21_div_169);
  tcase_add_test(tc, s21_div_170);
      tcase_add_test(tc, s21_div_173);
  tcase_add_test(tc, s21_div_174);
    tcase_add_test(tc, s21_div_176);
  tcase_add_test(tc, s21_div_177);
  tcase_add_test(tc, s21_div_178);
  tcase_add_test(tc, s21_div_179);
  tcase_add_test(tc, s21_div_180);
    tcase_add_test(tc, s21_div_182);
    tcase_add_test(tc, s21_div_184);
  tcase_add_test(tc, s21_div_185);
  tcase_add_test(tc, s21_div_186);
  tcase_add_test(tc, s21_div_187);
  tcase_add_test(tc, s21_div_188);
  tcase_add_test(tc, s21_div_189);
  tcase_add_test(tc, s21_div_190);
  tcase_add_test(tc, s21_div_191);
  tcase_add_test(tc, s21_div_192);
  tcase_add_test(tc, s21_div_193);
  tcase_add_test(tc, s21_div_194);
  tcase_add_test(tc, s21_div_195);
  tcase_add_test(tc, s21_div_196);
  tcase_add_test(tc, s21_div_197);
  tcase_add_test(tc, s21_div_198);
  tcase_add_test(tc, s21_div_199);
  tcase_add_test(tc, s21_div_200);
  tcase_add_test(tc, s21_div_201);
  tcase_add_test(tc, s21_div_202);
  tcase_add_test(tc, s21_div_203);
  tcase_add_test(tc, s21_div_204);
  tcase_add_test(tc, s21_div_205);
  tcase_add_test(tc, s21_div_206);
  tcase_add_test(tc, s21_div_207);
  tcase_add_test(tc, s21_div_208);
  tcase_add_test(tc, s21_div_209);
  tcase_add_test(tc, s21_div_210);
  tcase_add_test(tc, s21_div_211);
  tcase_add_test(tc, s21_div_212);
  tcase_add_test(tc, s21_div_213);
  tcase_add_test(tc, s21_div_214);
  tcase_add_test(tc, s21_div_215);
  tcase_add_test(tc, s21_div_216);
  tcase_add_test(tc, s21_div_217);
  tcase_add_test(tc, s21_div_218);
  tcase_add_test(tc, s21_div_219);
  tcase_add_test(tc, s21_div_220);
  tcase_add_test(tc, s21_div_221);
  tcase_add_test(tc, s21_div_222);
  tcase_add_test(tc, s21_div_223);
  tcase_add_test(tc, s21_div_224);
  tcase_add_test(tc, s21_div_225);
  tcase_add_test(tc, s21_div_226);
  tcase_add_test(tc, s21_div_227);
  tcase_add_test(tc, s21_div_228);
  tcase_add_test(tc, s21_div_229);
  tcase_add_test(tc, s21_div_230);
  tcase_add_test(tc, s21_div_231);
  tcase_add_test(tc, s21_div_232);
  tcase_add_test(tc, s21_div_233);
    tcase_add_test(tc, s21_div_235);
  tcase_add_test(tc, s21_div_236);
  tcase_add_test(tc, s21_div_237);
  tcase_add_test(tc, s21_div_238);
    tcase_add_test(tc, s21_div_240);
  tcase_add_test(tc, s21_div_241);
  tcase_add_test(tc, s21_div_242);
  tcase_add_test(tc, s21_div_243);
  tcase_add_test(tc, s21_div_244);
  tcase_add_test(tc, s21_div_245);
  tcase_add_test(tc, s21_div_246);
  tcase_add_test(tc, s21_div_247);
  tcase_add_test(tc, s21_div_248);
  tcase_add_test(tc, s21_div_249);
    tcase_add_test(tc, s21_div_251);
  tcase_add_test(tc, s21_div_252);
    tcase_add_test(tc, s21_div_254);
  tcase_add_test(tc, s21_div_255);
    tcase_add_test(tc, s21_div_257);
  tcase_add_test(tc, s21_div_258);
  tcase_add_test(tc, s21_div_259);
    tcase_add_test(tc, s21_div_261);
  tcase_add_test(tc, s21_div_262);
  tcase_add_test(tc, s21_div_263);
  tcase_add_test(tc, s21_div_264);
  tcase_add_test(tc, s21_div_265);
  tcase_add_test(tc, s21_div_266);
  tcase_add_test(tc, s21_div_267);
    tcase_add_test(tc, s21_div_269);
      tcase_add_test(tc, s21_div_272);
  tcase_add_test(tc, s21_div_273);
  tcase_add_test(tc, s21_div_274);
  tcase_add_test(tc, s21_div_275);
  tcase_add_test(tc, s21_div_276);
  tcase_add_test(tc, s21_div_277);
  tcase_add_test(tc, s21_div_278);
  tcase_add_test(tc, s21_div_279);
  tcase_add_test(tc, s21_div_280);
  tcase_add_test(tc, s21_div_281);
  tcase_add_test(tc, s21_div_282);
  tcase_add_test(tc, s21_div_283);
  tcase_add_test(tc, s21_div_284);
      tcase_add_test(tc, s21_div_287);
    tcase_add_test(tc, s21_div_289);
  tcase_add_test(tc, s21_div_290);
    tcase_add_test(tc, s21_div_292);
  tcase_add_test(tc, s21_div_293);
  tcase_add_test(tc, s21_div_294);
  tcase_add_test(tc, s21_div_295);
  tcase_add_test(tc, s21_div_296);
    tcase_add_test(tc, s21_div_298);
  tcase_add_test(tc, s21_div_299);
  tcase_add_test(tc, s21_div_300);
    tcase_add_test(tc, s21_div_302);
    tcase_add_test(tc, s21_div_304);
  tcase_add_test(tc, s21_div_305);
  tcase_add_test(tc, s21_div_306);
  tcase_add_test(tc, s21_div_307);
  tcase_add_test(tc, s21_div_308);
  tcase_add_test(tc, s21_div_309);
    tcase_add_test(tc, s21_div_311);
  tcase_add_test(tc, s21_div_312);
  tcase_add_test(tc, s21_div_313);
  tcase_add_test(tc, s21_div_314);
  tcase_add_test(tc, s21_div_315);
  tcase_add_test(tc, s21_div_316);
  tcase_add_test(tc, s21_div_317);
  tcase_add_test(tc, s21_div_318);
    tcase_add_test(tc, s21_div_320);
  tcase_add_test(tc, s21_div_321);
  tcase_add_test(tc, s21_div_322);
  tcase_add_test(tc, s21_div_323);
  tcase_add_test(tc, s21_div_324);
  tcase_add_test(tc, s21_div_325);
  tcase_add_test(tc, s21_div_326);
    tcase_add_test(tc, s21_div_328);
  tcase_add_test(tc, s21_div_329);
    tcase_add_test(tc, s21_div_331);
  tcase_add_test(tc, s21_div_332);
  tcase_add_test(tc, s21_div_333);
  tcase_add_test(tc, s21_div_334);
  tcase_add_test(tc, s21_div_335);
  tcase_add_test(tc, s21_div_336);
  tcase_add_test(tc, s21_div_337);
    tcase_add_test(tc, s21_div_339);
  tcase_add_test(tc, s21_div_340);
  tcase_add_test(tc, s21_div_341);
    tcase_add_test(tc, s21_div_343);
  tcase_add_test(tc, s21_div_344);
  tcase_add_test(tc, s21_div_345);
  tcase_add_test(tc, s21_div_346);
  tcase_add_test(tc, s21_div_347);
  tcase_add_test(tc, s21_div_348);
  tcase_add_test(tc, s21_div_349);
  tcase_add_test(tc, s21_div_350);
  tcase_add_test(tc, s21_div_351);
  tcase_add_test(tc, s21_div_352);
  tcase_add_test(tc, s21_div_353);
  tcase_add_test(tc, s21_div_354);
  tcase_add_test(tc, s21_div_355);
  tcase_add_test(tc, s21_div_356);
    tcase_add_test(tc, s21_div_358);
  tcase_add_test(tc, s21_div_359);
  tcase_add_test(tc, s21_div_360);
  tcase_add_test(tc, s21_div_361);
  tcase_add_test(tc, s21_div_362);
  tcase_add_test(tc, s21_div_363);
  tcase_add_test(tc, s21_div_364);
    tcase_add_test(tc, s21_div_366);
  tcase_add_test(tc, s21_div_367);
  tcase_add_test(tc, s21_div_368);
  tcase_add_test(tc, s21_div_369);
  tcase_add_test(tc, s21_div_370);
  tcase_add_test(tc, s21_div_371);
  tcase_add_test(tc, s21_div_372);
  tcase_add_test(tc, s21_div_373);
  tcase_add_test(tc, s21_div_374);
  tcase_add_test(tc, s21_div_375);
    tcase_add_test(tc, s21_div_377);
  tcase_add_test(tc, s21_div_378);
  tcase_add_test(tc, s21_div_379);
  tcase_add_test(tc, s21_div_380);
  tcase_add_test(tc, s21_div_381);
  tcase_add_test(tc, s21_div_382);
  tcase_add_test(tc, s21_div_383);
  tcase_add_test(tc, s21_div_384);
    tcase_add_test(tc, s21_div_386);
    tcase_add_test(tc, s21_div_388);
  tcase_add_test(tc, s21_div_389);
  tcase_add_test(tc, s21_div_390);
  tcase_add_test(tc, s21_div_391);
  tcase_add_test(tc, s21_div_392);
  tcase_add_test(tc, s21_div_393);
  tcase_add_test(tc, s21_div_394);
  tcase_add_test(tc, s21_div_395);
  tcase_add_test(tc, s21_div_396);
  tcase_add_test(tc, s21_div_397);
  tcase_add_test(tc, s21_div_398);
  tcase_add_test(tc, s21_div_399);
  tcase_add_test(tc, s21_div_400);
  tcase_add_test(tc, s21_div_401);
  tcase_add_test(tc, s21_div_402);
  tcase_add_test(tc, s21_div_403);
  tcase_add_test(tc, s21_div_404);
    tcase_add_test(tc, s21_div_406);
  tcase_add_test(tc, s21_div_407);
  tcase_add_test(tc, s21_div_408);
  tcase_add_test(tc, s21_div_409);
  tcase_add_test(tc, s21_div_410);
    tcase_add_test(tc, s21_div_412);
  tcase_add_test(tc, s21_div_413);
  tcase_add_test(tc, s21_div_414);
    tcase_add_test(tc, s21_div_416);
  tcase_add_test(tc, s21_div_417);
  tcase_add_test(tc, s21_div_418);
  tcase_add_test(tc, s21_div_419);
  tcase_add_test(tc, s21_div_420);
  tcase_add_test(tc, s21_div_421);
  tcase_add_test(tc, s21_div_422);
  tcase_add_test(tc, s21_div_423);
  tcase_add_test(tc, s21_div_424);
  tcase_add_test(tc, s21_div_425);
  tcase_add_test(tc, s21_div_426);
  tcase_add_test(tc, s21_div_427);
  tcase_add_test(tc, s21_div_428);
  tcase_add_test(tc, s21_div_429);
  tcase_add_test(tc, s21_div_430);
  tcase_add_test(tc, s21_div_431);
  tcase_add_test(tc, s21_div_432);
  tcase_add_test(tc, s21_div_433);
  tcase_add_test(tc, s21_div_434);
    tcase_add_test(tc, s21_div_436);
  tcase_add_test(tc, s21_div_437);
  tcase_add_test(tc, s21_div_438);
  tcase_add_test(tc, s21_div_439);
  tcase_add_test(tc, s21_div_440);
  tcase_add_test(tc, s21_div_441);
  tcase_add_test(tc, s21_div_442);
  tcase_add_test(tc, s21_div_443);
  tcase_add_test(tc, s21_div_444);
  tcase_add_test(tc, s21_div_445);
    tcase_add_test(tc, s21_div_447);
  tcase_add_test(tc, s21_div_448);
  tcase_add_test(tc, s21_div_449);
  tcase_add_test(tc, s21_div_450);
  tcase_add_test(tc, s21_div_451);
  tcase_add_test(tc, s21_div_452);
    tcase_add_test(tc, s21_div_454);
      tcase_add_test(tc, s21_div_457);
  tcase_add_test(tc, s21_div_458);
  tcase_add_test(tc, s21_div_459);
  tcase_add_test(tc, s21_div_460);
  tcase_add_test(tc, s21_div_461);
  tcase_add_test(tc, s21_div_462);
  tcase_add_test(tc, s21_div_463);
  tcase_add_test(tc, s21_div_464);
    tcase_add_test(tc, s21_div_466);
  tcase_add_test(tc, s21_div_467);
  tcase_add_test(tc, s21_div_468);
  tcase_add_test(tc, s21_div_469);
  tcase_add_test(tc, s21_div_470);
  tcase_add_test(tc, s21_div_471);
  tcase_add_test(tc, s21_div_472);
  tcase_add_test(tc, s21_div_473);
  tcase_add_test(tc, s21_div_474);
  tcase_add_test(tc, s21_div_475);
  tcase_add_test(tc, s21_div_476);
    tcase_add_test(tc, s21_div_478);
  tcase_add_test(tc, s21_div_479);
  tcase_add_test(tc, s21_div_480);
  tcase_add_test(tc, s21_div_481);
  tcase_add_test(tc, s21_div_482);
    tcase_add_test(tc, s21_div_484);
    tcase_add_test(tc, s21_div_486);
    tcase_add_test(tc, s21_div_488);
    tcase_add_test(tc, s21_div_490);
  tcase_add_test(tc, s21_div_491);
  tcase_add_test(tc, s21_div_492);
  tcase_add_test(tc, s21_div_493);
  tcase_add_test(tc, s21_div_494);
  tcase_add_test(tc, s21_div_495);
  tcase_add_test(tc, s21_div_496);
  tcase_add_test(tc, s21_div_497);
    tcase_add_test(tc, s21_div_499);
  tcase_add_test(tc, s21_div_500);
                                                                                                                                                                                                                                                                                                                                            
  suite_add_tcase(c, tc);
  return c;
}
