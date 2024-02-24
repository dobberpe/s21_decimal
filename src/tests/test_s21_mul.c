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

START_TEST(fail_s21_mul_1) {
  // 131498299767401667832.67483
  s21_decimal dec_1 = {{0x85ecf29b, 0xb6204402, 0xae095, 0x50000}};
  // 57675534954633
  s21_decimal dec_2 = {{0xa1c5f089, 0x3474, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 1;  // Результат слишком велик или положительная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
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

  suite_add_tcase(c, tc);
  return c;
}
