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

START_TEST(fail_s21_sub_1) {
  // -79228162514264337593083052642
  s21_decimal dec_1 = {{0xe4874262, 0xffffffff, 0xffffffff, 0x80000000}};
  // 3159372907528469504894978564
  s21_decimal dec_2 = {{0x40b04a04, 0x80701a8e, 0xa355f3c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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

  suite_add_tcase(c, tc);
  return c;
}
