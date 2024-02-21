#include "s21_decimal_test.h"

START_TEST(invalid_dec_s21_sub_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_sub(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_sub_1) {
  // -182
  s21_decimal dec_1 = {{0xb6, 0x0, 0x0, 0x80000000}};
  // -0.50783375608502233
  s21_decimal dec_2 = {{0x7a3d7d9, 0xb46b36, 0x0, 0x80110000}};
  // -181.49216624391497767
  s21_decimal dec_check = {{0x78782827, 0xfbdef85c, 0x0, 0x80110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // 15918596787339
  s21_decimal dec_1 = {{0x564e8c8b, 0xe7a, 0x0, 0x0}};
  // -5160.94298
  s21_decimal dec_2 = {{0x1ec2f95a, 0x0, 0x0, 0x80050000}};
  // 15918596792499.94298
  s21_decimal dec_check = {{0xb9f6923a, 0x16176bf1, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 41940
  s21_decimal dec_1 = {{0xa3d4, 0x0, 0x0, 0x0}};
  // -99838.293183596
  s21_decimal dec_2 = {{0x6a000c6c, 0x5acd, 0x0, 0x80090000}};
  // 141778.293183596
  s21_decimal dec_check = {{0x54cd546c, 0x80f2, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // 735952676749954461663058221
  s21_decimal dec_1 = {{0x2b35592d, 0x8c876817, 0x260c40a, 0x0}};
  // 649022.36198815138032015
  s21_decimal dec_2 = {{0x9b03a98f, 0x5b765409, 0xdbe, 0x110000}};
  // 735952676749954461662409198.64
  s21_decimal dec_check = {{0xdcf88138, 0xe4e4a90c, 0xedcc941e, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // 41355374059190707
  s21_decimal dec_1 = {{0x5c59f9b3, 0x92ec7e, 0x0, 0x0}};
  // 1516559603317
  s21_decimal dec_2 = {{0x19ff1675, 0x161, 0x0, 0x0}};
  // 41353857499587390
  s21_decimal dec_check = {{0x425ae33e, 0x92eb1d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_7) {
  // 475597970416811771540677.6010
  s21_decimal dec_1 = {{0x72566ca, 0x60b7a1b0, 0xf5e0de0, 0x40000}};
  // 430.3871889893075214683918
  s21_decimal dec_2 = {{0x4dc4f0e, 0x5cd70731, 0x38f61, 0x160000}};
  // 475597970416811771540247.21381
  s21_decimal dec_check = {{0x44e54be5, 0xc72c50e0, 0x99ac8ac3, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_8) {
  // -14039210424.8
  s21_decimal dec_1 = {{0xb0058138, 0x20, 0x0, 0x80010000}};
  // -479068929
  s21_decimal dec_2 = {{0x1c8e0301, 0x0, 0x0, 0x80000000}};
  // -13560141495.8
  s21_decimal dec_check = {{0x9279632e, 0x1f, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // -2399911820
  s21_decimal dec_1 = {{0x8f0bbf8c, 0x0, 0x0, 0x80000000}};
  // 84394125364381342
  s21_decimal dec_2 = {{0x8779469e, 0x12bd402, 0x0, 0x0}};
  // -84394127764293162
  s21_decimal dec_check = {{0x1685062a, 0x12bd403, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // 32680
  s21_decimal dec_1 = {{0x7fa8, 0x0, 0x0, 0x0}};
  // -0.8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80010000}};
  // 32680.8
  s21_decimal dec_check = {{0x4fc98, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // 127645
  s21_decimal dec_1 = {{0x1f29d, 0x0, 0x0, 0x0}};
  // -4.12406
  s21_decimal dec_2 = {{0x64af6, 0x0, 0x0, 0x80050000}};
  // 127649.12406
  s21_decimal dec_check = {{0xf8d91b16, 0x2, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // -8064.6480714416
  s21_decimal dec_1 = {{0xf8d5dab0, 0x4958, 0x0, 0x800a0000}};
  // 84314760960947
  s21_decimal dec_2 = {{0xf605bb3, 0x4caf, 0x0, 0x0}};
  // -84314760969011.6480714416
  s21_decimal dec_check = {{0x773246b0, 0x1f9e31ab, 0xb28b, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // -95998699911108633921367110
  s21_decimal dec_1 = {{0x5d78ac46, 0xf3314294, 0x4f6883, 0x80000000}};
  // -530905450383547902
  s21_decimal dec_2 = {{0xbb6e1dfe, 0x75e27b1, 0x0, 0x80000000}};
  // -95998699380203183537819208
  s21_decimal dec_check = {{0xa20a8e48, 0xebd31ae2, 0x4f6883, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // -64950332745486331
  s21_decimal dec_1 = {{0xc7568ffb, 0xe6bffb, 0x0, 0x80000000}};
  // -0.5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -64950332745486330.5
  s21_decimal dec_check = {{0xc9619fc9, 0x9037fd5, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // 656633.43380
  s21_decimal dec_1 = {{0x49d71b14, 0xf, 0x0, 0x50000}};
  // -618081791504137475088523
  s21_decimal dec_2 = {{0x2d58608b, 0x47f34b55, 0x82e2, 0x80000000}};
  // 618081791504137475745156.43380
  s21_decimal dec_check = {{0x442733f4, 0x9cd2d860, 0xc7b68709, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // -82
  s21_decimal dec_1 = {{0x52, 0x0, 0x0, 0x80000000}};
  // 3529212
  s21_decimal dec_2 = {{0x35d9fc, 0x0, 0x0, 0x0}};
  // -3529294
  s21_decimal dec_check = {{0x35da4e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_17) {
  // -57785037
  s21_decimal dec_1 = {{0x371bacd, 0x0, 0x0, 0x80000000}};
  // 852511965738427127
  s21_decimal dec_2 = {{0xb49be2f7, 0xbd4bb1d, 0x0, 0x0}};
  // -852511965796212164
  s21_decimal dec_check = {{0xb80d9dc4, 0xbd4bb1d, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_18) {
  // 184719217010682417004
  s21_decimal dec_1 = {{0xd604cf6c, 0x37e7d2f, 0xa, 0x0}};
  // 90328358501144738493236
  s21_decimal dec_2 = {{0x4157334, 0xb5cad4a3, 0x1320, 0x0}};
  // -90143639284134056076232
  s21_decimal dec_check = {{0x2e10a3c8, 0xb24c5773, 0x1316, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_19) {
  // -30852328586862
  s21_decimal dec_1 = {{0x5e15fe6e, 0x1c0f, 0x0, 0x80000000}};
  // 1128130017165329758160.2
  s21_decimal dec_2 = {{0x8c15ae22, 0x8f7d6f3a, 0x263, 0x10000}};
  // -1128130048017658345022.2
  s21_decimal dec_check = {{0x38f19e6e, 0x8f7e87d4, 0x263, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_20) {
  // -498
  s21_decimal dec_1 = {{0x1f2, 0x0, 0x0, 0x80000000}};
  // -29812172337711069692316.608
  s21_decimal dec_2 = {{0x916a4bc0, 0x19caf1ab, 0x18a8f9, 0x80030000}};
  // 29812172337711069691818.608
  s21_decimal dec_check = {{0x9162b270, 0x19caf1ab, 0x18a8f9, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_21) {
  // -4.6722342448627027148
  s21_decimal dec_1 = {{0x54918ccc, 0x88671ae9, 0x2, 0x80130000}};
  // 14308.7058815
  s21_decimal dec_2 = {{0x50a73f7f, 0x21, 0x0, 0x70000}};
  // -14313.3781157448627027148
  s21_decimal dec_check = {{0xe1647ccc, 0x4c3e376c, 0x1e4f, 0x80130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_22) {
  // 779901676027877975
  s21_decimal dec_1 = {{0x375f9a57, 0xad2c471, 0x0, 0x0}};
  // 90580.3469191878
  s21_decimal dec_2 = {{0xce047ac6, 0x337d2, 0x0, 0xa0000}};
  // 779901676027787394.6530808122
  s21_decimal dec_check = {{0x852e013a, 0xbcb991ec, 0x19333209, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_23) {
  // -34964717336799467
  s21_decimal dec_1 = {{0xa48828eb, 0x7c3839, 0x0, 0x80000000}};
  // 8514969003491512871054253569
  s21_decimal dec_2 = {{0x45849e01, 0x9c929171, 0x1b836ad2, 0x0}};
  // -8514969003526477588391053036
  s21_decimal dec_check = {{0xea0cc6ec, 0x9d0ec9aa, 0x1b836ad2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_24) {
  // 9.1176
  s21_decimal dec_1 = {{0x16428, 0x0, 0x0, 0x40000}};
  // -91217455856511813255.743
  s21_decimal dec_2 = {{0x15d1823f, 0xe87f2ab4, 0x1350, 0x80030000}};
  // 91217455856511813264.8606
  s21_decimal dec_check = {{0xda307a9e, 0x14f7ab08, 0xc129, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_25) {
  // -1654430596046757940527
  s21_decimal dec_1 = {{0x38c9cd2f, 0xafd6358e, 0x59, 0x80000000}};
  // -8.0496325239556134666
  s21_decimal dec_2 = {{0x4c0dd70a, 0x5d1c6551, 0x4, 0x80130000}};
  // -1654430596046757940518.9503675
  s21_decimal dec_check = {{0x723bdabb, 0x3aedd434, 0x3575210f, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_26) {
  // -7112292197632447386309961640
  s21_decimal dec_1 = {{0x8e9527a8, 0x99eadf1e, 0x16fb2674, 0x80000000}};
  // 710293735183793748521465
  s21_decimal dec_2 = {{0xec3531f9, 0x19bcf429, 0x9669, 0x0}};
  // -7113002491367631180058483105
  s21_decimal dec_check = {{0x7aca59a1, 0xb3a7d348, 0x16fbbcdd, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_27) {
  // 4864875386036847602
  s21_decimal dec_1 = {{0x6d4483f2, 0x43838263, 0x0, 0x0}};
  // 371665361703600267292352.181
  s21_decimal dec_2 = {{0xc8789eb5, 0xa13cb76d, 0x1336f33, 0x30000}};
  // -371660496828214230444750.181
  s21_decimal dec_check = {{0xf4d53565, 0xe787630a, 0x1336e2b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_28) {
  // 4.6334987
  s21_decimal dec_1 = {{0x2c3040b, 0x0, 0x0, 0x70000}};
  // 3399147970456216481
  s21_decimal dec_2 = {{0xd60863a1, 0x2f2c3311, 0x0, 0x0}};
  // -3399147970456216476.3665013
  s21_decimal dec_check = {{0x13672275, 0xce9d114f, 0x1c1df9, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_29) {
  // -487.335815
  s21_decimal dec_1 = {{0x1d0c2787, 0x0, 0x0, 0x80060000}};
  // 9194191625.0712060595
  s21_decimal dec_2 = {{0x6c6832b3, 0xfbf34db3, 0x4, 0xa0000}};
  // -9194192112.4070210595
  s21_decimal dec_check = {{0x17303c23, 0xfbf35222, 0x4, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_30) {
  // -776140965900020181964046.16101
  s21_decimal dec_1 = {{0x2a40bba5, 0xeb437c0b, 0xfac8e03e, 0x80050000}};
  // -6751.7
  s21_decimal dec_2 = {{0x107bd, 0x0, 0x0, 0x80010000}};
  // -776140965900020181957294.46101
  s21_decimal dec_check = {{0x20274d5, 0xeb437c0b, 0xfac8e03e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_31) {
  // 9901490544450990908487868508
  s21_decimal dec_1 = {{0x2119a05c, 0xf4f8dad3, 0x1ffe522d, 0x0}};
  // -611232230762
  s21_decimal dec_2 = {{0x5047ad6a, 0x8e, 0x0, 0x80000000}};
  // 9901490544450991519720099270
  s21_decimal dec_check = {{0x71614dc6, 0xf4f8db61, 0x1ffe522d, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_32) {
  // -79765648.331
  s21_decimal dec_1 = {{0x926733cb, 0x12, 0x0, 0x80030000}};
  // -60800309359330841
  s21_decimal dec_2 = {{0x2998c619, 0xd8018f, 0x0, 0x80000000}};
  // 60800309279565192.669
  s21_decimal dec_check = {{0xea5e9ddd, 0x4bc61727, 0x3, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_33) {
  // 240.2374
  s21_decimal dec_1 = {{0x24a846, 0x0, 0x0, 0x40000}};
  // 22560
  s21_decimal dec_2 = {{0x5820, 0x0, 0x0, 0x0}};
  // -22319.7626
  s21_decimal dec_check = {{0xd4db9ba, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_34) {
  // 6581376207
  s21_decimal dec_1 = {{0x8847d4cf, 0x1, 0x0, 0x0}};
  // -0.7901397392206501949437672440
  s21_decimal dec_2 = {{0x59e87bf8, 0xea42a562, 0x1987e1fa, 0x801c0000}};
  // 6581376207.7901397392206501949
  s21_decimal dec_check = {{0x3a42983d, 0x3719f948, 0xd4a7de37, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_35) {
  // -2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -31.460125
  s21_decimal dec_2 = {{0x1e00b1d, 0x0, 0x0, 0x80060000}};
  // 29.460125
  s21_decimal dec_check = {{0x1c1869d, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_36) {
  // -7994313.271837397640509
  s21_decimal dec_1 = {{0x92e0653d, 0x5f621d0c, 0x1b1, 0x800f0000}};
  // -2496592256.4943090614897
  s21_decimal dec_2 = {{0x5e190271, 0x67c699b0, 0x549, 0x800d0000}};
  // 2488597943.222471663849191
  s21_decimal dec_check = {{0x2ee48ee7, 0x2a31ebd8, 0x20efb, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_37) {
  // 80667.9325676870133880693091
  s21_decimal dec_1 = {{0xd35ba163, 0xdeb1c7da, 0x29b44fd, 0x160000}};
  // -261859163373
  s21_decimal dec_2 = {{0xf805bced, 0x3c, 0x0, 0x80000000}};
  // 261859244040.93256768701338807
  s21_decimal dec_check = {{0x17a814b7, 0x5f79f826, 0x549c7d2e, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_38) {
  // -31601730727339640332977
  s21_decimal dec_1 = {{0xc211a2b1, 0x221d075e, 0x6b1, 0x80000000}};
  // 4243784977208511
  s21_decimal dec_2 = {{0x3011d4bf, 0xf13b3, 0x0, 0x0}};
  // -31601734971124617541488
  s21_decimal dec_check = {{0xf2237770, 0x222c1b11, 0x6b1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_39) {
  // -2355.432
  s21_decimal dec_1 = {{0x23f0e8, 0x0, 0x0, 0x80030000}};
  // 576749
  s21_decimal dec_2 = {{0x8cced, 0x0, 0x0, 0x0}};
  // -579104.432
  s21_decimal dec_check = {{0x22846eb0, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_40) {
  // -609.16854476
  s21_decimal dec_1 = {{0x2eed6ecc, 0xe, 0x0, 0x80080000}};
  // 938225.932763408855
  s21_decimal dec_2 = {{0xd16c29d7, 0xd053f83, 0x0, 0xc0000}};
  // -938835.101308168855
  s21_decimal dec_check = {{0xec242a97, 0xd07698c, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_41) {
  // -6613288.693180592
  s21_decimal dec_1 = {{0x435aa8b0, 0x177ec0, 0x0, 0x80090000}};
  // -504755
  s21_decimal dec_2 = {{0x7b3b3, 0x0, 0x0, 0x80000000}};
  // -6108533.693180592
  s21_decimal dec_check = {{0xd4e16ab0, 0x15b3ad, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_42) {
  // 9789209806
  s21_decimal dec_1 = {{0x477b7cce, 0x2, 0x0, 0x0}};
  // -496924
  s21_decimal dec_2 = {{0x7951c, 0x0, 0x0, 0x80000000}};
  // 9789706730
  s21_decimal dec_check = {{0x478311ea, 0x2, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_43) {
  // -33091830277861076206273616
  s21_decimal dec_1 = {{0xd246c450, 0xb6c4b39d, 0x1b5f77, 0x80000000}};
  // -661322242023.5929114
  s21_decimal dec_2 = {{0xbacfc61a, 0x5bc6e2c0, 0x0, 0x80070000}};
  // -33091830277860414884031592.407
  s21_decimal dec_check = {{0x4f1d77d7, 0xf05b4705, 0x6aeceba1, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_44) {
  // -16418660742946485
  s21_decimal dec_1 = {{0x59455eb5, 0x3a54af, 0x0, 0x80000000}};
  // -5774548617685328455804
  s21_decimal dec_2 = {{0x3cf7e87c, 0x9f5dcea, 0x139, 0x80000000}};
  // 5774532199024585509319
  s21_decimal dec_check = {{0xe3b289c7, 0x9bb883a, 0x139, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_45) {
  // -275082179306
  s21_decimal dec_1 = {{0xc2cf2ea, 0x40, 0x0, 0x80000000}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -275082179304
  s21_decimal dec_check = {{0xc2cf2e8, 0x40, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_46) {
  // -615065461578743902631.1
  s21_decimal dec_1 = {{0x6f027087, 0x6d7ac97e, 0x14d, 0x80010000}};
  // -2963964553096224911718001
  s21_decimal dec_2 = {{0x16e8f671, 0xd72343c8, 0x273a4, 0x80000000}};
  // 2963349487634646167815369.9
  s21_decimal dec_check = {{0x76172fe3, 0xf9e5dc52, 0x188322, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_47) {
  // 49972303504218.449
  s21_decimal dec_1 = {{0x96fa1951, 0xb1898b, 0x0, 0x30000}};
  // -52059000604516
  s21_decimal dec_2 = {{0xee3d0764, 0x2f58, 0x0, 0x80000000}};
  // 102031304108734.449
  s21_decimal dec_check = {{0x355ef7f1, 0x16a7cee, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_48) {
  // -184615174911346815906994
  s21_decimal dec_1 = {{0x9a61b4b2, 0x23938c0, 0x2718, 0x80000000}};
  // 7.7
  s21_decimal dec_2 = {{0x4d, 0x0, 0x0, 0x10000}};
  // -184615174911346815907001.7
  s21_decimal dec_check = {{0x7d10f41, 0x163c3786, 0x186f0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_49) {
  // -77
  s21_decimal dec_1 = {{0x4d, 0x0, 0x0, 0x80000000}};
  // 8.048386052
  s21_decimal dec_2 = {{0xdfb8a004, 0x1, 0x0, 0x90000}};
  // -85.048386052
  s21_decimal dec_check = {{0xcd476204, 0x13, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_50) {
  // 1904004.81484941989213
  s21_decimal dec_1 = {{0x254e955d, 0x52566520, 0xa, 0xe0000}};
  // -606
  s21_decimal dec_2 = {{0x25e, 0x0, 0x0, 0x80000000}};
  // 1904610.81484941989213
  s21_decimal dec_check = {{0x26b2155d, 0x532db081, 0xa, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_51) {
  // 92225.741912966751543
  s21_decimal dec_1 = {{0xd3ce537, 0xffe3a7a3, 0x4, 0xf0000}};
  // -574417953081493
  s21_decimal dec_2 = {{0x1a0bc895, 0x20a6e, 0x0, 0x80000000}};
  // 574417953173718.74191296675154
  s21_decimal dec_check = {{0xf413bd52, 0xba659e75, 0xb99abd4b, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_52) {
  // 994264378.33
  s21_decimal dec_1 = {{0x26470ac9, 0x17, 0x0, 0x20000}};
  // 764.569
  s21_decimal dec_2 = {{0xbaa99, 0x0, 0x0, 0x30000}};
  // 994263613.761
  s21_decimal dec_check = {{0x7ebac141, 0xe7, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_53) {
  // 52181665928382226904
  s21_decimal dec_1 = {{0x953a1d8, 0xd42a84b1, 0x2, 0x0}};
  // 266536485181673
  s21_decimal dec_2 = {{0xdc84d8e9, 0xf269, 0x0, 0x0}};
  // 52181399391897045231
  s21_decimal dec_check = {{0x2ccec8ef, 0xd4299247, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_55) {
  // -8974
  s21_decimal dec_1 = {{0x230e, 0x0, 0x0, 0x80000000}};
  // -8.2482276790292
  s21_decimal dec_2 = {{0x66cef014, 0x4b04, 0x0, 0x800d0000}};
  // -8965.7517723209708
  s21_decimal dec_check = {{0x8f55cfec, 0x13e8709, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_56) {
  // -4692698095590
  s21_decimal dec_1 = {{0x9a9a5fe6, 0x444, 0x0, 0x80000000}};
  // 421765456.75
  s21_decimal dec_2 = {{0xd1eb038b, 0x9, 0x0, 0x20000}};
  // -4693119861046.75
  s21_decimal dec_check = {{0x36387963, 0x1aad6, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_58) {
  // 491935860897.442825
  s21_decimal dec_1 = {{0x21116c09, 0x6d3b50f, 0x0, 0x60000}};
  // -7744008042062.06
  s21_decimal dec_2 = {{0x3cd9367e, 0x2c050, 0x0, 0x80020000}};
  // 8235943902959.502825
  s21_decimal dec_check = {{0x5f205e9, 0x724bf358, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_59) {
  // -97351403948901482
  s21_decimal dec_1 = {{0xac2846a, 0x159dc96, 0x0, 0x80000000}};
  // -1869591118.316
  s21_decimal dec_2 = {{0x4c5081ec, 0x1b3, 0x0, 0x80030000}};
  // -97351402079310363.684
  s21_decimal dec_check = {{0xbb84bc24, 0x4705a866, 0x5, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_60) {
  // -0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80010000}};
  // 4423865538626986694
  s21_decimal dec_2 = {{0xcbf422c6, 0x3d64ba44, 0x0, 0x0}};
  // -4423865538626986694.3
  s21_decimal dec_check = {{0xf7895bbf, 0x65ef46af, 0x2, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_61) {
  // 86679598932066427455
  s21_decimal dec_1 = {{0x325e23f, 0xb2ebcbfb, 0x4, 0x0}};
  // 656799819852644094120077
  s21_decimal dec_2 = {{0xbe81108d, 0x30883964, 0x8b15, 0x0}};
  // -656713140253712027692622
  s21_decimal dec_check = {{0xbb5b2e4e, 0x7d9c6d69, 0x8b10, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_62) {
  // 20.596245
  s21_decimal dec_1 = {{0x13a4615, 0x0, 0x0, 0x60000}};
  // 5103272
  s21_decimal dec_2 = {{0x4ddea8, 0x0, 0x0, 0x0}};
  // -5103251.403755
  s21_decimal dec_check = {{0x317cb3eb, 0x4a4, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_63) {
  // -1180
  s21_decimal dec_1 = {{0x49c, 0x0, 0x0, 0x80000000}};
  // -38887778877
  s21_decimal dec_2 = {{0xde46a3d, 0x9, 0x0, 0x80000000}};
  // 38887777697
  s21_decimal dec_check = {{0xde465a1, 0x9, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_64) {
  // 1024510964591338912
  s21_decimal dec_1 = {{0x50f5a5a0, 0xe37cb4b, 0x0, 0x0}};
  // 897786152461318103949417
  s21_decimal dec_2 = {{0xd33ae069, 0x15b87cab, 0xbe1d, 0x0}};
  // -897785127950353512610505
  s21_decimal dec_check = {{0x82453ac9, 0x780b160, 0xbe1d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_65) {
  // -113195
  s21_decimal dec_1 = {{0x1ba2b, 0x0, 0x0, 0x80000000}};
  // 0.855
  s21_decimal dec_2 = {{0x357, 0x0, 0x0, 0x30000}};
  // -113195.855
  s21_decimal dec_check = {{0x6bf3b4f, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_66) {
  // -3085110969
  s21_decimal dec_1 = {{0xb7e30eb9, 0x0, 0x0, 0x80000000}};
  // 188583.56657
  s21_decimal dec_2 = {{0x640bafb1, 0x4, 0x0, 0x50000}};
  // -3085299552.56657
  s21_decimal dec_check = {{0x3a62b951, 0x1189b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_67) {
  // 508132267978417281927935958.6
  s21_decimal dec_1 = {{0xb825ae62, 0x6d1472c9, 0x106b2bee, 0x10000}};
  // 0.93515144
  s21_decimal dec_2 = {{0x592ed88, 0x0, 0x0, 0x80000}};
  // 508132267978417281927935957.66
  s21_decimal dec_check = {{0x3178cf76, 0x42cc7be1, 0xa42fb750, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_68) {
  // 349397
  s21_decimal dec_1 = {{0x554d5, 0x0, 0x0, 0x0}};
  // -8917.02961722111136763899
  s21_decimal dec_2 = {{0x20a0ffb, 0x507d897d, 0xbcd3, 0x80140000}};
  // 358314.02961722111136763899
  s21_decimal dec_check = {{0xae5a0ffb, 0x3f28b911, 0x1da398, 0x140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_69) {
  // -275927730530268420
  s21_decimal dec_1 = {{0x19efb504, 0x3d44acf, 0x0, 0x80000000}};
  // 1710617094955.1684177886
  s21_decimal dec_2 = {{0x3eadcfde, 0x53cf863d, 0x39f, 0xa0000}};
  // -275929441147363375.1684177886
  s21_decimal dec_check = {{0xd3115fde, 0xc5b82810, 0x8ea6f51, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_70) {
  // -7348423156336694530987064
  s21_decimal dec_1 = {{0xd59cd438, 0xd14921b8, 0x61416, 0x80000000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -7348423156336694530987056
  s21_decimal dec_check = {{0xd59cd430, 0xd14921b8, 0x61416, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_71) {
  // -3792111403370369542678692108
  s21_decimal dec_1 = {{0xdcc8c10c, 0x1791469f, 0xc40c2d3, 0x80000000}};
  // 4364944526887430
  s21_decimal dec_2 = {{0xd7fd4a06, 0xf81e4, 0x0, 0x0}};
  // -3792111403374734487205579538
  s21_decimal dec_check = {{0xb4c60b12, 0x17a0c884, 0xc40c2d3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_72) {
  // 2715748539345680716
  s21_decimal dec_1 = {{0x6afc394c, 0x25b046e8, 0x0, 0x0}};
  // 495444.1417458
  s21_decimal dec_2 = {{0x8bb882f2, 0x481, 0x0, 0x70000}};
  // 2715748539345185271.8582542
  s21_decimal dec_check = {{0xc116ab0e, 0x3baf2425, 0x1676d2, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_73) {
  // 8.13407506
  s21_decimal dec_1 = {{0x307b9d12, 0x0, 0x0, 0x80000}};
  // -833780359970219887.3276
  s21_decimal dec_2 = {{0x36d06cbc, 0xfe44e65a, 0x1c3, 0x80040000}};
  // 833780359970219895.46167506
  s21_decimal dec_check = {{0x5e130cd2, 0x636623fd, 0x44f7fc, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_74) {
  // -344761642234632710903.7
  s21_decimal dec_1 = {{0x8becadad, 0xe54a05de, 0xba, 0x80010000}};
  // 49366632655
  s21_decimal dec_2 = {{0x7e7b08cf, 0xb, 0x0, 0x0}};
  // -344761642283999343558.7
  s21_decimal dec_check = {{0x7cbb05c3, 0xe54a0651, 0xba, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_75) {
  // -36982748
  s21_decimal dec_1 = {{0x2344fdc, 0x0, 0x0, 0x80000000}};
  // 9504472359663978459439227515
  s21_decimal dec_2 = {{0x699ee27b, 0x8a77d9f, 0x1eb5ea4f, 0x0}};
  // -9504472359663978459476210263
  s21_decimal dec_check = {{0x6bd33257, 0x8a77d9f, 0x1eb5ea4f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_76) {
  // -30257901603
  s21_decimal dec_1 = {{0xb82f023, 0x7, 0x0, 0x80000000}};
  // 301686631272418849441204
  s21_decimal dec_2 = {{0xea1dc5b4, 0x770da1fc, 0x3fe2, 0x0}};
  // -301686631272449107342807
  s21_decimal dec_check = {{0xf5a0b5d7, 0x770da203, 0x3fe2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_77) {
  // 77581240481117685591.70
  s21_decimal dec_1 = {{0x6d7dde42, 0x91996d74, 0x1a4, 0x20000}};
  // -671071914823309353691314
  s21_decimal dec_2 = {{0xe46228b2, 0xe1a34069, 0x8e1a, 0x80000000}};
  // 671149496063790471376905.70
  s21_decimal dec_check = {{0xa3d5c3ca, 0xb55e96d1, 0x378424, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_78) {
  // 2315864502367238392
  s21_decimal dec_1 = {{0xb38938f8, 0x20239a7e, 0x0, 0x0}};
  // 35041
  s21_decimal dec_2 = {{0x88e1, 0x0, 0x0, 0x0}};
  // 2315864502367203351
  s21_decimal dec_check = {{0xb388b017, 0x20239a7e, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_80) {
  // -385180306232505421100590
  s21_decimal dec_1 = {{0xd93d762e, 0xaa8ec1bc, 0x5190, 0x80000000}};
  // 434245233987062900271926835
  s21_decimal dec_2 = {{0xc0d0ce33, 0x4dd3c336, 0x1673301, 0x0}};
  // -434630414293295405693027425
  s21_decimal dec_check = {{0x9a0e4461, 0xf86284f3, 0x1678491, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_81) {
  // 6408.23350
  s21_decimal dec_1 = {{0x26323036, 0x0, 0x0, 0x50000}};
  // 9.5
  s21_decimal dec_2 = {{0x5f, 0x0, 0x0, 0x10000}};
  // 6398.73350
  s21_decimal dec_check = {{0x2623b146, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_82) {
  // 13454340538619024704781345
  s21_decimal dec_1 = {{0x825bbc21, 0x4316caba, 0xb2111, 0x0}};
  // 719115079607868111
  s21_decimal dec_2 = {{0xd8a75acf, 0x9facf5a, 0x0, 0x0}};
  // 13454339819503945096913234
  s21_decimal dec_check = {{0xa9b46152, 0x391bfb5f, 0xb2111, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_83) {
  // 97.345
  s21_decimal dec_1 = {{0x17c41, 0x0, 0x0, 0x30000}};
  // 9.32271056279518257
  s21_decimal dec_2 = {{0x17eb3c31, 0xcf01796, 0x0, 0x110000}};
  // 88.02228943720481743
  s21_decimal dec_check = {{0x8e1f03cf, 0x7a27cc96, 0x0, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_84) {
  // -6472
  s21_decimal dec_1 = {{0x1948, 0x0, 0x0, 0x80000000}};
  // -49622754.757080197785615
  s21_decimal dec_2 = {{0x1a7e680f, 0xe0f9af1, 0xa82, 0x800f0000}};
  // 49616282.757080197785615
  s21_decimal dec_check = {{0x602a680f, 0xb43e713b, 0xa81, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_85) {
  // 0.7879617
  s21_decimal dec_1 = {{0x783bc1, 0x0, 0x0, 0x70000}};
  // -848221638679130703.4984
  s21_decimal dec_2 = {{0x5394168, 0xd2662f14, 0x1cb, 0x80040000}};
  // 848221638679130704.2863617
  s21_decimal dec_check = {{0x681fba01, 0xdf27e634, 0x7042d, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_86) {
  // 381483699176259686870302
  s21_decimal dec_1 = {{0xb7d1ad1e, 0x45d44d8b, 0x50c8, 0x0}};
  // -0.42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x80020000}};
  // 381483699176259686870302.42
  s21_decimal dec_check = {{0xcde79fe2, 0x46ee4a93, 0x1f8e3b, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_87) {
  // 7429459
  s21_decimal dec_1 = {{0x715d53, 0x0, 0x0, 0x0}};
  // 2.54843332841639051
  s21_decimal dec_2 = {{0x37670c8b, 0x38962a9, 0x0, 0x110000}};
  // 7429456.45156667158360949
  s21_decimal dec_check = {{0x3e56f375, 0x2a042742, 0x9d53, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_88) {
  // -21971634.3485075
  s21_decimal dec_1 = {{0xb29ad293, 0xc7d4, 0x0, 0x80070000}};
  // -757916
  s21_decimal dec_2 = {{0xb909c, 0x0, 0x0, 0x80000000}};
  // -21213718.3485075
  s21_decimal dec_check = {{0x9771c93, 0xc0f0, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_89) {
  // -7913291135117608282542080
  s21_decimal dec_1 = {{0x5ae0d000, 0x5f3c1025, 0x68bb4, 0x80000000}};
  // -58637724453573000954
  s21_decimal dec_2 = {{0xec747efa, 0x2dc30bb6, 0x3, 0x80000000}};
  // -7913232497393154709541126
  s21_decimal dec_check = {{0x6e6c5106, 0x3179046e, 0x68bb1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_90) {
  // -55883135
  s21_decimal dec_1 = {{0x354b57f, 0x0, 0x0, 0x80000000}};
  // -89806.75131262106925624
  s21_decimal dec_2 = {{0xe74fa38, 0xd7e7623a, 0x1e6, 0x80110000}};
  // -55793328.24868737893074376
  s21_decimal dec_check = {{0xeb0105c8, 0x3d0d7de6, 0x49d78, 0x80110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_91) {
  // 161087217373486975
  s21_decimal dec_1 = {{0x81671f7f, 0x23c4bf8, 0x0, 0x0}};
  // -50197263837712.9237347926330
  s21_decimal dec_2 = {{0x9a41813a, 0x40ba011b, 0x19f38d7, 0x800d0000}};
  // 161137414637324687.92373479263
  s21_decimal dec_check = {{0x1677075f, 0x17a925d8, 0x3410f97b, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_92) {
  // 5813925220
  s21_decimal dec_1 = {{0x5a897564, 0x1, 0x0, 0x0}};
  // -25201522607791
  s21_decimal dec_2 = {{0xafcd86af, 0x16eb, 0x0, 0x80000000}};
  // 25207336533011
  s21_decimal dec_check = {{0xa56fc13, 0x16ed, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_93) {
  // -20351826317063559.8150713971
  s21_decimal dec_1 = {{0x404b4273, 0x274c098c, 0xa858ab, 0x800a0000}};
  // 6.5503579225039722536581121358
  s21_decimal dec_2 = {{0xa442c54e, 0x1176f03a, 0xd3a74a71, 0x1c0000}};
  // -20351826317063566.365429319604
  s21_decimal dec_check = {{0x3d27c7b4, 0x59b3c0be, 0x41c2a2db, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_94) {
  // -7943033319259225237758616
  s21_decimal dec_1 = {{0xf1d42298, 0xb2f48019, 0x69200, 0x80000000}};
  // -57939698466778266375.833
  s21_decimal dec_2 = {{0x1b669699, 0xead749db, 0xc44, 0x80030000}};
  // -7942975379560758459492240.167
  s21_decimal dec_check = {{0x89408b27, 0x203d1b7d, 0x19aa4676, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_95) {
  // -525.58567859045928
  s21_decimal dec_1 = {{0x2f244628, 0xbab9bd, 0x0, 0x800e0000}};
  // 9108.9406270
  s21_decimal dec_2 = {{0x355a093e, 0x15, 0x0, 0x70000}};
  // -9634.52630559045928
  s21_decimal dec_check = {{0x1a633928, 0xd5edf10, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_96) {
  // 61388722481142
  s21_decimal dec_1 = {{0x2cff27f6, 0x37d5, 0x0, 0x0}};
  // 172958814.4132144
  s21_decimal dec_2 = {{0x1ef05030, 0x6250d, 0x0, 0x70000}};
  // 61388549522327.5867856
  s21_decimal dec_check = {{0x9c1dced0, 0x475f6566, 0x21, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_97) {
  // 0.15352
  s21_decimal dec_1 = {{0x3bf8, 0x0, 0x0, 0x50000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -3.84648
  s21_decimal dec_check = {{0x5de88, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_98) {
  // 4109549.682
  s21_decimal dec_1 = {{0xf4f2c072, 0x0, 0x0, 0x30000}};
  // 11444209885137055836488
  s21_decimal dec_2 = {{0x7028e948, 0x64510082, 0x26c, 0x0}};
  // -11444209885137051726938.318
  s21_decimal dec_check = {{0x2adc80ce, 0xdc69fd85, 0x97767, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_99) {
  // 42.3366771633211853055
  s21_decimal dec_1 = {{0x58448ff, 0xf364ebb5, 0x16, 0x130000}};
  // -8991
  s21_decimal dec_2 = {{0x231f, 0x0, 0x0, 0x80000000}};
  // 9033.3366771633211853055
  s21_decimal dec_check = {{0x709c48ff, 0xfb4bc81c, 0x1320, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_100) {
  // 36885.72782924799901926
  s21_decimal dec_1 = {{0x86bb80e6, 0xf53afb2c, 0xc7, 0x110000}};
  // -11.8609487
  s21_decimal dec_2 = {{0x711d64f, 0x0, 0x0, 0x80070000}};
  // 36897.58877794799901926
  s21_decimal dec_check = {{0x8afedce6, 0x5b0d62c, 0xc8, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_101) {
  // 25220843503132
  s21_decimal dec_1 = {{0x2f6afe1c, 0x16f0, 0x0, 0x0}};
  // -872686.61399525766376
  s21_decimal dec_2 = {{0x7693b4e8, 0xbb18912c, 0x4, 0x800e0000}};
  // 25220844375818.61399525766376
  s21_decimal dec_check = {{0xf72b4e8, 0x5226f27a, 0x8263827, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_102) {
  // -894904731131095.3
  s21_decimal dec_1 = {{0x7211a069, 0x1fcb1c, 0x0, 0x80010000}};
  // -63879.780
  s21_decimal dec_2 = {{0x3ceba64, 0x0, 0x0, 0x80030000}};
  // -894904731067215.520
  s21_decimal dec_check = {{0x8b13eea0, 0xc6b571c, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_103) {
  // 141999828140.83149
  s21_decimal dec_1 = {{0x2373384d, 0x3272cf, 0x0, 0x50000}};
  // -892787.19897537698
  s21_decimal dec_2 = {{0xd17e8ca2, 0x13d2e85, 0x0, 0x800b0000}};
  // 142000720928.03046537698
  s21_decimal dec_check = {{0xaf5379e2, 0xc9965d32, 0x301, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_104) {
  // -6221944288456339
  s21_decimal dec_1 = {{0x4b202e93, 0x161ad3, 0x0, 0x80000000}};
  // 256931
  s21_decimal dec_2 = {{0x3eba3, 0x0, 0x0, 0x0}};
  // -6221944288713270
  s21_decimal dec_check = {{0x4b241a36, 0x161ad3, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_105) {
  // 80582701328
  s21_decimal dec_1 = {{0xc31a7110, 0x12, 0x0, 0x0}};
  // -69759907187.726
  s21_decimal dec_2 = {{0x3e7ccc0e, 0x3f72, 0x0, 0x80030000}};
  // 150342608515.726
  s21_decimal dec_check = {{0x5dc6728e, 0x88bc, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_106) {
  // 749172
  s21_decimal dec_1 = {{0xb6e74, 0x0, 0x0, 0x0}};
  // -985746678093023385165619
  s21_decimal dec_2 = {{0x76931f33, 0x6f3b17de, 0xd0bd, 0x80000000}};
  // 985746678093023385914791
  s21_decimal dec_check = {{0x769e8da7, 0x6f3b17de, 0xd0bd, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_107) {
  // -6.1458488526358
  s21_decimal dec_1 = {{0x6b608616, 0x37e5, 0x0, 0x800d0000}};
  // -6971288720587536768768940
  s21_decimal dec_2 = {{0x7e0d1bac, 0x519c7fbd, 0x5c43a, 0x80000000}};
  // 6971288720587536768768933.8542
  s21_decimal dec_check = {{0xe007feae, 0xf13dda0b, 0xe1412613, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_108) {
  // -50332367934163795994805
  s21_decimal dec_1 = {{0xbeba68b5, 0x85ec0bce, 0xaa8, 0x80000000}};
  // 0.3798852322295852369
  s21_decimal dec_2 = {{0x589cad51, 0x34b83c0f, 0x0, 0x130000}};
  // -50332367934163795994805.379885
  s21_decimal dec_check = {{0xe039a32d, 0x72b6dc7, 0xa2a1f57d, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_109) {
  // -62920027435094
  s21_decimal dec_1 = {{0xb5e27056, 0x3939, 0x0, 0x80000000}};
  // -38.561919
  s21_decimal dec_2 = {{0x24c687f, 0x0, 0x0, 0x80060000}};
  // -62920027435055.438081
  s21_decimal dec_check = {{0x6c4fd901, 0x6930d796, 0x3, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_110) {
  // 66622246926272726549474520
  s21_decimal dec_1 = {{0x63f52cd8, 0x3e1f64cc, 0x371bcf, 0x0}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 66622246926272726549474515
  s21_decimal dec_check = {{0x63f52cd3, 0x3e1f64cc, 0x371bcf, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_111) {
  // -0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80010000}};
  // 35162572417.41333801
  s21_decimal dec_2 = {{0xd8e31529, 0x30cc4154, 0x0, 0x80000}};
  // -35162572417.71333801
  s21_decimal dec_check = {{0xdaacd8a9, 0x30cc4154, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_112) {
  // 48
  s21_decimal dec_1 = {{0x30, 0x0, 0x0, 0x0}};
  // 78.3032442
  s21_decimal dec_2 = {{0x2eac207a, 0x0, 0x0, 0x70000}};
  // -30.3032442
  s21_decimal dec_check = {{0x120fe87a, 0x0, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_113) {
  // -79371
  s21_decimal dec_1 = {{0x1360b, 0x0, 0x0, 0x80000000}};
  // -20.881571138
  s21_decimal dec_2 = {{0xdca37d42, 0x4, 0x0, 0x80090000}};
  // -79350.118428862
  s21_decimal dec_check = {{0x239f30be, 0x482b, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_114) {
  // -3638846487303
  s21_decimal dec_1 = {{0x3c26fb07, 0x34f, 0x0, 0x80000000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -3638846487300
  s21_decimal dec_check = {{0x3c26fb04, 0x34f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_115) {
  // 350669882643393034505848425
  s21_decimal dec_1 = {{0xf5568669, 0x6dea8c7d, 0x122113c, 0x0}};
  // 2728377360634
  s21_decimal dec_2 = {{0x3ff6a0fa, 0x27b, 0x0, 0x0}};
  // 350669882643390306128487791
  s21_decimal dec_check = {{0xb55fe56f, 0x6dea8a02, 0x122113c, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_117) {
  // -30817.17
  s21_decimal dec_1 = {{0x2f05f5, 0x0, 0x0, 0x80020000}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // -30823.17
  s21_decimal dec_check = {{0x2f084d, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_118) {
  // -206363.793
  s21_decimal dec_1 = {{0xc4cdc91, 0x0, 0x0, 0x80030000}};
  // 232821788398523579881
  s21_decimal dec_2 = {{0x7928fde9, 0x9f0d2701, 0xc, 0x0}};
  // -232821788398523786244.793
  s21_decimal dec_check = {{0x546cb2b9, 0x4b605dc1, 0x314d, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_119) {
  // -3486348009758082222398369899
  s21_decimal dec_1 = {{0xaa9bf06b, 0x4f9e70e5, 0xb43d6e8, 0x80000000}};
  // -51927626355921892
  s21_decimal dec_2 = {{0xaaf953e4, 0xb87be6, 0x0, 0x80000000}};
  // -3486348009706154596042448007
  s21_decimal dec_check = {{0xffa29c87, 0x4ee5f4fe, 0xb43d6e8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_120) {
  // 363154156055005171918830
  s21_decimal dec_1 = {{0xabb9a7ee, 0xa051bad8, 0x4ce6, 0x0}};
  // 2.7049226
  s21_decimal dec_2 = {{0x19cbd0a, 0x0, 0x0, 0x70000}};
  // 363154156055005171918827.29508
  s21_decimal dec_check = {{0x29d96824, 0xb5badd08, 0x75576860, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_121) {
  // 84949718
  s21_decimal dec_1 = {{0x5103ad6, 0x0, 0x0, 0x0}};
  // -5213359136045
  s21_decimal dec_2 = {{0xd46b5d2d, 0x4bd, 0x0, 0x80000000}};
  // 5213444085763
  s21_decimal dec_check = {{0xd97b9803, 0x4bd, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_122) {
  // -36
  s21_decimal dec_1 = {{0x24, 0x0, 0x0, 0x80000000}};
  // 6425342351554169087.7846235018
  s21_decimal dec_2 = {{0x75a4278a, 0x4252bc6a, 0xcf9d2fac, 0xa0000}};
  // -6425342351554169123.7846235018
  s21_decimal dec_check = {{0x4750378a, 0x4252bcbe, 0xcf9d2fac, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_123) {
  // 2584.46901
  s21_decimal dec_1 = {{0xf679635, 0x0, 0x0, 0x50000}};
  // -866
  s21_decimal dec_2 = {{0x362, 0x0, 0x0, 0x80000000}};
  // 3450.46901
  s21_decimal dec_check = {{0x1490ff75, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_124) {
  // -66764266248770842036
  s21_decimal dec_1 = {{0xc7966db4, 0x9e8a526b, 0x3, 0x80000000}};
  // 701474
  s21_decimal dec_2 = {{0xab422, 0x0, 0x0, 0x0}};
  // -66764266248771543510
  s21_decimal dec_check = {{0xc7a121d6, 0x9e8a526b, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_125) {
  // -13.662
  s21_decimal dec_1 = {{0x355e, 0x0, 0x0, 0x80030000}};
  // 71867552809447870056758890202
  s21_decimal dec_2 = {{0x35a9ceda, 0x5c6ad182, 0xe8377244, 0x0}};
  // -71867552809447870056758890216
  s21_decimal dec_check = {{0x35a9cee8, 0x5c6ad182, 0xe8377244, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_126) {
  // -28055164500.1551335
  s21_decimal dec_1 = {{0x15780de7, 0x3e4b83c, 0x0, 0x80070000}};
  // 985587.51416279311894140
  s21_decimal dec_2 = {{0xc0cc67c, 0xe1705276, 0x14de, 0x110000}};
  // -28056150087.66929629311894140
  s21_decimal dec_check = {{0x5d5b827c, 0x6216421b, 0x910c016, 0x80110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_127) {
  // 5933
  s21_decimal dec_1 = {{0x172d, 0x0, 0x0, 0x0}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // 5939
  s21_decimal dec_check = {{0x1733, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_128) {
  // -80348720534247256904
  s21_decimal dec_1 = {{0xc0f13348, 0x5b0fff9e, 0x4, 0x80000000}};
  // -29806376739905622168528134846
  s21_decimal dec_2 = {{0xc682a2be, 0xc42fc8da, 0x604f41c8, 0x80000000}};
  // 29806376659556901634280877942
  s21_decimal dec_check = {{0x5916f76, 0x691fc93c, 0x604f41c4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_129) {
  // -29774156676548740599823.120
  s21_decimal dec_1 = {{0x1260bb10, 0x44838623, 0x18a0ec, 0x80030000}};
  // 7954252.375
  s21_decimal dec_2 = {{0xda1c4257, 0x1, 0x0, 0x30000}};
  // -29774156676548748554075.495
  s21_decimal dec_check = {{0xec7cfd67, 0x44838624, 0x18a0ec, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_130) {
  // -9875429052416750
  s21_decimal dec_1 = {{0x80ac82ee, 0x2315a6, 0x0, 0x80000000}};
  // 1327328001
  s21_decimal dec_2 = {{0x4f1d6b01, 0x0, 0x0, 0x0}};
  // -9875430379744751
  s21_decimal dec_check = {{0xcfc9edef, 0x2315a6, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_131) {
  // -7.537
  s21_decimal dec_1 = {{0x1d71, 0x0, 0x0, 0x80030000}};
  // -654166.04312542027818368880
  s21_decimal dec_2 = {{0x166e7f70, 0x39c1d910, 0x361c81, 0x80140000}};
  // 654158.50612542027818368880
  s21_decimal dec_check = {{0x2a847f70, 0x5e118c56, 0x361c58, 0x140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_132) {
  // -6289263433341469
  s21_decimal dec_1 = {{0x40d7da1d, 0x16580d, 0x0, 0x80000000}};
  // -9643997365587458.75322001391
  s21_decimal dec_2 = {{0x492857ef, 0x79dfdb23, 0x31dbb96, 0x800b0000}};
  // 3354733932245989.75322001391
  s21_decimal dec_check = {{0xfa200fef, 0x1656a6ed, 0x1157f41, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_133) {
  // -16.88538757292236003726898
  s21_decimal dec_1 = {{0x7551d632, 0xde943788, 0x1658f, 0x80170000}};
  // -5531838441411151521
  s21_decimal dec_2 = {{0xe72986a1, 0x4cc509c0, 0x0, 0x80000000}};
  // 5531838441411151504.1146124271
  s21_decimal dec_check = {{0x4858b7ef, 0x22669f1, 0xb2be4b8c, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_134) {
  // 3190
  s21_decimal dec_1 = {{0xc76, 0x0, 0x0, 0x0}};
  // 21543235042004
  s21_decimal dec_2 = {{0xecdf3ad4, 0x1397, 0x0, 0x0}};
  // -21543235038814
  s21_decimal dec_check = {{0xecdf2e5e, 0x1397, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_135) {
  // -237110.4210474
  s21_decimal dec_1 = {{0x10d2fe2a, 0x228, 0x0, 0x80070000}};
  // 45.68223
  s21_decimal dec_2 = {{0x45b49f, 0x0, 0x0, 0x50000}};
  // -237156.1032774
  s21_decimal dec_check = {{0x2c0d8c46, 0x228, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_136) {
  // -8294633045
  s21_decimal dec_1 = {{0xee660e55, 0x1, 0x0, 0x80000000}};
  // -41593223969627461233
  s21_decimal dec_2 = {{0x7ce85671, 0x4138d0d4, 0x2, 0x80000000}};
  // 41593223961332828188
  s21_decimal dec_check = {{0x8e82481c, 0x4138d0d2, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_137) {
  // -145418.491
  s21_decimal dec_1 = {{0x8aae8fb, 0x0, 0x0, 0x80030000}};
  // 65901067449259831054
  s21_decimal dec_2 = {{0xb030af0e, 0x928f9faf, 0x3, 0x0}};
  // -65901067449259976472.491
  s21_decimal dec_check = {{0x46d6b7ab, 0x8107c648, 0xdf4, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_138) {
  // 4.95284679
  s21_decimal dec_1 = {{0x1d8571c7, 0x0, 0x0, 0x80000}};
  // 548914006176414524248312035.2
  s21_decimal dec_2 = {{0x5a56d8e0, 0x894e2a, 0x11bc829f, 0x10000}};
  // -548914006176414524248312030.25
  s21_decimal dec_check = {{0x876476d1, 0x55d0da7, 0xb15d1a36, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_139) {
  // -462637914875845161491380169
  s21_decimal dec_1 = {{0xd61837c9, 0x9e7f2827, 0x17eaf63, 0x80000000}};
  // 385
  s21_decimal dec_2 = {{0x181, 0x0, 0x0, 0x0}};
  // -462637914875845161491380554
  s21_decimal dec_check = {{0xd618394a, 0x9e7f2827, 0x17eaf63, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_140) {
  // -25947800781.1
  s21_decimal dec_1 = {{0x6a183003, 0x3c, 0x0, 0x80010000}};
  // 729
  s21_decimal dec_2 = {{0x2d9, 0x0, 0x0, 0x0}};
  // -25947801510.1
  s21_decimal dec_check = {{0x6a184c7d, 0x3c, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_141) {
  // 453321574830
  s21_decimal dec_1 = {{0x8c1249ae, 0x69, 0x0, 0x0}};
  // 87269739
  s21_decimal dec_2 = {{0x533a16b, 0x0, 0x0, 0x0}};
  // 453234305091
  s21_decimal dec_check = {{0x86dea843, 0x69, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_142) {
  // 8712727.4054266
  s21_decimal dec_1 = {{0xe638627a, 0x4f3d, 0x0, 0x70000}};
  // 57828.6851005427639849
  s21_decimal dec_2 = {{0x29c26629, 0x59579b18, 0x1f, 0x100000}};
  // 8654898.7203260572360151
  s21_decimal dec_check = {{0xaf55ddd7, 0xd47ab92d, 0x1253, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_143) {
  // -0.53997942
  s21_decimal dec_1 = {{0x337f176, 0x0, 0x0, 0x80080000}};
  // 78.029758651
  s21_decimal dec_2 = {{0x2aefa0bb, 0x12, 0x0, 0x90000}};
  // -78.569738071
  s21_decimal dec_check = {{0x4b1f0f57, 0x12, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_144) {
  // 5309912413.8199219
  s21_decimal dec_1 = {{0x402448b3, 0xbca55f, 0x0, 0x70000}};
  // 66343284.75
  s21_decimal dec_2 = {{0x8b6fd19b, 0x1, 0x0, 0x20000}};
  // 5243569129.0699219
  s21_decimal dec_check = {{0xc0ef25d3, 0xba49fb, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_145) {
  // 7627697360130878933753940.92
  s21_decimal dec_1 = {{0xdb9fa12c, 0x3e9cbe92, 0x276f2c6, 0x20000}};
  // 38
  s21_decimal dec_2 = {{0x26, 0x0, 0x0, 0x0}};
  // 7627697360130878933753902.92
  s21_decimal dec_check = {{0xdb9f9254, 0x3e9cbe92, 0x276f2c6, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_146) {
  // -474
  s21_decimal dec_1 = {{0x1da, 0x0, 0x0, 0x80000000}};
  // -127095
  s21_decimal dec_2 = {{0x1f077, 0x0, 0x0, 0x80000000}};
  // 126621
  s21_decimal dec_check = {{0x1ee9d, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_147) {
  // -461717913092186001047
  s21_decimal dec_1 = {{0xc66d4e97, 0x79f8bab, 0x19, 0x80000000}};
  // 0.3793691211918372840
  s21_decimal dec_2 = {{0xb1ea6fe8, 0x34a5e60e, 0x0, 0x130000}};
  // -461717913092186001047.37936912
  s21_decimal dec_check = {{0x3dd89610, 0x4007028b, 0x9530691e, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_148) {
  // 7.0429638747569
  s21_decimal dec_1 = {{0x2d9965b1, 0x400e, 0x0, 0xd0000}};
  // -1375688554913
  s21_decimal dec_2 = {{0x4d6d79a1, 0x140, 0x0, 0x80000000}};
  // 1375688554920.0429638747569
  s21_decimal dec_check = {{0xd15005b1, 0x428c5659, 0xb6122, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_149) {
  // -0.924
  s21_decimal dec_1 = {{0x39c, 0x0, 0x0, 0x80030000}};
  // -94294813432890
  s21_decimal dec_2 = {{0xb8dbdc3a, 0x55c2, 0x0, 0x80000000}};
  // 94294813432889.076
  s21_decimal dec_check = {{0x1ad43ef4, 0x14f00a2, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_150) {
  // 57.350
  s21_decimal dec_1 = {{0xe006, 0x0, 0x0, 0x30000}};
  // -575281224651568
  s21_decimal dec_2 = {{0x190a9330, 0x20b37, 0x0, 0x80000000}};
  // 575281224651625.350
  s21_decimal dec_check = {{0xd14fd386, 0x7fbcf39, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_151) {
  // -89571606078
  s21_decimal dec_1 = {{0xdae23e3e, 0x14, 0x0, 0x80000000}};
  // 437046760225442331
  s21_decimal dec_2 = {{0x7d790a1b, 0x610b3b6, 0x0, 0x0}};
  // -437046849797048409
  s21_decimal dec_check = {{0x585b4859, 0x610b3cb, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_152) {
  // -63.281
  s21_decimal dec_1 = {{0xf731, 0x0, 0x0, 0x80030000}};
  // -19.05201366542076555364930
  s21_decimal dec_2 = {{0xae750a42, 0x2c4bc88f, 0x19371, 0x80170000}};
  // -44.22898633457923444635070
  s21_decimal dec_check = {{0xb79af5be, 0xd0bb08b4, 0x3a895, 0x80170000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_153) {
  // -66363
  s21_decimal dec_1 = {{0x1033b, 0x0, 0x0, 0x80000000}};
  // 12427963.6
  s21_decimal dec_2 = {{0x7685b54, 0x0, 0x0, 0x10000}};
  // -12494326.6
  s21_decimal dec_check = {{0x7727ba2, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_154) {
  // 5092585554918
  s21_decimal dec_1 = {{0xb5c0c3e6, 0x4a1, 0x0, 0x0}};
  // 392348341212695242.970202
  s21_decimal dec_2 = {{0xe5bf945a, 0x3f06ae57, 0x5315, 0x60000}};
  // -392343248627140324.970202
  s21_decimal dec_check = {{0x48934eda, 0xf85a2ec3, 0x5314, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_155) {
  // 64913270.90
  s21_decimal dec_1 = {{0x82e9ca72, 0x1, 0x0, 0x20000}};
  // 9648.07324082901058277609975
  s21_decimal dec_2 = {{0xab1411f7, 0xd70c3b05, 0x31e11e5, 0x170000}};
  // 64903622.826759170989417223900
  s21_decimal dec_check = {{0x466d6dc, 0x8c2fbdd8, 0xd1b704bb, 0x150000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_156) {
  // -0.68
  s21_decimal dec_1 = {{0x44, 0x0, 0x0, 0x80020000}};
  // 3580360424
  s21_decimal dec_2 = {{0xd567f6e8, 0x0, 0x0, 0x0}};
  // -3580360424.68
  s21_decimal dec_check = {{0x5c9c72e4, 0x53, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_157) {
  // -1442.6413934594
  s21_decimal dec_1 = {{0xe9472802, 0xd1e, 0x0, 0x800a0000}};
  // 443212.2535326966443534493246
  s21_decimal dec_2 = {{0xba94a63e, 0x138011f1, 0xe522a74, 0x160000}};
  // -444654.8949261560443534493246
  s21_decimal dec_check = {{0x9e5ec63e, 0x8ae98a54, 0xe5e195d, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_158) {
  // 620695996544
  s21_decimal dec_1 = {{0x845d4880, 0x90, 0x0, 0x0}};
  // -42429908884.0085272595756
  s21_decimal dec_2 = {{0x77490d2c, 0x4cb8d323, 0x59d9, 0x800d0000}};
  // 663125905428.0085272595756
  s21_decimal dec_check = {{0xd990d2c, 0x460dcf7f, 0x57c39, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_159) {
  // -588030929096842.50244408466
  s21_decimal dec_1 = {{0x7365e492, 0xdd80311, 0x30a40a, 0x800b0000}};
  // -38963314518526626163.45
  s21_decimal dec_2 = {{0xabf9b119, 0x38760bcf, 0xd3, 0x80020000}};
  // 38962726487597529320.947555915
  s21_decimal dec_check = {{0xa0f19e4b, 0x30ca56aa, 0x7de53643, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_160) {
  // -82011331.01
  s21_decimal dec_1 = {{0xe8d35c2d, 0x1, 0x0, 0x80020000}};
  // -43.625733
  s21_decimal dec_2 = {{0x299ad05, 0x0, 0x0, 0x80060000}};
  // -82011287.384267
  s21_decimal dec_check = {{0xbda6f0cb, 0x4a96, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_161) {
  // -23287616909361315888
  s21_decimal dec_1 = {{0x2bdc8030, 0x432e3c32, 0x1, 0x80000000}};
  // -7010026228386
  s21_decimal dec_2 = {{0x261f8aa2, 0x660, 0x0, 0x80000000}};
  // -23287609899335087502
  s21_decimal dec_check = {{0x5bcf58e, 0x432e35d2, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_162) {
  // -8938854372243.459
  s21_decimal dec_1 = {{0x378e7803, 0x1fc1d7, 0x0, 0x80030000}};
  // 63
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x0}};
  // -8938854372306.459
  s21_decimal dec_check = {{0x378f6e1b, 0x1fc1d7, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_163) {
  // 4654402600
  s21_decimal dec_1 = {{0x156c8c28, 0x1, 0x0, 0x0}};
  // 624.727425850698863009908
  s21_decimal dec_2 = {{0x5410e074, 0x8aa75773, 0x844a, 0x150000}};
  // 4654401975.2725741493011369901
  s21_decimal dec_check = {{0xfd544fad, 0x9b0d735d, 0x96644f8e, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_164) {
  // -32
  s21_decimal dec_1 = {{0x20, 0x0, 0x0, 0x80000000}};
  // -108449291641909245
  s21_decimal dec_2 = {{0x60756ffd, 0x1814a0e, 0x0, 0x80000000}};
  // 108449291641909213
  s21_decimal dec_check = {{0x60756fdd, 0x1814a0e, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_165) {
  // -25863342.415461163026635
  s21_decimal dec_1 = {{0x3ff548cb, 0xdfa6100, 0x57a, 0x800f0000}};
  // -87745529.4335155
  s21_decimal dec_2 = {{0x7b2008b3, 0x31e0a, 0x0, 0x80070000}};
  // 61882187.018054336973365
  s21_decimal dec_check = {{0xb9ff0a35, 0xa3dc4b0a, 0xd1a, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_166) {
  // -13886757
  s21_decimal dec_1 = {{0xd3e525, 0x0, 0x0, 0x80000000}};
  // 284383967534821159069173515
  s21_decimal dec_2 = {{0xacca470b, 0xc5648446, 0xeb3ca5, 0x0}};
  // -284383967534821159083060272
  s21_decimal dec_check = {{0xad9e2c30, 0xc5648446, 0xeb3ca5, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_168) {
  // 2415461.9344096318800081979
  s21_decimal dec_1 = {{0x25a5343b, 0x89d5fd7c, 0x13faf0, 0x130000}};
  // -42130688511633157072
  s21_decimal dec_2 = {{0xbe866bd0, 0x48ae45fb, 0x2, 0x80000000}};
  // 42130688511635572533.934409632
  s21_decimal dec_check = {{0x6ac3c7a0, 0xa19ad0e5, 0x8821b050, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_169) {
  // -784795961.94826030978378848899
  s21_decimal dec_1 = {{0x75055a83, 0x82c22eca, 0xfd94ccea, 0x80140000}};
  // 494860601.90686
  s21_decimal dec_2 = {{0xdf09fbde, 0x2d01, 0x0, 0x50000}};
  // -1279656563.8551203097837884890
  s21_decimal dec_check = {{0xc10d5da, 0x48955377, 0x2959122d, 0x80130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_170) {
  // -79228162514264337592625175622
  s21_decimal dec_1 = {{0xc93c9c46, 0xffffffff, 0xffffffff, 0x80000000}};
  // 7398
  s21_decimal dec_2 = {{0x1ce6, 0x0, 0x0, 0x0}};
  // -79228162514264337592625183020
  s21_decimal dec_check = {{0xc93cb92c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_171) {
  // 6843290146
  s21_decimal dec_1 = {{0x97e45222, 0x1, 0x0, 0x0}};
  // 9.479411335174839784781781
  s21_decimal dec_2 = {{0xa2f137d5, 0xeb0d73c1, 0x7d757, 0x180000}};
  // 6843290136.5205886648251602152
  s21_decimal dec_check = {{0x57bc54e8, 0x7b6c6d8c, 0xdd1e5e88, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_172) {
  // 7408036.4357
  s21_decimal dec_1 = {{0x3f88a745, 0x11, 0x0, 0x40000}};
  // 25.20582648
  s21_decimal dec_2 = {{0x963d09f8, 0x0, 0x0, 0x80000}};
  // 7408011.22987352
  s21_decimal dec_check = {{0x33c8ed58, 0x2a1c1, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_173) {
  // -76380492516510
  s21_decimal dec_1 = {{0xb81fcc9e, 0x4577, 0x0, 0x80000000}};
  // -5813085370
  s21_decimal dec_2 = {{0x5a7ca4ba, 0x1, 0x0, 0x80000000}};
  // -76374679431140
  s21_decimal dec_check = {{0x5da327e4, 0x4576, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_174) {
  // -5553920230.157821543014
  s21_decimal dec_1 = {{0xe4b20266, 0x14205f65, 0x12d, 0x800c0000}};
  // 313182523533
  s21_decimal dec_2 = {{0xeb22108d, 0x48, 0x0, 0x0}};
  // -318736443763.157821543014
  s21_decimal dec_check = {{0x749bd266, 0xbcbbb089, 0x437e, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_175) {
  // 4857245738590836439581458.1
  s21_decimal dec_1 = {{0x4eae1eb5, 0x30e7defe, 0x282d9e, 0x10000}};
  // 2843879780.036
  s21_decimal dec_2 = {{0x2471aec4, 0x296, 0x0, 0x30000}};
  // 4857245738590833595701678.064
  s21_decimal dec_check = {{0x97924ff0, 0x1a9318c0, 0xfb1d1cb, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_176) {
  // 31045.9120924677
  s21_decimal dec_1 = {{0x659eb805, 0x11a5c, 0x0, 0xa0000}};
  // -9569665.57744859
  s21_decimal dec_2 = {{0x23bc7edb, 0x3665b, 0x0, 0x80080000}};
  // 9600711.4895410577
  s21_decimal dec_check = {{0x5b404591, 0x15515f6, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_177) {
  // 6813582167898
  s21_decimal dec_1 = {{0x69250f5a, 0x632, 0x0, 0x0}};
  // -6409
  s21_decimal dec_2 = {{0x1909, 0x0, 0x0, 0x80000000}};
  // 6813582174307
  s21_decimal dec_check = {{0x69252863, 0x632, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_179) {
  // 274754676544045046492
  s21_decimal dec_1 = {{0xa927dadc, 0xe4fcb29a, 0xe, 0x0}};
  // -40311096434914
  s21_decimal dec_2 = {{0xa89560e2, 0x24a9, 0x0, 0x80000000}};
  // 274754716855141481406
  s21_decimal dec_check = {{0x51bd3bbe, 0xe4fcd744, 0xe, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_180) {
  // -97368436822.90935842833
  s21_decimal dec_1 = {{0xe9a4c811, 0xd5d9bd08, 0x20f, 0x800b0000}};
  // 72720728189728.1828525087432
  s21_decimal dec_2 = {{0xa3ca9ac8, 0xbe77ce17, 0x2598821, 0xd0000}};
  // -72818096626551.0922109370732
  s21_decimal dec_check = {{0xe828c16c, 0x4785a592, 0x25a5651, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_181) {
  // -135842
  s21_decimal dec_1 = {{0x212a2, 0x0, 0x0, 0x80000000}};
  // 1489473922612852391.315
  s21_decimal dec_2 = {{0x9abb7d93, 0xbe9a610b, 0x50, 0x30000}};
  // -1489473922612988233.315
  s21_decimal dec_check = {{0xa2d44663, 0xbe9a610b, 0x50, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_183) {
  // 8609713930125
  s21_decimal dec_1 = {{0x9af0bf8d, 0x7d4, 0x0, 0x0}};
  // -10.705254354
  s21_decimal dec_2 = {{0x7e1537d2, 0x2, 0x0, 0x80090000}};
  // 8609713930135.705254354
  s21_decimal dec_check = {{0x2f0c79d2, 0xbbc8733d, 0x1d2, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_184) {
  // 6.100167
  s21_decimal dec_1 = {{0x5d14c7, 0x0, 0x0, 0x60000}};
  // 19.2871
  s21_decimal dec_2 = {{0x2f167, 0x0, 0x0, 0x40000}};
  // -13.186933
  s21_decimal dec_check = {{0xc93775, 0x0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_185) {
  // -59870.8
  s21_decimal dec_1 = {{0x922b4, 0x0, 0x0, 0x80010000}};
  // 514722015686
  s21_decimal dec_2 = {{0xd7d2a9c6, 0x77, 0x0, 0x0}};
  // -514722075556.8
  s21_decimal dec_check = {{0x6e43c470, 0x4ae, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_186) {
  // -3319458006057453019183
  s21_decimal dec_1 = {{0x58f2e02f, 0xf2bbdd44, 0xb3, 0x80000000}};
  // -12922181291972006
  s21_decimal dec_2 = {{0xc9a195a6, 0x2de8a7, 0x0, 0x80000000}};
  // -3319445083876161047177
  s21_decimal dec_check = {{0x8f514a89, 0xf28df49c, 0xb3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_187) {
  // -38
  s21_decimal dec_1 = {{0x26, 0x0, 0x0, 0x80000000}};
  // 16836609271006825.62121464
  s21_decimal dec_2 = {{0xcad32ef8, 0x71162c2a, 0x16487, 0x80000}};
  // -16836609271006863.62121464
  s21_decimal dec_check = {{0xad5294f8, 0x71162c2b, 0x16487, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_188) {
  // -507326954516
  s21_decimal dec_1 = {{0x1f0afc14, 0x76, 0x0, 0x80000000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -507326954520
  s21_decimal dec_check = {{0x1f0afc18, 0x76, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_189) {
  // 4154301335254
  s21_decimal dec_1 = {{0x3fa7c6d6, 0x3c7, 0x0, 0x0}};
  // -493683332747333104487434.68
  s21_decimal dec_2 = {{0x1557b42c, 0xb59cba1a, 0x28d626, 0x80020000}};
  // 493683332751487405822688.68
  s21_decimal dec_check = {{0xf2e15fc4, 0xb59e33ee, 0x28d626, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_190) {
  // 3798713823804
  s21_decimal dec_1 = {{0x74fcf23c, 0x374, 0x0, 0x0}};
  // -605957.02574
  s21_decimal dec_2 = {{0x1bc90b2e, 0xe, 0x0, 0x80050000}};
  // 3798714429761.02574
  s21_decimal dec_check = {{0x92e7d8ae, 0x5459310, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_191) {
  // 47097
  s21_decimal dec_1 = {{0xb7f9, 0x0, 0x0, 0x0}};
  // -817188.145
  s21_decimal dec_2 = {{0x30b54d31, 0x0, 0x0, 0x80030000}};
  // 864285.145
  s21_decimal dec_check = {{0x3383f1d9, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_192) {
  // 5059235597378968606.079
  s21_decimal dec_1 = {{0x509bd57f, 0x42ff82d6, 0x112, 0x30000}};
  // -6098838118809
  s21_decimal dec_2 = {{0xff146199, 0x58b, 0x0, 0x80000000}};
  // 5059241696217087415.079
  s21_decimal dec_check = {{0xb8391327, 0x43152db2, 0x112, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_193) {
  // 5718163
  s21_decimal dec_1 = {{0x574093, 0x0, 0x0, 0x0}};
  // -9764.0701374948168468860907
  s21_decimal dec_2 = {{0x54990feb, 0x7167407, 0x50c439, 0x80160000}};
  // 5727927.0701374948168468860907
  s21_decimal dec_check = {{0xaf590feb, 0xa40b8a8b, 0xb9144d5e, 0x160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_194) {
  // -398432808751036177
  s21_decimal dec_1 = {{0x50777711, 0x5878487, 0x0, 0x80000000}};
  // 13989779917840665
  s21_decimal dec_2 = {{0x767d2119, 0x31b3a1, 0x0, 0x0}};
  // -412422588668876842
  s21_decimal dec_check = {{0xc6f4982a, 0x5b93828, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_195) {
  // 1084837.98964631502096
  s21_decimal dec_1 = {{0xf3bffd10, 0xe183e062, 0x5, 0xe0000}};
  // -82723
  s21_decimal dec_2 = {{0x14323, 0x0, 0x0, 0x80000000}};
  // 1167560.98964631502096
  s21_decimal dec_check = {{0x7336bd10, 0x5450fd68, 0x6, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_196) {
  // -165825
  s21_decimal dec_1 = {{0x287c1, 0x0, 0x0, 0x80000000}};
  // 0.160026
  s21_decimal dec_2 = {{0x2711a, 0x0, 0x0, 0x60000}};
  // -165825.160026
  s21_decimal dec_check = {{0x9bf3235a, 0x26, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_197) {
  // -614530.5
  s21_decimal dec_1 = {{0x5dc519, 0x0, 0x0, 0x80010000}};
  // 5659383637491636666048382
  s21_decimal dec_2 = {{0xc03f1f7e, 0xcd3e7f0b, 0x4ae6b, 0x0}};
  // -5659383637491636666662912.5
  s21_decimal dec_check = {{0x82d50005, 0x470f675, 0x2ed036, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_198) {
  // 0.1048
  s21_decimal dec_1 = {{0x418, 0x0, 0x0, 0x40000}};
  // -855781074194640
  s21_decimal dec_2 = {{0xeeed0d0, 0x30a54, 0x0, 0x80000000}};
  // 855781074194640.1048
  s21_decimal dec_check = {{0x50bcc118, 0x76c37387, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_199) {
  // -975
  s21_decimal dec_1 = {{0x3cf, 0x0, 0x0, 0x80000000}};
  // -21312391699480
  s21_decimal dec_2 = {{0x2d895c18, 0x1362, 0x0, 0x80000000}};
  // 21312391698505
  s21_decimal dec_check = {{0x2d895849, 0x1362, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_200) {
  // 67941215614140374646190021
  s21_decimal dec_1 = {{0xc31eefc5, 0xadb2b0d0, 0x38331c, 0x0}};
  // 584745113
  s21_decimal dec_2 = {{0x22da8099, 0x0, 0x0, 0x0}};
  // 67941215614140374061444908
  s21_decimal dec_check = {{0xa0446f2c, 0xadb2b0d0, 0x38331c, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_201) {
  // 68.1778
  s21_decimal dec_1 = {{0xa6732, 0x0, 0x0, 0x40000}};
  // 32042156020796789382997555
  s21_decimal dec_2 = {{0x82d46633, 0xc2295836, 0x1a8130, 0x0}};
  // -32042156020796789382997486.822
  s21_decimal dec_check = {{0xdae2ce6, 0x718094ef, 0x6788a676, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_202) {
  // -9670.825
  s21_decimal dec_1 = {{0x9390a9, 0x0, 0x0, 0x80030000}};
  // 96185103685437
  s21_decimal dec_2 = {{0xd6f0173d, 0x577a, 0x0, 0x0}};
  // -96185103695107.825
  s21_decimal dec_check = {{0x9a6e56f1, 0x155b7d7, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_203) {
  // 797923977
  s21_decimal dec_1 = {{0x2f8f5a89, 0x0, 0x0, 0x0}};
  // -86628928510510343.038
  s21_decimal dec_2 = {{0x25ada37e, 0xb237c780, 0x4, 0x80030000}};
  // 86628929308434320.038
  s21_decimal dec_check = {{0xeda74aa6, 0xb237c839, 0x4, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_204) {
  // -9533606173644
  s21_decimal dec_1 = {{0xb7359bcc, 0x8ab, 0x0, 0x80000000}};
  // 42054698763.5685
  s21_decimal dec_2 = {{0x39cf33e5, 0x17e7c, 0x0, 0x40000}};
  // -9575660872407.5685
  s21_decimal dec_check = {{0xd7e504a5, 0x1543220, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_205) {
  // -8.052404314
  s21_decimal dec_1 = {{0xdff5f05a, 0x1, 0x0, 0x80090000}};
  // -318
  s21_decimal dec_2 = {{0x13e, 0x0, 0x0, 0x80000000}};
  // 309.947595686
  s21_decimal dec_check = {{0x2a50fba6, 0x48, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_206) {
  // 40575479189094651822392
  s21_decimal dec_1 = {{0x19928138, 0x99e3f061, 0x897, 0x0}};
  // -6541801092326919143.385851
  s21_decimal dec_2 = {{0xc36afb, 0xbf70b3b0, 0x56947, 0x80060000}};
  // 40582020990186978741535.385851
  s21_decimal dec_check = {{0xbcfc28fb, 0x12165423, 0x8320a936, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_207) {
  // -453696126826013230364
  s21_decimal dec_1 = {{0x2b17851c, 0x984c6f90, 0x18, 0x80000000}};
  // -32.05685386
  s21_decimal dec_2 = {{0xbf12e08a, 0x0, 0x0, 0x80080000}};
  // -453696126826013230331.94314614
  s21_decimal dec_check = {{0xdcb6bb76, 0xc3de68fa, 0x9298dd2f, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_208) {
  // -0.7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80010000}};
  // 53941035839537
  s21_decimal dec_2 = {{0x2047b031, 0x310f, 0x0, 0x0}};
  // -53941035839537.7
  s21_decimal dec_check = {{0x42cce1f1, 0x1ea97, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_209) {
  // -0.46
  s21_decimal dec_1 = {{0x2e, 0x0, 0x0, 0x80020000}};
  // 45178259358036293022
  s21_decimal dec_2 = {{0x7e38759e, 0x72f96b85, 0x2, 0x0}};
  // -45178259358036293022.46
  s21_decimal dec_check = {{0x4e0df1e6, 0xe96e0025, 0xf4, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_210) {
  // -59.94980
  s21_decimal dec_1 = {{0x5b79e4, 0x0, 0x0, 0x80050000}};
  // -834348.1438075692536452350
  s21_decimal dec_2 = {{0x49a254fe, 0x8f9de9d, 0x6e6cd, 0x80130000}};
  // 834288.1940075692536452350
  s21_decimal dec_check = {{0x148154fe, 0x89451fe4, 0x6e6ac, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_211) {
  // -9096.83084906979
  s21_decimal dec_1 = {{0x192251e3, 0x33b5a, 0x0, 0x800b0000}};
  // -76466291726219059618486170374
  s21_decimal dec_2 = {{0xaff83306, 0x92e8059c, 0xf7136f1c, 0x80000000}};
  // 76466291726219059618486161277
  s21_decimal dec_check = {{0xaff80f7d, 0x92e8059c, 0xf7136f1c, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_212) {
  // 326222823353
  s21_decimal dec_1 = {{0xf4653fb9, 0x4b, 0x0, 0x0}};
  // -857882835686
  s21_decimal dec_2 = {{0xbdcd3ae6, 0xc7, 0x0, 0x80000000}};
  // 1184105659039
  s21_decimal dec_check = {{0xb2327a9f, 0x113, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_213) {
  // 9753301856165426425045383
  s21_decimal dec_1 = {{0x9d3d2187, 0x8d95de85, 0x81157, 0x0}};
  // 485.213
  s21_decimal dec_2 = {{0x7675d, 0x0, 0x0, 0x30000}};
  // 9753301856165426425044897.787
  s21_decimal dec_check = {{0x36c38ffb, 0x116d39ee, 0x1f83be01, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_214) {
  // 10137143105.404671820
  s21_decimal dec_1 = {{0xaf2174c, 0x8cae5df2, 0x0, 0x90000}};
  // -904
  s21_decimal dec_2 = {{0x388, 0x0, 0x0, 0x80000000}};
  // 10137144009.404671820
  s21_decimal dec_check = {{0x858b674c, 0x8cae5ec4, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_215) {
  // -91725073295609332
  s21_decimal dec_1 = {{0xdac80df4, 0x145df77, 0x0, 0x80000000}};
  // 234838198.4540
  s21_decimal dec_2 = {{0xc679571c, 0x222, 0x0, 0x40000}};
  // -91725073530447530.4540
  s21_decimal dec_check = {{0xed1a625c, 0xb9693bf4, 0x31, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_216) {
  // 63042301242008956721094.61788
  s21_decimal dec_1 = {{0x5d2f711c, 0xd34ab3f4, 0x145ebca7, 0x50000}};
  // 2648946902904213355
  s21_decimal dec_2 = {{0x687a0f6b, 0x24c2f32c, 0x0, 0x0}};
  // 63039652295106052507739.61788
  s21_decimal dec_check = {{0x1d68cc3c, 0xdafd1109, 0x145e848f, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_217) {
  // 6608796264
  s21_decimal dec_1 = {{0x89ea3a68, 0x1, 0x0, 0x0}};
  // -5.7
  s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80010000}};
  // 6608796269.7
  s21_decimal dec_check = {{0x63264849, 0xf, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_218) {
  // 1801445134443417478.98044
  s21_decimal dec_1 = {{0x429156bc, 0xa7551317, 0x2625, 0x50000}};
  // -7661
  s21_decimal dec_2 = {{0x1ded, 0x0, 0x0, 0x80000000}};
  // 1801445134443425139.98044
  s21_decimal dec_check = {{0x703b18dc, 0xa7551317, 0x2625, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_221) {
  // 817990040483376126
  s21_decimal dec_1 = {{0xa0d1abfe, 0xb5a159b, 0x0, 0x0}};
  // 12365
  s21_decimal dec_2 = {{0x304d, 0x0, 0x0, 0x0}};
  // 817990040483363761
  s21_decimal dec_check = {{0xa0d17bb1, 0xb5a159b, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_222) {
  // 46893.631185723706385077271451
  s21_decimal dec_1 = {{0x74da7b9b, 0x5d625d87, 0x978580a8, 0x180000}};
  // 183174815414680403.3663475446
  s21_decimal dec_2 = {{0x5ac31ef6, 0x689aeb51, 0x5eb2fc2, 0xa0000}};
  // -183174815414633509.73516182089
  s21_decimal dec_check = {{0x1cb77249, 0x15fc883a, 0x3b2fdd98, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_223) {
  // -789055121570818359956059
  s21_decimal dec_1 = {{0xfd02125b, 0xc38bbb73, 0xa716, 0x80000000}};
  // 47361430277006676926918336.26
  s21_decimal dec_2 = {{0x6369431a, 0xfde3c82a, 0xf4da54b, 0x20000}};
  // -48150485398577495286874395.26
  s21_decimal dec_check = {{0x38386ea6, 0x60790179, 0xf8eea30, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_224) {
  // -9981004219525208741825
  s21_decimal dec_1 = {{0xb0417c1, 0x12423808, 0x21d, 0x80000000}};
  // 631230955
  s21_decimal dec_2 = {{0x259fd1eb, 0x0, 0x0, 0x0}};
  // -9981004219525839972780
  s21_decimal dec_check = {{0x30a3e9ac, 0x12423808, 0x21d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_225) {
  // -23273757
  s21_decimal dec_1 = {{0x163211d, 0x0, 0x0, 0x80000000}};
  // -214
  s21_decimal dec_2 = {{0xd6, 0x0, 0x0, 0x80000000}};
  // -23273543
  s21_decimal dec_check = {{0x1632047, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_226) {
  // -54222206211956889785501297558
  s21_decimal dec_1 = {{0x542d2b96, 0x9918bc67, 0xaf338ec8, 0x80000000}};
  // 58615089.6283954044
  s21_decimal dec_2 = {{0x75c82b7c, 0x8226d22, 0x0, 0xa0000}};
  // -54222206211956889785559912648
  s21_decimal dec_check = {{0x57ab90c8, 0x9918bc67, 0xaf338ec8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_227) {
  // -0.103637
  s21_decimal dec_1 = {{0x194d5, 0x0, 0x0, 0x80060000}};
  // -9354378553.753857423753
  s21_decimal dec_2 = {{0x76f7f989, 0x1a14a504, 0x1fb, 0x800c0000}};
  // 9354378553.650220423753
  s21_decimal dec_check = {{0x55b8da49, 0x1a14a4ec, 0x1fb, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_228) {
  // -46812274478
  s21_decimal dec_1 = {{0xe63a9f2e, 0xa, 0x0, 0x80000000}};
  // 4617389417513789866218361.93
  s21_decimal dec_2 = {{0x161d9ba1, 0x303afdea, 0x17df106, 0x20000}};
  // -4617389417513836678492839.93
  s21_decimal dec_check = {{0x503c999, 0x303b022c, 0x17df106, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_229) {
  // -371392011270159827915210
  s21_decimal dec_1 = {{0x841ad1ca, 0x3386a300, 0x4ea5, 0x80000000}};
  // 72277
  s21_decimal dec_2 = {{0x11a55, 0x0, 0x0, 0x0}};
  // -371392011270159827987487
  s21_decimal dec_check = {{0x841bec1f, 0x3386a300, 0x4ea5, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_230) {
  // -296781215624
  s21_decimal dec_1 = {{0x1989f788, 0x45, 0x0, 0x80000000}};
  // -2890521648.354
  s21_decimal dec_2 = {{0x841ce2, 0x2a1, 0x0, 0x80030000}};
  // -293890693975.646
  s21_decimal dec_check = {{0xc26ace5e, 0x10b4a, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_231) {
  // -770875.8
  s21_decimal dec_1 = {{0x75a056, 0x0, 0x0, 0x80010000}};
  // -1909408.416
  s21_decimal dec_2 = {{0x71cf42a0, 0x0, 0x0, 0x80030000}};
  // 1138532.616
  s21_decimal dec_check = {{0x43dca108, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_232) {
  // -631073630640637659.8739
  s21_decimal dec_1 = {{0x70c3ecd3, 0x1b0f32f6, 0x156, 0x80040000}};
  // 530507.283228947660724808
  s21_decimal dec_2 = {{0x99b8da48, 0xdb81d4ad, 0x7056, 0x120000}};
  // -631073630641168167.15712894766
  s21_decimal dec_check = {{0x4c5172e, 0xb2854efb, 0xcbe92fee, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_233) {
  // 54546
  s21_decimal dec_1 = {{0xd512, 0x0, 0x0, 0x0}};
  // 46972527960923
  s21_decimal dec_2 = {{0xa4d7e35b, 0x2ab8, 0x0, 0x0}};
  // -46972527906377
  s21_decimal dec_check = {{0xa4d70e49, 0x2ab8, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_234) {
  // -116668243543427329372348352
  s21_decimal dec_1 = {{0xa1e65fc0, 0x27ce5ccc, 0x608176, 0x80000000}};
  // -396739062258310.40406304720
  s21_decimal dec_2 = {{0xb034b7d0, 0xc41bf552, 0x20d146, 0x800b0000}};
  // -116668243543030590310090041.60
  s21_decimal dec_check = {{0x1e8c0a80, 0x8c0f4cba, 0x25b29227, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_235) {
  // -729821620807340207044143
  s21_decimal dec_1 = {{0x6452f62f, 0xb597539b, 0x9a8b, 0x80000000}};
  // -88394466.16646110470
  s21_decimal dec_2 = {{0x4c384d06, 0x7aac05dd, 0x0, 0x800b0000}};
  // -729821620807340118649676.83354
  s21_decimal dec_check = {{0xfed21d1a, 0x7f2f3ea, 0xebd16df6, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_236) {
  // 79549579823713.6104651
  s21_decimal dec_1 = {{0x804f2ccb, 0x1fb8cdc7, 0x2b, 0x70000}};
  // -3617647603253114972
  s21_decimal dec_2 = {{0xfa71f85c, 0x32347753, 0x0, 0x80000000}};
  // 3617727152832938685.6104651
  s21_decimal dec_check = {{0xf77142cb, 0xd1bc602e, 0x1decd5, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_237) {
  // -79228162514264337593144698587
  s21_decimal dec_1 = {{0xe833e6db, 0xffffffff, 0xffffffff, 0x80000000}};
  // -690160145520674459
  s21_decimal dec_2 = {{0xe7e4469b, 0x993f0fe, 0x0, 0x80000000}};
  // -79228162513574177447624024128
  s21_decimal dec_check = {{0x4fa040, 0xf66c0f01, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_238) {
  // 3664203377662278497.1140307520
  s21_decimal dec_1 = {{0x2c051a40, 0x3ebdbf35, 0x76659477, 0xa0000}};
  // -26214434285431075964
  s21_decimal dec_2 = {{0xb2f0b47c, 0x6bcc6117, 0x1, 0x80000000}};
  // 29878637663093354461.114030752
  s21_decimal dec_check = {{0x33025aa0, 0x42fb97e9, 0x608b07a1, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_239) {
  // 6.47393
  s21_decimal dec_1 = {{0x9e0e1, 0x0, 0x0, 0x50000}};
  // -905391.31268154001
  s21_decimal dec_2 = {{0x3582c291, 0x141a8dc, 0x0, 0x800b0000}};
  // 905397.78661154001
  s21_decimal dec_check = {{0xf123fcd1, 0x141a972, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_240) {
  // -7490431919561476075678732401
  s21_decimal dec_1 = {{0x52121071, 0x8df314, 0x1833f0a8, 0x80000000}};
  // -7435054608
  s21_decimal dec_2 = {{0xbb29ee10, 0x1, 0x0, 0x80000000}};
  // -7490431919561476068243677793
  s21_decimal dec_check = {{0x96e82261, 0x8df312, 0x1833f0a8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_241) {
  // 85900730169905135567
  s21_decimal dec_1 = {{0xcbe03fcf, 0xa81cb2f7, 0x4, 0x0}};
  // -98174626723
  s21_decimal dec_2 = {{0xdba9eba3, 0x16, 0x0, 0x80000000}};
  // 85900730268079762290
  s21_decimal dec_check = {{0xa78a2b72, 0xa81cb30e, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_242) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // 0.0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x10000}};
  // 3.0
  s21_decimal dec_check = {{0x1e, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_244) {
  // 4.95850671
  s21_decimal dec_1 = {{0x1d8e14af, 0x0, 0x0, 0x80000}};
  // -558287933729446297343
  s21_decimal dec_2 = {{0x6a77feff, 0x43cd2dca, 0x1e, 0x80000000}};
  // 558287933729446297347.95850671
  s21_decimal dec_check = {{0x99b733af, 0x1c0b2465, 0xb4647ed9, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_245) {
  // 774391043405030384720247748
  s21_decimal dec_1 = {{0x16a97bc4, 0x94a5a4d6, 0x2808fae, 0x0}};
  // 60590888172722912647
  s21_decimal dec_2 = {{0xd090fd87, 0x48de13c4, 0x3, 0x0}};
  // 774390982814142211997335101
  s21_decimal dec_check = {{0x46187e3d, 0x4bc79111, 0x2808fab, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_246) {
  // 285413157849578917757275597
  s21_decimal dec_1 = {{0x4f094dcd, 0x4a31d878, 0xec1696, 0x0}};
  // 8587.7760
  s21_decimal dec_2 = {{0x51e6400, 0x0, 0x0, 0x40000}};
  // 285413157849578917757267009.22
  s21_decimal dec_check = {{0xdf95497a, 0xfb788efe, 0x5c38d2b4, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_247) {
  // -2878741617500385.64449
  s21_decimal dec_1 = {{0x94644e61, 0x9b0e78e3, 0xf, 0x80050000}};
  // -19807525944378258376359178410
  s21_decimal dec_2 = {{0xca1470aa, 0x5dc72db, 0x400066c5, 0x80000000}};
  // 19807525944375379634741678024
  s21_decimal dec_check = {{0x86918fc8, 0x5d238a8, 0x400066c5, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_248) {
  // 4161163885693
  s21_decimal dec_1 = {{0xd8b1fc7d, 0x3c8, 0x0, 0x0}};
  // -831946664272356771720209
  s21_decimal dec_2 = {{0x9c656c11, 0xeb46315e, 0xb02b, 0x80000000}};
  // 831946664276517935605902
  s21_decimal dec_check = {{0x7517688e, 0xeb463527, 0xb02b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_249) {
  // 4647105813051
  s21_decimal dec_1 = {{0xfd175a3b, 0x439, 0x0, 0x0}};
  // -378643198729737050
  s21_decimal dec_2 = {{0xace7535a, 0x54135fb, 0x0, 0x80000000}};
  // 378647845835550101
  s21_decimal dec_check = {{0xa9fead95, 0x5413a35, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_250) {
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // 3386636.8659765220431376
  s21_decimal dec_2 = {{0x5fd95610, 0xe6473058, 0x72b, 0x100000}};
  // -3386630.8659765220431376
  s21_decimal dec_check = {{0xc1535610, 0xe57206a9, 0x72b, 0x80100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_251) {
  // 3583
  s21_decimal dec_1 = {{0xdff, 0x0, 0x0, 0x0}};
  // 726839911938672613054542
  s21_decimal dec_2 = {{0x1086d84e, 0x12117153, 0x99ea, 0x0}};
  // -726839911938672613050959
  s21_decimal dec_check = {{0x1086ca4f, 0x12117153, 0x99ea, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_253) {
  // 505006407613577
  s21_decimal dec_1 = {{0xf788fc89, 0x1cb4c, 0x0, 0x0}};
  // -59781446754429176892360609662
  s21_decimal dec_2 = {{0x9b3dcf7e, 0x462058f6, 0xc12a0dc2, 0x80000000}};
  // 59781446754429681898768223239
  s21_decimal dec_check = {{0x92c6cc07, 0x46222443, 0xc12a0dc2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_254) {
  // -405725950226
  s21_decimal dec_1 = {{0x7726b112, 0x5e, 0x0, 0x80000000}};
  // 13246.929
  s21_decimal dec_2 = {{0xca21d1, 0x0, 0x0, 0x30000}};
  // -405725963472.929
  s21_decimal dec_check = {{0x6fedd021, 0x17101, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_255) {
  // -746.2
  s21_decimal dec_1 = {{0x1d26, 0x0, 0x0, 0x80010000}};
  // -9224510721405063282285
  s21_decimal dec_2 = {{0xc31c3e6d, 0xfcd6b90, 0x1f4, 0x80000000}};
  // 9224510721405063281538.8
  s21_decimal dec_check = {{0x9f1a531c, 0x9e0633a7, 0x1388, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_256) {
  // 21796621995675845201746179967
  s21_decimal dec_1 = {{0x9d07b77f, 0x72172c1, 0x466dbe3e, 0x0}};
  // -0.67700536
  s21_decimal dec_2 = {{0x4090738, 0x0, 0x0, 0x80080000}};
  // 21796621995675845201746179968
  s21_decimal dec_check = {{0x9d07b780, 0x72172c1, 0x466dbe3e, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_257) {
  // 7322106652846996653
  s21_decimal dec_1 = {{0xe2783cad, 0x659d5934, 0x0, 0x0}};
  // 38
  s21_decimal dec_2 = {{0x26, 0x0, 0x0, 0x0}};
  // 7322106652846996615
  s21_decimal dec_check = {{0xe2783c87, 0x659d5934, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_258) {
  // -528975370960193.4
  s21_decimal dec_1 = {{0xc2cf648e, 0x12cb00, 0x0, 0x80010000}};
  // 5052809468349331.6439927989610
  s21_decimal dec_2 = {{0xf250a56a, 0x5ead92a8, 0xa343dc3d, 0xd0000}};
  // -5581784839309525.0439927989610
  s21_decimal dec_check = {{0x501f856a, 0x90220e77, 0xb45b7128, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_259) {
  // -60407
  s21_decimal dec_1 = {{0xebf7, 0x0, 0x0, 0x80000000}};
  // -79228162514264337592656242896
  s21_decimal dec_2 = {{0xcb16a8d0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 79228162514264337592656182489
  s21_decimal dec_check = {{0xcb15bcd9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_260) {
  // -5004376130264442242683526746
  s21_decimal dec_1 = {{0x9a8a5e5a, 0x9e4d3392, 0x102b85dd, 0x80000000}};
  // -62830502.05472
  s21_decimal dec_2 = {{0xe2f9c120, 0x5b6, 0x0, 0x80050000}};
  // -5004376130264442242620696243.9
  s21_decimal dec_check = {{0xe3f48307, 0x2f0403b9, 0xa1b33aa8, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_261) {
  // -84619956155768
  s21_decimal dec_1 = {{0x1e6d7578, 0x4cf6, 0x0, 0x80000000}};
  // 114.013320201
  s21_decimal dec_2 = {{0x8bb93409, 0x1a, 0x0, 0x90000}};
  // -84619956155882.013320201
  s21_decimal dec_check = {{0x3c99e409, 0x41cbbc08, 0x11eb, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_262) {
  // -9908570630835517811910089202
  s21_decimal dec_1 = {{0xc2c199f2, 0x357a40b0, 0x20042d72, 0x80000000}};
  // -99945594158
  s21_decimal dec_2 = {{0x4538bd2e, 0x17, 0x0, 0x80000000}};
  // -9908570630835517711964495044
  s21_decimal dec_check = {{0x7d88dcc4, 0x357a4099, 0x20042d72, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_263) {
  // -4974421093
  s21_decimal dec_1 = {{0x287fa465, 0x1, 0x0, 0x80000000}};
  // 50314747741.469872078310624
  s21_decimal dec_2 = {{0x83edcce0, 0xf0c28441, 0x299e8f, 0xf0000}};
  // -55289168834.469872078310624
  s21_decimal dec_check = {{0x303e4ce0, 0xd927bb41, 0x2dbbef, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_264) {
  // 177625645653892351609342744
  s21_decimal dec_1 = {{0xaf990b18, 0x8b9c5aa6, 0x92edb1, 0x0}};
  // 510960.66841475
  s21_decimal dec_2 = {{0xbae9db83, 0x2e78, 0x0, 0x80000}};
  // 177625645653892351608831783.33
  s21_decimal dec_check = {{0x94bcab5d, 0x8913691c, 0x3964d95a, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_265) {
  // -597686483006803.1500698
  s21_decimal dec_1 = {{0xea78319a, 0x1a97028, 0x144, 0x80070000}};
  // -7656865543652031405
  s21_decimal dec_2 = {{0xe64ebbad, 0x6a42a6a4, 0x0, 0x80000000}};
  // 7656267857169024601.8499302
  s21_decimal dec_check = {{0xcd9502e6, 0x1f373ffb, 0x3f54c7, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_267) {
  // -293.2
  s21_decimal dec_1 = {{0xb74, 0x0, 0x0, 0x80010000}};
  // -921363892259
  s21_decimal dec_2 = {{0x85914823, 0xd6, 0x0, 0x80000000}};
  // 921363891965.8
  s21_decimal dec_check = {{0x37acc5ea, 0x861, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_268) {
  // -71618672795
  s21_decimal dec_1 = {{0xacce389b, 0x10, 0x0, 0x80000000}};
  // -739816176668905613064303969
  s21_decimal dec_2 = {{0xe4b67561, 0x4c99824c, 0x263f62b, 0x80000000}};
  // 739816176668905541445631174
  s21_decimal dec_check = {{0x37e83cc6, 0x4c99823c, 0x263f62b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_269) {
  // 90412316932
  s21_decimal dec_1 = {{0xcfe7904, 0x15, 0x0, 0x0}};
  // 4.6894
  s21_decimal dec_2 = {{0xb72e, 0x0, 0x0, 0x40000}};
  // 90412316927.3106
  s21_decimal dec_check = {{0x94567512, 0x3364b, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_270) {
  // -2916462319123395
  s21_decimal dec_1 = {{0xcc883bc3, 0xa5c81, 0x0, 0x80000000}};
  // 0.33
  s21_decimal dec_2 = {{0x21, 0x0, 0x0, 0x20000}};
  // -2916462319123395.33
  s21_decimal dec_check = {{0xe537584d, 0x40c22b3, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_271) {
  // 93757.143383324229
  s21_decimal dec_1 = {{0xa84b645, 0x14d17a0, 0x0, 0xc0000}};
  // 8441662909982
  s21_decimal dec_2 = {{0x7a51ae1e, 0x7ad, 0x0, 0x0}};
  // -8441662816224.856616675771
  s21_decimal dec_check = {{0x21b329bb, 0x754f060b, 0x6fb97, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_272) {
  // 17666880710149202575812
  s21_decimal dec_1 = {{0x2c1501c4, 0xb938c2bc, 0x3bd, 0x0}};
  // -148252488123654821
  s21_decimal dec_2 = {{0x3bada2a5, 0x20eb2da, 0x0, 0x80000000}};
  // 17667028962637326230633
  s21_decimal dec_check = {{0x67c2a469, 0xbb477596, 0x3bd, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_273) {
  // -47489
  s21_decimal dec_1 = {{0xb981, 0x0, 0x0, 0x80000000}};
  // 231664577987588649678
  s21_decimal dec_2 = {{0xa6fff2ce, 0x8efdea44, 0xc, 0x0}};
  // -231664577987588697167
  s21_decimal dec_check = {{0xa700ac4f, 0x8efdea44, 0xc, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_274) {
  // 1559641172
  s21_decimal dec_1 = {{0x5cf63c54, 0x0, 0x0, 0x0}};
  // 521060861597332835068828
  s21_decimal dec_2 = {{0xe21eeb9c, 0xc4127c02, 0x6e56, 0x0}};
  // -521060861597331275427656
  s21_decimal dec_check = {{0x8528af48, 0xc4127c02, 0x6e56, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_275) {
  // 4633133.57186
  s21_decimal dec_1 = {{0xdfa0c982, 0x6b, 0x0, 0x50000}};
  // 7793988981914675155693011302
  s21_decimal dec_2 = {{0xf0a90166, 0x5374a80e, 0x192f095d, 0x0}};
  // -7793988981914675155688378168.4
  s21_decimal dec_check = {{0x63d71834, 0x428e9095, 0xfbd65da5, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_276) {
  // -955490125283576622559
  s21_decimal dec_1 = {{0xb111addf, 0xcc16d68a, 0x33, 0x80000000}};
  // 582135968542437107436
  s21_decimal dec_2 = {{0xcdef66ec, 0x8ec26b19, 0x1f, 0x0}};
  // -1537626093826013729995
  s21_decimal dec_check = {{0x7f0114cb, 0x5ad941a4, 0x53, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_277) {
  // 137524462939795
  s21_decimal dec_1 = {{0xe8c2ee93, 0x7d13, 0x0, 0x0}};
  // 189108415702141557375309129
  s21_decimal dec_2 = {{0xe1011549, 0xc1c94a2c, 0x9c6d43, 0x0}};
  // -189108415702004032912369334
  s21_decimal dec_check = {{0xf83e26b6, 0xc1c8cd18, 0x9c6d43, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_278) {
  // -87202982714342.2738001663761
  s21_decimal dec_1 = {{0xc7799711, 0xa72e796c, 0x2d1537f, 0x800d0000}};
  // 19021844964951612089
  s21_decimal dec_2 = {{0xac7e5ab9, 0x7fb2b36, 0x1, 0x0}};
  // -19021932167934326431.273800166
  s21_decimal dec_check = {{0x7e1151e6, 0x113b8c84, 0x3d7692d1, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_279) {
  // -273995091960902
  s21_decimal dec_1 = {{0x74206446, 0xf932, 0x0, 0x80000000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -273995091960898
  s21_decimal dec_check = {{0x74206442, 0xf932, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_280) {
  // 226.85493
  s21_decimal dec_1 = {{0x15a2735, 0x0, 0x0, 0x50000}};
  // -641223
  s21_decimal dec_2 = {{0x9c8c7, 0x0, 0x0, 0x80000000}};
  // 641449.85493
  s21_decimal dec_check = {{0xef56cd95, 0xe, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_281) {
  // -6741425921237364477331
  s21_decimal dec_1 = {{0x939b8d93, 0x741415c2, 0x16d, 0x80000000}};
  // -3060
  s21_decimal dec_2 = {{0xbf4, 0x0, 0x0, 0x80000000}};
  // -6741425921237364474271
  s21_decimal dec_check = {{0x939b819f, 0x741415c2, 0x16d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_282) {
  // -510087800230111278156290.9127
  s21_decimal dec_1 = {{0x1eb11c7, 0x957bbc87, 0x107b58ee, 0x80040000}};
  // -29436753719762196.3832566
  s21_decimal dec_2 = {{0xbb72bcf6, 0xb237ff2e, 0x3e55, 0x80070000}};
  // -510087770793357558394094.52944
  s21_decimal dec_check = {{0xcebf7790, 0x43219ab8, 0xa4d178b2, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_283) {
  // -2053335718397
  s21_decimal dec_1 = {{0x145899fd, 0x1de, 0x0, 0x80000000}};
  // -345211850427.029115892157901
  s21_decimal dec_2 = {{0x2a684dcd, 0xe8f8238e, 0x11d8d73, 0x800f0000}};
  // -1708123867969.970884107842099
  s21_decimal dec_check = {{0x50443233, 0x6d268951, 0x584ed4c, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_284) {
  // 48745833803058.513136799442091
  s21_decimal dec_1 = {{0xcbebe4ab, 0x71d5d2b7, 0x9d819bd1, 0xf0000}};
  // -41
  s21_decimal dec_2 = {{0x29, 0x0, 0x0, 0x80000000}};
  // 48745833803099.513136799442091
  s21_decimal dec_check = {{0x2fb664ab, 0x72677c00, 0x9d819bd1, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_285) {
  // 669978268020133.196269045890
  s21_decimal dec_1 = {{0x84bf4882, 0xaf6e3206, 0x22a316a, 0xc0000}};
  // 7788920869693743364
  s21_decimal dec_2 = {{0x75b8e104, 0x6c17ce43, 0x0, 0x0}};
  // -7788250891425723230.8037309541
  s21_decimal dec_check = {{0xbbd95465, 0x2c479e83, 0xfba6e6c4, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_286) {
  // 4794346002662674.21416
  s21_decimal dec_1 = {{0xee44eae8, 0xfd7ddcc9, 0x19, 0x50000}};
  // 523.9229248942886800383275
  s21_decimal dec_2 = {{0x49ecdd2b, 0x2fcb1750, 0x45573, 0x160000}};
  // 4794346002662150.2912351057113
  s21_decimal dec_check = {{0xcc3634d9, 0xdde33de8, 0x9ae9e68f, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_287) {
  // 0.516150
  s21_decimal dec_1 = {{0x7e036, 0x0, 0x0, 0x60000}};
  // 21720405296357511659169
  s21_decimal dec_2 = {{0xd69dfea1, 0x772d0165, 0x499, 0x0}};
  // -21720405296357511659168.483850
  s21_decimal dec_check = {{0x4e8c4a0a, 0x7a942e0c, 0x462eb2ba, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_288) {
  // 536.072701776552427046
  s21_decimal dec_1 = {{0xe7527e26, 0xf80d207, 0x1d, 0x120000}};
  // 3990338353039257987047928
  s21_decimal dec_2 = {{0x7fdde1f8, 0xacf1e284, 0x34cfc, 0x0}};
  // -3990338353039257987047391.9273
  s21_decimal dec_check = {{0xcaf91b29, 0xa8a057c2, 0x80ef4e23, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_289) {
  // 529.53277311
  s21_decimal dec_1 = {{0x5442e37f, 0xc, 0x0, 0x80000}};
  // 15418944553005896
  s21_decimal dec_2 = {{0xc8e4b348, 0x36c772, 0x0, 0x0}};
  // -15418944553005366.46722689
  s21_decimal dec_check = {{0xa9376481, 0x44129ce4, 0x14682, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_290) {
  // -535921365
  s21_decimal dec_1 = {{0x1ff182d5, 0x0, 0x0, 0x80000000}};
  // -1527687626
  s21_decimal dec_2 = {{0x5b0ea9ca, 0x0, 0x0, 0x80000000}};
  // 991766261
  s21_decimal dec_check = {{0x3b1d26f5, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_291) {
  // 72076998551.624272991489009623
  s21_decimal dec_1 = {{0xa48ea7d7, 0xcb9772b6, 0xe8e4b220, 0x120000}};
  // -6333.1254
  s21_decimal dec_2 = {{0x3c65bb6, 0x0, 0x0, 0x80040000}};
  // 72077004884.749672991489009623
  s21_decimal dec_check = {{0x503827d7, 0x1d5cafad, 0xe8e4b378, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_292) {
  // 2.6138739
  s21_decimal dec_1 = {{0x18ed873, 0x0, 0x0, 0x70000}};
  // -993138.466
  s21_decimal dec_2 = {{0x3b321722, 0x0, 0x0, 0x80030000}};
  // 993141.0798739
  s21_decimal dec_check = {{0x56367893, 0x908, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_293) {
  // 4446948211603893348998262333
  s21_decimal dec_1 = {{0xa32f2e3d, 0x98fa938e, 0xe5e6de9, 0x0}};
  // 0.8636
  s21_decimal dec_2 = {{0x21bc, 0x0, 0x0, 0x40000}};
  // 4446948211603893348998262332.1
  s21_decimal dec_check = {{0x5fd7ce59, 0xf9c9c392, 0x8fb04b1f, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_294) {
  // 97902388.900655822344
  s21_decimal dec_1 = {{0xfdbc7608, 0x4eab27fe, 0x5, 0xc0000}};
  // 677888452753765.767519569993
  s21_decimal dec_2 = {{0x5d6a8849, 0xa8af35f3, 0x230bc76, 0xc0000}};
  // -677888354851376.866863747649
  s21_decimal dec_check = {{0x5fae1241, 0x5a040df4, 0x230bc71, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_295) {
  // 10894454803.179046
  s21_decimal dec_1 = {{0xec90a626, 0x26b472, 0x0, 0x60000}};
  // 12930075300563
  s21_decimal dec_2 = {{0x848b92d3, 0xbc2, 0x0, 0x0}};
  // -12919180845759.820954
  s21_decimal dec_check = {{0xcc8b749a, 0xb34a2687, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_296) {
  // 0.725
  s21_decimal dec_1 = {{0x2d5, 0x0, 0x0, 0x30000}};
  // -2905343458.5365184593798
  s21_decimal dec_2 = {{0x2c3d3f86, 0xfd6677b2, 0x626, 0x800d0000}};
  // 2905343459.2615184593798
  s21_decimal dec_check = {{0x31e9f386, 0xfd667e4a, 0x626, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_297) {
  // -360309
  s21_decimal dec_1 = {{0x57f75, 0x0, 0x0, 0x80000000}};
  // -49897680274292266032
  s21_decimal dec_2 = {{0x1934d430, 0xb4782bd7, 0x2, 0x80000000}};
  // 49897680274291905723
  s21_decimal dec_check = {{0x192f54bb, 0xb4782bd7, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_298) {
  // -0.8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80010000}};
  // -7130378065373
  s21_decimal dec_2 = {{0x2ba6d5dd, 0x67c, 0x0, 0x80000000}};
  // 7130378065372.2
  s21_decimal dec_check = {{0xb4845a9a, 0x40d9, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_299) {
  // 1190.1179
  s21_decimal dec_1 = {{0xb598fb, 0x0, 0x0, 0x40000}};
  // 6664964706992
  s21_decimal dec_2 = {{0xceda92b0, 0x60f, 0x0, 0x0}};
  // -6664964705801.8821
  s21_decimal dec_check = {{0x394c6205, 0xecc980, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_300) {
  // -9.42
  s21_decimal dec_1 = {{0x3ae, 0x0, 0x0, 0x80020000}};
  // 208
  s21_decimal dec_2 = {{0xd0, 0x0, 0x0, 0x0}};
  // -217.42
  s21_decimal dec_check = {{0x54ee, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_301) {
  // -4981.715120657264344088507
  s21_decimal dec_1 = {{0xa838bfbb, 0x515d0bdd, 0x41eeb, 0x80150000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -4986.715120657264344088507
  s21_decimal dec_check = {{0x158bfbb, 0x5e4d70bb, 0x41ffa, 0x80150000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_302) {
  // 8320439464481925.3
  s21_decimal dec_1 = {{0xc28e4d35, 0x12799f4, 0x0, 0x10000}};
  // -292.9
  s21_decimal dec_2 = {{0xb71, 0x0, 0x0, 0x80010000}};
  // 8320439464482218.2
  s21_decimal dec_check = {{0xc28e58a6, 0x12799f4, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_303) {
  // 2924460180
  s21_decimal dec_1 = {{0xae4fb894, 0x0, 0x0, 0x0}};
  // -0.42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x80020000}};
  // 2924460180.42
  s21_decimal dec_check = {{0x172419fa, 0x44, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_304) {
  // -26746603
  s21_decimal dec_1 = {{0x1981eeb, 0x0, 0x0, 0x80000000}};
  // 67
  s21_decimal dec_2 = {{0x43, 0x0, 0x0, 0x0}};
  // -26746670
  s21_decimal dec_check = {{0x1981f2e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_305) {
  // 9243995921.0836461109726
  s21_decimal dec_1 = {{0x81f441de, 0x2e238e5c, 0x1393, 0xd0000}};
  // 971932462108
  s21_decimal dec_2 = {{0x4bb06c1c, 0xe2, 0x0, 0x0}};
  // -962688466186.9163538890274
  s21_decimal dec_check = {{0x6e153e22, 0x76967512, 0x7f692, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_306) {
  // 19
  s21_decimal dec_1 = {{0x13, 0x0, 0x0, 0x0}};
  // -76531184416234392.4345
  s21_decimal dec_2 = {{0x3f9df279, 0x7cd5db78, 0x29, 0x80040000}};
  // 76531184416234411.4345
  s21_decimal dec_check = {{0x3fa0d8a9, 0x7cd5db78, 0x29, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_307) {
  // 1336.68
  s21_decimal dec_1 = {{0x20a24, 0x0, 0x0, 0x20000}};
  // 45134257
  s21_decimal dec_2 = {{0x2b0b1b1, 0x0, 0x0, 0x0}};
  // -45132920.32
  s21_decimal dec_check = {{0xd035f00, 0x1, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_308) {
  // 139111.28207119453
  s21_decimal dec_1 = {{0xef35d45d, 0x316c18, 0x0, 0xb0000}};
  // -297.8474170032646657
  s21_decimal dec_2 = {{0x1d78ea01, 0x2955aa7a, 0x0, 0x80100000}};
  // 139409.1294881977946657
  s21_decimal dec_check = {{0xa0a35221, 0x92e7367b, 0x4b, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_309) {
  // 20226
  s21_decimal dec_1 = {{0x4f02, 0x0, 0x0, 0x0}};
  // -514252562.67467953682420504798
  s21_decimal dec_2 = {{0xca4e98de, 0x4a669745, 0xa629f998, 0x80140000}};
  // 514272788.67467953682420504798
  s21_decimal dec_check = {{0x806e98de, 0xa8055532, 0xa62ba5e5, 0x140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_310) {
  // 84228
  s21_decimal dec_1 = {{0x14904, 0x0, 0x0, 0x0}};
  // 0.8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x10000}};
  // 84227.2
  s21_decimal dec_check = {{0xcda20, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_311) {
  // -690046227093
  s21_decimal dec_1 = {{0xa9f5d295, 0xa0, 0x0, 0x80000000}};
  // -62580
  s21_decimal dec_2 = {{0xf474, 0x0, 0x0, 0x80000000}};
  // -690046164513
  s21_decimal dec_check = {{0xa9f4de21, 0xa0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_312) {
  // -6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80000000}};
  // 6066975832419565
  s21_decimal dec_2 = {{0xe35a2ced, 0x158de1, 0x0, 0x0}};
  // -6066975832419571
  s21_decimal dec_check = {{0xe35a2cf3, 0x158de1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_313) {
  // 6.21
  s21_decimal dec_1 = {{0x26d, 0x0, 0x0, 0x20000}};
  // -676.7
  s21_decimal dec_2 = {{0x1a6f, 0x0, 0x0, 0x80010000}};
  // 682.91
  s21_decimal dec_check = {{0x10ac3, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_315) {
  // -6124061756105206862014956
  s21_decimal dec_1 = {{0x7a2969ec, 0xd92bbe6, 0x510d2, 0x80000000}};
  // -354991212985
  s21_decimal dec_2 = {{0xa72009b9, 0x52, 0x0, 0x80000000}};
  // -6124061756104851870801971
  s21_decimal dec_check = {{0xd3096033, 0xd92bb93, 0x510d2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_316) {
  // -5835363814823.853855270029678
  s21_decimal dec_1 = {{0xfe0cc96e, 0x43862dcc, 0x12dae65a, 0x800f0000}};
  // 182804972293444649
  s21_decimal dec_2 = {{0x5cb9d429, 0x2897427, 0x0, 0x0}};
  // -182810807657259472.85385527003
  s21_decimal dec_check = {{0x87e43edb, 0x14434f04, 0x3b11c16e, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_317) {
  // -717023895
  s21_decimal dec_1 = {{0x2abcea97, 0x0, 0x0, 0x80000000}};
  // 269009894358017.404180591544
  s21_decimal dec_2 = {{0x376f73b8, 0x981a67f8, 0xde850f, 0xc0000}};
  // -269010611381912.404180591544
  s21_decimal dec_check = {{0x456be3b8, 0x76cf0184, 0xde8536, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_318) {
  // 155697156274016969
  s21_decimal dec_1 = {{0x1c4052c9, 0x22925bd, 0x0, 0x0}};
  // 88206432428601.03535621924595
  s21_decimal dec_2 = {{0x2b3566f3, 0x54d84c7d, 0x1c8043dc, 0xe0000}};
  // 155608949841588367.96464378075
  s21_decimal dec_check = {{0x31a530db, 0x61d73426, 0x3247abaf, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_319) {
  // -487038345515809821074672939
  s21_decimal dec_1 = {{0x8d544d2b, 0x9d5661d5, 0x192de61, 0x80000000}};
  // 32374661347152229.0
  s21_decimal dec_2 = {{0x6534adf2, 0x47e2dd4, 0x0, 0x10000}};
  // -487038345548184482421825168.0
  s21_decimal dec_check = {{0xea7fb1a0, 0x29de002b, 0xfbcafd0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_320) {
  // -45155840024
  s21_decimal dec_1 = {{0x837f7018, 0xa, 0x0, 0x80000000}};
  // -67092789.0631
  s21_decimal dec_2 = {{0x366b28c7, 0x9c, 0x0, 0x80040000}};
  // -45088747234.9369
  s21_decimal dec_check = {{0x6b9f80b9, 0x19a14, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_321) {
  // -49520395248642763246
  s21_decimal dec_1 = {{0xbc4b29ee, 0xaf3bc91b, 0x2, 0x80000000}};
  // 9936114184264142259161
  s21_decimal dec_2 = {{0x906383d9, 0xa348c6cc, 0x21a, 0x0}};
  // -9985634579512785022407
  s21_decimal dec_check = {{0x4caeadc7, 0x52848fe8, 0x21d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_322) {
  // 4653349046316512.4206679953
  s21_decimal dec_1 = {{0xd3385791, 0x929ad1c3, 0x267dd9, 0xa0000}};
  // 7189783494122684325246478
  s21_decimal dec_2 = {{0x60a7360e, 0xf1b72f08, 0x5f27e, 0x0}};
  // -7189783489469335278929965.5793
  s21_decimal dec_check = {{0x83b37471, 0x7dd50c37, 0xe8507ebf, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_323) {
  // 593
  s21_decimal dec_1 = {{0x251, 0x0, 0x0, 0x0}};
  // 296
  s21_decimal dec_2 = {{0x128, 0x0, 0x0, 0x0}};
  // 297
  s21_decimal dec_check = {{0x129, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_324) {
  // -4289397584859463473900.4053475
  s21_decimal dec_1 = {{0x111197e3, 0x14507bc3, 0x8a9910b2, 0x80070000}};
  // 88593836.0684
  s21_decimal dec_2 = {{0x460a916c, 0xce, 0x0, 0x40000}};
  // -4289397584859552067736.4737475
  s21_decimal dec_check = {{0xaa59a5c3, 0x1453a184, 0x8a9910b2, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_325) {
  // -907507228940690279
  s21_decimal dec_1 = {{0x3c1be367, 0xc981d04, 0x0, 0x80000000}};
  // -42.6
  s21_decimal dec_2 = {{0x1aa, 0x0, 0x0, 0x80010000}};
  // -907507228940690236.4
  s21_decimal dec_check = {{0x5916e05c, 0x7df1222a, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_326) {
  // -7059
  s21_decimal dec_1 = {{0x1b93, 0x0, 0x0, 0x80000000}};
  // 3906288263020082096166
  s21_decimal dec_2 = {{0x85a7e826, 0xc2a3bed0, 0xd3, 0x0}};
  // -3906288263020082103225
  s21_decimal dec_check = {{0x85a803b9, 0xc2a3bed0, 0xd3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_327) {
  // 756030079260.47421892384368303
  s21_decimal dec_1 = {{0x7f3da6af, 0xfe335dc8, 0xf44957a7, 0x110000}};
  // 4213952977349809014376372012
  s21_decimal dec_2 = {{0x45c6172c, 0xa3c4c392, 0xd9db340, 0x0}};
  // -4213952977349808258346292751.5
  s21_decimal dec_check = {{0x74b1dc9b, 0x65af9cd6, 0x88290086, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_328) {
  // 9372237
  s21_decimal dec_1 = {{0x8f024d, 0x0, 0x0, 0x0}};
  // 1191628220442952
  s21_decimal dec_2 = {{0x90c8a948, 0x43bc7, 0x0, 0x0}};
  // -1191628211070715
  s21_decimal dec_check = {{0x9039a6fb, 0x43bc7, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_329) {
  // 12
  s21_decimal dec_1 = {{0xc, 0x0, 0x0, 0x0}};
  // -385052207849
  s21_decimal dec_2 = {{0xa6e66ae9, 0x59, 0x0, 0x80000000}};
  // 385052207861
  s21_decimal dec_check = {{0xa6e66af5, 0x59, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_330) {
  // 5974429754405740013903907
  s21_decimal dec_1 = {{0xb25f6023, 0x7c67828e, 0x4f122, 0x0}};
  // -53
  s21_decimal dec_2 = {{0x35, 0x0, 0x0, 0x80000000}};
  // 5974429754405740013903960
  s21_decimal dec_check = {{0xb25f6058, 0x7c67828e, 0x4f122, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_331) {
  // 2375510809
  s21_decimal dec_1 = {{0x8d976b19, 0x0, 0x0, 0x0}};
  // -6753463.12848995142019728
  s21_decimal dec_2 = {{0x24cf2a90, 0x98d3960b, 0x8f02, 0x80110000}};
  // 2382264272.12848995142019728
  s21_decimal dec_check = {{0xf5492a90, 0x7f12dc4a, 0xc50e68, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_332) {
  // -3181398.4159332095383886824720
  s21_decimal dec_1 = {{0xf3b0510, 0xc61972b, 0x66cbe931, 0x80160000}};
  // -82172.774
  s21_decimal dec_2 = {{0x4e5db66, 0x0, 0x0, 0x80030000}};
  // -3099225.6419332095383886824720
  s21_decimal dec_check = {{0xa4cb0510, 0xddc4da, 0x64243193, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_333) {
  // -4408649416400
  s21_decimal dec_1 = {{0x77fb7ed0, 0x402, 0x0, 0x80000000}};
  // -69976806
  s21_decimal dec_2 = {{0x42bc2e6, 0x0, 0x0, 0x80000000}};
  // -4408579439594
  s21_decimal dec_check = {{0x73cfbbea, 0x402, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_334) {
  // 6558502763.23206
  s21_decimal dec_1 = {{0xabeff86, 0x2547e, 0x0, 0x50000}};
  // 83599204776075074.533178727
  s21_decimal dec_2 = {{0x9fa5bd67, 0xf8c8ce5b, 0x4526d1, 0x90000}};
  // -83599198217572311.301118727
  s21_decimal dec_check = {{0xdac85b07, 0x9dc452d7, 0x4526d1, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_336) {
  // -14473938163180791796.099378
  s21_decimal dec_1 = {{0x41346932, 0xc29271eb, 0xbf8f9, 0x80060000}};
  // -8013290983910
  s21_decimal dec_2 = {{0xbd5cd1e6, 0x749, 0x0, 0x80000000}};
  // -14473930149889807886.099378
  s21_decimal dec_check = {{0xaf68a3b2, 0x535d8439, 0xbf8f9, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_337) {
  // 60029938284698861
  s21_decimal dec_1 = {{0x2b591ced, 0xd544e9, 0x0, 0x0}};
  // 84
  s21_decimal dec_2 = {{0x54, 0x0, 0x0, 0x0}};
  // 60029938284698777
  s21_decimal dec_check = {{0x2b591c99, 0xd544e9, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_338) {
  // -66380914016768985530705.837
  s21_decimal dec_1 = {{0x4c5527ad, 0x8f36a7b3, 0x36e8b4, 0x80030000}};
  // 768933513463
  s21_decimal dec_2 = {{0x80248f7, 0xb3, 0x0, 0x0}};
  // -66380914017537919044168.837
  s21_decimal dec_check = {{0x95422c85, 0x8f39630a, 0x36e8b4, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_339) {
  // 611688375.6155471892
  s21_decimal dec_1 = {{0x1a010814, 0x54e3895e, 0x0, 0xa0000}};
  // 68520245971433.6
  s21_decimal dec_2 = {{0x2135e320, 0x26f30, 0x0, 0x10000}};
  // -68519634283057.9844528108
  s21_decimal dec_check = {{0x6c7637ec, 0x9173d699, 0x9118, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_340) {
  // -559330.597932
  s21_decimal dec_1 = {{0x3ab39c2c, 0x82, 0x0, 0x80060000}};
  // -953595343771731.7419
  s21_decimal dec_2 = {{0xc1ce472b, 0x84568320, 0x0, 0x80040000}};
  // 953595343212401.143968
  s21_decimal dec_check = {{0x79e030a0, 0xb1cb3849, 0x33, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_341) {
  // 5404414574.1099347313049124
  s21_decimal dec_1 = {{0x15023e24, 0x2d97dd2, 0x2cb44b, 0x100000}};
  // -4137525648742281
  s21_decimal dec_2 = {{0xc28ad789, 0xeb30e, 0x0, 0x80000000}};
  // 4137531053156855.1099347313049
  s21_decimal dec_check = {{0x326d2199, 0x478a044e, 0x85b0dace, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_342) {
  // -8592838916.3
  s21_decimal dec_1 = {{0x1bb2a2b, 0x14, 0x0, 0x80010000}};
  // -228637987522458763760410720
  s21_decimal dec_2 = {{0xf666a060, 0x23a4751e, 0xbd1ffa, 0x80000000}};
  // 228637987522458755167571803.7
  s21_decimal dec_check = {{0x9e471995, 0x646c9321, 0x7633fc5, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_343) {
  // -9366678453420168215
  s21_decimal dec_1 = {{0x356a1417, 0x81fd206d, 0x0, 0x80000000}};
  // 4352798065059888501838737129
  s21_decimal dec_2 = {{0xe55e6ee9, 0xed2a9e60, 0xe108cd7, 0x0}};
  // -4352798074426566955258905344
  s21_decimal dec_check = {{0x1ac88300, 0x6f27bece, 0xe108cd8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_344) {
  // 27073409551390044412657263
  s21_decimal dec_1 = {{0xd74b3e6f, 0x78fcfdd5, 0x166504, 0x0}};
  // -7502700347691
  s21_decimal dec_2 = {{0xdbca012b, 0x6d2, 0x0, 0x80000000}};
  // 27073409551397547113004954
  s21_decimal dec_check = {{0xb3153f9a, 0x78fd04a8, 0x166504, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_345) {
  // -0.5742092
  s21_decimal dec_1 = {{0x579e0c, 0x0, 0x0, 0x80070000}};
  // -240449332503460871.2867712776
  s21_decimal dec_2 = {{0x4b10f08, 0x5622f40e, 0x7c4f344, 0x800a0000}};
  // 240449332503460870.7125620776
  s21_decimal dec_check = {{0xae6fb028, 0x5622f40c, 0x7c4f344, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_346) {
  // -66576859677750104757197
  s21_decimal dec_1 = {{0xea8d13cd, 0x23881197, 0xe19, 0x80000000}};
  // 44566897131965658412518163
  s21_decimal dec_2 = {{0x975e8b13, 0x55a66de0, 0x24dd68, 0x0}};
  // -44633473991643408517275360
  s21_decimal dec_check = {{0x81eb9ee0, 0x792e7f78, 0x24eb81, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_347) {
  // 56348483.9886
  s21_decimal dec_1 = {{0x32504fce, 0x83, 0x0, 0x40000}};
  // -16014.53266481125818
  s21_decimal dec_2 = {{0xd0ff19ba, 0x16398142, 0x0, 0x800e0000}};
  // 56364498.52126481125818
  s21_decimal dec_check = {{0x5dec91ba, 0x8d747d51, 0x131, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_348) {
  // -98.73112000133410
  s21_decimal dec_1 = {{0x5987922, 0x23138b, 0x0, 0x800e0000}};
  // 506
  s21_decimal dec_2 = {{0x1fa, 0x0, 0x0, 0x0}};
  // -604.73112000133410
  s21_decimal dec_check = {{0x973af922, 0xd6d7f9, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_349) {
  // -72433901452716
  s21_decimal dec_1 = {{0xd4f73dac, 0x41e0, 0x0, 0x80000000}};
  // -78628120835999520
  s21_decimal dec_2 = {{0xfbc94720, 0x11757db, 0x0, 0x80000000}};
  // 78555686934546804
  s21_decimal dec_check = {{0x26d20974, 0x11715fb, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_350) {
  // 0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};
  // 0.832
  s21_decimal dec_2 = {{0x340, 0x0, 0x0, 0x30000}};
  // -0.532
  s21_decimal dec_check = {{0x214, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_351) {
  // 101934533543533311622695
  s21_decimal dec_1 = {{0xd336fe27, 0xe1d3a989, 0x1595, 0x0}};
  // 36189727108116.7091838999299
  s21_decimal dec_2 = {{0x86ffdb03, 0x604aa2a1, 0x12b5aba, 0xd0000}};
  // 101934533507343584514578.29082
  s21_decimal dec_check = {{0x29cb28da, 0x6658c168, 0x20efd3b5, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_353) {
  // 290111675122
  s21_decimal dec_1 = {{0x8c00daf2, 0x43, 0x0, 0x0}};
  // -1455703051628.10730956
  s21_decimal dec_2 = {{0xf28ba9cc, 0xe4319d47, 0x7, 0x80080000}};
  // 1745814726750.10730956
  s21_decimal dec_check = {{0xf6945bcc, 0x76cdfc6c, 0x9, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_354) {
  // 410958059488548733759940
  s21_decimal dec_1 = {{0xbf2b1c4, 0x14bf5bb8, 0x5706, 0x0}};
  // 14924801695549731
  s21_decimal dec_2 = {{0x2f680923, 0x350607, 0x0, 0x0}};
  // 410958044563747038210209
  s21_decimal dec_check = {{0xdc8aa8a1, 0x148a55b0, 0x5706, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_355) {
  // 0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};
  // 3805685935555912096150
  s21_decimal dec_2 = {{0xf6475996, 0x4e807aff, 0xce, 0x0}};
  // -3805685935555912096149.7
  s21_decimal dec_check = {{0x9ec97fd9, 0x1104cdff, 0x80f, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_356) {
  // -3006762133824665204604942208
  s21_decimal dec_1 = {{0x804e3780, 0xe1ca4539, 0x9b722a5, 0x80000000}};
  // -23020478.1
  s21_decimal dec_2 = {{0xdb8a56d, 0x0, 0x0, 0x80010000}};
  // -3006762133824665204581921729.9
  s21_decimal dec_check = {{0xf5558593, 0xd1e6b43e, 0x61275a7a, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_357) {
  // -155729
  s21_decimal dec_1 = {{0x26051, 0x0, 0x0, 0x80000000}};
  // -550631286
  s21_decimal dec_2 = {{0x20d1f776, 0x0, 0x0, 0x80000000}};
  // 550475557
  s21_decimal dec_check = {{0x20cf9725, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_358) {
  // 896503188283
  s21_decimal dec_1 = {{0xbbc10b3b, 0xd0, 0x0, 0x0}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 896503188291
  s21_decimal dec_check = {{0xbbc10b43, 0xd0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_359) {
  // -62991099340575173983690874
  s21_decimal dec_1 = {{0x7fa9607a, 0x566df150, 0x341ae2, 0x80000000}};
  // 6820.57
  s21_decimal dec_2 = {{0xa6849, 0x0, 0x0, 0x20000}};
  // -62991099340575173983697694.57
  s21_decimal dec_check = {{0xde3417f1, 0xc2f24371, 0x145a8069, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_360) {
  // 635440092013744000237594091
  s21_decimal dec_1 = {{0x91e465eb, 0x698b7a2d, 0x20d9fac, 0x0}};
  // -210593627437791894494157
  s21_decimal dec_2 = {{0x4e6adbcd, 0x4dacddd0, 0x2c98, 0x80000000}};
  // 635650685641181792132088248
  s21_decimal dec_check = {{0xe04f41b8, 0xb73857fd, 0x20dcc44, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_361) {
  // -4904121
  s21_decimal dec_1 = {{0x4ad4b9, 0x0, 0x0, 0x80000000}};
  // -0.71713
  s21_decimal dec_2 = {{0x11821, 0x0, 0x0, 0x80050000}};
  // -4904120.28287
  s21_decimal dec_check = {{0x2ed5b17f, 0x72, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_362) {
  // -7713856449869606057160147544
  s21_decimal dec_1 = {{0xc1f30258, 0xf3b3852, 0x18ecc0a4, 0x80000000}};
  // 39
  s21_decimal dec_2 = {{0x27, 0x0, 0x0, 0x0}};
  // -7713856449869606057160147583
  s21_decimal dec_check = {{0xc1f3027f, 0xf3b3852, 0x18ecc0a4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_363) {
  // 42820871.2675199979
  s21_decimal dec_1 = {{0x30bb8beb, 0x5f14d8e, 0x0, 0xa0000}};
  // 11230358
  s21_decimal dec_2 = {{0xab5c96, 0x0, 0x0, 0x0}};
  // 31590513.2675199979
  s21_decimal dec_check = {{0x5fd3f3eb, 0x462520b, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_364) {
  // -813.41876185927
  s21_decimal dec_1 = {{0xe1a2ab47, 0x49fa, 0x0, 0x800b0000}};
  // 697569787879357878
  s21_decimal dec_2 = {{0xb497fdb6, 0x9ae4406, 0x0, 0x0}};
  // -697569787879358691.41876185927
  s21_decimal dec_check = {{0xc1739b47, 0x65302668, 0xe1659ed5, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_365) {
  // 5308.0292
  s21_decimal dec_1 = {{0x329f0e4, 0x0, 0x0, 0x40000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 5316.0292
  s21_decimal dec_check = {{0x32b2964, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_366) {
  // -4721589333177
  s21_decimal dec_1 = {{0x54a7acb9, 0x44b, 0x0, 0x80000000}};
  // 252807219056
  s21_decimal dec_2 = {{0xdc7c0770, 0x3a, 0x0, 0x0}};
  // -4974396552233
  s21_decimal dec_check = {{0x3123b429, 0x486, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_367) {
  // -626266643
  s21_decimal dec_1 = {{0x25541213, 0x0, 0x0, 0x80000000}};
  // 2526224454170397342
  s21_decimal dec_2 = {{0xadbb4a9e, 0x230ef3c1, 0x0, 0x0}};
  // -2526224454796663985
  s21_decimal dec_check = {{0xd30f5cb1, 0x230ef3c1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_368) {
  // 1708.0
  s21_decimal dec_1 = {{0x42b8, 0x0, 0x0, 0x10000}};
  // 72449088878921334947764
  s21_decimal dec_2 = {{0xa9947fb4, 0x791513a7, 0xf57, 0x0}};
  // -72449088878921334946056.0
  s21_decimal dec_check = {{0x9fccba50, 0xbad2c48c, 0x996a, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_369) {
  // -985122060617236682
  s21_decimal dec_1 = {{0x737dc0ca, 0xdabdb4b, 0x0, 0x80000000}};
  // -209500308453728335150
  s21_decimal dec_2 = {{0xf73e352e, 0x5b669c8e, 0xb, 0x80000000}};
  // 208515186393111098468
  s21_decimal dec_check = {{0x83c07464, 0x4dbac143, 0xb, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_370) {
  // 97407672568822976811.410692085
  s21_decimal dec_1 = {{0x5f6497f5, 0xcb31b7ef, 0x3abdbcfe, 0x90000}};
  // 117554565.98577418714368
  s21_decimal dec_2 = {{0xe8c9bd00, 0x43bb7553, 0x27d, 0xe0000}};
  // 97407672568705422245.424917898
  s21_decimal dec_check = {{0x1c15ed8a, 0xc99014ae, 0x3abdbcfe, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_371) {
  // 242993514210.3381412085
  s21_decimal dec_1 = {{0x166388f5, 0xba1fd165, 0x83, 0xa0000}};
  // -796996757
  s21_decimal dec_2 = {{0x2f813495, 0x0, 0x0, 0x80000000}};
  // 243790510967.3381412085
  s21_decimal dec_check = {{0x4f9f3cf5, 0x28bad4ac, 0x84, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_372) {
  // 618168.57
  s21_decimal dec_1 = {{0x3af4019, 0x0, 0x0, 0x20000}};
  // 86364661054052994.61
  s21_decimal dec_2 = {{0x37625b05, 0x77dae42a, 0x0, 0x20000}};
  // -86364661053434826.04
  s21_decimal dec_check = {{0x33b31aec, 0x77dae42a, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_373) {
  // -64886665008917487.6376
  s21_decimal dec_1 = {{0xcaf440d8, 0x2cd56c69, 0x23, 0x80040000}};
  // 849084990799665721.2864
  s21_decimal dec_2 = {{0x42ec5dc0, 0x4a369cdf, 0x1cc, 0x40000}};
  // -913971655808583208.9240
  s21_decimal dec_check = {{0xde09e98, 0x770c0949, 0x1ef, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_374) {
  // -66088975623202560762
  s21_decimal dec_1 = {{0xc6705afa, 0x952b352c, 0x3, 0x80000000}};
  // 6.3234667187
  s21_decimal dec_2 = {{0xb91472b3, 0xe, 0x0, 0xa0000}};
  // -66088975623202560768.323466719
  s21_decimal dec_check = {{0x7915b5df, 0x66a09924, 0xd58b84f3, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_375) {
  // 2617769607978674867
  s21_decimal dec_1 = {{0xc361eab3, 0x24542f96, 0x0, 0x0}};
  // 3748.75917969834
  s21_decimal dec_2 = {{0x99ece9aa, 0x154f2, 0x0, 0xb0000}};
  // 2617769607978671118.2408203017
  s21_decimal dec_check = {{0xc420bb09, 0x4bc7f88, 0x5495aec4, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_376) {
  // -31.55
  s21_decimal dec_1 = {{0xc53, 0x0, 0x0, 0x80020000}};
  // -78.4808
  s21_decimal dec_2 = {{0xbf9a8, 0x0, 0x0, 0x80040000}};
  // 46.9308
  s21_decimal dec_check = {{0x7293c, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_377) {
  // -14960602
  s21_decimal dec_1 = {{0xe447da, 0x0, 0x0, 0x80000000}};
  // 7158505602573423852570
  s21_decimal dec_2 = {{0x8bbc1a, 0x1038c627, 0x184, 0x0}};
  // -7158505602573438813172
  s21_decimal dec_check = {{0x17003f4, 0x1038c627, 0x184, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_378) {
  // -43403751432575423694
  s21_decimal dec_1 = {{0xa0294ce, 0x5a5919f7, 0x2, 0x80000000}};
  // -9490.05585961441
  s21_decimal dec_2 = {{0x94d751e1, 0x35f1d, 0x0, 0x800b0000}};
  // -43403751432575414203.944140386
  s21_decimal dec_check = {{0x73edfe62, 0xdc67831d, 0x8c3ebddf, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_379) {
  // 23504815961044454982211
  s21_decimal dec_1 = {{0xba8bc243, 0x32d92eb7, 0x4fa, 0x0}};
  // -292776.15858970073615945915033
  s21_decimal dec_2 = {{0xb8f75a99, 0xf97d754e, 0x5e99e04f, 0x80170000}};
  // 23504815961044455274987.158590
  s21_decimal dec_check = {{0x37c47c3e, 0x711afa7b, 0x4bf2ba62, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_380) {
  // -9388570941904409748503.3228
  s21_decimal dec_1 = {{0xa3e5cf0c, 0x8180ed4f, 0x4da912, 0x80040000}};
  // -490
  s21_decimal dec_2 = {{0x1ea, 0x0, 0x0, 0x80000000}};
  // -9388570941904409748013.3228
  s21_decimal dec_check = {{0xa39b0a6c, 0x8180ed4f, 0x4da912, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_381) {
  // 78.568506978385433691782514841
  s21_decimal dec_1 = {{0xf7720899, 0xbed28b21, 0xfdde5881, 0x1b0000}};
  // 5670
  s21_decimal dec_2 = {{0x1626, 0x0, 0x0, 0x0}};
  // -5591.4314930216145663082174852
  s21_decimal dec_check = {{0xaf491984, 0x4d9fa2d, 0xb4ab3cbe, 0x80190000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_382) {
  // 73707395007513575177963
  s21_decimal dec_1 = {{0x670e3eeb, 0xaf9678d1, 0xf9b, 0x0}};
  // 430651614674295439967440.7997
  s21_decimal dec_2 = {{0x58701c3d, 0x1b6ceb5f, 0xdea4444, 0x40000}};
  // -356944219666781864789477.7997
  s21_decimal dec_check = {{0xbbf6608d, 0x359d7795, 0xb8892c9, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_383) {
  // -2476.8189029
  s21_decimal dec_1 = {{0xc44c9265, 0x5, 0x0, 0x80070000}};
  // -754540134117020582584.08490
  s21_decimal dec_2 = {{0xb29e242a, 0x4360267d, 0x3e6a02, 0x80050000}};
  // 754540134117020580107.2659971
  s21_decimal dec_check = {{0x1798e03, 0x518f0914, 0x186168e2, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_384) {
  // 4418.499
  s21_decimal dec_1 = {{0x436bc3, 0x0, 0x0, 0x30000}};
  // -273955816230200303874
  s21_decimal dec_2 = {{0x99486102, 0xd9e69361, 0xe, 0x80000000}};
  // 273955816230200308292.499
  s21_decimal dec_check = {{0xc2fe5b93, 0x2cafb53e, 0x3a03, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_386) {
  // -5633526671122241183121
  s21_decimal dec_1 = {{0xa2085d91, 0x64e343ae, 0x131, 0x80000000}};
  // -0.7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80010000}};
  // -5633526671122241183120.3
  s21_decimal dec_check = {{0x5453a7a3, 0xf0e0a4d2, 0xbed, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_387) {
  // 790066447180289
  s21_decimal dec_1 = {{0xadeee201, 0x2ce8f, 0x0, 0x0}};
  // -49774504576987285
  s21_decimal dec_2 = {{0xf02eb095, 0xb0d5a5, 0x0, 0x80000000}};
  // 50564571024167574
  s21_decimal dec_check = {{0x9e1d9296, 0xb3a435, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_388) {
  // -7177724334999
  s21_decimal dec_1 = {{0x31b59397, 0x687, 0x0, 0x80000000}};
  // -6297346
  s21_decimal dec_2 = {{0x601702, 0x0, 0x0, 0x80000000}};
  // -7177718037653
  s21_decimal dec_check = {{0x31557c95, 0x687, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_389) {
  // -14767
  s21_decimal dec_1 = {{0x39af, 0x0, 0x0, 0x80000000}};
  // -164021976.921505159833835509
  s21_decimal dec_2 = {{0x12f5d7f5, 0x2f88ee74, 0x87ad01, 0x80120000}};
  // 164007209.921505159833835509
  s21_decimal dec_check = {{0x6199d7f5, 0xaa3e095f, 0x87a9e0, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_390) {
  // 963312420087887
  s21_decimal dec_1 = {{0xa69b684f, 0x36c20, 0x0, 0x0}};
  // -21341742069515044916179.61
  s21_decimal dec_2 = {{0x8eac9ea9, 0xd0c9fad5, 0x1c3ed, 0x80020000}};
  // 21341743032827465004066.61
  s21_decimal dec_check = {{0xa3615d85, 0xd2203796, 0x1c3ed, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_391) {
  // 72824206673075
  s21_decimal dec_1 = {{0xb4f844b3, 0x423b, 0x0, 0x0}};
  // -4977195898679482949580281
  s21_decimal dec_2 = {{0x19f035f9, 0x548f4ef0, 0x41df6, 0x80000000}};
  // 4977195898752307156253356
  s21_decimal dec_check = {{0xcee87aac, 0x548f912b, 0x41df6, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_392) {
  // -81232645
  s21_decimal dec_1 = {{0x4d78305, 0x0, 0x0, 0x80000000}};
  // -5328274435293107876.515056606
  s21_decimal dec_2 = {{0x12b88bde, 0xeaccd6c4, 0x113771ff, 0x80090000}};
  // 5328274435211875231.515056606
  s21_decimal dec_check = {{0xd5499de, 0xe9ac3e1b, 0x113771ff, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_394) {
  // 1791774379
  s21_decimal dec_1 = {{0x6acc4eab, 0x0, 0x0, 0x0}};
  // -739149951452922583673046305
  s21_decimal dec_2 = {{0xd9318521, 0x286b8635, 0x2636917, 0x80000000}};
  // 739149951452922585464820684
  s21_decimal dec_check = {{0x43fdd3cc, 0x286b8636, 0x2636917, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_395) {
  // 92
  s21_decimal dec_1 = {{0x5c, 0x0, 0x0, 0x0}};
  // -28608.032579
  s21_decimal dec_2 = {{0xa92bef43, 0x6, 0x0, 0x80060000}};
  // 28700.032579
  s21_decimal dec_check = {{0xaea7be43, 0x6, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_396) {
  // 642152542212.77177643
  s21_decimal dec_1 = {{0xbca1272b, 0x7b2a697c, 0x3, 0x80000}};
  // -0.5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 642152542213.27177643
  s21_decimal dec_check = {{0xbf9c17ab, 0x7b2a697c, 0x3, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_397) {
  // -618.909571
  s21_decimal dec_1 = {{0x24e3cf83, 0x0, 0x0, 0x80060000}};
  // 611826.3439298931
  s21_decimal dec_2 = {{0x36f11173, 0x15bc87, 0x0, 0xa0000}};
  // -612445.2535008931
  s21_decimal dec_check = {{0x39cafea3, 0x15c228, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_398) {
  // 9921607225914009593993098
  s21_decimal dec_1 = {{0xc05e578a, 0x67cb30ca, 0x834fb, 0x0}};
  // -1422134013186276443
  s21_decimal dec_2 = {{0xa6f7fc5b, 0x13bc6f59, 0x0, 0x80000000}};
  // 9921608648048022780269541
  s21_decimal dec_check = {{0x675653e5, 0x7b87a024, 0x834fb, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_399) {
  // -3219305940751
  s21_decimal dec_1 = {{0x8d96470f, 0x2ed, 0x0, 0x80000000}};
  // 36
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x0}};
  // -3219305940787
  s21_decimal dec_check = {{0x8d964733, 0x2ed, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_400) {
  // 3980562720
  s21_decimal dec_1 = {{0xed429120, 0x0, 0x0, 0x0}};
  // -4.9
  s21_decimal dec_2 = {{0x31, 0x0, 0x0, 0x80010000}};
  // 3980562724.9
  s21_decimal dec_check = {{0x4499ab71, 0x9, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_401) {
  // -8148492.0744721927108119
  s21_decimal dec_1 = {{0x28f7f617, 0x4e708bb6, 0x1141, 0x80100000}};
  // -47465736381039.700
  s21_decimal dec_2 = {{0xf3fe8454, 0xa8a1d5, 0x0, 0x80030000}};
  // 47465728232547.625527807289188
  s21_decimal dec_check = {{0xf183a764, 0x6aaf12d4, 0x995ebaeb, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_402) {
  // 86378943977086611309
  s21_decimal dec_1 = {{0x539d6f6d, 0xaebfa7e4, 0x4, 0x0}};
  // -5624475531187
  s21_decimal dec_2 = {{0x8cddb7b3, 0x51d, 0x0, 0x80000000}};
  // 86378949601562142496
  s21_decimal dec_check = {{0xe07b2720, 0xaebfad01, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_403) {
  // -59698306822
  s21_decimal dec_1 = {{0xe64bdf06, 0xd, 0x0, 0x80000000}};
  // -3.562512131
  s21_decimal dec_2 = {{0xd4579f03, 0x0, 0x0, 0x80090000}};
  // -59698306818.437487869
  s21_decimal dec_check = {{0x953f1cfd, 0x3c7afdc1, 0x3, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_404) {
  // -24437984892192110727
  s21_decimal dec_1 = {{0xd793887, 0x532529c8, 0x1, 0x80000000}};
  // 5514895000306017
  s21_decimal dec_2 = {{0x8d778161, 0x1397c4, 0x0, 0x0}};
  // -24443499787192416744
  s21_decimal dec_check = {{0x9af0b9e8, 0x5338c18c, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_405) {
  // -12203.49560275685944441287
  s21_decimal dec_1 = {{0xbad5b9c7, 0x483fb5a8, 0x1026b, 0x80140000}};
  // 41552062035570379211659997910
  s21_decimal dec_2 = {{0x17aef2d6, 0x82c9df7f, 0x86430f64, 0x0}};
  // -41552062035570379211660010113
  s21_decimal dec_check = {{0x17af2281, 0x82c9df7f, 0x86430f64, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_406) {
  // -7.5820302898365201794
  s21_decimal dec_1 = {{0xdb93fd82, 0x1c37d3c5, 0x4, 0x80130000}};
  // -702.60780552
  s21_decimal dec_2 = {{0x5bde6e08, 0x10, 0x0, 0x80080000}};
  // 695.0257752301634798206
  s21_decimal dec_check = {{0xafd3427e, 0xc633c9ac, 0x178, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_407) {
  // 1127272286310114648
  s21_decimal dec_1 = {{0xfea82558, 0xfa4e02b, 0x0, 0x0}};
  // 2329952897489064642536142
  s21_decimal dec_2 = {{0x7150e2ce, 0xffe9dec9, 0x1ed62, 0x0}};
  // -2329951770216778332421494
  s21_decimal dec_check = {{0x72a8bd76, 0xf044fe9d, 0x1ed62, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_408) {
  // -93941167011050290436243.89
  s21_decimal dec_1 = {{0x52f299c5, 0x1638439a, 0x7c548, 0x80020000}};
  // 363753699310984889150
  s21_decimal dec_2 = {{0xd82033e, 0xb818be46, 0x13, 0x0}};
  // -94304920710361275325393.89
  s21_decimal dec_check = {{0x99bbddfd, 0xffe296f7, 0x7ccfb, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_409) {
  // -47720699299008.72968527
  s21_decimal dec_1 = {{0x18c6294f, 0xb1c61dbc, 0x102, 0x80080000}};
  // -193.21217624806
  s21_decimal dec_2 = {{0x92502ae6, 0x1192, 0x0, 0x800b0000}};
  // -47720699298815.51750902194
  s21_decimal dec_check = {{0x33c131b2, 0x6de4152e, 0x3f286, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_410) {
  // 83.92486714738
  s21_decimal dec_1 = {{0x7307d72, 0x7a2, 0x0, 0xb0000}};
  // -19160.32122
  s21_decimal dec_2 = {{0x7234547a, 0x0, 0x0, 0x80050000}};
  // 19244.24608714738
  s21_decimal dec_check = {{0x5330ff2, 0x6d641, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_411) {
  // -164435118175935
  s21_decimal dec_1 = {{0x88ceb6bf, 0x958d, 0x0, 0x80000000}};
  // -797720198611496641325
  s21_decimal dec_2 = {{0x6850a32d, 0x3e977622, 0x2b, 0x80000000}};
  // 797720034176378465390
  s21_decimal dec_check = {{0xdf81ec6e, 0x3e96e094, 0x2b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_412) {
  // 6050641
  s21_decimal dec_1 = {{0x5c5351, 0x0, 0x0, 0x0}};
  // -0.0344
  s21_decimal dec_2 = {{0x158, 0x0, 0x0, 0x80040000}};
  // 6050641.0344
  s21_decimal dec_check = {{0x16768d68, 0xe, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_413) {
  // 3236
  s21_decimal dec_1 = {{0xca4, 0x0, 0x0, 0x0}};
  // -18363632847909
  s21_decimal dec_2 = {{0x9dd00c25, 0x10b3, 0x0, 0x80000000}};
  // 18363632851145
  s21_decimal dec_check = {{0x9dd018c9, 0x10b3, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_414) {
  // -0.4054520801
  s21_decimal dec_1 = {{0xf1ab13e1, 0x0, 0x0, 0x800a0000}};
  // 3571408.919
  s21_decimal dec_2 = {{0xd4df6017, 0x0, 0x0, 0x30000}};
  // -3571409.3244520801
  s21_decimal dec_check = {{0x51509961, 0x7ee1c7, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_415) {
  // -889.29
  s21_decimal dec_1 = {{0x15b61, 0x0, 0x0, 0x80020000}};
  // -760076.963505462807356
  s21_decimal dec_2 = {{0x74a78b3c, 0x342fd33f, 0x29, 0x800f0000}};
  // 759187.673505462807356
  s21_decimal dec_check = {{0x5c58eb3c, 0x27d86eb4, 0x29, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_416) {
  // -349534908265802649247.8
  s21_decimal dec_1 = {{0x3b27123e, 0x7bb67f86, 0xbd, 0x80010000}};
  // -103420223898840002619
  s21_decimal dec_2 = {{0x31b8f03b, 0x9b3e71b1, 0x5, 0x80000000}};
  // -246114684366962646628.8
  s21_decimal dec_check = {{0x49edaff0, 0x6b460e9a, 0x85, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_417) {
  // 7513988.6109
  s21_decimal dec_1 = {{0x7eafac1d, 0x11, 0x0, 0x40000}};
  // -251
  s21_decimal dec_2 = {{0xfb, 0x0, 0x0, 0x80000000}};
  // 7514239.6109
  s21_decimal dec_check = {{0x7ed5f8cd, 0x11, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_418) {
  // -602646009476692
  s21_decimal dec_1 = {{0x7551f654, 0x2241a, 0x0, 0x80000000}};
  // 997279537909
  s21_decimal dec_2 = {{0x327e1af5, 0xe8, 0x0, 0x0}};
  // -603643289014601
  s21_decimal dec_check = {{0xa7d01149, 0x22502, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_419) {
  // -87454.257
  s21_decimal dec_1 = {{0x5367231, 0x0, 0x0, 0x80030000}};
  // -92202197
  s21_decimal dec_2 = {{0x57ee4d5, 0x0, 0x0, 0x80000000}};
  // 92114742.743
  s21_decimal dec_check = {{0x72776dd7, 0x15, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_420) {
  // 15296104.34495
  s21_decimal dec_1 = {{0x23e2f7bf, 0x164, 0x0, 0x50000}};
  // -484266254118.3631978
  s21_decimal dec_2 = {{0x7657426a, 0x433497ec, 0x0, 0x80070000}};
  // 484281550222.7081478
  s21_decimal dec_check = {{0x7b000906, 0x4335230a, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_421) {
  // -39829524736885524326389252
  s21_decimal dec_1 = {{0x16a1604, 0xdcc8db2b, 0x20f23a, 0x80000000}};
  // -11
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80000000}};
  // -39829524736885524326389241
  s21_decimal dec_check = {{0x16a15f9, 0xdcc8db2b, 0x20f23a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_422) {
  // -8412909544928953113
  s21_decimal dec_1 = {{0x58fbc319, 0x74c0a8a8, 0x0, 0x80000000}};
  // -0.7199383
  s21_decimal dec_2 = {{0x6dda97, 0x0, 0x0, 0x80070000}};
  // -8412909544928953112.2800617
  s21_decimal dec_check = {{0xd89c57e9, 0x671bcdcb, 0x459707, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_423) {
  // -37.92
  s21_decimal dec_1 = {{0xed0, 0x0, 0x0, 0x80020000}};
  // 5593119860544929548080
  s21_decimal dec_2 = {{0xeae04730, 0x34216f8b, 0x12f, 0x0}};
  // -5593119860544929548117.92
  s21_decimal dec_check = {{0xbf9bdd90, 0x5d0f92a7, 0x7670, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_424) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // 786473.6163794097885
  s21_decimal dec_2 = {{0x2f1d96dd, 0x6d2527df, 0x0, 0xd0000}};
  // -786471.6163794097885
  s21_decimal dec_check = {{0x923856dd, 0x6d2515ae, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_425) {
  // 3419056892590307883259969
  s21_decimal dec_1 = {{0xc8169841, 0x720ee718, 0x2d403, 0x0}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // 3419056892590307883259963
  s21_decimal dec_check = {{0xc816983b, 0x720ee718, 0x2d403, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_426) {
  // 49114284
  s21_decimal dec_1 = {{0x2ed6cac, 0x0, 0x0, 0x0}};
  // 6.7257
  s21_decimal dec_2 = {{0x106b9, 0x0, 0x0, 0x40000}};
  // 49114277.2743
  s21_decimal dec_check = {{0x5a63f807, 0x72, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_428) {
  // -106741587518016564221298
  s21_decimal dec_1 = {{0xa727d572, 0x791a1277, 0x169a, 0x80000000}};
  // -41899201637560339.760947952899
  s21_decimal dec_2 = {{0xf487d03, 0xae4f7ac, 0x87623510, 0x800c0000}};
  // -106741545618814926660958.23905
  s21_decimal dec_check = {{0x8324ec21, 0x459b25a5, 0x227d7426, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_429) {
  // -6621.84262261517777804
  s21_decimal dec_1 = {{0xcfdefb8c, 0xe5a7161f, 0x23, 0x80110000}};
  // 3241395531070263667272.198
  s21_decimal dec_2 = {{0xf952a06, 0x6761a2da, 0x2ae64, 0x30000}};
  // -3241395531070263673894.0406226
  s21_decimal dec_check = {{0x1da689d2, 0x55e96610, 0x68bc3206, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_430) {
  // -78.04
  s21_decimal dec_1 = {{0x1e7c, 0x0, 0x0, 0x80020000}};
  // -22908652066070
  s21_decimal dec_2 = {{0xd6119516, 0x14d5, 0x0, 0x80000000}};
  // 22908652065991.96
  s21_decimal dec_check = {{0x9ede1e1c, 0x82387, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_431) {
  // 7416018784
  s21_decimal dec_1 = {{0xba077760, 0x1, 0x0, 0x0}};
  // 964.3
  s21_decimal dec_2 = {{0x25ab, 0x0, 0x0, 0x10000}};
  // 7416017819.7
  s21_decimal dec_check = {{0x444a8415, 0x11, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_432) {
  // 10526673579.53
  s21_decimal dec_1 = {{0x17dd2b01, 0xf5, 0x0, 0x20000}};
  // -0.5657882917436
  s21_decimal dec_2 = {{0x5419fa3c, 0x525, 0x0, 0x800d0000}};
  // 10526673580.0957882917436
  s21_decimal dec_check = {{0xdd88e23c, 0x856c33e6, 0x164a, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_433) {
  // -7951848463651781653093
  s21_decimal dec_1 = {{0x1422b265, 0x1210cefe, 0x1af, 0x80000000}};
  // -942610633176027446526.6364
  s21_decimal dec_2 = {{0xacbe9abc, 0x3f86ac38, 0x7cc0e, 0x80040000}};
  // -7009237830475754206566.3636
  s21_decimal dec_check = {{0xde99ee94, 0x710ef8b9, 0x39faa3, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_434) {
  // 99270643055.847431836616
  s21_decimal dec_1 = {{0x804193c8, 0x78eb7ce2, 0x1505, 0xc0000}};
  // 870087741123569
  s21_decimal dec_2 = {{0x16bbabf1, 0x31757, 0x0, 0x0}};
  // -869988470480513.152568163384
  s21_decimal dec_check = {{0xa0d27c38, 0x7c92d84a, 0x2cfa339, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_435) {
  // -1992316
  s21_decimal dec_1 = {{0x1e667c, 0x0, 0x0, 0x80000000}};
  // 58348
  s21_decimal dec_2 = {{0xe3ec, 0x0, 0x0, 0x0}};
  // -2050664
  s21_decimal dec_check = {{0x1f4a68, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_436) {
  // 50446
  s21_decimal dec_1 = {{0xc50e, 0x0, 0x0, 0x0}};
  // -305406.74722
  s21_decimal dec_2 = {{0x1c5db6a2, 0x7, 0x0, 0x80050000}};
  // 355852.74722
  s21_decimal dec_check = {{0x490c3362, 0x8, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_437) {
  // -867.202604010959674893142365
  s21_decimal dec_1 = {{0x60c095d, 0x5cd9268d, 0x2cd554b, 0x80180000}};
  // -7252228
  s21_decimal dec_2 = {{0x6ea904, 0x0, 0x0, 0x80000000}};
  // 7251360.7973959890403251068576
  s21_decimal dec_check = {{0x628a1ea0, 0x1a8618b, 0xea4dd9c5, 0x160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_438) {
  // 71346.31130088418
  s21_decimal dec_1 = {{0xc21cc3e2, 0x1958e8, 0x0, 0xb0000}};
  // 2428.424235201
  s21_decimal dec_2 = {{0x695d28c1, 0x235, 0x0, 0x90000}};
  // 68917.88706568318
  s21_decimal dec_check = {{0x99b8d87e, 0x187c0b, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_439) {
  // -315182829106447548620
  s21_decimal dec_1 = {{0x807480cc, 0x160a5929, 0x11, 0x80000000}};
  // -4668926952263028628773
  s21_decimal dec_2 = {{0x4d00dd25, 0x1a60a60c, 0xfd, 0x80000000}};
  // 4353744123156581080153
  s21_decimal dec_check = {{0xcc8c5c59, 0x4564ce2, 0xec, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_440) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -5264408587037055375
  s21_decimal dec_2 = {{0xc6dc198f, 0x490eefb7, 0x0, 0x80000000}};
  // 5264408587037055371
  s21_decimal dec_check = {{0xc6dc198b, 0x490eefb7, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_441) {
  // 4678752994298.62908361173830
  s21_decimal dec_1 = {{0xc4a7eb46, 0xce015aaa, 0x1830472, 0xe0000}};
  // -88558280970652.0443
  s21_decimal dec_2 = {{0x97bfdf7b, 0xc4a38df, 0x0, 0x80040000}};
  // 93237033964950.67338361173830
  s21_decimal dec_check = {{0x9dfa7746, 0xe78eb75a, 0x1e2062fd, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_442) {
  // 9051.7405975778
  s21_decimal dec_1 = {{0x39d444e2, 0x5253, 0x0, 0xa0000}};
  // 795503462.30219025659
  s21_decimal dec_2 = {{0xab8a2cfb, 0x4ffb9a6b, 0x4, 0xb0000}};
  // -795494410.56159267879
  s21_decimal dec_check = {{0x693f7c27, 0x4ff8632b, 0x4, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_443) {
  // -23862792567303441372267
  s21_decimal dec_1 = {{0x94e546b, 0x9ac59178, 0x50d, 0x80000000}};
  // -2619.113
  s21_decimal dec_2 = {{0x27f6e9, 0x0, 0x0, 0x80030000}};
  // -23862792567303441369647.887
  s21_decimal dec_check = {{0x59d1cb0f, 0x93c03ce4, 0x13bd24, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_444) {
  // 9771476
  s21_decimal dec_1 = {{0x9519d4, 0x0, 0x0, 0x0}};
  // 76526609103800926941181387
  s21_decimal dec_2 = {{0xf5375cb, 0xcacb4ae1, 0x3f4d23, 0x0}};
  // -76526609103800926931409911
  s21_decimal dec_check = {{0xebe5bf7, 0xcacb4ae1, 0x3f4d23, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_445) {
  // 865335838011
  s21_decimal dec_1 = {{0x7a09053b, 0xc9, 0x0, 0x0}};
  // -7.623485160964630
  s21_decimal dec_2 = {{0xf4f84216, 0x1b1584, 0x0, 0x800f0000}};
  // 865335838018.623485160964630
  s21_decimal dec_check = {{0x4f37c216, 0xc6850ee7, 0x2cbc9fd, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_446) {
  // 86816
  s21_decimal dec_1 = {{0x15320, 0x0, 0x0, 0x0}};
  // 25998863842159
  s21_decimal dec_2 = {{0x550b3b6f, 0x17a5, 0x0, 0x0}};
  // -25998863755343
  s21_decimal dec_check = {{0x5509e84f, 0x17a5, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_447) {
  // -101
  s21_decimal dec_1 = {{0x65, 0x0, 0x0, 0x80000000}};
  // -5322726773
  s21_decimal dec_2 = {{0x3d425d75, 0x1, 0x0, 0x80000000}};
  // 5322726672
  s21_decimal dec_check = {{0x3d425d10, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_448) {
  // 1309773496901968.5941484136
  s21_decimal dec_1 = {{0xa93f1a68, 0xa2a9bd69, 0xad58d, 0xa0000}};
  // -3.6
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x80010000}};
  // 1309773496901972.1941484136
  s21_decimal dec_check = {{0xb038268, 0xa2a9bd72, 0xad58d, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_449) {
  // -300
  s21_decimal dec_1 = {{0x12c, 0x0, 0x0, 0x80000000}};
  // 44780259585615744
  s21_decimal dec_2 = {{0xa98ce780, 0x9f1768, 0x0, 0x0}};
  // -44780259585616044
  s21_decimal dec_check = {{0xa98ce8ac, 0x9f1768, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_450) {
  // 8513516106965.0088104
  s21_decimal dec_1 = {{0x6c2890a8, 0x9d7cd9ed, 0x4, 0x70000}};
  // -3470762621
  s21_decimal dec_2 = {{0xcedfa27d, 0x0, 0x0, 0x80000000}};
  // 8516986869586.0088104
  s21_decimal dec_check = {{0x5f670d28, 0x9df82854, 0x4, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_451) {
  // -432536731389465935449580
  s21_decimal dec_1 = {{0x44eb8dec, 0xdcfa30e6, 0x5b97, 0x80000000}};
  // 45874661641826104511
  s21_decimal dec_2 = {{0x784874bf, 0x7ca389b5, 0x2, 0x0}};
  // -432582606051107761554091
  s21_decimal dec_check = {{0xbd3402ab, 0x599dba9b, 0x5b9a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_452) {
  // 18473899657041391.7
  s21_decimal dec_1 = {{0x7abddb5d, 0x2905323, 0x0, 0x10000}};
  // -63867350655239128
  s21_decimal dec_2 = {{0x5c8d03d8, 0xe2e704, 0x0, 0x80000000}};
  // 82341250312280519.7
  s21_decimal dec_check = {{0x184001cd, 0xb6d594f, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_453) {
  // -40.2713321
  s21_decimal dec_1 = {{0x1800eae9, 0x0, 0x0, 0x80070000}};
  // -85323296
  s21_decimal dec_2 = {{0x515ee20, 0x0, 0x0, 0x80000000}};
  // 85323255.7286679
  s21_decimal dec_check = {{0xaf7ce517, 0x30802, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_454) {
  // 70.2
  s21_decimal dec_1 = {{0x2be, 0x0, 0x0, 0x10000}};
  // -66229907810
  s21_decimal dec_2 = {{0x6b9c3162, 0xf, 0x0, 0x80000000}};
  // 66229907880.2
  s21_decimal dec_check = {{0x3419f092, 0x9a, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_455) {
  // -3.622210874654399943
  s21_decimal dec_1 = {{0x65551dc7, 0x3244ad99, 0x0, 0x80120000}};
  // -548171161901976
  s21_decimal dec_2 = {{0xb619b98, 0x1f28f, 0x0, 0x80000000}};
  // 548171161901972.37778912534560
  s21_decimal dec_check = {{0xe2166020, 0x23de20ed, 0xb11fa7df, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_456) {
  // 696056625443817785020656105
  s21_decimal dec_1 = {{0xa34c29e9, 0x4621f7de, 0x23fc3b9, 0x0}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 696056625443817785020656110
  s21_decimal dec_check = {{0xa34c29ee, 0x4621f7de, 0x23fc3b9, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_457) {
  // -54745927850002.2343
  s21_decimal dec_1 = {{0x2ffc4847, 0x798f750, 0x0, 0x80040000}};
  // 0.678383834114
  s21_decimal dec_2 = {{0xf2d3d402, 0x9d, 0x0, 0xc0000}};
  // -54745927850002.912683834114
  s21_decimal dec_check = {{0x3d4d3b02, 0xb20b54a5, 0x2d48e6, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_458) {
  // 4699985862729618784947
  s21_decimal dec_1 = {{0x6cc582b3, 0xc968108f, 0xfe, 0x0}};
  // 94.00
  s21_decimal dec_2 = {{0x24b8, 0x0, 0x0, 0x20000}};
  // 4699985862729618784853.00
  s21_decimal dec_check = {{0x7d26e934, 0xaca67806, 0x6386, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_459) {
  // -0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80010000}};
  // -3262543632339749261016449795
  s21_decimal dec_2 = {{0x11d64303, 0xb358e649, 0xa8ab67c, 0x80000000}};
  // 3262543632339749261016449794.4
  s21_decimal dec_check = {{0xb25e9e18, 0x178feda, 0x696b20df, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_460) {
  // -5033826336251
  s21_decimal dec_1 = {{0x76e3dfb, 0x494, 0x0, 0x80000000}};
  // -423563786945
  s21_decimal dec_2 = {{0x9e5e7ac1, 0x62, 0x0, 0x80000000}};
  // -4610262549306
  s21_decimal dec_check = {{0x690fc33a, 0x431, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_461) {
  // -9351902681390007
  s21_decimal dec_1 = {{0x854c5bb7, 0x213981, 0x0, 0x80000000}};
  // 54402879320826
  s21_decimal dec_2 = {{0xa84bf2fa, 0x317a, 0x0, 0x0}};
  // -9406305560710833
  s21_decimal dec_check = {{0x2d984eb1, 0x216afc, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_462) {
  // -6648424622536555
  s21_decimal dec_1 = {{0xfbf1376b, 0x179eb4, 0x0, 0x80000000}};
  // -68450237413620793.5884
  s21_decimal dec_2 = {{0xbc34898c, 0x1b60f2a0, 0x25, 0x80040000}};
  // 61801812791084238.5884
  s21_decimal dec_check = {{0x3dafc5dc, 0x80b974ef, 0x21, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_463) {
  // 857789005351026
  s21_decimal dec_1 = {{0x90f4c872, 0x30c27, 0x0, 0x0}};
  // -2396361919518267083371570.82
  s21_decimal dec_2 = {{0x6e4663da, 0xfefaead1, 0xc638ef, 0x80020000}};
  // 2396361920376056088722596.82
  s21_decimal dec_check = {{0xde4b062, 0x2baa46, 0xc638f0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_464) {
  // 380193220188.6942
  s21_decimal dec_1 = {{0x525a84de, 0xd81d6, 0x0, 0x40000}};
  // -455594142998
  s21_decimal dec_2 = {{0x1386ed16, 0x6a, 0x0, 0x80000000}};
  // 835787363186.6942
  s21_decimal dec_check = {{0x18e7b03e, 0x1db171, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_465) {
  // 7189802517534529367726.415560
  s21_decimal dec_1 = {{0x708cdec8, 0x766f336f, 0x173b43e7, 0x60000}};
  // -74.92535933988825203424
  s21_decimal dec_2 = {{0x5d8c02e0, 0x2bd2e6ce, 0x196, 0x80140000}};
  // 7189802517534529367801.3409193
  s21_decimal dec_check = {{0x922967a9, 0xa058025a, 0xe850a70a, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_466) {
  // 44.42006808968462388
  s21_decimal dec_1 = {{0x726e8034, 0x3da52da8, 0x0, 0x110000}};
  // 249.5919799
  s21_decimal dec_2 = {{0x94c4b6b7, 0x0, 0x0, 0x70000}};
  // -205.17191181031537612
  s21_decimal dec_check = {{0xa6297bcc, 0x1cbbb4ac, 0x1, 0x80110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_468) {
  // 4.3896428095
  s21_decimal dec_1 = {{0x386e563f, 0xa, 0x0, 0xa0000}};
  // -510360.523
  s21_decimal dec_2 = {{0x1e6b7bcb, 0x0, 0x0, 0x80030000}};
  // 510364.9126428095
  s21_decimal dec_check = {{0xe93d2dbf, 0x1221bd, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_469) {
  // -5606885504
  s21_decimal dec_1 = {{0x4e324880, 0x1, 0x0, 0x80000000}};
  // 15864.842470
  s21_decimal dec_2 = {{0xb19e48e6, 0x3, 0x0, 0x60000}};
  // -5606901368.842470
  s21_decimal dec_check = {{0x746168e6, 0x13eb72, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_470) {
  // -294536818.10525
  s21_decimal dec_1 = {{0xb83ddc5d, 0x1ac9, 0x0, 0x80050000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // -294536818.10525
  s21_decimal dec_check = {{0xb83ddc5d, 0x1ac9, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_471) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // 7661
  s21_decimal dec_2 = {{0x1ded, 0x0, 0x0, 0x0}};
  // -7660
  s21_decimal dec_check = {{0x1dec, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_472) {
  // -5.1590245815
  s21_decimal dec_1 = {{0x304adb7, 0xc, 0x0, 0x800a0000}};
  // -3447541699816847526868
  s21_decimal dec_2 = {{0xe9934bd4, 0xe4408e1f, 0xba, 0x80000000}};
  // 3447541699816847526862.8409754
  s21_decimal dec_check = {{0x1ae0ed9a, 0x56807246, 0x6f656584, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_474) {
  // 7949054227
  s21_decimal dec_1 = {{0xd9ccf113, 0x1, 0x0, 0x0}};
  // 17204400563053188528
  s21_decimal dec_2 = {{0xc650d5b0, 0xeec24f28, 0x0, 0x0}};
  // -17204400555104134301
  s21_decimal dec_check = {{0xec83e49d, 0xeec24f26, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_475) {
  // 12703938048195078293768
  s21_decimal dec_1 = {{0x24f28908, 0xae8e7a7c, 0x2b0, 0x0}};
  // -313234860
  s21_decimal dec_2 = {{0x12ab95ac, 0x0, 0x0, 0x80000000}};
  // 12703938048195391528628
  s21_decimal dec_check = {{0x379e1eb4, 0xae8e7a7c, 0x2b0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_476) {
  // -54109.567884818
  s21_decimal dec_1 = {{0x5d929e12, 0x3136, 0x0, 0x80090000}};
  // -3328204361167
  s21_decimal dec_2 = {{0xe8704dcf, 0x306, 0x0, 0x80000000}};
  // 3328204307057.432115182
  s21_decimal dec_check = {{0xc358b7ee, 0x6c1cf7af, 0xb4, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_477) {
  // 76608567976929268
  s21_decimal dec_1 = {{0x310427f4, 0x1102b16, 0x0, 0x0}};
  // 3897
  s21_decimal dec_2 = {{0xf39, 0x0, 0x0, 0x0}};
  // 76608567976925371
  s21_decimal dec_check = {{0x310418bb, 0x1102b16, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_478) {
  // 6728.20504114292
  s21_decimal dec_1 = {{0x3b253474, 0x263ed, 0x0, 0xb0000}};
  // -0.629987863
  s21_decimal dec_2 = {{0x258cda17, 0x0, 0x0, 0x80090000}};
  // 6728.83502900592
  s21_decimal dec_check = {{0xe62a6570, 0x263fb, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_479) {
  // 9763.5931284
  s21_decimal dec_1 = {{0xbb8e1494, 0x16, 0x0, 0x70000}};
  // -7606773344615651476193190423
  s21_decimal dec_2 = {{0x1570a217, 0x4ab70fd1, 0x18942ce9, 0x80000000}};
  // 7606773344615651476193200186.6
  s21_decimal dec_check = {{0xd667d24a, 0xeb269e2a, 0xf5c9c11c, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_480) {
  // -432182278322433
  s21_decimal dec_1 = {{0x472d7901, 0x18911, 0x0, 0x80000000}};
  // 82343434392276161468911.037929
  s21_decimal dec_2 = {{0x5277ade9, 0xe6b321d5, 0xa10e47a, 0x60000}};
  // -82343434824458439791344.037929
  s21_decimal dec_check = {{0xee173029, 0x546f062a, 0xa10e492, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_481) {
  // -3.47379945
  s21_decimal dec_1 = {{0x14b498e9, 0x0, 0x0, 0x80080000}};
  // 1616204319680688.527
  s21_decimal dec_2 = {{0x704f18f, 0x166de944, 0x0, 0x30000}};
  // -1616204319680692.00079945
  s21_decimal dec_check = {{0xffcb6c49, 0x760f6d35, 0x2239, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_482) {
  // -905
  s21_decimal dec_1 = {{0x389, 0x0, 0x0, 0x80000000}};
  // 6697.75354
  s21_decimal dec_2 = {{0x27ebf5fa, 0x0, 0x0, 0x50000}};
  // -7602.75354
  s21_decimal dec_check = {{0x2d50e19a, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_483) {
  // -623730.149
  s21_decimal dec_1 = {{0x252d5de5, 0x0, 0x0, 0x80030000}};
  // 87751582
  s21_decimal dec_2 = {{0x53afb9e, 0x0, 0x0, 0x0}};
  // -88375312.149
  s21_decimal dec_check = {{0x93943f15, 0x14, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_484) {
  // -89616587
  s21_decimal dec_1 = {{0x55770cb, 0x0, 0x0, 0x80000000}};
  // -0.29815133375
  s21_decimal dec_2 = {{0xf11ed4bf, 0x6, 0x0, 0x800b0000}};
  // -89616586.70184866625
  s21_decimal dec_check = {{0x62ab2341, 0x7c5e3514, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_485) {
  // 45972234745521749254.3742482
  s21_decimal dec_1 = {{0x39692212, 0x647e6d87, 0x17c45fe, 0x70000}};
  // 358678708493310112440646
  s21_decimal dec_2 = {{0x11962146, 0x301f56c, 0x4bf4, 0x0}};
  // -358632736258564590691391.62575
  s21_decimal dec_check = {{0xdf7795cf, 0xe1397aff, 0x73e16796, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_486) {
  // 114628480609746613606
  s21_decimal dec_1 = {{0x6eb2f566, 0x36ca2bc9, 0x6, 0x0}};
  // 13
  s21_decimal dec_2 = {{0xd, 0x0, 0x0, 0x0}};
  // 114628480609746613593
  s21_decimal dec_check = {{0x6eb2f559, 0x36ca2bc9, 0x6, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_487) {
  // -429516131526980356084
  s21_decimal dec_1 = {{0x259f47f4, 0x48bbd5f3, 0x17, 0x80000000}};
  // 660911345.333211104
  s21_decimal dec_2 = {{0xee9c8fe0, 0x92c075d, 0x0, 0x90000}};
  // -429516131527641267429.33321110
  s21_decimal dec_check = {{0x36ab596, 0x99649f72, 0x8ac8bdde, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_488) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -0.812311226018991560855956
  s21_decimal dec_2 = {{0xc6761194, 0x7ad41ef1, 0xac03, 0x80180000}};
  // -0.187688773981008439144044
  s21_decimal dec_check = {{0xda89ee6c, 0xa0faadfb, 0x27be, 0x80180000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_489) {
  // -5071609576223004642622
  s21_decimal dec_1 = {{0x21934d3e, 0xeeb8b709, 0x112, 0x80000000}};
  // -48
  s21_decimal dec_2 = {{0x30, 0x0, 0x0, 0x80000000}};
  // -5071609576223004642574
  s21_decimal dec_check = {{0x21934d0e, 0xeeb8b709, 0x112, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_490) {
  // 59
  s21_decimal dec_1 = {{0x3b, 0x0, 0x0, 0x0}};
  // -9923286365148471828
  s21_decimal dec_2 = {{0x8f26e214, 0x89b6985f, 0x0, 0x80000000}};
  // 9923286365148471887
  s21_decimal dec_check = {{0x8f26e24f, 0x89b6985f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_491) {
  // 0.974
  s21_decimal dec_1 = {{0x3ce, 0x0, 0x0, 0x30000}};
  // 96.7008674010601131
  s21_decimal dec_2 = {{0xfd1f96ab, 0xd6b8143, 0x0, 0x100000}};
  // -95.7268674010601131
  s21_decimal dec_check = {{0x8502d6ab, 0xd48e6c9, 0x0, 0x80100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_492) {
  // -75039494763.08331
  s21_decimal dec_1 = {{0x62f2a56b, 0x1aa8cd, 0x0, 0x80050000}};
  // -7672422058993915686616614318
  s21_decimal dec_2 = {{0xede0c5ae, 0x3ab6635e, 0x18ca7a91, 0x80000000}};
  // 7672422058993915611577119554.9
  s21_decimal dec_check = {{0x93c1809d, 0x4b1fe106, 0xf7e8c9ac, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_493) {
  // -31333
  s21_decimal dec_1 = {{0x7a65, 0x0, 0x0, 0x80000000}};
  // -705818.51267
  s21_decimal dec_2 = {{0x6f019483, 0x10, 0x0, 0x80050000}};
  // 674485.51267
  s21_decimal dec_check = {{0xb43f3763, 0xf, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_494) {
  // 30550686817852321752931672553
  s21_decimal dec_1 = {{0x32b8a1e9, 0xf126175d, 0x62b6ef92, 0x0}};
  // -3517855
  s21_decimal dec_2 = {{0x35ad9f, 0x0, 0x0, 0x80000000}};
  // 30550686817852321752935190408
  s21_decimal dec_check = {{0x32ee4f88, 0xf126175d, 0x62b6ef92, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_495) {
  // -4682605210343718570485896
  s21_decimal dec_1 = {{0x93b4e888, 0x897f35eb, 0x3df94, 0x80000000}};
  // -877.13
  s21_decimal dec_2 = {{0x156a1, 0x0, 0x0, 0x80020000}};
  // -4682605210343718570485018.87
  s21_decimal dec_check = {{0xb2a97e7f, 0xb5b11005, 0x1835605, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_496) {
  // 7.36
  s21_decimal dec_1 = {{0x2e0, 0x0, 0x0, 0x20000}};
  // 187525.16
  s21_decimal dec_2 = {{0x11e2404, 0x0, 0x0, 0x20000}};
  // -187517.80
  s21_decimal dec_check = {{0x11e2124, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_497) {
  // -6322566815209598
  s21_decimal dec_1 = {{0x4d16d87e, 0x167657, 0x0, 0x80000000}};
  // -5371823991532399251024
  s21_decimal dec_2 = {{0xc9a24e50, 0x35089327, 0x123, 0x80000000}};
  // 5371817668965584041426
  s21_decimal dec_check = {{0x7c8b75d2, 0x34f21cd0, 0x123, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_498) {
  // 877
  s21_decimal dec_1 = {{0x36d, 0x0, 0x0, 0x0}};
  // -153
  s21_decimal dec_2 = {{0x99, 0x0, 0x0, 0x80000000}};
  // 1030
  s21_decimal dec_check = {{0x406, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_499) {
  // 72799535904525
  s21_decimal dec_1 = {{0xf67a370d, 0x4235, 0x0, 0x0}};
  // 99.7730335218
  s21_decimal dec_2 = {{0x4d5cb9f2, 0xe8, 0x0, 0xa0000}};
  // 72799535904425.2269664782
  s21_decimal dec_check = {{0x2d39da0e, 0xb51e2e07, 0x9a28, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_500) {
  // 311511065371958595744426917
  s21_decimal dec_1 = {{0xbb43eba5, 0xb104aca2, 0x101ad08, 0x0}};
  // 4919016485
  s21_decimal dec_2 = {{0x25323c25, 0x1, 0x0, 0x0}};
  // 311511065371958590825410432
  s21_decimal dec_check = {{0x9611af80, 0xb104aca1, 0x101ad08, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_sub_1) {
  // -79228162514264337593083052642
  s21_decimal dec_1 = {{0xe4874262, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3159372907528469504894978564
  s21_decimal dec_2 = {{0x40b04a04, 0x80701a8e, 0xa355f3c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_2) {
  // 79228162514264337593413707774
  s21_decimal dec_1 = {{0xf83ca7fe, 0xffffffff, 0xffffffff, 0x0}};
  // -44017823726227.8465824
  s21_decimal dec_2 = {{0x33b89920, 0xdcb33ea0, 0x17, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_3) {
  // 79228162514264337593053578138
  s21_decimal dec_1 = {{0xe2c5839a, 0xffffffff, 0xffffffff, 0x0}};
  // -113707982935239
  s21_decimal dec_2 = {{0xb3ee54c7, 0x676a, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_4) {
  // -79228162514264337591606734791
  s21_decimal dec_1 = {{0x8c886fc7, 0xffffffff, 0xffffffff, 0x80000000}};
  // 52300377881
  s21_decimal dec_2 = {{0x2d586f19, 0xc, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_5) {
  // -79228162514264337593483064916
  s21_decimal dec_1 = {{0xfc5ef654, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2954013629507315381187957752
  s21_decimal dec_2 = {{0x1da0d3f8, 0xbbb1c121, 0x98b80b7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_6) {
  // 79228162514264337592107910318
  s21_decimal dec_1 = {{0xaa67c4ae, 0xffffffff, 0xffffffff, 0x0}};
  // -2608996100592
  s21_decimal dec_2 = {{0x744929f0, 0x25f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_7) {
  // -9066773298
  s21_decimal dec_1 = {{0x1c6bfb32, 0x2, 0x0, 0x80000000}};
  // 79228162514264337591633658613
  s21_decimal dec_2 = {{0x8e2342f5, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_8) {
  // -79228162514264337593171459954
  s21_decimal dec_1 = {{0xe9cc3f72, 0xffffffff, 0xffffffff, 0x80000000}};
  // 6212986110058
  s21_decimal dec_2 = {{0x92d4806a, 0x5a6, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_9) {
  // 4537264381352.1888942445382694
  s21_decimal dec_1 = {{0xe31d4c26, 0xb39a23c5, 0x929b5f0d, 0x100000}};
  // -79228162514264337593090209348
  s21_decimal dec_2 = {{0xe4f47644, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_10) {
  // 855511506423087261.651002487
  s21_decimal dec_1 = {{0x67bb6477, 0xb1488654, 0x2c3a99b, 0x90000}};
  // -79228162514264337592492157172
  s21_decimal dec_2 = {{0xc14ee8f4, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_11) {
  // 548179879599339549202
  s21_decimal dec_1 = {{0x37093212, 0xb786281d, 0x1d, 0x0}};
  // -79228162514264337592072799515
  s21_decimal dec_2 = {{0xa850051b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_12) {
  // 79228162514264337593157287877
  s21_decimal dec_1 = {{0xe8f3ffc5, 0xffffffff, 0xffffffff, 0x0}};
  // -172724806952306
  s21_decimal dec_2 = {{0xa0c32572, 0x9d17, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_13) {
  // 520216489360.1
  s21_decimal dec_1 = {{0x3930c7a1, 0x4bb, 0x0, 0x10000}};
  // -79228162514264337591541503512
  s21_decimal dec_2 = {{0x88a51618, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_14) {
  // 34601402606312382054426171975
  s21_decimal dec_1 = {{0x6b3f5a47, 0xd7294dc6, 0x6fcd9c01, 0x0}};
  // -79228162514264337592559733782
  s21_decimal dec_2 = {{0xc5560c16, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_15) {
  // 4067944126420186612429831748
  s21_decimal dec_1 = {{0x81793e44, 0xf88126b5, 0xd24ecac, 0x0}};
  // -79228162514264337592520644101
  s21_decimal dec_2 = {{0xc3019605, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_16) {
  // -79228162514264337591698424635
  s21_decimal dec_1 = {{0x91ff833b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 60801816540062508239175.805850
  s21_decimal dec_2 = {{0x658beb9a, 0x30a69e5f, 0xc4761577, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_17) {
  // -79228162514264337593039190513
  s21_decimal dec_1 = {{0xe1e9f9f1, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9070444872059482250299477
  s21_decimal dec_2 = {{0x68ba4855, 0xcd41c586, 0x780bd, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_18) {
  // -79228162514264337592868003882
  s21_decimal dec_1 = {{0xd7b5e02a, 0xffffffff, 0xffffffff, 0x80000000}};
  // 276852606762.7
  s21_decimal dec_2 = {{0x990347ab, 0x284, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_19) {
  // -79228162514264337592891778101
  s21_decimal dec_1 = {{0xd920a435, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1479987325447516236.96
  s21_decimal dec_2 = {{0x59f6de10, 0x5e51f1e, 0x8, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_20) {
  // -79228162514264337592099555018
  s21_decimal dec_1 = {{0xa9e846ca, 0xffffffff, 0xffffffff, 0x80000000}};
  // 21341689011382184479.0612585
  s21_decimal dec_2 = {{0xd149269, 0xcb9a7032, 0xb088c8, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_21) {
  // 48658725998036725034686119466
  s21_decimal dec_1 = {{0xd3cc7e2a, 0xdf56a12a, 0x9d398e05, 0x0}};
  // -46152310072791383662752555703
  s21_decimal dec_2 = {{0x8549e2b7, 0x4ea8176b, 0x95204bce, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_22) {
  // -43125475529.721
  s21_decimal dec_1 = {{0xeea653f9, 0x2738, 0x0, 0x80030000}};
  // 79228162514264337593142250106
  s21_decimal dec_2 = {{0xe80e8a7a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_23) {
  // -79228162514264337591756796255
  s21_decimal dec_1 = {{0x957a315f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3383246028123891198449
  s21_decimal dec_2 = {{0x7bc669f1, 0x67f8715f, 0xb7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_24) {
  // -79228162514264337593275880535
  s21_decimal dec_1 = {{0xf0059457, 0xffffffff, 0xffffffff, 0x80000000}};
  // 373243528086711166673847
  s21_decimal dec_2 = {{0x20bda3b7, 0x927bc1e6, 0x4f09, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_25) {
  // 79228162514264337593139679471
  s21_decimal dec_1 = {{0xe7e750ef, 0xffffffff, 0xffffffff, 0x0}};
  // -6514253848391792146737110
  s21_decimal dec_2 = {{0x3a5767d6, 0x68a25c3e, 0x56372, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_26) {
  // -41386052117
  s21_decimal dec_1 = {{0xa2cd0a15, 0x9, 0x0, 0x80000000}};
  // 79228162514264337591865201165
  s21_decimal dec_2 = {{0x9bf0520d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_27) {
  // -241166567719932525700563
  s21_decimal dec_1 = {{0x6d9265d3, 0xaa74020a, 0x3311, 0x80000000}};
  // 79228162514264337592957580619
  s21_decimal dec_2 = {{0xdd0cb54b, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_28) {
  // -79228162514264337593100450428
  s21_decimal dec_1 = {{0xe590ba7c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 70883147823626962362463408.47
  s21_decimal dec_2 = {{0x368d94ef, 0x509fbf24, 0x16e7510a, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_29) {
  // 9239226037308463158596
  s21_decimal dec_1 = {{0x1eea9544, 0xdc04b96a, 0x1f4, 0x0}};
  // -79228162514264337593454158159
  s21_decimal dec_2 = {{0xfaa5e14f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_30) {
  // -995037879663
  s21_decimal dec_1 = {{0xace11d6f, 0xe7, 0x0, 0x80000000}};
  // 79228162514264337593279246303
  s21_decimal dec_2 = {{0xf038efdf, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_31) {
  // -841243774013
  s21_decimal dec_1 = {{0xde094c3d, 0xc3, 0x0, 0x80000000}};
  // 79228162514264337591440217222
  s21_decimal dec_2 = {{0x829b9486, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_32) {
  // -86665026181
  s21_decimal dec_1 = {{0x2da35a85, 0x14, 0x0, 0x80000000}};
  // 79228162514264337591621769210
  s21_decimal dec_2 = {{0x8d6dd7fa, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_33) {
  // -131614241846565819
  s21_decimal dec_1 = {{0xa4a59bbb, 0x1d39674, 0x0, 0x80000000}};
  // 79228162514264337593180541121
  s21_decimal dec_2 = {{0xea56d0c1, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_34) {
  // 79228162514264337592199530973
  s21_decimal dec_1 = {{0xafddc9dd, 0xffffffff, 0xffffffff, 0x0}};
  // -4773429762
  s21_decimal dec_2 = {{0x1c84c202, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_35) {
  // -79228162514264337592009102260
  s21_decimal dec_1 = {{0xa48413b4, 0xffffffff, 0xffffffff, 0x80000000}};
  // 332955190067.8294839826811
  s21_decimal dec_2 = {{0x63b1197b, 0x5ec5d0e4, 0x2c10f, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_36) {
  // -79228162514264337591681732362
  s21_decimal dec_1 = {{0x9100cf0a, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2184135025971745634218783.6273
  s21_decimal dec_2 = {{0x9be10371, 0x148314ab, 0x4692bdd2, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_37) {
  // 6489109775758442073319
  s21_decimal dec_1 = {{0x74a78ce7, 0xc67d1046, 0x15f, 0x0}};
  // -79228162514264337593242598211
  s21_decimal dec_2 = {{0xee09bb43, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_38) {
  // 79228162514264337592081105639
  s21_decimal dec_1 = {{0xa8cec2e7, 0xffffffff, 0xffffffff, 0x0}};
  // -61197117465.4763120213
  s21_decimal dec_2 = {{0x7bb0b655, 0x2cce5cfc, 0x21, 0x800a0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_39) {
  // 91391915991996
  s21_decimal dec_1 = {{0xd6b023bc, 0x531e, 0x0, 0x0}};
  // -79228162514264337592578016784
  s21_decimal dec_2 = {{0xc66d0610, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_40) {
  // 79228162514264337591490994340
  s21_decimal dec_1 = {{0x85a260a4, 0xffffffff, 0xffffffff, 0x0}};
  // -8273180016293805156
  s21_decimal dec_2 = {{0x420d7c64, 0x72d03d64, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_41) {
  // 41526026021570980681564589340
  s21_decimal dec_1 = {{0xe7b88d1c, 0x5d24c4be, 0x862d860d, 0x0}};
  // -47307792896333314458766869099
  s21_decimal dec_2 = {{0x414d026b, 0xaf5888d5, 0x98dc16cf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_42) {
  // -1847401992590
  s21_decimal dec_1 = {{0x21bd518e, 0x1ae, 0x0, 0x80000000}};
  // 79228162514264337592387357479
  s21_decimal dec_2 = {{0xbb0fcb27, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_43) {
  // -7395152045984
  s21_decimal dec_1 = {{0xd16927a0, 0x6b9, 0x0, 0x80000000}};
  // 79228162514264337592658404530
  s21_decimal dec_2 = {{0xcb37a4b2, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_44) {
  // 79228162514264337591731388310
  s21_decimal dec_1 = {{0x93f67f96, 0xffffffff, 0xffffffff, 0x0}};
  // -42690228856589048778776009529
  s21_decimal dec_2 = {{0x4d325b39, 0x82c7c82a, 0x89f08797, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_45) {
  // -79228162514264337592607892843
  s21_decimal dec_1 = {{0xc834e56b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3245337367
  s21_decimal dec_2 = {{0xc16feb17, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_46) {
  // -79228162514264337591645305830
  s21_decimal dec_1 = {{0x8ed4fbe6, 0xffffffff, 0xffffffff, 0x80000000}};
  // 32306138573560076169663
  s21_decimal dec_2 = {{0x1921f1bf, 0x51bc6b65, 0x6d7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_47) {
  // -78479040904682542067489568250
  s21_decimal dec_1 = {{0xb619f5fa, 0x2bf9b4e5, 0xfd945754, 0x80000000}};
  // 56927521241628203313031005847
  s21_decimal dec_2 = {{0x1fb3c697, 0x382a9835, 0xb7f15786, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_48) {
  // -79228162514264337592837344191
  s21_decimal dec_1 = {{0xd5e20bbf, 0xffffffff, 0xffffffff, 0x80000000}};
  // 794912282444167
  s21_decimal dec_2 = {{0xf0390187, 0x2d2f7, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_49) {
  // -79228162514264337592413447307
  s21_decimal dec_1 = {{0xbc9de48b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 698149283967620610530
  s21_decimal dec_2 = {{0xab57f9e2, 0xd8c482d0, 0x25, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_50) {
  // -79228162514264337592075198495
  s21_decimal dec_1 = {{0xa874a01f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9439251770957004
  s21_decimal dec_2 = {{0x10c0dccc, 0x2188f3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_51) {
  // -142387828895.705458704785191
  s21_decimal dec_1 = {{0xbaca1f27, 0xabd47a5e, 0x75c7cb, 0x800f0000}};
  // 79228162514264337593431221680
  s21_decimal dec_2 = {{0xf947e5b0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_52) {
  // -4867085205
  s21_decimal dec_1 = {{0x2219d395, 0x1, 0x0, 0x80000000}};
  // 79228162514264337591904460748
  s21_decimal dec_2 = {{0x9e475fcc, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_53) {
  // -7020471763229
  s21_decimal dec_1 = {{0x94b9c11d, 0x662, 0x0, 0x80000000}};
  // 79228162514264337592644567505
  s21_decimal dec_2 = {{0xca6481d1, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_54) {
  // 9367908715646
  s21_decimal dec_1 = {{0x22df0c7e, 0x885, 0x0, 0x0}};
  // -79228162514264337593148613214
  s21_decimal dec_2 = {{0xe86fa25e, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_55) {
  // 83778325164
  s21_decimal dec_1 = {{0x8193caac, 0x13, 0x0, 0x0}};
  // -79228162514264337593333812919
  s21_decimal dec_2 = {{0xf3798eb7, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_56) {
  // -79228162514264337591813488494
  s21_decimal dec_1 = {{0x98db3f6e, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2216974535.267
  s21_decimal dec_2 = {{0x2dfaca63, 0x204, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_57) {
  // 68799363728.770854279
  s21_decimal dec_1 = {{0xf247ed87, 0xbac870cb, 0x3, 0x90000}};
  // -79228162514264337591557670163
  s21_decimal dec_2 = {{0x899bc513, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_58) {
  // -79228162514264337591729984320
  s21_decimal dec_1 = {{0x93e11340, 0xffffffff, 0xffffffff, 0x80000000}};
  // 14820989470382248732912821
  s21_decimal dec_2 = {{0x5033ecb5, 0x72f8c903, 0xc4277, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_59) {
  // -79228162514264337591971355721
  s21_decimal dec_1 = {{0xa2441c49, 0xffffffff, 0xffffffff, 0x80000000}};
  // 47187389256592
  s21_decimal dec_2 = {{0xab931390, 0x2aea, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_60) {
  // -79228162514264337592693322379
  s21_decimal dec_1 = {{0xcd4c728b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 80619519200328
  s21_decimal dec_2 = {{0xb1cdcc48, 0x4952, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_61) {
  // -79228162514264337592110960857
  s21_decimal dec_1 = {{0xaa9650d9, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1457822369790140
  s21_decimal dec_2 = {{0xb87f38bc, 0x52de1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_62) {
  // -79228162514264337592966100807
  s21_decimal dec_1 = {{0xdd8eb747, 0xffffffff, 0xffffffff, 0x80000000}};
  // 19004245136876593403491894207
  s21_decimal dec_2 = {{0x13d5c3bf, 0x31435f19, 0x3d67f171, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_63) {
  // -9870877047
  s21_decimal dec_1 = {{0x4c59a177, 0x2, 0x0, 0x80000000}};
  // 79228162514264337592395891089
  s21_decimal dec_2 = {{0xbb920191, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_64) {
  // -6990407063071
  s21_decimal dec_1 = {{0x94bad61f, 0x65b, 0x0, 0x80000000}};
  // 79228162514264337593154002896
  s21_decimal dec_2 = {{0xe8c1dfd0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_65) {
  // -7181425819112915223085371
  s21_decimal dec_1 = {{0xf9f2813b, 0xdfacda81, 0x5f0b9, 0x80000000}};
  // 79228162514264337593129911117
  s21_decimal dec_2 = {{0xe752434d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_66) {
  // -79228162514264337592771560048
  s21_decimal dec_1 = {{0xd1f64270, 0xffffffff, 0xffffffff, 0x80000000}};
  // 68267350319830628160213394
  s21_decimal dec_2 = {{0xd35f9192, 0x79f0ba5f, 0x38782c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_67) {
  // 79228162514264337592667345107
  s21_decimal dec_1 = {{0xcbc010d3, 0xffffffff, 0xffffffff, 0x0}};
  // -2441341916283
  s21_decimal dec_2 = {{0x6b51547b, 0x238, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_68) {
  // -5932131981385504
  s21_decimal dec_1 = {{0x1b82df20, 0x15133e, 0x0, 0x80000000}};
  // 79228162514264337591503116641
  s21_decimal dec_2 = {{0x865b5961, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_69) {
  // 78001394473
  s21_decimal dec_1 = {{0x293ed329, 0x12, 0x0, 0x0}};
  // -79228162514264337592024901894
  s21_decimal dec_2 = {{0xa5752906, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_70) {
  // -79228162514264337591607192039
  s21_decimal dec_1 = {{0x8c8f69e7, 0xffffffff, 0xffffffff, 0x80000000}};
  // 809315014979780
  s21_decimal dec_2 = {{0x55fab0c4, 0x2e011, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_71) {
  // 17564029874569691833.292768685
  s21_decimal dec_1 = {{0xa6345ad, 0x6164640a, 0x38c09fff, 0x90000}};
  // -79228162514264337592454185495
  s21_decimal dec_2 = {{0xbf0b8217, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_72) {
  // -17891018622769736
  s21_decimal dec_1 = {{0x61ae1a48, 0x3f8fc9, 0x0, 0x80000000}};
  // 79228162514264337593073090266
  s21_decimal dec_2 = {{0xe3ef3eda, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_73) {
  // 6417803218858479910105
  s21_decimal dec_1 = {{0xb23afcd9, 0xe8e94892, 0x15b, 0x0}};
  // -79228162514264337592347499310
  s21_decimal dec_2 = {{0xb8af9b2e, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_74) {
  // 79228162514264337592107753249
  s21_decimal dec_1 = {{0xaa655f21, 0xffffffff, 0xffffffff, 0x0}};
  // -550149087460714239986888
  s21_decimal dec_2 = {{0x1d078cc8, 0xa44c66bb, 0x747f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_75) {
  // -45752297946951
  s21_decimal dec_1 = {{0x89777f47, 0x299c, 0x0, 0x80000000}};
  // 79228162514264337591563678351
  s21_decimal dec_2 = {{0x89f7728f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_76) {
  // -79228162514264337592839982512
  s21_decimal dec_1 = {{0xd60a4db0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 4686954752026656062.0240294
  s21_decimal dec_2 = {{0x7c149da6, 0x432270ec, 0x26c503, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_77) {
  // 56661047016501736714940065829
  s21_decimal dec_1 = {{0x13662825, 0x879c0854, 0xb714eb69, 0x0}};
  // -36160884331548874265989029663
  s21_decimal dec_2 = {{0x116d1f1f, 0x902864e0, 0x74d7951b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_78) {
  // -17412937861424721632257
  s21_decimal dec_1 = {{0x5aa31c01, 0xf50e8744, 0x3af, 0x80000000}};
  // 79228162514264337592287869445
  s21_decimal dec_2 = {{0xb521ba05, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_79) {
  // -5878776622716146720970428.045
  s21_decimal dec_1 = {{0x3e78ce8d, 0x4b984420, 0x12fecf5f, 0x80030000}};
  // 79228162514264337592600820563
  s21_decimal dec_2 = {{0xc7c8fb53, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_80) {
  // 2603496868362531120233104
  s21_decimal dec_1 = {{0x24e3a90, 0xd918f222, 0x2274f, 0x0}};
  // -79228162514264337592015605606
  s21_decimal dec_2 = {{0xa4e74f66, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_81) {
  // 79228162514264337593020420947
  s21_decimal dec_1 = {{0xe0cb9353, 0xffffffff, 0xffffffff, 0x0}};
  // -73961766775938.66825
  s21_decimal dec_2 = {{0x6c02e249, 0x66a47f80, 0x0, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_82) {
  // 79228162514264337591683053384
  s21_decimal dec_1 = {{0x9114f748, 0xffffffff, 0xffffffff, 0x0}};
  // -79082998566067846
  s21_decimal dec_2 = {{0x754d9e86, 0x118f591, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_83) {
  // -79228162514264337593431127050
  s21_decimal dec_1 = {{0xf946740a, 0xffffffff, 0xffffffff, 0x80000000}};
  // 68120240727
  s21_decimal dec_2 = {{0xdc486257, 0xf, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_84) {
  // 79228162514264337592588773764
  s21_decimal dec_1 = {{0xc7112984, 0xffffffff, 0xffffffff, 0x0}};
  // -916661717379058998314926
  s21_decimal dec_2 = {{0xd69a07ae, 0x54ce2a53, 0xc21c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_85) {
  // -79228162514264337591881202038
  s21_decimal dec_1 = {{0x9ce47976, 0xffffffff, 0xffffffff, 0x80000000}};
  // 985624445551552062.8472971
  s21_decimal dec_2 = {{0x780cbc8b, 0x1522b62a, 0x82724, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_86) {
  // -19291564280
  s21_decimal dec_1 = {{0x7ddde8f8, 0x4, 0x0, 0x80000000}};
  // 79228162514264337592501687488
  s21_decimal dec_2 = {{0xc1e054c0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_87) {
  // -184588525179647356
  s21_decimal dec_1 = {{0x20f2357c, 0x28fca49, 0x0, 0x80000000}};
  // 79228162514264337592557492695
  s21_decimal dec_2 = {{0xc533d9d7, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_88) {
  // 79228162514264337591509069997
  s21_decimal dec_1 = {{0x86b630ad, 0xffffffff, 0xffffffff, 0x0}};
  // -36656994137437800643952876317
  s21_decimal dec_2 = {{0xe7039b1d, 0x7a90b49, 0x7671f472, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_89) {
  // -79228162514264337593350720778
  s21_decimal dec_1 = {{0xf47b8d0a, 0xffffffff, 0xffffffff, 0x80000000}};
  // 914645813710386
  s21_decimal dec_2 = {{0x92d24e32, 0x33fdd, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_90) {
  // -79228162514264337593450365904
  s21_decimal dec_1 = {{0xfa6c03d0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 731359940085214559927940820
  s21_decimal dec_2 = {{0x66c236d4, 0xcba374e1, 0x25cf77d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_91) {
  // 79228162514264337591623647202
  s21_decimal dec_1 = {{0x8d8a7fe2, 0xffffffff, 0xffffffff, 0x0}};
  // -2700391144022019930
  s21_decimal dec_2 = {{0x2e0b0f5a, 0x2579b770, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_92) {
  // 79228162514264337591788064721
  s21_decimal dec_1 = {{0x97574fd1, 0xffffffff, 0xffffffff, 0x0}};
  // -146562865730538
  s21_decimal dec_2 = {{0x538c93ea, 0x854c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_93) {
  // 1627485834440285025
  s21_decimal dec_1 = {{0x5ecb1b61, 0x1695fdbe, 0x0, 0x0}};
  // -79228162514264337593431084757
  s21_decimal dec_2 = {{0xf945ced5, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_94) {
  // -74263882482753153368068433505
  s21_decimal dec_1 = {{0x19a3a661, 0x401e08b5, 0xeff5a4d0, 0x80000000}};
  // 78343609226265339311499232847
  s21_decimal dec_2 = {{0x76c3c64f, 0x2c71fff4, 0xfd24508e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_95) {
  // -6640359417.968986373363
  s21_decimal dec_1 = {{0xc1133cf3, 0xf97fbc82, 0x167, 0x800c0000}};
  // 79228162514264337593357387842
  s21_decimal dec_2 = {{0xf4e14842, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_96) {
  // 26526945663
  s21_decimal dec_1 = {{0x2d21117f, 0x6, 0x0, 0x0}};
  // -79228162514264337592176654520
  s21_decimal dec_2 = {{0xae80b8b8, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_97) {
  // 58075857441.5261729
  s21_decimal dec_1 = {{0xb048b021, 0x80f44d8, 0x0, 0x70000}};
  // -79228162514264337592847113366
  s21_decimal dec_2 = {{0xd6771c96, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_98) {
  // -79228162514264337592605129712
  s21_decimal dec_1 = {{0xc80abbf0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 27309145955270
  s21_decimal dec_2 = {{0x67f19bc6, 0x18d6, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_99) {
  // 194653415389720
  s21_decimal dec_1 = {{0x47adba18, 0xb109, 0x0, 0x0}};
  // -79228162514264337591486462402
  s21_decimal dec_2 = {{0x855d39c2, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_100) {
  // 94676438902.13
  s21_decimal dec_1 = {{0x5b8d0a25, 0x89c, 0x0, 0x20000}};
  // -79228162514264337592469539617
  s21_decimal dec_2 = {{0xbff5cb21, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_101) {
  // 178846818480.4163951653880730
  s21_decimal dec_1 = {{0x3fe1039a, 0x91bd4166, 0x5c762de, 0x100000}};
  // -79228162514264337592248436735
  s21_decimal dec_2 = {{0xb2c807ff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_102) {
  // 346705582185831531323081
  s21_decimal dec_1 = {{0xc0549ec9, 0xf280591c, 0x496a, 0x0}};
  // -79228162514264337592148453728
  s21_decimal dec_2 = {{0xacd26960, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_103) {
  // -5339444073437806494641907538
  s21_decimal dec_1 = {{0x85816752, 0x36dcc2f5, 0x1140af43, 0x80000000}};
  // 73937459582322805840940696392
  s21_decimal dec_2 = {{0xdfe90348, 0x5c556788, 0xeee7a213, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_104) {
  // 79228162514264337593483140689
  s21_decimal dec_1 = {{0xfc601e51, 0xffffffff, 0xffffffff, 0x0}};
  // -72073393624973
  s21_decimal dec_2 = {{0xe506578d, 0x418c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_105) {
  // -181869232627
  s21_decimal dec_1 = {{0x584041f3, 0x2a, 0x0, 0x80000000}};
  // 79228162514264337592414441562
  s21_decimal dec_2 = {{0xbcad105a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_106) {
  // -155068698044521358590
  s21_decimal dec_1 = {{0x4601a4fe, 0x6802af48, 0x8, 0x80000000}};
  // 79228162514264337593436140548
  s21_decimal dec_2 = {{0xf992f404, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_107) {
  // 79228162514264337593242166013
  s21_decimal dec_1 = {{0xee0322fd, 0xffffffff, 0xffffffff, 0x0}};
  // -52331111244508854
  s21_decimal dec_2 = {{0x506e2eb6, 0xb9eade, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_108) {
  // 5230841148183039665.9
  s21_decimal dec_1 = {{0xd37712f3, 0xd5eccf19, 0x2, 0x10000}};
  // -79228162514264337593079217561
  s21_decimal dec_2 = {{0xe44cbd99, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_109) {
  // 6458537387.0887627999346676107
  s21_decimal dec_1 = {{0x8fb7d18b, 0x148aef0d, 0xd0afc4e5, 0x130000}};
  // -79228162514264337591700300800
  s21_decimal dec_2 = {{0x921c2400, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_110) {
  // 79228162514264337591604442320
  s21_decimal dec_1 = {{0x8c6574d0, 0xffffffff, 0xffffffff, 0x0}};
  // -292461942900901729
  s21_decimal dec_2 = {{0x68edc761, 0x40f0896, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_111) {
  // -79228162514264337591819223883
  s21_decimal dec_1 = {{0x9932c34b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9014621414875
  s21_decimal dec_2 = {{0xe14ea5db, 0x832, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_112) {
  // 79228162514264337592409530791
  s21_decimal dec_1 = {{0xbc6221a7, 0xffffffff, 0xffffffff, 0x0}};
  // -6579013078
  s21_decimal dec_2 = {{0x8823c5d6, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_113) {
  // -193927888194870525285
  s21_decimal dec_1 = {{0xd8ed3d65, 0x834a42d6, 0xa, 0x80000000}};
  // 79228162514264337592864661644
  s21_decimal dec_2 = {{0xd782e08c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_114) {
  // -401776472613
  s21_decimal dec_1 = {{0x8bbe7225, 0x5d, 0x0, 0x80000000}};
  // 79228162514264337592861944919
  s21_decimal dec_2 = {{0xd7596c57, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_115) {
  // 739629105409715678016625385
  s21_decimal dec_1 = {{0x713adae9, 0x255c1310, 0x263ce8e, 0x0}};
  // -79228162514264337593289997450
  s21_decimal dec_2 = {{0xf0dcfc8a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_116) {
  // -79228162514264337593240585042
  s21_decimal dec_1 = {{0xedeb0352, 0xffffffff, 0xffffffff, 0x80000000}};
  // 914022689528962
  s21_decimal dec_2 = {{0x7db9dc82, 0x33f4c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_117) {
  // -79228162514264337593380290532
  s21_decimal dec_1 = {{0xf63ebfe4, 0xffffffff, 0xffffffff, 0x80000000}};
  // 4259755424674509905.6634662
  s21_decimal dec_2 = {{0xededb26, 0xaf7db91, 0x233c62, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_118) {
  // -79228162514264337593314646787
  s21_decimal dec_1 = {{0xf2551b03, 0xffffffff, 0xffffffff, 0x80000000}};
  // 4387446379
  s21_decimal dec_2 = {{0x5831e6b, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_119) {
  // -6319737745704148814.70
  s21_decimal dec_1 = {{0x985f3abe, 0x4265dfa1, 0x22, 0x80020000}};
  // 79228162514264337592725639955
  s21_decimal dec_2 = {{0xcf399313, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_120) {
  // -882413676.311
  s21_decimal dec_1 = {{0x73f42717, 0xcd, 0x0, 0x80030000}};
  // 79228162514264337592741722531
  s21_decimal dec_2 = {{0xd02ef9a3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_121) {
  // -79228162514264337591541624845
  s21_decimal dec_1 = {{0x88a6f00d, 0xffffffff, 0xffffffff, 0x80000000}};
  // 400603510016.0664716785
  s21_decimal dec_2 = {{0x66d2c5f1, 0x2ae7b2b6, 0xd9, 0xa0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_122) {
  // -79228162514264337593140263940
  s21_decimal dec_1 = {{0xe7f03c04, 0xffffffff, 0xffffffff, 0x80000000}};
  // 546032594.3306759816128674868
  s21_decimal dec_2 = {{0x7e32bc34, 0x82b72c94, 0x11a4acfe, 0x130000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_123) {
  // -1921556328922.278095622
  s21_decimal dec_1 = {{0x240d6b06, 0x2af37450, 0x68, 0x80090000}};
  // 79228162514264337591971329137
  s21_decimal dec_2 = {{0xa243b471, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_124) {
  // -33812233254229676938450
  s21_decimal dec_1 = {{0x121054d2, 0xf6ff97d5, 0x728, 0x80000000}};
  // 79228162514264337592067443583
  s21_decimal dec_2 = {{0xa7fe4b7f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_125) {
  // 481315129780505
  s21_decimal dec_1 = {{0xe955e919, 0x1b5c0, 0x0, 0x0}};
  // -79228162514264337591999309578
  s21_decimal dec_2 = {{0xa3eea70a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_126) {
  // -79228162514264337593232603147
  s21_decimal dec_1 = {{0xed71380b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 33015385989573161.5
  s21_decimal dec_2 = {{0xb44f259f, 0x494f12f, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_127) {
  // -55292795662255857762882878199
  s21_decimal dec_1 = {{0x5120faf7, 0xfda16376, 0xb2a920ea, 0x80000000}};
  // 79228162514264337591684481619
  s21_decimal dec_2 = {{0x912ac253, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_128) {
  // 79228162514264337591824517539
  s21_decimal dec_1 = {{0x998389a3, 0xffffffff, 0xffffffff, 0x0}};
  // -74629319943
  s21_decimal dec_2 = {{0x60410d07, 0x11, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_129) {
  // 79228162514264337592302867295
  s21_decimal dec_1 = {{0xb606935f, 0xffffffff, 0xffffffff, 0x0}};
  // -399572749693459758
  s21_decimal dec_2 = {{0x7f679d2e, 0x58b914c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_130) {
  // 79228162514264337592668834412
  s21_decimal dec_1 = {{0xcbd6ca6c, 0xffffffff, 0xffffffff, 0x0}};
  // -4839619340615533
  s21_decimal dec_2 = {{0xafa53f6d, 0x11319b, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_131) {
  // -28613708536.66157319017655
  s21_decimal dec_1 = {{0xd06dd4b7, 0x398bf0d9, 0x25deb, 0x800e0000}};
  // 79228162514264337592688106995
  s21_decimal dec_2 = {{0xccfcddf3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_132) {
  // -79228162514264337592385888780
  s21_decimal dec_1 = {{0xbaf9620c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 83051583358994154
  s21_decimal dec_2 = {{0x9c2586ea, 0x1270ef9, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_133) {
  // -79228162514264337592705106266
  s21_decimal dec_1 = {{0xce00415a, 0xffffffff, 0xffffffff, 0x80000000}};
  // 105901918651350519528395
  s21_decimal dec_2 = {{0xaeba3bcb, 0xf45b00fd, 0x166c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_134) {
  // 79228162514264337591643655450
  s21_decimal dec_1 = {{0x8ebbcd1a, 0xffffffff, 0xffffffff, 0x0}};
  // -3242494357349717
  s21_decimal dec_2 = {{0xc5b2555, 0xb8508, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_135) {
  // 5761628334027781945
  s21_decimal dec_1 = {{0x818d3739, 0x4ff56a71, 0x0, 0x0}};
  // -79228162514264337591822110192
  s21_decimal dec_2 = {{0x995ecdf0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_136) {
  // 4545486641363386043855329
  s21_decimal dec_1 = {{0x3b8df1e1, 0x5317939f, 0x3c28b, 0x0}};
  // -79228162514264337591859057486
  s21_decimal dec_2 = {{0x9b92934e, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_137) {
  // -79228162514264337592558474048
  s21_decimal dec_1 = {{0xc542d340, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3624161462
  s21_decimal dec_2 = {{0xd80450b6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_138) {
  // -79228162514264337593499711598
  s21_decimal dec_1 = {{0xfd5cf86e, 0xffffffff, 0xffffffff, 0x80000000}};
  // 630320424489717728738849924
  s21_decimal dec_2 = {{0xb950b484, 0xadfff55b, 0x209638a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_139) {
  // -79228162514264337592585031552
  s21_decimal dec_1 = {{0xc6d80f80, 0xffffffff, 0xffffffff, 0x80000000}};
  // 104128501509387361
  s21_decimal dec_2 = {{0x775f461, 0x171f052, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_140) {
  // -2955714158655
  s21_decimal dec_1 = {{0x2e4ae03f, 0x2b0, 0x0, 0x80000000}};
  // 79228162514264337592617570175
  s21_decimal dec_2 = {{0xc8c88f7f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_141) {
  // 56784609342021515415506864182
  s21_decimal dec_1 = {{0x14b34836, 0x9e368cf0, 0xb77b20c0, 0x0}};
  // -37804475351132316197821068392
  s21_decimal dec_2 = {{0x4223b468, 0x44c42673, 0x7a27210b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_142) {
  // -52346906700311462591092869741
  s21_decimal dec_1 = {{0xe099ca6d, 0x5e6220a1, 0xa92458aa, 0x80000000}};
  // 39284187670456358058815843015
  s21_decimal dec_2 = {{0x3cb2eac7, 0xd4f449dc, 0x7eef1e50, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_143) {
  // -79228162514264337592613724076
  s21_decimal dec_1 = {{0xc88ddfac, 0xffffffff, 0xffffffff, 0x80000000}};
  // 976220148488262303054958
  s21_decimal dec_2 = {{0x4bd37c6e, 0x130e0e, 0xceb9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_144) {
  // -79228162514264337591988136844
  s21_decimal dec_1 = {{0xa3442b8c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3992803748
  s21_decimal dec_2 = {{0xedfd59a4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_145) {
  // 833428234560002.752547818889
  s21_decimal dec_1 = {{0x68c28d89, 0x2043dfc9, 0x2b1654b, 0xc0000}};
  // -79228162514264337591836316876
  s21_decimal dec_2 = {{0x9a3794cc, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_146) {
  // -79228162514264337592070440386
  s21_decimal dec_1 = {{0xa82c05c2, 0xffffffff, 0xffffffff, 0x80000000}};
  // 5278378815558.95331017
  s21_decimal dec_2 = {{0x8dda28c9, 0x9d38dcab, 0x1c, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_147) {
  // -588325633769495903.37830
  s21_decimal dec_1 = {{0x4039a926, 0x51d4ab0e, 0xc75, 0x80050000}};
  // 79228162514264337591596517803
  s21_decimal dec_2 = {{0x8bec89ab, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_148) {
  // 10835637692622
  s21_decimal dec_1 = {{0xde55e8ce, 0x9da, 0x0, 0x0}};
  // -79228162514264337591610344967
  s21_decimal dec_2 = {{0x8cbf8607, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_149) {
  // -79228162514264337593280806818
  s21_decimal dec_1 = {{0xf050bfa2, 0xffffffff, 0xffffffff, 0x80000000}};
  // 489519614673989.0687658948
  s21_decimal dec_2 = {{0x30c14bc4, 0x1d66ef2f, 0x40c99, 0xa0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_150) {
  // 79228162514264337592067914939
  s21_decimal dec_1 = {{0xa8057cbb, 0xffffffff, 0xffffffff, 0x0}};
  // -714840407436953.9
  s21_decimal dec_2 = {{0x85905203, 0x19656f, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_151) {
  // -9085267688883.609113
  s21_decimal dec_1 = {{0xc53dde19, 0x7e155ad3, 0x0, 0x80060000}};
  // 79228162514264337593039008478
  s21_decimal dec_2 = {{0xe1e732de, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_152) {
  // -79228162514264337591500197462
  s21_decimal dec_1 = {{0x862ece56, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3673245312574.4373
  s21_decimal dec_2 = {{0xb449e6f5, 0x827ff8, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_153) {
  // 63454490416281081.2082579
  s21_decimal dec_1 = {{0x4252a993, 0xbf88d516, 0x865e, 0x70000}};
  // -79228162514264337591929470671
  s21_decimal dec_2 = {{0x9fc4fecf, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_154) {
  // 79228162514264337591736883703
  s21_decimal dec_1 = {{0x944a59f7, 0xffffffff, 0xffffffff, 0x0}};
  // -4480783439589885374478910
  s21_decimal dec_2 = {{0xdf75ba3e, 0xc1c992e0, 0x3b4d7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_155) {
  // 79228162514264337591463684286
  s21_decimal dec_1 = {{0x8401a8be, 0xffffffff, 0xffffffff, 0x0}};
  // -4098820489
  s21_decimal dec_2 = {{0xf44f0989, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_156) {
  // -868354090634.875
  s21_decimal dec_1 = {{0x711c8e7b, 0x315c3, 0x0, 0x80030000}};
  // 79228162514264337593527718925
  s21_decimal dec_2 = {{0xff08540d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_157) {
  // 79228162514264337592061057334
  s21_decimal dec_1 = {{0xa79cd936, 0xffffffff, 0xffffffff, 0x0}};
  // -5272574088083898611
  s21_decimal dec_2 = {{0xa42b80f3, 0x492bf232, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_158) {
  // 79228162514264337593049872374
  s21_decimal dec_1 = {{0xe28cf7f6, 0xffffffff, 0xffffffff, 0x0}};
  // -27031276211
  s21_decimal dec_2 = {{0x4b308ab3, 0x6, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_159) {
  // 79228162514264337592503122659
  s21_decimal dec_1 = {{0xc1f63ae3, 0xffffffff, 0xffffffff, 0x0}};
  // -3202719064667141
  s21_decimal dec_2 = {{0x242a3405, 0xb60db, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_160) {
  // 79228162514264337593539603389
  s21_decimal dec_1 = {{0xffbdabbd, 0xffffffff, 0xffffffff, 0x0}};
  // -32468227046371479
  s21_decimal dec_2 = {{0x3395f097, 0x7359ae, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_161) {
  // 56559243075
  s21_decimal dec_1 = {{0x2b318f43, 0xd, 0x0, 0x0}};
  // -79228162514264337592464055149
  s21_decimal dec_2 = {{0xbfa21b6d, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_162) {
  // 45323877827279
  s21_decimal dec_1 = {{0xc9a342cf, 0x2938, 0x0, 0x0}};
  // -79228162514264337592213881068
  s21_decimal dec_2 = {{0xb0b8c0ec, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_163) {
  // 2039669913542
  s21_decimal dec_1 = {{0xe5ccf7c6, 0x1da, 0x0, 0x0}};
  // -79228162514264337593518829286
  s21_decimal dec_2 = {{0xfe80aee6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_164) {
  // -48025632404638429567840855
  s21_decimal dec_1 = {{0x2d5cf257, 0xbfd900e8, 0x27b9d2, 0x80000000}};
  // 79228162514264337592838655532
  s21_decimal dec_2 = {{0xd5f60e2c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_165) {
  // -9798768739675743
  s21_decimal dec_1 = {{0xa1f6ee5f, 0x22cfed, 0x0, 0x80000000}};
  // 79228162514264337592160613933
  s21_decimal dec_2 = {{0xad8bf62d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_166) {
  // -5830171261092721
  s21_decimal dec_1 = {{0x86ff4371, 0x14b682, 0x0, 0x80000000}};
  // 79228162514264337592340747341
  s21_decimal dec_2 = {{0xb848944d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_sub_cases(void) {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, invalid_dec_s21_sub_1);
  tcase_add_test(tc, invalid_dec_s21_sub_2);
  tcase_add_test(tc, invalid_dec_s21_sub_3);
  tcase_add_test(tc, invalid_dec_s21_sub_4);
  tcase_add_test(tc, invalid_dec_s21_sub_5);
  tcase_add_test(tc, invalid_dec_s21_sub_6);
  tcase_add_test(tc, invalid_dec_s21_sub_7);
  tcase_add_test(tc, invalid_dec_s21_sub_8);
  tcase_add_test(tc, invalid_dec_s21_sub_9);
  tcase_add_test(tc, invalid_dec_s21_sub_10);
  tcase_add_test(tc, invalid_dec_s21_sub_11);
  tcase_add_test(tc, invalid_dec_s21_sub_12);
  tcase_add_test(tc, invalid_dec_s21_sub_13);
  tcase_add_test(tc, invalid_dec_s21_sub_14);
  tcase_add_test(tc, invalid_dec_s21_sub_15);
  tcase_add_test(tc, invalid_dec_s21_sub_16);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);
  tcase_add_test(tc, s21_sub_21);
  tcase_add_test(tc, s21_sub_22);
  tcase_add_test(tc, s21_sub_23);
  tcase_add_test(tc, s21_sub_24);
  tcase_add_test(tc, s21_sub_25);
  tcase_add_test(tc, s21_sub_26);
  tcase_add_test(tc, s21_sub_27);
  tcase_add_test(tc, s21_sub_28);
  tcase_add_test(tc, s21_sub_29);
  tcase_add_test(tc, s21_sub_30);
  tcase_add_test(tc, s21_sub_31);
  tcase_add_test(tc, s21_sub_32);
  tcase_add_test(tc, s21_sub_33);
  tcase_add_test(tc, s21_sub_34);
  tcase_add_test(tc, s21_sub_35);
  tcase_add_test(tc, s21_sub_36);
  tcase_add_test(tc, s21_sub_37);
  tcase_add_test(tc, s21_sub_38);
  tcase_add_test(tc, s21_sub_39);
  tcase_add_test(tc, s21_sub_40);
  tcase_add_test(tc, s21_sub_41);
  tcase_add_test(tc, s21_sub_42);
  tcase_add_test(tc, s21_sub_43);
  tcase_add_test(tc, s21_sub_44);
  tcase_add_test(tc, s21_sub_45);
  tcase_add_test(tc, s21_sub_46);
  tcase_add_test(tc, s21_sub_47);
  tcase_add_test(tc, s21_sub_48);
  tcase_add_test(tc, s21_sub_49);
  tcase_add_test(tc, s21_sub_50);
  tcase_add_test(tc, s21_sub_51);
  tcase_add_test(tc, s21_sub_52);
  tcase_add_test(tc, s21_sub_53);
  tcase_add_test(tc, s21_sub_55);
  tcase_add_test(tc, s21_sub_56);
  tcase_add_test(tc, s21_sub_58);
  tcase_add_test(tc, s21_sub_59);
  tcase_add_test(tc, s21_sub_60);
  tcase_add_test(tc, s21_sub_61);
  tcase_add_test(tc, s21_sub_62);
  tcase_add_test(tc, s21_sub_63);
  tcase_add_test(tc, s21_sub_64);
  tcase_add_test(tc, s21_sub_65);
  tcase_add_test(tc, s21_sub_66);
  tcase_add_test(tc, s21_sub_67);
  tcase_add_test(tc, s21_sub_68);
  tcase_add_test(tc, s21_sub_69);
  tcase_add_test(tc, s21_sub_70);
  tcase_add_test(tc, s21_sub_71);
  tcase_add_test(tc, s21_sub_72);
  tcase_add_test(tc, s21_sub_73);
  tcase_add_test(tc, s21_sub_74);
  tcase_add_test(tc, s21_sub_75);
  tcase_add_test(tc, s21_sub_76);
  tcase_add_test(tc, s21_sub_77);
  tcase_add_test(tc, s21_sub_78);
  tcase_add_test(tc, s21_sub_80);
  tcase_add_test(tc, s21_sub_81);
  tcase_add_test(tc, s21_sub_82);
  tcase_add_test(tc, s21_sub_83);
  tcase_add_test(tc, s21_sub_84);
  tcase_add_test(tc, s21_sub_85);
  tcase_add_test(tc, s21_sub_86);
  tcase_add_test(tc, s21_sub_87);
  tcase_add_test(tc, s21_sub_88);
  tcase_add_test(tc, s21_sub_89);
  tcase_add_test(tc, s21_sub_90);
  tcase_add_test(tc, s21_sub_91);
  tcase_add_test(tc, s21_sub_92);
  tcase_add_test(tc, s21_sub_93);
  tcase_add_test(tc, s21_sub_94);
  tcase_add_test(tc, s21_sub_95);
  tcase_add_test(tc, s21_sub_96);
  tcase_add_test(tc, s21_sub_97);
  tcase_add_test(tc, s21_sub_98);
  tcase_add_test(tc, s21_sub_99);
  tcase_add_test(tc, s21_sub_100);
  tcase_add_test(tc, s21_sub_101);
  tcase_add_test(tc, s21_sub_102);
  tcase_add_test(tc, s21_sub_103);
  tcase_add_test(tc, s21_sub_104);
  tcase_add_test(tc, s21_sub_105);
  tcase_add_test(tc, s21_sub_106);
  tcase_add_test(tc, s21_sub_107);
  tcase_add_test(tc, s21_sub_108);
  tcase_add_test(tc, s21_sub_109);
  tcase_add_test(tc, s21_sub_110);
  tcase_add_test(tc, s21_sub_111);
  tcase_add_test(tc, s21_sub_112);
  tcase_add_test(tc, s21_sub_113);
  tcase_add_test(tc, s21_sub_114);
  tcase_add_test(tc, s21_sub_115);
  tcase_add_test(tc, s21_sub_117);
  tcase_add_test(tc, s21_sub_118);
  tcase_add_test(tc, s21_sub_119);
  tcase_add_test(tc, s21_sub_120);
  tcase_add_test(tc, s21_sub_121);
  tcase_add_test(tc, s21_sub_122);
  tcase_add_test(tc, s21_sub_123);
  tcase_add_test(tc, s21_sub_124);
  tcase_add_test(tc, s21_sub_125);
  tcase_add_test(tc, s21_sub_126);
  tcase_add_test(tc, s21_sub_127);
  tcase_add_test(tc, s21_sub_128);
  tcase_add_test(tc, s21_sub_129);
  tcase_add_test(tc, s21_sub_130);
  tcase_add_test(tc, s21_sub_131);
  tcase_add_test(tc, s21_sub_132);
  tcase_add_test(tc, s21_sub_133);
  tcase_add_test(tc, s21_sub_134);
  tcase_add_test(tc, s21_sub_135);
  tcase_add_test(tc, s21_sub_136);
  tcase_add_test(tc, s21_sub_137);
  tcase_add_test(tc, s21_sub_138);
  tcase_add_test(tc, s21_sub_139);
  tcase_add_test(tc, s21_sub_140);
  tcase_add_test(tc, s21_sub_141);
  tcase_add_test(tc, s21_sub_142);
  tcase_add_test(tc, s21_sub_143);
  tcase_add_test(tc, s21_sub_144);
  tcase_add_test(tc, s21_sub_145);
  tcase_add_test(tc, s21_sub_146);
  tcase_add_test(tc, s21_sub_147);
  tcase_add_test(tc, s21_sub_148);
  tcase_add_test(tc, s21_sub_149);
  tcase_add_test(tc, s21_sub_150);
  tcase_add_test(tc, s21_sub_151);
  tcase_add_test(tc, s21_sub_152);
  tcase_add_test(tc, s21_sub_153);
  tcase_add_test(tc, s21_sub_154);
  tcase_add_test(tc, s21_sub_155);
  tcase_add_test(tc, s21_sub_156);
  tcase_add_test(tc, s21_sub_157);
  tcase_add_test(tc, s21_sub_158);
  tcase_add_test(tc, s21_sub_159);
  tcase_add_test(tc, s21_sub_160);
  tcase_add_test(tc, s21_sub_161);
  tcase_add_test(tc, s21_sub_162);
  tcase_add_test(tc, s21_sub_163);
  tcase_add_test(tc, s21_sub_164);
  tcase_add_test(tc, s21_sub_165);
  tcase_add_test(tc, s21_sub_166);
  tcase_add_test(tc, s21_sub_168);
  tcase_add_test(tc, s21_sub_169);
  tcase_add_test(tc, s21_sub_170);
  tcase_add_test(tc, s21_sub_171);
  tcase_add_test(tc, s21_sub_172);
  tcase_add_test(tc, s21_sub_173);
  tcase_add_test(tc, s21_sub_174);
  tcase_add_test(tc, s21_sub_175);
  tcase_add_test(tc, s21_sub_176);
  tcase_add_test(tc, s21_sub_177);
  tcase_add_test(tc, s21_sub_179);
  tcase_add_test(tc, s21_sub_180);
  tcase_add_test(tc, s21_sub_181);
  tcase_add_test(tc, s21_sub_183);
  tcase_add_test(tc, s21_sub_184);
  tcase_add_test(tc, s21_sub_185);
  tcase_add_test(tc, s21_sub_186);
  tcase_add_test(tc, s21_sub_187);
  tcase_add_test(tc, s21_sub_188);
  tcase_add_test(tc, s21_sub_189);
  tcase_add_test(tc, s21_sub_190);
  tcase_add_test(tc, s21_sub_191);
  tcase_add_test(tc, s21_sub_192);
  tcase_add_test(tc, s21_sub_193);
  tcase_add_test(tc, s21_sub_194);
  tcase_add_test(tc, s21_sub_195);
  tcase_add_test(tc, s21_sub_196);
  tcase_add_test(tc, s21_sub_197);
  tcase_add_test(tc, s21_sub_198);
  tcase_add_test(tc, s21_sub_199);
  tcase_add_test(tc, s21_sub_200);
  tcase_add_test(tc, s21_sub_201);
  tcase_add_test(tc, s21_sub_202);
  tcase_add_test(tc, s21_sub_203);
  tcase_add_test(tc, s21_sub_204);
  tcase_add_test(tc, s21_sub_205);
  tcase_add_test(tc, s21_sub_206);
  tcase_add_test(tc, s21_sub_207);
  tcase_add_test(tc, s21_sub_208);
  tcase_add_test(tc, s21_sub_209);
  tcase_add_test(tc, s21_sub_210);
  tcase_add_test(tc, s21_sub_211);
  tcase_add_test(tc, s21_sub_212);
  tcase_add_test(tc, s21_sub_213);
  tcase_add_test(tc, s21_sub_214);
  tcase_add_test(tc, s21_sub_215);
  tcase_add_test(tc, s21_sub_216);
  tcase_add_test(tc, s21_sub_217);
  tcase_add_test(tc, s21_sub_218);
  tcase_add_test(tc, s21_sub_221);
  tcase_add_test(tc, s21_sub_222);
  tcase_add_test(tc, s21_sub_223);
  tcase_add_test(tc, s21_sub_224);
  tcase_add_test(tc, s21_sub_225);
  tcase_add_test(tc, s21_sub_226);
  tcase_add_test(tc, s21_sub_227);
  tcase_add_test(tc, s21_sub_228);
  tcase_add_test(tc, s21_sub_229);
  tcase_add_test(tc, s21_sub_230);
  tcase_add_test(tc, s21_sub_231);
  tcase_add_test(tc, s21_sub_232);
  tcase_add_test(tc, s21_sub_233);
  tcase_add_test(tc, s21_sub_234);
  tcase_add_test(tc, s21_sub_235);
  tcase_add_test(tc, s21_sub_236);
  tcase_add_test(tc, s21_sub_237);
  tcase_add_test(tc, s21_sub_238);
  tcase_add_test(tc, s21_sub_239);
  tcase_add_test(tc, s21_sub_240);
  tcase_add_test(tc, s21_sub_241);
  tcase_add_test(tc, s21_sub_242);
  tcase_add_test(tc, s21_sub_244);
  tcase_add_test(tc, s21_sub_245);
  tcase_add_test(tc, s21_sub_246);
  tcase_add_test(tc, s21_sub_247);
  tcase_add_test(tc, s21_sub_248);
  tcase_add_test(tc, s21_sub_249);
  tcase_add_test(tc, s21_sub_250);
  tcase_add_test(tc, s21_sub_251);
  tcase_add_test(tc, s21_sub_253);
  tcase_add_test(tc, s21_sub_254);
  tcase_add_test(tc, s21_sub_255);
  tcase_add_test(tc, s21_sub_256);
  tcase_add_test(tc, s21_sub_257);
  tcase_add_test(tc, s21_sub_258);
  tcase_add_test(tc, s21_sub_259);
  tcase_add_test(tc, s21_sub_260);
  tcase_add_test(tc, s21_sub_261);
  tcase_add_test(tc, s21_sub_262);
  tcase_add_test(tc, s21_sub_263);
  tcase_add_test(tc, s21_sub_264);
  tcase_add_test(tc, s21_sub_265);
  tcase_add_test(tc, s21_sub_267);
  tcase_add_test(tc, s21_sub_268);
  tcase_add_test(tc, s21_sub_269);
  tcase_add_test(tc, s21_sub_270);
  tcase_add_test(tc, s21_sub_271);
  tcase_add_test(tc, s21_sub_272);
  tcase_add_test(tc, s21_sub_273);
  tcase_add_test(tc, s21_sub_274);
  tcase_add_test(tc, s21_sub_275);
  tcase_add_test(tc, s21_sub_276);
  tcase_add_test(tc, s21_sub_277);
  tcase_add_test(tc, s21_sub_278);
  tcase_add_test(tc, s21_sub_279);
  tcase_add_test(tc, s21_sub_280);
  tcase_add_test(tc, s21_sub_281);
  tcase_add_test(tc, s21_sub_282);
  tcase_add_test(tc, s21_sub_283);
  tcase_add_test(tc, s21_sub_284);
  tcase_add_test(tc, s21_sub_285);
  tcase_add_test(tc, s21_sub_286);
  tcase_add_test(tc, s21_sub_287);
  tcase_add_test(tc, s21_sub_288);
  tcase_add_test(tc, s21_sub_289);
  tcase_add_test(tc, s21_sub_290);
  tcase_add_test(tc, s21_sub_291);
  tcase_add_test(tc, s21_sub_292);
  tcase_add_test(tc, s21_sub_293);
  tcase_add_test(tc, s21_sub_294);
  tcase_add_test(tc, s21_sub_295);
  tcase_add_test(tc, s21_sub_296);
  tcase_add_test(tc, s21_sub_297);
  tcase_add_test(tc, s21_sub_298);
  tcase_add_test(tc, s21_sub_299);
  tcase_add_test(tc, s21_sub_300);
  tcase_add_test(tc, s21_sub_301);
  tcase_add_test(tc, s21_sub_302);
  tcase_add_test(tc, s21_sub_303);
  tcase_add_test(tc, s21_sub_304);
  tcase_add_test(tc, s21_sub_305);
  tcase_add_test(tc, s21_sub_306);
  tcase_add_test(tc, s21_sub_307);
  tcase_add_test(tc, s21_sub_308);
  tcase_add_test(tc, s21_sub_309);
  tcase_add_test(tc, s21_sub_310);
  tcase_add_test(tc, s21_sub_311);
  tcase_add_test(tc, s21_sub_312);
  tcase_add_test(tc, s21_sub_313);
  tcase_add_test(tc, s21_sub_315);
  tcase_add_test(tc, s21_sub_316);
  tcase_add_test(tc, s21_sub_317);
  tcase_add_test(tc, s21_sub_318);
  tcase_add_test(tc, s21_sub_319);
  tcase_add_test(tc, s21_sub_320);
  tcase_add_test(tc, s21_sub_321);
  tcase_add_test(tc, s21_sub_322);
  tcase_add_test(tc, s21_sub_323);
  tcase_add_test(tc, s21_sub_324);
  tcase_add_test(tc, s21_sub_325);
  tcase_add_test(tc, s21_sub_326);
  tcase_add_test(tc, s21_sub_327);
  tcase_add_test(tc, s21_sub_328);
  tcase_add_test(tc, s21_sub_329);
  tcase_add_test(tc, s21_sub_330);
  tcase_add_test(tc, s21_sub_331);
  tcase_add_test(tc, s21_sub_332);
  tcase_add_test(tc, s21_sub_333);
  tcase_add_test(tc, s21_sub_334);
  tcase_add_test(tc, s21_sub_336);
  tcase_add_test(tc, s21_sub_337);
  tcase_add_test(tc, s21_sub_338);
  tcase_add_test(tc, s21_sub_339);
  tcase_add_test(tc, s21_sub_340);
  tcase_add_test(tc, s21_sub_341);
  tcase_add_test(tc, s21_sub_342);
  tcase_add_test(tc, s21_sub_343);
  tcase_add_test(tc, s21_sub_344);
  tcase_add_test(tc, s21_sub_345);
  tcase_add_test(tc, s21_sub_346);
  tcase_add_test(tc, s21_sub_347);
  tcase_add_test(tc, s21_sub_348);
  tcase_add_test(tc, s21_sub_349);
  tcase_add_test(tc, s21_sub_350);
  tcase_add_test(tc, s21_sub_351);
  tcase_add_test(tc, s21_sub_353);
  tcase_add_test(tc, s21_sub_354);
  tcase_add_test(tc, s21_sub_355);
  tcase_add_test(tc, s21_sub_356);
  tcase_add_test(tc, s21_sub_357);
  tcase_add_test(tc, s21_sub_358);
  tcase_add_test(tc, s21_sub_359);
  tcase_add_test(tc, s21_sub_360);
  tcase_add_test(tc, s21_sub_361);
  tcase_add_test(tc, s21_sub_362);
  tcase_add_test(tc, s21_sub_363);
  tcase_add_test(tc, s21_sub_364);
  tcase_add_test(tc, s21_sub_365);
  tcase_add_test(tc, s21_sub_366);
  tcase_add_test(tc, s21_sub_367);
  tcase_add_test(tc, s21_sub_368);
  tcase_add_test(tc, s21_sub_369);
  tcase_add_test(tc, s21_sub_370);
  tcase_add_test(tc, s21_sub_371);
  tcase_add_test(tc, s21_sub_372);
  tcase_add_test(tc, s21_sub_373);
  tcase_add_test(tc, s21_sub_374);
  tcase_add_test(tc, s21_sub_375);
  tcase_add_test(tc, s21_sub_376);
  tcase_add_test(tc, s21_sub_377);
  tcase_add_test(tc, s21_sub_378);
  tcase_add_test(tc, s21_sub_379);
  tcase_add_test(tc, s21_sub_380);
  tcase_add_test(tc, s21_sub_381);
  tcase_add_test(tc, s21_sub_382);
  tcase_add_test(tc, s21_sub_383);
  tcase_add_test(tc, s21_sub_384);
  tcase_add_test(tc, s21_sub_386);
  tcase_add_test(tc, s21_sub_387);
  tcase_add_test(tc, s21_sub_388);
  tcase_add_test(tc, s21_sub_389);
  tcase_add_test(tc, s21_sub_390);
  tcase_add_test(tc, s21_sub_391);
  tcase_add_test(tc, s21_sub_392);
  tcase_add_test(tc, s21_sub_394);
  tcase_add_test(tc, s21_sub_395);
  tcase_add_test(tc, s21_sub_396);
  tcase_add_test(tc, s21_sub_397);
  tcase_add_test(tc, s21_sub_398);
  tcase_add_test(tc, s21_sub_399);
  tcase_add_test(tc, s21_sub_400);
  tcase_add_test(tc, s21_sub_401);
  tcase_add_test(tc, s21_sub_402);
  tcase_add_test(tc, s21_sub_403);
  tcase_add_test(tc, s21_sub_404);
  tcase_add_test(tc, s21_sub_405);
  tcase_add_test(tc, s21_sub_406);
  tcase_add_test(tc, s21_sub_407);
  tcase_add_test(tc, s21_sub_408);
  tcase_add_test(tc, s21_sub_409);
  tcase_add_test(tc, s21_sub_410);
  tcase_add_test(tc, s21_sub_411);
  tcase_add_test(tc, s21_sub_412);
  tcase_add_test(tc, s21_sub_413);
  tcase_add_test(tc, s21_sub_414);
  tcase_add_test(tc, s21_sub_415);
  tcase_add_test(tc, s21_sub_416);
  tcase_add_test(tc, s21_sub_417);
  tcase_add_test(tc, s21_sub_418);
  tcase_add_test(tc, s21_sub_419);
  tcase_add_test(tc, s21_sub_420);
  tcase_add_test(tc, s21_sub_421);
  tcase_add_test(tc, s21_sub_422);
  tcase_add_test(tc, s21_sub_423);
  tcase_add_test(tc, s21_sub_424);
  tcase_add_test(tc, s21_sub_425);
  tcase_add_test(tc, s21_sub_426);
  tcase_add_test(tc, s21_sub_428);
  tcase_add_test(tc, s21_sub_429);
  tcase_add_test(tc, s21_sub_430);
  tcase_add_test(tc, s21_sub_431);
  tcase_add_test(tc, s21_sub_432);
  tcase_add_test(tc, s21_sub_433);
  tcase_add_test(tc, s21_sub_434);
  tcase_add_test(tc, s21_sub_435);
  tcase_add_test(tc, s21_sub_436);
  tcase_add_test(tc, s21_sub_437);
  tcase_add_test(tc, s21_sub_438);
  tcase_add_test(tc, s21_sub_439);
  tcase_add_test(tc, s21_sub_440);
  tcase_add_test(tc, s21_sub_441);
  tcase_add_test(tc, s21_sub_442);
  tcase_add_test(tc, s21_sub_443);
  tcase_add_test(tc, s21_sub_444);
  tcase_add_test(tc, s21_sub_445);
  tcase_add_test(tc, s21_sub_446);
  tcase_add_test(tc, s21_sub_447);
  tcase_add_test(tc, s21_sub_448);
  tcase_add_test(tc, s21_sub_449);
  tcase_add_test(tc, s21_sub_450);
  tcase_add_test(tc, s21_sub_451);
  tcase_add_test(tc, s21_sub_452);
  tcase_add_test(tc, s21_sub_453);
  tcase_add_test(tc, s21_sub_454);
  tcase_add_test(tc, s21_sub_455);
  tcase_add_test(tc, s21_sub_456);
  tcase_add_test(tc, s21_sub_457);
  tcase_add_test(tc, s21_sub_458);
  tcase_add_test(tc, s21_sub_459);
  tcase_add_test(tc, s21_sub_460);
  tcase_add_test(tc, s21_sub_461);
  tcase_add_test(tc, s21_sub_462);
  tcase_add_test(tc, s21_sub_463);
  tcase_add_test(tc, s21_sub_464);
  tcase_add_test(tc, s21_sub_465);
  tcase_add_test(tc, s21_sub_466);
  tcase_add_test(tc, s21_sub_468);
  tcase_add_test(tc, s21_sub_469);
  tcase_add_test(tc, s21_sub_470);
  tcase_add_test(tc, s21_sub_471);
  tcase_add_test(tc, s21_sub_472);
  tcase_add_test(tc, s21_sub_474);
  tcase_add_test(tc, s21_sub_475);
  tcase_add_test(tc, s21_sub_476);
  tcase_add_test(tc, s21_sub_477);
  tcase_add_test(tc, s21_sub_478);
  tcase_add_test(tc, s21_sub_479);
  tcase_add_test(tc, s21_sub_480);
  tcase_add_test(tc, s21_sub_481);
  tcase_add_test(tc, s21_sub_482);
  tcase_add_test(tc, s21_sub_483);
  tcase_add_test(tc, s21_sub_484);
  tcase_add_test(tc, s21_sub_485);
  tcase_add_test(tc, s21_sub_486);
  tcase_add_test(tc, s21_sub_487);
  tcase_add_test(tc, s21_sub_488);
  tcase_add_test(tc, s21_sub_489);
  tcase_add_test(tc, s21_sub_490);
  tcase_add_test(tc, s21_sub_491);
  tcase_add_test(tc, s21_sub_492);
  tcase_add_test(tc, s21_sub_493);
  tcase_add_test(tc, s21_sub_494);
  tcase_add_test(tc, s21_sub_495);
  tcase_add_test(tc, s21_sub_496);
  tcase_add_test(tc, s21_sub_497);
  tcase_add_test(tc, s21_sub_498);
  tcase_add_test(tc, s21_sub_499);
  tcase_add_test(tc, s21_sub_500);
  tcase_add_test(tc, fail_s21_sub_1);
  tcase_add_test(tc, fail_s21_sub_2);
  tcase_add_test(tc, fail_s21_sub_3);
  tcase_add_test(tc, fail_s21_sub_4);
  tcase_add_test(tc, fail_s21_sub_5);
  tcase_add_test(tc, fail_s21_sub_6);
  tcase_add_test(tc, fail_s21_sub_7);
  tcase_add_test(tc, fail_s21_sub_8);
  tcase_add_test(tc, fail_s21_sub_9);
  tcase_add_test(tc, fail_s21_sub_10);
  tcase_add_test(tc, fail_s21_sub_11);
  tcase_add_test(tc, fail_s21_sub_12);
  tcase_add_test(tc, fail_s21_sub_13);
  tcase_add_test(tc, fail_s21_sub_14);
  tcase_add_test(tc, fail_s21_sub_15);
  tcase_add_test(tc, fail_s21_sub_16);
  tcase_add_test(tc, fail_s21_sub_17);
  tcase_add_test(tc, fail_s21_sub_18);
  tcase_add_test(tc, fail_s21_sub_19);
  tcase_add_test(tc, fail_s21_sub_20);
  tcase_add_test(tc, fail_s21_sub_21);
  tcase_add_test(tc, fail_s21_sub_22);
  tcase_add_test(tc, fail_s21_sub_23);
  tcase_add_test(tc, fail_s21_sub_24);
  tcase_add_test(tc, fail_s21_sub_25);
  tcase_add_test(tc, fail_s21_sub_26);
  tcase_add_test(tc, fail_s21_sub_27);
  tcase_add_test(tc, fail_s21_sub_28);
  tcase_add_test(tc, fail_s21_sub_29);
  tcase_add_test(tc, fail_s21_sub_30);
  tcase_add_test(tc, fail_s21_sub_31);
  tcase_add_test(tc, fail_s21_sub_32);
  tcase_add_test(tc, fail_s21_sub_33);
  tcase_add_test(tc, fail_s21_sub_34);
  tcase_add_test(tc, fail_s21_sub_35);
  tcase_add_test(tc, fail_s21_sub_36);
  tcase_add_test(tc, fail_s21_sub_37);
  tcase_add_test(tc, fail_s21_sub_38);
  tcase_add_test(tc, fail_s21_sub_39);
  tcase_add_test(tc, fail_s21_sub_40);
  tcase_add_test(tc, fail_s21_sub_41);
  tcase_add_test(tc, fail_s21_sub_42);
  tcase_add_test(tc, fail_s21_sub_43);
  tcase_add_test(tc, fail_s21_sub_44);
  tcase_add_test(tc, fail_s21_sub_45);
  tcase_add_test(tc, fail_s21_sub_46);
  tcase_add_test(tc, fail_s21_sub_47);
  tcase_add_test(tc, fail_s21_sub_48);
  tcase_add_test(tc, fail_s21_sub_49);
  tcase_add_test(tc, fail_s21_sub_50);
  tcase_add_test(tc, fail_s21_sub_51);
  tcase_add_test(tc, fail_s21_sub_52);
  tcase_add_test(tc, fail_s21_sub_53);
  tcase_add_test(tc, fail_s21_sub_54);
  tcase_add_test(tc, fail_s21_sub_55);
  tcase_add_test(tc, fail_s21_sub_56);
  tcase_add_test(tc, fail_s21_sub_57);
  tcase_add_test(tc, fail_s21_sub_58);
  tcase_add_test(tc, fail_s21_sub_59);
  tcase_add_test(tc, fail_s21_sub_60);
  tcase_add_test(tc, fail_s21_sub_61);
  tcase_add_test(tc, fail_s21_sub_62);
  tcase_add_test(tc, fail_s21_sub_63);
  tcase_add_test(tc, fail_s21_sub_64);
  tcase_add_test(tc, fail_s21_sub_65);
  tcase_add_test(tc, fail_s21_sub_66);
  tcase_add_test(tc, fail_s21_sub_67);
  tcase_add_test(tc, fail_s21_sub_68);
  tcase_add_test(tc, fail_s21_sub_69);
  tcase_add_test(tc, fail_s21_sub_70);
  tcase_add_test(tc, fail_s21_sub_71);
  tcase_add_test(tc, fail_s21_sub_72);
  tcase_add_test(tc, fail_s21_sub_73);
  tcase_add_test(tc, fail_s21_sub_74);
  tcase_add_test(tc, fail_s21_sub_75);
  tcase_add_test(tc, fail_s21_sub_76);
  tcase_add_test(tc, fail_s21_sub_77);
  tcase_add_test(tc, fail_s21_sub_78);
  tcase_add_test(tc, fail_s21_sub_79);
  tcase_add_test(tc, fail_s21_sub_80);
  tcase_add_test(tc, fail_s21_sub_81);
  tcase_add_test(tc, fail_s21_sub_82);
  tcase_add_test(tc, fail_s21_sub_83);
  tcase_add_test(tc, fail_s21_sub_84);
  tcase_add_test(tc, fail_s21_sub_85);
  tcase_add_test(tc, fail_s21_sub_86);
  tcase_add_test(tc, fail_s21_sub_87);
  tcase_add_test(tc, fail_s21_sub_88);
  tcase_add_test(tc, fail_s21_sub_89);
  tcase_add_test(tc, fail_s21_sub_90);
  tcase_add_test(tc, fail_s21_sub_91);
  tcase_add_test(tc, fail_s21_sub_92);
  tcase_add_test(tc, fail_s21_sub_93);
  tcase_add_test(tc, fail_s21_sub_94);
  tcase_add_test(tc, fail_s21_sub_95);
  tcase_add_test(tc, fail_s21_sub_96);
  tcase_add_test(tc, fail_s21_sub_97);
  tcase_add_test(tc, fail_s21_sub_98);
  tcase_add_test(tc, fail_s21_sub_99);
  tcase_add_test(tc, fail_s21_sub_100);
  tcase_add_test(tc, fail_s21_sub_101);
  tcase_add_test(tc, fail_s21_sub_102);
  tcase_add_test(tc, fail_s21_sub_103);
  tcase_add_test(tc, fail_s21_sub_104);
  tcase_add_test(tc, fail_s21_sub_105);
  tcase_add_test(tc, fail_s21_sub_106);
  tcase_add_test(tc, fail_s21_sub_107);
  tcase_add_test(tc, fail_s21_sub_108);
  tcase_add_test(tc, fail_s21_sub_109);
  tcase_add_test(tc, fail_s21_sub_110);
  tcase_add_test(tc, fail_s21_sub_111);
  tcase_add_test(tc, fail_s21_sub_112);
  tcase_add_test(tc, fail_s21_sub_113);
  tcase_add_test(tc, fail_s21_sub_114);
  tcase_add_test(tc, fail_s21_sub_115);
  tcase_add_test(tc, fail_s21_sub_116);
  tcase_add_test(tc, fail_s21_sub_117);
  tcase_add_test(tc, fail_s21_sub_118);
  tcase_add_test(tc, fail_s21_sub_119);
  tcase_add_test(tc, fail_s21_sub_120);
  tcase_add_test(tc, fail_s21_sub_121);
  tcase_add_test(tc, fail_s21_sub_122);
  tcase_add_test(tc, fail_s21_sub_123);
  tcase_add_test(tc, fail_s21_sub_124);
  tcase_add_test(tc, fail_s21_sub_125);
  tcase_add_test(tc, fail_s21_sub_126);
  tcase_add_test(tc, fail_s21_sub_127);
  tcase_add_test(tc, fail_s21_sub_128);
  tcase_add_test(tc, fail_s21_sub_129);
  tcase_add_test(tc, fail_s21_sub_130);
  tcase_add_test(tc, fail_s21_sub_131);
  tcase_add_test(tc, fail_s21_sub_132);
  tcase_add_test(tc, fail_s21_sub_133);
  tcase_add_test(tc, fail_s21_sub_134);
  tcase_add_test(tc, fail_s21_sub_135);
  tcase_add_test(tc, fail_s21_sub_136);
  tcase_add_test(tc, fail_s21_sub_137);
  tcase_add_test(tc, fail_s21_sub_138);
  tcase_add_test(tc, fail_s21_sub_139);
  tcase_add_test(tc, fail_s21_sub_140);
  tcase_add_test(tc, fail_s21_sub_141);
  tcase_add_test(tc, fail_s21_sub_142);
  tcase_add_test(tc, fail_s21_sub_143);
  tcase_add_test(tc, fail_s21_sub_144);
  tcase_add_test(tc, fail_s21_sub_145);
  tcase_add_test(tc, fail_s21_sub_146);
  tcase_add_test(tc, fail_s21_sub_147);
  tcase_add_test(tc, fail_s21_sub_148);
  tcase_add_test(tc, fail_s21_sub_149);
  tcase_add_test(tc, fail_s21_sub_150);
  tcase_add_test(tc, fail_s21_sub_151);
  tcase_add_test(tc, fail_s21_sub_152);
  tcase_add_test(tc, fail_s21_sub_153);
  tcase_add_test(tc, fail_s21_sub_154);
  tcase_add_test(tc, fail_s21_sub_155);
  tcase_add_test(tc, fail_s21_sub_156);
  tcase_add_test(tc, fail_s21_sub_157);
  tcase_add_test(tc, fail_s21_sub_158);
  tcase_add_test(tc, fail_s21_sub_159);
  tcase_add_test(tc, fail_s21_sub_160);
  tcase_add_test(tc, fail_s21_sub_161);
  tcase_add_test(tc, fail_s21_sub_162);
  tcase_add_test(tc, fail_s21_sub_163);
  tcase_add_test(tc, fail_s21_sub_164);
  tcase_add_test(tc, fail_s21_sub_165);
  tcase_add_test(tc, fail_s21_sub_166);

  suite_add_tcase(c, tc);
  return c;
}
