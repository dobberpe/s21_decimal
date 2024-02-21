#include "s21_decimal_test.h"

START_TEST(invalid_dec_s21_mul_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_mul(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_1) {
  // 336843.89241999153888802
  s21_decimal dec_1 = {{0x250afe22, 0x8ce6c0e, 0x722, 0x110000}};
  // 8540283502625719.3573251603
  s21_decimal dec_2 = {{0x4f277a13, 0xf6ae2060, 0x46a4c0, 0xa0000}};
  // 2876742337394686338428.8911722
  s21_decimal dec_check = {{0xb571616a, 0xf132478f, 0x5cf3dad9, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_2) {
  // 979595539954588710912
  s21_decimal dec_1 = {{0x163bf800, 0x1a9e7978, 0x35, 0x0}};
  // -3754.48
  s21_decimal dec_2 = {{0x5ba98, 0x0, 0x0, 0x80020000}};
  // -3677871862848704223344885.76
  s21_decimal dec_check = {{0x9dcb4000, 0x51b1cea0, 0x13039f7, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_3) {
  // -9661.97679098233771397014
  s21_decimal dec_1 = {{0xbf3e0f96, 0xae5ef524, 0xcc99, 0x80140000}};
  // 11.082141793100977182328
  s21_decimal dec_2 = {{0x26409678, 0xc39cbd1f, 0x258, 0x150000}};
  // -107075.39679931702949690049631
  s21_decimal dec_check = {{0xe091845f, 0x25d87fa6, 0x229911b9, 0x80170000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_4) {
  // 26629077
  s21_decimal dec_1 = {{0x19653d5, 0x0, 0x0, 0x0}};
  // 188653047
  s21_decimal dec_2 = {{0xb3e9df7, 0x0, 0x0, 0x0}};
  // 5023656514847619
  s21_decimal dec_check = {{0x2e0a8383, 0x11d8fd, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_5) {
  // 0.078
  s21_decimal dec_1 = {{0x4e, 0x0, 0x0, 0x30000}};
  // -4759
  s21_decimal dec_2 = {{0x1297, 0x0, 0x0, 0x80000000}};
  // -371.202
  s21_decimal dec_check = {{0x5aa02, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_6) {
  // -986672139018.94392
  s21_decimal dec_1 = {{0xeb9992f8, 0x15e894e, 0x0, 0x80050000}};
  // -929068770
  s21_decimal dec_2 = {{0x376076e2, 0x0, 0x0, 0x80000000}};
  // 916686270591599234453.37840
  s21_decimal dec_check = {{0x2c520ef0, 0x3af5f06f, 0x4bd396, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_7) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -517
  s21_decimal dec_2 = {{0x205, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_8) {
  // -3754251997851263.4159305
  s21_decimal dec_1 = {{0x5b3d20c9, 0x2f2043a9, 0x7f3, 0x80070000}};
  // -6741641775.8913764665659
  s21_decimal dec_2 = {{0xf12293b, 0xa6bd8c3e, 0xe46, 0x800d0000}};
  // 25309822105937739561808889.280
  s21_decimal dec_check = {{0x3c3705c0, 0x9fbc4ef8, 0x51c7cb4d, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_9) {
  // 7020366709895290665.4471172598
  s21_decimal dec_1 = {{0xee0431f6, 0x41b6abf4, 0xe2d71cc3, 0xa0000}};
  // 89347.977493974
  s21_decimal dec_2 = {{0xf275bdd6, 0x5142, 0x0, 0x90000}};
  // 627255566795168727938500.03882
  s21_decimal dec_check = {{0xea3a41aa, 0x1d5fb90a, 0xcaad5d49, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_10) {
  // -16143.057306
  s21_decimal dec_1 = {{0xc233819a, 0x3, 0x0, 0x80060000}};
  // -0.11
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80020000}};
  // 1775.73630366
  s21_decimal dec_check = {{0x5836919e, 0x29, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_11) {
  // 0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x10000}};
  // 36
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x0}};
  // 21.6
  s21_decimal dec_check = {{0xd8, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_12) {
  // 65704365791294279.9129630877
  s21_decimal dec_1 = {{0xb7e3589d, 0x10fc6dca, 0x21f7e68, 0xa0000}};
  // -538438990.7
  s21_decimal dec_2 = {{0x40ef4513, 0x1, 0x0, 0x80010000}};
  // -35377792401248098923019128.788
  s21_decimal dec_check = {{0xb35a4fd4, 0xf56e8a7f, 0x724fd2f0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_13) {
  // -591780481523127385
  s21_decimal dec_1 = {{0x6a321459, 0x8366d36, 0x0, 0x80000000}};
  // -4878
  s21_decimal dec_2 = {{0x130e, 0x0, 0x0, 0x80000000}};
  // 2886705188869815384030
  s21_decimal dec_check = {{0x863fb7de, 0x7d1502db, 0x9c, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_14) {
  // -333643482.95328028755867
  s21_decimal dec_1 = {{0x1ce5079b, 0xaf5892b5, 0x710, 0x800e0000}};
  // -6326.29061350624419584
  s21_decimal dec_2 = {{0x68c55f00, 0x4b7deb7c, 0x22, 0x80110000}};
  // 2110725634464.8676774652948352
  s21_decimal dec_check = {{0xd89c2f80, 0x342e03af, 0x44338363, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_15) {
  // 133976569905467853
  s21_decimal dec_1 = {{0x170d1cd, 0x1dbfafb, 0x0, 0x0}};
  // -0.51200097710
  s21_decimal dec_2 = {{0xebc37dae, 0xb, 0x0, 0x800b0000}};
  // -68596134700105995.36863916630
  s21_decimal dec_check = {{0xf46b256, 0x546ed3a5, 0x162a23a7, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_16) {
  // 81676595486311092800708
  s21_decimal dec_1 = {{0x8dfb4cc4, 0xb27605a6, 0x114b, 0x0}};
  // 9.558885
  s21_decimal dec_2 = {{0x91db65, 0x0, 0x0, 0x60000}};
  // 780737183445166810306295.69058
  s21_decimal dec_check = {{0xd8fbb222, 0x28460359, 0xfc4510f0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_17) {
  // -76.50246628010781729020450
  s21_decimal dec_1 = {{0xb6ada22, 0xb3618804, 0x65400, 0x80170000}};
  // -24
  s21_decimal dec_2 = {{0x18, 0x0, 0x0, 0x80000000}};
  // 1836.05919072258761496490800
  s21_decimal dec_check = {{0x12047330, 0xd124c061, 0x97e010, 0x170000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_18) {
  // 6113868.8123269
  s21_decimal dec_1 = {{0xf5c9a185, 0x379a, 0x0, 0x70000}};
  // -0.93851852
  s21_decimal dec_2 = {{0x59810cc, 0x0, 0x0, 0x80080000}};
  // -5737979.109219199944188
  s21_decimal dec_check = {{0xf6bd05fc, 0xe74deb7, 0x137, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_19) {
  // 42
  s21_decimal dec_1 = {{0x2a, 0x0, 0x0, 0x0}};
  // -877383797593657312311922008
  s21_decimal dec_2 = {{0xe35e4d58, 0xf904ea96, 0x2d5c13e, 0x80000000}};
  // -36850119498933607117100724336
  s21_decimal dec_check = {{0x4d78b070, 0xdace7cc1, 0x7711b454, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_20) {
  // -126
  s21_decimal dec_1 = {{0x7e, 0x0, 0x0, 0x80000000}};
  // 0.3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x10000}};
  // -37.8
  s21_decimal dec_check = {{0x17a, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_21) {
  // -61.41314
  s21_decimal dec_1 = {{0x5db582, 0x0, 0x0, 0x80050000}};
  // -81579586915467723
  s21_decimal dec_2 = {{0xbb0501cb, 0x121d433, 0x0, 0x80000000}};
  // 5010058592381787438.08022
  s21_decimal dec_check = {{0x298e7016, 0x95014651, 0x6a17, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_22) {
  // -49876665247630.3183
  s21_decimal dec_1 = {{0xbaa9274f, 0x6ebf9a0, 0x0, 0x80040000}};
  // 79
  s21_decimal dec_2 = {{0x4f, 0x0, 0x0, 0x0}};
  // -3940256554562795.1457
  s21_decimal dec_check = {{0x9a332161, 0x22d20899, 0x2, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_23) {
  // -6925891126535217
  s21_decimal dec_1 = {{0xb059a431, 0x189b0f, 0x0, 0x80000000}};
  // -7846522142357.8
  s21_decimal dec_2 = {{0x1ba671da, 0x475d, 0x0, 0x80010000}};
  // 54344158079917987778349114643
  s21_decimal dec_check = {{0xa3422513, 0x9b6d66be, 0xaf986f18, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_24) {
  // -12
  s21_decimal dec_1 = {{0xc, 0x0, 0x0, 0x80000000}};
  // -3120006261955546
  s21_decimal dec_2 = {{0x10f0dbda, 0xb15a1, 0x0, 0x80000000}};
  // 37440075143466552
  s21_decimal dec_check = {{0xcb4a4e38, 0x85038c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_25) {
  // -8.12803
  s21_decimal dec_1 = {{0xc6703, 0x0, 0x0, 0x80050000}};
  // -46
  s21_decimal dec_2 = {{0x2e, 0x0, 0x0, 0x80000000}};
  // 373.88938
  s21_decimal dec_check = {{0x23a828a, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_26) {
  // 69247779660809133255.271
  s21_decimal dec_1 = {{0x884a6a67, 0xedfe070b, 0xea9, 0x30000}};
  // -18778172
  s21_decimal dec_2 = {{0x11e883c, 0x0, 0x0, 0x80000000}};
  // -1300346717088775563438398744.6
  s21_decimal dec_check = {{0xb41722f6, 0xd3762e2e, 0x2a043747, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_27) {
  // -277094782158
  s21_decimal dec_1 = {{0x8422d4ce, 0x40, 0x0, 0x80000000}};
  // 666543180
  s21_decimal dec_2 = {{0x27baa44c, 0x0, 0x0, 0x0}};
  // -184695637261000582440
  s21_decimal dec_check = {{0x8a572528, 0x32ab787, 0xa, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_28) {
  // -8.024009633234820528
  s21_decimal dec_1 = {{0x97461db0, 0x6f5b023f, 0x0, 0x80120000}};
  // -69416502280543
  s21_decimal dec_2 = {{0x49f5c15f, 0x3f22, 0x0, 0x80000000}};
  // 556998683004543.92018814931139
  s21_decimal dec_check = {{0xa8ec90c3, 0xeceaba7d, 0xb3f9d9e6, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_29) {
  // 138978717438273482320
  s21_decimal dec_1 = {{0x57ad6e50, 0x88b7972b, 0x7, 0x0}};
  // -94376232.9660978
  s21_decimal dec_2 = {{0xca696e32, 0x35a58, 0x0, 0x80070000}};
  // -13116287814283977010817865308
  s21_decimal dec_check = {{0xc785165c, 0x28db026d, 0x2a6189fb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_30) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 53231459938972631221772
  s21_decimal dec_2 = {{0x2c66c60c, 0xaee7de22, 0xb45, 0x0}};
  // -266157299694863156108860
  s21_decimal dec_check = {{0xde01de3c, 0x6a8756aa, 0x385c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_31) {
  // 0.205
  s21_decimal dec_1 = {{0xcd, 0x0, 0x0, 0x30000}};
  // -283840.266527
  s21_decimal dec_2 = {{0x1632c11f, 0x42, 0x0, 0x80060000}};
  // -58187.254638035
  s21_decimal dec_check = {{0xc6a4a5d3, 0x34eb, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_32) {
  // -73645
  s21_decimal dec_1 = {{0x11fad, 0x0, 0x0, 0x80000000}};
  // -70362786881
  s21_decimal dec_2 = {{0x61f2ec41, 0x10, 0x0, 0x80000000}};
  // 5181867439851245
  s21_decimal dec_check = {{0x880686ed, 0x1268e1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_33) {
  // -161990083
  s21_decimal dec_1 = {{0x9a7c5c3, 0x0, 0x0, 0x80000000}};
  // -3095805563344.13
  s21_decimal dec_2 = {{0xd716f54d, 0x1198f, 0x0, 0x80020000}};
  // 501489800157977376262.79
  s21_decimal dec_check = {{0x3b7c1aa7, 0x94e747af, 0xa9e, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_34) {
  // -6264127743.87787841526395
  s21_decimal dec_1 = {{0xdce1da7b, 0xe7902492, 0x84a5, 0x800e0000}};
  // 9.179416880781463
  s21_decimal dec_2 = {{0x8a6c9897, 0x209ca1, 0x0, 0xf0000}};
  // -57501039955.524097842775590786
  s21_decimal dec_check = {{0x2b9c0782, 0xff6c9c28, 0xb9cbbed5, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_35) {
  // 621853013396476
  s21_decimal dec_1 = {{0x6ff74bfc, 0x23592, 0x0, 0x0}};
  // -4018541.1567738945241938305
  s21_decimal dec_2 = {{0xd378f981, 0x86b4ef1c, 0x213d97, 0x80130000}};
  // -2498941927797606793287.2214978
  s21_decimal dec_check = {{0x4b9389c2, 0x84428399, 0x50bec35d, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_36) {
  // 1094841922
  s21_decimal dec_1 = {{0x4141f642, 0x0, 0x0, 0x0}};
  // -3027398298919256.84
  s21_decimal dec_2 = {{0x741206b4, 0x4338c45, 0x0, 0x80020000}};
  // -3314522572248289681517246.48
  s21_decimal dec_check = {{0xa6cab268, 0xde2ff3b8, 0x1122bbe, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_37) {
  // 0.7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x10000}};
  // -96.1
  s21_decimal dec_2 = {{0x3c1, 0x0, 0x0, 0x80010000}};
  // -67.27
  s21_decimal dec_check = {{0x1a47, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_38) {
  // -8044377273.293
  s21_decimal dec_1 = {{0xfa3ff3cd, 0x750, 0x0, 0x80030000}};
  // 24855995.574
  s21_decimal dec_2 = {{0xc98864b6, 0x5, 0x0, 0x30000}};
  // -199951005900556996.405182
  s21_decimal dec_check = {{0x5e9b67be, 0x5da1c0b9, 0x2a57, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_39) {
  // -99556713343179866909646
  s21_decimal dec_1 = {{0x5bfa2bce, 0xfaf14f8c, 0x1514, 0x80000000}};
  // 511941.54039
  s21_decimal dec_2 = {{0xeb68cc37, 0xb, 0x0, 0x50000}};
  // -50967217185073167766559362190
  s21_decimal dec_check = {{0x52ab8c8e, 0xe13d67c0, 0xa4af180b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_40) {
  // -46124090
  s21_decimal dec_1 = {{0x2bfcc3a, 0x0, 0x0, 0x80000000}};
  // -943.0689407892436056241569
  s21_decimal dec_2 = {{0x8b9775a1, 0xb27bf03e, 0x7cd06, 0x80160000}};
  // 43498196701.167743097733119030
  s21_decimal dec_check = {{0x633bfc36, 0x21617763, 0x8c8cdd70, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_41) {
  // 0.8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x10000}};
  // -53.0101
  s21_decimal dec_2 = {{0x816b5, 0x0, 0x0, 0x80040000}};
  // -42.40808
  s21_decimal dec_check = {{0x40b5a8, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_42) {
  // -7793675459.3732
  s21_decimal dec_1 = {{0x10928fc4, 0x46e2, 0x0, 0x80040000}};
  // 8.57893
  s21_decimal dec_2 = {{0xd1725, 0x0, 0x0, 0x50000}};
  // -66861396208.680526676
  s21_decimal dec_check = {{0xdd0d6354, 0x9fe3659a, 0x3, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_43) {
  // 702919
  s21_decimal dec_1 = {{0xab9c7, 0x0, 0x0, 0x0}};
  // -21025602222156149
  s21_decimal dec_2 = {{0x7fa3e975, 0x4ab2ac, 0x0, 0x80000000}};
  // -14779295288395778098931
  s21_decimal dec_check = {{0xcab206f3, 0x2fec88bb, 0x321, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_44) {
  // 423
  s21_decimal dec_1 = {{0x1a7, 0x0, 0x0, 0x0}};
  // -28
  s21_decimal dec_2 = {{0x1c, 0x0, 0x0, 0x80000000}};
  // -11844
  s21_decimal dec_check = {{0x2e44, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_45) {
  // 21059414521.74988
  s21_decimal dec_1 = {{0xb42cb68c, 0x77b57, 0x0, 0x50000}};
  // 230731.41
  s21_decimal dec_2 = {{0x1601175, 0x0, 0x0, 0x20000}};
  // 4859068406377825.4797308
  s21_decimal dec_check = {{0x510eb9fc, 0x1b33ef87, 0xa4a, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_46) {
  // 0.9181538467227712
  s21_decimal dec_1 = {{0x82d4a840, 0x209e8f, 0x0, 0x100000}};
  // -0.4690
  s21_decimal dec_2 = {{0x1252, 0x0, 0x0, 0x80040000}};
  // -0.43061415411297969280
  s21_decimal dec_check = {{0xdbf26480, 0x5598e12a, 0x2, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_47) {
  // -99462208185169702989
  s21_decimal dec_1 = {{0xfcfd704d, 0x6450bf5e, 0x5, 0x80000000}};
  // 706.2676888908691355228763849
  s21_decimal dec_2 = {{0xf640f6c9, 0x536e12dc, 0x16d21c01, 0x190000}};
  // -70246943906922293440806.212412
  s21_decimal dec_check = {{0x1335533c, 0xb7b655ad, 0xe2fae8fb, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_48) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 59600415029093108232264236
  s21_decimal dec_2 = {{0x5ab49a2c, 0xf9080bc9, 0x314ce0, 0x0}};
  // 536403735261837974090378124
  s21_decimal dec_check = {{0x30596b8c, 0xc1486a14, 0x1bbb3e8, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_49) {
  // 778384590724494942317.62
  s21_decimal dec_1 = {{0xcdbdaad2, 0xa19e488f, 0x107b, 0x20000}};
  // 8837
  s21_decimal dec_2 = {{0x2285, 0x0, 0x0, 0x0}};
  // 6878584628232361805260807.94
  s21_decimal dec_check = {{0x1439a31a, 0xfcdecc09, 0x238fbb1, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_50) {
  // 35.45230213249512888367
  s21_decimal dec_1 = {{0x791d82f, 0x2ff3df84, 0xc0, 0x140000}};
  // 0.63915269792456986
  s21_decimal dec_2 = {{0x67b3e11a, 0xe31299, 0x0, 0x110000}};
  // 22.659434555621242984679002521
  s21_decimal dec_check = {{0xb10ad199, 0x9ff85714, 0x493771e8, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_51) {
  // -43
  s21_decimal dec_1 = {{0x2b, 0x0, 0x0, 0x80000000}};
  // 67435.24995
  s21_decimal dec_2 = {{0x91f20683, 0x1, 0x0, 0x50000}};
  // -2899715.74785
  s21_decimal dec_check = {{0x83a71801, 0x43, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_52) {
  // -4512051.0178
  s21_decimal dec_1 = {{0x816458e2, 0xa, 0x0, 0x80040000}};
  // 31504890929173777533
  s21_decimal dec_2 = {{0x48d44c7d, 0xb537db61, 0x1, 0x0}};
  // -142151675182656530630843423.09
  s21_decimal dec_check = {{0x805afc25, 0x4706f48d, 0x2dee82cf, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_53) {
  // -46539
  s21_decimal dec_1 = {{0xb5cb, 0x0, 0x0, 0x80000000}};
  // 133
  s21_decimal dec_2 = {{0x85, 0x0, 0x0, 0x0}};
  // -6189687
  s21_decimal dec_check = {{0x5e7277, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_54) {
  // 24214
  s21_decimal dec_1 = {{0x5e96, 0x0, 0x0, 0x0}};
  // -999079892
  s21_decimal dec_2 = {{0x3b8cbfd4, 0x0, 0x0, 0x80000000}};
  // -24191720504888
  s21_decimal dec_check = {{0x92e83e38, 0x1600, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_55) {
  // 450425
  s21_decimal dec_1 = {{0x6df79, 0x0, 0x0, 0x0}};
  // 9403
  s21_decimal dec_2 = {{0x24bb, 0x0, 0x0, 0x0}};
  // 4235346275
  s21_decimal dec_check = {{0xfc724163, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_56) {
  // 9260
  s21_decimal dec_1 = {{0x242c, 0x0, 0x0, 0x0}};
  // 379091
  s21_decimal dec_2 = {{0x5c8d3, 0x0, 0x0, 0x0}};
  // 3510382660
  s21_decimal dec_check = {{0xd13c3044, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_57) {
  // -4455848522046904135025
  s21_decimal dec_1 = {{0x530aed71, 0x8d51feb4, 0xf1, 0x80000000}};
  // 74500
  s21_decimal dec_2 = {{0x12304, 0x0, 0x0, 0x0}};
  // -331960714892494358059362500
  s21_decimal dec_check = {{0xb81328c4, 0x69cef536, 0x112976a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_58) {
  // -36260918070
  s21_decimal dec_1 = {{0x7151b336, 0x8, 0x0, 0x80000000}};
  // 366585.65614702
  s21_decimal dec_2 = {{0x3cc80c6e, 0x2157, 0x0, 0x80000}};
  // -13292732443184284.09465140
  s21_decimal dec_check = {{0x2fb18934, 0xc05f41f, 0x1197c, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_59) {
  // 369003076.958572104485414507
  s21_decimal dec_1 = {{0x7203a66b, 0xe276316c, 0x1313b70, 0x120000}};
  // 39834318458394
  s21_decimal dec_2 = {{0xa666ce1a, 0x243a, 0x0, 0x0}};
  // 14698986079695030495348.929097
  s21_decimal dec_check = {{0x5d723249, 0xc06af57, 0x2f7eb760, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_60) {
  // -41966707
  s21_decimal dec_1 = {{0x2805c73, 0x0, 0x0, 0x80000000}};
  // 490785411
  s21_decimal dec_2 = {{0x1d40ca83, 0x0, 0x0, 0x0}};
  // -20596647543311577
  s21_decimal dec_check = {{0xb4620cd9, 0x492c8a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_61) {
  // -1749.79180250024558553314
  s21_decimal dec_1 = {{0xb0bd68e2, 0xa3ef2df7, 0x250d, 0x80140000}};
  // 88851188042170356
  s21_decimal dec_2 = {{0x4d1ffff4, 0x13ba9af, 0x0, 0x0}};
  // -155471080478597533803.69214880
  s21_decimal dec_check = {{0x31352da0, 0x115cb2eb, 0x323c4430, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_62) {
  // 31772873507532037677
  s21_decimal dec_1 = {{0x7dddde2d, 0xb8efec1d, 0x1, 0x0}};
  // 0.93
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x20000}};
  // 29548772362004795039.61
  s21_decimal dec_check = {{0xb999b659, 0x2f28c6b6, 0xa0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_63) {
  // 2290.056289762
  s21_decimal dec_1 = {{0x31fddde2, 0x215, 0x0, 0x90000}};
  // -0.67956
  s21_decimal dec_2 = {{0x10974, 0x0, 0x0, 0x80050000}};
  // -1556.23065227066472
  s21_decimal dec_check = {{0x71b77c68, 0x228e25a, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_64) {
  // 7.25994644047299
  s21_decimal dec_1 = {{0xccde05c3, 0x29449, 0x0, 0xe0000}};
  // -881219140436866670997156.098
  s21_decimal dec_2 = {{0x418e3102, 0x532ae038, 0x2d8ed69, 0x80030000}};
  // -6397603761891298074095688.2305
  s21_decimal dec_check = {{0xbc0a0581, 0xac079363, 0xceb7bcec, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_65) {
  // 566352354456360067
  s21_decimal dec_1 = {{0x3913d483, 0x7dc1677, 0x0, 0x0}};
  // 875003402
  s21_decimal dec_2 = {{0x34277e0a, 0x0, 0x0, 0x0}};
  // 495560236880024919161947934
  s21_decimal dec_check = {{0xf953c71e, 0x456947ef, 0x199eaf6, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_66) {
  // -2465
  s21_decimal dec_1 = {{0x9a1, 0x0, 0x0, 0x80000000}};
  // -5992534189534.57
  s21_decimal dec_2 = {{0x8f2acaf1, 0x22104, 0x0, 0x80020000}};
  // 14771596777202715.05
  s21_decimal dec_check = {{0x8b0c1a91, 0x147fece6, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_67) {
  // 78.1274726
  s21_decimal dec_1 = {{0x2e914e66, 0x0, 0x0, 0x70000}};
  // -83765374641
  s21_decimal dec_2 = {{0x80ce2eb1, 0x13, 0x0, 0x80000000}};
  // -6544377012093.4623366
  s21_decimal dec_check = {{0x64a18886, 0x8c36fa30, 0x3, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_68) {
  // 4760502318
  s21_decimal dec_1 = {{0x1bbf802e, 0x1, 0x0, 0x0}};
  // 83422918101959612
  s21_decimal dec_2 = {{0xb79803bc, 0x12860b3, 0x0, 0x0}};
  // 397134994998702893268380616
  s21_decimal dec_check = {{0x9c72abc8, 0x37a642a2, 0x148809b, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_69) {
  // 731573080362414785.1822103383
  s21_decimal dec_1 = {{0x6919fb57, 0x87c9b0fc, 0x17a36e41, 0xa0000}};
  // -24552.479645
  s21_decimal dec_2 = {{0xb7711b9d, 0x5, 0x0, 0x80060000}};
  // -17961933164428138236233.266947
  s21_decimal dec_check = {{0x7fa23703, 0xf21436c5, 0x3a09c34b, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_70) {
  // 161196022.437867883
  s21_decimal dec_1 = {{0xa89d716b, 0x23caeed, 0x0, 0x90000}};
  // -62461886175526.9745995
  s21_decimal dec_2 = {{0xd3ad8d4b, 0xdc53f964, 0x21, 0x80070000}};
  // -10068607605461795926999.405966
  s21_decimal dec_check = {{0x3439958e, 0xfcbee130, 0x20888e97, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_71) {
  // -99361396175
  s21_decimal dec_1 = {{0x226695cf, 0x17, 0x0, 0x80000000}};
  // 8031.4927853305
  s21_decimal dec_2 = {{0xc6beaef9, 0x490b, 0x0, 0xa0000}};
  // -798020336519878.0388108375
  s21_decimal dec_check = {{0x793c6857, 0xb0f726c8, 0x699df, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_72) {
  // -4312172846452980063.617174
  s21_decimal dec_1 = {{0x79f34096, 0x5bc0f212, 0x39123, 0x80060000}};
  // 569780984.89
  s21_decimal dec_2 = {{0x4428c939, 0xd, 0x0, 0x20000}};
  // -2456994091467893723723328257.6
  s21_decimal dec_check = {{0xa19b2e10, 0xe073f3ab, 0x4f63c75d, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_73) {
  // 9317270.8933205
  s21_decimal dec_1 = {{0x7637fe55, 0x54bd, 0x0, 0x70000}};
  // 4832464385.026
  s21_decimal dec_2 = {{0x2552b402, 0x465, 0x0, 0x30000}};
  // 45025379757610699.6836188330
  s21_decimal dec_check = {{0xb7dc0aa, 0x466c81d5, 0x17470f3, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_74) {
  // -461688949069920
  s21_decimal dec_1 = {{0x55ce5860, 0x1a3e7, 0x0, 0x80000000}};
  // 520738
  s21_decimal dec_2 = {{0x7f222, 0x0, 0x0, 0x0}};
  // -240418979960772000960
  s21_decimal dec_check = {{0xdf927cc0, 0x87bcc7a, 0xd, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_75) {
  // -670139387.8433
  s21_decimal dec_1 = {{0x4a339da1, 0x618, 0x0, 0x80040000}};
  // -3.004363999802735428
  s21_decimal dec_2 = {{0xd836bb44, 0x29b1a523, 0x0, 0x80120000}};
  // 2013342651.6862534016767494224
  s21_decimal dec_check = {{0xecee0850, 0x753e3fb6, 0x410dfae6, 0x130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_76) {
  // -787393625536.391858
  s21_decimal dec_1 = {{0xa480eab2, 0xaed6254, 0x0, 0x80060000}};
  // 8814039814165875
  s21_decimal dec_2 = {{0x9028d573, 0x1f5052, 0x0, 0x0}};
  // -6940118764898173859953283411.4
  s21_decimal dec_check = {{0x1471ad42, 0x1ae1ccfb, 0xe03f5121, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_77) {
  // 151803184282084
  s21_decimal dec_1 = {{0x6edff9e4, 0x8a10, 0x0, 0x0}};
  // -287342657.72435987105755209603
  s21_decimal dec_2 = {{0xb0609f83, 0xc3365f8b, 0x5cd86d74, 0x80140000}};
  // -43619530422634789049884.185291
  s21_decimal dec_check = {{0x2abf92cb, 0x59d535e3, 0x8cf13ada, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_78) {
  // -496
  s21_decimal dec_1 = {{0x1f0, 0x0, 0x0, 0x80000000}};
  // 82689799264759747
  s21_decimal dec_2 = {{0x2fb96fc3, 0x125c5ef, 0x0, 0x0}};
  // -41014140435320834512
  s21_decimal dec_check = {{0x774889d0, 0x392f7f6c, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_80) {
  // -992.68106
  s21_decimal dec_1 = {{0x5eab60a, 0x0, 0x0, 0x80050000}};
  // -597951674.15443807
  s21_decimal dec_2 = {{0x5115215f, 0xd46f63, 0x0, 0x80080000}};
  // 593575301728.4021870319542
  s21_decimal dec_check = {{0x8c62d7b6, 0xd0da7c7d, 0x4e8f1, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_81) {
  // -36621902906536336057257432
  s21_decimal dec_1 = {{0x17254dd8, 0x55a7c166, 0x1e4afd, 0x80000000}};
  // 967
  s21_decimal dec_2 = {{0x3c7, 0x0, 0x0, 0x0}};
  // -35413380110620636967367936744
  s21_decimal dec_check = {{0x6de90ae8, 0x8cab88a1, 0x726d42ee, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_82) {
  // 8698687
  s21_decimal dec_1 = {{0x84bb3f, 0x0, 0x0, 0x0}};
  // 93
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x0}};
  // 808977891
  s21_decimal dec_check = {{0x303805e3, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_83) {
  // -870370
  s21_decimal dec_1 = {{0xd47e2, 0x0, 0x0, 0x80000000}};
  // -65571996106735.38984
  s21_decimal dec_2 = {{0xeb86a7a8, 0x5affda4d, 0x0, 0x80050000}};
  // 57071898251419281255.04080
  s21_decimal dec_check = {{0xc8e79a50, 0x615f4af2, 0x4b88b, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_84) {
  // -3170
  s21_decimal dec_1 = {{0xc62, 0x0, 0x0, 0x80000000}};
  // 7517127145322681
  s21_decimal dec_2 = {{0x8d3a78b9, 0x1ab4c9, 0x0, 0x0}};
  // -23829293050672898770
  s21_decimal dec_check = {{0xce0ae2d2, 0x4ab2a7c6, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_85) {
  // 112162754088136026982312766
  s21_decimal dec_1 = {{0x39f9eb3e, 0x152cdb90, 0x5cc763, 0x0}};
  // -69
  s21_decimal dec_2 = {{0x45, 0x0, 0x0, 0x80000000}};
  // -7739230032081385861779580854
  s21_decimal dec_check = {{0xa05c67b6, 0xb5172ddf, 0x1901bdb4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_86) {
  // -1800528614286598
  s21_decimal dec_1 = {{0x3c766506, 0x66592, 0x0, 0x80000000}};
  // -585163.3
  s21_decimal dec_2 = {{0x5949f1, 0x0, 0x0, 0x80010000}};
  // 1053603265680372831453.4
  s21_decimal dec_check = {{0xcd59d0a6, 0x28d35711, 0x23b, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_87) {
  // -21131958463006876166145755
  s21_decimal dec_1 = {{0x878a46db, 0xc3835e58, 0x117add, 0x80000000}};
  // 2364.1322102828151157187409354
  s21_decimal dec_2 = {{0xa893f5ca, 0x373e3206, 0x4c63a4af, 0x190000}};
  // -49958743668753086673945407472
  s21_decimal dec_check = {{0xd6e8aff0, 0x3f30351, 0xa16ce779, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_88) {
  // -0.870754827863956795561115
  s21_decimal dec_1 = {{0x836e149b, 0xb6bbd577, 0xb863, 0x80180000}};
  // 2131
  s21_decimal dec_2 = {{0x853, 0x0, 0x0, 0x0}};
  // -1855.578538178091931340736065
  s21_decimal dec_check = {{0xd558641, 0x1d91f1db, 0x5fee60a, 0x80180000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_89) {
  // 156.8
  s21_decimal dec_1 = {{0x620, 0x0, 0x0, 0x10000}};
  // -90
  s21_decimal dec_2 = {{0x5a, 0x0, 0x0, 0x80000000}};
  // -14112.0
  s21_decimal dec_check = {{0x22740, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_90) {
  // -0.543503
  s21_decimal dec_1 = {{0x84b0f, 0x0, 0x0, 0x80060000}};
  // -7453679
  s21_decimal dec_2 = {{0x71bbef, 0x0, 0x0, 0x80000000}};
  // 4051096.897537
  s21_decimal dec_check = {{0x38310801, 0x3af, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_91) {
  // 5053234206
  s21_decimal dec_1 = {{0x2d323c1e, 0x1, 0x0, 0x0}};
  // -5145454973144294186
  s21_decimal dec_2 = {{0x4a08632a, 0x47685409, 0x0, 0x80000000}};
  // -26001189075725558754422126316
  s21_decimal dec_check = {{0x646d76ec, 0x27c858ac, 0x5403adf4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_92) {
  // -8041719.992553634262592430
  s21_decimal dec_1 = {{0x583aabae, 0x83aaa0f6, 0x6a6e6, 0x80120000}};
  // -56574730097
  s21_decimal dec_2 = {{0x2c1ddf71, 0xd, 0x0, 0x80000000}};
  // 454958138094370708.20261835077
  s21_decimal dec_check = {{0x7b893145, 0x8f33cee7, 0x93014150, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_93) {
  // -3430658927575
  s21_decimal dec_1 = {{0xc334ebd7, 0x31e, 0x0, 0x80000000}};
  // -7027057273460446.447813324
  s21_decimal dec_2 = {{0xe9c842cc, 0x89c12331, 0x5d009, 0x80090000}};
  // 24107436769777918719835976318
  s21_decimal dec_check = {{0x46d7327e, 0xf1482ca5, 0x4de5344d, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_94) {
  // 0.785372220893269
  s21_decimal dec_1 = {{0xb83e2855, 0x2ca4a, 0x0, 0xf0000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0.000000000000000
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_95) {
  // 2839429.824364466267746919265
  s21_decimal dec_1 = {{0x8aae361, 0x35b5be41, 0x92cb8a7, 0x150000}};
  // 785359.4
  s21_decimal dec_2 = {{0x77d61a, 0x0, 0x0, 0x10000}};
  // 2229972903204.9826093579598658
  s21_decimal dec_check = {{0x4d7b7b42, 0x1e8c1244, 0x480de74d, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_96) {
  // -65287
  s21_decimal dec_1 = {{0xff07, 0x0, 0x0, 0x80000000}};
  // -8934496287486175261.65670
  s21_decimal dec_2 = {{0x7b2e40a6, 0x5d5fdb, 0xbd32, 0x80050000}};
  // 583306459121109924307780.97290
  s21_decimal dec_check = {{0x70a91e8a, 0x5093eb3, 0xbc79fabb, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_97) {
  // 3481.15659368687
  s21_decimal dec_1 = {{0xfe37a8ef, 0x13c9b, 0x0, 0xb0000}};
  // 2.6940
  s21_decimal dec_2 = {{0x693c, 0x0, 0x0, 0x40000}};
  // 9378.235863392427780
  s21_decimal dec_check = {{0x69559f04, 0x82262fd4, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_98) {
  // -6.7
  s21_decimal dec_1 = {{0x43, 0x0, 0x0, 0x80010000}};
  // -24860456524947
  s21_decimal dec_2 = {{0x46ae1c93, 0x169c, 0x0, 0x80000000}};
  // 166565058717144.9
  s21_decimal dec_check = {{0x7f917a79, 0x5eae6, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_99) {
  // 1373763646
  s21_decimal dec_1 = {{0x51e1f83e, 0x0, 0x0, 0x0}};
  // -2857031211.32
  s21_decimal dec_2 = {{0x853ba8ec, 0x42, 0x0, 0x80020000}};
  // -3924885613598759672.72
  s21_decimal dec_check = {{0x33838928, 0x46df7b10, 0x15, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_100) {
  // 60059078804670674
  s21_decimal dec_1 = {{0xf9b088d2, 0xd55f69, 0x0, 0x0}};
  // 1955767977
  s21_decimal dec_2 = {{0x7492a6a9, 0x0, 0x0, 0x0}};
  // 117461623054294342240206498
  s21_decimal dec_check = {{0x7e067ea2, 0x584f198b, 0x612977, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_101) {
  // 94538895875.66624807
  s21_decimal dec_1 = {{0xb4ac4027, 0x8332f67d, 0x0, 0x80000}};
  // 42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x0}};
  // 3970633626777.98241894
  s21_decimal dec_check = {{0xa4428666, 0x865c709f, 0x15, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_102) {
  // -68035136336659439127061
  s21_decimal dec_1 = {{0x30e78a15, 0x312f8097, 0xe68, 0x80000000}};
  // -4.34769
  s21_decimal dec_2 = {{0x6a251, 0x0, 0x0, 0x80050000}};
  // 295795681899530876898331.83909
  s21_decimal dec_check = {{0x3b21faa5, 0xa2f28236, 0x5f93a534, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_103) {
  // 42.378650
  s21_decimal dec_1 = {{0x286a59a, 0x0, 0x0, 0x60000}};
  // -2983067954.998509043940910
  s21_decimal dec_2 = {{0x76237e2e, 0x701883bf, 0x277b0, 0x800f0000}};
  // -126418392791.09756529500644557
  s21_decimal dec_check = {{0x760664cd, 0x87fab21e, 0x28d91598, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_104) {
  // 257549.34074092086552
  s21_decimal dec_1 = {{0xbbdce518, 0x656be815, 0x1, 0xe0000}};
  // 507990.4377036516004
  s21_decimal dec_2 = {{0xce36aaa4, 0x467f721d, 0x0, 0xd0000}};
  // 130832602333.26730005223692103
  s21_decimal dec_check = {{0xda55d747, 0x688681d1, 0x2a46381e, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_105) {
  // 78178062616188763407
  s21_decimal dec_1 = {{0x8a2d3d0f, 0x3cf045be, 0x4, 0x0}};
  // -41706.978464175877915
  s21_decimal dec_2 = {{0xac11ef1b, 0x42ccf3f0, 0x2, 0x800f0000}};
  // -3260570773904378047826214.9918
  s21_decimal dec_check = {{0x7575831e, 0x4e103161, 0x695acf2e, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_106) {
  // -1584942794.91974566605
  s21_decimal dec_1 = {{0x929f92cd, 0x978ccb75, 0x8, 0x800b0000}};
  // -6799277799
  s21_decimal dec_2 = {{0x9544bee7, 0x1, 0x0, 0x80000000}};
  // 10776466358182836693.900233024
  s21_decimal dec_check = {{0x8cec8940, 0xdce9951d, 0x22d21583, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_107) {
  // 99701078457992
  s21_decimal dec_1 = {{0x775d7e88, 0x5aad, 0x0, 0x0}};
  // -43860153985.132
  s21_decimal dec_2 = {{0xfce5e86c, 0x27e3, 0x0, 0x80030000}};
  // -4372904653651256016254574.944
  s21_decimal dec_check = {{0x25c4a160, 0x472d2f23, 0xe212e94, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_108) {
  // -0.484523216447
  s21_decimal dec_1 = {{0xcfd58e3f, 0x70, 0x0, 0x800c0000}};
  // 665542566620393991624809
  s21_decimal dec_2 = {{0xbdb4d869, 0x2284419a, 0x8cef, 0x0}};
  // -322470825061305075288445.63632
  s21_decimal dec_check = {{0x733354b0, 0x792a3145, 0x68322955, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_109) {
  // -670864051
  s21_decimal dec_1 = {{0x27fc92b3, 0x0, 0x0, 0x80000000}};
  // 76.9
  s21_decimal dec_2 = {{0x301, 0x0, 0x0, 0x10000}};
  // -51589445521.9
  s21_decimal dec_check = {{0x1db4abb3, 0x78, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_110) {
  // 285.5662967
  s21_decimal dec_1 = {{0xaa35f577, 0x0, 0x0, 0x70000}};
  // -6.88502
  s21_decimal dec_2 = {{0xa8176, 0x0, 0x0, 0x80050000}};
  // -1966.129664105434
  s21_decimal dec_check = {{0x3c361bda, 0x6fc2f, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_111) {
  // -953916702504800977013
  s21_decimal dec_1 = {{0x5ea38075, 0xb640eadc, 0x33, 0x80000000}};
  // 662649.949343538030
  s21_decimal dec_2 = {{0x390d5b6e, 0x932349e, 0x0, 0xc0000}};
  // -632112854592761204435410015.52
  s21_decimal dec_check = {{0x5be81550, 0x7057a53, 0xcc3f265b, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_112) {
  // -5298228132189155519385
  s21_decimal dec_1 = {{0xa3fa6b99, 0x37af8f02, 0x11f, 0x80000000}};
  // 31404
  s21_decimal dec_2 = {{0x7aac, 0x0, 0x0, 0x0}};
  // -166385556263268239930766540
  s21_decimal dec_check = {{0x838734cc, 0x141b57eb, 0x89a183, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_113) {
  // -12194625867194149131522
  s21_decimal dec_1 = {{0xf11c5502, 0x126e2050, 0x295, 0x80000000}};
  // 3821.882
  s21_decimal dec_2 = {{0x3a513a, 0x0, 0x0, 0x30000}};
  // -46606421098563709071079564.404
  s21_decimal dec_check = {{0xd9c4e474, 0x57838f0b, 0x9697ed8e, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_114) {
  // 9.35
  s21_decimal dec_1 = {{0x3a7, 0x0, 0x0, 0x20000}};
  // 1739.6
  s21_decimal dec_2 = {{0x43f4, 0x0, 0x0, 0x10000}};
  // 16265.260
  s21_decimal dec_check = {{0xf8302c, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_115) {
  // -626332118
  s21_decimal dec_1 = {{0x255511d6, 0x0, 0x0, 0x80000000}};
  // 859725108
  s21_decimal dec_2 = {{0x333e5d34, 0x0, 0x0, 0x0}};
  // -538473447791418744
  s21_decimal dec_check = {{0x70965d78, 0x7790abf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_116) {
  // -836770879494806904532210
  s21_decimal dec_1 = {{0x78a06cf2, 0x70b59a66, 0xb131, 0x80000000}};
  // 177.29592529831480366
  s21_decimal dec_2 = {{0x71064c2e, 0xf60c2a78, 0x0, 0x110000}};
  // -148356067342716463460323705.96
  s21_decimal dec_check = {{0x5a42d3a4, 0x9267b4d1, 0x2fefb9ec, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_117) {
  // 193450088950966535461163919
  s21_decimal dec_1 = {{0xcc12538f, 0x55dd45bf, 0xa004a6, 0x0}};
  // -2.99328731
  s21_decimal dec_2 = {{0x11d764db, 0x0, 0x0, 0x80080000}};
  // -579051696375299342830566956.57
  s21_decimal dec_check = {{0x84594969, 0xf5240ab1, 0xbb1a089f, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_118) {
  // -24127808161
  s21_decimal dec_1 = {{0x9e2122a1, 0x5, 0x0, 0x80000000}};
  // 178944861
  s21_decimal dec_2 = {{0xaaa7b5d, 0x0, 0x0, 0x0}};
  // -4317547277604810621
  s21_decimal dec_check = {{0xa696ef7d, 0x3beb025f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_119) {
  // 70596217022484679
  s21_decimal dec_1 = {{0xa61c90c7, 0xfacee2, 0x0, 0x0}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -423577302134908074
  s21_decimal dec_check = {{0xe4ab64aa, 0x5e0d94f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_120) {
  // -71598731407.0
  s21_decimal dec_1 = {{0xb42b6596, 0xa6, 0x0, 0x80010000}};
  // 8.18
  s21_decimal dec_2 = {{0x332, 0x0, 0x0, 0x20000}};
  // -585677622909.260
  s21_decimal dec_check = {{0xb2aa994c, 0x214ab, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_121) {
  // -0.725958640508628962376697
  s21_decimal dec_1 = {{0x3c37fbf9, 0x4bf860e0, 0x99ba, 0x80180000}};
  // 75448443271288
  s21_decimal dec_2 = {{0xb5a8f878, 0x449e, 0x0, 0x0}};
  // -54772449305716.650942332302078
  s21_decimal dec_check = {{0x866e72fe, 0x7b028bc4, 0xb0fab54a, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_122) {
  // 35115903807.42372
  s21_decimal dec_1 = {{0xd93da6e4, 0xc79c5, 0x0, 0x50000}};
  // -96107487024
  s21_decimal dec_2 = {{0x6073df30, 0x16, 0x0, 0x80000000}};
  // -3374901269508007364769.80928
  s21_decimal dec_check = {{0xe85be6c0, 0x710e3a34, 0x1172a50, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_123) {
  // 8109045739.73131
  s21_decimal dec_1 = {{0x6f14128b, 0x2e183, 0x0, 0x50000}};
  // -4.734
  s21_decimal dec_2 = {{0x127e, 0x0, 0x0, 0x80030000}};
  // -38388222531.88802154
  s21_decimal dec_check = {{0x152ee66a, 0x35463c80, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_124) {
  // -691284514119264487
  s21_decimal dec_1 = {{0x5ecea8e7, 0x997ef9a, 0x0, 0x80000000}};
  // 0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
  // -69128451411926448.7
  s21_decimal dec_check = {{0x5ecea8e7, 0x997ef9a, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_125) {
  // 7374
  s21_decimal dec_1 = {{0x1cce, 0x0, 0x0, 0x0}};
  // 557
  s21_decimal dec_2 = {{0x22d, 0x0, 0x0, 0x0}};
  // 4107318
  s21_decimal dec_check = {{0x3eac36, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_126) {
  // -427188614088.71963856145859271
  s21_decimal dec_1 = {{0x40dc2c7, 0x47c243ca, 0x8a0836c5, 0x80110000}};
  // -23.77782388896723611

  s21_decimal dec_2 = {{0x135e729b, 0x20ff947c, 0x0, 0x80110000}};
  // 10157615633173.563426448840460
  s21_decimal dec_check = {{0xd11f970c, 0xd68587b3, 0x20d22ec6, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_127) {
  // 0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};
  // -9211219
  s21_decimal dec_2 = {{0x8c8d53, 0x0, 0x0, 0x80000000}};
  // -2763365.7
  s21_decimal dec_check = {{0x1a5a7f9, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_129) {
  // -36
  s21_decimal dec_1 = {{0x24, 0x0, 0x0, 0x80000000}};
  // 5559736462
  s21_decimal dec_2 = {{0x4b62d88e, 0x1, 0x0, 0x0}};
  // -200150512632
  s21_decimal dec_check = {{0x99e673f8, 0x2e, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_130) {
  // -111573.63839607
  s21_decimal dec_1 = {{0xc6b55277, 0xa25, 0x0, 0x80080000}};
  // 695825840320060768
  s21_decimal dec_2 = {{0x45d09d60, 0x9a811ea, 0x0, 0x0}};
  // -77635820694512004842400.452382
  s21_decimal dec_check = {{0x7270f1e, 0xfbf7ce46, 0xfadad880, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_131) {
  // -14797895.5168570071
  s21_decimal dec_1 = {{0x610e5ad7, 0x20dba13, 0x0, 0x800a0000}};
  // -445411355933576366410
  s21_decimal dec_2 = {{0xc1e5894a, 0x25530454, 0x18, 0x80000000}};
  // 6591150707126670400797814092.0
  s21_decimal dec_check = {{0x251c4f8, 0xec4d29ac, 0xd4f8b885, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_132) {
  // 963349590770247
  s21_decimal dec_1 = {{0x4e270247, 0x36c29, 0x0, 0x0}};
  // -78252351086.385643796365
  s21_decimal dec_2 = {{0xc0f6378d, 0x11861a57, 0x1092, 0x800c0000}};
  // -75384370395879303200349549.218
  s21_decimal dec_check = {{0x9d3ef2a2, 0xbbb3ef12, 0xf3947d5b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_133) {
  // -25250900750
  s21_decimal dec_1 = {{0xe1122b0e, 0x5, 0x0, 0x80000000}};
  // 53710620
  s21_decimal dec_2 = {{0x3338f1c, 0x0, 0x0, 0x0}};
  // -1356241534840965000
  s21_decimal dec_check = {{0x81d38788, 0x12d2567d, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_134) {
  // -636037903393446578
  s21_decimal dec_1 = {{0x6f735ab2, 0x8d3a91a, 0x0, 0x80000000}};
  // 1410706
  s21_decimal dec_2 = {{0x158692, 0x0, 0x0, 0x0}};
  // -897262486544555448264068
  s21_decimal dec_check = {{0x61dce584, 0xb2656be0, 0xbe00, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_135) {
  // 98
  s21_decimal dec_1 = {{0x62, 0x0, 0x0, 0x0}};
  // -4865900414349.8
  s21_decimal dec_2 = {{0x4ea8378a, 0x2c41, 0x0, 0x80010000}};
  // -476858240606280.4
  s21_decimal dec_check = {{0x1c6542d4, 0x10f100, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_136) {
  // 92024.084599185810
  s21_decimal dec_1 = {{0xd950a192, 0x146ef6a, 0x0, 0xc0000}};
  // 80.6748015952005014
  s21_decimal dec_2 = {{0xd2120796, 0xb32250b, 0x0, 0x100000}};
  // 7424024.7670192612780852221438
  s21_decimal dec_check = {{0xa1fd95fe, 0x7e8650c9, 0xefe217f2, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_137) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -98478772803080636
  s21_decimal dec_2 = {{0xed811bc, 0x15dddec, 0x0, 0x80000000}};
  // 393915091212322544
  s21_decimal dec_check = {{0x3b6046f0, 0x57777b0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_138) {
  // -59897
  s21_decimal dec_1 = {{0xe9f9, 0x0, 0x0, 0x80000000}};
  // 159142301864609.6
  s21_decimal dec_2 = {{0xbb6ba50, 0x5a764, 0x0, 0x10000}};
  // -9532146454784521211.2
  s21_decimal dec_check = {{0xb44e07d0, 0x2ad9def8, 0x5, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_139) {
  // 87517290635727
  s21_decimal dec_1 = {{0xb50521cf, 0x4f98, 0x0, 0x0}};
  // 784
  s21_decimal dec_2 = {{0x310, 0x0, 0x0, 0x0}};
  // 68613555858409968
  s21_decimal dec_check = {{0x5fb789f0, 0xf3c3aa, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_140) {
  // 6940088402697939077902137
  s21_decimal dec_1 = {{0x1e652f39, 0xf2385985, 0x5bd9e, 0x0}};
  // 109.6546807929104465869
  s21_decimal dec_2 = {{0xbac37fcd, 0x71a4d80e, 0x3b, 0x130000}};
  // 761013178472422240982642265.13
  s21_decimal dec_check = {{0x9a101ad1, 0xf31223c9, 0xf5e588e2, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_141) {
  // 6825.0210081718910679698542
  s21_decimal dec_1 = {{0xec6cc6e, 0x4d5a54a4, 0x38748b, 0x160000}};
  // 35544
  s21_decimal dec_2 = {{0x8ad8, 0x0, 0x0, 0x0}};
  // 242588546.71446169611992049768
  s21_decimal dec_check = {{0x5b382868, 0xd6f03d10, 0x4e62744a, 0x140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_142) {
  // -588283381.77
  s21_decimal dec_1 = {{0xb2713401, 0xd, 0x0, 0x80020000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -1764850145.31
  s21_decimal dec_check = {{0x17539c03, 0x29, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_143) {
  // 390874523105132
  s21_decimal dec_1 = {{0x9119f76c, 0x1637f, 0x0, 0x0}};
  // 4.9
  s21_decimal dec_2 = {{0x31, 0x0, 0x0, 0x10000}};
  // 1915285163215146.8
  s21_decimal dec_check = {{0xc5f85bac, 0x440b6a, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_144) {
  // 0.4041
  s21_decimal dec_1 = {{0xfc9, 0x0, 0x0, 0x40000}};
  // 679513.9
  s21_decimal dec_2 = {{0x67af83, 0x0, 0x0, 0x10000}};
  // 274591.56699
  s21_decimal dec_check = {{0x64b17adb, 0x6, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_145) {
  // -82761826742618381
  s21_decimal dec_1 = {{0x63f4c90d, 0x1260771, 0x0, 0x80000000}};
  // 7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x0}};
  // -579332787198328667
  s21_decimal dec_check = {{0xbbb17f5b, 0x80a3419, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_146) {
  // 89
  s21_decimal dec_1 = {{0x59, 0x0, 0x0, 0x0}};
  // 9.975509012142449
  s21_decimal dec_2 = {{0x2f1f5971, 0x2370ac, 0x0, 0xf0000}};
  // 887.820302080677961
  s21_decimal dec_check = {{0x61e61849, 0xc522bdc, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_147) {
  // -22.73901442669752300
  s21_decimal dec_1 = {{0x80942fec, 0x1f8e8550, 0x0, 0x80110000}};
  // 2587
  s21_decimal dec_2 = {{0xa1b, 0x0, 0x0, 0x0}};
  // -58825.83032186649200100
  s21_decimal dec_check = {{0x598045e4, 0xe53d3483, 0x13e, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_148) {
  // -2.5
  s21_decimal dec_1 = {{0x19, 0x0, 0x0, 0x80010000}};
  // 9.3
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x10000}};
  // -23.25
  s21_decimal dec_check = {{0x915, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_149) {
  // -11
  s21_decimal dec_1 = {{0xb, 0x0, 0x0, 0x80000000}};
  // -46047760.671119
  s21_decimal dec_2 = {{0x546ae18f, 0x29e1, 0x0, 0x80060000}};
  // 506525367.382309
  s21_decimal dec_check = {{0xa097b125, 0x1ccae, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_150) {
  // -8272
  s21_decimal dec_1 = {{0x2050, 0x0, 0x0, 0x80000000}};
  // -940466179.94668104
  s21_decimal dec_2 = {{0x99e62848, 0x14e1ee6, 0x0, 0x80080000}};
  // 7779536240518.94556288
  s21_decimal dec_check = {{0xdcf59680, 0x2c467b4c, 0x2a, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_151) {
  // 513714564
  s21_decimal dec_1 = {{0x1e9ea984, 0x0, 0x0, 0x0}};
  // 1012.8078758
  s21_decimal dec_2 = {{0x5bae37a6, 0x2, 0x0, 0x70000}};
  // 520294156332.3631512
  s21_decimal dec_check = {{0x15054798, 0x48348fc9, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_152) {
  // 3222820
  s21_decimal dec_1 = {{0x312d24, 0x0, 0x0, 0x0}};
  // -40421.60903784447
  s21_decimal dec_2 = {{0xeccb87ff, 0xe5c52, 0x0, 0x800b0000}};
  // -130271570039.34591480540
  s21_decimal dec_check = {{0x1b55f2dc, 0x341ee23e, 0x2c2, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_153) {
  // 1630876279.2329
  s21_decimal dec_1 = {{0x2e035189, 0xed5, 0x0, 0x40000}};
  // -9.73
  s21_decimal dec_2 = {{0x3cd, 0x0, 0x0, 0x80020000}};
  // -15868426196.936117
  s21_decimal dec_check = {{0xe29ce5b5, 0x38603f, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_154) {
  // -829956.771674
  s21_decimal dec_1 = {{0x3d474f5a, 0xc1, 0x0, 0x80060000}};
  // 8696.130100
  s21_decimal dec_2 = {{0x6546a34, 0x2, 0x0, 0x60000}};
  // -7217412063.853098787400
  s21_decimal dec_check = {{0x1edf6248, 0x41b69096, 0x187, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_155) {
  // 71281499038838
  s21_decimal dec_1 = {{0x846de476, 0x40d4, 0x0, 0x0}};
  // 4736.6
  s21_decimal dec_2 = {{0xb906, 0x0, 0x0, 0x10000}};
  // 337631948347360070.8
  s21_decimal dec_check = {{0x84aca0c4, 0x2edb18ae, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_156) {
  // 0.58
  s21_decimal dec_1 = {{0x3a, 0x0, 0x0, 0x20000}};
  // 849988782035063252
  s21_decimal dec_2 = {{0x384451d4, 0xbcbc44b, 0x0, 0x0}};
  // 492993493580336686.16
  s21_decimal dec_check = {{0xbf7a8a08, 0xac2a790a, 0x2, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_157) {
  // 9197.086214
  s21_decimal dec_1 = {{0x24306606, 0x2, 0x0, 0x60000}};
  // 75.788281926846958
  s21_decimal dec_2 = {{0x766309ee, 0x10d410a, 0x0, 0xf0000}};
  // 697031.362892149513909637012
  s21_decimal dec_check = {{0x90e70f94, 0xe59be53d, 0x2409221, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_158) {
  // 515.00611715441
  s21_decimal dec_1 = {{0xebaac171, 0x2ed6, 0x0, 0xb0000}};
  // -3073242430673714057212
  s21_decimal dec_2 = {{0x24c68ffc, 0x99ce6bf6, 0xa6, 0x80000000}};
  // -1582738651295450534293396.1534
  s21_decimal dec_check = {{0x860a8b3e, 0x1b0c086e, 0x33241b76, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_159) {
  // 840.928033
  s21_decimal dec_1 = {{0x321f8b21, 0x0, 0x0, 0x60000}};
  // 0.550867815
  s21_decimal dec_2 = {{0x20d59367, 0x0, 0x0, 0x90000}};
  // 463.240188110957895
  s21_decimal dec_check = {{0x2a09ed47, 0x66dc27f, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_161) {
  // 0.03
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x20000}};
  // -95171912239307
  s21_decimal dec_2 = {{0xf00588cb, 0x568e, 0x0, 0x80000000}};
  // -2855157367179.21
  s21_decimal dec_check = {{0xd0109a61, 0x103ac, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_162) {
  // 9384443.37
  s21_decimal dec_1 = {{0x37ef8631, 0x0, 0x0, 0x20000}};
  // -93971
  s21_decimal dec_2 = {{0x16f13, 0x0, 0x0, 0x80000000}};
  // -881865527922.27
  s21_decimal dec_check = {{0x882734a3, 0x5034, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_163) {
  // 6000833095014.716026
  s21_decimal dec_1 = {{0xf8c2927a, 0x53473de7, 0x0, 0x60000}};
  // -401
  s21_decimal dec_2 = {{0x191, 0x0, 0x0, 0x80000000}};
  // -2406334071100901.126426
  s21_decimal dec_check = {{0xa8c7711a, 0x7297f85c, 0x82, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_165) {
  // 95
  s21_decimal dec_1 = {{0x5f, 0x0, 0x0, 0x0}};
  // 58175661077906314
  s21_decimal dec_2 = {{0x9d1f438a, 0xceae74, 0x0, 0x0}};
  // 5526687802401099830
  s21_decimal dec_check = {{0x4e9a1036, 0x4cb2bd46, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_166) {
  // -66627157143318074283
  s21_decimal dec_1 = {{0x819a93ab, 0x9ca3366a, 0x3, 0x80000000}};
  // -998.09663660
  s21_decimal dec_2 = {{0x3d1e9aac, 0x17, 0x0, 0x80080000}};
  // 66500341450965434105851.256558
  s21_decimal dec_check = {{0x52379eee, 0x9bb4d964, 0xd6dfcb0d, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_167) {
  // -75209458087890414.2
  s21_decimal dec_1 = {{0x5ac88b4e, 0xa6ffa09, 0x0, 0x80010000}};
  // 0.60767469
  s21_decimal dec_2 = {{0x39f3ced, 0x0, 0x0, 0x80000}};
  // -45702884128626800.202956598
  s21_decimal dec_check = {{0x7bc13f36, 0x50246820, 0x25cdf6, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_168) {
  // 8477.44782402224509382
  s21_decimal dec_1 = {{0xeb69d1c6, 0xf4d27c0c, 0x2d, 0x110000}};
  // -61083072263.491745817644
  s21_decimal dec_2 = {{0x9d49242c, 0x51ea5fa8, 0xcef, 0x800c0000}};
  // -517828558044731.65389706244225
  s21_decimal dec_check = {{0x81e33081, 0x921bb82, 0xa751c63e, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_169) {
  // -313752478958887196
  s21_decimal dec_1 = {{0x9fbe211c, 0x45aac37, 0x0, 0x80000000}};
  // -0.31
  s21_decimal dec_2 = {{0x1f, 0x0, 0x0, 0x80020000}};
  // 97263268477255030.76
  s21_decimal dec_check = {{0x58060264, 0x86fadabc, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_170) {
  // -6044
  s21_decimal dec_1 = {{0x179c, 0x0, 0x0, 0x80000000}};
  // -9277846943425020
  s21_decimal dec_2 = {{0x1357e1fc, 0x20f627, 0x0, 0x80000000}};
  // 56075306926060820880
  s21_decimal dec_check = {{0xaedb5990, 0xa33828c, 0x3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_171) {
  // -44713427
  s21_decimal dec_1 = {{0x2aa45d3, 0x0, 0x0, 0x80000000}};
  // -87328232300096
  s21_decimal dec_2 = {{0xb043de40, 0x4f6c, 0x0, 0x80000000}};
  // 3904744539989384588992
  s21_decimal dec_check = {{0xa9576ec0, 0xad3756e5, 0xd3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_172) {
  // 304027
  s21_decimal dec_1 = {{0x4a39b, 0x0, 0x0, 0x0}};
  // -157786281011350
  s21_decimal dec_2 = {{0x7b3ae896, 0x8f81, 0x0, 0x80000000}};
  // -47971289657037706450
  s21_decimal dec_check = {{0xc11a54d2, 0x99bc41c7, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_173) {
  // 62355113983823408
  s21_decimal dec_1 = {{0x52ef4e30, 0xdd87a5, 0x0, 0x0}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // 24942045593529363.2
  s21_decimal dec_check = {{0x4bbd38c0, 0x3761e95, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_174) {
  // -3839641700868496971
  s21_decimal dec_1 = {{0x9d0b1e4b, 0x354925c8, 0x0, 0x80000000}};
  // 22
  s21_decimal dec_2 = {{0x16, 0x0, 0x0, 0x0}};
  // -84472117419106933362
  s21_decimal dec_check = {{0x7ef49a72, 0x94493f3d, 0x4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_175) {
  // -255.69582566792
  s21_decimal dec_1 = {{0x61e2cd88, 0x1741, 0x0, 0x800b0000}};
  // 94255.61275
  s21_decimal dec_2 = {{0x31cea6bb, 0x2, 0x0, 0x50000}};
  // -24100766.7259469776179800
  s21_decimal dec_check = {{0xfd625258, 0xd442b23, 0x3309, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_176) {
  // -86251
  s21_decimal dec_1 = {{0x150eb, 0x0, 0x0, 0x80000000}};
  // 228
  s21_decimal dec_2 = {{0xe4, 0x0, 0x0, 0x0}};
  // -19665228
  s21_decimal dec_check = {{0x12c114c, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_177) {
  // -810489098.21336862342517885
  s21_decimal dec_1 = {{0x5df0147d, 0x348e21b9, 0x430ac6, 0x80110000}};
  // -0.89
  s21_decimal dec_2 = {{0x59, 0x0, 0x0, 0x80020000}};
  // 721335297.4098980748484091765
  s21_decimal dec_check = {{0xa8771f75, 0x4569b971, 0x174ebee8, 0x130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_178) {
  // 0.284
  s21_decimal dec_1 = {{0x11c, 0x0, 0x0, 0x30000}};
  // 3407201
  s21_decimal dec_2 = {{0x33fd61, 0x0, 0x0, 0x0}};
  // 967645.084
  s21_decimal dec_check = {{0x39ad179c, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_179) {
  // 4489249275.41325006564271
  s21_decimal dec_1 = {{0x7c72ebaf, 0x44e2d4a1, 0x5f10, 0xe0000}};
  // -705659009352.5333878782
  s21_decimal dec_2 = {{0x608a7fe, 0x89dc26a5, 0x17e, 0x800a0000}};
  // -3167879196424692362881.8072707
  s21_decimal dec_check = {{0x214a0483, 0x77b76f59, 0x665c1521, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_180) {
  // 2995334808186313
  s21_decimal dec_1 = {{0xbb39adc9, 0xaa43d, 0x0, 0x0}};
  // -9757346.8
  s21_decimal dec_2 = {{0x5d0da5c, 0x0, 0x0, 0x80010000}};
  // -29226520505585334954348.4
  s21_decimal dec_check = {{0x87079e3c, 0xba7fd6e0, 0x3de3, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_181) {
  // 361
  s21_decimal dec_1 = {{0x169, 0x0, 0x0, 0x0}};
  // -929787650995022218547234.7882
  s21_decimal dec_2 = {{0x9d1a4eea, 0x945a0428, 0x1e0b05ef, 0x80040000}};
  // -335653342009203020895551758.54
  s21_decimal dec_check = {{0x55dc69ae, 0xabfd6b1, 0x6c7497fd, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_182) {
  // 7153671804179588878
  s21_decimal dec_1 = {{0xa7da270e, 0x6346f29a, 0x0, 0x0}};
  // 2.8
  s21_decimal dec_2 = {{0x1c, 0x0, 0x0, 0x10000}};
  // 20030281051702848858.4
  s21_decimal dec_check = {{0x5bdc4588, 0xdbc288ea, 0xa, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_183) {
  // 195.404566
  s21_decimal dec_1 = {{0xba5a316, 0x0, 0x0, 0x60000}};
  // 52742245879823488277
  s21_decimal dec_2 = {{0xf3305515, 0xdbf2192f, 0x2, 0x0}};
  // 10306075666012196883373.272782
  s21_decimal dec_check = {{0x69dcaece, 0x583283c5, 0x214cfc69, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_184) {
  // -5.266559071185344283856117
  s21_decimal dec_1 = {{0x81dcccf5, 0xbd446939, 0x45b3c, 0x80180000}};
  // 8828956138
  s21_decimal dec_2 = {{0xe3f2dea, 0x2, 0x0, 0x0}};
  // -46498219037.681424350594678496
  s21_decimal dec_check = {{0xacd33ee0, 0xde38a947, 0x963e6ce0, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_185) {
  // 9892681481399019909221
  s21_decimal dec_1 = {{0xd9ae3065, 0x4888d1a8, 0x218, 0x0}};
  // 42.03
  s21_decimal dec_2 = {{0x106b, 0x0, 0x0, 0x20000}};
  // 415789402663200806784558.63
  s21_decimal dec_check = {{0xded48a37, 0xde4a2f2d, 0x2264ae, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_186) {
  // -690685475362
  s21_decimal dec_1 = {{0xd00ffa22, 0xa0, 0x0, 0x80000000}};
  // -26.5
  s21_decimal dec_2 = {{0x109, 0x0, 0x0, 0x80010000}};
  // 18303165097093.0
  s21_decimal dec_check = {{0x6089ed32, 0xa677, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_187) {
  // -9.8
  s21_decimal dec_1 = {{0x62, 0x0, 0x0, 0x80010000}};
  // 8361995
  s21_decimal dec_2 = {{0x7f980b, 0x0, 0x0, 0x0}};
  // -81947551.0
  s21_decimal dec_check = {{0x30d83436, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_188) {
  // 2998462.5711894109369207566
  s21_decimal dec_1 = {{0x51c90b0e, 0xd1205c02, 0x18cd7d, 0x130000}};
  // -0.51
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80020000}};
  // -1529215.911306599577829585866
  s21_decimal dec_check = {{0x4b0d33ca, 0xa9725476, 0x4f0f010, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_189) {
  // -635095
  s21_decimal dec_1 = {{0x9b0d7, 0x0, 0x0, 0x80000000}};
  // -910266066
  s21_decimal dec_2 = {{0x36418ed2, 0x0, 0x0, 0x80000000}};
  // 578105427186270
  s21_decimal dec_check = {{0xa8a1525e, 0x20dc8, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_190) {
  // 5272
  s21_decimal dec_1 = {{0x1498, 0x0, 0x0, 0x0}};
  // -402
  s21_decimal dec_2 = {{0x192, 0x0, 0x0, 0x80000000}};
  // -2119344
  s21_decimal dec_check = {{0x2056b0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_191) {
  // 448927341409786
  s21_decimal dec_1 = {{0xab6f5fa, 0x1984c, 0x0, 0x0}};
  // -9157449370057
  s21_decimal dec_2 = {{0x228449c9, 0x854, 0x0, 0x80000000}};
  // -4111029399794408575995177802
  s21_decimal dec_check = {{0x9eb36b4a, 0x52089bcc, 0xd489056, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_192) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -528674663
  s21_decimal dec_2 = {{0x1f82ef67, 0x0, 0x0, 0x80000000}};
  // 1586023989
  s21_decimal dec_check = {{0x5e88ce35, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_193) {
  // -52995759811099
  s21_decimal dec_1 = {{0x9702a1b, 0x3033, 0x0, 0x80000000}};
  // -8.908948544511431345
  s21_decimal dec_2 = {{0xe5d652b1, 0x7ba2f17f, 0x0, 0x80120000}};
  // 472136497234367.84380934330750
  s21_decimal dec_check = {{0x3d13997e, 0xe5559fd, 0x988e3738, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_194) {
  // 837966936751
  s21_decimal dec_1 = {{0x1ab8baaf, 0xc3, 0x0, 0x0}};
  // 6.58302
  s21_decimal dec_2 = {{0xa0b7e, 0x0, 0x0, 0x50000}};
  // 5516353103970.56802
  s21_decimal dec_check = {{0x61c76722, 0x7a7cd64, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_195) {
  // -88780175089255775041.4493071
  s21_decimal dec_1 = {{0x5792458f, 0x5a4b0656, 0x2de5f55, 0x80070000}};
  // -19.5287187936
  s21_decimal dec_2 = {{0x780601e0, 0x2d, 0x0, 0x800a0000}};
  // 1733763073764647811489.2849025
  s21_decimal dec_check = {{0xb6e49f81, 0x934ca96e, 0x38055a1d, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_196) {
  // -807194.01827392600359
  s21_decimal dec_1 = {{0xd3c0b927, 0x6034ec4a, 0x4, 0x800e0000}};
  // -4700007720
  s21_decimal dec_2 = {{0x18246d28, 0x1, 0x0, 0x80000000}};
  // 3793818117425273.2915817477148
  s21_decimal dec_check = {{0x1571741c, 0x76b355bf, 0x7a95ba5a, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_197) {
  // -59711888
  s21_decimal dec_1 = {{0x38f2190, 0x0, 0x0, 0x80000000}};
  // 2959
  s21_decimal dec_2 = {{0xb8f, 0x0, 0x0, 0x0}};
  // -176687476592
  s21_decimal dec_check = {{0x2364ef70, 0x29, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_198) {
  // 46.17586772
  s21_decimal dec_1 = {{0x133ac854, 0x1, 0x0, 0x80000}};
  // -4656418640
  s21_decimal dec_2 = {{0x158b4f50, 0x1, 0x0, 0x80000000}};
  // -215014171169.58230080
  s21_decimal dec_check = {{0xcfcc8640, 0x2a6460f2, 0x1, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_199) {
  // 700.55428387422
  s21_decimal dec_1 = {{0xcec725e, 0x3fb7, 0x0, 0xb0000}};
  // 727971.3
  s21_decimal dec_2 = {{0x6f1461, 0x0, 0x0, 0x10000}};
  // 509983412.752484969886
  s21_decimal dec_check = {{0xf548ad9e, 0xa5710be3, 0x1b, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_200) {
  // 1235
  s21_decimal dec_1 = {{0x4d3, 0x0, 0x0, 0x0}};
  // -85.2
  s21_decimal dec_2 = {{0x354, 0x0, 0x0, 0x80010000}};
  // -105222.0
  s21_decimal dec_check = {{0x100e3c, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_201) {
  // 40005753911041375414458
  s21_decimal dec_1 = {{0x136128ba, 0xb75d2686, 0x878, 0x0}};
  // 2.9
  s21_decimal dec_2 = {{0x1d, 0x0, 0x0, 0x10000}};
  // 116016686342019988701928.2
  s21_decimal dec_check = {{0x32019d12, 0xc58d5d30, 0xf5ac, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_202) {
  // 805069946352452
  s21_decimal dec_1 = {{0xf42bf344, 0x2dc34, 0x0, 0x0}};
  // -71199972490659
  s21_decimal dec_2 = {{0x89117da3, 0x40c1, 0x0, 0x80000000}};
  // -57320958033350899338691745868
  s21_decimal dec_check = {{0x7948184c, 0x6f7b334f, 0xb936c901, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_203) {
  // -773916.773003052
  s21_decimal dec_1 = {{0x8a572f2c, 0x2bfdf, 0x0, 0x80090000}};
  // 0.14712017504480
  s21_decimal dec_2 = {{0x6893c8e0, 0xd61, 0x0, 0xe0000}};
  // -113858.77111431575720463672960
  s21_decimal dec_check = {{0x1f67a680, 0xfe4c7e93, 0x24ca2d42, 0x80170000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_204) {
  // -50
  s21_decimal dec_1 = {{0x32, 0x0, 0x0, 0x80000000}};
  // 28338004359291
  s21_decimal dec_2 = {{0xf4aef87b, 0x19c5, 0x0, 0x0}};
  // -1416900217964550
  s21_decimal dec_check = {{0xca2c8806, 0x508a9, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_205) {
  // 4366650573.4581257925798406
  s21_decimal dec_1 = {{0x84d7aa06, 0x4e4aad7, 0x241ebe, 0x100000}};
  // -899733
  s21_decimal dec_2 = {{0xdba95, 0x0, 0x0, 0x80000000}};
  // -3928819620409199.8937352377226
  s21_decimal dec_check = {{0x1aca138a, 0xe02b8fd0, 0x7ef26f27, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_206) {
  // -849005
  s21_decimal dec_1 = {{0xcf46d, 0x0, 0x0, 0x80000000}};
  // -7167245611635.2399171789
  s21_decimal dec_2 = {{0xddfe0cd, 0x5f233ce0, 0xf2d, 0x800a0000}};
  // 6085027360506376865.8844719945
  s21_decimal dec_check = {{0xd4321b49, 0xf2871f1d, 0xc49e2aa5, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_207) {
  // 7889
  s21_decimal dec_1 = {{0x1ed1, 0x0, 0x0, 0x0}};
  // -1143341
  s21_decimal dec_2 = {{0x11722d, 0x0, 0x0, 0x80000000}};
  // -9019817149
  s21_decimal dec_check = {{0x199f7cbd, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_208) {
  // -9755587.97
  s21_decimal dec_1 = {{0x3a25d88d, 0x0, 0x0, 0x80020000}};
  // 2992245214215484847797
  s21_decimal dec_2 = {{0x99b6b5, 0x35be80bc, 0xa2, 0x0}};
  // -29191111415090656968885694202
  s21_decimal dec_check = {{0xb4546efa, 0xace60641, 0x5e525248, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_209) {
  // 384072234804.237
  s21_decimal dec_1 = {{0xc91fa40d, 0x15d4f, 0x0, 0x30000}};
  // -0.654383542286425213222
  s21_decimal dec_2 = {{0xc2f4926, 0x79655ca3, 0x23, 0x80150000}};
  // -251330549505.06025641390763215
  s21_decimal dec_check = {{0x3a2deccf, 0xed436777, 0x51359366, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_210) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // -55071.426750485732732017368
  s21_decimal dec_2 = {{0x16459ad8, 0x6b782af, 0x2d8dd4, 0x80150000}};
  // -165214.280251457198196052104
  s21_decimal dec_check = {{0x42d0d088, 0x1426880d, 0x88a97c, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_211) {
  // 842393680311043172
  s21_decimal dec_1 = {{0xcbf94464, 0xbb0c896, 0x0, 0x0}};
  // 4754374177
  s21_decimal dec_2 = {{0x1b61fe21, 0x1, 0x0, 0x0}};
  // 4005054760538816984888969444
  s21_decimal dec_check = {{0x12e108e4, 0x9d6f51df, 0xcf0e755, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_212) {
  // -125
  s21_decimal dec_1 = {{0x7d, 0x0, 0x0, 0x80000000}};
  // 6.983802356593822678665
  s21_decimal dec_2 = {{0x26ba3e89, 0x97ba298d, 0x17a, 0x150000}};
  // -872.975294574227834833125
  s21_decimal dec_check = {{0xe8f088e5, 0x15e649eb, 0xb8dc, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_213) {
  // 99993479
  s21_decimal dec_1 = {{0x5f5c787, 0x0, 0x0, 0x0}};
  // 32.02349261
  s21_decimal dec_2 = {{0xbedff8cd, 0x0, 0x0, 0x80000}};
  // 3202140435.80469019
  s21_decimal dec_check = {{0xdfb48f1b, 0x471a0f9, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_214) {
  // -647.02483387796496209
  s21_decimal dec_1 = {{0x2f391f51, 0x81ed65d5, 0x3, 0x80110000}};
  // -9122811773444096780449020.467
  s21_decimal dec_2 = {{0xd462fa33, 0x327d195e, 0x1d7a3689, 0x80030000}};
  // 5902685772212609647031917231.3
  s21_decimal dec_check = {{0x88760ad9, 0xddb85c52, 0xbeb9df50, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_215) {
  // -6755346206
  s21_decimal dec_1 = {{0x92a6671e, 0x1, 0x0, 0x80000000}};
  // -480231.139259
  s21_decimal dec_2 = {{0xd001a7bb, 0x6f, 0x0, 0x80060000}};
  // 3244127604596343.301354
  s21_decimal dec_check = {{0x73efe4ea, 0xdd508441, 0xaf, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_216) {
  // 27895876
  s21_decimal dec_1 = {{0x1a9a844, 0x0, 0x0, 0x0}};
  // -74
  s21_decimal dec_2 = {{0x4a, 0x0, 0x0, 0x80000000}};
  // -2064294824
  s21_decimal dec_check = {{0x7b0aa3a8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_217) {
  // -0.9448455765359546697278311
  s21_decimal dec_1 = {{0xa6146367, 0xd0392262, 0x7d0c9, 0x80190000}};
  // 523642757
  s21_decimal dec_2 = {{0x1f362785, 0x0, 0x0, 0x0}};
  // -494761542.63654181288330591683
  s21_decimal dec_check = {{0x15a2fdc3, 0xf1afef83, 0x9fddb730, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_218) {
  // -490
  s21_decimal dec_1 = {{0x1ea, 0x0, 0x0, 0x80000000}};
  // -454381296299874105715599
  s21_decimal dec_2 = {{0x56a46b8f, 0xf36c173, 0x6038, 0x80000000}};
  // 222646835186938311800643510
  s21_decimal dec_check = {{0xd6b5dfb6, 0x1ece46c3, 0xb82b4d, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_219) {
  // -38866210
  s21_decimal dec_1 = {{0x2510d22, 0x0, 0x0, 0x80000000}};
  // -83300.7825436
  s21_decimal dec_2 = {{0xf322b21c, 0xc1, 0x0, 0x80070000}};
  // 3237585707503.8917560
  s21_decimal dec_check = {{0xa08313b8, 0xc14e2679, 0x1, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_220) {
  // -96727
  s21_decimal dec_1 = {{0x179d7, 0x0, 0x0, 0x80000000}};
  // 8508.464908148114952
  s21_decimal dec_2 = {{0x120b8608, 0x761423c1, 0x0, 0xf0000}};
  // -822998285.170442714962104
  s21_decimal dec_check = {{0x200f58b8, 0xd3915ab9, 0xae46, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_221) {
  // -9423776712236406.5644
  s21_decimal dec_1 = {{0x9a7ee76c, 0x1bcfcde7, 0x5, 0x80040000}};
  // -0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80010000}};
  // 3769510684894562.62576
  s21_decimal dec_check = {{0x69fb9db0, 0x6f3f379e, 0x14, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_222) {
  // -44382442273.48863
  s21_decimal dec_1 = {{0x4298f97f, 0xfc48f, 0x0, 0x80050000}};
  // 38995061.672
  s21_decimal dec_2 = {{0x14496ba8, 0x9, 0x0, 0x30000}};
  // -1730696073608669017.44078936
  s21_decimal dec_check = {{0xb5e2d058, 0x36ef956d, 0x8f28ea, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_223) {
  // 775
  s21_decimal dec_1 = {{0x307, 0x0, 0x0, 0x0}};
  // 27.84767175837
  s21_decimal dec_2 = {{0x610eec9d, 0x288, 0x0, 0xb0000}};
  // 21581.94561273675
  s21_decimal dec_check = {{0xd42e4f4b, 0x7aadd, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_224) {
  // 3464262509906353
  s21_decimal dec_1 = {{0x784fc9b1, 0xc4eba, 0x0, 0x0}};
  // 907952497602
  s21_decimal dec_2 = {{0x662fa3c2, 0xd3, 0x0, 0x0}};
  // 3145385798218446473477065506
  s21_decimal dec_check = {{0x87618b22, 0xc96381cf, 0xa29cd59, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_225) {
  // -8811238
  s21_decimal dec_1 = {{0x8672e6, 0x0, 0x0, 0x80000000}};
  // -4.546
  s21_decimal dec_2 = {{0x11c2, 0x0, 0x0, 0x80030000}};
  // 40055887.948
  s21_decimal dec_check = {{0x5384584c, 0x9, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_226) {
  // 89.5471935716
  s21_decimal dec_1 = {{0x7e4960e4, 0xd0, 0x0, 0xa0000}};
  // -57888475
  s21_decimal dec_2 = {{0x3734edb, 0x0, 0x0, 0x80000000}};
  // -5183750476.3897273100
  s21_decimal dec_check = {{0x96b75b0c, 0xcf63cfef, 0x2, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_227) {
  // 526
  s21_decimal dec_1 = {{0x20e, 0x0, 0x0, 0x0}};
  // -356.8
  s21_decimal dec_2 = {{0xdf0, 0x0, 0x0, 0x80010000}};
  // -187676.8
  s21_decimal dec_check = {{0x1ca320, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_228) {
  // 57
  s21_decimal dec_1 = {{0x39, 0x0, 0x0, 0x0}};
  // 59074434337036.7481367814
  s21_decimal dec_2 = {{0x3b7f4d06, 0x50a55dad, 0x7d18, 0xa0000}};
  // 3367242757211094.6437965398
  s21_decimal dec_check = {{0x3f582656, 0xf4d1db92, 0x1bda69, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_229) {
  // 9253575303718008085
  s21_decimal dec_1 = {{0x10707515, 0x806b4db6, 0x0, 0x0}};
  // -3939469.057689645
  s21_decimal dec_2 = {{0x1dc9882d, 0xdfeed, 0x0, 0x80090000}};
  // -36454173581998151844865931.531
  s21_decimal dec_check = {{0xff36790b, 0xb034b03e, 0x75ca2f85, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_230) {
  // 0.2303112
  s21_decimal dec_1 = {{0x232488, 0x0, 0x0, 0x70000}};
  // -76476118776693890188401551281
  s21_decimal dec_2 = {{0x71ada7b1, 0xc2c3727, 0xf71b9012, 0x80000000}};
  // -17613306686802901881958987357
  s21_decimal dec_check = {{0x8de0765d, 0xb968fffe, 0x38e962c4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_231) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -249487434.79513156478
  s21_decimal dec_2 = {{0xb0b98b7e, 0x5a3bbe02, 0x1, 0x800b0000}};
  // 249487434.79513156478
  s21_decimal dec_check = {{0xb0b98b7e, 0x5a3bbe02, 0x1, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_232) {
  // 3159706.8
  s21_decimal dec_1 = {{0x1e2220c, 0x0, 0x0, 0x10000}};
  // -962
  s21_decimal dec_2 = {{0x3c2, 0x0, 0x0, 0x80000000}};
  // -3039637941.6
  s21_decimal dec_check = {{0x13c3f118, 0x7, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_233) {
  // -3.49109232727915
  s21_decimal dec_1 = {{0x53cdf76b, 0x13d83, 0x0, 0x800e0000}};
  // 70591
  s21_decimal dec_2 = {{0x113bf, 0x0, 0x0, 0x0}};
  // -246439.69847496247765
  s21_decimal dec_check = {{0xc77389d5, 0x5600f801, 0x1, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_234) {
  // -0.89503
  s21_decimal dec_1 = {{0x15d9f, 0x0, 0x0, 0x80050000}};
  // -612272
  s21_decimal dec_2 = {{0x957b0, 0x0, 0x0, 0x80000000}};
  // 548001.80816
  s21_decimal dec_check = {{0xc2586650, 0xc, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_235) {
  // -0.25556671986324027633
  s21_decimal dec_1 = {{0x3a0538f1, 0x62ab89c4, 0x1, 0x80140000}};
  // -76220
  s21_decimal dec_2 = {{0x129bc, 0x0, 0x0, 0x80000000}};
  // 19479.29538797617386187260
  s21_decimal dec_check = {{0xaae569fc, 0x78cdd36a, 0x19c7d, 0x140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_236) {
  // -108
  s21_decimal dec_1 = {{0x6c, 0x0, 0x0, 0x80000000}};
  // 73
  s21_decimal dec_2 = {{0x49, 0x0, 0x0, 0x0}};
  // -7884
  s21_decimal dec_check = {{0x1ecc, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_237) {
  // -364854817.5
  s21_decimal dec_1 = {{0xd9786d4f, 0x0, 0x0, 0x80010000}};
  // -7.3069
  s21_decimal dec_2 = {{0x11d6d, 0x0, 0x0, 0x80040000}};
  // 2665957665.99075
  s21_decimal dec_check = {{0xa9f77da3, 0xf277, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_238) {
  // 470154313
  s21_decimal dec_1 = {{0x1c05fc49, 0x0, 0x0, 0x0}};
  // 0.2389426664787438
  s21_decimal dec_2 = {{0xbf924dee, 0x87d2b, 0x0, 0x100000}};
  // 112339925.2047019203920094
  s21_decimal dec_check = {{0x331480de, 0x9871806f, 0xede3, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_239) {
  // -46135.027004315
  s21_decimal dec_1 = {{0xa5e5739b, 0x29f5, 0x0, 0x80090000}};
  // -760592162
  s21_decimal dec_2 = {{0x2d55b722, 0x0, 0x0, 0x80000000}};
  // 35089939933140.329179030
  s21_decimal dec_check = {{0xaf942796, 0x3abd96b8, 0x76e, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_240) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // 991447292408805446212824.9309
  s21_decimal dec_2 = {{0xb5fad9dd, 0x2ad0d4e0, 0x20090f4e, 0x40000}};
  // 6940131046861638123489774.5163
  s21_decimal dec_check = {{0xf9dbf50b, 0x2bb5d224, 0xe03f6b23, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_241) {
  // 8805688.662873998993803216330
  s21_decimal dec_1 = {{0xf74885ca, 0xed0af2ef, 0x1c73e51a, 0x150000}};
  // -48911409411.87306617
  s21_decimal dec_2 = {{0x89d6d479, 0x43e0d2c5, 0x0, 0x80080000}};
  // -430698643343319269.56781898938
  s21_decimal dec_check = {{0x1bd48cba, 0xff36de4a, 0x8b2a8e87, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_242) {
  // 248864
  s21_decimal dec_1 = {{0x3cc20, 0x0, 0x0, 0x0}};
  // 12740183.8918299
  s21_decimal dec_2 = {{0xd5a3a9b, 0x73df, 0x0, 0x70000}};
  // 3170573124056.3562336
  s21_decimal dec_check = {{0x41cbd760, 0xb8016294, 0x1, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_243) {
  // -816089.0055866963715360
  s21_decimal dec_1 = {{0xf81fe520, 0x6719bb8f, 0x1ba, 0x80100000}};
  // -2022288.8908
  s21_decimal dec_2 = {{0xb560cbcc, 0x4, 0x0, 0x80040000}};
  // 1650367729901.9952084299221323
  s21_decimal dec_check = {{0xb71b094b, 0x14717d20, 0x3553859b, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_244) {
  // -6294
  s21_decimal dec_1 = {{0x1896, 0x0, 0x0, 0x80000000}};
  // -9942136326
  s21_decimal dec_2 = {{0x5098f606, 0x2, 0x0, 0x80000000}};
  // 62575806035844
  s21_decimal dec_check = {{0x90b0b784, 0x38e9, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_245) {
  // -2041761029
  s21_decimal dec_1 = {{0x79b2cd05, 0x0, 0x0, 0x80000000}};
  // -0.01
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80020000}};
  // 20417610.29
  s21_decimal dec_check = {{0x79b2cd05, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_246) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 419913.2559472
  s21_decimal dec_2 = {{0xafcdf870, 0x3d1, 0x0, 0x70000}};
  // 0.0000000
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_247) {
  // -8.4
  s21_decimal dec_1 = {{0x54, 0x0, 0x0, 0x80010000}};
  // 1769324953573821
  s21_decimal dec_2 = {{0x115999bd, 0x64931, 0x0, 0x0}};
  // -14862329610020096.4
  s21_decimal dec_check = {{0xb1667204, 0x2100419, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_248) {
  // 86107840.94
  s21_decimal dec_1 = {{0x13e235e, 0x2, 0x0, 0x20000}};
  // 90916.825923479304572109
  s21_decimal dec_2 = {{0x81aa8ccd, 0x9c6b176a, 0x1340, 0x120000}};
  // 7828651585388.6245694769765323
  s21_decimal dec_check = {{0xb68c9bcb, 0x4155f177, 0xfcf51690, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_249) {
  // 3954
  s21_decimal dec_1 = {{0xf72, 0x0, 0x0, 0x0}};
  // 16587408164652280.5951
  s21_decimal dec_2 = {{0x41222ebf, 0xfdf71e6b, 0x8, 0x40000}};
  // 65586611883035117473.0254
  s21_decimal dec_check = {{0x1f6020e, 0x92d3d494, 0x8ae2, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_250) {
  // -0.93
  s21_decimal dec_1 = {{0x5d, 0x0, 0x0, 0x80020000}};
  // -9648128.6
  s21_decimal dec_2 = {{0x5c03006, 0x0, 0x0, 0x80010000}};
  // 8972759.598
  s21_decimal dec_check = {{0x16d1722e, 0x2, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_251) {
  // -0.218341770583
  s21_decimal dec_1 = {{0xd62f0557, 0x32, 0x0, 0x800c0000}};
  // -293604544776636.17
  s21_decimal dec_2 = {{0x8395cd81, 0x684f2d, 0x0, 0x80020000}};
  // 64106136157746.44560859978711
  s21_decimal dec_check = {{0x359b5bd7, 0x759b5186, 0x14b6bc3c, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_252) {
  // -859024628.4
  s21_decimal dec_1 = {{0x4c18c, 0x2, 0x0, 0x80010000}};
  // -46898086.51621558441
  s21_decimal dec_2 = {{0xf874e8a9, 0x41158c1e, 0x0, 0x800b0000}};
  // 40286611342263142.972089083244
  s21_decimal dec_check = {{0xa5faa56c, 0xf7d1ad65, 0x822c4dc8, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_253) {
  // 7912472685368481778531474
  s21_decimal dec_1 = {{0xe2087c92, 0xf671a5, 0x68b88, 0x0}};
  // -0.523704918
  s21_decimal dec_2 = {{0x1f371a56, 0x0, 0x0, 0x80090000}};
  // -4143800858868140549610319.7516
  s21_decimal dec_check = {{0x4beadb4c, 0xc41d11d6, 0x85e4b7a2, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_254) {
  // -249351030027969
  s21_decimal dec_1 = {{0x8f91b6c1, 0xe2c8, 0x0, 0x80000000}};
  // 15816474
  s21_decimal dec_2 = {{0xf1571a, 0x0, 0x0, 0x0}};
  // -3943854083310590961306
  s21_decimal dec_check = {{0x2599269a, 0xcbf85956, 0xd5, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_255) {
  // 5139607615
  s21_decimal dec_1 = {{0x3258303f, 0x1, 0x0, 0x0}};
  // 23.0184
  s21_decimal dec_2 = {{0x38328, 0x0, 0x0, 0x40000}};
  // 118305543925.1160
  s21_decimal dec_check = {{0x8f34c6d8, 0x433fb, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_256) {
  // 70514920255.307251435093611751
  s21_decimal dec_1 = {{0xe317d4e7, 0xac1c955d, 0xe3d8932e, 0x120000}};
  // -543185051182433
  s21_decimal dec_2 = {{0x2005e561, 0x1ee06, 0x0, 0x80000000}};
  // -38302650568004250838377614.490
  s21_decimal dec_check = {{0x759ecc9a, 0xe3a07a7e, 0x7bc335bf, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_257) {
  // -479126
  s21_decimal dec_1 = {{0x74f96, 0x0, 0x0, 0x80000000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // 4312134
  s21_decimal dec_check = {{0x41cc46, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_259) {
  // 30.69
  s21_decimal dec_1 = {{0xbfd, 0x0, 0x0, 0x20000}};
  // 8113195090061.39
  s21_decimal dec_2 = {{0xb22373b, 0x2e1e4, 0x0, 0x20000}};
  // 248993957313984.0591
  s21_decimal dec_check = {{0x79301e4f, 0x228e0ad9, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_260) {
  // -6324.51497577929276
  s21_decimal dec_1 = {{0x42cbda3c, 0x8c6eb49, 0x0, 0x800e0000}};
  // 6485620766766484121056
  s21_decimal dec_2 = {{0x24db65e0, 0x96119d15, 0x15f, 0x0}};
  // -41018405666639808459365154.500
  s21_decimal dec_check = {{0x9007fec4, 0xc87b3a48, 0x8489a142, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_261) {
  // -47728168935422462596.46343737
  s21_decimal dec_1 = {{0x50d52a39, 0x3e21a70b, 0xf6bfb4a, 0x80080000}};
  // 26633527.04983621368
  s21_decimal dec_2 = {{0x941fdef8, 0x24f6212c, 0x0, 0xb0000}};
  // -1271169478380726639590251030.7
  s21_decimal dec_check = {{0x167d04e3, 0x7610d3e, 0x2912de13, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_262) {
  // 69961554277.59183092169945432
  s21_decimal dec_1 = {{0xd2f1b158, 0xb0ee6b69, 0x169b1589, 0x110000}};
  // -896881972
  s21_decimal dec_2 = {{0x35755534, 0x0, 0x0, 0x80000000}};
  // -62747256764671596728.144384182
  s21_decimal dec_check = {{0xa6cc50b6, 0x16900bd5, 0xcabf5075, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_263) {
  // -0.4438
  s21_decimal dec_1 = {{0x1156, 0x0, 0x0, 0x80040000}};
  // -0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0.04438
  s21_decimal dec_check = {{0x1156, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_264) {
  // 8208370
  s21_decimal dec_1 = {{0x7d3ff2, 0x0, 0x0, 0x0}};
  // 642433300045
  s21_decimal dec_2 = {{0x9402364d, 0x95, 0x0, 0x0}};
  // 5273330227090376650
  s21_decimal dec_check = {{0xf90d47ca, 0x492ea1e6, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_265) {
  // 365018
  s21_decimal dec_1 = {{0x591da, 0x0, 0x0, 0x0}};
  // 20354336588
  s21_decimal dec_2 = {{0xbd36874c, 0x4, 0x0, 0x0}};
  // 7429699232678584
  s21_decimal dec_check = {{0xa78d42b8, 0x1a6545, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_266) {
  // 7508359
  s21_decimal dec_1 = {{0x729187, 0x0, 0x0, 0x0}};
  // -262435900812.4498406964
  s21_decimal dec_2 = {{0x7534ee34, 0x444c2570, 0x8e, 0x800a0000}};
  // -1970462957788265073.4413812076
  s21_decimal dec_check = {{0xdcfd116c, 0xd170a242, 0x3fab499d, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_267) {
  // -43939441094438701
  s21_decimal dec_1 = {{0x5a102f2d, 0x9c1ab0, 0x0, 0x80000000}};
  // -776371
  s21_decimal dec_2 = {{0xbd8b3, 0x0, 0x0, 0x80000000}};
  // 34113307821930468734071
  s21_decimal dec_check = {{0xa80df477, 0x493f53fe, 0x739, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_268) {
  // -443.1690748431
  s21_decimal dec_1 = {{0xd55a520f, 0x407, 0x0, 0x800a0000}};
  // 91914762966292
  s21_decimal dec_2 = {{0x92cbd514, 0x5398, 0x0, 0x0}};
  // -40733780468194455.5104887852
  s21_decimal dec_check = {{0x7139e42c, 0xa37a1c74, 0x150f122, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_269) {
  // 208931.92
  s21_decimal dec_1 = {{0x13ece08, 0x0, 0x0, 0x20000}};
  // -61061.3046380680
  s21_decimal dec_2 = {{0x6db98888, 0x22b59, 0x0, 0x800a0000}};
  // -12757655615.736452330560
  s21_decimal dec_check = {{0x5299b440, 0x98099d8e, 0x2b3, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_270) {
  // 79228162514264337592431328971
  s21_decimal dec_1 = {{0xbdaebecb, 0xffffffff, 0xffffffff, 0x0}};
  // 0.9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x10000}};
  // 71305346262837903833188196074
  s21_decimal dec_check = {{0x2ab6deea, 0x66666666, 0xe6666666, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_271) {
  // -0.8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80010000}};
  // 860897816199
  s21_decimal dec_2 = {{0x71822e87, 0xc8, 0x0, 0x0}};
  // -688718252959.2
  s21_decimal dec_check = {{0x8c117438, 0x643, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_272) {
  // -72483991645.42745300
  s21_decimal dec_1 = {{0xf0cefad4, 0x64977ca2, 0x0, 0x80080000}};
  // 579.8861790437478890224668255
  s21_decimal dec_2 = {{0x4d4ace5f, 0x8e88cb8c, 0x12bcb4bf, 0x190000}};
  // -42032464957105.870164281659763
  s21_decimal dec_check = {{0xf1261173, 0x121cbc48, 0x87d070ab, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_273) {
  // -63085413
  s21_decimal dec_1 = {{0x3c29b65, 0x0, 0x0, 0x80000000}};
  // -247264696083643330
  s21_decimal dec_2 = {{0x578f7bc2, 0x36e75ee, 0x0, 0x80000000}};
  // 15598795472756122017745290
  s21_decimal dec_check = {{0x7a8e498a, 0x65a0df3b, 0xce72c, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_274) {
  // 0.76
  s21_decimal dec_1 = {{0x4c, 0x0, 0x0, 0x20000}};
  // -14820691070426834.42
  s21_decimal dec_2 = {{0x21dc0a32, 0x14915e00, 0x0, 0x80020000}};
  // -11263725213524394.1592
  s21_decimal dec_check = {{0xd5306d8, 0x1b27e80a, 0x6, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_275) {
  // -599308028557
  s21_decimal dec_1 = {{0x898aca8d, 0x8b, 0x0, 0x80000000}};
  // -7.534096819
  s21_decimal dec_2 = {{0xc11131b3, 0x1, 0x0, 0x80090000}};
  // 4515244711552.454860183
  s21_decimal dec_check = {{0x7d2d9d97, 0xc59ba65d, 0xf4, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_276) {
  // -5487
  s21_decimal dec_1 = {{0x156f, 0x0, 0x0, 0x80000000}};
  // -90658541.271180600640368334
  s21_decimal dec_2 = {{0x5ab96ece, 0x5eba391b, 0x4afdb1, 0x80120000}};
  // 497443415954.96795571370104866
  s21_decimal dec_check = {{0x8e0c9822, 0x55be3354, 0xa0bb8e11, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_277) {
  // 6481
  s21_decimal dec_1 = {{0x1951, 0x0, 0x0, 0x0}};
  // 27
  s21_decimal dec_2 = {{0x1b, 0x0, 0x0, 0x0}};
  // 174987
  s21_decimal dec_check = {{0x2ab8b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_278) {
  // -523332577.446253
  s21_decimal dec_1 = {{0xdc60c96d, 0x1dbf7, 0x0, 0x80060000}};
  // -7156451532336421318
  s21_decimal dec_2 = {{0x8d3659c6, 0x6350d2c0, 0x0, 0x80000000}};
  // 3745204225786806164966401508.4
  s21_decimal dec_check = {{0xfd00faec, 0xfffe42a7, 0x79039a6e, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_279) {
  // 0.3931872120779575829
  s21_decimal dec_1 = {{0xa5541215, 0x3690d0dc, 0x0, 0x130000}};
  // 4898235670580.96979500
  s21_decimal dec_2 = {{0xf8997e2c, 0x8daae30a, 0x1a, 0x80000}};
  // 1925923627416.5365473053145840
  s21_decimal dec_check = {{0x6fa7af0, 0x716e16a7, 0x3e3addea, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_280) {
  // -76
  s21_decimal dec_1 = {{0x4c, 0x0, 0x0, 0x80000000}};
  // -35256
  s21_decimal dec_2 = {{0x89b8, 0x0, 0x0, 0x80000000}};
  // 2679456
  s21_decimal dec_check = {{0x28e2a0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_281) {
  // -98
  s21_decimal dec_1 = {{0x62, 0x0, 0x0, 0x80000000}};
  // 544992451322038.2870179
  s21_decimal dec_2 = {{0x1a96caa3, 0x70e55dd6, 0x127, 0x70000}};
  // -53409260229559752.1277542
  s21_decimal dec_check = {{0x2db99266, 0x37cdebf6, 0x7119, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_282) {
  // -623488692600396006
  s21_decimal dec_1 = {{0x9beb58e6, 0x8a713a9, 0x0, 0x80000000}};
  // -1005002.0115562429046
  s21_decimal dec_2 = {{0x3da0fa76, 0x8b78d80c, 0x0, 0x800d0000}};
  // 626607390245969966783668.86749
  s21_decimal dec_check = {{0x7f657b5d, 0x321bbd, 0xca77bf9d, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_283) {
  // 4067192751126.9304003725916134
  s21_decimal dec_1 = {{0xba877e6, 0x5834df0a, 0x836b07a8, 0x100000}};
  // -0.4129575681290
  s21_decimal dec_2 = {{0x7de43d0a, 0x3c1, 0x0, 0x800d0000}};
  // -1679578027617.2743023385057482
  s21_decimal dec_check = {{0x949b18ca, 0x33668f31, 0x364524d1, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_284) {
  // 8113884
  s21_decimal dec_1 = {{0x7bcedc, 0x0, 0x0, 0x0}};
  // -33.4
  s21_decimal dec_2 = {{0x14e, 0x0, 0x0, 0x80010000}};
  // -271003725.6
  s21_decimal dec_check = {{0xa187e308, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_287) {
  // -62172.0775432
  s21_decimal dec_1 = {{0xc1722b08, 0x90, 0x0, 0x80070000}};
  // -103165768.1
  s21_decimal dec_2 = {{0x3d7dd8d1, 0x0, 0x0, 0x80010000}};
  // 6414030134116.98893192
  s21_decimal dec_check = {{0x2d6be188, 0xc5414266, 0x22, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_288) {
  // 5.852938249997194
  s21_decimal dec_1 = {{0x61488b8a, 0x14cb37, 0x0, 0xf0000}};
  // -2492265187455802352858277
  s21_decimal dec_2 = {{0x8257f4a5, 0xf76eac2a, 0x20fc1, 0x80000000}};
  // -14587074244796492479368205.301
  s21_decimal dec_check = {{0x639313f5, 0x521efc53, 0x2f22251f, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_289) {
  // -63696686877191.9631097423040
  s21_decimal dec_1 = {{0x298664c0, 0x256cb8f6, 0x20ee2fb, 0x800d0000}};
  // -3261
  s21_decimal dec_2 = {{0xcbd, 0x0, 0x0, 0x80000000}};
  // 207714895906522991.70086965334
  s21_decimal dec_check = {{0xab68d056, 0xff4ca413, 0x431dc602, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_291) {
  // -261430378682721893.437580
  s21_decimal dec_1 = {{0x421508c, 0x2b52666d, 0x375c, 0x80060000}};
  // -729204653
  s21_decimal dec_2 = {{0x2b76c7ad, 0x0, 0x0, 0x80000000}};
  // 190636248570992815399653501.06
  s21_decimal dec_check = {{0xb52770da, 0x4699dcc2, 0x3d990f96, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_292) {
  // 42160.57130915783694386202
  s21_decimal dec_1 = {{0xcedc841a, 0xea3f9be0, 0x37cc8, 0x140000}};
  // -900288693
  s21_decimal dec_2 = {{0x35a950b5, 0x0, 0x0, 0x80000000}};
  // -37956685640055.007952896652358
  s21_decimal dec_check = {{0x459f446, 0x9099f93b, 0x7aa508d3, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_293) {
  // -12360696572788697
  s21_decimal dec_1 = {{0xf065bfd9, 0x2be9fc, 0x0, 0x80000000}};
  // -15008.1041
  s21_decimal dec_2 = {{0x8f20e11, 0x0, 0x0, 0x80040000}};
  // 185510620912925991879.3577
  s21_decimal dec_check = {{0xaa619b69, 0x8254cd1f, 0x188d5, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_294) {
  // 841552300025101758555456
  s21_decimal dec_1 = {{0xd944e540, 0xa43fb9a6, 0xb234, 0x0}};
  // -4.33
  s21_decimal dec_2 = {{0x1b1, 0x0, 0x0, 0x80020000}};
  // -3643921459108690614545124.48
  s21_decimal dec_check = {{0x7d87c140, 0xcfc90335, 0x12d6b09, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_295) {
  // -9675752256
  s21_decimal dec_1 = {{0x40b84340, 0x2, 0x0, 0x80000000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_296) {
  // 8496304162110091212
  s21_decimal dec_1 = {{0xbe3eafcc, 0x75e8ef9e, 0x0, 0x0}};
  // 34622
  s21_decimal dec_2 = {{0x873e, 0x0, 0x0, 0x0}};
  // 294159042700575577941864
  s21_decimal dec_check = {{0x21e32768, 0x64c6bec5, 0x3e4a, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_297) {
  // -24912
  s21_decimal dec_1 = {{0x6150, 0x0, 0x0, 0x80000000}};
  // 4766.87733
  s21_decimal dec_2 = {{0x1c69ad75, 0x0, 0x0, 0x50000}};
  // -118752448.04496
  s21_decimal dec_check = {{0xebbf8990, 0xacc, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_298) {
  // 72427683
  s21_decimal dec_1 = {{0x45128a3, 0x0, 0x0, 0x0}};
  // 16926291300851580
  s21_decimal dec_2 = {{0x4c5a1f7c, 0x3c225f, 0x0, 0x0}};
  // 1225932060703735866289140
  s21_decimal dec_check = {{0x98896bf4, 0xe901579d, 0x10399, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_299) {
  // -2799656
  s21_decimal dec_1 = {{0x2ab828, 0x0, 0x0, 0x80000000}};
  // -9.4043714035727799072495
  s21_decimal dec_2 = {{0xf4f2b6ef, 0x1eb5428a, 0x13ea, 0x80160000}};
  // 26329004.826240954704010506172
  s21_decimal dec_check = {{0xdfa96fbc, 0x997ea55b, 0x5512d7a3, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_300) {
  // 3.22493647842429257
  s21_decimal dec_1 = {{0x99f7c949, 0x479ba43, 0x0, 0x110000}};
  // -7.61249951018
  s21_decimal dec_2 = {{0x3e086d2a, 0xb1, 0x0, 0x800b0000}};
  // -24.549827362366541327338013363
  s21_decimal dec_check = {{0x12c382b3, 0x5666ef6, 0x4f532428, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_301) {
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // -614606493693840156
  s21_decimal dec_2 = {{0x85450b1c, 0x8878559, 0x0, 0x80000000}};
  // -3687638962163040936
  s21_decimal dec_check = {{0x1f9e42a8, 0x332d2019, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_302) {
  // -148.913790
  s21_decimal dec_1 = {{0x8e03e7e, 0x0, 0x0, 0x80060000}};
  // 9826938363013689
  s21_decimal dec_2 = {{0x625b6a39, 0x22e98c, 0x0, 0x0}};
  // -1463366635732764250.871310
  s21_decimal dec_check = {{0x4698160e, 0x43a7de39, 0x135e1, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_303) {
  // -5.514001777543
  s21_decimal dec_1 = {{0xd41e0387, 0x503, 0x0, 0x800c0000}};
  // -7670057310413615976314
  s21_decimal dec_2 = {{0xab9acf7a, 0xcb6d861d, 0x19f, 0x80000000}};
  // 42292709643477360217945.579385
  s21_decimal dec_check = {{0x81d89f79, 0xc9afdfdf, 0x88a7b59f, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_304) {
  // -0.8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80010000}};
  // 7549948449040772328
  s21_decimal dec_2 = {{0xf1962ce8, 0x68c6ce1c, 0x0, 0x0}};
  // -6039958759232617862.4
  s21_decimal dec_check = {{0x8cb16740, 0x463670e7, 0x3, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_305) {
  // -8746791.1457058244586562877
  s21_decimal dec_1 = {{0xc7fae53d, 0xfb319a14, 0x485a0c, 0x80130000}};
  // 5.98403289
  s21_decimal dec_2 = {{0x23aae8d9, 0x0, 0x0, 0x80000}};
  // -52341085.897864435825165670802
  s21_decimal dec_check = {{0x97a31992, 0x926fae4, 0xa91f8810, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_306) {
  // 5.618128685
  s21_decimal dec_1 = {{0x4eddd72d, 0x1, 0x0, 0x90000}};
  // 8877029112307
  s21_decimal dec_2 = {{0xd82ab9f3, 0x812, 0x0, 0x0}};
  // 49872291893432.043226295
  s21_decimal dec_check = {{0x7274c4b7, 0x95159a59, 0xa8f, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_307) {
  // 201777330670840790724.98558
  s21_decimal dec_1 = {{0x1927537e, 0x19f29d63, 0x10b0cd, 0x50000}};
  // 29697.4531985
  s21_decimal dec_2 = {{0x250fbd91, 0x45, 0x0, 0x70000}};
  // 5992272834115552991199992.1466
  s21_decimal dec_check = {{0xe5e7fd3a, 0x6fddb37f, 0xc19eeb4c, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_308) {
  // 7530895.392642
  s21_decimal dec_1 = {{0x6c583f82, 0x6d9, 0x0, 0x60000}};
  // -38643326.184723307
  s21_decimal dec_2 = {{0x822e136b, 0x8949e6, 0x0, 0x80090000}};
  // -291018847120894.70889189370709
  s21_decimal dec_check = {{0xd37eeb55, 0x69db70e1, 0x5e0883cb, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_309) {
  // -913237
  s21_decimal dec_1 = {{0xdef55, 0x0, 0x0, 0x80000000}};
  // -714142452505
  s21_decimal dec_2 = {{0x46350b19, 0xa6, 0x0, 0x80000000}};
  // 652181310898308685
  s21_decimal dec_check = {{0x653e064d, 0x90d0372, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_310) {
  // 9480120194.047544615
  s21_decimal dec_1 = {{0xb2360d27, 0x83902716, 0x0, 0x90000}};
  // -9.5
  s21_decimal dec_2 = {{0x5f, 0x0, 0x0, 0x80010000}};
  // -90061141843.4516738425
  s21_decimal dec_check = {{0x220ee179, 0xd27e816c, 0x30, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_311) {
  // 41330.509828114711628730
  s21_decimal dec_1 = {{0x886ccbba, 0x880b9e3e, 0x8c0, 0x120000}};
  // -4895534897612212.576906840
  s21_decimal dec_2 = {{0x34aaee58, 0x7a83cac8, 0x40cab, 0x80090000}};
  // -202334953199640100424.28300715
  s21_decimal dec_check = {{0x60d51dab, 0x24de0e87, 0x4160c14b, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_312) {
  // -1004.8095018014
  s21_decimal dec_1 = {{0x81225c1e, 0x923, 0x0, 0x800a0000}};
  // 59043909736677025369013690
  s21_decimal dec_2 = {{0xd943bdba, 0xc2ab5ac3, 0x30d708, 0x0}};
  // -59327881526917272522175954842
  s21_decimal dec_check = {{0xf19e3f9a, 0x5b68b26, 0xbfb2df96, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_313) {
  // 9172723
  s21_decimal dec_1 = {{0x8bf6f3, 0x0, 0x0, 0x0}};
  // 72277
  s21_decimal dec_2 = {{0x11a55, 0x0, 0x0, 0x0}};
  // 662976900271
  s21_decimal dec_check = {{0x5c80acaf, 0x9a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_314) {
  // 44394070225.71168584618323
  s21_decimal dec_1 = {{0x1e02d153, 0xbca6da02, 0x3ac14, 0xe0000}};
  // 42995.30441323
  s21_decimal dec_2 = {{0xffc126b, 0x3e9, 0x0, 0x80000}};
  // 1908736563496784.1886799851558
  s21_decimal dec_check = {{0x5c3af026, 0x6c40dc63, 0x3dacb2e4, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_315) {
  // 58781643
  s21_decimal dec_1 = {{0x380efcb, 0x0, 0x0, 0x0}};
  // -3803.46
  s21_decimal dec_2 = {{0x5cdba, 0x0, 0x0, 0x80020000}};
  // -223573627884.78
  s21_decimal dec_check = {{0x7aaac87e, 0x1455, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_316) {
  // 3053757.296841900702439
  s21_decimal dec_1 = {{0x66983ae7, 0x8b6551fa, 0xa5, 0xf0000}};
  // 23674832726562
  s21_decimal dec_2 = {{0x39feaa22, 0x1588, 0x0, 0x0}};
  // 72297193190250138798.970373413
  s21_decimal dec_check = {{0xad040525, 0x12dc183d, 0xe99ad628, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_317) {
  // -424381.7487
  s21_decimal dec_1 = {{0xfcf3840f, 0x0, 0x0, 0x80040000}};
  // 1413502760
  s21_decimal dec_2 = {{0x54405728, 0x0, 0x0, 0x0}};
  // -599864773081076.4120
  s21_decimal dec_check = {{0x37adbb58, 0x533f7a54, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_318) {
  // 58663734426403.0
  s21_decimal dec_1 = {{0x26844f5e, 0x2158b, 0x0, 0x10000}};
  // 655.8724652
  s21_decimal dec_2 = {{0x86ee322c, 0x1, 0x0, 0x70000}};
  // 38475928116083043.57867560
  s21_decimal dec_check = {{0x73a20028, 0x6c9c415b, 0x32ec2, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_319) {
  // -45628451001.8964198
  s21_decimal dec_1 = {{0x28318ae6, 0x6550c58, 0x0, 0x80070000}};
  // 25.21
  s21_decimal dec_2 = {{0x9d9, 0x0, 0x0, 0x20000}};
  // -1150293249757.808743158
  s21_decimal dec_check = {{0xcfe0d2f6, 0x5b869023, 0x3e, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_320) {
  // 2.60
  s21_decimal dec_1 = {{0x104, 0x0, 0x0, 0x20000}};
  // 1492123443210160.85792380633
  s21_decimal dec_2 = {{0xe0b756d9, 0x64cb2a01, 0x7b6cf1, 0xb0000}};
  // 3879520952346418.2306018964580
  s21_decimal dec_check = {{0x3a343464, 0x5e56a9e8, 0x7d5aa52a, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_321) {
  // 2022577549357486
  s21_decimal dec_1 = {{0x85c31ae, 0x72f86, 0x0, 0x0}};
  // 158022
  s21_decimal dec_2 = {{0x26946, 0x0, 0x0, 0x0}};
  // 319611749504568652692
  s21_decimal dec_check = {{0x7cf1f394, 0x538108cc, 0x11, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_322) {
  // -21338463753
  s21_decimal dec_1 = {{0xf7df1e09, 0x4, 0x0, 0x80000000}};
  // -9819.31951764
  s21_decimal dec_2 = {{0x9fb48694, 0xe4, 0x0, 0x80080000}};
  // 209529193606286.58410292
  s21_decimal dec_check = {{0xcc0a1334, 0xdc2b392a, 0x46f, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_323) {
  // 158281100.749320
  s21_decimal dec_1 = {{0xb0c8ea08, 0x8ff4, 0x0, 0x60000}};
  // -93242
  s21_decimal dec_2 = {{0x16c3a, 0x0, 0x0, 0x80000000}};
  // -14758446396068.095440
  s21_decimal dec_check = {{0xba4865d0, 0xccd088cd, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_324) {
  // -80344312875292.4
  s21_decimal dec_1 = {{0x2e495b1c, 0x2daba, 0x0, 0x80010000}};
  // 63289787881
  s21_decimal dec_2 = {{0xbc5d85e9, 0xe, 0x0, 0x0}};
  // -5084974519321953201851404.4
  s21_decimal dec_check = {{0xe645787c, 0x35df7896, 0x2a0fda, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_325) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // -96992.9443044178372870976
  s21_decimal dec_2 = {{0x553c4340, 0xfaffc63f, 0xcd63, 0x80130000}};
  // -193985.8886088356745741952
  s21_decimal dec_check = {{0xaa788680, 0xf5ff8c7e, 0x19ac7, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_326) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 754.21710
  s21_decimal dec_2 = {{0x47ed80e, 0x0, 0x0, 0x50000}};
  // -5279.51970
  s21_decimal dec_check = {{0x1f77e862, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_327) {
  // -0.63821441677
  s21_decimal dec_1 = {{0xdc0dea8d, 0xe, 0x0, 0x800b0000}};
  // -98279280.36068485785
  s21_decimal dec_2 = {{0x6bf6ea99, 0x8863d07a, 0x0, 0x800b0000}};
  // 62723253.595969801790508106144
  s21_decimal dec_check = {{0xe5201a0, 0xb49a9f90, 0xcaab7596, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_328) {
  // -866413682036163416
  s21_decimal dec_1 = {{0x424dc358, 0xc061ea7, 0x0, 0x80000000}};
  // 0.81450609318113516221354
  s21_decimal dec_2 = {{0x3dc073aa, 0x7245df00, 0x113f, 0x170000}};
  // -705699223233957731.51534461588
  s21_decimal dec_check = {{0xe5453294, 0xc208fdb7, 0xe4061252, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_329) {
  // -775864121
  s21_decimal dec_1 = {{0x2e3ebf39, 0x0, 0x0, 0x80000000}};
  // -519115998.8119981180883534886
  s21_decimal dec_2 = {{0x849b8426, 0xd78bb3fa, 0x10c606e2, 0x80130000}};
  // 402763478115307964.14427457977
  s21_decimal dec_check = {{0xb2abe9b9, 0xda281494, 0x8223d065, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_330) {
  // -0.81002732167
  s21_decimal dec_1 = {{0xdc239a87, 0x12, 0x0, 0x800b0000}};
  // -3591782308944043715717006699
  s21_decimal dec_2 = {{0xcfd0856b, 0x1f6326a2, 0xb9b0d7d, 0x80000000}};
  // 2909441803735632216941641820.1
  s21_decimal dec_check = {{0x265d8399, 0x2a47d454, 0x5e0256aa, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_331) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 5980039005398.88475
  s21_decimal dec_2 = {{0x11fa635b, 0x84c8961, 0x0, 0x50000}};
  // 53820351048589.96275
  s21_decimal dec_check = {{0xa1cd7e33, 0x4ab0d469, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_332) {
  // 630691538162948490.2020146964
  s21_decimal dec_1 = {{0xa015e714, 0xec185a41, 0x1460f547, 0xa0000}};
  // 0.0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x10000}};
  // 0.00000000000
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_333) {
  // 271796.12
  s21_decimal dec_1 = {{0x19eba5c, 0x0, 0x0, 0x20000}};
  // -807259993101577
  s21_decimal dec_2 = {{0xdd215509, 0x2de32, 0x0, 0x80000000}};
  // -219410133956235394481.24
  s21_decimal dec_check = {{0x3451193c, 0x6cba6ad9, 0x4a5, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_334) {
  // -2700
  s21_decimal dec_1 = {{0xa8c, 0x0, 0x0, 0x80000000}};
  // -607.7475570215166907
  s21_decimal dec_2 = {{0xcdca23bb, 0x545787d4, 0x0, 0x80100000}};
  // 1640918.4039580950648900
  s21_decimal dec_check = {{0x6ff0d844, 0x8b2c986a, 0x379, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_335) {
  // 0.05859944945109
  s21_decimal dec_1 = {{0x5fefd5d5, 0x554, 0x0, 0xe0000}};
  // -295710094089973358
  s21_decimal dec_2 = {{0x8abaee6e, 0x41a92c3, 0x0, 0x80000000}};
  // -17328448710802461.546525824060
  s21_decimal dec_check = {{0xe9ed143c, 0xe71ccf8f, 0x37fdc1be, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_336) {
  // -0.4218376
  s21_decimal dec_1 = {{0x405e08, 0x0, 0x0, 0x80070000}};
  // 7393
  s21_decimal dec_2 = {{0x1ce1, 0x0, 0x0, 0x0}};
  // -3118.6453768
  s21_decimal dec_check = {{0x42db8508, 0x7, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_337) {
  // -77.244867714
  s21_decimal dec_1 = {{0xfc272482, 0x11, 0x0, 0x80090000}};
  // -42992179
  s21_decimal dec_2 = {{0x2900233, 0x0, 0x0, 0x80000000}};
  // 3320925179.591608806
  s21_decimal dec_check = {{0x173549e6, 0x2e164bdb, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_338) {
  // -408.0037798922
  s21_decimal dec_1 = {{0xf534240a, 0x3b5, 0x0, 0x800a0000}};
  // 1234595038484775068580
  s21_decimal dec_2 = {{0x48bc63a4, 0xed72ae56, 0x42, 0x0}};
  // -503719442337944355281740.48001
  s21_decimal dec_check = {{0x48c79301, 0x87a98255, 0xa2c2b218, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_339) {
  // -8132605449779510
  s21_decimal dec_1 = {{0xc2eeb936, 0x1ce48f, 0x0, 0x80000000}};
  // 882.8966032963224873533
  s21_decimal dec_2 = {{0xfac62a3d, 0x9e84651c, 0x1de, 0x130000}};
  // -7180249727559490353.5461975102
  s21_decimal dec_check = {{0xd1e1c43e, 0xcde1b715, 0xe801a238, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_340) {
  // -229031.7688351
  s21_decimal dec_1 = {{0x41927e1f, 0x215, 0x0, 0x80070000}};
  // -35.60280
  s21_decimal dec_2 = {{0x365358, 0x0, 0x0, 0x80050000}};
  // 8154172.259482298280
  s21_decimal dec_check = {{0xa3c967a8, 0x71297077, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_341) {
  // 435028192318470
  s21_decimal dec_1 = {{0xe4ded406, 0x18ba7, 0x0, 0x0}};
  // 606.399176846123240763793628
  s21_decimal dec_2 = {{0xf00da0dc, 0x3f1a9606, 0x1f59a05, 0x180000}};
  // 263800737726777201.48883870954
  s21_decimal dec_check = {{0x4c8914ea, 0xbbb678fe, 0x553d15e8, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_342) {
  // 161749956790958
  s21_decimal dec_1 = {{0x58b78aae, 0x931c, 0x0, 0x0}};
  // -1510338
  s21_decimal dec_2 = {{0x170bc2, 0x0, 0x0, 0x80000000}};
  // -244297106239741923804
  s21_decimal dec_check = {{0x93ae91dc, 0x3e4dabc8, 0xd, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_343) {
  // -942412045245688
  s21_decimal dec_1 = {{0x67305cf8, 0x3591e, 0x0, 0x80000000}};
  // 4267480
  s21_decimal dec_2 = {{0x411dd8, 0x0, 0x0, 0x0}};
  // -4021724554845068626240
  s21_decimal dec_check = {{0x264e8940, 0x4a3d69f, 0xda, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_344) {
  // -17202693341.93185269
  s21_decimal dec_1 = {{0x569521f5, 0x17df9fd8, 0x0, 0x80080000}};
  // -33902.38871020208
  s21_decimal dec_2 = {{0x7f9c62b0, 0xc0b67, 0x0, 0x800b0000}};
  // 583212396540578.93249737671869
  s21_decimal dec_check = {{0x8359c4bd, 0xbfb5ac0e, 0xbc7232e0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_345) {
  // 81014
  s21_decimal dec_1 = {{0x13c76, 0x0, 0x0, 0x0}};
  // -7.434
  s21_decimal dec_2 = {{0x1d0a, 0x0, 0x0, 0x80030000}};
  // -602258.076
  s21_decimal dec_check = {{0x23e5ba9c, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_346) {
  // 11630.925132418004
  s21_decimal dec_1 = {{0xc8ed4bd4, 0x295243, 0x0, 0xc0000}};
  // -46211278937.810901439626323023
  s21_decimal dec_2 = {{0xf28ba44f, 0xe2aa45cc, 0x955112f2, 0x80120000}};
  // -537479925598963.57805884548918
  s21_decimal dec_check = {{0xe5c1a736, 0x23b57b6, 0xadab4c23, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_347) {
  // -5927021.8042
  s21_decimal dec_1 = {{0xccc7c13a, 0xd, 0x0, 0x80040000}};
  // 64209.0526469739280
  s21_decimal dec_2 = {{0x8fdf5310, 0x8e929ee, 0x0, 0xd0000}};
  // -380568455065.64019640492089760
  s21_decimal dec_check = {{0x47a7e1a0, 0xcedf5f1e, 0x7af7e280, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_348) {
  // 89948373786549971.74
  s21_decimal dec_1 = {{0x6f230ab6, 0x7cd414f0, 0x0, 0x20000}};
  // -0.3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80010000}};
  // -26984512135964991.522
  s21_decimal dec_check = {{0x4d692022, 0x767c3ed1, 0x1, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_349) {
  // 1415929124511.56867628565309
  s21_decimal dec_1 = {{0xb43a833d, 0x2a166d40, 0x751f77, 0xe0000}};
  // -25.77
  s21_decimal dec_2 = {{0xa11, 0x0, 0x0, 0x80020000}};
  // -36488493538663.124787881280129
  s21_decimal dec_check = {{0x39b38281, 0x44602da2, 0x75e6930e, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_350) {
  // -22576
  s21_decimal dec_1 = {{0x5830, 0x0, 0x0, 0x80000000}};
  // 86.2663
  s21_decimal dec_2 = {{0xd29c7, 0x0, 0x0, 0x40000}};
  // -1947547.9888
  s21_decimal dec_check = {{0x88d43d50, 0x4, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_351) {
  // -50988
  s21_decimal dec_1 = {{0xc72c, 0x0, 0x0, 0x80000000}};
  // 546.98475688124
  s21_decimal dec_2 = {{0x7b3690bc, 0x31bf, 0x0, 0xb0000}};
  // -27889658.78386066512
  s21_decimal dec_check = {{0x97e30450, 0x26b465b0, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_352) {
  // -496520.35716424292
  s21_decimal dec_1 = {{0x6f40a264, 0xb06643, 0x0, 0x800b0000}};
  // 695593971
  s21_decimal dec_2 = {{0x2975ebf3, 0x0, 0x0, 0x0}};
  // -345376566922214.03193143532
  s21_decimal dec_check = {{0x2b1ff0ec, 0x1ef42baf, 0x1c91a2, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_353) {
  // 946
  s21_decimal dec_1 = {{0x3b2, 0x0, 0x0, 0x0}};
  // 175699
  s21_decimal dec_2 = {{0x2ae53, 0x0, 0x0, 0x0}};
  // 166211254
  s21_decimal dec_check = {{0x9e82eb6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_354) {
  // 0.87558258
  s21_decimal dec_1 = {{0x5380872, 0x0, 0x0, 0x80000}};
  // 789
  s21_decimal dec_2 = {{0x315, 0x0, 0x0, 0x0}};
  // 690.83465562
  s21_decimal dec_check = {{0x15b2075a, 0x10, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_355) {
  // 13
  s21_decimal dec_1 = {{0xd, 0x0, 0x0, 0x0}};
  // 93678533483.2052423207928
  s21_decimal dec_2 = {{0x8abdabf8, 0x3c192854, 0xc65f, 0xd0000}};
  // 1217820935281.6681501703064
  s21_decimal dec_check = {{0xba1bb98, 0xd470c4b, 0xa12d6, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_356) {
  // 7.8144
  s21_decimal dec_1 = {{0x13140, 0x0, 0x0, 0x40000}};
  // 5959
  s21_decimal dec_2 = {{0x1747, 0x0, 0x0, 0x0}};
  // 46566.0096
  s21_decimal dec_check = {{0x1bc168c0, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_357) {
  // 6595747.828
  s21_decimal dec_1 = {{0x89231ff4, 0x1, 0x0, 0x30000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -52765982.624
  s21_decimal dec_check = {{0x4918ffa0, 0xc, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_358) {
  // 1326.3
  s21_decimal dec_1 = {{0x33cf, 0x0, 0x0, 0x10000}};
  // 52053548361878
  s21_decimal dec_2 = {{0xa9426896, 0x2f57, 0x0, 0x0}};
  // 69038621192358791.4
  s21_decimal dec_check = {{0x1788734a, 0x994be9a, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_359) {
  // 1675172.8327117387325
  s21_decimal dec_1 = {{0xb7ae363d, 0xe87a1828, 0x0, 0xd0000}};
  // -3643009374055797281
  s21_decimal dec_2 = {{0x66039221, 0x328e91b9, 0x0, 0x80000000}};
  // -6102670332732468131606761.3331
  s21_decimal dec_check = {{0x99869a93, 0x5b0e706e, 0xc5301b18, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_360) {
  // -5432.6
  s21_decimal dec_1 = {{0xd436, 0x0, 0x0, 0x80010000}};
  // 257799918
  s21_decimal dec_2 = {{0xf5db6ee, 0x0, 0x0, 0x0}};
  // -1400523834526.8
  s21_decimal dec_check = {{0xd941ae34, 0xcbc, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_361) {
  // -7472.1
  s21_decimal dec_1 = {{0x123e1, 0x0, 0x0, 0x80010000}};
  // 8614.18
  s21_decimal dec_2 = {{0xd24ea, 0x0, 0x0, 0x20000}};
  // -64366014.378
  s21_decimal dec_check = {{0xfc836faa, 0xe, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_362) {
  // -456.84556577785459423625844861
  s21_decimal dec_1 = {{0xea97987d, 0x8899cd79, 0x939d6126, 0x801a0000}};
  // 805798500804486556301316
  s21_decimal dec_2 = {{0xc9f43804, 0x6c9c2a3f, 0xaaa2, 0x0}};
  // -368125472002972681227838285.59
  s21_decimal dec_check = {{0x1f93ca4f, 0x76e13039, 0x76f2a016, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_363) {
  // 78508132254642993769
  s21_decimal dec_1 = {{0xe961fa69, 0x4184ea54, 0x4, 0x0}};
  // -39582612.2169923270400208
  s21_decimal dec_2 = {{0x784cd8d0, 0xc6eea8de, 0x53d1, 0x80100000}};
  // -3107556954915881130377442659.5
  s21_decimal dec_check = {{0x21de95e3, 0xd234d31a, 0x64691bd0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_364) {
  // -742470.670621519732882
  s21_decimal dec_1 = {{0xedbd6092, 0x3fd9b526, 0x28, 0x800f0000}};
  // -3871903150.17
  s21_decimal dec_2 = {{0x26575809, 0x5a, 0x0, 0x80020000}};
  // 2874774528488294.7255386327329
  s21_decimal dec_check = {{0x86454921, 0x98b4400a, 0x5ce393da, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_366) {
  // -852060648860
  s21_decimal dec_1 = {{0x62c5b59c, 0xc6, 0x0, 0x80000000}};
  // 16726671968897433
  s21_decimal dec_2 = {{0xccfb0999, 0x3b6cd1, 0x0, 0x0}};
  // -14252138971087120500768376380
  s21_decimal dec_check = {{0x5b80063c, 0xc03ae8f7, 0x2e0d17d1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_367) {
  // 8781.01313
  s21_decimal dec_1 = {{0x3456c341, 0x0, 0x0, 0x50000}};
  // -44.458734362134025374
  s21_decimal dec_2 = {{0x9273949e, 0x68fd2759, 0x2, 0x80120000}};
  // -390392.73017708105162884716062
  s21_decimal dec_check = {{0x3ea1161e, 0xe716e550, 0x7e24879e, 0x80170000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_369) {
  // 6637240805512.0314
  s21_decimal dec_1 = {{0x7d0341ba, 0xebcd5a, 0x0, 0x40000}};
  // -145890
  s21_decimal dec_2 = {{0x239e2, 0x0, 0x0, 0x80000000}};
  // -968307061116150260.9460
  s21_decimal dec_check = {{0x99f67034, 0xeb9969be, 0x20c, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_370) {
  // 13641591.6
  s21_decimal dec_1 = {{0x8218aac, 0x0, 0x0, 0x10000}};
  // -71445232
  s21_decimal dec_2 = {{0x4422af0, 0x0, 0x0, 0x80000000}};
  // -974626676711251.2
  s21_decimal dec_check = {{0x908a3940, 0x22a02d, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_371) {
  // 368290.78171
  s21_decimal dec_1 = {{0x932f229b, 0x8, 0x0, 0x50000}};
  // 51791
  s21_decimal dec_2 = {{0xca4f, 0x0, 0x0, 0x0}};
  // 19074147875.54261
  s21_decimal dec_check = {{0x9cd9fbd5, 0x6c6c8, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_372) {
  // 2293145616004758216
  s21_decimal dec_1 = {{0xc4353ac8, 0x1fd2e3c9, 0x0, 0x0}};
  // 249.4399159125174368553943
  s21_decimal dec_2 = {{0x84ab4bd7, 0xa63d0331, 0x21035, 0x160000}};
  // 572002049631384888847.43786006
  s21_decimal dec_check = {{0xb12a4e16, 0x61ee6999, 0xb8d2e68c, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_373) {
  // -40.93862520
  s21_decimal dec_1 = {{0xf4036278, 0x0, 0x0, 0x80080000}};
  // -906314155314.8987
  s21_decimal dec_2 = {{0x14d3143b, 0x2032e1, 0x0, 0x80040000}};
  // 37103255517891.225855267240
  s21_decimal dec_check = {{0x96111a8, 0x830e713c, 0x1eb0eb, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_374) {
  // 65071149758573008.26647
  s21_decimal dec_1 = {{0x96f56a17, 0xc05c625e, 0x160, 0x50000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // -585640347827157074.39823
  s21_decimal dec_check = {{0x4ea0bacf, 0xc33f7553, 0xc66, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_375) {
  // -38562
  s21_decimal dec_1 = {{0x96a2, 0x0, 0x0, 0x80000000}};
  // -94889856
  s21_decimal dec_2 = {{0x5a7e780, 0x0, 0x0, 0x80000000}};
  // 3659142627072
  s21_decimal dec_check = {{0xf5e57f00, 0x353, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_376) {
  // 83842235424339199.794
  s21_decimal dec_1 = {{0x3a690732, 0x8b8b74e7, 0x4, 0x30000}};
  // -28044174.3402799361292283
  s21_decimal dec_2 = {{0x1f39f7fb, 0xc701e4cf, 0x3b62, 0x80100000}};
  // -2351286267318962869169565.4563
  s21_decimal dec_check = {{0xdc61d6a3, 0x94ce8193, 0x4bf96257, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_377) {
  // 7918.3
  s21_decimal dec_1 = {{0x1354f, 0x0, 0x0, 0x10000}};
  // -631892699
  s21_decimal dec_2 = {{0x25a9eadb, 0x0, 0x0, 0x80000000}};
  // -5003515958491.7
  s21_decimal dec_check = {{0xb7e9d095, 0x2d81, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_378) {
  // 8538338
  s21_decimal dec_1 = {{0x8248e2, 0x0, 0x0, 0x0}};
  // 85
  s21_decimal dec_2 = {{0x55, 0x0, 0x0, 0x0}};
  // 725758730
  s21_decimal dec_check = {{0x2b42330a, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_379) {
  // 349344
  s21_decimal dec_1 = {{0x554a0, 0x0, 0x0, 0x0}};
  // -991.994533276159720
  s21_decimal dec_2 = {{0xaf0e0ee8, 0xdc445c5, 0x0, 0x800f0000}};
  // -346547338.232826741223680
  s21_decimal dec_check = {{0x50357100, 0x5e6ce444, 0x4962, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_380) {
  // 240.0690442322
  s21_decimal dec_1 = {{0xf44d1052, 0x22e, 0x0, 0xa0000}};
  // -2394918.673
  s21_decimal dec_2 = {{0x8ebf8f11, 0x0, 0x0, 0x80030000}};
  // -574945836.8409587278706
  s21_decimal dec_check = {{0xee69e372, 0xadc36421, 0x137, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_381) {
  // -4327792.2260970912617787282
  s21_decimal dec_1 = {{0x5b92ef92, 0xdde69db6, 0x23cc74, 0x80130000}};
  // 642779801280.577228
  s21_decimal dec_2 = {{0xdc1ffecc, 0x8eb9cd2, 0x0, 0x60000}};
  // -2781817427074315274.0832409435
  s21_decimal dec_check = {{0xc164775b, 0xf22d592b, 0x59e2a788, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_382) {
  // -6977577873810062.4
  s21_decimal dec_1 = {{0x799c5990, 0xf7e4b3, 0x0, 0x80010000}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // -2791031149524024.96
  s21_decimal dec_check = {{0xe6716640, 0x3df92cd, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_383) {
  // -5620806075.517340
  s21_decimal dec_1 = {{0xe57b899c, 0x13f817, 0x0, 0x80060000}};
  // 702
  s21_decimal dec_2 = {{0x2be, 0x0, 0x0, 0x0}};
  // -3945805865013.172680
  s21_decimal dec_check = {{0x48c359c8, 0x36c25187, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_385) {
  // 95162918029467817743
  s21_decimal dec_1 = {{0xc80b970f, 0x28a699c0, 0x5, 0x0}};
  // 40848
  s21_decimal dec_2 = {{0x9f90, 0x0, 0x0, 0x0}};
  // 3887214875667701419166064
  s21_decimal dec_check = {{0xb9574970, 0x573538af, 0x33726, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_386) {
  // 5.358
  s21_decimal dec_1 = {{0x14ee, 0x0, 0x0, 0x30000}};
  // 924369378715643797077469
  s21_decimal dec_2 = {{0xec0c7ddd, 0x2a180702, 0xc3be, 0x0}};
  // 4952771131158419464741078.902
  s21_decimal dec_check = {{0x6d724776, 0x2e2bf28, 0x1000d615, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_387) {
  // -1440.9
  s21_decimal dec_1 = {{0x3849, 0x0, 0x0, 0x80010000}};
  // -58299855333804
  s21_decimal dec_2 = {{0xfe2ae9ac, 0x3505, 0x0, 0x80000000}};
  // 84004261550478183.6
  s21_decimal dec_check = {{0xdd5a420c, 0xba86e4e, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_388) {
  // 339005
  s21_decimal dec_1 = {{0x52c3d, 0x0, 0x0, 0x0}};
  // 599640785
  s21_decimal dec_2 = {{0x23bdcad1, 0x0, 0x0, 0x0}};
  // 203281224318925
  s21_decimal dec_check = {{0x192a3fcd, 0xb8e2, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_389) {
  // 444930686
  s21_decimal dec_1 = {{0x1a851a7e, 0x0, 0x0, 0x0}};
  // -76.8604502
  s21_decimal dec_2 = {{0x2dcff956, 0x0, 0x0, 0x80070000}};
  // -34197572833.7548372
  s21_decimal dec_check = {{0xf15d7454, 0x4bef11c, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_390) {
  // -75.02
  s21_decimal dec_1 = {{0x1d4e, 0x0, 0x0, 0x80020000}};
  // 834.55861725755783
  s21_decimal dec_2 = {{0x967987, 0x1287eaa, 0x0, 0xe0000}};
  // -62608.5874666619884066
  s21_decimal dec_check = {{0x399d5222, 0xf0afd9dd, 0x21, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_391) {
  // -87.4430584366021
  s21_decimal dec_1 = {{0x3c5ca3c5, 0x31b4a, 0x0, 0x800d0000}};
  // -6.654
  s21_decimal dec_2 = {{0x19fe, 0x0, 0x0, 0x80030000}};
  // 581.8461108371503734
  s21_decimal dec_check = {{0xefe8ba76, 0x50bf538c, 0x0, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_392) {
  // 50744858
  s21_decimal dec_1 = {{0x3064e1a, 0x0, 0x0, 0x0}};
  // -645888191625
  s21_decimal dec_2 = {{0x61efac89, 0x96, 0x0, 0x80000000}};
  // -32775504567887414250
  s21_decimal dec_check = {{0x9f1f43ea, 0xc6d9fbc0, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_393) {
  // -3717657255414026011
  s21_decimal dec_1 = {{0xa99b4f1b, 0x3397c593, 0x0, 0x80000000}};
  // -0.565402
  s21_decimal dec_2 = {{0x8a09a, 0x0, 0x0, 0x80060000}};
  // 2101970847525601134.671422
  s21_decimal dec_check = {{0x91b6763e, 0x116671af, 0x1bd1c, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_394) {
  // -56
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x80000000}};
  // 1.9042586210521
  s21_decimal dec_2 = {{0xb29630d9, 0x1151, 0x0, 0xd0000}};
  // -106.6384827789176
  s21_decimal dec_check = {{0x10daaf78, 0x3c9df, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_395) {
  // -377.5372059843
  s21_decimal dec_1 = {{0x5b5e4c3, 0x36f, 0x0, 0x800a0000}};
  // 6534045.05147524172
  s21_decimal dec_2 = {{0x7ff5444c, 0x9115bef, 0x0, 0xb0000}};
  // -2466845112.5095044298352730250
  s21_decimal dec_check = {{0xf4f1a08a, 0x1582c55e, 0x4fb543b7, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_396) {
  // 50467
  s21_decimal dec_1 = {{0xc523, 0x0, 0x0, 0x0}};
  // -8831836
  s21_decimal dec_2 = {{0x86c35c, 0x0, 0x0, 0x80000000}};
  // -445716267412
  s21_decimal dec_check = {{0xc6c28194, 0x67, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_397) {
  // -387033858647302
  s21_decimal dec_1 = {{0x57a92506, 0x16001, 0x0, 0x80000000}};
  // 512955180888
  s21_decimal dec_2 = {{0x6e82e758, 0x77, 0x0, 0x0}};
  // -198531022972207420403164176
  s21_decimal dec_check = {{0x23992410, 0x52139e27, 0xa43894, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_398) {
  // -609357898643887263639979442
  s21_decimal dec_1 = {{0xab90c5b2, 0xe065447a, 0x1f80c8d, 0x80000000}};
  // -0.3555
  s21_decimal dec_2 = {{0xde3, 0x0, 0x0, 0x80040000}};
  // 216626732967901922224012691.63
  s21_decimal dec_check = {{0xecc10dab, 0x82dcdc08, 0x45fef180, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_399) {
  // 84962.354484690
  s21_decimal dec_1 = {{0xd6f555d2, 0x4d45, 0x0, 0x90000}};
  // -37110529432684486859148
  s21_decimal dec_2 = {{0xcd6a198c, 0xc40d8b03, 0x7db, 0x80000000}};
  // -3152997956774261053563124450.2
  s21_decimal dec_check = {{0xe41f4cd6, 0x49db7a5c, 0x65e0fce1, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_400) {
  // -24412425221191543192222692204
  s21_decimal dec_1 = {{0xb087f36c, 0x5d58a3f, 0x4ee17c1f, 0x80000000}};
  // 0.2534686577
  s21_decimal dec_2 = {{0x97143f71, 0x0, 0x0, 0xa0000}};
  // -6187784652017046047524258872.4
  s21_decimal dec_check = {{0xb7f42a34, 0x4b6f924b, 0xc7f027ad, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_401) {
  // -16196319729638920550381
  s21_decimal dec_1 = {{0xb295f7ed, 0x116a653, 0x36e, 0x80000000}};
  // -338852.4117217
  s21_decimal dec_2 = {{0xf3c6bce1, 0x314, 0x0, 0x80070000}};
  // 5488162001403900336814457779.8
  s21_decimal dec_check = {{0xa3452506, 0x6fefb505, 0xb1550316, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_403) {
  // 49271928447277514
  s21_decimal dec_1 = {{0xd07f99ca, 0xaf0c8e, 0x0, 0x0}};
  // -3.862393
  s21_decimal dec_2 = {{0x3aef79, 0x0, 0x0, 0x80060000}};
  // -190307551531265539.131002
  s21_decimal dec_check = {{0x84a7467a, 0x97d18110, 0x284c, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_404) {
  // -882636449188804242781173858
  s21_decimal dec_1 = {{0xbcf2f862, 0xc948f7d7, 0x2da1989, 0x80000000}};
  // 0.219936426223098893
  s21_decimal dec_2 = {{0xae325c0d, 0x30d5f03, 0x0, 0x120000}};
  // -194123906288831419106400652.97
  s21_decimal dec_check = {{0x9b05fb11, 0xa60bcbff, 0x3eb98d9c, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_405) {
  // 6536
  s21_decimal dec_1 = {{0x1988, 0x0, 0x0, 0x0}};
  // 5701560513776
  s21_decimal dec_2 = {{0x7f7d34f0, 0x52f, 0x0, 0x0}};
  // 37265399518039936
  s21_decimal dec_check = {{0xf4af8f80, 0x8464ae, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_406) {
  // -21758100.1210
  s21_decimal dec_1 = {{0xa8d699fa, 0x32, 0x0, 0x80040000}};
  // -52
  s21_decimal dec_2 = {{0x34, 0x0, 0x0, 0x80000000}};
  // 1131421206.2920
  s21_decimal dec_check = {{0x4b9746c8, 0xa4a, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_407) {
  // 67186076205427053
  s21_decimal dec_1 = {{0x5e13a96d, 0xeeb161, 0x0, 0x0}};
  // 18850443
  s21_decimal dec_2 = {{0x11fa28b, 0x0, 0x0, 0x0}};
  // 1266487299904058953234479
  s21_decimal dec_check = {{0x7716f82f, 0x6a026571, 0x10c30, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_408) {
  // 9296251.90
  s21_decimal dec_1 = {{0x3768f466, 0x0, 0x0, 0x20000}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -55777511.40
  s21_decimal dec_check = {{0x4c75ba64, 0x1, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_409) {
  // -64796.03
  s21_decimal dec_1 = {{0x62def3, 0x0, 0x0, 0x80020000}};
  // 798260400.2
  s21_decimal dec_2 = {{0xdbccdee2, 0x1, 0x0, 0x10000}};
  // -51724104839171.206
  s21_decimal dec_check = {{0x9f438c86, 0xb7c2cc, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_410) {
  // -555550265814735055081
  s21_decimal dec_1 = {{0xb91ee8e9, 0x1dcf0753, 0x1e, 0x80000000}};
  // -0.035361144550943628
  s21_decimal dec_2 = {{0xbcf6b8c, 0x7da0c6, 0x0, 0x80120000}};
  // 19644893254790002588.901679769
  s21_decimal dec_check = {{0x2877a299, 0x412422f3, 0x3f79dff5, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_411) {
  // 85787213307230.51455046
  s21_decimal dec_1 = {{0x6dd6c246, 0xdac9e47, 0x1d1, 0x80000}};
  // 453396.04
  s21_decimal dec_2 = {{0x2b3d3d4, 0x0, 0x0, 0x20000}};
  // 38895582796133618664.340944178
  s21_decimal dec_check = {{0x89177532, 0x620557bc, 0x7dadac08, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_412) {
  // 30258352450172309272763
  s21_decimal dec_1 = {{0x430cf8bb, 0x4efea5cf, 0x668, 0x0}};
  // 0.4798828775503715690315682633
  s21_decimal dec_2 = {{0xb04a9349, 0x3079824b, 0xf817f85, 0x1c0000}};
  // 14520465243722023833858.817991
  s21_decimal dec_check = {{0xf5113fc7, 0x231e7bce, 0x2eeb0c1e, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_413) {
  // 766277562132466696890
  s21_decimal dec_1 = {{0xd1ff02ba, 0x8a3cc6d8, 0x29, 0x0}};
  // -22
  s21_decimal dec_2 = {{0x16, 0x0, 0x0, 0x80000000}};
  // -16858106366914267331580
  s21_decimal dec_check = {{0xbea3bfc, 0xe13916a2, 0x391, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_414) {
  // -6.5899
  s21_decimal dec_1 = {{0x1016b, 0x0, 0x0, 0x80040000}};
  // 868327
  s21_decimal dec_2 = {{0xd3fe7, 0x0, 0x0, 0x0}};
  // -5722188.0973
  s21_decimal dec_check = {{0x52b09c8d, 0xd, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_415) {
  // -36.29
  s21_decimal dec_1 = {{0xe2d, 0x0, 0x0, 0x80020000}};
  // 857628041631299401285635066
  s21_decimal dec_2 = {{0xd9100bfa, 0x4bca6721, 0x2c569cd, 0x0}};
  // -31123321630799855272655696545
  s21_decimal dec_check = {{0x8015b2a1, 0x5a9a28e8, 0x64909bb6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_416) {
  // 2127338701644807
  s21_decimal dec_1 = {{0xa3a0e407, 0x78ecd, 0x0, 0x0}};
  // -8673866629394
  s21_decimal dec_2 = {{0x8abd4112, 0x7e3, 0x0, 0x80000000}};
  // -18452252173615250296893656958
  s21_decimal dec_check = {{0x7a60cf7e, 0xb1b72cea, 0x3b9f5862, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_417) {
  // -32555.74762305
  s21_decimal dec_1 = {{0xff609341, 0x2f5, 0x0, 0x80080000}};
  // 4591594022776
  s21_decimal dec_2 = {{0x1054a778, 0x42d, 0x0, 0x0}};
  // -149482776193000349.56258680
  s21_decimal dec_check = {{0x16a86d78, 0xc0e49839, 0xc5d6b, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_418) {
  // -2.278636
  s21_decimal dec_1 = {{0x22c4ec, 0x0, 0x0, 0x80060000}};
  // 134090.29328275766595
  s21_decimal dec_2 = {{0x46abfd43, 0xba167121, 0x0, 0xe0000}};
  // -305542.96952464979690964420
  s21_decimal dec_check = {{0x775ac5c4, 0xc1b927a0, 0x19461f, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_419) {
  // 0.68019995517526377461457
  s21_decimal dec_1 = {{0xfe5376d1, 0x5f1081ce, 0xe67, 0x170000}};
  // 96069200648270325
  s21_decimal dec_2 = {{0xd27ef1f5, 0x1554e6d, 0x0, 0x0}};
  // 65346265974676896.622655727374
  s21_decimal dec_check = {{0x2b26670e, 0xad925be1, 0xd3252a10, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_420) {
  // 83294.09938130918588
  s21_decimal dec_1 = {{0x26e6dcbc, 0x73980235, 0x0, 0xe0000}};
  // 65917058.397358456
  s21_decimal dec_2 = {{0x2269c978, 0xea2f37, 0x0, 0x90000}};
  // 5490502013073.1364456523143999
  s21_decimal dec_check = {{0xa6b09b3f, 0x4e122fb0, 0xb1685e41, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_421) {
  // -0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80010000}};
  // -3514.9789469179427
  s21_decimal dec_2 = {{0x1b3d7e23, 0x7ce08c, 0x0, 0x800d0000}};
  // 1405.99157876717708
  s21_decimal dec_check = {{0x6cf5f88c, 0x1f38230, 0x0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_422) {
  // -64949898905705888014.42
  s21_decimal dec_1 = {{0xed2c49a2, 0x18176d8a, 0x160, 0x80020000}};
  // 944.487600
  s21_decimal dec_2 = {{0x384bbcb0, 0x0, 0x0, 0x60000}};
  // -61344374137692780476608.311192
  s21_decimal dec_check = {{0xb9d46f98, 0x7e14d337, 0xc636e081, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_423) {
  // 80606.5
  s21_decimal dec_1 = {{0xc4cb1, 0x0, 0x0, 0x10000}};
  // 7044431067790044
  s21_decimal dec_2 = {{0x6b70badc, 0x1906df, 0x0, 0x0}};
  // 567826932865818181686.0
  s21_decimal dec_check = {{0x82ba821c, 0xd1d11da7, 0x133, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_424) {
  // -1.9923831
  s21_decimal dec_1 = {{0x1300377, 0x0, 0x0, 0x80070000}};
  // 8569972335779982.1845
  s21_decimal dec_2 = {{0x5ae7b215, 0xa5529456, 0x4, 0x40000}};
  // -17074668049275561.82269888195
  s21_decimal dec_check = {{0x71ba06c3, 0xf7abea58, 0x5846228, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_425) {
  // -917959533678421184337
  s21_decimal dec_1 = {{0x8d858f51, 0xc33f6452, 0x31, 0x80000000}};
  // 31.2776
  s21_decimal dec_2 = {{0x4c5c8, 0x0, 0x0, 0x40000}};
  // -28711571110580186435218.9512
  s21_decimal dec_check = {{0x94e54c48, 0xe3041d7c, 0xed7f1d, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_426) {
  // -8630192566.26
  s21_decimal dec_1 = {{0xeff4cb32, 0xc8, 0x0, 0x80020000}};
  // -45109754323127903.29
  s21_decimal dec_2 = {{0x69849d39, 0x3e9a3441, 0x0, 0x80020000}};
  // 389305866425273328964538197.00
  s21_decimal dec_check = {{0x6889fd34, 0xb2baec40, 0x7dcaa062, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_427) {
  // -59
  s21_decimal dec_1 = {{0x3b, 0x0, 0x0, 0x80000000}};
  // 81049724.4092
  s21_decimal dec_2 = {{0xb5667bbc, 0xbc, 0x0, 0x40000}};
  // -4781933740.1428
  s21_decimal dec_check = {{0xce9e8454, 0x2b7d, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_428) {
  // 94.707459
  s21_decimal dec_1 = {{0x5a51f03, 0x0, 0x0, 0x60000}};
  // 533454839.9
  s21_decimal dec_2 = {{0x3df6bfaf, 0x1, 0x0, 0x10000}};
  // 50522152378.1808141
  s21_decimal dec_check = {{0x91e5700d, 0x702e84c, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_429) {
  // -7412871
  s21_decimal dec_1 = {{0x711c87, 0x0, 0x0, 0x80000000}};
  // -8.8949077073
  s21_decimal dec_2 = {{0xb5c73451, 0x14, 0x0, 0x800a0000}};
  // 65936803.3911206583
  s21_decimal dec_check = {{0xbd8672b7, 0x9268bbb, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_430) {
  // 46823
  s21_decimal dec_1 = {{0xb6e7, 0x0, 0x0, 0x0}};
  // -86811040319619385521
  s21_decimal dec_2 = {{0xe106c8b1, 0xb4bec539, 0x4, 0x80000000}};
  // -4064753340885538488249783
  s21_decimal dec_check = {{0xdfccedb7, 0xb85b1d34, 0x35cbe, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_431) {
  // 65606.848887
  s21_decimal dec_1 = {{0x46791177, 0xf, 0x0, 0x60000}};
  // -94757406869148
  s21_decimal dec_2 = {{0x6d93869c, 0x562e, 0x0, 0x80000000}};
  // -6216734873388168618.438276
  s21_decimal dec_check = {{0x33fee84, 0xdf6e2989, 0x52471, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_432) {
  // 0.00
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x20000}};
  // 49689310760858678489840185
  s21_decimal dec_2 = {{0x8860fa39, 0xef0e4584, 0x291a1e, 0x0}};
  // 0.00
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_433) {
  // -0.66317784
  s21_decimal dec_1 = {{0x3f3edd8, 0x0, 0x0, 0x80080000}};
  // 55232332575737862
  s21_decimal dec_2 = {{0x8b4b0806, 0xc43983, 0x0, 0x0}};
  // -36628859015739471.72737808
  s21_decimal dec_check = {{0xad6e5310, 0x714e6842, 0x307a5, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_434) {
  // 5893.6216221177
  s21_decimal dec_1 = {{0x283b75f9, 0x359a, 0x0, 0xa0000}};
  // 7800
  s21_decimal dec_2 = {{0x1e78, 0x0, 0x0, 0x0}};
  // 45970248.6525180600
  s21_decimal dec_check = {{0xd3b27ab8, 0x66130f9, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_435) {
  // -83.91691178938894652638883
  s21_decimal dec_1 = {{0xe59186a3, 0x7d87af8a, 0x6f102, 0x80170000}};
  // -0.782
  s21_decimal dec_2 = {{0x30e, 0x0, 0x0, 0x80030000}};
  // 65.62302501930215618363606506
  s21_decimal dec_check = {{0x428945ea, 0x747a3a49, 0x1534359b, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_436) {
  // -985440
  s21_decimal dec_1 = {{0xf0960, 0x0, 0x0, 0x80000000}};
  // -57838719
  s21_decimal dec_2 = {{0x3728c7f, 0x0, 0x0, 0x80000000}};
  // 56996587251360
  s21_decimal dec_check = {{0x8d5626a0, 0x33d6, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_437) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // -421630024950107356572368733.2
  s21_decimal dec_2 = {{0xff1079a4, 0x849c6dd2, 0xd9fa44e, 0x80010000}};
  // -1686520099800429426289474932.8
  s21_decimal dec_check = {{0xfc41e690, 0x1271b74b, 0x367e913a, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_438) {
  // -113949
  s21_decimal dec_1 = {{0x1bd1d, 0x0, 0x0, 0x80000000}};
  // 5972261618094
  s21_decimal dec_2 = {{0x868841ae, 0x56e, 0x0, 0x0}};
  // -680533239120193206
  s21_decimal dec_check = {{0x179ae6b6, 0x971bd60, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_439) {
  // 0.802
  s21_decimal dec_1 = {{0x322, 0x0, 0x0, 0x30000}};
  // 76629129442890125934.049
  s21_decimal dec_2 = {{0xccdbfde1, 0x12cc5dc7, 0x103a, 0x30000}};
  // 61456561813197880999.107298
  s21_decimal dec_check = {{0xc9315ae2, 0xe43dcbef, 0x32d5ee, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_440) {
  // -25121718353660650340231
  s21_decimal dec_1 = {{0xa0e3f87, 0xd9e06e16, 0x551, 0x80000000}};
  // 980.868687948462191705
  s21_decimal dec_2 = {{0xf7907459, 0x2c499ad2, 0x35, 0x120000}};
  // -24641106920565923791897188.978
  s21_decimal dec_check = {{0x58995a72, 0xc9483ef6, 0x4f9ea55a, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_441) {
  // -545477.163
  s21_decimal dec_1 = {{0x2083522b, 0x0, 0x0, 0x80030000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 3818340.141
  s21_decimal dec_check = {{0xe3973f2d, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_442) {
  // -59480
  s21_decimal dec_1 = {{0xe858, 0x0, 0x0, 0x80000000}};
  // 98708791759298.188899133186
  s21_decimal dec_2 = {{0x966a2702, 0x52cd20fb, 0x51a666, 0xc0000}};
  // -5871198933843056275.7204419033
  s21_decimal dec_check = {{0xadd6a1d9, 0x95676ef2, 0xbdb56b57, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_443) {
  // 90237481
  s21_decimal dec_1 = {{0x560ea29, 0x0, 0x0, 0x0}};
  // -0.40445
  s21_decimal dec_2 = {{0x9dfd, 0x0, 0x0, 0x80050000}};
  // -36496549.19045
  s21_decimal dec_check = {{0xc0628f85, 0x351, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_444) {
  // -59619270.66566
  s21_decimal dec_1 = {{0x1e8b83c6, 0x56c, 0x0, 0x80050000}};
  // 740193701369782379
  s21_decimal dec_2 = {{0xeb20a06b, 0xa45b23f, 0x0, 0x0}};
  // -44129808626981764748652668.405
  s21_decimal dec_check = {{0x54f965f5, 0x3cb677e2, 0x8e975277, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_445) {
  // -507.392959664699
  s21_decimal dec_1 = {{0xa11f523b, 0x1cd78, 0x0, 0x800c0000}};
  // -70270200.716581595954295549
  s21_decimal dec_2 = {{0xd05032fd, 0x36c1db2f, 0x3a204b, 0x80120000}};
  // 35654605117.818788482303517617
  s21_decimal dec_check = {{0xb5e3b1, 0x648127e9, 0x7334cc50, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_446) {
  // 6700851705628621330.52
  s21_decimal dec_1 = {{0x106faf3c, 0x534cc05d, 0x24, 0x20000}};
  // -86694
  s21_decimal dec_2 = {{0x152a6, 0x0, 0x0, 0x80000000}};
  // -580923637767767697628100.88
  s21_decimal dec_check = {{0x1dc8d8e8, 0x59bf9c0c, 0x300d89, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_447) {
  // -1322975518608149594.5026
  s21_decimal dec_1 = {{0x79768f42, 0x2fbc377e, 0x2cd, 0x80040000}};
  // -65
  s21_decimal dec_2 = {{0x41, 0x0, 0x0, 0x80000000}};
  // 85993408709529723642.6690
  s21_decimal dec_check = {{0xd71a5fc2, 0x1eca171c, 0xb619, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_448) {
  // 701739.754856
  s21_decimal dec_1 = {{0x62f2e568, 0xa3, 0x0, 0x60000}};
  // -6.6316461
  s21_decimal dec_2 = {{0x3f3e8ad, 0x0, 0x0, 0x80070000}};
  // -4653689.7085057484616
  s21_decimal dec_check = {{0xf7c34748, 0x85d44555, 0x2, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_449) {
  // 99.956242424
  s21_decimal dec_1 = {{0x45db37f8, 0x17, 0x0, 0x90000}};
  // -0.518891486142
  s21_decimal dec_2 = {{0xd057bbbe, 0x78, 0x0, 0x800c0000}};
  // -51.866443180559388488208
  s21_decimal dec_check = {{0x7fddb210, 0xaf7e2886, 0xafb, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_450) {
  // -6540854
  s21_decimal dec_1 = {{0x63ce36, 0x0, 0x0, 0x80000000}};
  // 379
  s21_decimal dec_2 = {{0x17b, 0x0, 0x0, 0x0}};
  // -2478983666
  s21_decimal dec_check = {{0x93c249f2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_451) {
  // -6929272658982336
  s21_decimal dec_1 = {{0x363f5c0, 0x189e23, 0x0, 0x80000000}};
  // 5228477
  s21_decimal dec_2 = {{0x4fc7bd, 0x0, 0x0, 0x0}};
  // -36229542724217987182272
  s21_decimal dec_check = {{0xb14aec0, 0x1e80355, 0x7ac, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_452) {
  // 60221.2237398
  s21_decimal dec_1 = {{0x36a58056, 0x8c, 0x0, 0x70000}};
  // 5279091
  s21_decimal dec_2 = {{0x508d73, 0x0, 0x0, 0x0}};
  // 317913320253.7645218
  s21_decimal dec_check = {{0xcee804a2, 0x2c1e8ccd, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_453) {
  // 6619.8329
  s21_decimal dec_1 = {{0x3f21b39, 0x0, 0x0, 0x40000}};
  // -0.91868272820922266125762
  s21_decimal dec_2 = {{0xa0e785c2, 0x30657fa8, 0x1374, 0x80170000}};
  // -6081.5261488611702564187482517
  s21_decimal dec_check = {{0xbd572995, 0x4fb41c3a, 0xc481348b, 0x80190000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_454) {
  // -273008461015578
  s21_decimal dec_1 = {{0xbc56ea1a, 0xf84c, 0x0, 0x80000000}};
  // 289710479.1487739200703956
  s21_decimal dec_2 = {{0x14628dd4, 0x5d8da310, 0x2657c, 0x100000}};
  // -79093412052492467799535.314544
  s21_decimal dec_check = {{0x1d6ee670, 0xd48664ea, 0xff90897a, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_455) {
  // -80603083
  s21_decimal dec_1 = {{0x4cde7cb, 0x0, 0x0, 0x80000000}};
  // 2222258.046
  s21_decimal dec_2 = {{0x8474f77e, 0x0, 0x0, 0x30000}};
  // -179120849729155.818
  s21_decimal dec_check = {{0xbbf8f2ea, 0x27c5d76, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_456) {
  // 946
  s21_decimal dec_1 = {{0x3b2, 0x0, 0x0, 0x0}};
  // -1868.972086951860432920
  s21_decimal dec_2 = {{0x1e1ef018, 0x5132b2d8, 0x65, 0x80120000}};
  // -1768047.594256459969542320
  s21_decimal dec_check = {{0x4e5338b0, 0xd58e29f, 0x17666, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_458) {
  // -22800994932980
  s21_decimal dec_1 = {{0xc53418f4, 0x14bc, 0x0, 0x80000000}};
  // 84553.3744944348
  s21_decimal dec_2 = {{0x2a8354dc, 0x30102, 0x0, 0xa0000}};
  // -1927901063413968244.0089797040
  s21_decimal dec_check = {{0x5dd181b0, 0xa5305e97, 0x3e4b394c, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_459) {
  // 6689.080377
  s21_decimal dec_1 = {{0x8eb34439, 0x1, 0x0, 0x60000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -53512.643016
  s21_decimal dec_check = {{0x759a21c8, 0xc, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_460) {
  // 920820
  s21_decimal dec_1 = {{0xe0cf4, 0x0, 0x0, 0x0}};
  // 644713127972206223806
  s21_decimal dec_2 = {{0xde4f21be, 0xf331260d, 0x22, 0x0}};
  // 593664742499366935005040920
  s21_decimal dec_check = {{0x71651118, 0x2d6313f7, 0x1eb1166, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_461) {
  // -29.67826987
  s21_decimal dec_1 = {{0xb0e5722b, 0x0, 0x0, 0x80080000}};
  // 85712565709690221
  s21_decimal dec_2 = {{0xd7e9d56d, 0x130831f, 0x0, 0x0}};
  // -2543800656382294452.93794127
  s21_decimal dec_check = {{0x3fd2634f, 0xfd771b66, 0xd26b12, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_462) {
  // 5397685536778040.175256
  s21_decimal dec_1 = {{0x36c0ea98, 0x9bef3d89, 0x124, 0x60000}};
  // -635.7
  s21_decimal dec_2 = {{0x18d5, 0x0, 0x0, 0x80010000}};
  // -3431308695729800139.4102392
  s21_decimal dec_check = {{0xa4817078, 0x2bd3104c, 0x1c6214, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_463) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1695206.308956
  s21_decimal dec_2 = {{0xb22b7c5c, 0x18a, 0x0, 0x80060000}};
  // 1695206.308956
  s21_decimal dec_check = {{0xb22b7c5c, 0x18a, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_464) {
  // 209575119701935.7766
  s21_decimal dec_1 = {{0x23f04246, 0x1d159a9c, 0x0, 0x40000}};
  // 44650373
  s21_decimal dec_2 = {{0x2a94f85, 0x0, 0x0, 0x0}};
  // 9357607266211081247234.6718
  s21_decimal dec_check = {{0x1c7c085e, 0x104b1c56, 0x4d6781, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_465) {
  // 8.5510
  s21_decimal dec_1 = {{0x14e06, 0x0, 0x0, 0x40000}};
  // -94658
  s21_decimal dec_2 = {{0x171c2, 0x0, 0x0, 0x80000000}};
  // -809420.5580
  s21_decimal dec_check = {{0xe273c68c, 0x1, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_466) {
  // 743572061797347917399132
  s21_decimal dec_1 = {{0x707d845c, 0x1f4b1f0f, 0x9d75, 0x0}};
  // -5406.6211136539678263
  s21_decimal dec_2 = {{0xd8b75637, 0xee51c492, 0x2, 0x80100000}};
  // -4020212408836754182567748007.7
  s21_decimal dec_check = {{0x817ad08d, 0xc1ca7bf6, 0x81e66ae9, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_467) {
  // -0.6923
  s21_decimal dec_1 = {{0x1b0b, 0x0, 0x0, 0x80040000}};
  // 42676915212752388121737.617684
  s21_decimal dec_2 = {{0x3214e114, 0x6eaa997f, 0x89e58451, 0x60000}};
  // -29545228401788478296678.952723
  s21_decimal dec_check = {{0xd5cb6f13, 0xfd6efd42, 0x5f773d78, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_468) {
  // 93708628.611787
  s21_decimal dec_1 = {{0x3d8552cb, 0x553a, 0x0, 0x60000}};
  // -973905864
  s21_decimal dec_2 = {{0x3a0c9fc8, 0x0, 0x0, 0x80000000}};
  // -91263382912417538.818968
  s21_decimal dec_check = {{0xbe18c398, 0x65dcd8b7, 0x1353, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_469) {
  // 820514553978
  s21_decimal dec_1 = {{0xa7a807a, 0xbf, 0x0, 0x0}};
  // 17113
  s21_decimal dec_2 = {{0x42d9, 0x0, 0x0, 0x0}};
  // 14041465562225514
  s21_decimal dec_check = {{0x76f65b6a, 0x31e2a3, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_470) {
  // -698024474527852489956
  s21_decimal dec_1 = {{0x79596ce4, 0xd709194a, 0x25, 0x80000000}};
  // 97
  s21_decimal dec_2 = {{0x61, 0x0, 0x0, 0x0}};
  // -67708374029201691525732
  s21_decimal dec_check = {{0xfae24264, 0x7a729537, 0xe56, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_471) {
  // 245
  s21_decimal dec_1 = {{0xf5, 0x0, 0x0, 0x0}};
  // -4782152.6046963508085902
  s21_decimal dec_2 = {{0xce26848e, 0x68fdba68, 0xa20, 0x80100000}};
  // -1171627388.1506059481045990
  s21_decimal dec_check = {{0x4adcdbe6, 0x7ad3664d, 0x9b104, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_472) {
  // -0.2789755478331
  s21_decimal dec_1 = {{0x8a62613b, 0x289, 0x0, 0x800d0000}};
  // -6.8924983547248692
  s21_decimal dec_2 = {{0x487bc034, 0xf4dee8, 0x0, 0x80100000}};
  // 1.9228385044481107988947409305
  s21_decimal dec_check = {{0xeba01999, 0xee4302c7, 0x3e2158e9, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_473) {
  // -8.054
  s21_decimal dec_1 = {{0x1f76, 0x0, 0x0, 0x80030000}};
  // 925672470512600
  s21_decimal dec_2 = {{0xeac883d8, 0x349e4, 0x0, 0x0}};
  // -7455366077508480.400
  s21_decimal dec_check = {{0x8063ed90, 0x6776c7f2, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_474) {
  // 6879246864492.3
  s21_decimal dec_1 = {{0xfea8243b, 0x3e90, 0x0, 0x10000}};
  // -7.963692529695797788332953289
  s21_decimal dec_2 = {{0x923a8ec9, 0x15cba010, 0x19bb697d, 0x801b0000}};
  // -54784206864690.569641736845952
  s21_decimal dec_check = {{0x42a4ba80, 0x7967d92, 0xb1046f0d, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_476) {
  // 0.56
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x20000}};
  // 50020.405099753032666
  s21_decimal dec_2 = {{0x33eacbda, 0xb62c2d6b, 0x2, 0xf0000}};
  // 28011.42685586169829296
  s21_decimal dec_check = {{0x5b5c97b0, 0xd9a9ef73, 0x97, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_477) {
  // 6286650368.69221984334544581
  s21_decimal dec_1 = {{0xe2e87ec5, 0xefdce7fb, 0x20804ff, 0x110000}};
  // 29522
  s21_decimal dec_2 = {{0x7352, 0x0, 0x0, 0x0}};
  // 185594492184531.71421524425120
  s21_decimal dec_check = {{0xa31a79a0, 0x2399d934, 0x3bf8043e, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_478) {
  // 0.01
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x20000}};
  // -4.930
  s21_decimal dec_2 = {{0x1342, 0x0, 0x0, 0x80030000}};
  // -0.04930
  s21_decimal dec_check = {{0x1342, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_479) {
  // 7344.3961745985535010
  s21_decimal dec_1 = {{0xced87c22, 0xfb3d5e15, 0x3, 0x100000}};
  // -54572524236468.71291
  s21_decimal dec_2 = {{0x611c7efb, 0x4bbc0e2a, 0x0, 0x80050000}};
  // -400802238240507661.80705410633
  s21_decimal dec_check = {{0xcecc9e49, 0x2fe2e0f8, 0x81819587, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_480) {
  // -592230052
  s21_decimal dec_1 = {{0x234cb6a4, 0x0, 0x0, 0x80000000}};
  // -64199.153883
  s21_decimal dec_2 = {{0xf29158db, 0xe, 0x0, 0x80060000}};
  // 38020668242485.091916
  s21_decimal dec_check = {{0xc4c9e4c, 0xfa48c53, 0x2, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_481) {
  // 648969659614.37483633
  s21_decimal dec_1 = {{0xfc191271, 0x84a056b3, 0x3, 0x80000}};
  // -0.51
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80020000}};
  // -330974526403.3311665283
  s21_decimal dec_check = {{0x38feac83, 0x6bf145db, 0xb3, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_482) {
  // -41165852834.209080956
  s21_decimal dec_1 = {{0xf30a267c, 0x3b4a7d0b, 0x2, 0x80090000}};
  // -635260773029480
  s21_decimal dec_2 = {{0x2cb75668, 0x241c4, 0x0, 0x80000000}};
  // 26151051493877470953280622.695
  s21_decimal dec_check = {{0x1377d067, 0x1f42c3ed, 0x547fa48e, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_483) {
  // -0.90399
  s21_decimal dec_1 = {{0x1611f, 0x0, 0x0, 0x80050000}};
  // -242201.4
  s21_decimal dec_2 = {{0x24f4fe, 0x0, 0x0, 0x80010000}};
  // 218947.643586
  s21_decimal dec_check = {{0xfa4be8c2, 0x32, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_484) {
  // -96736245741345031
  s21_decimal dec_1 = {{0x5c515907, 0x157ad1a, 0x0, 0x80000000}};
  // -38502411995
  s21_decimal dec_2 = {{0xf6ec2edb, 0x8, 0x0, 0x80000000}};
  // 3724578788382830589008046845
  s21_decimal dec_check = {{0x640a6afd, 0xb2a9e0e6, 0xc08e63c, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_485) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -511541063532493607750645
  s21_decimal dec_2 = {{0x80e34bf5, 0xb255ae17, 0x6c52, 0x80000000}};
  // 3580787444727455254254515
  s21_decimal dec_check = {{0x863713b3, 0xe057c2a4, 0x2f642, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_486) {
  // 803753155
  s21_decimal dec_1 = {{0x2fe84cc3, 0x0, 0x0, 0x0}};
  // -52500.301
  s21_decimal dec_2 = {{0x321174d, 0x0, 0x0, 0x80030000}};
  // -42197282567199.655
  s21_decimal dec_check = {{0x75e79ba7, 0x95ea34, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_487) {
  // -23767041.0880
  s21_decimal dec_1 = {{0x5642aa80, 0x37, 0x0, 0x80040000}};
  // 2828401139
  s21_decimal dec_2 = {{0xa895f9f3, 0x0, 0x0, 0x0}};
  // -67222726083958999.2320
  s21_decimal dec_check = {{0xf59e5780, 0x7106fc1e, 0x24, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_488) {
  // -2.0
  s21_decimal dec_1 = {{0x14, 0x0, 0x0, 0x80010000}};
  // -48330
  s21_decimal dec_2 = {{0xbcca, 0x0, 0x0, 0x80000000}};
  // 96660.0
  s21_decimal dec_check = {{0xebfc8, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_489) {
  // 3051095965073208816912
  s21_decimal dec_1 = {{0xb840b510, 0x66765ed5, 0xa5, 0x0}};
  // 579267.6317664786201
  s21_decimal dec_2 = {{0x853a3719, 0x5063b86b, 0x0, 0xd0000}};
  // 1767401133980216238042917864.9
  s21_decimal dec_check = {{0xddf5b719, 0x8eae4f83, 0x391b997a, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_490) {
  // 1377702903934059.40
  s21_decimal dec_1 = {{0x638059f4, 0x1e97559, 0x0, 0x20000}};
  // 62033063908
  s21_decimal dec_2 = {{0x71756fe4, 0xe, 0x0, 0x0}};
  // 85463132285978691378068135.20
  s21_decimal dec_check = {{0x15d4e950, 0x75995277, 0x1b9d5838, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_491) {
  // 93898.712685
  s21_decimal dec_1 = {{0xdccca66d, 0x15, 0x0, 0x60000}};
  // -2.6672114
  s21_decimal dec_2 = {{0x196fbf2, 0x0, 0x0, 0x80070000}};
  // -250447.7169187566090
  s21_decimal dec_check = {{0x5180320a, 0x22c1b0b7, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_492) {
  // -69.144338
  s21_decimal dec_1 = {{0x41f0f12, 0x0, 0x0, 0x80060000}};
  // 787427722.495050
  s21_decimal dec_2 = {{0x4daf844a, 0x2cc29, 0x0, 0x60000}};
  // -54446168594.767940526900
  s21_decimal dec_check = {{0xec0da334, 0x885fecc6, 0xb87, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_493) {
  // -3667074563078146138853
  s21_decimal dec_1 = {{0x37aea2e5, 0xcae1f620, 0xc6, 0x80000000}};
  // -7674
  s21_decimal dec_2 = {{0x1dfa, 0x0, 0x0, 0x80000000}};
  // 28141130197061693469557922
  s21_decimal dec_check = {{0x28ff04a2, 0xb98c01c5, 0x17471d, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_494) {
  // 801448363052700455015110
  s21_decimal dec_1 = {{0x6efe12c6, 0x9a524504, 0xa9b6, 0x0}};
  // 78997
  s21_decimal dec_2 = {{0x13495, 0x0, 0x0, 0x0}};
  // 63312016336074177844828644670
  s21_decimal dec_check = {{0x4877253e, 0xcceb811e, 0xcc9278f2, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_495) {
  // -51713662673044
  s21_decimal dec_1 = {{0x867e6094, 0x2f08, 0x0, 0x80000000}};
  // -9346.46382198194017
  s21_decimal dec_2 = {{0xc186ff61, 0xcf887ee, 0x0, 0x800e0000}};
  // 483339877275783620.65761547978
  s21_decimal dec_check = {{0xa62336ca, 0xf4d72fd3, 0x9c2cf004, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_496) {
  // 608197483049934.2950863647410
  s21_decimal dec_1 = {{0xc34ab2b2, 0x36235faf, 0x13a6e444, 0xd0000}};
  // 8724703835217.79
  s21_decimal dec_2 = {{0xd7496ff3, 0x31981, 0x0, 0x20000}};
  // 5306342912935568570671473302.1
  s21_decimal dec_check = {{0x1aee59dd, 0x1432e678, 0xab750a31, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_497) {
  // -137
  s21_decimal dec_1 = {{0x89, 0x0, 0x0, 0x80000000}};
  // -7381138.134854
  s21_decimal dec_2 = {{0x8e1dd746, 0x6b6, 0x0, 0x80060000}};
  // 1011215924.474998
  s21_decimal dec_check = {{0xdf83476, 0x397b2, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_498) {
  // -1.607971050365
  s21_decimal dec_1 = {{0x628b137d, 0x176, 0x0, 0x800c0000}};
  // -1870293847191018.4369
  s21_decimal dec_2 = {{0xa23195b1, 0x38e2f72, 0x1, 0x80040000}};
  // 3007378361958938.7207761734745
  s21_decimal dec_check = {{0xb4f82c59, 0xc2c9a80a, 0x612c7364, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_499) {
  // -9298089
  s21_decimal dec_1 = {{0x8de0a9, 0x0, 0x0, 0x80000000}};
  // 7227367
  s21_decimal dec_2 = {{0x6e47e7, 0x0, 0x0, 0x0}};
  // -67200701601663
  s21_decimal dec_check = {{0x61f2977f, 0x3d1e, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_500) {
  // 132197796
  s21_decimal dec_1 = {{0x7e12da4, 0x0, 0x0, 0x0}};
  // -411897895439814099272.05
  s21_decimal dec_2 = {{0x9ef08025, 0xe728bd64, 0x8b8, 0x80020000}};
  // -54451993954181874573490214402
  s21_decimal dec_check = {{0xead75602, 0x10881f73, 0xaff1a23b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_mul_1) {
  // 131498299767401667832.67483
  s21_decimal dec_1 = {{0x85ecf29b, 0xb6204402, 0xae095, 0x50000}};
  // 57675534954633
  s21_decimal dec_2 = {{0xa1c5f089, 0x3474, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_2) {
  // 3665031550069976159117
  s21_decimal dec_1 = {{0x8835538d, 0xae87b89e, 0xc6, 0x0}};
  // -85171121851915041057
  s21_decimal dec_2 = {{0x80e7f921, 0x9dfc9c11, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_3) {
  // 86260214966808716852341789
  s21_decimal dec_1 = {{0xf3d42c1d, 0x9f90da5f, 0x475a4f, 0x0}};
  // -8403.63938962477228988
  s21_decimal dec_2 = {{0x228123bc, 0x8e64760c, 0x2d, 0x80110000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_4) {
  // -181254227429482
  s21_decimal dec_1 = {{0x89d7086a, 0xa4d9, 0x0, 0x80000000}};
  // 69355380156744493965972.52
  s21_decimal dec_2 = {{0xccdd8204, 0x44ea20a3, 0x5bca8, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_5) {
  // -658.411
  s21_decimal dec_1 = {{0xa0beb, 0x0, 0x0, 0x80030000}};
  // -76834321077174681219595587911
  s21_decimal dec_2 = {{0xaca15147, 0xaa842105, 0xf843dc5b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_6) {
  // 464606623434924365739494
  s21_decimal dec_1 = {{0x781c75e6, 0x602256ac, 0x6262, 0x0}};
  // 891147959950
  s21_decimal dec_2 = {{0x7c8ebe8e, 0xcf, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_7) {
  // 25922484035295225577004313210
  s21_decimal dec_1 = {{0x691faa7a, 0x5d48f48a, 0x53c29383, 0x0}};
  // -4781272785149719.551807633
  s21_decimal dec_2 = {{0x1dc21091, 0x5129e0c3, 0x3f479, 0x80090000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_8) {
  // 63333311856430031215
  s21_decimal dec_1 = {{0x438c216f, 0x6eed1f94, 0x3, 0x0}};
  // 7574089761334
  s21_decimal dec_2 = {{0x7aee0236, 0x6e3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_9) {
  // -916767886649410378256623435
  s21_decimal dec_1 = {{0xc6e8274b, 0xb7f0632b, 0x2f65526, 0x80000000}};
  // -2129002548274801407585969571
  s21_decimal dec_2 = {{0x9b4065a3, 0x674102c2, 0x6e111d3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_10) {
  // -4594447091344118
  s21_decimal dec_1 = {{0x12d1a2f6, 0x1052a0, 0x0, 0x80000000}};
  // -554875933776253
  s21_decimal dec_2 = {{0x1eed597d, 0x1f8a8, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_11) {
  // -31296471712617051380617591
  s21_decimal dec_1 = {{0xa1699177, 0x218f9b87, 0x19e349, 0x80000000}};
  // 882226722
  s21_decimal dec_2 = {{0x3495b622, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_12) {
  // -7323020248702655.771
  s21_decimal dec_1 = {{0xfeea1d1b, 0x65a0981d, 0x0, 0x80030000}};
  // -75328757266225436.81706002776
  s21_decimal dec_2 = {{0xabb80958, 0x64b42c77, 0x18570c7b, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_13) {
  // -724222002506824817384715730
  s21_decimal dec_1 = {{0x251975d2, 0x6c8a4986, 0x2570ff9, 0x80000000}};
  // -209222.5470469972
  s21_decimal dec_2 = {{0x33f51754, 0x76ede, 0x0, 0x800a0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_14) {
  // -90518510677481514064
  s21_decimal dec_1 = {{0xa0b06450, 0xe83259df, 0x4, 0x80000000}};
  // 3407091912741356425717406
  s21_decimal dec_2 = {{0xd57c269e, 0xd29b53a7, 0x2d17a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_15) {
  // -6485379323.84186649259
  s21_decimal dec_1 = {{0xf5bfcaab, 0x28459566, 0x23, 0x800b0000}};
  // -5280360696523037261892.2633
  s21_decimal dec_2 = {{0x30f66a89, 0x44f3611d, 0x2bad99, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_16) {
  // 43868893540578969647954
  s21_decimal dec_1 = {{0x15d1fb52, 0x233227cc, 0x94a, 0x0}};
  // 64491344636847.190705
  s21_decimal dec_2 = {{0xe691f2b1, 0x7eff4841, 0x3, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_17) {
  // -311719433622507918861310574
  s21_decimal dec_1 = {{0x681c9a6e, 0x5b62a0f0, 0x101d928, 0x80000000}};
  // 353952501460946.2138929030892
  s21_decimal dec_2 = {{0x7f8226ec, 0x8533943b, 0xb6fd393, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_18) {
  // 52371735073.4170865
  s21_decimal dec_1 = {{0xdd380af1, 0x7449e27, 0x0, 0x70000}};
  // -8793758317749674869759
  s21_decimal dec_2 = {{0x3a0283ff, 0xb5e976aa, 0x1dc, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_19) {
  // -358810165399
  s21_decimal dec_1 = {{0x8ac0a097, 0x53, 0x0, 0x80000000}};
  // -7010474245264218813618449384
  s21_decimal dec_2 = {{0x79a7ebe8, 0x57eccedc, 0x16a6edaa, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_20) {
  // 597.1
  s21_decimal dec_1 = {{0x1753, 0x0, 0x0, 0x10000}};
  // 79228162514264337593331698779
  s21_decimal dec_2 = {{0xf3594c5b, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_21) {
  // 111134695611117861834120417
  s21_decimal dec_1 = {{0xe5c0dce1, 0xebc6f2cb, 0x5bedaf, 0x0}};
  // -31872125427
  s21_decimal dec_2 = {{0x6bba09f3, 0x7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_22) {
  // -75589980189983693
  s21_decimal dec_1 = {{0xbdcd83cd, 0x10c8caf, 0x0, 0x80000000}};
  // 74256844678017276339338
  s21_decimal dec_2 = {{0x2f96648a, 0x78bbd508, 0xfb9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_23) {
  // 76723725686575712429.355512
  s21_decimal dec_1 = {{0xa2d731f8, 0x80e73c21, 0x3f76e1, 0x60000}};
  // -37374576596756379367
  s21_decimal dec_2 = {{0x504ab6e7, 0x6ad2b65, 0x2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_24) {
  // 8766.61363435
  s21_decimal dec_1 = {{0x1d16d2eb, 0xcc, 0x0, 0x80000}};
  // 9986968531129077984415981355
  s21_decimal dec_2 = {{0x74dc1f2b, 0xe6546bf6, 0x204506d8, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_25) {
  // -5723349042
  s21_decimal dec_1 = {{0x55236032, 0x1, 0x0, 0x80000000}};
  // 86565180689840720421305.4802
  s21_decimal dec_2 = {{0xc57d5d52, 0x7b965752, 0x2cc0ce6, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_26) {
  // 22423115438209402823082894730
  s21_decimal dec_1 = {{0x72c9e58a, 0x99993be6, 0x4873f763, 0x0}};
  // 455580655412.842142151936
  s21_decimal dec_2 = {{0xd20cb500, 0x13aa4837, 0x6079, 0xc0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_27) {
  // -90406.34974578666716202
  s21_decimal dec_1 = {{0xd6153c2a, 0x18038a0a, 0x1ea, 0x80110000}};
  // -9147844845281903669946773
  s21_decimal dec_2 = {{0xfe02995, 0xa9a960af, 0x79121, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_28) {
  // 395603982618786136.3827
  s21_decimal dec_1 = {{0xa98c0c73, 0x7514cdeb, 0xd6, 0x40000}};
  // 117015313461780174
  s21_decimal dec_2 = {{0xc02b9ece, 0x19fb8ce, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_29) {
  // 33338588521052
  s21_decimal dec_1 = {{0x3eb9e25c, 0x1e52, 0x0, 0x0}};
  // -5808945304548230298404235
  s21_decimal dec_2 = {{0x320d058b, 0x8e52df58, 0x4ce17, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_30) {
  // 9430431704109030352168779
  s21_decimal dec_1 = {{0x2865274b, 0xba202e9c, 0x7ccf8, 0x0}};
  // -366328672294031111873171768.6
  s21_decimal dec_2 = {{0x8022ac36, 0x2c264dda, 0xbd63323, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_31) {
  // 84791950802
  s21_decimal dec_1 = {{0xbdfe7dd2, 0x13, 0x0, 0x0}};
  // 60364724042217721579
  s21_decimal dec_2 = {{0xbcde8eeb, 0x45ba94b0, 0x3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_32) {
  // -7943940064205546998995736941
  s21_decimal dec_1 = {{0xc749d96d, 0xc90a605d, 0x19ab12bd, 0x80000000}};
  // 48359268968953
  s21_decimal dec_2 = {{0x850c69f9, 0x2bfb, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_33) {
  // 56
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x0}};
  // -9023594581637650495734026773
  s21_decimal dec_2 = {{0x6d481215, 0x73b62a16, 0x1d28247a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_34) {
  // -359805568495487040717619372
  s21_decimal dec_1 = {{0xd6c880ac, 0xf3a681e3, 0x1299fca, 0x80000000}};
  // -23074899095
  s21_decimal dec_2 = {{0x5f5f0497, 0x5, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_35) {
  // -688646662826505940
  s21_decimal dec_1 = {{0xc18836d4, 0x98e907d, 0x0, 0x80000000}};
  // 60991449506997967000
  s21_decimal dec_2 = {{0x18c99898, 0x4e6d282e, 0x3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_36) {
  // 58945909213837397298143753131
  s21_decimal dec_1 = {{0x910ef3ab, 0x70549a75, 0xbe76e9cd, 0x0}};
  // 2807656176317
  s21_decimal dec_2 = {{0xb5595abd, 0x28d, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_37) {
  // -622670064191438554363253
  s21_decimal dec_1 = {{0xf51f7575, 0x3066eb8, 0x83db, 0x80000000}};
  // -6429557208551671
  s21_decimal dec_2 = {{0xf17a90f7, 0x16d7a5, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_38) {
  // -9809865077558121158663074904
  s21_decimal dec_1 = {{0x2071f458, 0x71a412f1, 0x1fb287bb, 0x80000000}};
  // -904635246983819829851697448
  s21_decimal dec_2 = {{0xd243b128, 0x11c7c7e, 0x2ec4bf7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_39) {
  // 807048160896463168097360324
  s21_decimal dec_1 = {{0x542a19c4, 0x779ba6f9, 0x29b9318, 0x0}};
  // -346700.5580696484226941
  s21_decimal dec_2 = {{0x1ed6a77d, 0xf25e26a9, 0xbb, 0x80100000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_40) {
  // -9789311854653.11
  s21_decimal dec_1 = {{0x2d91b7df, 0x37a55, 0x0, 0x80020000}};
  // -6412843582380360706748369
  s21_decimal dec_2 = {{0x81e2efd1, 0xf27b2176, 0x54df8, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_41) {
  // -975941129647260524371
  s21_decimal dec_1 = {{0xe695f53, 0xe7e766a8, 0x34, 0x80000000}};
  // 1276072199830
  s21_decimal dec_2 = {{0x1bd48696, 0x129, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_42) {
  // 25769555004222474950
  s21_decimal dec_1 = {{0x4e920ac6, 0x659fd9be, 0x1, 0x0}};
  // -324755357551512054379.7
  s21_decimal dec_2 = {{0x9c792835, 0xcdc02a7, 0xb0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_43) {
  // -926263365079515527
  s21_decimal dec_1 = {{0x7c05c187, 0xcdabf9f, 0x0, 0x80000000}};
  // -7580670958145241227292
  s21_decimal dec_2 = {{0x2732201c, 0xf2f16851, 0x19a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_44) {
  // 12611340487
  s21_decimal dec_1 = {{0xefb1c8c7, 0x2, 0x0, 0x0}};
  // 1867636863715892089587.173
  s21_decimal dec_2 = {{0x8c2c05e5, 0xcc18c169, 0x18b7c, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_45) {
  // 650085256432555
  s21_decimal dec_1 = {{0xc4c88bab, 0x24f3f, 0x0, 0x0}};
  // -907116737805715694828331
  s21_decimal dec_2 = {{0x476e3b2b, 0xe59aabd7, 0xc016, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_46) {
  // 58663640457857361.901806568
  s21_decimal dec_1 = {{0xca5463e8, 0x524edd44, 0x308682, 0x90000}};
  // 3388263108513116027624630
  s21_decimal dec_2 = {{0xeb881cb6, 0x1c74fd59, 0x2cd7e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_47) {
  // 37063423697686073705483677
  s21_decimal dec_1 = {{0x408fcd9d, 0x3981f2ad, 0x1ea87c, 0x0}};
  // 21042543.7263181
  s21_decimal dec_2 = {{0x7d70954d, 0xbf61, 0x0, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_48) {
  // -3467
  s21_decimal dec_1 = {{0xd8b, 0x0, 0x0, 0x80000000}};
  // 35303292336130582675551255154
  s21_decimal dec_2 = {{0x4ecd7a72, 0x56100353, 0x721232f0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_49) {
  // -5341164723002459
  s21_decimal dec_1 = {{0xd2005c5b, 0x12f9c2, 0x0, 0x80000000}};
  // -224516834418444707
  s21_decimal dec_2 = {{0x119b49a3, 0x31da4df, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_50) {
  // -7280
  s21_decimal dec_1 = {{0x1c70, 0x0, 0x0, 0x80000000}};
  // 98413375276880775240607602
  s21_decimal dec_2 = {{0x1af5e772, 0xc38b19f3, 0x5167d7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_51) {
  // -2210133842216549068
  s21_decimal dec_1 = {{0xb62facc, 0x1eabf905, 0x0, 0x80000000}};
  // 2532281088851987721.7
  s21_decimal dec_2 = {{0x4c9f0261, 0x5f6cb256, 0x1, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_52) {
  // 4626025811511770195323
  s21_decimal dec_1 = {{0xb335a57b, 0xc7012dd5, 0xfa, 0x0}};
  // 9623701112
  s21_decimal dec_2 = {{0x3d9e0678, 0x2, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_53) {
  // -17672585291967119171955
  s21_decimal dec_1 = {{0x9d272173, 0x86381ac, 0x3be, 0x80000000}};
  // 90292838.157645
  s21_decimal dec_2 = {{0xf08b4d4d, 0x521e, 0x0, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_54) {
  // 31576965132
  s21_decimal dec_1 = {{0x5a22400c, 0x7, 0x0, 0x0}};
  // -5970638031155165316804
  s21_decimal dec_2 = {{0x214ac6c4, 0xab3f678a, 0x143, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_55) {
  // -25168807983415491215833
  s21_decimal dec_1 = {{0x4802c1d9, 0x676066db, 0x554, 0x80000000}};
  // -8532354591.03996888230821
  s21_decimal dec_2 = {{0x8d682ba5, 0xfca6cbe0, 0xb4ad, 0x800e0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_56) {
  // 332780733.7
  s21_decimal dec_1 = {{0xc65a4f69, 0x0, 0x0, 0x10000}};
  // 12287188795148860499772555
  s21_decimal dec_2 = {{0xc75448b, 0xd6da8794, 0xa29e9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_57) {
  // -931885238714733295796636072
  s21_decimal dec_1 = {{0xe3249a8, 0x41e1a66, 0x302d660, 0x80000000}};
  // 3932133507845
  s21_decimal dec_2 = {{0x856bc305, 0x393, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_58) {
  // -5377458996449690136
  s21_decimal dec_1 = {{0x5d9cc218, 0x4aa09277, 0x0, 0x80000000}};
  // -55338647841127229593289
  s21_decimal dec_2 = {{0x79d096c9, 0xea0326c8, 0xbb7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_59) {
  // 70307469407783352610.190784567
  s21_decimal dec_1 = {{0xee67f837, 0xb19fabcb, 0xe32cf9c1, 0x90000}};
  // 21838136763575857778863244595
  s21_decimal dec_2 = {{0x88560533, 0x1af00d07, 0x46901556, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_60) {
  // -146360458527572
  s21_decimal dec_1 = {{0x3323c354, 0x851d, 0x0, 0x80000000}};
  // -47474155803566728228665
  s21_decimal dec_2 = {{0x881b2f39, 0x9442b67c, 0xa0d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_61) {
  // 7645.467
  s21_decimal dec_1 = {{0x74a91b, 0x0, 0x0, 0x30000}};
  // 8845651032409587394128877369
  s21_decimal dec_2 = {{0x55e79739, 0x51c15076, 0x1c94f377, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_62) {
  // -42664435977552058725530319428
  s21_decimal dec_1 = {{0x2ce7ba44, 0xbc8d6baf, 0x89db31bc, 0x80000000}};
  // 58463
  s21_decimal dec_2 = {{0xe45f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_63) {
  // -594.6
  s21_decimal dec_1 = {{0x173a, 0x0, 0x0, 0x80010000}};
  // -926914303831319442479684162.6
  s21_decimal dec_2 = {{0xcde069a, 0xf5fdb8b4, 0x1df34162, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_64) {
  // -47454218031
  s21_decimal dec_1 = {{0xc7de72f, 0xb, 0x0, 0x80000000}};
  // 4293983701723588729
  s21_decimal dec_2 = {{0x1c8d2879, 0x3b974b6d, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_65) {
  // 59708798280
  s21_decimal dec_1 = {{0xe6ebf548, 0xd, 0x0, 0x0}};
  // -418291921542528480015.555877
  s21_decimal dec_2 = {{0x5c801d25, 0x80e3e309, 0x15a00c2, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_66) {
  // -45504016452670.905842171268
  s21_decimal dec_1 = {{0x6d207d84, 0xacbbc458, 0x25a3d9, 0x800c0000}};
  // 7850383908241859.9391801161590
  s21_decimal dec_2 = {{0x16e8b776, 0x149dec6c, 0xfda8da8c, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_67) {
  // 60670497
  s21_decimal dec_1 = {{0x39dc221, 0x0, 0x0, 0x0}};
  // -6974814182307567367962711051
  s21_decimal dec_2 = {{0x1fc3540b, 0x74ffd34f, 0x16896e5a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_68) {
  // -77915394
  s21_decimal dec_1 = {{0x4a4e502, 0x0, 0x0, 0x80000000}};
  // 16424036019806100020815
  s21_decimal dec_2 = {{0xcb185e4f, 0x59496dbd, 0x37a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_69) {
  // -6002793500048934128
  s21_decimal dec_1 = {{0x5670c4f0, 0x534e34e2, 0x0, 0x80000000}};
  // -21099055586937062661809152
  s21_decimal dec_2 = {{0x58d3e400, 0x18617bc2, 0x1173e6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_70) {
  // -65998709644635384031293520
  s21_decimal dec_1 = {{0xbf893050, 0x3809adbd, 0x3697c5, 0x80000000}};
  // 8850782
  s21_decimal dec_2 = {{0x870d5e, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_71) {
  // -346567997.176356537887
  s21_decimal dec_1 = {{0x6750061f, 0xc998dd3c, 0x12, 0x800c0000}};
  // -305344965398418819294
  s21_decimal dec_2 = {{0x2eb208de, 0x8d833c3e, 0x10, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_72) {
  // 338807495776610595091.66669129
  s21_decimal dec_1 = {{0xfdc9fd49, 0xe07abdaa, 0x6d797fca, 0x80000}};
  // -3549945993
  s21_decimal dec_2 = {{0xd397e089, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_73) {
  // 49762266964934660196
  s21_decimal dec_1 = {{0x1f161064, 0xb2971627, 0x2, 0x0}};
  // -715065669167837707299559769
  s21_decimal dec_2 = {{0xd759959, 0x995d35ec, 0x24f7d0b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_74) {
  // 990648458483365036939092727
  s21_decimal dec_1 = {{0x478122f7, 0x8af87b2a, 0x33371f8, 0x0}};
  // 92854495643586611556240
  s21_decimal dec_2 = {{0xb446af90, 0xa6fccfa3, 0x13a9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_75) {
  // -880307356340733572269952209
  s21_decimal dec_1 = {{0x23234cd1, 0x68f46e59, 0x2d82c55, 0x80000000}};
  // 82818194767270926
  s21_decimal dec_2 = {{0x980ad40e, 0x1263ab5, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_76) {
  // 20456149002116753075519
  s21_decimal dec_1 = {{0x4e792d3f, 0xee18601a, 0x454, 0x0}};
  // 45632212.850
  s21_decimal dec_2 = {{0x9fe44f72, 0xa, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_77) {
  // -4608427.5512952150346
  s21_decimal dec_1 = {{0xbed94a, 0x7f8c3c6a, 0x2, 0x800d0000}};
  // 883511755688633199814675
  s21_decimal dec_2 = {{0xe128e813, 0x44abd0e8, 0xbb17, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_78) {
  // -8896098868096308.9
  s21_decimal dec_1 = {{0x41324411, 0x13c0d8c, 0x0, 0x80010000}};
  // -4139412288521540.757
  s21_decimal dec_2 = {{0x7c369495, 0x3972258b, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_79) {
  // 8152113.7876586654941534958981
  s21_decimal dec_1 = {{0xa2bb3585, 0x76db0816, 0x768b46b, 0x160000}};
  // -79228162514264337592768110955
  s21_decimal dec_2 = {{0xd1c1a16b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_80) {
  // 258963920337094631756242
  s21_decimal dec_1 = {{0x299011d2, 0x765618ef, 0x36d6, 0x0}};
  // 4309849.6
  s21_decimal dec_2 = {{0x291a180, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_81) {
  // -840660697197754
  s21_decimal dec_1 = {{0x923bacba, 0x2fc93, 0x0, 0x80000000}};
  // 8450937572769151
  s21_decimal dec_2 = {{0x3c0b3d7f, 0x1e0615, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_82) {
  // 950978.23459153031773
  s21_decimal dec_1 = {{0x13a0325d, 0x27bf5696, 0x5, 0xe0000}};
  // 9143856450737377387363766237
  s21_decimal dec_2 = {{0x73010fdd, 0x7072e121, 0x1d8b9eeb, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_83) {
  // 8619626992108368
  s21_decimal dec_1 = {{0x4cf60350, 0x1e9f81, 0x0, 0x0}};
  // -8939432621866594133271
  s21_decimal dec_2 = {{0x9934e517, 0x9b8c8e71, 0x1e4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_84) {
  // 791409564858546183681038
  s21_decimal dec_1 = {{0x30c3340e, 0x66029b44, 0xa796, 0x0}};
  // -8134585692419401458
  s21_decimal dec_2 = {{0x9fa226f2, 0x70e3da96, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_85) {
  // -775781219863393806
  s21_decimal dec_1 = {{0xc160760e, 0xac420e8, 0x0, 0x80000000}};
  // -6532364659721483110102871797
  s21_decimal dec_2 = {{0x5f0c2ef5, 0xc6e17e21, 0x151b7205, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_86) {
  // -6970982302740986769339270
  s21_decimal dec_1 = {{0x392e7386, 0xb5359fc6, 0x5c429, 0x80000000}};
  // 2674524344136723644
  s21_decimal dec_2 = {{0x83676cbc, 0x251dd1b8, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_87) {
  // 52176671996141814062078663323
  s21_decimal dec_1 = {{0xf0ca9a9b, 0x90640f7a, 0xa8978810, 0x0}};
  // -70.82187818079405
  s21_decimal dec_2 = {{0x592114ad, 0x192936, 0x0, 0x800e0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_88) {
  // 3320215611956190
  s21_decimal dec_1 = {{0xf020dbde, 0xbcbb7, 0x0, 0x0}};
  // 147239432319076628
  s21_decimal dec_2 = {{0xcc4f0914, 0x20b197b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_89) {
  // -4237019095186993705443200033
  s21_decimal dec_1 = {{0x1d290c21, 0x64a9c115, 0xdb0c7b1, 0x80000000}};
  // 343059935826526
  s21_decimal dec_2 = {{0xdd9c925e, 0x13802, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_90) {
  // 2704217748274070063
  s21_decimal dec_1 = {{0xe92ec22f, 0x25874fb6, 0x0, 0x0}};
  // 1745306304974015.53693356
  s21_decimal dec_2 = {{0xb1322aac, 0x530e5679, 0x24f5, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_91) {
  // 87757443
  s21_decimal dec_1 = {{0x53b1283, 0x0, 0x0, 0x0}};
  // 35566991993993387630736.51
  s21_decimal dec_2 = {{0xd7f7b873, 0xcc915b6, 0x2f129, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_92) {
  // -617525548030362317243114154
  s21_decimal dec_1 = {{0xc70562aa, 0x9783e72, 0x1fece1f, 0x80000000}};
  // -198297979802450081418
  s21_decimal dec_2 = {{0xaa9f368a, 0xbfeff200, 0xa, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_93) {
  // 6926.113793029139
  s21_decimal dec_1 = {{0x884eb413, 0x189b43, 0x0, 0xc0000}};
  // 76787353395739978977555961028
  s21_decimal dec_2 = {{0xb766d4c4, 0x8dbd849b, 0xf81d0290, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_94) {
  // 8934658945251517476049
  s21_decimal dec_1 = {{0xb6f92cd1, 0x594d0cda, 0x1e4, 0x0}};
  // 60881989611148
  s21_decimal dec_2 = {{0x315d2e8c, 0x375f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_95) {
  // -7783056842189878541471702
  s21_decimal dec_1 = {{0x7024cfd6, 0x5b5a213b, 0x67020, 0x80000000}};
  // -28668494598563197802016
  s21_decimal dec_2 = {{0xf442d620, 0x1f48e932, 0x612, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_96) {
  // 19252315249538078407639659
  s21_decimal dec_1 = {{0x79f7c26b, 0x19d79d08, 0xfecd6, 0x0}};
  // 147940010245511
  s21_decimal dec_2 = {{0xf7c23d87, 0x868c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_97) {
  // -8215574093797
  s21_decimal dec_1 = {{0xd6601fe5, 0x778, 0x0, 0x80000000}};
  // -90560981945779599720.5851
  s21_decimal dec_2 = {{0x4f5a855b, 0x34e93e67, 0xbfc5, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_98) {
  // -14750243758238186913280296.962
  s21_decimal dec_1 = {{0xa6300802, 0x5e5e8402, 0x2fa91d9c, 0x80030000}};
  // -63706070671329478
  s21_decimal dec_2 = {{0x706688c6, 0xe25455, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_99) {
  // -69015727092831114104.2
  s21_decimal dec_1 = {{0xa30342b2, 0x69db2d4c, 0x25, 0x80010000}};
  // 97570316946.0050
  s21_decimal dec_2 = {{0x98d26752, 0x37765, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_100) {
  // -8136480528182088960102332289
  s21_decimal dec_1 = {{0x3aab7781, 0x40866ea1, 0x1a4a56c5, 0x80000000}};
  // -40877693.30227088703
  s21_decimal dec_2 = {{0x43ec0d3f, 0x38baac8c, 0x0, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_101) {
  // -2352073852096225347
  s21_decimal dec_1 = {{0xe7ae2043, 0x20a43eb4, 0x0, 0x80000000}};
  // 96170337391981282329438437
  s21_decimal dec_2 = {{0xd4bd28e5, 0x6fbb59e7, 0x4f8cdc, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_102) {
  // -3542798880866047861555961363
  s21_decimal dec_1 = {{0xff079e13, 0x2a6bea1d, 0xb7288d8, 0x80000000}};
  // -963.22526144729
  s21_decimal dec_2 = {{0xd5f468d9, 0x579a, 0x0, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_103) {
  // -661279580191046220170108840
  s21_decimal dec_1 = {{0xfcdb9fa8, 0xdf882ec3, 0x222ff65, 0x80000000}};
  // 283547
  s21_decimal dec_2 = {{0x4539b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_104) {
  // -6983
  s21_decimal dec_1 = {{0x1b47, 0x0, 0x0, 0x80000000}};
  // 3456094104912275306057458033
  s21_decimal dec_2 = {{0xf24a6171, 0xd7cf9d2f, 0xb2ad064, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_105) {
  // 87907
  s21_decimal dec_1 = {{0x15763, 0x0, 0x0, 0x0}};
  // 89935895384368753058747407
  s21_decimal dec_2 = {{0x76cf940f, 0xa87337bb, 0x4a64aa, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_106) {
  // 282353258035896945653711249
  s21_decimal dec_1 = {{0xfd9e0191, 0xc9de04be, 0xe98ea0, 0x0}};
  // -39254630240239826946
  s21_decimal dec_2 = {{0x3acd3802, 0x20c47639, 0x2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_107) {
  // 437214106368567
  s21_decimal dec_1 = {{0xd7803a37, 0x18da4, 0x0, 0x0}};
  // -107023232742721312553899
  s21_decimal dec_2 = {{0xb2c07bab, 0xbdb6ea1d, 0x16a9, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_108) {
  // -59792615214163235163010934
  s21_decimal dec_1 = {{0xdf12f776, 0x2a6a9cd7, 0x317594, 0x80000000}};
  // 278886
  s21_decimal dec_2 = {{0x44166, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_109) {
  // -631940098321
  s21_decimal dec_1 = {{0x2290a911, 0x93, 0x0, 0x80000000}};
  // -3006204772891034894247
  s21_decimal dec_2 = {{0x8dfbbfa7, 0xf778d163, 0xa2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_110) {
  // 3899064821376030161071839980
  s21_decimal dec_1 = {{0x6391aec, 0x7ff87443, 0xc993b17, 0x0}};
  // 9142766.814
  s21_decimal dec_2 = {{0x20f38cde, 0x2, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_111) {
  // 370700961
  s21_decimal dec_1 = {{0x161872a1, 0x0, 0x0, 0x0}};
  // 691095991126287399799046
  s21_decimal dec_2 = {{0x78004906, 0x638509de, 0x9258, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_112) {
  // 9969093285039877728630970119
  s21_decimal dec_1 = {{0x4f39707, 0xde176513, 0x20363d9d, 0x0}};
  // -42427752211700519574972478
  s21_decimal dec_2 = {{0xb0a8283e, 0xe5b4442, 0x23186d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_113) {
  // -72013401349784971874636719
  s21_decimal dec_1 = {{0xee1f93af, 0x4f4054de, 0x3b916e, 0x80000000}};
  // -81116029.0
  s21_decimal dec_2 = {{0x305952e2, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_114) {
  // 30185684598410270743026846
  s21_decimal dec_1 = {{0x80655c9e, 0x3db0bad2, 0x18f811, 0x0}};
  // -2237852814161138905477973
  s21_decimal dec_2 = {{0x77537355, 0x3e800331, 0x1d9e2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_115) {
  // 405051881481815095601063906
  s21_decimal dec_1 = {{0xf2bce7e2, 0x7e5c52e4, 0x14f0d12, 0x0}};
  // 1704900208536172.164542318
  s21_decimal dec_2 = {{0x853fef6e, 0xd353db35, 0x16906, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_116) {
  // -146885.75
  s21_decimal dec_1 = {{0xe0213f, 0x0, 0x0, 0x80020000}};
  // 72277848797842180217100014
  s21_decimal dec_2 = {{0x109d6ee, 0x8d25e46, 0x3bc96e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_117) {
  // -7817195750215190909.23
  s21_decimal dec_1 = {{0x16f7b4eb, 0x6089d3c1, 0x2a, 0x80020000}};
  // 634910289735264938291227
  s21_decimal dec_2 = {{0x9744f01b, 0x8e472756, 0x8672, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_118) {
  // 836955882815608515296
  s21_decimal dec_1 = {{0xd9ceeae0, 0x5f189d09, 0x2d, 0x0}};
  // 67930754837926956.738727
  s21_decimal dec_2 = {{0xc067a8a7, 0x8899ec87, 0xe62, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_119) {
  // -48410352850042420326507
  s21_decimal dec_1 = {{0x5199f06b, 0x549ac412, 0xa40, 0x80000000}};
  // -1081589189378.42597776574
  s21_decimal dec_2 = {{0x99ec4cbe, 0x4e86cb74, 0x16e7, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_120) {
  // 62957034
  s21_decimal dec_1 = {{0x3c0a5ea, 0x0, 0x0, 0x0}};
  // -20804992036474397308464603
  s21_decimal dec_2 = {{0xccf7addb, 0xe0d3516d, 0x1135a0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_121) {
  // -11696179526754016
  s21_decimal dec_1 = {{0x1ebdee0, 0x298d9d, 0x0, 0x80000000}};
  // 40330373963309281786
  s21_decimal dec_2 = {{0xadb671fa, 0x2fb24570, 0x2, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_122) {
  // -969470.1087401759034
  s21_decimal dec_1 = {{0x362cd13a, 0x868a7f46, 0x0, 0x800d0000}};
  // 49437057702712478731806531
  s21_decimal dec_2 = {{0xd76f2743, 0x44a41387, 0x28e4b4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_123) {
  // 2312961203629155578221
  s21_decimal dec_1 = {{0x67c2716d, 0x62c8e81b, 0x7d, 0x0}};
  // -6905755547682.737
  s21_decimal dec_2 = {{0x825347b1, 0x1888bf, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_124) {
  // -71631184793667614050972182
  s21_decimal dec_1 = {{0x207d7216, 0x4efd263d, 0x3b407e, 0x80000000}};
  // -98761266452
  s21_decimal dec_2 = {{0xfea15514, 0x16, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_125) {
  // -25272527.303153963431052457239
  s21_decimal dec_1 = {{0xe3043517, 0x505e3852, 0x51a8f1d2, 0x80150000}};
  // 19295331512936873869554998
  s21_decimal dec_2 = {{0x6addb536, 0x46b004e, 0xff5f2, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_126) {
  // 78385049285199609743120590793
  s21_decimal dec_1 = {{0xc05ce7c9, 0x451414cf, 0xfd4697d4, 0x0}};
  // -42649.037
  s21_decimal dec_2 = {{0x28ac5cd, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_127) {
  // 2845804143225474403768641530
  s21_decimal dec_1 = {{0x7aeea7fa, 0xba484866, 0x931fe77, 0x0}};
  // 154045245551.8372423327262
  s21_decimal dec_2 = {{0xa004de1e, 0x184e430e, 0x14634, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_128) {
  // 395393443593727434703484
  s21_decimal dec_1 = {{0x8dba427c, 0x524f903f, 0x53ba, 0x0}};
  // 2177700461456.69
  s21_decimal dec_2 = {{0x8a3e4485, 0xc60f, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_129) {
  // -8241670768334055004258
  s21_decimal dec_1 = {{0x8011d862, 0xc828798e, 0x1be, 0x80000000}};
  // -36875799458330669
  s21_decimal dec_2 = {{0x1f85b82d, 0x830258, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_130) {
  // -671710617726092149490860497
  s21_decimal dec_1 = {{0x635e41d1, 0x8d0f0595, 0x22ba041, 0x80000000}};
  // 319410.8758347962132091984465
  s21_decimal dec_2 = {{0x76395a51, 0xbf6f49ed, 0xa521ad6, 0x160000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_131) {
  // 7423239857
  s21_decimal dec_1 = {{0xba75a6b1, 0x1, 0x0, 0x0}};
  // 4787811837529848222697
  s21_decimal dec_2 = {{0xb0db13e9, 0x8c3c9b51, 0x103, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_132) {
  // 136406046185954592727.55
  s21_decimal dec_1 = {{0x87121033, 0x756a9d97, 0x2e3, 0x20000}};
  // 798958547155979580331391
  s21_decimal dec_2 = {{0x4695d57f, 0xa12f468f, 0xa92f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_133) {
  // -2396185733995627.8468605
  s21_decimal dec_1 = {{0x387e1ffd, 0xf9925754, 0x512, 0x80070000}};
  // -5438791277583587618295
  s21_decimal dec_2 = {{0xd6b02df7, 0xd6642b02, 0x126, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_134) {
  // 153339894872753431286492
  s21_decimal dec_1 = {{0xe27e92dc, 0x9286052f, 0x2078, 0x0}};
  // 33926716150572422
  s21_decimal dec_2 = {{0x288ce586, 0x78882b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_135) {
  // -588575981
  s21_decimal dec_1 = {{0x2314f4ed, 0x0, 0x0, 0x80000000}};
  // 11046891827894985123421685
  s21_decimal dec_2 = {{0xc867ddf5, 0x34b93125, 0x92345, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_136) {
  // 1644378151730900366940
  s21_decimal dec_1 = {{0xddb3f65c, 0x2454c0b5, 0x59, 0x0}};
  // -857846643785599098664.51417
  s21_decimal dec_2 = {{0xe42b31d9, 0xf9690515, 0x46f59b, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_137) {
  // 87589297411101677521
  s21_decimal dec_1 = {{0x6ac1d7d1, 0xbf8bb1ed, 0x4, 0x0}};
  // -65605524843.909684947666
  s21_decimal dec_2 = {{0x6d406ad2, 0x7b8d8491, 0xde4, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_138) {
  // 916365574764266885630047296
  s21_decimal dec_1 = {{0xb7eab440, 0x58f6e4e2, 0x2f5fff5, 0x0}};
  // 8878505
  s21_decimal dec_2 = {{0x8779a9, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_139) {
  // -84620533861571018
  s21_decimal dec_1 = {{0x5d85d9ca, 0x12ca1ed, 0x0, 0x80000000}};
  // -1273789997890
  s21_decimal dec_2 = {{0x93cce342, 0x128, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_140) {
  // 72139955723929
  s21_decimal dec_1 = {{0x646f5e99, 0x419c, 0x0, 0x0}};
  // 33874336152606739
  s21_decimal dec_2 = {{0x7d60d813, 0x785887, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_141) {
  // 6597091176732795565
  s21_decimal dec_1 = {{0xec05a2ad, 0x5b8d9378, 0x0, 0x0}};
  // -741745393226194494397735.8
  s21_decimal dec_2 = {{0xef94238e, 0xfbbf0502, 0x622b4, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_142) {
  // -1401289021272615874807622619
  s21_decimal dec_1 = {{0xc0de6bdb, 0xea43044, 0x4871e7e, 0x80000000}};
  // -94641686547074.654649723588913
  s21_decimal dec_2 = {{0xb2071131, 0x19fd7978, 0x31cdc4ac, 0x800f0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_143) {
  // -91817056
  s21_decimal dec_1 = {{0x5790460, 0x0, 0x0, 0x80000000}};
  // -87592829703237425036952
  s21_decimal dec_2 = {{0x8f55fe98, 0x6ab44064, 0x128c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_144) {
  // 85580494948732350
  s21_decimal dec_1 = {{0xb91f0dbe, 0x1300b01, 0x0, 0x0}};
  // -9921893855061010933965235318
  s21_decimal dec_2 = {{0xa85a476, 0xa431e369, 0x200f32bf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_145) {
  // 620749255372022869094.303325
  s21_decimal dec_1 = {{0x136c065d, 0x8fe96936, 0x20178c4, 0x60000}};
  // 679808676355
  s21_decimal dec_2 = {{0x47c13203, 0x9e, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_146) {
  // 6638396641674125776.88
  s21_decimal dec_1 = {{0x113c3598, 0xfca04163, 0x23, 0x20000}};
  // -6221616353929475922092.97850
  s21_decimal dec_2 = {{0x36a6f1ba, 0xd6256a2f, 0x202a3d9, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_147) {
  // 33640922659298173710360635958
  s21_decimal dec_1 = {{0x213ea36, 0x94d65871, 0x6cb31e77, 0x0}};
  // -616651213865030465314176
  s21_decimal dec_2 = {{0xf0f5d80, 0xbab28c17, 0x8294, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_148) {
  // 324344322259383622617.01885
  s21_decimal dec_1 = {{0x53be04fd, 0x18193810, 0x1ad442, 0x50000}};
  // -889729285922047628
  s21_decimal dec_2 = {{0x51a5468c, 0xc58f412, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_149) {
  // -763694784184892
  s21_decimal dec_1 = {{0x8c54023c, 0x2b693, 0x0, 0x80000000}};
  // 86953067632136058
  s21_decimal dec_2 = {{0xb4580f7a, 0x134eb5a, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_150) {
  // 25711902786021070581421
  s21_decimal dec_1 = {{0x275aead, 0xd854bc63, 0x571, 0x0}};
  // -74681341803660361977722000311
  s21_decimal dec_2 = {{0x441753b7, 0x620fd78c, 0xf14ef543, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_151) {
  // -9192281005989146541418216
  s21_decimal dec_1 = {{0x35dfe6e8, 0x8d455b0d, 0x79a8a, 0x80000000}};
  // -2646222727913355550826
  s21_decimal dec_2 = {{0x90b7206a, 0x73b7aebf, 0x8f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_152) {
  // 830553645313358328403832392
  s21_decimal dec_1 = {{0xf07fae48, 0x54aa633f, 0x2af0493, 0x0}};
  // 252958.0661270588778
  s21_decimal dec_2 = {{0x89bb2d6a, 0x231ae035, 0x0, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_153) {
  // -8780280263824
  s21_decimal dec_1 = {{0x517c7490, 0x7fc, 0x0, 0x80000000}};
  // 584100071493397919440894546
  s21_decimal dec_2 = {{0xd46cfa52, 0x52b6f200, 0x1e32800, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_154) {
  // -605242590904103906190093
  s21_decimal dec_1 = {{0x364e230d, 0x443fb29a, 0x802a, 0x80000000}};
  // -9154966.91
  s21_decimal dec_2 = {{0x36915ef3, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_155) {
  // -39674973970525210847925633
  s21_decimal dec_1 = {{0x657ad581, 0xa60b2384, 0x20d180, 0x80000000}};
  // 7955254231.2522
  s21_decimal dec_2 = {{0x4506884a, 0x485a, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_156) {
  // 10942612634.79419308207
  s21_decimal dec_1 = {{0x68ea08af, 0x51ecf57d, 0x3b, 0xb0000}};
  // -750571730867348391485751796
  s21_decimal dec_2 = {{0xd30bc1f4, 0xf856594, 0x26cdbbf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_157) {
  // -1474867071389729062178093
  s21_decimal dec_1 = {{0x4e48cd2d, 0xb442f050, 0x13850, 0x80000000}};
  // 844214388147967
  s21_decimal dec_2 = {{0xfab846ff, 0x2ffce, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_158) {
  // 7900743231563995288441560
  s21_decimal dec_1 = {{0xf6ac12d8, 0x261777c6, 0x6890c, 0x0}};
  // -74084388438407471974345981.266
  s21_decimal dec_2 = {{0xc269bd52, 0x9bebe873, 0xef612b78, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_160) {
  // -28053521075391988267112363545
  s21_decimal dec_1 = {{0x5c467619, 0xca574170, 0x5aa55428, 0x80000000}};
  // 2.91963
  s21_decimal dec_2 = {{0x4747b, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_161) {
  // -61033831
  s21_decimal dec_1 = {{0x3a34d67, 0x0, 0x0, 0x80000000}};
  // -3575058551619997485379244
  s21_decimal dec_2 = {{0xea262eac, 0x4ffada62, 0x2f50c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_162) {
  // 19676498283936945.4
  s21_decimal dec_1 = {{0x9a605eee, 0x2bb0cb5, 0x0, 0x10000}};
  // -880664642919058631
  s21_decimal dec_2 = {{0xa76fccc7, 0xc38bfd3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_163) {
  // 75854265359481528758656502
  s21_decimal dec_1 = {{0xd43d5df6, 0xf6f9fe36, 0x3ebec3, 0x0}};
  // -698955506314.7198633
  s21_decimal dec_2 = {{0x34ebf8a9, 0x60ffe34c, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_164) {
  // 954092963691036417
  s21_decimal dec_1 = {{0xd780ff01, 0xd3d9e7e, 0x0, 0x0}};
  // 6564105895075198.6
  s21_decimal dec_2 = {{0x170a6f2, 0xe93432, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_165) {
  // 61849516825790228472.61574
  s21_decimal dec_1 = {{0xd96dbb86, 0xe70d6b2d, 0x51db6, 0x50000}};
  // 8953318019633.6908125
  s21_decimal dec_2 = {{0x7db3375d, 0xda85c105, 0x4, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 1; // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_166) {
  // 9355880484087803
  s21_decimal dec_1 = {{0xacd0a7fb, 0x213d1f, 0x0, 0x0}};
  // -53185890036655589112938229
  s21_decimal dec_2 = {{0x9063fef5, 0xe04c67d4, 0x2bfe8c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_mul_cases(void) {
  Suite *c = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("s21_mul_tc");

  tcase_add_test(tc, invalid_dec_s21_mul_1);
  tcase_add_test(tc, invalid_dec_s21_mul_2);
  tcase_add_test(tc, invalid_dec_s21_mul_3);
  tcase_add_test(tc, invalid_dec_s21_mul_4);
  tcase_add_test(tc, invalid_dec_s21_mul_5);
  tcase_add_test(tc, invalid_dec_s21_mul_6);
  tcase_add_test(tc, invalid_dec_s21_mul_7);
  tcase_add_test(tc, invalid_dec_s21_mul_8);
  tcase_add_test(tc, invalid_dec_s21_mul_9);
  tcase_add_test(tc, invalid_dec_s21_mul_10);
  tcase_add_test(tc, invalid_dec_s21_mul_11);
  tcase_add_test(tc, invalid_dec_s21_mul_12);
  tcase_add_test(tc, invalid_dec_s21_mul_13);
  tcase_add_test(tc, invalid_dec_s21_mul_14);
  tcase_add_test(tc, invalid_dec_s21_mul_15);
  tcase_add_test(tc, invalid_dec_s21_mul_16);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_29);
  tcase_add_test(tc, s21_mul_30);
  tcase_add_test(tc, s21_mul_31);
  tcase_add_test(tc, s21_mul_32);
  tcase_add_test(tc, s21_mul_33);
  tcase_add_test(tc, s21_mul_34);
  tcase_add_test(tc, s21_mul_35);
  tcase_add_test(tc, s21_mul_36);
  tcase_add_test(tc, s21_mul_37);
  tcase_add_test(tc, s21_mul_38);
  tcase_add_test(tc, s21_mul_39);
  tcase_add_test(tc, s21_mul_40);
  tcase_add_test(tc, s21_mul_41);
  tcase_add_test(tc, s21_mul_42);
  tcase_add_test(tc, s21_mul_43);
  tcase_add_test(tc, s21_mul_44);
  tcase_add_test(tc, s21_mul_45);
  tcase_add_test(tc, s21_mul_46);
  tcase_add_test(tc, s21_mul_47);
  tcase_add_test(tc, s21_mul_48);
  tcase_add_test(tc, s21_mul_49);
  tcase_add_test(tc, s21_mul_50);
  tcase_add_test(tc, s21_mul_51);
  tcase_add_test(tc, s21_mul_52);
  tcase_add_test(tc, s21_mul_53);
  tcase_add_test(tc, s21_mul_54);
  tcase_add_test(tc, s21_mul_55);
  tcase_add_test(tc, s21_mul_56);
  tcase_add_test(tc, s21_mul_57);
  tcase_add_test(tc, s21_mul_58);
  tcase_add_test(tc, s21_mul_59);
  tcase_add_test(tc, s21_mul_60);
  tcase_add_test(tc, s21_mul_61);
  tcase_add_test(tc, s21_mul_62);
  tcase_add_test(tc, s21_mul_63);
  tcase_add_test(tc, s21_mul_64);
  tcase_add_test(tc, s21_mul_65);
  tcase_add_test(tc, s21_mul_66);
  tcase_add_test(tc, s21_mul_67);
  tcase_add_test(tc, s21_mul_68);
  tcase_add_test(tc, s21_mul_69);
  tcase_add_test(tc, s21_mul_70);
  tcase_add_test(tc, s21_mul_71);
  tcase_add_test(tc, s21_mul_72);
  tcase_add_test(tc, s21_mul_73);
  tcase_add_test(tc, s21_mul_74);
  tcase_add_test(tc, s21_mul_75);
  tcase_add_test(tc, s21_mul_76);
  tcase_add_test(tc, s21_mul_77);
  tcase_add_test(tc, s21_mul_78);
  tcase_add_test(tc, s21_mul_80);
  tcase_add_test(tc, s21_mul_81);
  tcase_add_test(tc, s21_mul_82);
  tcase_add_test(tc, s21_mul_83);
  tcase_add_test(tc, s21_mul_84);
  tcase_add_test(tc, s21_mul_85);
  tcase_add_test(tc, s21_mul_86);
  tcase_add_test(tc, s21_mul_87);
  tcase_add_test(tc, s21_mul_88);
  tcase_add_test(tc, s21_mul_89);
  tcase_add_test(tc, s21_mul_90);
  tcase_add_test(tc, s21_mul_91);
  tcase_add_test(tc, s21_mul_92);
  tcase_add_test(tc, s21_mul_93);
  tcase_add_test(tc, s21_mul_94);
  tcase_add_test(tc, s21_mul_95);
  tcase_add_test(tc, s21_mul_96);
  tcase_add_test(tc, s21_mul_97);
  tcase_add_test(tc, s21_mul_98);
  tcase_add_test(tc, s21_mul_99);
  tcase_add_test(tc, s21_mul_100);
  tcase_add_test(tc, s21_mul_101);
  tcase_add_test(tc, s21_mul_102);
  tcase_add_test(tc, s21_mul_103);
  tcase_add_test(tc, s21_mul_104);
  tcase_add_test(tc, s21_mul_105);
  tcase_add_test(tc, s21_mul_106);
  tcase_add_test(tc, s21_mul_107);
  tcase_add_test(tc, s21_mul_108);
  tcase_add_test(tc, s21_mul_109);
  tcase_add_test(tc, s21_mul_110);
  tcase_add_test(tc, s21_mul_111);
  tcase_add_test(tc, s21_mul_112);
  tcase_add_test(tc, s21_mul_113);
  tcase_add_test(tc, s21_mul_114);
  tcase_add_test(tc, s21_mul_115);
  tcase_add_test(tc, s21_mul_116);
  tcase_add_test(tc, s21_mul_117);
  tcase_add_test(tc, s21_mul_118);
  tcase_add_test(tc, s21_mul_119);
  tcase_add_test(tc, s21_mul_120);
  tcase_add_test(tc, s21_mul_121);
  tcase_add_test(tc, s21_mul_122);
  tcase_add_test(tc, s21_mul_123);
  tcase_add_test(tc, s21_mul_124);
  tcase_add_test(tc, s21_mul_125);
  tcase_add_test(tc, s21_mul_126);
  tcase_add_test(tc, s21_mul_127);
  tcase_add_test(tc, s21_mul_129);
  tcase_add_test(tc, s21_mul_130);
  tcase_add_test(tc, s21_mul_131);
  tcase_add_test(tc, s21_mul_132);
  tcase_add_test(tc, s21_mul_133);
  tcase_add_test(tc, s21_mul_134);
  tcase_add_test(tc, s21_mul_135);
  tcase_add_test(tc, s21_mul_136);
  tcase_add_test(tc, s21_mul_137);
  tcase_add_test(tc, s21_mul_138);
  tcase_add_test(tc, s21_mul_139);
  tcase_add_test(tc, s21_mul_140);
  tcase_add_test(tc, s21_mul_141);
  tcase_add_test(tc, s21_mul_142);
  tcase_add_test(tc, s21_mul_143);
  tcase_add_test(tc, s21_mul_144);
  tcase_add_test(tc, s21_mul_145);
  tcase_add_test(tc, s21_mul_146);
  tcase_add_test(tc, s21_mul_147);
  tcase_add_test(tc, s21_mul_148);
  tcase_add_test(tc, s21_mul_149);
  tcase_add_test(tc, s21_mul_150);
  tcase_add_test(tc, s21_mul_151);
  tcase_add_test(tc, s21_mul_152);
  tcase_add_test(tc, s21_mul_153);
  tcase_add_test(tc, s21_mul_154);
  tcase_add_test(tc, s21_mul_155);
  tcase_add_test(tc, s21_mul_156);
  tcase_add_test(tc, s21_mul_157);
  tcase_add_test(tc, s21_mul_158);
  tcase_add_test(tc, s21_mul_159);
  tcase_add_test(tc, s21_mul_161);
  tcase_add_test(tc, s21_mul_162);
  tcase_add_test(tc, s21_mul_163);
  tcase_add_test(tc, s21_mul_165);
  tcase_add_test(tc, s21_mul_166);
  tcase_add_test(tc, s21_mul_167);
  tcase_add_test(tc, s21_mul_168);
  tcase_add_test(tc, s21_mul_169);
  tcase_add_test(tc, s21_mul_170);
  tcase_add_test(tc, s21_mul_171);
  tcase_add_test(tc, s21_mul_172);
  tcase_add_test(tc, s21_mul_173);
  tcase_add_test(tc, s21_mul_174);
  tcase_add_test(tc, s21_mul_175);
  tcase_add_test(tc, s21_mul_176);
  tcase_add_test(tc, s21_mul_177);
  tcase_add_test(tc, s21_mul_178);
  tcase_add_test(tc, s21_mul_179);
  tcase_add_test(tc, s21_mul_180);
  tcase_add_test(tc, s21_mul_181);
  tcase_add_test(tc, s21_mul_182);
  tcase_add_test(tc, s21_mul_183);
  tcase_add_test(tc, s21_mul_184);
  tcase_add_test(tc, s21_mul_185);
  tcase_add_test(tc, s21_mul_186);
  tcase_add_test(tc, s21_mul_187);
  tcase_add_test(tc, s21_mul_188);
  tcase_add_test(tc, s21_mul_189);
  tcase_add_test(tc, s21_mul_190);
  tcase_add_test(tc, s21_mul_191);
  tcase_add_test(tc, s21_mul_192);
  tcase_add_test(tc, s21_mul_193);
  tcase_add_test(tc, s21_mul_194);
  tcase_add_test(tc, s21_mul_195);
  tcase_add_test(tc, s21_mul_196);
  tcase_add_test(tc, s21_mul_197);
  tcase_add_test(tc, s21_mul_198);
  tcase_add_test(tc, s21_mul_199);
  tcase_add_test(tc, s21_mul_200);
  tcase_add_test(tc, s21_mul_201);
  tcase_add_test(tc, s21_mul_202);
  tcase_add_test(tc, s21_mul_203);
  tcase_add_test(tc, s21_mul_204);
  tcase_add_test(tc, s21_mul_205);
  tcase_add_test(tc, s21_mul_206);
  tcase_add_test(tc, s21_mul_207);
  tcase_add_test(tc, s21_mul_208);
  tcase_add_test(tc, s21_mul_209);
  tcase_add_test(tc, s21_mul_210);
  tcase_add_test(tc, s21_mul_211);
  tcase_add_test(tc, s21_mul_212);
  tcase_add_test(tc, s21_mul_213);
  tcase_add_test(tc, s21_mul_214);
  tcase_add_test(tc, s21_mul_215);
  tcase_add_test(tc, s21_mul_216);
  tcase_add_test(tc, s21_mul_217);
  tcase_add_test(tc, s21_mul_218);
  tcase_add_test(tc, s21_mul_219);
  tcase_add_test(tc, s21_mul_220);
  tcase_add_test(tc, s21_mul_221);
  tcase_add_test(tc, s21_mul_222);
  tcase_add_test(tc, s21_mul_223);
  tcase_add_test(tc, s21_mul_224);
  tcase_add_test(tc, s21_mul_225);
  tcase_add_test(tc, s21_mul_226);
  tcase_add_test(tc, s21_mul_227);
  tcase_add_test(tc, s21_mul_228);
  tcase_add_test(tc, s21_mul_229);
  tcase_add_test(tc, s21_mul_230);
  tcase_add_test(tc, s21_mul_231);
  tcase_add_test(tc, s21_mul_232);
  tcase_add_test(tc, s21_mul_233);
  tcase_add_test(tc, s21_mul_234);
  tcase_add_test(tc, s21_mul_235);
  tcase_add_test(tc, s21_mul_236);
  tcase_add_test(tc, s21_mul_237);
  tcase_add_test(tc, s21_mul_238);
  tcase_add_test(tc, s21_mul_239);
  tcase_add_test(tc, s21_mul_240);
  tcase_add_test(tc, s21_mul_241);
  tcase_add_test(tc, s21_mul_242);
  tcase_add_test(tc, s21_mul_243);
  tcase_add_test(tc, s21_mul_244);
  tcase_add_test(tc, s21_mul_245);
  tcase_add_test(tc, s21_mul_246);
  tcase_add_test(tc, s21_mul_247);
  tcase_add_test(tc, s21_mul_248);
  tcase_add_test(tc, s21_mul_249);
  tcase_add_test(tc, s21_mul_250);
  tcase_add_test(tc, s21_mul_251);
  tcase_add_test(tc, s21_mul_252);
  tcase_add_test(tc, s21_mul_253);
  tcase_add_test(tc, s21_mul_254);
  tcase_add_test(tc, s21_mul_255);
  tcase_add_test(tc, s21_mul_256);
  tcase_add_test(tc, s21_mul_257);
  tcase_add_test(tc, s21_mul_259);
  tcase_add_test(tc, s21_mul_260);
  tcase_add_test(tc, s21_mul_261);
  tcase_add_test(tc, s21_mul_262);
  tcase_add_test(tc, s21_mul_263);
  tcase_add_test(tc, s21_mul_264);
  tcase_add_test(tc, s21_mul_265);
  tcase_add_test(tc, s21_mul_266);
  tcase_add_test(tc, s21_mul_267);
  tcase_add_test(tc, s21_mul_268);
  tcase_add_test(tc, s21_mul_269);
  tcase_add_test(tc, s21_mul_270);
  tcase_add_test(tc, s21_mul_271);
  tcase_add_test(tc, s21_mul_272);
  tcase_add_test(tc, s21_mul_273);
  tcase_add_test(tc, s21_mul_274);
  tcase_add_test(tc, s21_mul_275);
  tcase_add_test(tc, s21_mul_276);
  tcase_add_test(tc, s21_mul_277);
  tcase_add_test(tc, s21_mul_278);
  tcase_add_test(tc, s21_mul_279);
  tcase_add_test(tc, s21_mul_280);
  tcase_add_test(tc, s21_mul_281);
  tcase_add_test(tc, s21_mul_282);
  tcase_add_test(tc, s21_mul_283);
  tcase_add_test(tc, s21_mul_284);
  tcase_add_test(tc, s21_mul_287);
  tcase_add_test(tc, s21_mul_288);
  tcase_add_test(tc, s21_mul_289);
  tcase_add_test(tc, s21_mul_291);
  tcase_add_test(tc, s21_mul_292);
  tcase_add_test(tc, s21_mul_293);
  tcase_add_test(tc, s21_mul_294);
  tcase_add_test(tc, s21_mul_295);
  tcase_add_test(tc, s21_mul_296);
  tcase_add_test(tc, s21_mul_297);
  tcase_add_test(tc, s21_mul_298);
  tcase_add_test(tc, s21_mul_299);
  tcase_add_test(tc, s21_mul_300);
  tcase_add_test(tc, s21_mul_301);
  tcase_add_test(tc, s21_mul_302);
  tcase_add_test(tc, s21_mul_303);
  tcase_add_test(tc, s21_mul_304);
  tcase_add_test(tc, s21_mul_305);
  tcase_add_test(tc, s21_mul_306);
  tcase_add_test(tc, s21_mul_307);
  tcase_add_test(tc, s21_mul_308);
  tcase_add_test(tc, s21_mul_309);
  tcase_add_test(tc, s21_mul_310);
  tcase_add_test(tc, s21_mul_311);
  tcase_add_test(tc, s21_mul_312);
  tcase_add_test(tc, s21_mul_313);
  tcase_add_test(tc, s21_mul_314);
  tcase_add_test(tc, s21_mul_315);
  tcase_add_test(tc, s21_mul_316);
  tcase_add_test(tc, s21_mul_317);
  tcase_add_test(tc, s21_mul_318);
  tcase_add_test(tc, s21_mul_319);
  tcase_add_test(tc, s21_mul_320);
  tcase_add_test(tc, s21_mul_321);
  tcase_add_test(tc, s21_mul_322);
  tcase_add_test(tc, s21_mul_323);
  tcase_add_test(tc, s21_mul_324);
  tcase_add_test(tc, s21_mul_325);
  tcase_add_test(tc, s21_mul_326);
  tcase_add_test(tc, s21_mul_327);
  tcase_add_test(tc, s21_mul_328);
  tcase_add_test(tc, s21_mul_329);
  tcase_add_test(tc, s21_mul_330);
  tcase_add_test(tc, s21_mul_331);
  tcase_add_test(tc, s21_mul_332);
  tcase_add_test(tc, s21_mul_333);
  tcase_add_test(tc, s21_mul_334);
  tcase_add_test(tc, s21_mul_335);
  tcase_add_test(tc, s21_mul_336);
  tcase_add_test(tc, s21_mul_337);
  tcase_add_test(tc, s21_mul_338);
  tcase_add_test(tc, s21_mul_339);
  tcase_add_test(tc, s21_mul_340);
  tcase_add_test(tc, s21_mul_341);
  tcase_add_test(tc, s21_mul_342);
  tcase_add_test(tc, s21_mul_343);
  tcase_add_test(tc, s21_mul_344);
  tcase_add_test(tc, s21_mul_345);
  tcase_add_test(tc, s21_mul_346);
  tcase_add_test(tc, s21_mul_347);
  tcase_add_test(tc, s21_mul_348);
  tcase_add_test(tc, s21_mul_349);
  tcase_add_test(tc, s21_mul_350);
  tcase_add_test(tc, s21_mul_351);
  tcase_add_test(tc, s21_mul_352);
  tcase_add_test(tc, s21_mul_353);
  tcase_add_test(tc, s21_mul_354);
  tcase_add_test(tc, s21_mul_355);
  tcase_add_test(tc, s21_mul_356);
  tcase_add_test(tc, s21_mul_357);
  tcase_add_test(tc, s21_mul_358);
  tcase_add_test(tc, s21_mul_359);
  tcase_add_test(tc, s21_mul_360);
  tcase_add_test(tc, s21_mul_361);
  tcase_add_test(tc, s21_mul_362);
  tcase_add_test(tc, s21_mul_363);
  tcase_add_test(tc, s21_mul_364);
  tcase_add_test(tc, s21_mul_366);
  tcase_add_test(tc, s21_mul_367);
  tcase_add_test(tc, s21_mul_369);
  tcase_add_test(tc, s21_mul_370);
  tcase_add_test(tc, s21_mul_371);
  tcase_add_test(tc, s21_mul_372);
  tcase_add_test(tc, s21_mul_373);
  tcase_add_test(tc, s21_mul_374);
  tcase_add_test(tc, s21_mul_375);
  tcase_add_test(tc, s21_mul_376);
  tcase_add_test(tc, s21_mul_377);
  tcase_add_test(tc, s21_mul_378);
  tcase_add_test(tc, s21_mul_379);
  tcase_add_test(tc, s21_mul_380);
  tcase_add_test(tc, s21_mul_381);
  tcase_add_test(tc, s21_mul_382);
  tcase_add_test(tc, s21_mul_383);
  tcase_add_test(tc, s21_mul_385);
  tcase_add_test(tc, s21_mul_386);
  tcase_add_test(tc, s21_mul_387);
  tcase_add_test(tc, s21_mul_388);
  tcase_add_test(tc, s21_mul_389);
  tcase_add_test(tc, s21_mul_390);
  tcase_add_test(tc, s21_mul_391);
  tcase_add_test(tc, s21_mul_392);
  tcase_add_test(tc, s21_mul_393);
  tcase_add_test(tc, s21_mul_394);
  tcase_add_test(tc, s21_mul_395);
  tcase_add_test(tc, s21_mul_396);
  tcase_add_test(tc, s21_mul_397);
  tcase_add_test(tc, s21_mul_398);
  tcase_add_test(tc, s21_mul_399);
  tcase_add_test(tc, s21_mul_400);
  tcase_add_test(tc, s21_mul_401);
  tcase_add_test(tc, s21_mul_403);
  tcase_add_test(tc, s21_mul_404);
  tcase_add_test(tc, s21_mul_405);
  tcase_add_test(tc, s21_mul_406);
  tcase_add_test(tc, s21_mul_407);
  tcase_add_test(tc, s21_mul_408);
  tcase_add_test(tc, s21_mul_409);
  tcase_add_test(tc, s21_mul_410);
  tcase_add_test(tc, s21_mul_411);
  tcase_add_test(tc, s21_mul_412);
  tcase_add_test(tc, s21_mul_413);
  tcase_add_test(tc, s21_mul_414);
  tcase_add_test(tc, s21_mul_415);
  tcase_add_test(tc, s21_mul_416);
  tcase_add_test(tc, s21_mul_417);
  tcase_add_test(tc, s21_mul_418);
  tcase_add_test(tc, s21_mul_419);
  tcase_add_test(tc, s21_mul_420);
  tcase_add_test(tc, s21_mul_421);
  tcase_add_test(tc, s21_mul_422);
  tcase_add_test(tc, s21_mul_423);
  tcase_add_test(tc, s21_mul_424);
  tcase_add_test(tc, s21_mul_425);
  tcase_add_test(tc, s21_mul_426);
  tcase_add_test(tc, s21_mul_427);
  tcase_add_test(tc, s21_mul_428);
  tcase_add_test(tc, s21_mul_429);
  tcase_add_test(tc, s21_mul_430);
  tcase_add_test(tc, s21_mul_431);
  tcase_add_test(tc, s21_mul_432);
  tcase_add_test(tc, s21_mul_433);
  tcase_add_test(tc, s21_mul_434);
  tcase_add_test(tc, s21_mul_435);
  tcase_add_test(tc, s21_mul_436);
  tcase_add_test(tc, s21_mul_437);
  tcase_add_test(tc, s21_mul_438);
  tcase_add_test(tc, s21_mul_439);
  tcase_add_test(tc, s21_mul_440);
  tcase_add_test(tc, s21_mul_441);
  tcase_add_test(tc, s21_mul_442);
  tcase_add_test(tc, s21_mul_443);
  tcase_add_test(tc, s21_mul_444);
  tcase_add_test(tc, s21_mul_445);
  tcase_add_test(tc, s21_mul_446);
  tcase_add_test(tc, s21_mul_447);
  tcase_add_test(tc, s21_mul_448);
  tcase_add_test(tc, s21_mul_449);
  tcase_add_test(tc, s21_mul_450);
  tcase_add_test(tc, s21_mul_451);
  tcase_add_test(tc, s21_mul_452);
  tcase_add_test(tc, s21_mul_453);
  tcase_add_test(tc, s21_mul_454);
  tcase_add_test(tc, s21_mul_455);
  tcase_add_test(tc, s21_mul_456);
  tcase_add_test(tc, s21_mul_458);
  tcase_add_test(tc, s21_mul_459);
  tcase_add_test(tc, s21_mul_460);
  tcase_add_test(tc, s21_mul_461);
  tcase_add_test(tc, s21_mul_462);
  tcase_add_test(tc, s21_mul_463);
  tcase_add_test(tc, s21_mul_464);
  tcase_add_test(tc, s21_mul_465);
  tcase_add_test(tc, s21_mul_466);
  tcase_add_test(tc, s21_mul_467);
  tcase_add_test(tc, s21_mul_468);
  tcase_add_test(tc, s21_mul_469);
  tcase_add_test(tc, s21_mul_470);
  tcase_add_test(tc, s21_mul_471);
  tcase_add_test(tc, s21_mul_472);
  tcase_add_test(tc, s21_mul_473);
  tcase_add_test(tc, s21_mul_474);
  tcase_add_test(tc, s21_mul_476);
  tcase_add_test(tc, s21_mul_477);
  tcase_add_test(tc, s21_mul_478);
  tcase_add_test(tc, s21_mul_479);
  tcase_add_test(tc, s21_mul_480);
  tcase_add_test(tc, s21_mul_481);
  tcase_add_test(tc, s21_mul_482);
  tcase_add_test(tc, s21_mul_483);
  tcase_add_test(tc, s21_mul_484);
  tcase_add_test(tc, s21_mul_485);
  tcase_add_test(tc, s21_mul_486);
  tcase_add_test(tc, s21_mul_487);
  tcase_add_test(tc, s21_mul_488);
  tcase_add_test(tc, s21_mul_489);
  tcase_add_test(tc, s21_mul_490);
  tcase_add_test(tc, s21_mul_491);
  tcase_add_test(tc, s21_mul_492);
  tcase_add_test(tc, s21_mul_493);
  tcase_add_test(tc, s21_mul_494);
  tcase_add_test(tc, s21_mul_495);
  tcase_add_test(tc, s21_mul_496);
  tcase_add_test(tc, s21_mul_497);
  tcase_add_test(tc, s21_mul_498);
  tcase_add_test(tc, s21_mul_499);
  tcase_add_test(tc, s21_mul_500);
  tcase_add_test(tc, fail_s21_mul_1);
  tcase_add_test(tc, fail_s21_mul_2);
  tcase_add_test(tc, fail_s21_mul_3);
  tcase_add_test(tc, fail_s21_mul_4);
  tcase_add_test(tc, fail_s21_mul_5);
  tcase_add_test(tc, fail_s21_mul_6);
  tcase_add_test(tc, fail_s21_mul_7);
  tcase_add_test(tc, fail_s21_mul_8);
  tcase_add_test(tc, fail_s21_mul_9);
  tcase_add_test(tc, fail_s21_mul_10);
  tcase_add_test(tc, fail_s21_mul_11);
  tcase_add_test(tc, fail_s21_mul_12);
  tcase_add_test(tc, fail_s21_mul_13);
  tcase_add_test(tc, fail_s21_mul_14);
  tcase_add_test(tc, fail_s21_mul_15);
  tcase_add_test(tc, fail_s21_mul_16);
  tcase_add_test(tc, fail_s21_mul_17);
  tcase_add_test(tc, fail_s21_mul_18);
  tcase_add_test(tc, fail_s21_mul_19);
  tcase_add_test(tc, fail_s21_mul_20);
  tcase_add_test(tc, fail_s21_mul_21);
  tcase_add_test(tc, fail_s21_mul_22);
  tcase_add_test(tc, fail_s21_mul_23);
  tcase_add_test(tc, fail_s21_mul_24);
  tcase_add_test(tc, fail_s21_mul_25);
  tcase_add_test(tc, fail_s21_mul_26);
  tcase_add_test(tc, fail_s21_mul_27);
  tcase_add_test(tc, fail_s21_mul_28);
  tcase_add_test(tc, fail_s21_mul_29);
  tcase_add_test(tc, fail_s21_mul_30);
  tcase_add_test(tc, fail_s21_mul_31);
  tcase_add_test(tc, fail_s21_mul_32);
  tcase_add_test(tc, fail_s21_mul_33);
  tcase_add_test(tc, fail_s21_mul_34);
  tcase_add_test(tc, fail_s21_mul_35);
  tcase_add_test(tc, fail_s21_mul_36);
  tcase_add_test(tc, fail_s21_mul_37);
  tcase_add_test(tc, fail_s21_mul_38);
  tcase_add_test(tc, fail_s21_mul_39);
  tcase_add_test(tc, fail_s21_mul_40);
  tcase_add_test(tc, fail_s21_mul_41);
  tcase_add_test(tc, fail_s21_mul_42);
  tcase_add_test(tc, fail_s21_mul_43);
  tcase_add_test(tc, fail_s21_mul_44);
  tcase_add_test(tc, fail_s21_mul_45);
  tcase_add_test(tc, fail_s21_mul_46);
  tcase_add_test(tc, fail_s21_mul_47);
  tcase_add_test(tc, fail_s21_mul_48);
  tcase_add_test(tc, fail_s21_mul_49);
  tcase_add_test(tc, fail_s21_mul_50);
  tcase_add_test(tc, fail_s21_mul_51);
  tcase_add_test(tc, fail_s21_mul_52);
  tcase_add_test(tc, fail_s21_mul_53);
  tcase_add_test(tc, fail_s21_mul_54);
  tcase_add_test(tc, fail_s21_mul_55);
  tcase_add_test(tc, fail_s21_mul_56);
  tcase_add_test(tc, fail_s21_mul_57);
  tcase_add_test(tc, fail_s21_mul_58);
  tcase_add_test(tc, fail_s21_mul_59);
  tcase_add_test(tc, fail_s21_mul_60);
  tcase_add_test(tc, fail_s21_mul_61);
  tcase_add_test(tc, fail_s21_mul_62);
  tcase_add_test(tc, fail_s21_mul_63);
  tcase_add_test(tc, fail_s21_mul_64);
  tcase_add_test(tc, fail_s21_mul_65);
  tcase_add_test(tc, fail_s21_mul_66);
  tcase_add_test(tc, fail_s21_mul_67);
  tcase_add_test(tc, fail_s21_mul_68);
  tcase_add_test(tc, fail_s21_mul_69);
  tcase_add_test(tc, fail_s21_mul_70);
  tcase_add_test(tc, fail_s21_mul_71);
  tcase_add_test(tc, fail_s21_mul_72);
  tcase_add_test(tc, fail_s21_mul_73);
  tcase_add_test(tc, fail_s21_mul_74);
  tcase_add_test(tc, fail_s21_mul_75);
  tcase_add_test(tc, fail_s21_mul_76);
  tcase_add_test(tc, fail_s21_mul_77);
  tcase_add_test(tc, fail_s21_mul_78);
  tcase_add_test(tc, fail_s21_mul_79);
  tcase_add_test(tc, fail_s21_mul_80);
  tcase_add_test(tc, fail_s21_mul_81);
  tcase_add_test(tc, fail_s21_mul_82);
  tcase_add_test(tc, fail_s21_mul_83);
  tcase_add_test(tc, fail_s21_mul_84);
  tcase_add_test(tc, fail_s21_mul_85);
  tcase_add_test(tc, fail_s21_mul_86);
  tcase_add_test(tc, fail_s21_mul_87);
  tcase_add_test(tc, fail_s21_mul_88);
  tcase_add_test(tc, fail_s21_mul_89);
  tcase_add_test(tc, fail_s21_mul_90);
  tcase_add_test(tc, fail_s21_mul_91);
  tcase_add_test(tc, fail_s21_mul_92);
  tcase_add_test(tc, fail_s21_mul_93);
  tcase_add_test(tc, fail_s21_mul_94);
  tcase_add_test(tc, fail_s21_mul_95);
  tcase_add_test(tc, fail_s21_mul_96);
  tcase_add_test(tc, fail_s21_mul_97);
  tcase_add_test(tc, fail_s21_mul_98);
  tcase_add_test(tc, fail_s21_mul_99);
  tcase_add_test(tc, fail_s21_mul_100);
  tcase_add_test(tc, fail_s21_mul_101);
  tcase_add_test(tc, fail_s21_mul_102);
  tcase_add_test(tc, fail_s21_mul_103);
  tcase_add_test(tc, fail_s21_mul_104);
  tcase_add_test(tc, fail_s21_mul_105);
  tcase_add_test(tc, fail_s21_mul_106);
  tcase_add_test(tc, fail_s21_mul_107);
  tcase_add_test(tc, fail_s21_mul_108);
  tcase_add_test(tc, fail_s21_mul_109);
  tcase_add_test(tc, fail_s21_mul_110);
  tcase_add_test(tc, fail_s21_mul_111);
  tcase_add_test(tc, fail_s21_mul_112);
  tcase_add_test(tc, fail_s21_mul_113);
  tcase_add_test(tc, fail_s21_mul_114);
  tcase_add_test(tc, fail_s21_mul_115);
  tcase_add_test(tc, fail_s21_mul_116);
  tcase_add_test(tc, fail_s21_mul_117);
  tcase_add_test(tc, fail_s21_mul_118);
  tcase_add_test(tc, fail_s21_mul_119);
  tcase_add_test(tc, fail_s21_mul_120);
  tcase_add_test(tc, fail_s21_mul_121);
  tcase_add_test(tc, fail_s21_mul_122);
  tcase_add_test(tc, fail_s21_mul_123);
  tcase_add_test(tc, fail_s21_mul_124);
  tcase_add_test(tc, fail_s21_mul_125);
  tcase_add_test(tc, fail_s21_mul_126);
  tcase_add_test(tc, fail_s21_mul_127);
  tcase_add_test(tc, fail_s21_mul_128);
  tcase_add_test(tc, fail_s21_mul_129);
  tcase_add_test(tc, fail_s21_mul_130);
  tcase_add_test(tc, fail_s21_mul_131);
  tcase_add_test(tc, fail_s21_mul_132);
  tcase_add_test(tc, fail_s21_mul_133);
  tcase_add_test(tc, fail_s21_mul_134);
  tcase_add_test(tc, fail_s21_mul_135);
  tcase_add_test(tc, fail_s21_mul_136);
  tcase_add_test(tc, fail_s21_mul_137);
  tcase_add_test(tc, fail_s21_mul_138);
  tcase_add_test(tc, fail_s21_mul_139);
  tcase_add_test(tc, fail_s21_mul_140);
  tcase_add_test(tc, fail_s21_mul_141);
  tcase_add_test(tc, fail_s21_mul_142);
  tcase_add_test(tc, fail_s21_mul_143);
  tcase_add_test(tc, fail_s21_mul_144);
  tcase_add_test(tc, fail_s21_mul_145);
  tcase_add_test(tc, fail_s21_mul_146);
  tcase_add_test(tc, fail_s21_mul_147);
  tcase_add_test(tc, fail_s21_mul_148);
  tcase_add_test(tc, fail_s21_mul_149);
  tcase_add_test(tc, fail_s21_mul_150);
  tcase_add_test(tc, fail_s21_mul_151);
  tcase_add_test(tc, fail_s21_mul_152);
  tcase_add_test(tc, fail_s21_mul_153);
  tcase_add_test(tc, fail_s21_mul_154);
  tcase_add_test(tc, fail_s21_mul_155);
  tcase_add_test(tc, fail_s21_mul_156);
  tcase_add_test(tc, fail_s21_mul_157);
  tcase_add_test(tc, fail_s21_mul_158);
  tcase_add_test(tc, fail_s21_mul_160);
  tcase_add_test(tc, fail_s21_mul_161);
  tcase_add_test(tc, fail_s21_mul_162);
  tcase_add_test(tc, fail_s21_mul_163);
  tcase_add_test(tc, fail_s21_mul_164);
  tcase_add_test(tc, fail_s21_mul_165);
  tcase_add_test(tc, fail_s21_mul_166);

  suite_add_tcase(c, tc);
  return c;
}
