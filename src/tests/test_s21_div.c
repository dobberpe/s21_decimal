#include "s21_decimal_test.h"

START_TEST(invalid_dec_s21_div_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_div_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_1) {
  // 0.0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x10000}};
  // -547783951080155032315
  s21_decimal dec_2 = {{0x4098aafb, 0xb2078939, 0x1d, 0x80000000}};
  // 0.0
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
  // -47048579.10
  s21_decimal dec_1 = {{0x186e6f36, 0x1, 0x0, 0x80020000}};
  // -31514
  s21_decimal dec_2 = {{0x7b1a, 0x0, 0x0, 0x80000000}};
  // 1492.9421558672336104588436885
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
  // -14316316279080
  s21_decimal dec_1 = {{0x46f24128, 0xd05, 0x0, 0x80000000}};
  // 63
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x0}};
  // -227243115540.95238095238095238
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
  // -612848382647.7138592271
  s21_decimal dec_1 = {{0x86420f, 0x39cc5215, 0x14c, 0x800a0000}};
  // 1865281.4743
  s21_decimal dec_2 = {{0x57cb5d97, 0x4, 0x0, 0x40000}};
  // -328555.44382528254611267062644
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
  // 758080587127881203214.5
  s21_decimal dec_1 = {{0xe137ec91, 0xf4d0b718, 0x19a, 0x10000}};
  // -5302159136
  s21_decimal dec_2 = {{0x3c088720, 0x1, 0x0, 0x80000000}};
  // -142975826957.12609468055392595
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
  // -437899016.6648351
  s21_decimal dec_1 = {{0x195ba61f, 0xf8eab, 0x0, 0x80070000}};
  // 741735.15782
  s21_decimal dec_2 = {{0x45160806, 0x11, 0x0, 0x50000}};
  // -590.37112107756108521144280900
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
  // 3599032
  s21_decimal dec_1 = {{0x36eab8, 0x0, 0x0, 0x0}};
  // -756.38366103314
  s21_decimal dec_2 = {{0xedf16712, 0x44ca, 0x0, 0x800b0000}};
  // -4758.2096036872389999098683592
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
  // 349
  s21_decimal dec_1 = {{0x15d, 0x0, 0x0, 0x0}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // 174.5
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
  // -941158
  s21_decimal dec_1 = {{0xe5c66, 0x0, 0x0, 0x80000000}};
  // -377
  s21_decimal dec_2 = {{0x179, 0x0, 0x0, 0x80000000}};
  // 2496.4403183023872679045092838
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
  // 795367864932357
  s21_decimal dec_1 = {{0x30e1805, 0x2d362, 0x0, 0x0}};
  // 52749067072530
  s21_decimal dec_2 = {{0x9967b412, 0x2ff9, 0x0, 0x0}};
  // 15.078330462958248939675808947
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
  // 2962306739419524029763029
  s21_decimal dec_1 = {{0xa2904dd5, 0xf859f04b, 0x2734a, 0x0}};
  // 60525594
  s21_decimal dec_2 = {{0x39b8c1a, 0x0, 0x0, 0x0}};
  // 48943042829443756.136668877632
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
  // -406897507916532163
  s21_decimal dec_1 = {{0xab5b49c3, 0x5a59720, 0x0, 0x80000000}};
  // -2542222639817.0299
  s21_decimal dec_2 = {{0x55dcccbb, 0x5a5161, 0x0, 0x80040000}};
  // 160055.81161287179428800473333
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
  // 95946741.7248742097410394740
  s21_decimal dec_1 = {{0x8b990a74, 0xe916fe65, 0x319a720, 0x130000}};
  // 6729
  s21_decimal dec_2 = {{0x1a49, 0x0, 0x0, 0x0}};
  // 14258.692484005678368411275672
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

// START_TEST(s21_div_14) {
//   // 5410196858757297693229
//   s21_decimal dec_1 = {{0x9aef622d, 0x49906296, 0x125, 0x0}};
//   // 58229774218789
//   s21_decimal dec_2 = {{0xad01f625, 0x34f5, 0x0, 0x0}};
//   // 92911176.993909579486063555971
//   s21_decimal dec_check = {{0xd9b0f583, 0x3fc4f821, 0x2c365305, 0x150000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_15) {
  // -827984
  s21_decimal dec_1 = {{0xca250, 0x0, 0x0, 0x80000000}};
  // 67613
  s21_decimal dec_2 = {{0x1081d, 0x0, 0x0, 0x0}};
  // -12.245929037315309186103264165
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
  // 21191639213251506913566754828
  s21_decimal dec_1 = {{0xb047880c, 0xad43b6df, 0x44795027, 0x0}};
  // 47994576605564939
  s21_decimal dec_2 = {{0x29b8500b, 0xaa82d0, 0x0, 0x0}};
  // 441542372327.00893428970601766
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

// START_TEST(s21_div_17) {
//   // -1445825.5
//   s21_decimal dec_1 = {{0xdc9d8f, 0x0, 0x0, 0x80010000}};
//   // -1.5603192593764778434990
//   s21_decimal dec_2 = {{0x8b7ee1ae, 0xd9cbc2c5, 0x34d, 0x80160000}};
//   // 926621.58164846922856660820805
//   s21_decimal dec_check = {{0x303d6345, 0x79e32f72, 0x2b68573b, 0x170000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_18) {
  // -2863102584972500597
  s21_decimal dec_1 = {{0xb4c9de75, 0x27bbc8a1, 0x0, 0x80000000}};
  // 965
  s21_decimal dec_2 = {{0x3c5, 0x0, 0x0, 0x0}};
  // -2966945683909327.0435233160622
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
  // 53448736423708738143817717922
  s21_decimal dec_1 = {{0x9f4258a2, 0x5c0899c5, 0xacb3c22f, 0x0}};
  // 86964.42610475942384
  s21_decimal dec_2 = {{0x7efd41f0, 0x78aff87a, 0x0, 0xe0000}};
  // 614604601188572373649541.44430
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
  // -89308266614597843
  s21_decimal dec_1 = {{0x3311a8d3, 0x13d4965, 0x0, 0x80000000}};
  // -75
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x80000000}};
  // 1190776888194637.9066666666667
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
  // -1782985291959415334323
  s21_decimal dec_1 = {{0x4b17e5b3, 0xa7e43c60, 0x60, 0x80000000}};
  // -17
  s21_decimal dec_2 = {{0x11, 0x0, 0x0, 0x80000000}};
  // 104881487762318549077.82352941
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
  // -6854748086.03935173977463234
  s21_decimal dec_1 = {{0x9d2a59c2, 0xd5685b15, 0x23702ef, 0x80110000}};
  // -947.332950
  s21_decimal dec_2 = {{0x38772756, 0x0, 0x0, 0x80060000}};
  // 7235838.3460000538773349246851
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
  // 5083307385295.56707
  s21_decimal dec_1 = {{0xa7758e3, 0x70df41d, 0x0, 0x50000}};
  // 84969137.476131669317
  s21_decimal dec_2 = {{0x4828c545, 0x9b2f0459, 0x4, 0xc0000}};
  // 59825.338190863688891297072373
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
  // 122138841276901
  s21_decimal dec_1 = {{0xaa3f61e5, 0x6f15, 0x0, 0x0}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 24427768255380.2
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
  // 9181
  s21_decimal dec_1 = {{0x23dd, 0x0, 0x0, 0x0}};
  // -3243.71659074056229569110564
  s21_decimal dec_2 = {{0xe52b2224, 0xdf7f9cb8, 0x10c505e, 0x80170000}};
  // -2.8303952405114147173300635457
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
  // -4025661070152008334045
  s21_decimal dec_1 = {{0xd155fadd, 0x3b45266f, 0xda, 0x80000000}};
  // -5.2537
  s21_decimal dec_2 = {{0xcd39, 0x0, 0x0, 0x80040000}};
  // 766252559177723953412.83286065
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

// START_TEST(s21_div_27) {
//   // -798063797599.6392327
//   s21_decimal dec_1 = {{0xb841e387, 0x6ec0ebf4, 0x0, 0x80070000}};
//   // 8883079
//   s21_decimal dec_2 = {{0x878b87, 0x0, 0x0, 0x0}};
//   // -89840.898364141446079675752067
//   s21_decimal dec_check = {{0xa561de83, 0x38fadce3, 0x224aa63b, 0x80180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_28) {
  // 11697535036.2
  s21_decimal dec_1 = {{0x3c46325a, 0x1b, 0x0, 0x10000}};
  // -3.715372
  s21_decimal dec_2 = {{0x38b12c, 0x0, 0x0, 0x80060000}};
  // -3148415565.4400151586436028478
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
  // -65049151961583685.8724177206
  s21_decimal dec_1 = {{0x5674d536, 0xf002e871, 0x21a12ef, 0x800a0000}};
  // 840405121089
  s21_decimal dec_2 = {{0xac0c7841, 0xc3, 0x0, 0x0}};
  // -77402.136575860888545402023460
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
  // 82796389019714985
  s21_decimal dec_1 = {{0x8c3485a9, 0x12626e0, 0x0, 0x0}};
  // -7814518.4675718304352866
  s21_decimal dec_2 = {{0x8fca62, 0x424a87a2, 0x108c, 0x80100000}};
  // -10595200377.770932325833161155
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
  // 4453018956872.362211196
  s21_decimal dec_1 = {{0x79a7b77c, 0x660d5c2b, 0xf1, 0x90000}};
  // -727854
  s21_decimal dec_2 = {{0xb1b2e, 0x0, 0x0, 0x80000000}};
  // -6118011.2452117625391850563437
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
  // -6950512354103986180642658.117
  s21_decimal dec_1 = {{0xfd095745, 0xb5d91a4c, 0x1675543d, 0x80030000}};
  // 4.64417807353911825
  s21_decimal dec_2 = {{0x2b21a11, 0x671f189, 0x0, 0x110000}};
  // -1496607633050408593274429.2672
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
  // 73424
  s21_decimal dec_1 = {{0x11ed0, 0x0, 0x0, 0x0}};
  // -3436.192
  s21_decimal dec_2 = {{0x346ea0, 0x0, 0x0, 0x80030000}};
  // -21.367839748186364440636611691
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
  // -21181126456766267430671630
  s21_decimal dec_1 = {{0xaee150e, 0x2a7f5b51, 0x118547, 0x80000000}};
  // 6285815
  s21_decimal dec_2 = {{0x5fe9f7, 0x0, 0x0, 0x0}};
  // -3369670672262271070.7635573112
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

// START_TEST(s21_div_35) {
//   // -36679274510746899320
//   s21_decimal dec_1 = {{0x181bd378, 0xfd06f5d5, 0x1, 0x80000000}};
//   // -373509781055895.2
//   s21_decimal dec_2 = {{0x3a331fe8, 0xd450d, 0x0, 0x80010000}};
//   // 98201.643895525988365297442573
//   s21_decimal dec_check = {{0x4106df0d, 0xa8aae39a, 0x3d4e7ef6, 0x180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_36) {
  // -2366608376103853
  s21_decimal dec_1 = {{0xf39483ad, 0x8686a, 0x0, 0x80000000}};
  // -8.0482
  s21_decimal dec_2 = {{0x13a62, 0x0, 0x0, 0x80040000}};
  // 294054369437122.95917099475659
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
  // -8897334025.713455633758
  s21_decimal dec_1 = {{0x56c2955e, 0x53504c4a, 0x1e2, 0x800c0000}};
  // -7608242201.6152323054873
  s21_decimal dec_2 = {{0x16395d19, 0x6fb569be, 0x101c, 0x800d0000}};
  // 1.1694335945068295424123634483
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
  // -82.1
  s21_decimal dec_1 = {{0x335, 0x0, 0x0, 0x80010000}};
  // 0.711
  s21_decimal dec_2 = {{0x2c7, 0x0, 0x0, 0x30000}};
  // -115.47116736990154711673699015
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
  // 96072576266999
  s21_decimal dec_1 = {{0xa3c7f2f7, 0x5760, 0x0, 0x0}};
  // -8.07469568937336059005858356
  s21_decimal dec_2 = {{0xb8357234, 0xafad160, 0x29bec55, 0x801a0000}};
  // -11897981046324.080582455074346
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
  // -6259812
  s21_decimal dec_1 = {{0x5f8464, 0x0, 0x0, 0x80000000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // -3129906
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
  // 121720549124174.08008
  s21_decimal dec_1 = {{0xd9302408, 0xa8ebd373, 0x0, 0x50000}};
  // -914671696
  s21_decimal dec_2 = {{0x3684c850, 0x0, 0x0, 0x80000000}};
  // -133075.67038148962256726483422
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
  // -6923819325789403538.91
  s21_decimal dec_1 = {{0xaa337d63, 0x88bac348, 0x25, 0x80020000}};
  // 91573465
  s21_decimal dec_2 = {{0x5754cd9, 0x0, 0x0, 0x0}};
  // -75609450027.793570319851935274
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
  // -6788.94315826839555696311
  s21_decimal dec_1 = {{0x813866b7, 0xef424c44, 0x8fc2, 0x80140000}};
  // -1039
  s21_decimal dec_2 = {{0x40f, 0x0, 0x0, 0x80000000}};
  // 6.5341127606048080432753705486
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
  // -734
  s21_decimal dec_1 = {{0x2de, 0x0, 0x0, 0x80000000}};
  // 18.00317016387032
  s21_decimal dec_2 = {{0xf83eadd8, 0x66560, 0x0, 0xe0000}};
  // -40.770597251423453859410212788
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
  // 950.72532144357965
  s21_decimal dec_1 = {{0xda5c824d, 0x151c3f6, 0x0, 0xe0000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -316.90844048119321666666666667
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
  // -8949002265909454723712
  s21_decimal dec_1 = {{0xa2d85a80, 0x205ac2ff, 0x1e5, 0x80000000}};
  // -2767.39
  s21_decimal dec_2 = {{0x43903, 0x0, 0x0, 0x80020000}};
  // 3233733686220393484.0091205070
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
  // -56790448190342714352415
  s21_decimal dec_1 = {{0x3ad7e31f, 0x9dca1c6d, 0xc06, 0x80000000}};
  // 361906860865
  s21_decimal dec_2 = {{0x43547341, 0x54, 0x0, 0x0}};
  // -156920065164.29906298348782479
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
  // -2831383543424.53
  s21_decimal dec_1 = {{0x49086a35, 0x10183, 0x0, 0x80020000}};
  // -195228333571
  s21_decimal dec_2 = {{0x7483f603, 0x2d, 0x0, 0x80000000}};
  // 14.502933522171471693302271157
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
  // -3962991672055066953939051512
  s21_decimal dec_1 = {{0x424663f8, 0x4ea8158, 0xcce1c21, 0x80000000}};
  // -7056
  s21_decimal dec_2 = {{0x1b90, 0x0, 0x0, 0x80000000}};
  // 561648479599641008211316.82426
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

// START_TEST(s21_div_50) {
//   // -52716388085800700
//   s21_decimal dec_1 = {{0x91b21efc, 0xbb4946, 0x0, 0x80000000}};
//   // 0.56
//   s21_decimal dec_2 = {{0x38, 0x0, 0x0, 0x20000}};
//   // -94136407296072678.571428571429
//   s21_decimal dec_check = {{0xc4c86925, 0x4e4aeaf, 0x302bcfa1, 0x800c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_51) {
  // -848542.9939019726
  s21_decimal dec_1 = {{0x1d481fce, 0x1e2574, 0x0, 0x800a0000}};
  // -32
  s21_decimal dec_2 = {{0x20, 0x0, 0x0, 0x80000000}};
  // 26516.96855943664375
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
  // -2127134233634068607
  s21_decimal dec_1 = {{0xc154d87f, 0x1d851950, 0x0, 0x80000000}};
  // 1591037789653076
  s21_decimal dec_2 = {{0x5a46c854, 0x5a70a, 0x0, 0x0}};
  // -1336.9476498090518852241438692
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
  // -42594877849170554154152619372
  s21_decimal dec_1 = {{0xebffed6c, 0xa90b020, 0x89a1a83b, 0x80000000}};
  // 6714098371288507635469088032
  s21_decimal dec_2 = {{0xc04b7520, 0x588d875, 0x15b1c5a2, 0x0}};
  // -6.3440949914167163621064106987
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

// START_TEST(s21_div_54) {
//   // -749582135128785822529
//   s21_decimal dec_1 = {{0x7a222341, 0xa28ab471, 0x28, 0x80000000}};
//   // -834576794369484116.4668481320
//   s21_decimal dec_2 = {{0x6f1e2f28, 0xc7db641c, 0x1af7751a, 0x800a0000}};
//   // 898.15837222635568503435102642
//   s21_decimal dec_check = {{0xfe8509b2, 0x4f0939b, 0x2235eb54, 0x1a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_55) {
//   // -554889006537575497904
//   s21_decimal dec_1 = {{0x999800b0, 0x14a1c384, 0x1e, 0x80000000}};
//   // -57691635362346525
//   s21_decimal dec_2 = {{0x9848b61d, 0xccf63c, 0x0, 0x80000000}};
//   // 9618.1882009837028623223052390
//   s21_decimal dec_check = {{0xd4cf5866, 0x70c3d3fc, 0x36c7c9bf, 0x190000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_56) {
  // 5470963835
  s21_decimal dec_1 = {{0x4618487b, 0x1, 0x0, 0x0}};
  // -889472523
  s21_decimal dec_2 = {{0x3504460b, 0x0, 0x0, 0x80000000}};
  // -6.1507957733732040197041589783
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
  // -1065071651381766183528
  s21_decimal dec_1 = {{0xb4dada68, 0xbcd69ff0, 0x39, 0x80000000}};
  // -228169174453.623
  s21_decimal dec_2 = {{0xc6978d77, 0xcf84, 0x0, 0x80030000}};
  // 4667903339.4068291933083647875
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
  // -1823822165277253486186419770
  s21_decimal dec_1 = {{0xdd15563a, 0xb0e80be4, 0x5e4a15d, 0x80000000}};
  // -4960575326
  s21_decimal dec_2 = {{0x27ac5f5e, 0x1, 0x0, 0x80000000}};
  // 367663435270905809.88516971267
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
  // 43417354492261731396373895206
  s21_decimal dec_1 = {{0x41ded826, 0x3444a183, 0x8c49fe6f, 0x0}};
  // 952143322773269440037105613
  s21_decimal dec_2 = {{0x103bafcd, 0xf41327a4, 0x3139830, 0x0}};
  // 45.599599822641989160118715640
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

// START_TEST(s21_div_60) {
//   // 3467381166810710566
//   s21_decimal dec_1 = {{0xdca1c226, 0x301e9ccc, 0x0, 0x0}};
//   // -43.4994240301
//   s21_decimal dec_2 = {{0x47ad5b2d, 0x65, 0x0, 0x800a0000}};
//   // -79710967308702994.550181626866
//   s21_decimal dec_check = {{0xb4c83f2, 0x59d0ae3b, 0x18f5de4, 0x800c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_61) {
  // -27904744.56348648589
  s21_decimal dec_1 = {{0xc576648d, 0x26b9c1bb, 0x0, 0x800b0000}};
  // 0.43
  s21_decimal dec_2 = {{0x2b, 0x0, 0x0, 0x20000}};
  // -64894754.798805781139534883721
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

// START_TEST(s21_div_62) {
//   // -5641529361438348152720
//   s21_decimal dec_1 = {{0xe50c0f90, 0xd3f2881f, 0x131, 0x80000000}};
//   // -6192432715314322404
//   s21_decimal dec_2 = {{0xe3d15be4, 0x55eff0be, 0x0, 0x80000000}};
//   // 911.03603717589834407821066839
//   s21_decimal dec_check = {{0x476e4257, 0x97ed92c6, 0x265f227d, 0x1a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_63) {
  // -31237.6160857
  s21_decimal dec_1 = {{0xbb11f259, 0x48, 0x0, 0x80070000}};
  // -1.0
  s21_decimal dec_2 = {{0xa, 0x0, 0x0, 0x80010000}};
  // 31237.6160857
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
  // 18343991868850362651
  s21_decimal dec_1 = {{0x17ad91b, 0xfe92f36a, 0x0, 0x0}};
  // -1811
  s21_decimal dec_2 = {{0x713, 0x0, 0x0, 0x80000000}};
  // -10129205891137693.346769740475
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
  // 35638762022326070596464493.48
  s21_decimal dec_1 = {{0x15e186c4, 0xbe75d0b, 0xb83f824, 0x20000}};
  // 73494032197722816189
  s21_decimal dec_2 = {{0x5063bebd, 0xfbef40e5, 0x3, 0x0}};
  // 484920.48886971156936114884106
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
  // 48449120427900901512
  s21_decimal dec_1 = {{0xb1279888, 0xa05dda55, 0x2, 0x0}};
  // -696486506576
  s21_decimal dec_2 = {{0x29d4b050, 0xa2, 0x0, 0x80000000}};
  // -69562180.990528889387349249969
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

// START_TEST(s21_div_67) {
//   // -93184917
//   s21_decimal dec_1 = {{0x58de395, 0x0, 0x0, 0x80000000}};
//   // 1023.648796659056
//   s21_decimal dec_2 = {{0xcee64d70, 0x3a300, 0x0, 0xc0000}};
//   // -91032.116976186759578958425287
//   s21_decimal dec_check = {{0x9ff7ecc7, 0x93a9feca, 0x26240095, 0x80180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_68) {
//   // 801566.2784953561953
//   s21_decimal dec_1 = {{0x8879b361, 0x6f3d5ad5, 0x0, 0xd0000}};
//   // -9984
//   s21_decimal dec_2 = {{0x2700, 0x0, 0x0, 0x80000000}};
//   // -80.285083983909875330528846154
//   s21_decimal dec_check = {{0x85ec214a, 0xad43a15e, 0x36a43d3, 0x801b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_69) {
  // 318214539312294718.448553
  s21_decimal dec_1 = {{0x2e09a3a9, 0x71da9ba5, 0x4362, 0x60000}};
  // -8818166984217
  s21_decimal dec_2 = {{0x23b5ee19, 0x805, 0x0, 0x80000000}};
  // -36086.245574827958277050396697
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
  // 855505
  s21_decimal dec_1 = {{0xd0dd1, 0x0, 0x0, 0x0}};
  // -0.2201648823
  s21_decimal dec_2 = {{0x833a7eb7, 0x0, 0x0, 0x800a0000}};
  // -3885746.8596389316172064194817
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
  // -44208
  s21_decimal dec_1 = {{0xacb0, 0x0, 0x0, 0x80000000}};
  // 6497.40
  s21_decimal dec_2 = {{0x9ea0c, 0x0, 0x0, 0x20000}};
  // -6.8039523501708375657955489888
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
  // 2594941.0473565
  s21_decimal dec_1 = {{0xd164b65d, 0x1799, 0x0, 0x70000}};
  // 0.22016555242835
  s21_decimal dec_2 = {{0x20f45553, 0x1406, 0x0, 0xe0000}};
  // 11786317.245069433060420407406
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
  // 94878118590
  s21_decimal dec_1 = {{0x172d32be, 0x16, 0x0, 0x0}};
  // -42118286064.10504835105
  s21_decimal dec_2 = {{0x56ac9021, 0x52dd1a4e, 0xe4, 0x800b0000}};
  // -2.2526585826781558166685381587
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

// START_TEST(s21_div_74) {
//   // -6985803202098805938585261
//   s21_decimal dec_1 = {{0x7bcbfead, 0x26818138, 0x5c74d, 0x80000000}};
//   // -84506583336182171162595.5
//   s21_decimal dec_2 = {{0xaf026ee3, 0x1c51abe6, 0xb2f3, 0x80010000}};
//   // 82.665786809863584804760972376
//   s21_decimal dec_check = {{0xfc77ec58, 0x795061d8, 0xb1b8942, 0x1b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_75) {
//   // 79228162514264337592278184500
//   s21_decimal dec_1 = {{0xb48df234, 0xffffffff, 0xffffffff, 0x0}};
//   // 84080360.062805
//   s21_decimal dec_2 = {{0x7bfe7f55, 0x4c78, 0x0, 0x60000}};
//   // 942290951835645736557.74611355
//   s21_decimal dec_check = {{0x24d9479b, 0x77dc4288, 0x30787b0d, 0x80000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_76) {
//   // 3522593792744586264346014.535
//   s21_decimal dec_1 = {{0xbefab347, 0x24d56daa, 0xb61d240, 0x30000}};
//   // 44143368
//   s21_decimal dec_2 = {{0x2a19308, 0x0, 0x0, 0x0}};
//   // 79798935884198647.106990443842
//   s21_decimal dec_check = {{0x5d830d42, 0x624cae13, 0x1d821f6, 0xc0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_77) {
  // 6920233302488244.5832799899020
  s21_decimal dec_1 = {{0x170fcd8c, 0x550782f5, 0xdf9ad406, 0xd0000}};
  // -8949455861586
  s21_decimal dec_2 = {{0xb5233752, 0x823, 0x0, 0x80000000}};
  // -773.25743704621816952843073580
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
  // -12680672672919522808915021160
  s21_decimal dec_1 = {{0xc6bfcd68, 0x720e62d, 0x28f934e3, 0x80000000}};
  // 475920717193.536127302935
  s21_decimal dec_2 = {{0x4652fd17, 0xb6b9ff7e, 0x64c7, 0xc0000}};
  // -26644506563396457.890984470715
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
  // 825850540247
  s21_decimal dec_1 = {{0x488730d7, 0xc0, 0x0, 0x0}};
  // 363186
  s21_decimal dec_2 = {{0x58ab2, 0x0, 0x0, 0x0}};
  // 2273905.2172908647359755056638
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
  // -32327233504141596497993217
  s21_decimal dec_1 = {{0x4026de01, 0xd6fbf113, 0x1abd8e, 0x80000000}};
  // -132084136.037085589310
  s21_decimal dec_2 = {{0xfadbaf3e, 0x29091de9, 0x7, 0x800c0000}};
  // 244747283618261312.26681368576
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
  // 436435586140896066546685
  s21_decimal dec_1 = {{0xb1cc2bfd, 0x3874cc4e, 0x5c6b, 0x0}};
  // 6398.77
  s21_decimal dec_2 = {{0x9c385, 0x0, 0x0, 0x20000}};
  // 68206168707563495257.164267508
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
  // 31859379320183.0224913
  s21_decimal dec_1 = {{0x4f59e411, 0x456086ef, 0x11, 0x70000}};
  // 63602525
  s21_decimal dec_2 = {{0x3ca7f5d, 0x0, 0x0, 0x0}};
  // 500913.75020383267002843047505
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
  // -625697555419215.0949
  s21_decimal dec_1 = {{0x9bed11a5, 0x56d53e1d, 0x0, 0x80040000}};
  // 210.96830
  s21_decimal dec_2 = {{0x141e97e, 0x0, 0x0, 0x50000}};
  // -2965836836241.3457135503295993
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
  // 40565231424681296524772178048
  s21_decimal dec_1 = {{0x16c0f880, 0xe69d2ca6, 0x8312c5e1, 0x0}};
  // -39.521324
  s21_decimal dec_2 = {{0x25b0c2c, 0x0, 0x0, 0x80060000}};
  // -1026413776640714175587138175.0
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
  // -2546169068864901889925262446
  s21_decimal dec_1 = {{0x5abf2c6e, 0xcc871253, 0x83a2445, 0x80000000}};
  // 33485679033729703298800775
  s21_decimal dec_2 = {{0x7dd1c87, 0x4c3b0dfe, 0x1bb2de, 0x0}};
  // -76.037552241367953543867440180
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
  // 805287808031808323306
  s21_decimal dec_1 = {{0xa8e47eea, 0xa79d02ce, 0x2b, 0x0}};
  // -461504
  s21_decimal dec_2 = {{0x70ac0, 0x0, 0x0, 0x80000000}};
  // -1744920538135765.5043206559423
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
  // 9542932569275353535770
  s21_decimal dec_1 = {{0xdb3c151a, 0x52cb1321, 0x205, 0x0}};
  // -192420107432941264220.9983
  s21_decimal dec_2 = {{0x94eb00bf, 0x26358860, 0x19777, 0x80040000}};
  // -49.594258607308395874755316554
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
  // -6962027501
  s21_decimal dec_1 = {{0x9ef81bed, 0x1, 0x0, 0x80000000}};
  // -910.6449742799920091828
  s21_decimal dec_2 = {{0xb88ed2b4, 0xa9609109, 0x1ed, 0x80130000}};
  // 7645161.0645571036699188353568
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
  // 0.9682400057011118534
  s21_decimal dec_1 = {{0x635ea1c6, 0x865ecb8d, 0x0, 0x130000}};
  // -1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -0.9682400057011118534
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
  // 4263819.33
  s21_decimal dec_1 = {{0x196a126d, 0x0, 0x0, 0x20000}};
  // -60
  s21_decimal dec_2 = {{0x3c, 0x0, 0x0, 0x80000000}};
  // -71063.6555
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
  // -71246906
  s21_decimal dec_1 = {{0x43f243a, 0x0, 0x0, 0x80000000}};
  // 689.0135507
  s21_decimal dec_2 = {{0x9aaf1fd3, 0x1, 0x0, 0x70000}};
  // -103404.21596587911634522226531
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
  // -32155951525508228909
  s21_decimal dec_1 = {{0xfc99272d, 0xbe40e38a, 0x1, 0x80000000}};
  // -30741168288182.313694754
  s21_decimal dec_2 = {{0x69e83622, 0x7b691469, 0x682, 0x80090000}};
  // 1046022.4290782661582871065206
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -5575
  s21_decimal dec_2 = {{0x15c7, 0x0, 0x0, 0x80000000}};
  // 0
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

// START_TEST(s21_div_94) {
//   // 8113425674
//   s21_decimal dec_1 = {{0xe3990d0a, 0x1, 0x0, 0x0}};
//   // 8402389.747930826026129977510
//   s21_decimal dec_2 = {{0x971670a6, 0xf056f049, 0x1b264b3c, 0x150000}};
//   // 965.60929894950583913501459870
//   s21_decimal dec_check = {{0xf4c859e, 0x775f281f, 0x38015442, 0x1a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_95) {
  // 1253328
  s21_decimal dec_1 = {{0x131fd0, 0x0, 0x0, 0x0}};
  // 0.11647
  s21_decimal dec_2 = {{0x2d7f, 0x0, 0x0, 0x50000}};
  // 10760951.317935949171460461922
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
  // 879114555.7045077121
  s21_decimal dec_1 = {{0x806ce481, 0x7a006c4e, 0x0, 0xa0000}};
  // -80350.5536951052428714325621
  s21_decimal dec_2 = {{0xc64a3675, 0x7035f1ff, 0x298a4ea, 0x80160000}};
  // -10940.989393058298214630135535
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
  // -5478
  s21_decimal dec_1 = {{0x1566, 0x0, 0x0, 0x80000000}};
  // -766.3797959
  s21_decimal dec_2 = {{0xc8cc46c7, 0x1, 0x0, 0x80070000}};
  // 7.1478919842437876564590160016
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
  // -23113099407052278012
  s21_decimal dec_1 = {{0xc7a488fc, 0x40c23973, 0x1, 0x80000000}};
  // 0.897
  s21_decimal dec_2 = {{0x381, 0x0, 0x0, 0x30000}};
  // -25767111936513130448.160535117
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
  // 1022201231861436888470212
  s21_decimal dec_1 = {{0xc71d52c4, 0xa3caebbc, 0xd875, 0x0}};
  // 801767879
  s21_decimal dec_2 = {{0x2fca01c7, 0x0, 0x0, 0x0}};
  // 1274934128237178.8412219641940
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

// START_TEST(s21_div_100) {
//   // 9194903615863495921.6265877412
//   s21_decimal dec_1 = {{0xef9b57a4, 0xe98494b, 0x291a75c6, 0xa0000}};
//   // -4339756
//   s21_decimal dec_2 = {{0x42382c, 0x0, 0x0, 0x80000000}};
//   // -2118760505397.8831809038544428
//   s21_decimal dec_check = {{0x8b6c6e2c, 0x76e538bc, 0x4475f9e3, 0x80100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_101) {
  // -90639682976652032
  s21_decimal dec_1 = {{0xba609b00, 0x142044f, 0x0, 0x80000000}};
  // -833052546.2915
  s21_decimal dec_2 = {{0x9a02d183, 0x793, 0x0, 0x80040000}};
  // 108804280.57047866487608750335
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

// START_TEST(s21_div_102) {
//   // -84326784801544228741301302
//   s21_decimal dec_1 = {{0xa7e3c436, 0x29fdb65d, 0x45c0e4, 0x80000000}};
//   // -0.860001
//   s21_decimal dec_2 = {{0xd1f61, 0x0, 0x0, 0x80060000}};
//   // 98054286915415480611419407.652
//   s21_decimal dec_check = {{0xf5e34524, 0xc2b18e08, 0x3cd49ae8, 0x30000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_103) {
  // -5932836144698
  s21_decimal dec_1 = {{0x5897463a, 0x565, 0x0, 0x80000000}};
  // -31018612.485680408
  s21_decimal dec_2 = {{0x82a26d18, 0x6e3343, 0x0, 0x80090000}};
  // 191266.97389952129642535732248
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
  // 60427841742.82
  s21_decimal dec_1 = {{0xf20110ca, 0x57e, 0x0, 0x20000}};
  // 9.01
  s21_decimal dec_2 = {{0x385, 0x0, 0x0, 0x20000}};
  // 6706752690.6570477247502774695
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
  // -7496011900523079
  s21_decimal dec_1 = {{0x46901247, 0x1aa195, 0x0, 0x80000000}};
  // -485
  s21_decimal dec_2 = {{0x1e5, 0x0, 0x0, 0x80000000}};
  // 15455694640253.771134020618557
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
  // 964630315361430453343
  s21_decimal dec_1 = {{0xa318bc5f, 0x4aef50fd, 0x34, 0x0}};
  // 3129306.29093776450537
  s21_decimal dec_2 = {{0xea1063e9, 0xf6c8ed2e, 0x10, 0xe0000}};
  // 308256918843299.94949680447877
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
  // -85981227951.2024
  s21_decimal dec_1 = {{0xa57e6bd8, 0x30dfe, 0x0, 0x80040000}};
  // -0.449
  s21_decimal dec_2 = {{0x1c1, 0x0, 0x0, 0x80030000}};
  // 191494939757.68908685968819599
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
  // 80321511609344743273072392
  s21_decimal dec_1 = {{0x5fc70708, 0xde8473ca, 0x4270bd, 0x0}};
  // 30831
  s21_decimal dec_2 = {{0x786f, 0x0, 0x0, 0x0}};
  // 2605219149860359484709.2988226
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
  // 83399968503
  s21_decimal dec_1 = {{0x6b0686f7, 0x13, 0x0, 0x0}};
  // -640974263
  s21_decimal dec_2 = {{0x26347db7, 0x0, 0x0, 0x80000000}};
  // -130.11437949576455927061146291
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
  // 46247903749105268
  s21_decimal dec_1 = {{0x32926674, 0xa44e39, 0x0, 0x0}};
  // -826443.1
  s21_decimal dec_2 = {{0x7e1aef, 0x0, 0x0, 0x80010000}};
  // -55960178927.146064865203666169
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

// START_TEST(s21_div_111) {
//   // -78519
//   s21_decimal dec_1 = {{0x132b7, 0x0, 0x0, 0x80000000}};
//   // -9020
//   s21_decimal dec_2 = {{0x233c, 0x0, 0x0, 0x80000000}};
//   // 8.7049889135254988913525498891
//   s21_decimal dec_check = {{0xe4b5a40b, 0xc0d7821e, 0x1945fb09, 0x1c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_112) {
//   // -738330565189054756622.463
//   s21_decimal dec_1 = {{0xf7dd107f, 0xfaea6c74, 0x9c58, 0x80030000}};
//   // 82401256.50785170
//   s21_decimal dec_2 = {{0xc251d392, 0x1d4659, 0x0, 0x80000}};
//   // -8960185760258.4259875775306493
//   s21_decimal dec_check = {{0x77e1dafd, 0x92abc22c, 0x2184eb61, 0x80100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_113) {
  // 9.603857870541615771723826674
  s21_decimal dec_1 = {{0x44d105f2, 0x5fc90c7c, 0x1f082002, 0x1b0000}};
  // 1.52773
  s21_decimal dec_2 = {{0x254c5, 0x0, 0x0, 0x50000}};
  // 6.2863581068262165249905589823
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
  // 72157704195668160526781224
  s21_decimal dec_1 = {{0xe52d8b28, 0xfb86ca62, 0x3baffc, 0x0}};
  // 1.912294430617916797
  s21_decimal dec_2 = {{0x22f0557d, 0x1a89d5a7, 0x0, 0x120000}};
  // 37733574412153650987030319.442
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
  // 5465912719225032400431.499
  s21_decimal dec_1 = {{0x13abe98b, 0xb8e4b86d, 0x48573, 0x30000}};
  // -4132280108353651230393
  s21_decimal dec_2 = {{0x101046b9, 0x2e810ca, 0xe0, 0x80000000}};
  // -1.3227352880012570140962997969
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

// START_TEST(s21_div_116) {
//   // 60106801893676045582
//   s21_decimal dec_1 = {{0xe156550e, 0x422641dc, 0x3, 0x0}};
//   // 70.608444
//   s21_decimal dec_2 = {{0x435663c, 0x0, 0x0, 0x60000}};
//   // 851269316934332182.45115272615
//   s21_decimal dec_check = {{0xe1e45da7, 0xf3c815cd, 0x130f58f5, 0xb0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_117) {
  // 777998528438913.02
  s21_decimal dec_1 = {{0xd0567a66, 0x114668d, 0x0, 0x20000}};
  // -5114499900963
  s21_decimal dec_2 = {{0xcff32623, 0x4a6, 0x0, 0x80000000}};
  // -152.11624665246842110089256439
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
  // 4.9663952
  s21_decimal dec_1 = {{0x2f5cfd0, 0x0, 0x0, 0x70000}};
  // -0.121
  s21_decimal dec_2 = {{0x79, 0x0, 0x0, 0x80030000}};
  // -41.044588429752066115702479339
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
  // 104836720632402555407889
  s21_decimal dec_1 = {{0x33838e11, 0x35c36e6b, 0x1633, 0x0}};
  // 165613592200102175
  s21_decimal dec_2 = {{0x4510411f, 0x24c60af, 0x0, 0x0}};
  // 633020.02715896573968893135738
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
  // 4092151702944214694229142149
  s21_decimal dec_1 = {{0xd1d36a85, 0x52d8acf7, 0xd38f2d4, 0x0}};
  // 0.8628836409029
  s21_decimal dec_2 = {{0xeba9ec5, 0x7d9, 0x0, 0xd0000}};
  // 4742414282721003770983939206.7
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
  // -21514013202071122579
  s21_decimal dec_1 = {{0x6a837293, 0x2a912105, 0x1, 0x80000000}};
  // -779.94529878728242277210
  s21_decimal dec_2 = {{0x4352ab5a, 0x17892bf9, 0x1084, 0x80140000}};
  // 27584002667267470.505811802764
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
  // -84724814981829008598236186
  s21_decimal dec_1 = {{0xb823fc1a, 0x6c5fc918, 0x46152d, 0x80000000}};
  // -37804973
  s21_decimal dec_2 = {{0x240dbad, 0x0, 0x0, 0x80000000}};
  // 2241102380415111223.5481873245
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
  // 3401703.2282789021720110578
  s21_decimal dec_1 = {{0x921e5f2, 0x3df4346, 0x1c2363, 0x130000}};
  // 5.60
  s21_decimal dec_2 = {{0x230, 0x0, 0x0, 0x20000}};
  // 607447.00504980395928768889286
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
  // -8200180425965599
  s21_decimal dec_1 = {{0x4962401f, 0x1d2205, 0x0, 0x80000000}};
  // -15869542723862
  s21_decimal dec_2 = {{0xea74f116, 0xe6e, 0x0, 0x80000000}};
  // 516.72443047999868577727015158
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

// START_TEST(s21_div_125) {
//   // 9791975405598478105542
//   s21_decimal dec_1 = {{0x5ad2fbc6, 0xd2f4f748, 0x212, 0x0}};
//   // -9966371946337927161
//   s21_decimal dec_2 = {{0x28e3fff9, 0x8a4faa7b, 0x0, 0x80000000}};
//   // -982.50150188268562160810086756
//   s21_decimal dec_check = {{0x2c625164, 0xeb1551c, 0x3d769e92, 0x801a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_126) {
  // -705917910646837832579393
  s21_decimal dec_1 = {{0x14abf941, 0xe2f943ea, 0x957b, 0x80000000}};
  // 0.96831715759
  s21_decimal dec_2 = {{0x8b9eb9af, 0x16, 0x0, 0xb0000}};
  // -729015183830641218432231.78697
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
  // 88752778879548054907686
  s21_decimal dec_1 = {{0xbd612b26, 0x4c3b8e92, 0x12cb, 0x0}};
  // -51034135698083
  s21_decimal dec_2 = {{0x4f879aa3, 0x2e6a, 0x0, 0x80000000}};
  // -1739086547.9648337381392076025
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
  // -209507032707965460196
  s21_decimal dec_1 = {{0x686d1ee4, 0x5b7e803b, 0xb, 0x80000000}};
  // -77854.000104255688
  s21_decimal dec_2 = {{0xf48eb0c8, 0x11497cc, 0x0, 0x800c0000}};
  // 2691024641346762.3344650248702
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
  // 41541420772852099016581007971
  s21_decimal dec_1 = {{0xe9d54a63, 0x80c6edde, 0x863a4204, 0x0}};
  // -6628610151016.6652213662
  s21_decimal dec_2 = {{0xd75d599e, 0x60738cad, 0xe09, 0x800a0000}};
  // -6266988075393251.2078134497828
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
  // 426367938364403805470
  s21_decimal dec_1 = {{0xc1eeed1e, 0x1d0b34f2, 0x17, 0x0}};
  // 584
  s21_decimal dec_2 = {{0x248, 0x0, 0x0, 0x0}};
  // 730082086240417475.11986301370
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
  // 9083618
  s21_decimal dec_1 = {{0x8a9ae2, 0x0, 0x0, 0x0}};
  // 271
  s21_decimal dec_2 = {{0x10f, 0x0, 0x0, 0x0}};
  // 33518.885608856088560885608856
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
  // -83817924396203029856798035
  s21_decimal dec_1 = {{0x521c4553, 0xc9430e85, 0x455522, 0x80000000}};
  // -40369033864081505868
  s21_decimal dec_2 = {{0x424afe4c, 0x303b9e6a, 0x2, 0x80000000}};
  // 2076292.5533073094362330510510
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
  // 3534345121395950582.07863000
  s21_decimal dec_1 = {{0x752130d8, 0x4b6e8564, 0x1245aab, 0x80000}};
  // -59.9691
  s21_decimal dec_2 = {{0x9268b, 0x0, 0x0, 0x80040000}};
  // -58936104116886039.344906460160
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
  // -35890417055426328270.7977
  s21_decimal dec_1 = {{0x52c4ee09, 0x3bec1b4f, 0x4c00, 0x80040000}};
  // -317774.62200547258131
  s21_decimal dec_2 = {{0xd705af13, 0xb9003981, 0x1, 0x800e0000}};
  // 112942993461599.45571639858206
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
  // 3750390259566
  s21_decimal dec_1 = {{0x34addf6e, 0x369, 0x0, 0x0}};
  // 4750
  s21_decimal dec_2 = {{0x128e, 0x0, 0x0, 0x0}};
  // 789555844.11915789473684210526
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
  // 8358619124612620179124
  s21_decimal dec_1 = {{0x19c556b4, 0x1f247ff9, 0x1c5, 0x0}};
  // -198.91696
  s21_decimal dec_2 = {{0x12f85f0, 0x0, 0x0, 0x80050000}};
  // -42020645824331018225.514807787
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
  // -259338870300543800363611
  s21_decimal dec_1 = {{0x6f4ca5b, 0xc9cff61f, 0x36ea, 0x80000000}};
  // 4.071686508531184964809738743
  s21_decimal dec_2 = {{0x43b349f7, 0xe956317f, 0xd280527, 0x1b0000}};
  // -63693231234075870944217.559080
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
  // -4034672164913423676496
  s21_decimal dec_1 = {{0x24e17450, 0xb852fd61, 0xda, 0x80000000}};
  // -993621726
  s21_decimal dec_2 = {{0x3b3976de, 0x0, 0x0, 0x80000000}};
  // 4060571603195.2220784029031990
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
  // 352223828368274785136
  s21_decimal dec_1 = {{0x372c8370, 0x181669bd, 0x13, 0x0}};
  // 83.2092
  s21_decimal dec_2 = {{0xcb25c, 0x0, 0x0, 0x40000}};
  // 4232991404415314474.0725785130
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
  // -181385953537430676920297324
  s21_decimal dec_1 = {{0x341f676c, 0x3e82b3bb, 0x9609f8, 0x80000000}};
  // 70602571616647891.63735
  s21_decimal dec_2 = {{0x416b2ed7, 0xbcc031b0, 0x17e, 0x50000}};
  // -2569112560.4079323565385720344
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
  // -887422237429315611
  s21_decimal dec_1 = {{0xbbc1b81b, 0xc50c1d2, 0x0, 0x80000000}};
  // 3340.8624
  s21_decimal dec_2 = {{0x1fdc670, 0x0, 0x0, 0x40000}};
  // -265626694900489.05067146734328
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
  // 22381295304399072947284.97
  s21_decimal dec_1 = {{0x9d225131, 0x3eb5b8a0, 0x1d9f1, 0x20000}};
  // -214279
  s21_decimal dec_2 = {{0x34507, 0x0, 0x0, 0x80000000}};
  // -104449317499143980.26537817518
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
  // -16525948189813161695793094190
  s21_decimal dec_1 = {{0xb1079e2e, 0x7d2998c1, 0x3565f1a6, 0x80000000}};
  // -55249926480726174370
  s21_decimal dec_2 = {{0x5621aaa2, 0xfebf2b68, 0x2, 0x80000000}};
  // 299112582.44982833513217585447
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
  // -8990792971
  s21_decimal dec_1 = {{0x17e49d0b, 0x2, 0x0, 0x80000000}};
  // 638
  s21_decimal dec_2 = {{0x27e, 0x0, 0x0, 0x0}};
  // -14092151.992163009404388714734
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
  // 5866208452769985
  s21_decimal dec_1 = {{0x170178c1, 0x14d749, 0x0, 0x0}};
  // 960963809497588
  s21_decimal dec_2 = {{0xd281d1f4, 0x369fd, 0x0, 0x0}};
  // 6.1045050758331488093807444836
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

START_TEST(s21_div_146) {
  // -77283039920
  s21_decimal dec_1 = {{0xfe6d9ab0, 0x11, 0x0, 0x80000000}};
  // -11267.275504047544421309931647
  s21_decimal dec_2 = {{0xccfae07f, 0xf95b851a, 0x24681264, 0x80180000}};
  // 6859070.7569223461716587002356
  s21_decimal dec_check = {{0xdd3539f4, 0xf1893fda, 0xdda0e74b, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_147) {
  // 8716680673446
  s21_decimal dec_1 = {{0x82a7b8a6, 0x7ed, 0x0, 0x0}};
  // -12881116
  s21_decimal dec_2 = {{0xc48cdc, 0x0, 0x0, 0x80000000}};
  // -676702.28833014158090028845327
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
  // 7230371404750644
  s21_decimal dec_1 = {{0x72c9f34, 0x19affc, 0x0, 0x0}};
  // -15
  s21_decimal dec_2 = {{0xf, 0x0, 0x0, 0x80000000}};
  // -482024760316709.6
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
  // 0.96
  s21_decimal dec_1 = {{0x60, 0x0, 0x0, 0x20000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // 0.48
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
  // -7105690709
  s21_decimal dec_1 = {{0xa7883c55, 0x1, 0x0, 0x80000000}};
  // 3180.214
  s21_decimal dec_2 = {{0x3086b6, 0x0, 0x0, 0x30000}};
  // -2234343.5721621249387619826842
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

// START_TEST(s21_div_151) {
//   // 7.2236
//   s21_decimal dec_1 = {{0x11a2c, 0x0, 0x0, 0x40000}};
//   // -0.851652
//   s21_decimal dec_2 = {{0xcfec4, 0x0, 0x0, 0x80060000}};
//   // -8.4818681809001798856810058569
//   s21_decimal dec_check = {{0xc1ce5349, 0x3bdbe86e, 0x12105e82, 0x801c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_152) {
  // 52.0195
  s21_decimal dec_1 = {{0x7f003, 0x0, 0x0, 0x40000}};
  // -1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -52.0195
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
  // -800944148756489222.6
  s21_decimal dec_1 = {{0xdb94e842, 0x6f274098, 0x0, 0x80010000}};
  // 73.92444570533641752967675
  s21_decimal dec_2 = {{0xa68879fb, 0x39218265, 0x61d69, 0x170000}};
  // -10834631779980612.064862850280
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
  // -53883656533961
  s21_decimal dec_1 = {{0xc434f7c9, 0x3101, 0x0, 0x80000000}};
  // -126915.17151688477349
  s21_decimal dec_2 = {{0x5f2b4aa5, 0xb021539b, 0x0, 0x800e0000}};
  // 424564343.96255239839676577761
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
  // 444188408157
  s21_decimal dec_1 = {{0x6bb1395d, 0x67, 0x0, 0x0}};
  // 689
  s21_decimal dec_2 = {{0x2b1, 0x0, 0x0, 0x0}};
  // 644685643.18867924528301886792
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
  // -6910217617337011891.45
  s21_decimal dec_1 = {{0x49e0be19, 0x75da771b, 0x25, 0x80020000}};
  // 9244602344090.3
  s21_decimal dec_2 = {{0x44635a07, 0x5414, 0x0, 0x10000}};
  // -747486.73443530367165466171818
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
  // 6992761326311.513288
  s21_decimal dec_1 = {{0x85e31cc8, 0x610b4760, 0x0, 0x60000}};
  // 30645560.92
  s21_decimal dec_2 = {{0xb6a96a3c, 0x0, 0x0, 0x20000}};
  // 228181.86766318497811329994086
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -66133
  s21_decimal dec_2 = {{0x10255, 0x0, 0x0, 0x80000000}};
  // 0
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

// START_TEST(s21_div_159) {
//   // -8285859945832935721489
//   s21_decimal dec_1 = {{0x198a0a11, 0x2d67f85e, 0x1c1, 0x80000000}};
//   // -0.91496
//   s21_decimal dec_2 = {{0x16568, 0x0, 0x0, 0x80050000}};
//   // 9055980530113814507179.5488327
//   s21_decimal dec_check = {{0xf88b4647, 0x5e2f9af2, 0x249d50b2, 0x70000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_160) {
  // 596979644409215278
  s21_decimal dec_1 = {{0xdb26792e, 0x848e5d2, 0x0, 0x0}};
  // -76376039910
  s21_decimal dec_2 = {{0xc85de1e6, 0x11, 0x0, 0x80000000}};
  // -7816320.9969079853802543138427
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
  // -4191904
  s21_decimal dec_1 = {{0x3ff6a0, 0x0, 0x0, 0x80000000}};
  // 3428616.65913092
  s21_decimal dec_2 = {{0xb3cdc904, 0x137d4, 0x0, 0x80000}};
  // -1.2226225375287527171134636006
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

// START_TEST(s21_div_162) {
//   // -71669362097632441902761103
//   s21_decimal dec_1 = {{0x6cb3048f, 0xe7832a39, 0x3b4893, 0x80000000}};
//   // 8262484816045684291086
//   s21_decimal dec_2 = {{0x3dc3f60e, 0xe902d3ac, 0x1bf, 0x0}};
//   // -8674.0688416698898798797203023
//   s21_decimal dec_check = {{0xd0c1264f, 0x36b257d2, 0x1846373d, 0x80190000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_163) {
  // 953884128957682780
  s21_decimal dec_1 = {{0xb767d45c, 0xd3ce08f, 0x0, 0x0}};
  // -155098471372139
  s21_decimal dec_2 = {{0xad4a956b, 0x8d0f, 0x0, 0x80000000}};
  // -6150.1839477770188711802837457
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
  // -96457877397556544.6231143
  s21_decimal dec_1 = {{0x55893467, 0xeb8c9567, 0xcc41, 0x80070000}};
  // -765170057387
  s21_decimal dec_2 = {{0x27b080ab, 0xb2, 0x0, 0x80000000}};
  // 126060.70567757599997916853666
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
  // -5047105122
  s21_decimal dec_1 = {{0x2cd4b662, 0x1, 0x0, 0x80000000}};
  // -934831.865302468582327623985
  s21_decimal dec_2 = {{0x5d9ea131, 0xf6a6aae2, 0x3054658, 0x80150000}};
  // 5398.9442479766016397490230005
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
  // -765327429923396840
  s21_decimal dec_1 = {{0x1d725ce8, 0xa9efd3e, 0x0, 0x80000000}};
  // 73611991052615
  s21_decimal dec_2 = {{0x2093f147, 0x42f3, 0x0, 0x0}};
  // -10396.776652547958340458270880
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
  // 3810436297
  s21_decimal dec_1 = {{0xe31ea4c9, 0x0, 0x0, 0x0}};
  // 960455215
  s21_decimal dec_2 = {{0x393f622f, 0x0, 0x0, 0x0}};
  // 3.9673232416151751542106000226
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
  // -6250367179166915820068256
  s21_decimal dec_1 = {{0x7b911da0, 0x156ef3b6, 0x52b91, 0x80000000}};
  // -28976476326646181853
  s21_decimal dec_2 = {{0xf442efdd, 0x92211fb1, 0x1, 0x80000000}};
  // 215704.87414369305204501119007
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
  // 61516488
  s21_decimal dec_1 = {{0x3aaaac8, 0x0, 0x0, 0x0}};
  // -9504.9
  s21_decimal dec_2 = {{0x17349, 0x0, 0x0, 0x80010000}};
  // -6472.0815579332765205315153237
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
  // -981116487454974156134796153
  s21_decimal dec_1 = {{0xe321cb79, 0x5ba5fc9b, 0x32b8f7f, 0x80000000}};
  // 42979724.29065
  s21_decimal dec_2 = {{0xb31eb109, 0x3e8, 0x0, 0x50000}};
  // -22827426272448438944.085759460
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

// START_TEST(s21_div_171) {
//   // 4870148496409930127184
//   s21_decimal dec_1 = {{0xca65750, 0x2e32e55, 0x108, 0x0}};
//   // -5571404
//   s21_decimal dec_2 = {{0x55034c, 0x0, 0x0, 0x80000000}};
//   // -874133072455332.64634623516801
//   s21_decimal dec_check = {{0xdf976081, 0xfcccf7a4, 0x1a7297d0, 0x800e0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_172) {
//   // -9076760745574704606398.8671242
//   s21_decimal dec_1 = {{0x3a02030a, 0xbddadd48, 0x25493483, 0x80070000}};
//   // 2880007870210250
//   s21_decimal dec_2 = {{0x160de0ca, 0xa3b5a, 0x0, 0x0}};
//   // -3151644.4241216852529737298252
//   s21_decimal dec_check = {{0x6246f14c, 0xc46c62e1, 0x65d5caa9, 0x80160000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_173) {
  // -858382892638132562
  s21_decimal dec_1 = {{0x64f7d952, 0xbe996b1, 0x0, 0x80000000}};
  // 4562485.57760310444208225447
  s21_decimal dec_2 = {{0xc1a0fca7, 0xe0380e2b, 0x1796663, 0x140000}};
  // -188139310916.81013939910530771
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
  // -164340
  s21_decimal dec_1 = {{0x281f4, 0x0, 0x0, 0x80000000}};
  // -100437
  s21_decimal dec_2 = {{0x18855, 0x0, 0x0, 0x80000000}};
  // 1.6362495892947818035186236148
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

// START_TEST(s21_div_175) {
//   // 7697156652024808690.5076
//   s21_decimal dec_1 = {{0x11540f4, 0xa3114154, 0x104c, 0x40000}};
//   // 8003670046177634
//   s21_decimal dec_2 = {{0xa6007962, 0x1c6f4b, 0x0, 0x0}};
//   // 961.70339451971674517046734284
//   s21_decimal dec_check = {{0xd6eaadcc, 0x1ff33cfc, 0x36be3d84, 0x1a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_176) {
  // 8204855419324012
  s21_decimal dec_1 = {{0xc4b3c66c, 0x1d2645, 0x0, 0x0}};
  // 5.0926659336868938383647775
  s21_decimal dec_2 = {{0x5f64641f, 0xbc09b520, 0x2a2023, 0x190000}};
  // 1611112043507635.4858949904451
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
  // -43814316345438123215950118165
  s21_decimal dec_1 = {{0xa7d2fd15, 0x627264ea, 0x8d925a60, 0x80000000}};
  // 650.82428925958
  s21_decimal dec_2 = {{0x2f0ea806, 0x3b31, 0x0, 0xb0000}};
  // -67321267919001819075525661.534
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
  // -99.4833311532152
  s21_decimal dec_1 = {{0xae250478, 0x388cb, 0x0, 0x800d0000}};
  // -40.27657488374888776
  s21_decimal dec_2 = {{0x6f86f948, 0x37e51d25, 0x0, 0x80110000}};
  // 2.4700047469367988482010349462
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
  // 4436553.228588184
  s21_decimal dec_1 = {{0x8b379498, 0xfc305, 0x0, 0x90000}};
  // -3102
  s21_decimal dec_2 = {{0xc1e, 0x0, 0x0, 0x80000000}};
  // -1430.2234779459007092198581560
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
  // -18346091.197544154
  s21_decimal dec_1 = {{0x38d8b6da, 0x412dac, 0x0, 0x80090000}};
  // 34.054
  s21_decimal dec_2 = {{0x8506, 0x0, 0x0, 0x30000}};
  // -538735.27919023180830445762612
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

// START_TEST(s21_div_181) {
//   // 284548321019780704583
//   s21_decimal dec_1 = {{0xa9d8a947, 0x6ce6b65d, 0xf, 0x0}};
//   // 349872207697
//   s21_decimal dec_2 = {{0x76023751, 0x51, 0x0, 0x0}};
//   // 813292152.84858586680346304512
//   s21_decimal dec_check = {{0x673c6000, 0xeb53e12e, 0x6c9f33a, 0x140000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_182) {
  // 75584280081.64009
  s21_decimal dec_1 = {{0xa87caaa9, 0x1ada59, 0x0, 0x50000}};
  // 959230649
  s21_decimal dec_2 = {{0x392cb2b9, 0x0, 0x0, 0x0}};
  // 78.796773393799357217994814092
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

// START_TEST(s21_div_183) {
//   // 377903
//   s21_decimal dec_1 = {{0x5c42f, 0x0, 0x0, 0x0}};
//   // -387.740316
//   s21_decimal dec_2 = {{0x171c729c, 0x0, 0x0, 0x80060000}};
//   // -974.62911233610280546632659164
//   s21_decimal dec_check = {{0x86c2f0dc, 0xcfe63f7f, 0x3aeb6e3c, 0x801a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_184) {
  // -5156932043586
  s21_decimal dec_1 = {{0xb11a4342, 0x4b0, 0x0, 0x80000000}};
  // -14396
  s21_decimal dec_2 = {{0x383c, 0x0, 0x0, 0x80000000}};
  // 358219786.30077799388719088636
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
  // 3709658577750712588172.123074
  s21_decimal dec_1 = {{0x370ddbc2, 0x75769177, 0xbfc8ec2, 0x60000}};
  // 32386849
  s21_decimal dec_2 = {{0x1ee2f21, 0x0, 0x0, 0x0}};
  // 114542127199552.89840552636269
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
  // 234
  s21_decimal dec_1 = {{0xea, 0x0, 0x0, 0x0}};
  // -7.9909773
  s21_decimal dec_2 = {{0x4c3538d, 0x0, 0x0, 0x80070000}};
  // -29.283026495395000058378341282
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
  // 6830886383980
  s21_decimal dec_1 = {{0x708e716c, 0x636, 0x0, 0x0}};
  // -6.02703328460182
  s21_decimal dec_2 = {{0xcdcc3d96, 0x22427, 0x0, 0x800e0000}};
  // -1133374591016.7620875601410136
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
  // -50276227365386502376950262744
  s21_decimal dec_1 = {{0x286aebd8, 0xb244b28e, 0xa2738542, 0x80000000}};
  // 9.2114870425706607168
  s21_decimal dec_2 = {{0x4f60b240, 0xfe59c29b, 0x4, 0x130000}};
  // -5457992518801378611751189450.2
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
  // 13198528365397.54740915631369
  s21_decimal dec_1 = {{0xd42bf509, 0xa30a6da3, 0x443c1b5, 0xe0000}};
  // 95457.85717459403
  s21_decimal dec_2 = {{0x6eca89cb, 0x21e9d7, 0x0, 0xb0000}};
  // 138265500.14900519428354542182
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
  // -753284664077751.917912133
  s21_decimal dec_1 = {{0xf1dea045, 0xa4ba1983, 0x9f83, 0x80090000}};
  // -5795004333
  s21_decimal dec_2 = {{0x5968bfad, 0x1, 0x0, 0x80000000}};
  // 129988.62827213556768744058849
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
  // -429229998304592
  s21_decimal dec_1 = {{0xe5936d50, 0x18661, 0x0, 0x80000000}};
  // -553157950829
  s21_decimal dec_2 = {{0xcac87d6d, 0x80, 0x0, 0x80000000}};
  // 775.96281073302630813191998878
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
  // -640711467308523409240287
  s21_decimal dec_1 = {{0xc10df0df, 0x9ca1242, 0x87ad, 0x80000000}};
  // 965.3300180716956601
  s21_decimal dec_2 = {{0x75d92bb9, 0x85f7695e, 0x0, 0x100000}};
  // -663722722088745167931.53899872
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
  // -5866845758935737142329716010
  s21_decimal dec_1 = {{0xc5ebad2a, 0xdfafb315, 0x12f4f0e9, 0x80000000}};
  // 3397622187554248
  s21_decimal dec_2 = {{0x8f91f5c8, 0xc121e, 0x0, 0x0}};
  // -1726750484626.1145338249056124
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
  // -6341018167.5946170702823465
  s21_decimal dec_1 = {{0x84fb0029, 0xd6275bdc, 0x3473a0, 0x80100000}};
  // -9569.40
  s21_decimal dec_2 = {{0xe9a0c, 0x0, 0x0, 0x80020000}};
  // 662634.87445342624096415099170
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
  // 7084093456.5644906703919943780
  s21_decimal dec_1 = {{0x5bde9064, 0xd949e205, 0xe4e63f65, 0x130000}};
  // -399.53849
  s21_decimal dec_2 = {{0x261a5b9, 0x0, 0x0, 0x80050000}};
  // -17730690.869268917421177605136
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
  // -1373141337.47
  s21_decimal dec_1 = {{0xf88f66f3, 0x1f, 0x0, 0x80020000}};
  // -0.002
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80030000}};
  // 686570668735
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
  // -5064368266681969980
  s21_decimal dec_1 = {{0x3b56ed3c, 0x4648401b, 0x0, 0x80000000}};
  // -851449
  s21_decimal dec_2 = {{0xcfdf9, 0x0, 0x0, 0x80000000}};
  // 5947940824032.8780467180065982
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
  // -8063.7234361976360
  s21_decimal dec_1 = {{0x2dd0c628, 0x11e7b23, 0x0, 0x800d0000}};
  // 373
  s21_decimal dec_2 = {{0x175, 0x0, 0x0, 0x0}};
  // -21.618561491146477211796246649
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
  // 3751749218722197615718453
  s21_decimal dec_1 = {{0xc754b035, 0xbb90c88f, 0x31a76, 0x0}};
  // 338
  s21_decimal dec_2 = {{0x152, 0x0, 0x0, 0x0}};
  // 11099849759533129040587.139053
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
  // 8061884195546571777
  s21_decimal dec_1 = {{0x4fe3a401, 0x6fe190f6, 0x0, 0x0}};
  // -4945.44625722
  s21_decimal dec_2 = {{0x2528203a, 0x73, 0x0, 0x80080000}};
  // -1630163139226676.2401438287892
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
  // 15345044400557611553
  s21_decimal dec_1 = {{0xadd55a21, 0xd4f48c94, 0x0, 0x0}};
  // 929025191
  s21_decimal dec_2 = {{0x375fcca7, 0x0, 0x0, 0x0}};
  // 16517360938.340380861642319019
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
  // -7851787334208845527.8031849
  s21_decimal dec_1 = {{0xb5bff3e9, 0x715cc34a, 0x40f2ce, 0x80070000}};
  // -4406414661092869726
  s21_decimal dec_2 = {{0xbf83865e, 0x3d26bac9, 0x0, 0x80000000}};
  // 1.7818993304323886973437848908
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
  // 5708755673111327008890524049
  s21_decimal dec_1 = {{0x8e979191, 0x2618928f, 0x12722c09, 0x0}};
  // -9156
  s21_decimal dec_2 = {{0x23c4, 0x0, 0x0, 0x80000000}};
  // -623498872117881936313949.76507
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
  // 9673516.93297530898
  s21_decimal dec_1 = {{0x63df3812, 0xd6cb93d, 0x0, 0xb0000}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -1612252.8221625514966666666667
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
  // 13786161009712716525545078365
  s21_decimal dec_1 = {{0x61ce3e5d, 0xd9287e59, 0x2c8ba525, 0x0}};
  // -8491974955963937866102014
  s21_decimal dec_2 = {{0xd9efb4fe, 0xe2821598, 0x7063e, 0x80000000}};
  // -1623.4340163745604221513583747
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
  // -53630332535775.379
  s21_decimal dec_1 = {{0xd7fb2093, 0xbe8880, 0x0, 0x80030000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // 13407583133943.84475
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
  // -236980588326600035932347
  s21_decimal dec_1 = {{0xfd5e18bb, 0xbe51c212, 0x322e, 0x80000000}};
  // 91.285
  s21_decimal dec_2 = {{0x16495, 0x0, 0x0, 0x30000}};
  // -2596051797410308768498.0774497
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
  // 25291633650846.826506
  s21_decimal dec_1 = {{0xfc0a800a, 0x5efdeecd, 0x1, 0x60000}};
  // 9312367333405
  s21_decimal dec_2 = {{0x3458d01d, 0x878, 0x0, 0x0}};
  // 2.7159188147702849412521165845
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
  // -56963910028033.70813307410136
  s21_decimal dec_1 = {{0x2342d6d8, 0x73fa35c, 0x1267f1b7, 0x800e0000}};
  // 1913.4376032994774123
  s21_decimal dec_2 = {{0xad66cc6b, 0x98af59f, 0x1, 0x100000}};
  // -29770456026.267467996099886000
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
  // -61552707606688183
  s21_decimal dec_1 = {{0x87dc31b7, 0xdaaddc, 0x0, 0x80000000}};
  // -1236061
  s21_decimal dec_2 = {{0x12dc5d, 0x0, 0x0, 0x80000000}};
  // 49797467606.119910748741364706
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
  // -65780959186857265.97
  s21_decimal dec_1 = {{0xc3b5a785, 0x5b4a1762, 0x0, 0x80020000}};
  // 31927185751778
  s21_decimal dec_2 = {{0xa090bee2, 0x1d09, 0x0, 0x0}};
  // -2060.3431726892488733980731610
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
  // 77549623645583
  s21_decimal dec_1 = {{0xedc5158f, 0x4687, 0x0, 0x0}};
  // 46676.01022144503445
  s21_decimal dec_2 = {{0x4e2c5e95, 0x40c6a666, 0x0, 0xe0000}};
  // 1661444996.6409779988062067167
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
  // 3040471332515383219
  s21_decimal dec_1 = {{0x5c5687b3, 0x2a31ec91, 0x0, 0x0}};
  // 437858366.896342993101711
  s21_decimal dec_2 = {{0xbdc6638f, 0x5981732b, 0x5cb8, 0xf0000}};
  // 6943960792.7720001997765080459
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
  // -11242699.09342
  s21_decimal dec_1 = {{0xc3b5655e, 0x105, 0x0, 0x80050000}};
  // 718991.953
  s21_decimal dec_2 = {{0x2adaf251, 0x0, 0x0, 0x30000}};
  // -15.636752325961011138048161159
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
  // -79228162514264337592998903785
  s21_decimal dec_1 = {{0xdf833fe9, 0xffffffff, 0xffffffff, 0x80000000}};
  // 393920725243412
  s21_decimal dec_2 = {{0xd0e5d614, 0x16644, 0x0, 0x0}};
  // -201127174675329.83889316185900
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
  // 3724400119882177199901905
  s21_decimal dec_1 = {{0x86a68cd1, 0x22933b4c, 0x314ac, 0x0}};
  // -1.4069516
  s21_decimal dec_2 = {{0xd6af0c, 0x0, 0x0, 0x80070000}};
  // -2647141607346107143914477.9394
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
  // 2149.185794642
  s21_decimal dec_1 = {{0x6574b252, 0x1f4, 0x0, 0x90000}};
  // 41.241236
  s21_decimal dec_2 = {{0x2754a94, 0x0, 0x0, 0x60000}};
  // 52.112545672539979160663371001
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
  // 697290011569187
  s21_decimal dec_1 = {{0x7b71ec23, 0x27a2e, 0x0, 0x0}};
  // 6.2035577614
  s21_decimal dec_2 = {{0x719bcb0e, 0xe, 0x0, 0xa0000}};
  // 112401631191038.46569690779312
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
  // 2868413227664990876540656
  s21_decimal dec_1 = {{0x81d11ef0, 0xfe1e60b1, 0x25f68, 0x0}};
  // -499
  s21_decimal dec_2 = {{0x1f3, 0x0, 0x0, 0x80000000}};
  // -5748323101533047848778.8697395
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
  // 7987862768085716817626568
  s21_decimal dec_1 = {{0x308f45c8, 0xe8888f32, 0x69b7e, 0x0}};
  // 1334296768
  s21_decimal dec_2 = {{0x4f87c0c0, 0x0, 0x0, 0x0}};
  // 5986571323303780.0610385410152
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
  // -1470158849725103355900845
  s21_decimal dec_1 = {{0x68bab3ad, 0x788f6d90, 0x13751, 0x80000000}};
  // 579385
  s21_decimal dec_2 = {{0x8d739, 0x0, 0x0, 0x0}};
  // -2537447206477736489.3824400010
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
  // 19414038114590
  s21_decimal dec_1 = {{0x2ed8711e, 0x11a8, 0x0, 0x0}};
  // -9.0
  s21_decimal dec_2 = {{0x5a, 0x0, 0x0, 0x80010000}};
  // -2157115346065.5555555555555556
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
  // 2469591103065468720802131
  s21_decimal dec_1 = {{0xf8b26953, 0xcd4ce79a, 0x20af4, 0x0}};
  // -6804.7654740885310331049
  s21_decimal dec_2 = {{0x9eb4d8a9, 0xdee9cee8, 0xe68, 0x80130000}};
  // -362920825481683450768.54215871
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
  // -7437.8458682
  s21_decimal dec_1 = {{0x514d363a, 0x11, 0x0, 0x80070000}};
  // -1.041692
  s21_decimal dec_2 = {{0xfe51c, 0x0, 0x0, 0x80060000}};
  // 7140.1583848200811756258087803
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
  // -42440970658
  s21_decimal dec_1 = {{0xe1add1a2, 0x9, 0x0, 0x80000000}};
  // -2769909753.91456396
  s21_decimal dec_2 = {{0x16325c8c, 0x3d811d3, 0x0, 0x80080000}};
  // 15.322149249815979295689807517
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
  // -8845.717
  s21_decimal dec_1 = {{0x86f995, 0x0, 0x0, 0x80030000}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 1769.1434
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
  // 62326882822582520.35
  s21_decimal dec_1 = {{0x73be2103, 0x567ef4f8, 0x0, 0x20000}};
  // -3663392894855
  s21_decimal dec_2 = {{0xf33b6f87, 0x354, 0x0, 0x80000000}};
  // -17013.431158344119643754426550
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
  // -502973666767316387056653
  s21_decimal dec_1 = {{0x35eb4c0d, 0x41d2002d, 0x6a82, 0x80000000}};
  // 9.7
  s21_decimal dec_2 = {{0x61, 0x0, 0x0, 0x10000}};
  // -51852955336836740933675.567010
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -2749039129786042329360396531
  s21_decimal dec_2 = {{0x9cb670f3, 0xd68cb2bb, 0x8e1f3ad, 0x80000000}};
  // 0
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
  // -33849898771360.4535618817
  s21_decimal dec_1 = {{0xd9f28d01, 0x111fe905, 0x47ae, 0x800a0000}};
  // -6.59267347
  s21_decimal dec_2 = {{0x274b9f13, 0x0, 0x0, 0x80080000}};
  // 5134472217590.4236861713856427
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
  // -7573485101851272520099285011
  s21_decimal dec_1 = {{0x4c25c813, 0x922d224, 0x1878a3da, 0x80000000}};
  // -0.3339448961046739834390903
  s21_decimal dec_2 = {{0xa4404977, 0xe413911e, 0x2c327, 0x80190000}};
  // 22678846690555160625046493509
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
  // 3439885234.449065013351228703
  s21_decimal dec_1 = {{0x8963251f, 0x36eb0fb7, 0xb1d6808, 0x120000}};
  // -922
  s21_decimal dec_2 = {{0x39a, 0x0, 0x0, 0x80000000}};
  // -3730895.0482093980622030680076
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
  // 7877898377259342578876671
  s21_decimal dec_1 = {{0xcc8480ff, 0xba0d16eb, 0x68435, 0x0}};
  // -758304586130702195994
  s21_decimal dec_2 = {{0x7e1bdd1a, 0x1b97136a, 0x29, 0x80000000}};
  // -10388.831244522500515916041419
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

// START_TEST(s21_div_234) {
//   // 489093617.620
//   s21_decimal dec_1 = {{0xe04057d4, 0x71, 0x0, 0x30000}};
//   // -5005
//   s21_decimal dec_2 = {{0x138d, 0x0, 0x0, 0x80000000}};
//   // -97721.002521478521478521478521
//   s21_decimal dec_check = {{0x996edd79, 0x8ffafc41, 0x3bc0eb31, 0x80180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_235) {
  // -1676356974060
  s21_decimal dec_1 = {{0x4ea975ec, 0x186, 0x0, 0x80000000}};
  // -394
  s21_decimal dec_2 = {{0x18a, 0x0, 0x0, 0x80000000}};
  // 4254713132.1319796954314720812
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
  // -1308922026027198242467657
  s21_decimal dec_1 = {{0xa965af49, 0xce22599f, 0x1152c, 0x80000000}};
  // -0.7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80010000}};
  // 1869888608610283203525224.2857
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
  // 10690618851069261160754773
  s21_decimal dec_1 = {{0x4b65ae55, 0x9bf30948, 0x8d7d3, 0x0}};
  // 910
  s21_decimal dec_2 = {{0x38e, 0x0, 0x0, 0x0}};
  // 11747932803372814462367.882418
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
  // -85.117649952851689
  s21_decimal dec_1 = {{0x398e46e9, 0x12e660d, 0x0, 0x800f0000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -21.27941248821292225
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

// START_TEST(s21_div_239) {
//   // -91588759607
//   s21_decimal dec_1 = {{0x531d9037, 0x15, 0x0, 0x80000000}};
//   // -9.4258018061925549784
//   s21_decimal dec_2 = {{0xe56d06d8, 0x1c17c006, 0x5, 0x80130000}};
//   // 9716813645.1615285701710728928
//   s21_decimal dec_check = {{0xb0044ee0, 0xdc4731b9, 0x39f7993f, 0x130000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_240) {
  // -79650089033985758
  s21_decimal dec_1 = {{0x7f32eede, 0x11af955, 0x0, 0x80000000}};
  // -206203344656
  s21_decimal dec_2 = {{0x2ad5710, 0x30, 0x0, 0x80000000}};
  // 386269.62703666378302743993489
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
  // -83195
  s21_decimal dec_1 = {{0x144fb, 0x0, 0x0, 0x80000000}};
  // -3311.873
  s21_decimal dec_2 = {{0x328901, 0x0, 0x0, 0x80030000}};
  // 25.120226530425532621570935842
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
  // 27284558813167
  s21_decimal dec_1 = {{0xae6f97ef, 0x18d0, 0x0, 0x0}};
  // 9927176602.72000
  s21_decimal dec_2 = {{0x1780b580, 0x386df, 0x0, 0x50000}};
  // 2748.4711821980842351914250100
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
  // -82424567372853030941271320
  s21_decimal dec_1 = {{0x382aa518, 0xc026bf99, 0x442e14, 0x80000000}};
  // 34047054722471.5613178
  s21_decimal dec_2 = {{0x840853fa, 0x74fa5ecf, 0x12, 0x70000}};
  // -2420901544780.3651995008719766
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
  // -1634543980529549398969039
  s21_decimal dec_1 = {{0x220f0acf, 0xce863a75, 0x15a20, 0x80000000}};
  // 56.7
  s21_decimal dec_2 = {{0x237, 0x0, 0x0, 0x10000}};
  // -28827936164542317442134.726631
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
  // 911
  s21_decimal dec_1 = {{0x38f, 0x0, 0x0, 0x0}};
  // 0.85
  s21_decimal dec_2 = {{0x55, 0x0, 0x0, 0x20000}};
  // 1071.7647058823529411764705882
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
  // -926171825785.2015
  s21_decimal dec_1 = {{0xd2c4de6f, 0x20e77b, 0x0, 0x80040000}};
  // 67857.165403724
  s21_decimal dec_2 = {{0x3a3d464c, 0x3db7, 0x0, 0x90000}};
  // -13648843.423901305595788879474
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
  // -5810616.6
  s21_decimal dec_1 = {{0x376a136, 0x0, 0x0, 0x80010000}};
  // 5794
  s21_decimal dec_2 = {{0x16a2, 0x0, 0x0, 0x0}};
  // -1002.8678978253365550569554712
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
  // -6243332182676857580
  s21_decimal dec_1 = {{0xa337e2ec, 0x56a4c58a, 0x0, 0x80000000}};
  // 5.91
  s21_decimal dec_2 = {{0x24f, 0x0, 0x0, 0x20000}};
  // -1056401384547691637.9018612521
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
  // -537343487420121
  s21_decimal dec_1 = {{0x7b0a6d9, 0x1e8b6, 0x0, 0x80000000}};
  // 7078816590.54151
  s21_decimal dec_2 = {{0x8ad4b847, 0x283d0, 0x0, 0x50000}};
  // -75908.660797639863853496172773
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

// START_TEST(s21_div_250) {
//   // -432527311836539529798898
//   s21_decimal dec_1 = {{0x7b8524f2, 0x5a41376b, 0x5b97, 0x80000000}};
//   // -5275276886858.3594
//   s21_decimal dec_2 = {{0x215488aa, 0xbb6a5d, 0x0, 0x80040000}};
//   // 81991395165.254922893859051086
//   s21_decimal dec_check = {{0x80e9564e, 0x2a126c46, 0x8edb146, 0x120000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_251) {
  // 288804837665584958194449510
  s21_decimal dec_1 = {{0xd179fc66, 0x9efe4824, 0xeee4cd, 0x0}};
  // 61147368269243222.7125
  s21_decimal dec_2 = {{0xae586b35, 0x25e6eaae, 0x21, 0x40000}};
  // 4723095136.2276721794268698906
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
  // -3795505219
  s21_decimal dec_1 = {{0xe23ad043, 0x0, 0x0, 0x80000000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // -421722802.11111111111111111111
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

// START_TEST(s21_div_253) {
//   // 582579844246039031281327
//   s21_decimal dec_1 = {{0x626976af, 0xb775a578, 0x7b5d, 0x0}};
//   // 5.91478534328765482352
//   s21_decimal dec_2 = {{0x36c18570, 0x1069e12f, 0x20, 0x140000}};
//   // 98495517661883527888965.834741
//   s21_decimal dec_check = {{0x4997f5, 0x7475f134, 0x3e419527, 0x60000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_254) {
  // -45044342009895215527244417
  s21_decimal dec_1 = {{0x96923281, 0xac5b1f6e, 0x254282, 0x80000000}};
  // -5849924
  s21_decimal dec_2 = {{0x594344, 0x0, 0x0, 0x80000000}};
  // 7699987557085393849.0900765548
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
  // 96678198725283057
  s21_decimal dec_1 = {{0x3c8b8cf1, 0x157784f, 0x0, 0x0}};
  // 18928201870367649
  s21_decimal dec_2 = {{0x6cb85ba1, 0x433f19, 0x0, 0x0}};
  // 5.1076272002695649065078411873
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

// START_TEST(s21_div_256) {
//   // -24.8873576169619
//   s21_decimal dec_1 = {{0x651a0093, 0xe259, 0x0, 0x800d0000}};
//   // -3
//   s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
//   // 8.2957858723206333333333333333
//   s21_decimal dec_check = {{0xdf53d555, 0x9f4e9975, 0xc0d21e4, 0x1c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_257) {
  // 264.8538625037
  s21_decimal dec_1 = {{0xa934340d, 0x268, 0x0, 0xa0000}};
  // -4.56957
  s21_decimal dec_2 = {{0x6f8fd, 0x0, 0x0, 0x80050000}};
  // -57.960346926231571023094076686
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
  // -5637043199
  s21_decimal dec_1 = {{0x4ffe73ff, 0x1, 0x0, 0x80000000}};
  // 1.88640216743567672386800
  s21_decimal dec_2 = {{0x55f6a4f0, 0x34e66592, 0x27f2, 0x170000}};
  // -2988251018.9557519661003152447
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
  // 73859738.917054
  s21_decimal dec_1 = {{0xcf8058be, 0x432c, 0x0, 0x60000}};
  // -52
  s21_decimal dec_2 = {{0x34, 0x0, 0x0, 0x80000000}};
  // -1420379.5945587307692307692308
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

// START_TEST(s21_div_260) {
//   // 70809453298683561070
//   s21_decimal dec_1 = {{0x4fa5446e, 0xd6adb69c, 0x3, 0x0}};
//   // 7091060
//   s21_decimal dec_2 = {{0x6c3374, 0x0, 0x0, 0x0}};
//   // 9985736025175.8638440515240317
//   s21_decimal dec_check = {{0x48ea017d, 0x2e645918, 0x42a8128a, 0x100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_261) {
  // -42970936.61
  s21_decimal dec_1 = {{0x20721d, 0x1, 0x0, 0x80020000}};
  // 4128.7822494314
  s21_decimal dec_2 = {{0x11fe4a6a, 0x258d, 0x0, 0xa0000}};
  // -10407.653882913731281862769006
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
  // 43526407643044497970139808
  s21_decimal dec_1 = {{0xf40392a0, 0x494e7da8, 0x240113, 0x0}};
  // -57
  s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80000000}};
  // -763621186720078911756838.73684
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
  // -94585678117870212030
  s21_decimal dec_1 = {{0x9f1793be, 0x20a3d51c, 0x5, 0x80000000}};
  // -435.98446
  s21_decimal dec_2 = {{0x299426e, 0x0, 0x0, 0x80050000}};
  // 216947361192346653.89220524053
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
  // 989328046282465561
  s21_decimal dec_1 = {{0xccff6119, 0xdbacc9d, 0x0, 0x0}};
  // 249490.995
  s21_decimal dec_2 = {{0xedeee33, 0x0, 0x0, 0x30000}};
  // 3965385789905.8263044724319609
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
  // 18636443638475069970392710760
  s21_decimal dec_1 = {{0xb2ce7e68, 0x30cf566, 0x3c37b472, 0x0}};
  // -439136913937887977936691.0213
  s21_decimal dec_2 = {{0x34aa3905, 0xe15bacd, 0xe307496, 0x80040000}};
  // -42438.799943634503130912134752
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
  // -512995.5861439896042445299
  s21_decimal dec_1 = {{0x3ca199f3, 0x76e89490, 0x43e4f, 0x80130000}};
  // 233.23520936345
  s21_decimal dec_2 = {{0x6e2e2999, 0x1536, 0x0, 0xb0000}};
  // -2199.4774611606325740711728946
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
  // 3511022389983
  s21_decimal dec_1 = {{0x793e0adf, 0x331, 0x0, 0x0}};
  // -0.123205396709440231263316125
  s21_decimal dec_2 = {{0x3da2289d, 0xf04faba8, 0x65e9c1, 0x801b0000}};
  // -28497310050980.735998363282897
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

// START_TEST(s21_div_268) {
//   // 776622302547508756220436
//   s21_decimal dec_1 = {{0xbd100a14, 0xc78585a6, 0xa474, 0x0}};
//   // 91
//   s21_decimal dec_2 = {{0x5b, 0x0, 0x0, 0x0}};
//   // 8534311017005590727697.0989011
//   s21_decimal dec_check = {{0xd85f15d3, 0xa6f7c44d, 0x13c22a88, 0x70000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_269) {
  // 3329528
  s21_decimal dec_1 = {{0x32cdf8, 0x0, 0x0, 0x0}};
  // -4810.2044543952154426160
  s21_decimal dec_2 = {{0x7ce67b30, 0x9df7a12b, 0xa2f, 0x80130000}};
  // -692.18014152344795924506143544
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

// START_TEST(s21_div_270) {
//   // -48025214360743281863667554.1
//   s21_decimal dec_1 = {{0xaa1cd9d5, 0xdf3b639d, 0x18d4158, 0x80010000}};
//   // -53463.384397600378
//   s21_decimal dec_2 = {{0x3382567a, 0xbdf0aa, 0x0, 0x800c0000}};
//   // 898282345980678693122.43544138
//   s21_decimal dec_check = {{0x8d45304a, 0x1690230f, 0x22402c93, 0x80000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_271) {
//   // 91.2674
//   s21_decimal dec_1 = {{0xded22, 0x0, 0x0, 0x40000}};
//   // 0.1
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
//   // 912.674
//   s21_decimal dec_check = {{0xded22, 0x0, 0x0, 0x30000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_272) {
  // 90613259.039583981801528
  s21_decimal dec_1 = {{0x28b41038, 0x2794dee1, 0x1330, 0xf0000}};
  // -6.422835
  s21_decimal dec_2 = {{0x620133, 0x0, 0x0, 0x80060000}};
  // -14107984.875772767290694529752
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
  // -238771989451096328087785616
  s21_decimal dec_1 = {{0x425bd090, 0x7c0d519f, 0xc581ef, 0x80000000}};
  // -7.28
  s21_decimal dec_2 = {{0x2d8, 0x0, 0x0, 0x80020000}};
  // 32798350199326418693377145.055
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
  // -32851481591480790863845806
  s21_decimal dec_1 = {{0xefac19ae, 0x62b2eaa9, 0x1b2c92, 0x80000000}};
  // -12172517.8794
  s21_decimal dec_2 = {{0x5762d3aa, 0x1c, 0x0, 0x80040000}};
  // 2698823851972036304.3762501980
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
  // -1189
  s21_decimal dec_1 = {{0x4a5, 0x0, 0x0, 0x80000000}};
  // -73
  s21_decimal dec_2 = {{0x49, 0x0, 0x0, 0x80000000}};
  // 16.287671232876712328767123288
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
  // -8289965460538120
  s21_decimal dec_1 = {{0xfe79c308, 0x1d73ad, 0x0, 0x80000000}};
  // 79406259125
  s21_decimal dec_2 = {{0x7cfb5bb5, 0x12, 0x0, 0x0}};
  // -104399.39561298556513507083060
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
  // -575007299333391.8885320682
  s21_decimal dec_1 = {{0x246197ea, 0x14e184cd, 0x4c1a0, 0x800a0000}};
  // -226474522098797
  s21_decimal dec_2 = {{0x3570bc6d, 0xcdfa, 0x0, 0x80000000}};
  // 2.5389491674588955645731827393
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
  // 66778382
  s21_decimal dec_1 = {{0x3faf50e, 0x0, 0x0, 0x0}};
  // 18844064.77553823264
  s21_decimal dec_2 = {{0x130a6e20, 0x1a26c1b5, 0x0, 0xb0000}};
  // 3.5437355366495043194122813949
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
  // 84116.41
  s21_decimal dec_1 = {{0x8059f9, 0x0, 0x0, 0x20000}};
  // -3149.8062288329027445156588
  s21_decimal dec_2 = {{0x27c56aec, 0x60cb74ed, 0x1a0df9, 0x80160000}};
  // -26.705264987417223272746117755
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
  // -30784093474559567
  s21_decimal dec_1 = {{0x4c48964f, 0x6d5df8, 0x0, 0x80000000}};
  // -763867
  s21_decimal dec_2 = {{0xba7db, 0x0, 0x0, 0x80000000}};
  // 40300331699.837232135960841351
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
  // -9404355857427597943770
  s21_decimal dec_1 = {{0xe818e3da, 0xcfa7b1ea, 0x1fd, 0x80000000}};
  // 72911.50470
  s21_decimal dec_2 = {{0xb2962086, 0x1, 0x0, 0x50000}};
  // -128983154251479848.33414088079
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
  // 7435605299258521373770098.9
  s21_decimal dec_1 = {{0x52f40e7d, 0xb5a85f56, 0x3d8181, 0x10000}};
  // 5749164
  s21_decimal dec_2 = {{0x57b9ac, 0x0, 0x0, 0x0}};
  // 1293336787619647199.7963702027
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
  // -42068
  s21_decimal dec_1 = {{0xa454, 0x0, 0x0, 0x80000000}};
  // 99.05
  s21_decimal dec_2 = {{0x26b1, 0x0, 0x0, 0x20000}};
  // -424.71479050984351337708228168
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
  // 2843944763709682228687041901
  s21_decimal dec_1 = {{0xe858756d, 0x8fe8724d, 0x93074ba, 0x0}};
  // 62814525
  s21_decimal dec_2 = {{0x3be793d, 0x0, 0x0, 0x0}};
  // 45275272935832631524.110735550
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

// START_TEST(s21_div_285) {
//   // -8444263518629701182890158
//   s21_decimal dec_1 = {{0x423520ae, 0x714e0823, 0x6fc24, 0x80000000}};
//   // 9015463.586801755
//   s21_decimal dec_2 = {{0x3093a85b, 0x200784, 0x0, 0x90000}};
//   // -936642185654405418.09657864265
//   s21_decimal dec_check = {{0xfd516049, 0xa3f071ea, 0x2ea539c6, 0x800b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_286) {
//   // 860540220326569964098
//   s21_decimal dec_1 = {{0xad95f242, 0xa665030c, 0x2e, 0x0}};
//   // -8.63
//   s21_decimal dec_2 = {{0x35f, 0x0, 0x0, 0x80020000}};
//   // -99714973386624561309.154113557
//   s21_decimal dec_check = {{0xe97d7815, 0xc170fd75, 0x42324af2, 0x80090000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_287) {
  // -77457293198248297323733.766
  s21_decimal dec_1 = {{0x1962a306, 0x472c4719, 0x401238, 0x80030000}};
  // 46559145
  s21_decimal dec_2 = {{0x2c66fa9, 0x0, 0x0, 0x0}};
  // -1663632207985097.1774445979624
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

// START_TEST(s21_div_288) {
//   // 4817093903853055.11056154
//   s21_decimal dec_1 = {{0xd718d31a, 0x84b46db3, 0x6601, 0x80000}};
//   // -53809
//   s21_decimal dec_2 = {{0xd231, 0x0, 0x0, 0x80000000}};
//   // -89522085596.332492901959523500
//   s21_decimal dec_check = {{0xf192dcac, 0x72e7bf33, 0x2142ef00, 0x80120000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_289) {
  // 90391484537.01876261017
  s21_decimal dec_1 = {{0x49c92099, 0x3625b2e, 0x1ea, 0xb0000}};
  // 548.8
  s21_decimal dec_2 = {{0x1570, 0x0, 0x0, 0x10000}};
  // 164707515.55579220592232142857
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
  // 3663572514942532559613.8622958
  s21_decimal dec_1 = {{0x330d4fee, 0xe122e14f, 0x76605c8f, 0x70000}};
  // -2882080852731825.8417420
  s21_decimal dec_2 = {{0x71cdff0c, 0x6110b068, 0x61a, 0x80070000}};
  // -1271155.3568908233461912549706
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

// START_TEST(s21_div_291) {
//   // -77826224085896
//   s21_decimal dec_1 = {{0x5470db88, 0x46c8, 0x0, 0x80000000}};
//   // -89
//   s21_decimal dec_2 = {{0x59, 0x0, 0x0, 0x80000000}};
//   // 874451956021.30337078651685393
//   s21_decimal dec_check = {{0xd4208a11, 0x4331dad5, 0x1a8cf870, 0x110000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_292) {
  // -3170936568646898265704
  s21_decimal dec_1 = {{0xa66bae68, 0xe595b8d7, 0xab, 0x80000000}};
  // 672.5219264780845139791
  s21_decimal dec_2 = {{0x53fb474f, 0x932a7994, 0x16c, 0x130000}};
  // -4714993584302458637.6655686898
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
  // 4210632754610495529113916175
  s21_decimal dec_1 = {{0x4f54930f, 0x11e23f5, 0xd9af42b, 0x0}};
  // -3119470416863
  s21_decimal dec_2 = {{0x4eed13df, 0x2d6, 0x0, 0x80000000}};
  // -1349790891379822.5903268605576
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
  // -789606675329327847611
  s21_decimal dec_1 = {{0x51c858bb, 0xcdfe6fb2, 0x2a, 0x80000000}};
  // -51
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80000000}};
  // 15482483829986820541.392156863
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
  // -17809847064563060753298
  s21_decimal dec_1 = {{0x32b2c392, 0x7947489b, 0x3c5, 0x80000000}};
  // -848409769
  s21_decimal dec_2 = {{0x3291b4a9, 0x0, 0x0, 0x80000000}};
  // 20992034409923.279364429383415
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
  // 891633707213877
  s21_decimal dec_1 = {{0xa6636435, 0x32aef, 0x0, 0x0}};
  // -50.8496910689
  s21_decimal dec_2 = {{0x64c71961, 0x76, 0x0, 0x800a0000}};
  // -17534692708471.653689818942278
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

// START_TEST(s21_div_297) {
//   // -682
//   s21_decimal dec_1 = {{0x2aa, 0x0, 0x0, 0x80000000}};
//   // 7
//   s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x0}};
//   // -97.428571428571428571428571429
//   s21_decimal dec_check = {{0x94924925, 0x40356052, 0x3acf0680, 0x801b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_298) {
  // 988858369986512
  s21_decimal dec_1 = {{0x87e04fd0, 0x3835c, 0x0, 0x0}};
  // 7568781.193352508
  s21_decimal dec_2 = {{0x3269953c, 0x1ae3c4, 0x0, 0x90000}};
  // 130649617.78192297182647989611
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
  // -4930384720774072462753
  s21_decimal dec_1 = {{0x8156da1, 0x46d53d3f, 0x10b, 0x80000000}};
  // 870819.67
  s21_decimal dec_2 = {{0x530c3ef, 0x0, 0x0, 0x20000}};
  // -5661774636732852.4661747707192
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
  // 206625013879767382169704593
  s21_decimal dec_1 = {{0x6de75891, 0x7268fe31, 0xaaea8c, 0x0}};
  // -711911854209.0
  s21_decimal dec_2 = {{0x8c88250a, 0x679, 0x0, 0x80010000}};
  // -290239602920149.30426961732879
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

// START_TEST(s21_div_301) {
//   // -8002467064594510403783464
//   s21_decimal dec_1 = {{0x8fbacb28, 0x9bdc8910, 0x69e96, 0x80000000}};
//   // 913277565166144.403051
//   s21_decimal dec_2 = {{0x45b3366b, 0x8245b2c4, 0x31, 0x60000}};
//   // -8762360283.2493682084539177796
//   s21_decimal dec_check = {{0xb12e9b44, 0x998e9f68, 0x1b208ba3, 0x80130000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_302) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 0.415
  s21_decimal dec_2 = {{0x19f, 0x0, 0x0, 0x30000}};
  // -2.4096385542168674698795180723
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

// START_TEST(s21_div_303) {
//   // -3991363110390890985936342
//   s21_decimal dec_1 = {{0x3ed3d5d6, 0x3a4f586e, 0x34d34, 0x80000000}};
//   // -445299168141
//   s21_decimal dec_2 = {{0xade6138d, 0x67, 0x0, 0x80000000}};
//   // 8963329365859.1824392319486123
//   s21_decimal dec_check = {{0xfec548ab, 0x95755f21, 0x219eec39, 0x100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_304) {
  // 4825019830148739955929494917
  s21_decimal dec_1 = {{0x622db585, 0x1b4d191b, 0xf9729b1, 0x0}};
  // -219012684446
  s21_decimal dec_2 = {{0xfe2c5a9e, 0x32, 0x0, 0x80000000}};
  // -22030777999702578.723989085518
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
  // -4902508133905
  s21_decimal dec_1 = {{0x74417e11, 0x475, 0x0, 0x80000000}};
  // 773499225.16552180
  s21_decimal dec_2 = {{0x3f00c9f4, 0x112cd58, 0x0, 0x80000}};
  // -6338.0905557544777664754848100
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
  // -293196439251709924427003.9566
  s21_decimal dec_1 = {{0xd6f6b20e, 0x336b7fe2, 0x979439c, 0x80040000}};
  // 85846709.44542
  s21_decimal dec_2 = {{0xc6431d1e, 0x7ce, 0x0, 0x50000}};
  // -3415348603875372.1973061969385
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
  // -620576402446607171
  s21_decimal dec_1 = {{0x37d1e343, 0x89cbaf3, 0x0, 0x80000000}};
  // 506833811.51985395
  s21_decimal dec_2 = {{0x41946ef3, 0xb41044, 0x0, 0x80000}};
  // -1224417922.2883152869365817807
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
  // -1297958209033
  s21_decimal dec_1 = {{0x34568609, 0x12e, 0x0, 0x80000000}};
  // -62943.7
  s21_decimal dec_2 = {{0x99abd, 0x0, 0x0, 0x80010000}};
  // 20620939.173149973706661667490
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
  // -357370872466422092
  s21_decimal dec_1 = {{0x426eb94c, 0x4f5a2ea, 0x0, 0x80000000}};
  // -700185.88373
  s21_decimal dec_2 = {{0x4d6eded5, 0x10, 0x0, 0x80050000}};
  // 510394283533.18323760145880655
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

// START_TEST(s21_div_310) {
//   // -916274681588179340528040717
//   s21_decimal dec_1 = {{0x14a9bb0d, 0x4c0e5f3, 0x2f5ecb6, 0x80000000}};
//   // 92186795810430978071905262
//   s21_decimal dec_2 = {{0xb2bec3ee, 0x36f081c0, 0x4c4150, 0x0}};
//   // -9.9393267065314623030070504574
//   s21_decimal dec_check = {{0x2bc66c7e, 0x21de9551, 0x41282efc, 0x801c0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_311) {
  // 5280034155827230620897
  s21_decimal dec_1 = {{0xab973ce1, 0x3b3191e7, 0x11e, 0x0}};
  // 496275975
  s21_decimal dec_2 = {{0x1d949207, 0x0, 0x0, 0x0}};
  // 10639310427685.383361338416594
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
  // -626794813
  s21_decimal dec_1 = {{0x255c213d, 0x0, 0x0, 0x80000000}};
  // 978
  s21_decimal dec_2 = {{0x3d2, 0x0, 0x0, 0x0}};
  // -640894.49182004089979550102249
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
  // 47367307121180864377514
  s21_decimal dec_1 = {{0x102772aa, 0xc96feff7, 0xa07, 0x0}};
  // -78672605582.9937
  s21_decimal dec_2 = {{0xef17e1b1, 0x2cb85, 0x0, 0x80040000}};
  // -602081331489.80183421342049631
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
  // -80531
  s21_decimal dec_1 = {{0x13a93, 0x0, 0x0, 0x80000000}};
  // 137.0857657883636690135532438
  s21_decimal dec_2 = {{0xc94bc396, 0x8ad39d09, 0x46df266, 0x190000}};
  // -587.44975845505150052049516351
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
  // -424107
  s21_decimal dec_1 = {{0x678ab, 0x0, 0x0, 0x80000000}};
  // 902
  s21_decimal dec_2 = {{0x386, 0x0, 0x0, 0x0}};
  // -470.18514412416851441241685144
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
  // 80509054829120139384265007
  s21_decimal dec_1 = {{0xfb57192f, 0x9b86b6f2, 0x429874, 0x0}};
  // -29890173300.48124895432167141
  s21_decimal dec_2 = {{0xbd9e4ee5, 0x2449b990, 0x9a8750a, 0x80110000}};
  // -2693495752593174.0706856215723
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
  // -3439259176517295363
  s21_decimal dec_1 = {{0xc2d0dd03, 0x2fbab3ff, 0x0, 0x80000000}};
  // 60854790
  s21_decimal dec_2 = {{0x3a09206, 0x0, 0x0, 0x0}};
  // -56515833453.986043875921681761
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
  // -78474205783
  s21_decimal dec_1 = {{0x456d5a57, 0x12, 0x0, 0x80000000}};
  // -5970.1289181
  s21_decimal dec_2 = {{0xe67960dd, 0xd, 0x0, 0x80070000}};
  // 13144474.241600548394697152026
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

// START_TEST(s21_div_319) {
//   // 3721198701285420726145
//   s21_decimal dec_1 = {{0x3a6e7781, 0xba018710, 0xc9, 0x0}};
//   // 4.655164412
//   s21_decimal dec_2 = {{0x15782bfc, 0x1, 0x0, 0x90000}};
//   // 799369983945783078852.29639876
//   s21_decimal dec_check = {{0xe99388c4, 0x11900976, 0x24a55d6, 0x80000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_320) {
  // 88416.2168765170546166
  s21_decimal dec_1 = {{0xfef775f6, 0xee3707ff, 0x2f, 0x100000}};
  // 700
  s21_decimal dec_2 = {{0x2bc, 0x0, 0x0, 0x0}};
  // 126.30888125216722088085714286
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
  // 2844000627873
  s21_decimal dec_1 = {{0x2ba5aca1, 0x296, 0x0, 0x0}};
  // 774.0555496271
  s21_decimal dec_2 = {{0x3d0f8b4f, 0x70a, 0x0, 0xa0000}};
  // 3674155723.3755286287227507453
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
  // -3044319845895396607805
  s21_decimal dec_1 = {{0x130b473d, 0x86cc258, 0xa5, 0x80000000}};
  // -304420.04240
  s21_decimal dec_2 = {{0x167c1f10, 0x7, 0x0, 0x80050000}};
  // 10000392293143562.770244854286
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
  // -159959320112228031248114251
  s21_decimal dec_1 = {{0xf5c2a24b, 0x1e665731, 0x8450b4, 0x80000000}};
  // 61197867034506.0822
  s21_decimal dec_2 = {{0xb80881d6, 0x87e2f5b, 0x0, 0x40000}};
  // -2613805478253.6104495387863172
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
  // 418292283157531770996061.7
  s21_decimal dec_1 = {{0x1ffdb5a9, 0xb3791ac4, 0x375c4, 0x10000}};
  // 978631371921618115
  s21_decimal dec_2 = {{0x3970f4c3, 0xd94cc0c, 0x0, 0x0}};
  // 427425.78580552004803817448514
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
  // -225139
  s21_decimal dec_1 = {{0x36f73, 0x0, 0x0, 0x80000000}};
  // -737.3287150432
  s21_decimal dec_2 = {{0xba295360, 0x6b4, 0x0, 0x800a0000}};
  // 305.34413675562484134658583974
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
  // -8289173947555270458
  s21_decimal dec_1 = {{0x91744f3a, 0x73090fc9, 0x0, 0x80000000}};
  // 36
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x0}};
  // -230254831876535290.5
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

// START_TEST(s21_div_327) {
//   // -893632992682446
//   s21_decimal dec_1 = {{0x2516a1ce, 0x32cc1, 0x0, 0x80000000}};
//   // -89.8
//   s21_decimal dec_2 = {{0x382, 0x0, 0x0, 0x80010000}};
//   // 9951369628980.4677060133630290
//   s21_decimal dec_check = {{0x6c0fb152, 0x7933bc08, 0x418bccdd, 0x100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_328) {
  // 2829466713032793961
  s21_decimal dec_1 = {{0xfe1c9f69, 0x274448fb, 0x0, 0x0}};
  // -3.98
  s21_decimal dec_2 = {{0x18e, 0x0, 0x0, 0x80020000}};
  // -710921284681606522.86432160804
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
  // -7160308529638358840327960
  s21_decimal dec_1 = {{0xed693f18, 0x1a69ad97, 0x5ec41, 0x80000000}};
  // -999
  s21_decimal dec_2 = {{0x3e7, 0x0, 0x0, 0x80000000}};
  // 7167476005644002843171.1311311
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

// START_TEST(s21_div_330) {
//   // 7379615556087058654179161676
//   s21_decimal dec_1 = {{0x8f88f64c, 0xe69f7563, 0x17d84660, 0x0}};
//   // -839933768963287
//   s21_decimal dec_2 = {{0x51ef14d7, 0x2fbea, 0x0, 0x80000000}};
//   // -8785949355501.6445741541480436
//   s21_decimal dec_check = {{0x4991d7f4, 0x4a8f60e8, 0x1be3ab71, 0x80100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_331) {
  // -9910214005375410102
  s21_decimal dec_1 = {{0x9e809fb6, 0x89882721, 0x0, 0x80000000}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 4955107002687705051
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
  // -318445302164734.4876
  s21_decimal dec_1 = {{0xb73594ec, 0x2c317326, 0x0, 0x80040000}};
  // 759
  s21_decimal dec_2 = {{0x2f7, 0x0, 0x0, 0x0}};
  // -419559027885.02567536231884058
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
  // -416133822421365
  s21_decimal dec_1 = {{0xb4aa1975, 0x17a78, 0x0, 0x80000000}};
  // 806726
  s21_decimal dec_2 = {{0xc4f46, 0x0, 0x0, 0x0}};
  // -515830433.65574556912756003897
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
  // -9420
  s21_decimal dec_1 = {{0x24cc, 0x0, 0x0, 0x80000000}};
  // -1.31
  s21_decimal dec_2 = {{0x83, 0x0, 0x0, 0x80020000}};
  // 7190.8396946564885496183206107
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
  // 28186443164435223513779
  s21_decimal dec_1 = {{0xaabd8ab3, 0xfd7a2fe0, 0x5f7, 0x0}};
  // -60693951966133
  s21_decimal dec_2 = {{0x69726bb5, 0x3733, 0x0, 0x80000000}};
  // -464402831.77083532503142784231
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
  // 487191681673683.19
  s21_decimal dec_1 = {{0x485e567f, 0xad15d3, 0x0, 0x20000}};
  // 853
  s21_decimal dec_2 = {{0x355, 0x0, 0x0, 0x0}};
  // 571150857765.16200468933177022
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
  // 4247130433103537806
  s21_decimal dec_1 = {{0x6be3268e, 0x3af0d6a0, 0x0, 0x0}};
  // 7869697421354
  s21_decimal dec_2 = {{0x4e84f02a, 0x728, 0x0, 0x0}};
  // 539681.54119613013014932914711
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

// START_TEST(s21_div_338) {
//   // 35496632719801075409311811
//   s21_decimal dec_1 = {{0x48975843, 0x50c6fea5, 0x1d5cb4, 0x0}};
//   // -360883639938020598246641
//   s21_decimal dec_2 = {{0xaaf26cf1, 0x8a941028, 0x4c6b, 0x80000000}};
//   // -98.360326685624733816007244508
//   s21_decimal dec_check = {{0x1c9d3adc, 0xf268ee44, 0x3dd1c159, 0x801b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_339) {
  // 301123770144863277796
  s21_decimal dec_1 = {{0x4ef3d2e4, 0x52ee8986, 0x10, 0x0}};
  // 76820.73696028314641783
  s21_decimal dec_2 = {{0xbbd52577, 0x72304d2a, 0x1a0, 0x110000}};
  // 3919824022262977.6977548570460
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
  // 8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // 6.4
  s21_decimal dec_2 = {{0x40, 0x0, 0x0, 0x10000}};
  // 1.25
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
  // -3555174485713941385
  s21_decimal dec_1 = {{0xcf82f389, 0x3156845b, 0x0, 0x80000000}};
  // 757840389958891
  s21_decimal dec_2 = {{0x773d6ceb, 0x2b140, 0x0, 0x0}};
  // -4691.1916187349048277231214907
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

// START_TEST(s21_div_342) {
//   // 22177459273159518145567
//   s21_decimal dec_1 = {{0x35d74c1f, 0x3e12ebb9, 0x4b2, 0x0}};
//   // 223578
//   s21_decimal dec_2 = {{0x3695a, 0x0, 0x0, 0x0}};
//   // 99193387869824035.216197479180
//   s21_decimal dec_check = {{0xa330eb0c, 0x3ba78854, 0x4082d8eb, 0xc0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_343) {
  // 482583953004036599332269
  s21_decimal dec_1 = {{0x9d003dad, 0xedb301ce, 0x6630, 0x0}};
  // -692
  s21_decimal dec_2 = {{0x2b4, 0x0, 0x0, 0x80000000}};
  // -697375654630110692676.68930636
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
  // 8366754905039724373890053413
  s21_decimal dec_1 = {{0x6c683525, 0x3c21d0a3, 0x1b08d144, 0x0}};
  // -4014584428077519097514097
  s21_decimal dec_2 = {{0xdb034871, 0xed4549a, 0x3521f, 0x80000000}};
  // -2084.0899114049389733795151789
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 38.822371146802774
  s21_decimal dec_2 = {{0xa98b2656, 0x89ecbd, 0x0, 0xf0000}};
  // 0
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
  // 2932099858
  s21_decimal dec_1 = {{0xaec44b12, 0x0, 0x0, 0x0}};
  // 5992.2242092130
  s21_decimal dec_2 = {{0xbbf43c62, 0x367f, 0x0, 0xa0000}};
  // 489317.44801736863440723442411
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
  // -8595022735
  s21_decimal dec_1 = {{0x4da38f, 0x2, 0x0, 0x80000000}};
  // 15759
  s21_decimal dec_2 = {{0x3d8f, 0x0, 0x0, 0x0}};
  // -545404.06973792753347293610001
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
  // 9244203363
  s21_decimal dec_1 = {{0x26ff5963, 0x2, 0x0, 0x0}};
  // 1376164881
  s21_decimal dec_2 = {{0x52069c11, 0x0, 0x0, 0x0}};
  // 6.7173661315079003240455458186
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
  // 0.94
  s21_decimal dec_1 = {{0x5e, 0x0, 0x0, 0x20000}};
  // -0.6349189835508655050672258056
  s21_decimal dec_2 = {{0x1cd33c08, 0xa8b8b385, 0x1483ed3e, 0x801c0000}};
  // -1.4805038506534013939788620198
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
  // -343680920926193075222958064
  s21_decimal dec_1 = {{0x79774ff0, 0xe353d4d, 0x11c4944, 0x80000000}};
  // -884852784965422683932570
  s21_decimal dec_2 = {{0x755a479a, 0xf730df12, 0xbb5f, 0x80000000}};
  // 388.40463268658081351850638310
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
  // 916555238.024336193
  s21_decimal dec_1 = {{0x376d341, 0xcb84222, 0x0, 0x90000}};
  // 2269989
  s21_decimal dec_2 = {{0x22a325, 0x0, 0x0, 0x0}};
  // 403.77078392200851766242039058
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
  // 58879790460.60
  s21_decimal dec_1 = {{0xe6e644ac, 0x55a, 0x0, 0x20000}};
  // 3579.766158566481132
  s21_decimal dec_2 = {{0xd451dcec, 0x31ade25a, 0x0, 0xf0000}};
  // 16447943.204250647735908448649
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
  // -73863540854112570757559901
  s21_decimal dec_1 = {{0x1783365d, 0x92b50b9d, 0x3d1936, 0x80000000}};
  // -37495830108804624
  s21_decimal dec_2 = {{0x42319610, 0x853642, 0x0, 0x80000000}};
  // 1969913471.4387406862345221215
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
  // 33274555603039470170325
  s21_decimal dec_1 = {{0x276730d5, 0xd138d8d0, 0x70b, 0x0}};
  // 743708984.4836263437098385538
  s21_decimal dec_2 = {{0xc3358082, 0x564a168e, 0x1807d108, 0x130000}};
  // 44741365637989.075434161133240
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
  // 77554461462.39616313011498846
  s21_decimal dec_1 = {{0xe0386f5e, 0x4721d6f, 0x190f279a, 0x110000}};
  // -5490063708.16523
  s21_decimal dec_2 = {{0x81b6420b, 0x1f351, 0x0, 0x80050000}};
  // -14.126331785012151143015011207
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
  // 9787.40
  s21_decimal dec_1 = {{0xeef34, 0x0, 0x0, 0x20000}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -1957.48
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

// START_TEST(s21_div_357) {
//   // 511405034384756886290672471
//   s21_decimal dec_1 = {{0x49a5ab57, 0x770a2a93, 0x1a7063a, 0x0}};
//   // -5746448044719819044.1200122663
//   s21_decimal dec_2 = {{0x29387b27, 0x1484f01e, 0xb9ad810f, 0x800a0000}};
//   // -88994980.969969177738795644702
//   s21_decimal dec_check = {{0x7525771e, 0x65b7c51c, 0x1f8eec41, 0x80150000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_358) {
  // 625551362139168312
  s21_decimal dec_1 = {{0x49111e38, 0x8ae67a6, 0x0, 0x0}};
  // 98230546318.67057135
  s21_decimal dec_2 = {{0x95b103ef, 0x88528024, 0x0, 0x80000}};
  // 6368195.8981456917349231267562
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
  // 3752346355802008
  s21_decimal dec_1 = {{0x379c9f98, 0xd54bd, 0x0, 0x0}};
  // 215953.6295533458480
  s21_decimal dec_2 = {{0xaed5b430, 0x1df836d1, 0x0, 0xd0000}};
  // 17375704050.739681283366699214
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
  // -469637633880474259585
  s21_decimal dec_1 = {{0x78a01081, 0x75880bc4, 0x19, 0x80000000}};
  // -161331681185828
  s21_decimal dec_2 = {{0xf58c5024, 0x92ba, 0x0, 0x80000000}};
  // 2911006.8799167081951116467293
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
  // -4061763335123
  s21_decimal dec_1 = {{0xb3f5f3d3, 0x3b1, 0x0, 0x80000000}};
  // -0.86047194851
  s21_decimal dec_2 = {{0x8cffee3, 0x14, 0x0, 0x800b0000}};
  // 4720390179082.9804118933113551
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
  // -812146264.0529625776999524
  s21_decimal dec_1 = {{0x64a54c64, 0x5f36e078, 0x6b7c9, 0x80100000}};
  // -4932953
  s21_decimal dec_2 = {{0x4b4559, 0x0, 0x0, 0x80000000}};
  // 164.63693533122301747045885092
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
  // -20314335936794446745
  s21_decimal dec_1 = {{0x9095cb99, 0x19eb04e7, 0x1, 0x80000000}};
  // 4.733
  s21_decimal dec_2 = {{0x127d, 0x0, 0x0, 0x30000}};
  // -4292063371391178268.5400380308
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
  // 759404.42
  s21_decimal dec_1 = {{0x486c25a, 0x0, 0x0, 0x20000}};
  // 0.72133
  s21_decimal dec_2 = {{0x119c5, 0x0, 0x0, 0x50000}};
  // 1052783.6357838991862254446647
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

// START_TEST(s21_div_365) {
//   // -83859765373477643499885
//   s21_decimal dec_1 = {{0x49de396d, 0xc078b19, 0x11c2, 0x80000000}};
//   // -917461.7228
//   s21_decimal dec_2 = {{0x22d98c8c, 0x2, 0x0, 0x80040000}};
//   // 91404102524894615.145556239221
//   s21_decimal dec_check = {{0xa006375, 0x943480f6, 0x2757b396, 0xc0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_366) {
  // -58656977254052
  s21_decimal dec_1 = {{0x244af6a4, 0x3559, 0x0, 0x80000000}};
  // -9.0926736731904
  s21_decimal dec_2 = {{0x87d7ef00, 0x52b2, 0x0, 0x800d0000}};
  // 6451015329737.5161042159592450
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
  // -23928211758624261462907
  s21_decimal dec_1 = {{0x941adb7b, 0x26a5395e, 0x511, 0x80000000}};
  // 6191.77565
  s21_decimal dec_2 = {{0x24e7e65d, 0x0, 0x0, 0x50000}};
  // -3864515304042752495.8703889732
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
  // 36593681626
  s21_decimal dec_1 = {{0x852744da, 0x8, 0x0, 0x0}};
  // 23375182
  s21_decimal dec_2 = {{0x164ad4e, 0x0, 0x0, 0x0}};
  // 1565.4929072210004610873190207
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
  // -89490938159
  s21_decimal dec_1 = {{0xd613592f, 0x14, 0x0, 0x80000000}};
  // -4.6867564514055
  s21_decimal dec_2 = {{0x3488cb07, 0x2aa0, 0x0, 0x800d0000}};
  // 19094428969.562260928510642422
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
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // 0.095
  s21_decimal dec_2 = {{0x5f, 0x0, 0x0, 0x30000}};
  // 63.157894736842105263157894737
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
  // 66805499066239552580203438181
  s21_decimal dec_1 = {{0x9eb5e065, 0x146b59be, 0xd7dc36b1, 0x0}};
  // -5.4387
  s21_decimal dec_2 = {{0xd473, 0x0, 0x0, 0x80040000}};
  // -12283357983753388232519432618
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
  // 8426691228111239967
  s21_decimal dec_1 = {{0x83787b1f, 0x74f19f06, 0x0, 0x0}};
  // -626990.5857258
  s21_decimal dec_2 = {{0xd382eaea, 0x5b3, 0x0, 0x80070000}};
  // -13439900725712.747377662278539
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
  // -9206999500545.967614
  s21_decimal dec_1 = {{0xd53dc5fe, 0x7fc5d543, 0x0, 0x80060000}};
  // -223
  s21_decimal dec_2 = {{0xdf, 0x0, 0x0, 0x80000000}};
  // 41286993275.990886161434977578
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
  // 79228162514264337592675194986
  s21_decimal dec_1 = {{0xcc37d86a, 0xffffffff, 0xffffffff, 0x0}};
  // 6151475
  s21_decimal dec_2 = {{0x5ddd33, 0x0, 0x0, 0x0}};
  // 12879539055960454621481.058606
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
  // 1294348358678748335
  s21_decimal dec_1 = {{0x76a81caf, 0x11f672f9, 0x0, 0x0}};
  // -786964
  s21_decimal dec_2 = {{0xc0214, 0x0, 0x0, 0x80000000}};
  // -1644736428450.0286353632440620
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

// START_TEST(s21_div_376) {
//   // 97029103599
//   s21_decimal dec_1 = {{0x97629fef, 0x16, 0x0, 0x0}};
//   // -98.24611660097960090028331
//   s21_decimal dec_2 = {{0xabcc492b, 0x43e9bba0, 0x82071, 0x80170000}};
//   // -987612609.59634239424490671243
//   s21_decimal dec_check = {{0x26c8c8b, 0x7dfe7310, 0x3f1d667c, 0x80140000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_377) {
  // -835115037711179661.715411329
  s21_decimal dec_1 = {{0xba5b9181, 0xe8788110, 0x2b2ca7c, 0x80090000}};
  // 6279.75053198303668181
  s21_decimal dec_2 = {{0xbbeba7d5, 0xae78fba, 0x22, 0x110000}};
  // -132985384285236.05165143226009
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
  // -275381915866952426902
  s21_decimal dec_1 = {{0xf034e596, 0xedb11971, 0xe, 0x80000000}};
  // -437536817371079.0233050
  s21_decimal dec_2 = {{0xbd460bda, 0x306e5c4b, 0xed, 0x80070000}};
  // 629391.41332510648119645191943
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
  // -2327513216460229113737371
  s21_decimal dec_1 = {{0x8816f09b, 0xbe89b50b, 0x1ecde, 0x80000000}};
  // 516.46213181
  s21_decimal dec_2 = {{0x65aac3d, 0xc, 0x0, 0x80000}};
  // -4506648354455718935621.7071066
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
  // 40684
  s21_decimal dec_1 = {{0x9eec, 0x0, 0x0, 0x0}};
  // -3267.8
  s21_decimal dec_2 = {{0x7fa6, 0x0, 0x0, 0x80010000}};
  // -12.449966338209192729053185629
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
  // -7095
  s21_decimal dec_1 = {{0x1bb7, 0x0, 0x0, 0x80000000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // 1773.75
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
  // 3918024618.91661008
  s21_decimal dec_1 = {{0x632d0cd0, 0x56ff643, 0x0, 0x80000}};
  // 588481851
  s21_decimal dec_2 = {{0x2313853b, 0x0, 0x0, 0x0}};
  // 6.6578512357836674898577288495
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
  // -4391763284791702630
  s21_decimal dec_1 = {{0x5f9cb466, 0x3cf2ad70, 0x0, 0x80000000}};
  // 403.719
  s21_decimal dec_2 = {{0x62907, 0x0, 0x0, 0x30000}};
  // -10878267519714709.067445426150
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
  // -5976.762334458
  s21_decimal dec_1 = {{0x92cbbcfa, 0x56f, 0x0, 0x80090000}};
  // 2.886630769530088809
  s21_decimal dec_2 = {{0xf8dad69, 0x280f5f64, 0x0, 0x120000}};
  // -2070.4976880125718449736936943
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

// START_TEST(s21_div_385) {
//   // 708580565596410707925339126
//   s21_decimal dec_1 = {{0x18550bf6, 0x6e16905f, 0x24a1fc5, 0x0}};
//   // 807.36936838717712
//   s21_decimal dec_2 = {{0xf8866110, 0x11ed5d0, 0x0, 0xe0000}};
//   // 877641130988026464778946.48696
//   s21_decimal dec_check = {{0xc0090378, 0x663661b4, 0x1b94c5d8, 0x50000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_386) {
  // -7787897853460262968
  s21_decimal dec_1 = {{0xee86b038, 0x6c142bd5, 0x0, 0x80000000}};
  // 6439641364
  s21_decimal dec_2 = {{0x7fd52114, 0x1, 0x0, 0x0}};
  // -1209368257.2134405228967965241
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

// START_TEST(s21_div_387) {
//   // 5615171075569
//   s21_decimal dec_1 = {{0x6246fdf1, 0x51b, 0x0, 0x0}};
//   // -60919.7894518
//   s21_decimal dec_2 = {{0xd7062b76, 0x8d, 0x0, 0x80070000}};
//   // -92173185.857967345050560721840
//   s21_decimal dec_check = {{0x2e4b73b0, 0x9b1d7915, 0x29d3df51, 0x80150000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_388) {
  // -69983084399057058177738653
  s21_decimal dec_1 = {{0xdffbe79d, 0x9b6d2e10, 0x39e37e, 0x80000000}};
  // -201727876920797915
  s21_decimal dec_2 = {{0x6d286adb, 0x2ccae6f, 0x0, 0x80000000}};
  // 346918261.70625742434918847907
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
  // -77421031416350623
  s21_decimal dec_1 = {{0x93b7479f, 0x1130e04, 0x0, 0x80000000}};
  // 4368998399391
  s21_decimal dec_2 = {{0x3c98fd9f, 0x3f9, 0x0, 0x0}};
  // -17720.544696730132636420432375
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
  // 42312233859
  s21_decimal dec_1 = {{0xda017383, 0x9, 0x0, 0x0}};
  // 8032732.8440
  s21_decimal dec_2 = {{0xb3e1c2b8, 0x12, 0x0, 0x40000}};
  // 5267.4767953480316194118406062
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
  // -919130959951946259.7
  s21_decimal dec_1 = {{0x13fed4c5, 0x7f8e1762, 0x0, 0x80010000}};
  // -2768
  s21_decimal dec_2 = {{0xad0, 0x0, 0x0, 0x80000000}};
  // 332055982641599.08226156069364
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
  // -83913026091502400
  s21_decimal dec_1 = {{0xe0364b40, 0x12a1e73, 0x0, 0x80000000}};
  // -26.23422602198329
  s21_decimal dec_2 = {{0x2c4cbd39, 0x951fd, 0x0, 0x800e0000}};
  // 3198608795288508.0450485596174
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
  // 741623528298.28178139
  s21_decimal dec_1 = {{0x411820db, 0x5359af8, 0x4, 0x80000}};
  // 0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
  // 7416235282982.8178139
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
  // -2055042696186886776157084
  s21_decimal dec_1 = {{0x805bf39c, 0x16794320, 0x1b32c, 0x80000000}};
  // 52256.222767911192
  s21_decimal dec_2 = {{0xfb629118, 0xb9a6c1, 0x0, 0xc0000}};
  // -39326277088837353376.707984637
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
  // 9529521837280870033392147
  s21_decimal dec_1 = {{0x3fb60213, 0x69f7bc5f, 0x7e1f4, 0x0}};
  // 8463449644329327859
  s21_decimal dec_2 = {{0x38a7dcf3, 0x7574369c, 0x0, 0x0}};
  // 1125961.8994325594893013637535
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
  // 893779684064728425.5
  s21_decimal dec_1 = {{0x4163d61f, 0x7c096edf, 0x0, 0x10000}};
  // -14638.1
  s21_decimal dec_2 = {{0x23bcd, 0x0, 0x0, 0x80010000}};
  // -61058449120085.832553405155041
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
  // -7907187077727.3503264
  s21_decimal dec_1 = {{0xfcfa4e20, 0x4957b787, 0x4, 0x80070000}};
  // -299781858362.116696
  s21_decimal dec_2 = {{0x9c7ca58, 0x4290a03, 0x0, 0x80060000}};
  // 26.376469613367965375218919839
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
  // 1414988839783198211992233594
  s21_decimal dec_1 = {{0xdec0a67a, 0xb4efd197, 0x492738a, 0x0}};
  // -383
  s21_decimal dec_2 = {{0x17f, 0x0, 0x0, 0x80000000}};
  // -3694487832332110214078938.8877
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
  // -9957369825197558812.0082609
  s21_decimal dec_1 = {{0x53bfb8b1, 0xff948c15, 0x525d8c, 0x80070000}};
  // 0.22236350
  s21_decimal dec_2 = {{0x1534cbe, 0x0, 0x0, 0x80000}};
  // -44779695521960927994.064947260
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
  // -3360295871018655245212947554
  s21_decimal dec_1 = {{0xefb99462, 0x2d78d1fb, 0xadb9254, 0x80000000}};
  // -453982724581329923547711
  s21_decimal dec_2 = {{0x77b1223f, 0x73eb8f28, 0x6022, 0x80000000}};
  // 7401.8144063027364060722097303
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
  // 79228162514264337593473298926
  s21_decimal dec_1 = {{0xfbc9f1ee, 0xffffffff, 0xffffffff, 0x0}};
  // 40650354773744375338
  s21_decimal dec_2 = {{0xbaa3562a, 0x3423124a, 0x2, 0x0}};
  // 1949015278.1012615219733228374
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
  // 1408543517630844755171226
  s21_decimal dec_1 = {{0x3f86d79a, 0x4c0e45db, 0x12a45, 0x0}};
  // -38246064
  s21_decimal dec_2 = {{0x24796b0, 0x0, 0x0, 0x80000000}};
  // -36828456848026106.821638587437
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
  // -2826116012430148524263749979
  s21_decimal dec_1 = {{0xc896395b, 0x4c5b715, 0x921b558, 0x80000000}};
  // -9874366051276565
  s21_decimal dec_2 = {{0xde5715, 0x2314af, 0x0, 0x80000000}};
  // 286207337033.52897830474322540
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
  // 941343313005376779056
  s21_decimal dec_1 = {{0x4ed53330, 0x7c343ba, 0x33, 0x0}};
  // 0.2189591544070025904639547251
  s21_decimal dec_2 = {{0xc7fd9773, 0x72637daa, 0x713300b, 0x1c0000}};
  // 4299173129138059140673.2589718
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

// START_TEST(s21_div_405) {
//   // 266303
//   s21_decimal dec_1 = {{0x4103f, 0x0, 0x0, 0x0}};
//   // 31
//   s21_decimal dec_2 = {{0x1f, 0x0, 0x0, 0x0}};
//   // 8590.4193548387096774193548387
//   s21_decimal dec_check = {{0xd0318c63, 0x89f0948f, 0x1592488f, 0x190000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_406) {
  // 2450026
  s21_decimal dec_1 = {{0x25626a, 0x0, 0x0, 0x0}};
  // 748.449831617437
  s21_decimal dec_2 = {{0xe58839d, 0x2a8b6, 0x0, 0xc0000}};
  // 3273.4672338764149063146064222
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
  // -24195946356073
  s21_decimal dec_1 = {{0x8ec99d69, 0x1601, 0x0, 0x80000000}};
  // 7.668231
  s21_decimal dec_2 = {{0x750207, 0x0, 0x0, 0x60000}};
  // -3155349174545.3416831078771623
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
  // -171.4
  s21_decimal dec_1 = {{0x6b2, 0x0, 0x0, 0x80010000}};
  // 15.734
  s21_decimal dec_2 = {{0x3d76, 0x0, 0x0, 0x30000}};
  // -10.893606203126986144654887505
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
  // 1933976829310207
  s21_decimal dec_1 = {{0x11ea34ff, 0x6def1, 0x0, 0x0}};
  // -0.53
  s21_decimal dec_2 = {{0x35, 0x0, 0x0, 0x80020000}};
  // -3649012885490956.6037735849057
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
  // -305415.059958689365056554976
  s21_decimal dec_1 = {{0x389007e0, 0x936ae92e, 0xfca227, 0x80150000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 43630.722851241337865222139429
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

// START_TEST(s21_div_411) {
//   // -6598851424291234978.149941
//   s21_decimal dec_1 = {{0x975b3635, 0x73d7739e, 0x5755c, 0x80060000}};
//   // 7.6255
//   s21_decimal dec_2 = {{0x129df, 0x0, 0x0, 0x40000}};
//   // -865366392274766897.66571910039
//   s21_decimal dec_check = {{0x53a12397, 0x80507304, 0x179d6e24, 0x800b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_412) {
  // -2214169134906342147115700510
  s21_decimal dec_1 = {{0x77c3d11e, 0x50d7a229, 0x727848d, 0x80000000}};
  // 352.3261287781116419292572668
  s21_decimal dec_2 = {{0xf164abfc, 0x1f503d91, 0xb625f99, 0x190000}};
  // -6284430685243853013450080.1898
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
  // -77867
  s21_decimal dec_1 = {{0x1302b, 0x0, 0x0, 0x80000000}};
  // 356.4
  s21_decimal dec_2 = {{0xdec, 0x0, 0x0, 0x10000}};
  // -218.48204264870931537598204265
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
  // -75632310674
  s21_decimal dec_1 = {{0x9c097992, 0x11, 0x0, 0x80000000}};
  // -430758906
  s21_decimal dec_2 = {{0x19acdbfa, 0x0, 0x0, 0x80000000}};
  // 175.57921524204075307034975152
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

// START_TEST(s21_div_415) {
//   // -813765041096524046
//   s21_decimal dec_1 = {{0x4d30810e, 0xb4b12fe, 0x0, 0x80000000}};
//   // 899481766346379.2
//   s21_decimal dec_2 = {{0x2fa67170, 0x1ff4bd, 0x0, 0x10000}};
//   // -904.70432146942852746264177433
//   s21_decimal dec_check = {{0x139beb19, 0xf88c71a0, 0x24536331, 0x801a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_416) {
  // -56351.820699978
  s21_decimal dec_1 = {{0x6e41594a, 0x3340, 0x0, 0x80090000}};
  // 0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
  // -563518.20699978
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
  // 5015361
  s21_decimal dec_1 = {{0x4c8741, 0x0, 0x0, 0x0}};
  // 34.375742481038
  s21_decimal dec_2 = {{0xb9eb628e, 0x1f43, 0x0, 0xc0000}};
  // 145898.25958716448956096913546
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
  // 2.0583645126
  s21_decimal dec_1 = {{0xcae17fc6, 0x4, 0x0, 0xa0000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.0291822563
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
  // -430194741416221040751867317
  s21_decimal dec_1 = {{0x79c2f5b5, 0xa96973ef, 0x163d947, 0x80000000}};
  // 7.000146758056711574655496809
  s21_decimal dec_2 = {{0x5f567269, 0x23df0f55, 0x169e62bc, 0x1b0000}};
  // -61455103197814388604980045.137
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
  // 52795797994207560577253623
  s21_decimal dec_1 = {{0x726b00f7, 0xf1b53591, 0x2babf1, 0x0}};
  // -2148359968310371189594
  s21_decimal dec_2 = {{0xe922835a, 0x767bd8ad, 0x74, 0x80000000}};
  // -24574.931004569998581901875715
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 362674817285132
  s21_decimal dec_2 = {{0xcfa73c0c, 0x149d9, 0x0, 0x0}};
  // 0
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
  // 6974497428547004.20547
  s21_decimal dec_1 = {{0x15f44dc3, 0xcf0f3de1, 0x25, 0x50000}};
  // 594586.7238468447931545256800
  s21_decimal dec_2 = {{0xdb5d8360, 0xdce69d6f, 0x13364e5c, 0x160000}};
  // 11729991856.231747169832373368
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
  // 4798838
  s21_decimal dec_1 = {{0x493976, 0x0, 0x0, 0x0}};
  // -27767.430
  s21_decimal dec_2 = {{0x1a7b286, 0x0, 0x0, 0x80030000}};
  // -172.82254785552714097055435091
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
  // 7668909
  s21_decimal dec_1 = {{0x7504ad, 0x0, 0x0, 0x0}};
  // -15.0
  s21_decimal dec_2 = {{0x96, 0x0, 0x0, 0x80010000}};
  // -511260.6
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
  // -209425546885
  s21_decimal dec_1 = {{0xc2bc3e85, 0x30, 0x0, 0x80000000}};
  // -3697.982494
  s21_decimal dec_2 = {{0xdc6abc1e, 0x0, 0x0, 0x80060000}};
  // 56632379.202658280620838439264
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
  // 78890644704067565
  s21_decimal dec_1 = {{0x95afffed, 0x118469f, 0x0, 0x0}};
  // -0.46205
  s21_decimal dec_2 = {{0xb47d, 0x0, 0x0, 0x80050000}};
  // -170740492812612412.07661508495
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
  // -83478773107.248184
  s21_decimal dec_1 = {{0x7957cc38, 0x1289380, 0x0, 0x80060000}};
  // 160.983800508532
  s21_decimal dec_2 = {{0xf63e7074, 0x9269, 0x0, 0xc0000}};
  // -518553872.15078129779157210273
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
  // -17992.65910132421
  s21_decimal dec_1 = {{0x3d6e0ec5, 0x6646c, 0x0, 0x800b0000}};
  // -5523.9138603352324781
  s21_decimal dec_2 = {{0xe761faad, 0xfe98d7e3, 0x2, 0x80100000}};
  // 3.2572302096384031312683676811
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
  // 1228118871043410854807137411
  s21_decimal dec_1 = {{0xb328ec83, 0x671cf444, 0x3f7e049, 0x0}};
  // 888552747785.1119
  s21_decimal dec_2 = {{0x14f593ef, 0x1f9157, 0x0, 0x40000}};
  // 1382156404450644.7449109324053
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
  // 1201.888995397310501
  s21_decimal dec_1 = {{0x661b9825, 0x10adf7ac, 0x0, 0xf0000}};
  // -166.246806343317832527396733
  s21_decimal dec_2 = {{0x45723f7d, 0x6e28cd9b, 0x898421, 0x80180000}};
  // -7.2295463704444241229074337632
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
  // -2885.10
  s21_decimal dec_1 = {{0x466fe, 0x0, 0x0, 0x80020000}};
  // 59.32222292830
  s21_decimal dec_2 = {{0x3400a35e, 0x565, 0x0, 0xb0000}};
  // -48.634387883392124587765622555
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
  // 63536593650.7
  s21_decimal dec_1 = {{0xeec2cd7b, 0x93, 0x0, 0x10000}};
  // -11520237890
  s21_decimal dec_2 = {{0xaea8e142, 0x2, 0x0, 0x80000000}};
  // -5.5152154198006756612210895933
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
  // -8076209649242157366601
  s21_decimal dec_1 = {{0xa4e83d49, 0xcfec7e64, 0x1b5, 0x80000000}};
  // -73729218510
  s21_decimal dec_2 = {{0x2a9a97ce, 0x11, 0x0, 0x80000000}};
  // 109538793607.94756600494177678
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
  // -385854256.7826864892173769607
  s21_decimal dec_1 = {{0x767e5b87, 0xbbb88336, 0xc77b62b, 0x80130000}};
  // 99.4199150925989916512
  s21_decimal dec_2 = {{0x3a99af60, 0xe548ec46, 0x35, 0x130000}};
  // -3881055.9878602251691692575045
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

// START_TEST(s21_div_435) {
//   // 817013979
//   s21_decimal dec_1 = {{0x30b2a4db, 0x0, 0x0, 0x0}};
//   // 9833
//   s21_decimal dec_2 = {{0x2669, 0x0, 0x0, 0x0}};
//   // 83088.983931658700294925251703
//   s21_decimal dec_check = {{0xcd82f477, 0x6a76e3ff, 0xc7998bc, 0x180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_436) {
  // 9209260253436
  s21_decimal dec_1 = {{0x32afa0fc, 0x860, 0x0, 0x0}};
  // -0.29822476769807
  s21_decimal dec_2 = {{0x96225a0f, 0x1b1f, 0x0, 0x800e0000}};
  // -30880266332404.955760559191022
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
  // -9856733667769068161
  s21_decimal dec_1 = {{0x31022a81, 0x88ca270c, 0x0, 0x80000000}};
  // 78490388614640.35795895
  s21_decimal dec_2 = {{0xe85223b7, 0x7f4bba82, 0x1a9, 0x80000}};
  // -125578.86184207971511500996422
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
  // -24203811029.678
  s21_decimal dec_1 = {{0x638f02ae, 0x1603, 0x0, 0x80030000}};
  // -45332
  s21_decimal dec_2 = {{0xb114, 0x0, 0x0, 0x80000000}};
  // 533923.29986936380481778875849
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
  // -396071127138275259822011
  s21_decimal dec_1 = {{0x4273afbb, 0xf0f297e, 0x53df, 0x80000000}};
  // 3118.8824195810495
  s21_decimal dec_2 = {{0x32744bf, 0x6ece12, 0x0, 0xd0000}};
  // -126991362242978802172.79498810
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
  // 83919801114767571
  s21_decimal dec_1 = {{0x4f1130d3, 0x12a249d, 0x0, 0x0}};
  // 65913208
  s21_decimal dec_2 = {{0x3edc178, 0x0, 0x0, 0x0}};
  // 1273186416.8220665424143822586
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
  // -304499.7169
  s21_decimal dec_1 = {{0xb57ef831, 0x0, 0x0, 0x80040000}};
  // 0.42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x20000}};
  // -724999.32595238095238095238095
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
  // -24411166205878.444696570662730
  s21_decimal dec_1 = {{0xbfbf8f4a, 0xaa78e02e, 0x4ee07183, 0x800f0000}};
  // -608.1
  s21_decimal dec_2 = {{0x17c1, 0x0, 0x0, 0x80010000}};
  // 40143341894.225365394788131442
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
  // -820962422
  s21_decimal dec_1 = {{0x30eee476, 0x0, 0x0, 0x80000000}};
  // -63090397
  s21_decimal dec_2 = {{0x3c2aedd, 0x0, 0x0, 0x80000000}};
  // 13.012478301570998198030042512
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
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 294665353304272951600347724
  s21_decimal dec_2 = {{0x2f69fa4c, 0xcf78ac43, 0xf3bdd0, 0x0}};
  // 0
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
  // -9215.7774325
  s21_decimal dec_1 = {{0x750809f5, 0x15, 0x0, 0x80070000}};
  // 0.05723305798
  s21_decimal dec_2 = {{0x5522b746, 0x1, 0x0, 0xb0000}};
  // -161021.92959391473703673661367
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

// START_TEST(s21_div_446) {
//   // 73755276391702740716018420
//   s21_decimal dec_1 = {{0x309cdaf4, 0x8b788394, 0x3d0249, 0x0}};
//   // 8720835409815.2
//   s21_decimal dec_2 = {{0xc6f7abe8, 0x4f50, 0x0, 0x10000}};
//   // 8457363649896.6629985417100450
//   s21_decimal dec_check = {{0xe10efca2, 0x5be40dc7, 0x1145ac25, 0x100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_447) {
  // -9167183987790
  s21_decimal dec_1 = {{0x66bec44e, 0x856, 0x0, 0x80000000}};
  // -0.652
  s21_decimal dec_2 = {{0x28c, 0x0, 0x0, 0x80030000}};
  // 14060098140782.208588957055215
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
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 0.201628
  s21_decimal dec_2 = {{0x3139c, 0x0, 0x0, 0x60000}};
  // 44.636657607078381970758029639
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
  // 582790491624616
  s21_decimal dec_1 = {{0x7c3b54a8, 0x2120b, 0x0, 0x0}};
  // -7828.521376489450950625
  s21_decimal dec_2 = {{0x1dc6cfe1, 0x628efaa2, 0x1a8, 0x80120000}};
  // -74444516863.024410352274148206
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
  // 838204186941754
  s21_decimal dec_1 = {{0x9ecfd93a, 0x2fa57, 0x0, 0x0}};
  // 69193164.6362025837785389100
  s21_decimal dec_2 = {{0x6dee182c, 0xb5b951ef, 0x23c5a39, 0x130000}};
  // 12113973.849133601367839610592
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
  // -57380619988924016694
  s21_decimal dec_1 = {{0x477ea836, 0x1c50e9dd, 0x3, 0x80000000}};
  // -22.4237286793246060846
  s21_decimal dec_2 = {{0x44d2b12e, 0x27eae047, 0xc, 0x80130000}};
  // 2558924111574306582.6698915169
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
  // 997711370048412076.124
  s21_decimal dec_1 = {{0x27e8485c, 0x1606d4f5, 0x36, 0x30000}};
  // -520061797838238
  s21_decimal dec_2 = {{0x52b8ad9e, 0x1d8fe, 0x0, 0x80000000}};
  // -1918.4477194741845201280926163
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

// START_TEST(s21_div_453) {
//   // 5915520129540629381267041
//   s21_decimal dec_1 = {{0xfc403e61, 0xfd21704e, 0x4e4a8, 0x0}};
//   // 62516388.333569181605008483021
//   s21_decimal dec_2 = {{0x4ecba2cd, 0x5c3348f6, 0xca00582a, 0x150000}};
//   // 94623510526186228.392692731704
//   s21_decimal dec_check = {{0xfac2cf38, 0x8e8ffb7, 0x31bebbc0, 0xc0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_454) {
  // -94
  s21_decimal dec_1 = {{0x5e, 0x0, 0x0, 0x80000000}};
  // 0.7257
  s21_decimal dec_2 = {{0x1c59, 0x0, 0x0, 0x40000}};
  // -129.53010886041063800468513160
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

// START_TEST(s21_div_455) {
//   // -48.38
//   s21_decimal dec_1 = {{0x12e6, 0x0, 0x0, 0x80020000}};
//   // -0.61
//   s21_decimal dec_2 = {{0x3d, 0x0, 0x0, 0x80020000}};
//   // 79.311475409836065573770491803
//   s21_decimal dec_check = {{0x5e29f79b, 0x1e6627da, 0x44ea31, 0x1b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_456) {
//   // -8163342289938216
//   s21_decimal dec_1 = {{0x3d5f2728, 0x1d0084, 0x0, 0x80000000}};
//   // -995.30401425376446748
//   s21_decimal dec_2 = {{0xff98891c, 0x654304c2, 0x5, 0x80110000}};
//   // 8201858098662.1800635543971349
//   s21_decimal dec_check = {{0xee5de615, 0x7e61f4d8, 0x9042e18, 0x100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_457) {
  // 52638441179116055444872263114
  s21_decimal dec_1 = {{0xd86875ca, 0x21e52de0, 0xaa157f7e, 0x0}};
  // 9831093506
  s21_decimal dec_2 = {{0x49fa9502, 0x2, 0x0, 0x0}};
  // 5354281407962437443.7185078600
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
  // -73305167010264224
  s21_decimal dec_1 = {{0x37d8f4a0, 0x1046ea9, 0x0, 0x80000000}};
  // -0.311
  s21_decimal dec_2 = {{0x137, 0x0, 0x0, 0x80030000}};
  // 235707932508888180.06430868167
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
  // -7882603309715
  s21_decimal dec_1 = {{0x4fc52a93, 0x72b, 0x0, 0x80000000}};
  // 194971
  s21_decimal dec_2 = {{0x2f99b, 0x0, 0x0, 0x0}};
  // -40429619.326540870180693539039
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
  // 9622
  s21_decimal dec_1 = {{0x2596, 0x0, 0x0, 0x0}};
  // 90.92756287706093368
  s21_decimal dec_2 = {{0xdebd738, 0x7e2ff5ab, 0x0, 0x110000}};
  // 105.82049815862186080075907043
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
  // 947840010832
  s21_decimal dec_1 = {{0xafaaca50, 0xdc, 0x0, 0x0}};
  // 824769041491
  s21_decimal dec_2 = {{0x810d453, 0xc0, 0x0, 0x0}};
  // 1.1492187062677751688578747127
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
  // -108805.05099890560
  s21_decimal dec_1 = {{0x174af80, 0x26a7c3, 0x0, 0x800b0000}};
  // 0.4207
  s21_decimal dec_2 = {{0x106f, 0x0, 0x0, 0x40000}};
  // -258628.59757286807701449964345
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
  // 5345332247256218
  s21_decimal dec_1 = {{0x25cddc9a, 0x12fd8d, 0x0, 0x0}};
  // -8669135417477
  s21_decimal dec_2 = {{0x70bcb085, 0x7e2, 0x0, 0x80000000}};
  // -616.59346518915992578556934029
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
  // -650456956747605471684042.554
  s21_decimal dec_1 = {{0x9c4d9f3a, 0x47dc29eb, 0x21a0b9e, 0x80030000}};
  // 92386.3959568
  s21_decimal dec_2 = {{0x1a954810, 0xd7, 0x0, 0x70000}};
  // -7040614042913417667.4442652491
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

// START_TEST(s21_div_465) {
//   // 7324247830253230074
//   s21_decimal dec_1 = {{0x992b57fa, 0x65a4f498, 0x0, 0x0}};
//   // -8.75
//   s21_decimal dec_2 = {{0x36b, 0x0, 0x0, 0x80020000}};
//   // -837056894886083437.02857142857
//   s21_decimal dec_check = {{0xc2655249, 0xa5b62b8a, 0xe77b937, 0x800b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_466) {
  // 8844.7387703
  s21_decimal dec_1 = {{0x97e00837, 0x14, 0x0, 0x70000}};
  // 86.8
  s21_decimal dec_2 = {{0x364, 0x0, 0x0, 0x10000}};
  // 101.89791210023041474654377880
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
  // -272893052376909368
  s21_decimal dec_1 = {{0x8990638, 0x3c982c9, 0x0, 0x80000000}};
  // -92.3648430169948
  s21_decimal dec_2 = {{0xa893df5c, 0x3480d, 0x0, 0x800d0000}};
  // 2954512165702463.4865272252294
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
  // -90566
  s21_decimal dec_1 = {{0x161c6, 0x0, 0x0, 0x80000000}};
  // -2349.3
  s21_decimal dec_2 = {{0x5bc5, 0x0, 0x0, 0x80010000}};
  // 38.550206444472821691567701017
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
  // 9397
  s21_decimal dec_1 = {{0x24b5, 0x0, 0x0, 0x0}};
  // 0.2216512
  s21_decimal dec_2 = {{0x21d240, 0x0, 0x0, 0x70000}};
  // 42395.439320878930499812317732
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
  // 243627256429284
  s21_decimal dec_1 = {{0xe413bae4, 0xdd93, 0x0, 0x0}};
  // 78407047993
  s21_decimal dec_2 = {{0x416c9b39, 0x12, 0x0, 0x0}};
  // 3107.2111840128769838151557356
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
  // 656985136167718452
  s21_decimal dec_1 = {{0x1ffd0e34, 0x91e1480, 0x0, 0x0}};
  // -19975989899
  s21_decimal dec_2 = {{0xa6a96a8b, 0x4, 0x0, 0x80000000}};
  // -32888739.906732091004247658886
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
  // 2335056
  s21_decimal dec_1 = {{0x23a150, 0x0, 0x0, 0x0}};
  // 0.34
  s21_decimal dec_2 = {{0x22, 0x0, 0x0, 0x20000}};
  // 6867811.7647058823529411764706
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
  // -14472389077422942110672601338
  s21_decimal dec_1 = {{0x565c0fa, 0xf09b72c6, 0x2ec34797, 0x80000000}};
  // 3999206.06888699203474333
  s21_decimal dec_2 = {{0xf8d39d, 0xbd528716, 0x54af, 0x110000}};
  // -3618815541918476992515.2916655
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
  // 10442.163650331785061135794
  s21_decimal dec_1 = {{0x59a2f5b2, 0xd364ce9e, 0x8a336, 0x150000}};
  // 793
  s21_decimal dec_2 = {{0x319, 0x0, 0x0, 0x0}};
  // 13.167923897013600329301127364
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
  // 762037684.6371719419514567
  s21_decimal dec_1 = {{0xa14fcec7, 0x74e3b82c, 0x64dad, 0x100000}};
  // 0.38638724652179020894
  s21_decimal dec_2 = {{0xbb425c5e, 0x1838535a, 0x2, 0x140000}};
  // 1972212311.6043298898261073042
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
  // 12234372423117383962575754
  s21_decimal dec_1 = {{0x20f1c38a, 0xa8732615, 0xa1eba, 0x0}};
  // -1154.675012283178
  s21_decimal dec_2 = {{0xb9f02b2a, 0x41a2b, 0x0, 0x800c0000}};
  // -10595511544781717502298.869183
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

// START_TEST(s21_div_477) {
//   // 555606177542465
//   s21_decimal dec_1 = {{0x24d8f141, 0x1f952, 0x0, 0x0}};
//   // -67.32
//   s21_decimal dec_2 = {{0x1a4c, 0x0, 0x0, 0x80020000}};
//   // -8253211193441.2507427213309566
//   s21_decimal dec_check = {{0xec7a767e, 0xf49162e6, 0xaacf680, 0x80100000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_478) {
  // 1196523229712519
  s21_decimal dec_1 = {{0x46129087, 0x4403b, 0x0, 0x0}};
  // -7562810820034.7704
  s21_decimal dec_2 = {{0x1c510838, 0x10caf5d, 0x0, 0x80040000}};
  // -158.21144521330469096215675412
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
  // 183049554338433998748103.71
  s21_decimal dec_1 = {{0x2bbb9203, 0x9f57a625, 0xf2439, 0x20000}};
  // -413058026794404
  s21_decimal dec_2 = {{0x90f56da4, 0x177ac, 0x0, 0x80000000}};
  // -443156996.02551315266647780733
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
  // 498741477317664600033795603
  s21_decimal dec_1 = {{0xc72f1e13, 0xa92ba304, 0x19c8c9d, 0x0}};
  // -35215981369816094129.7
  s21_decimal dec_2 = {{0x5e9fd8f1, 0x1732fcbc, 0x13, 0x80010000}};
  // -14162362.027631579859277704444
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
  // -368321551512.05100
  s21_decimal dec_1 = {{0x641982ec, 0x82daa6, 0x0, 0x80050000}};
  // -202646075995
  s21_decimal dec_2 = {{0x2ea5ba5b, 0x2f, 0x0, 0x80000000}};
  // 1.8175607383640569664513034283
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
  // -5584872790744271148
  s21_decimal dec_1 = {{0x980e892c, 0x4d817436, 0x0, 0x80000000}};
  // -9696.313010147651955615
  s21_decimal dec_2 = {{0x11632b9f, 0xa35fdd76, 0x20d, 0x80120000}};
  // 575979012321429.45439397946582
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

// START_TEST(s21_div_483) {
//   // 5022631.3137
//   s21_decimal dec_1 = {{0xb1b8b7b1, 0xb, 0x0, 0x40000}};
//   // 63.06937451720071
//   s21_decimal dec_2 = {{0x4e6e2d87, 0x166820, 0x0, 0xe0000}};
//   // 79636.612098161742985369679317
//   s21_decimal dec_check = {{0x42a6f5d5, 0x4f84af59, 0x151dc90, 0x180000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_484) {
  // -8699101491.5901858
  s21_decimal dec_1 = {{0xfeb689a2, 0x1350ddd, 0x0, 0x80070000}};
  // -741329.53622321384181161
  s21_decimal dec_2 = {{0x8dcccda9, 0xc1666247, 0xfb2, 0x80110000}};
  // 11734.459597966014390063213920
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

// START_TEST(s21_div_485) {
//   // -549364875
//   s21_decimal dec_1 = {{0x20bea48b, 0x0, 0x0, 0x80000000}};
//   // -563549.219564
//   s21_decimal dec_2 = {{0x3626aaec, 0x83, 0x0, 0x80060000}};
//   // 974.83033589333337458881293691
//   s21_decimal dec_check = {{0x99a76d7b, 0xe6d13deb, 0x3afc134f, 0x1a0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_486) {
  // -4720816691859907690335
  s21_decimal dec_1 = {{0xac803f5f, 0xea7e0949, 0xff, 0x80000000}};
  // -9252473796285
  s21_decimal dec_2 = {{0x4269f6bd, 0x86a, 0x0, 0x80000000}};
  // 510222108.78947669373437252178
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

// START_TEST(s21_div_487) {
//   // -3681917824
//   s21_decimal dec_1 = {{0xdb759b80, 0x0, 0x0, 0x80000000}};
//   // -0.39597614653902312561113
//   s21_decimal dec_2 = {{0xf9b9d9d9, 0x974b3a91, 0x862, 0x80170000}};
//   // 9298332377.2942217055158158596
//   s21_decimal dec_check = {{0xae744504, 0xfa339e30, 0x2c7200b1, 0x130000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_488) {
  // 432267788008817
  s21_decimal dec_1 = {{0x2ff3bd71, 0x18925, 0x0, 0x0}};
  // 7.390555148
  s21_decimal dec_2 = {{0xb882ec0c, 0x1, 0x0, 0x90000}};
  // 58489217569237.059970856738677
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

// START_TEST(s21_div_489) {
//   // -7621250510722014153795275574
//   s21_decimal dec_1 = {{0xee3d8b36, 0x9ff6748, 0x18a02692, 0x80000000}};
//   // -871663532691593879.2170
//   s21_decimal dec_2 = {{0xe576b2ea, 0x879d8f1d, 0x1d8, 0x80040000}};
//   // 8743339860.9535655347868491498
//   s21_decimal dec_check = {{0xe6615eea, 0x3320554, 0x1a833654, 0x130000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_490) {
  // -4428797711473419061171511355
  s21_decimal dec_1 = {{0x85e2e03b, 0x38ff859, 0xe4f6a65, 0x80000000}};
  // -0.5864699425197
  s21_decimal dec_2 = {{0x7b5371ad, 0x555, 0x0, 0x800d0000}};
  // 7551619256812384995864144172.4
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
  // 87141093738413113238165
  s21_decimal dec_1 = {{0xe9e06295, 0xed9bb5c8, 0x1273, 0x0}};
  // -6.5
  s21_decimal dec_2 = {{0x41, 0x0, 0x0, 0x80010000}};
  // -13406322113602017421256.153846
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
  // -188398487142289949.875948
  s21_decimal dec_1 = {{0xa6805eec, 0x1a3a55f2, 0x27e5, 0x80060000}};
  // 90
  s21_decimal dec_2 = {{0x5a, 0x0, 0x0, 0x0}};
  // -2093316523803221.6652883111111
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
  // 68410693715443704312973477755
  s21_decimal dec_1 = {{0x6d83c77b, 0x60504fe2, 0xdd0bffe1, 0x0}};
  // 2172279116674.004232363990
  s21_decimal dec_2 = {{0xc446dfd6, 0x7ca3fafb, 0x1cbff, 0xc0000}};
  // 31492589138447329.226894688070
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
  // -6252366455427707965
  s21_decimal dec_1 = {{0x2d56343d, 0x56c4de2a, 0x0, 0x80000000}};
  // 348886326
  s21_decimal dec_2 = {{0x14cb9536, 0x0, 0x0, 0x0}};
  // -17920927217.502092544033955633
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
  // 281670.82568542178908605491
  s21_decimal dec_1 = {{0xea148c33, 0x9b0d29b6, 0x174c9c, 0x140000}};
  // 5.179363
  s21_decimal dec_2 = {{0x4f07e3, 0x0, 0x0, 0x60000}};
  // 54383.294950638097597340620845
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
  // 90399993500718459781
  s21_decimal dec_1 = {{0x13f1eb85, 0xe68d4b21, 0x4, 0x0}};
  // -703699598446796
  s21_decimal dec_2 = {{0xd49810cc, 0x28002, 0x0, 0x80000000}};
  // -128463.89808982284507438287909
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
  // -526951240974848309
  s21_decimal dec_1 = {{0x9c41d135, 0x7501b5c, 0x0, 0x80000000}};
  // -371608.5394
  s21_decimal dec_2 = {{0xdd7ef692, 0x0, 0x0, 0x80040000}};
  // 1418027803735.7940999996298793
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

// START_TEST(s21_div_498) {
//   // -79228162514264337591437929233
//   s21_decimal dec_1 = {{0x8278ab11, 0xffffffff, 0xffffffff, 0x80000000}};
//   // 81998700509761011166415.2
//   s21_decimal dec_2 = {{0x7054c018, 0x95a972ed, 0xada3, 0x10000}};
//   // -966212.41582765238348399445417
//   s21_decimal dec_check = {{0xe3d305a9, 0x9d31d334, 0x383337c1, 0x80170000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_499) {
  // 655078027973996271.360303
  s21_decimal dec_1 = {{0x2a8bd92f, 0xd9deaa35, 0x8ab7, 0x60000}};
  // 5450041017954801
  s21_decimal dec_2 = {{0x8ee2f1f1, 0x135cc8, 0x0, 0x0}};
  // 120.19689866844760891728359529
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
  // 46.7556711635
  s21_decimal dec_1 = {{0xdc8d3cd3, 0x6c, 0x0, 0xa0000}};
  // -9.561943274
  s21_decimal dec_2 = {{0x39efacea, 0x2, 0x0, 0x80090000}};
  // -4.8897666325457015046500264356
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

START_TEST(fail_s21_div_1) {
  // -722.12698391416
  s21_decimal dec_1 = {{0x543c6378, 0x41ad, 0x0, 0x800b0000}};
  // -72669
  s21_decimal dec_2 = {{0x11bdd, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_2) {
  // 834047800477447660
  s21_decimal dec_1 = {{0x392775ec, 0xb93220e, 0x0, 0x0}};
  // -963119317287958040499391
  s21_decimal dec_2 = {{0xc1df54bf, 0xcd84d88e, 0xcbf2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_3) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // 7268988654770702546081787
  s21_decimal dec_2 = {{0x9b0797fb, 0xaa20d97a, 0x60344, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_4) {
  // -9.63934355
  s21_decimal dec_1 = {{0x39747893, 0x0, 0x0, 0x80080000}};
  // -68565433992279631
  s21_decimal dec_2 = {{0x20faf64f, 0xf397e6, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_5) {
  // 1711880227187161102481
  s21_decimal dec_1 = {{0x51bcf891, 0xcd1c4cb2, 0x5c, 0x0}};
  // 93147041255473979611639
  s21_decimal dec_2 = {{0x8e2459f7, 0x82df9bad, 0x13b9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_6) {
  // 5115
  s21_decimal dec_1 = {{0x13fb, 0x0, 0x0, 0x0}};
  // -7941776353991
  s21_decimal dec_2 = {{0x16c22ac7, 0x739, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_7) {
  // -2153.79
  s21_decimal dec_1 = {{0x34953, 0x0, 0x0, 0x80020000}};
  // 8716006635925
  s21_decimal dec_2 = {{0x5a7ab995, 0x7ed, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_8) {
  // -0.0653370
  s21_decimal dec_1 = {{0x9f83a, 0x0, 0x0, 0x80070000}};
  // -98.25721974274853668598427
  s21_decimal dec_2 = {{0xd1c7329b, 0x749e18d0, 0x820ad, 0x80170000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_9) {
  // 2357044027.51973218
  s21_decimal dec_1 = {{0xce06e762, 0x34563e7, 0x0, 0x80000}};
  // 467988595208863620277682800
  s21_decimal dec_2 = {{0x17134270, 0x94c9290d, 0x1831c70, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_10) {
  // 64
  s21_decimal dec_1 = {{0x40, 0x0, 0x0, 0x0}};
  // -48829124783314267496812642
  s21_decimal dec_2 = {{0x46349062, 0x28958982, 0x2863f8, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_11) {
  // 49228545256553
  s21_decimal dec_1 = {{0xe9f3ec69, 0x2cc5, 0x0, 0x0}};
  // 241720970430440634
  s21_decimal dec_2 = {{0x2144e4ba, 0x35ac3f1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_12) {
  // -14.77
  s21_decimal dec_1 = {{0x5c5, 0x0, 0x0, 0x80020000}};
  // -919
  s21_decimal dec_2 = {{0x397, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_13) {
  // 318127
  s21_decimal dec_1 = {{0x4daaf, 0x0, 0x0, 0x0}};
  // -937815568907319
  s21_decimal dec_2 = {{0x33d97c37, 0x354f0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_14) {
  // 0.67
  s21_decimal dec_1 = {{0x43, 0x0, 0x0, 0x20000}};
  // -2782249495969833.74159
  s21_decimal dec_2 = {{0x3b27b14f, 0x1525958f, 0xf, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_15) {
  // -888.430233547
  s21_decimal dec_1 = {{0xda9187cb, 0xce, 0x0, 0x80090000}};
  // -25633
  s21_decimal dec_2 = {{0x6421, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_16) {
  // -0.4993697815463657264985
  s21_decimal dec_1 = {{0x5374d759, 0xb57a896b, 0x10e, 0x80160000}};
  // 619793357550434134365756482
  s21_decimal dec_2 = {{0x2232dc42, 0x3cc71df9, 0x200ae59, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_17) {
  // 387.543324742722047393
  s21_decimal dec_1 = {{0x9bcccda1, 0x23e788f, 0x15, 0x120000}};
  // 1530023331569949247125757727
  s21_decimal dec_2 = {{0xb79a9f1f, 0x887916, 0x4f19b0b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_18) {
  // 6252750.07105511319324
  s21_decimal dec_1 = {{0xdd9e71c, 0xe56f121d, 0x21, 0xe0000}};
  // 2111213046079
  s21_decimal dec_2 = {{0x8e1a893f, 0x1eb, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_19) {
  // 37308533631.95
  s21_decimal dec_1 = {{0xa8307dfb, 0x364, 0x0, 0x20000}};
  // 38692242514805936646907558272
  s21_decimal dec_2 = {{0x6c6cf980, 0xa4f95840, 0x7d05790d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_20) {
  // 563.72759884948828888551270800
  s21_decimal dec_1 = {{0x9c6a2990, 0xd031db7e, 0xb626743c, 0x1a0000}};
  // 1692857475370020175227
  s21_decimal dec_2 = {{0xaaa2fd7b, 0xc51de8b4, 0x5b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_21) {
  // 0.52304
  s21_decimal dec_1 = {{0xcc50, 0x0, 0x0, 0x50000}};
  // 674.93284213263438292701115
  s21_decimal dec_2 = {{0x2b13cfbb, 0x44c3a184, 0x37d442, 0x170000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_22) {
  // -95720
  s21_decimal dec_1 = {{0x175e8, 0x0, 0x0, 0x80000000}};
  // 7006447558951771844372944
  s21_decimal dec_2 = {{0xb5b7e9d0, 0x48827c80, 0x5cbac, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_23) {
  // 152964708446009
  s21_decimal dec_1 = {{0xdf1c2f39, 0x8b1e, 0x0, 0x0}};
  // 566665894489725169611949237
  s21_decimal dec_2 = {{0x4721c4b5, 0xb1a75e36, 0x1d4bc2b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_24) {
  // -60.545306216353836987
  s21_decimal dec_1 = {{0x93052fbb, 0x483c2338, 0x3, 0x80120000}};
  // -1987831.276959343599614
  s21_decimal dec_2 = {{0xbcd05ffe, 0xc2b35e69, 0x6b, 0x800f0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_25) {
  // 280392.3730687
  s21_decimal dec_1 = {{0xd6e0c0ff, 0x28c, 0x0, 0x70000}};
  // -8207328193018283126180
  s21_decimal dec_2 = {{0xff636da4, 0xeb8f2342, 0x1bc, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_26) {
  // 3464396.2083284172947600
  s21_decimal dec_1 = {{0x4ee44090, 0xd8dfb2b, 0x756, 0x100000}};
  // -4578614234
  s21_decimal dec_2 = {{0x10e81bda, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_27) {
  // -1.455
  s21_decimal dec_1 = {{0x5af, 0x0, 0x0, 0x80030000}};
  // -3.16332517366936031994864
  s21_decimal dec_2 = {{0x9be823f0, 0x6b8d7fb8, 0x42fc, 0x80170000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_28) {
  // -9419570082748029
  s21_decimal dec_1 = {{0x90b8167d, 0x21770c, 0x0, 0x80000000}};
  // 3487500650446433921
  s21_decimal dec_2 = {{0x2fcdae81, 0x3066175d, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_29) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -57723800509325
  s21_decimal dec_2 = {{0xde9fdb8d, 0x347f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_30) {
  // -85709
  s21_decimal dec_1 = {{0x14ecd, 0x0, 0x0, 0x80000000}};
  // 43403361769880752737889354256
  s21_decimal dec_2 = {{0xadd0210, 0x343611f3, 0x8c3e6b5c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_31) {
  // 59211054042108669409594.21
  s21_decimal dec_1 = {{0xd025abd, 0xc46328d6, 0x4e5d7, 0x20000}};
  // 93478429409918775628310
  s21_decimal dec_2 = {{0x347e9216, 0x79ced660, 0x13cb, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_32) {
  // -17.4597446574586315700
  s21_decimal dec_1 = {{0x4875c3b4, 0x7706bc9a, 0x9, 0x80130000}};
  // -332079927955533612.635407
  s21_decimal dec_2 = {{0x8bb2d50f, 0x16c680b1, 0x4652, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_33) {
  // -869676855219184348336
  s21_decimal dec_1 = {{0x8e4e2cb0, 0x2530dc13, 0x2f, 0x80000000}};
  // -4261865870409850933186288
  s21_decimal dec_2 = {{0xebe38ef0, 0x363704a0, 0x3867c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_34) {
  // 763215704605332041115
  s21_decimal dec_1 = {{0x476d9b, 0x5fbedfa6, 0x29, 0x0}};
  // 701172853331461449378156161
  s21_decimal dec_2 = {{0xcb9fce81, 0x8b2242ae, 0x243ff20, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_35) {
  // 582
  s21_decimal dec_1 = {{0x246, 0x0, 0x0, 0x0}};
  // -9008.6104934804675012397276
  s21_decimal dec_2 = {{0x90dd08dc, 0x88b7bce5, 0x4a8479, 0x80160000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_36) {
  // -306181542.3361
  s21_decimal dec_1 = {{0xe26bb181, 0x2c8, 0x0, 0x80040000}};
  // -6627938877574.667464690288
  s21_decimal dec_2 = {{0xa654a70, 0x49589cf8, 0x57b85, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_37) {
  // -0.963
  s21_decimal dec_1 = {{0x3c3, 0x0, 0x0, 0x80030000}};
  // -349697565656322
  s21_decimal dec_2 = {{0x4f2e0502, 0x13e0c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_38) {
  // -44.55
  s21_decimal dec_1 = {{0x1167, 0x0, 0x0, 0x80020000}};
  // 986203
  s21_decimal dec_2 = {{0xf0c5b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_39) {
  // 30187
  s21_decimal dec_1 = {{0x75eb, 0x0, 0x0, 0x0}};
  // -17967822887697
  s21_decimal dec_2 = {{0x75b35b11, 0x1057, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_40) {
  // 11044136.4
  s21_decimal dec_1 = {{0x6953394, 0x0, 0x0, 0x10000}};
  // 66500327812
  s21_decimal dec_2 = {{0x7bba7984, 0xf, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_41) {
  // -214
  s21_decimal dec_1 = {{0xd6, 0x0, 0x0, 0x80000000}};
  // 8266844
  s21_decimal dec_2 = {{0x7e245c, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_42) {
  // -274518723819164645409310188
  s21_decimal dec_1 = {{0x2f5a45ec, 0xd66f3400, 0xe31399, 0x80000000}};
  // 345652728381298715218968642
  s21_decimal dec_2 = {{0x46d08042, 0xf3aaf43e, 0x11deacf, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_43) {
  // 0.81904
  s21_decimal dec_1 = {{0x13ff0, 0x0, 0x0, 0x50000}};
  // 81646133.323793138799580205711
  s21_decimal dec_2 = {{0xc0dad28f, 0x3c214aeb, 0x7d0193c, 0x150000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_44) {
  // 28901
  s21_decimal dec_1 = {{0x70e5, 0x0, 0x0, 0x0}};
  // -6658265439782
  s21_decimal dec_2 = {{0x3f8bde26, 0x60e, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_45) {
  // -610.35
  s21_decimal dec_1 = {{0xee6b, 0x0, 0x0, 0x80020000}};
  // 7552964169620
  s21_decimal dec_2 = {{0x8fbf0f94, 0x6de, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_46) {
  // 861.3408009
  s21_decimal dec_1 = {{0x1662d09, 0x2, 0x0, 0x70000}};
  // 7746103
  s21_decimal dec_2 = {{0x763237, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_47) {
  // 6464645473163.545075867
  s21_decimal dec_1 = {{0xbe26e09b, 0x72fa66ae, 0x15e, 0x90000}};
  // -8483337051831573671.32114933
  s21_decimal dec_2 = {{0x8e6bcff5, 0x4ebfb6ef, 0x2bdb9a6, 0x80080000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_48) {
  // -48
  s21_decimal dec_1 = {{0x30, 0x0, 0x0, 0x80000000}};
  // -74810.5
  s21_decimal dec_2 = {{0xb6a49, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_49) {
  // 234473.9
  s21_decimal dec_1 = {{0x23c723, 0x0, 0x0, 0x10000}};
  // -125965639145954.020271504
  s21_decimal dec_2 = {{0x8d15a590, 0x9c6940af, 0x1aac, 0x80090000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_50) {
  // 9671416
  s21_decimal dec_1 = {{0x9392f8, 0x0, 0x0, 0x0}};
  // -249952032255292601964414.2483
  s21_decimal dec_2 = {{0x6fbdb393, 0x31b59ed8, 0x8138e04, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_51) {
  // 2989.76
  s21_decimal dec_1 = {{0x48fe0, 0x0, 0x0, 0x20000}};
  // 5659649545
  s21_decimal dec_2 = {{0x51576609, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_52) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -299.0698
  s21_decimal dec_2 = {{0x2da26a, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_53) {
  // 9.5
  s21_decimal dec_1 = {{0x5f, 0x0, 0x0, 0x10000}};
  // -7598025421977.45816950639
  s21_decimal dec_2 = {{0x9917d76f, 0xfa74da73, 0xa0e4, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_54) {
  // 938.1156613884218664863
  s21_decimal dec_1 = {{0x6b33679f, 0x8db36cd4, 0x1fc, 0x130000}};
  // 3269460569
  s21_decimal dec_2 = {{0xc2e00259, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_55) {
  // -339999
  s21_decimal dec_1 = {{0x5301f, 0x0, 0x0, 0x80000000}};
  // -2212131232459200106613974169
  s21_decimal dec_2 = {{0x260c2499, 0x671b9c64, 0x725d502, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_56) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -7479420
  s21_decimal dec_2 = {{0x72207c, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_57) {
  // 353.5273378745201833989168968
  s21_decimal dec_1 = {{0x6a2cdf48, 0xe0d757b8, 0xb6c4f41, 0x190000}};
  // -571.56891
  s21_decimal dec_2 = {{0x368251b, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_58) {
  // 0.61552913
  s21_decimal dec_1 = {{0x3ab3911, 0x0, 0x0, 0x80000}};
  // -669.2
  s21_decimal dec_2 = {{0x1a24, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_59) {
  // 7829325774496132735
  s21_decimal dec_1 = {{0x73a6ee7f, 0x6ca75a4f, 0x0, 0x0}};
  // 145226908348162359224
  s21_decimal dec_2 = {{0x906dbfb8, 0xdf6d9fb2, 0x7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_60) {
  // 6687408795
  s21_decimal dec_1 = {{0x8e99c29b, 0x1, 0x0, 0x0}};
  // -400486246667693501.3
  s21_decimal dec_2 = {{0xdc92c965, 0x37942131, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_61) {
  // 1.157858279675787093644235
  s21_decimal dec_1 = {{0xb44693cb, 0x9f84510b, 0xf52f, 0x180000}};
  // -6871
  s21_decimal dec_2 = {{0x1ad7, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_62) {
  // 49896994796812285
  s21_decimal dec_1 = {{0x6a3937fd, 0xb1450d, 0x0, 0x0}};
  // -87898439024038061702
  s21_decimal dec_2 = {{0x231f2686, 0xc3d5fc96, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_63) {
  // -628568740967975.3565
  s21_decimal dec_1 = {{0x671b615d, 0x573b3f65, 0x0, 0x80040000}};
  // -1659845817512039877615350
  s21_decimal dec_2 = {{0xac769ef6, 0x6c0c9327, 0x15f7c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_64) {
  // 65422188781085
  s21_decimal dec_1 = {{0x4a529e1d, 0x3b80, 0x0, 0x0}};
  // -7963471446126819036705
  s21_decimal dec_2 = {{0xeb544e21, 0xb35deff8, 0x1af, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_65) {
  // 8948600943739.2450969890013039
  s21_decimal dec_1 = {{0xcb613f6f, 0xf436e101, 0x21251793, 0x100000}};
  // 1708697697743067859272345199
  s21_decimal dec_2 = {{0xd4266f, 0xccfab894, 0x58566cf, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_66) {
  // -66802202833
  s21_decimal dec_1 = {{0x8db8b8d1, 0xf, 0x0, 0x80000000}};
  // -307637588974425037
  s21_decimal dec_2 = {{0xda60d3cd, 0x444f2c1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_67) {
  // 6.603211
  s21_decimal dec_1 = {{0x64c1cb, 0x0, 0x0, 0x60000}};
  // -5924693522.991
  s21_decimal dec_2 = {{0x7340ba2f, 0x563, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_68) {
  // -961594817957.5669171770
  s21_decimal dec_1 = {{0xdbe6a63a, 0x4816a1d8, 0x209, 0x800a0000}};
  // 71485393336138658072505
  s21_decimal dec_2 = {{0x34ddc7b9, 0x3b1ebd5f, 0xf23, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_69) {
  // 15.390142696233591870792718
  s21_decimal dec_1 = {{0xc45f240e, 0x4eab99c7, 0xcbafd, 0x180000}};
  // -9196997720
  s21_decimal dec_2 = {{0x242f0c58, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_70) {
  // -0.71478
  s21_decimal dec_1 = {{0x11736, 0x0, 0x0, 0x80050000}};
  // 5075029907335921353088383005
  s21_decimal dec_2 = {{0xd5b9381d, 0x8c51f76b, 0x1065f762, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_71) {
  // -79470822
  s21_decimal dec_1 = {{0x4bca0e6, 0x0, 0x0, 0x80000000}};
  // 508322694.19417
  s21_decimal dec_2 = {{0x4f5ca399, 0x2e3b, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_72) {
  // -48.653029168343024654327784550
  s21_decimal dec_1 = {{0x4d28a466, 0x1dac05fa, 0x9d34d7ac, 0x801b0000}};
  // 70720453291
  s21_decimal dec_2 = {{0x77447aab, 0x10, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_73) {
  // -3054663944.13
  s21_decimal dec_1 = {{0x1f37472d, 0x47, 0x0, 0x80020000}};
  // -7963069571870157689833154070
  s21_decimal dec_2 = {{0x59406616, 0x79472869, 0x19bae592, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_74) {
  // -518.314676430505062
  s21_decimal dec_1 = {{0xba830466, 0x7316c73, 0x0, 0x800f0000}};
  // 530162805673859378
  s21_decimal dec_2 = {{0x49509932, 0x75b8443, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_75) {
  // 6460.569203
  s21_decimal dec_1 = {{0x81147673, 0x1, 0x0, 0x60000}};
  // -562430
  s21_decimal dec_2 = {{0x894fe, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_76) {
  // 567.6172653030310
  s21_decimal dec_1 = {{0xeeaaeba6, 0x142a72, 0x0, 0xd0000}};
  // -374520948
  s21_decimal dec_2 = {{0x1652bc74, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_77) {
  // -58.15
  s21_decimal dec_1 = {{0x16b7, 0x0, 0x0, 0x80020000}};
  // -17385390838636635385364
  s21_decimal dec_2 = {{0xdb2a6e14, 0x76c3d7fd, 0x3ae, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_78) {
  // -301018294560.031647677
  s21_decimal dec_1 = {{0x9627bd, 0x5177d00a, 0x10, 0x80090000}};
  // 41093547780258948645591788
  s21_decimal dec_2 = {{0x8ea31aec, 0xb05d5e30, 0x21fde5, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_79) {
  // -3452642223629
  s21_decimal dec_1 = {{0xe183660d, 0x323, 0x0, 0x80000000}};
  // 39041761853376291.37526685
  s21_decimal dec_2 = {{0x99015f9d, 0xd0aa189d, 0x33abd, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_80) {
  // 56
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x0}};
  // 27211
  s21_decimal dec_2 = {{0x6a4b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_81) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -2946080338656209
  s21_decimal dec_2 = {{0xc810bbd1, 0xa7771, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_82) {
  // -0.14018807143311500
  s21_decimal dec_1 = {{0xe3f3a88c, 0x31ce07, 0x0, 0x80110000}};
  // 50952209106299.537
  s21_decimal dec_2 = {{0xa44d6a91, 0xb504c3, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_83) {
  // 0.7865965907436323480829894347
  s21_decimal dec_1 = {{0x7b731ecb, 0x46e76bde, 0x196a9312, 0x1c0000}};
  // 85636621888427519866962
  s21_decimal dec_2 = {{0xa3cf7852, 0x5eddfd41, 0x1222, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_84) {
  // -76.46148921597
  s21_decimal dec_1 = {{0x41fd88fd, 0x6f4, 0x0, 0x800b0000}};
  // -6023135.77825557422339359543
  s21_decimal dec_2 = {{0x183d8337, 0x7ad420c0, 0x1f238dc, 0x80140000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_85) {
  // -4548.53
  s21_decimal dec_1 = {{0x6f0c5, 0x0, 0x0, 0x80020000}};
  // 25336440
  s21_decimal dec_2 = {{0x1829a78, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_86) {
  // 5.84566595
  s21_decimal dec_1 = {{0x22d7c743, 0x0, 0x0, 0x80000}};
  // -705974.145601868160
  s21_decimal dec_2 = {{0xb9359180, 0x9cc1fbe, 0x0, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_87) {
  // -21308
  s21_decimal dec_1 = {{0x533c, 0x0, 0x0, 0x80000000}};
  // -19398261807243987097
  s21_decimal dec_2 = {{0x58ce0899, 0xd347856, 0x1, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_88) {
  // -355503
  s21_decimal dec_1 = {{0x56caf, 0x0, 0x0, 0x80000000}};
  // 4846971.90
  s21_decimal dec_2 = {{0x1ce3e466, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_89) {
  // -29864092492.6
  s21_decimal dec_1 = {{0x8862e0fe, 0x45, 0x0, 0x80010000}};
  // 53441386815222271
  s21_decimal dec_2 = {{0x7d6cf1ff, 0xbddca8, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_90) {
  // -770375.40452
  s21_decimal dec_1 = {{0xefcb9464, 0x11, 0x0, 0x80050000}};
  // -657423370917095403
  s21_decimal dec_2 = {{0x9a8da7eb, 0x91fa312, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_91) {
  // 758985366539267995984
  s21_decimal dec_1 = {{0x34b7f950, 0x2509b197, 0x29, 0x0}};
  // -4718690452342485485628185
  s21_decimal dec_2 = {{0x20782b19, 0xb8d40ffe, 0x3e738, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_92) {
  // -278819848.25811502026744766807
  s21_decimal dec_1 = {{0xe7e5a157, 0x11508684, 0x5a176ff2, 0x80140000}};
  // 98378038258.21651154
  s21_decimal dec_2 = {{0xe81410d2, 0x8886e674, 0x0, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_93) {
  // 189.44815739638425463888
  s21_decimal dec_1 = {{0xf98e2c50, 0x220543, 0x403, 0x140000}};
  // -817
  s21_decimal dec_2 = {{0x331, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_94) {
  // 68529316170911201
  s21_decimal dec_1 = {{0xcb114de1, 0xf3770c, 0x0, 0x0}};
  // -814283737103232850406
  s21_decimal dec_2 = {{0x9fc2d9e6, 0x2474f8a2, 0x2c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_95) {
  // -0.6263623924799374805834554
  s21_decimal dec_1 = {{0x888a1b3a, 0xbbbc7f2f, 0x52e5f, 0x80190000}};
  // 14405156
  s21_decimal dec_2 = {{0xdbce24, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_96) {
  // 0.396
  s21_decimal dec_1 = {{0x18c, 0x0, 0x0, 0x30000}};
  // -8773
  s21_decimal dec_2 = {{0x2245, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_97) {
  // -6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -7916329694530435755
  s21_decimal dec_2 = {{0x275cfaab, 0x6ddc73ea, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_98) {
  // -0.20
  s21_decimal dec_1 = {{0x14, 0x0, 0x0, 0x80020000}};
  // -161187172795790916
  s21_decimal dec_2 = {{0x30d7b644, 0x23ca6e1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_99) {
  // -7.0346
  s21_decimal dec_1 = {{0x112ca, 0x0, 0x0, 0x80040000}};
  // -827.3675203017
  s21_decimal dec_2 = {{0x5d78b1c9, 0x786, 0x0, 0x800a0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_100) {
  // 8308612010456163120611136716
  s21_decimal dec_1 = {{0xb01114cc, 0x9a91bdca, 0x1ad8b907, 0x0}};
  // 15546906598270149678997859130
  s21_decimal dec_2 = {{0x84b26b3a, 0x76b42005, 0x323c1987, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_101) {
  // -7.8
  s21_decimal dec_1 = {{0x4e, 0x0, 0x0, 0x80010000}};
  // 97.93772733
  s21_decimal dec_2 = {{0x47c11cbd, 0x2, 0x0, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_102) {
  // 4415471467958.380171954612
  s21_decimal dec_1 = {{0x3e2d09b4, 0x301a91ae, 0x3a703, 0xc0000}};
  // 9154157735796959354627680
  s21_decimal dec_2 = {{0xe2b92660, 0xe29ddcff, 0x79277, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_103) {
  // 0.1872
  s21_decimal dec_1 = {{0x750, 0x0, 0x0, 0x40000}};
  // 50274145502551448250361
  s21_decimal dec_2 = {{0x594467f9, 0x5dec6abb, 0xaa5, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_104) {
  // -984107
  s21_decimal dec_1 = {{0xf042b, 0x0, 0x0, 0x80000000}};
  // -7215163284233863994655
  s21_decimal dec_2 = {{0xf03e9d1f, 0x22814b6f, 0x187, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_105) {
  // 397570703536.49545
  s21_decimal dec_1 = {{0x47bd4f89, 0x8d3ed8, 0x0, 0x50000}};
  // 6057982266782915746
  s21_decimal dec_2 = {{0x6b361ca2, 0x541246c6, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_106) {
  // 3018723.50346810237492
  s21_decimal dec_1 = {{0x8de42234, 0x5d520740, 0x10, 0xe0000}};
  // 381596267139
  s21_decimal dec_2 = {{0xd8e8f283, 0x58, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_107) {
  // -183
  s21_decimal dec_1 = {{0xb7, 0x0, 0x0, 0x80000000}};
  // 74138712332902418119643.0574
  s21_decimal dec_2 = {{0xe0a61cee, 0x7d019403, 0x26542d4, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_108) {
  // -4597363
  s21_decimal dec_1 = {{0x462673, 0x0, 0x0, 0x80000000}};
  // -6590146136461190
  s21_decimal dec_2 = {{0xf77b4f86, 0x1769b3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_109) {
  // -3475
  s21_decimal dec_1 = {{0xd93, 0x0, 0x0, 0x80000000}};
  // 230462670241844857
  s21_decimal dec_2 = {{0xd9c0ce79, 0x332c493, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_110) {
  // 1960.39852238120961350097046
  s21_decimal dec_1 = {{0xfa08d896, 0xaf3c66bd, 0xa2290d, 0x170000}};
  // -586442873767512531228
  s21_decimal dec_2 = {{0x83d4611c, 0xca879e95, 0x1f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_111) {
  // -5156065
  s21_decimal dec_1 = {{0x4eace1, 0x0, 0x0, 0x80000000}};
  // -641498134643436
  s21_decimal dec_2 = {{0x6c7082ec, 0x24770, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_112) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -634208695093
  s21_decimal dec_2 = {{0xa9c8b335, 0x93, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_113) {
  // 7398
  s21_decimal dec_1 = {{0x1ce6, 0x0, 0x0, 0x0}};
  // 290601160
  s21_decimal dec_2 = {{0x115238c8, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_114) {
  // 36882402304610
  s21_decimal dec_1 = {{0x5a7ce262, 0x218b, 0x0, 0x0}};
  // 61154548212923.84
  s21_decimal dec_2 = {{0x48435960, 0x15b9f9, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_115) {
  // -51
  s21_decimal dec_1 = {{0x33, 0x0, 0x0, 0x80000000}};
  // 3955228027004397525354
  s21_decimal dec_2 = {{0x423b996a, 0x69d0b6dd, 0xd6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_116) {
  // -78.463755
  s21_decimal dec_1 = {{0x4ad430b, 0x0, 0x0, 0x80060000}};
  // -638.00
  s21_decimal dec_2 = {{0xf938, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_117) {
  // -0.117197078322031202157424473
  s21_decimal dec_1 = {{0xf9c76f59, 0x58a62247, 0x60f172, 0x801b0000}};
  // -8558728560.71
  s21_decimal dec_2 = {{0x45ff6007, 0xc7, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_118) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 6881261324.25238
  s21_decimal dec_2 = {{0xd9af1216, 0x271d8, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_119) {
  // 55506794395
  s21_decimal dec_1 = {{0xec76779b, 0xc, 0x0, 0x0}};
  // 402724236099268928727704
  s21_decimal dec_2 = {{0xbe49ea98, 0xb97e5fd5, 0x5547, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_120) {
  // -4437377
  s21_decimal dec_1 = {{0x43b581, 0x0, 0x0, 0x80000000}};
  // 77993788300894165380604812.945
  s21_decimal dec_2 = {{0xd016de91, 0xcf692e55, 0xfc02f317, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_121) {
  // -4126664941022
  s21_decimal dec_1 = {{0xd065ddde, 0x3c0, 0x0, 0x80000000}};
  // -884997130122591951663491175
  s21_decimal dec_2 = {{0xfd216867, 0x8e5db821, 0x2dc0d6e, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_122) {
  // -535975120657.2450383638
  s21_decimal dec_1 = {{0xde340716, 0x8d7d6d32, 0x122, 0x800a0000}};
  // -14261801574236
  s21_decimal dec_2 = {{0x959ddf5c, 0xcf8, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_123) {
  // -0.1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80010000}};
  // 57.92566414992
  s21_decimal dec_2 = {{0xafdd0e90, 0x544, 0x0, 0xb0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_124) {
  // -6.2
  s21_decimal dec_1 = {{0x3e, 0x0, 0x0, 0x80010000}};
  // 45882239148735770
  s21_decimal dec_2 = {{0x45f5bd1a, 0xa301a7, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_125) {
  // -287.5197
  s21_decimal dec_1 = {{0x2bdf3d, 0x0, 0x0, 0x80040000}};
  // -224967995306
  s21_decimal dec_2 = {{0x61232faa, 0x34, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_126) {
  // 39590090098855157
  s21_decimal dec_1 = {{0x28f7ccf5, 0x8ca6fa, 0x0, 0x0}};
  // -38134074211546472397524
  s21_decimal dec_2 = {{0xcbd03ad4, 0x4097146a, 0x813, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_127) {
  // 8.346618849354556581778438
  s21_decimal dec_1 = {{0x1d129406, 0x1d4dd606, 0x6e777, 0x180000}};
  // 1268199067.74
  s21_decimal dec_2 = {{0x870e34d6, 0x1d, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_128) {
  // -18523356.362856446113840959
  s21_decimal dec_1 = {{0xd1037f3f, 0x29179dcb, 0xf5279, 0x80120000}};
  // -99663109865122884765294581
  s21_decimal dec_2 = {{0x32731ff5, 0x2f99e85, 0x52707c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_129) {
  // 60
  s21_decimal dec_1 = {{0x3c, 0x0, 0x0, 0x0}};
  // -733517433
  s21_decimal dec_2 = {{0x2bb89679, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_130) {
  // -42
  s21_decimal dec_1 = {{0x2a, 0x0, 0x0, 0x80000000}};
  // 4765561.61515
  s21_decimal dec_2 = {{0xf4f5f1eb, 0x6e, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_131) {
  // -61694493.77631
  s21_decimal dec_1 = {{0x6fd6af5f, 0x59c, 0x0, 0x80050000}};
  // 650033326075133617208753
  s21_decimal dec_2 = {{0x137b7db1, 0x6091392b, 0x89a6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_132) {
  // 2751906224360325
  s21_decimal dec_1 = {{0x18f54b85, 0x9c6d8, 0x0, 0x0}};
  // -5315439484852168
  s21_decimal dec_2 = {{0x3251d7c8, 0x12e25d, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_133) {
  // -0.06972944
  s21_decimal dec_1 = {{0x6a6610, 0x0, 0x0, 0x80080000}};
  // -804732.022189852674
  s21_decimal dec_2 = {{0xb2020802, 0xb2afb82, 0x0, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_134) {
  // 77401.3707058699673903
  s21_decimal dec_1 = {{0x650da12f, 0xf59915ab, 0x29, 0x100000}};
  // -572321822446486345469111
  s21_decimal dec_2 = {{0x1b47ccb7, 0xa0cf481b, 0x7931, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_135) {
  // 84015
  s21_decimal dec_1 = {{0x1482f, 0x0, 0x0, 0x0}};
  // 835023005101627973
  s21_decimal dec_2 = {{0xbe5c9a45, 0xb9698ff, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_136) {
  // 297672.319577492
  s21_decimal dec_1 = {{0x3cde2d94, 0x10ebb, 0x0, 0x90000}};
  // 29743603
  s21_decimal dec_2 = {{0x1c5d9f3, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_137) {
  // 410627280413.763548
  s21_decimal dec_1 = {{0x25a7dc, 0x5b2d756, 0x0, 0x60000}};
  // 9948022038661824724400494386
  s21_decimal dec_2 = {{0xe80e5732, 0x5002b5dc, 0x2024cf9b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_138) {
  // 83253418.5229
  s21_decimal dec_1 = {{0xd6e7850d, 0xc1, 0x0, 0x40000}};
  // 83552859728956191
  s21_decimal dec_2 = {{0x1c1ccb1f, 0x128d6e2, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_139) {
  // -61
  s21_decimal dec_1 = {{0x3d, 0x0, 0x0, 0x80000000}};
  // 838982936508808232125
  s21_decimal dec_2 = {{0xf59efcbd, 0x7b3a27a1, 0x2d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_140) {
  // 2500
  s21_decimal dec_1 = {{0x9c4, 0x0, 0x0, 0x0}};
  // 107889651244
  s21_decimal dec_2 = {{0x1eb96e2c, 0x19, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_141) {
  // -8.66075333
  s21_decimal dec_1 = {{0x339f42c5, 0x0, 0x0, 0x80080000}};
  // 86661187142488969
  s21_decimal dec_2 = {{0xfb711389, 0x133e1e3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_142) {
  // -53
  s21_decimal dec_1 = {{0x35, 0x0, 0x0, 0x80000000}};
  // 85660375.2943
  s21_decimal dec_2 = {{0x718ff9ef, 0xc7, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_143) {
  // -692
  s21_decimal dec_1 = {{0x2b4, 0x0, 0x0, 0x80000000}};
  // 4297213226530279569124
  s21_decimal dec_2 = {{0xf784b6e4, 0xf3d035ea, 0xe8, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_144) {
  // 73662066196701
  s21_decimal dec_1 = {{0xc94a00dd, 0x42fe, 0x0, 0x0}};
  // -42330642771019479013
  s21_decimal dec_2 = {{0xa892b7e5, 0x4b74a752, 0x2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_145) {
  // -527949997.5252
  s21_decimal dec_1 = {{0x3ab87a54, 0x4cd, 0x0, 0x80040000}};
  // -413744587938220951322.3
  s21_decimal dec_2 = {{0x9c48c707, 0x4a98922b, 0xe0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_146) {
  // 365
  s21_decimal dec_1 = {{0x16d, 0x0, 0x0, 0x0}};
  // -149122
  s21_decimal dec_2 = {{0x24682, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_147) {
  // 817.46297
  s21_decimal dec_1 = {{0x4df5979, 0x0, 0x0, 0x50000}};
  // -96584523659505377
  s21_decimal dec_2 = {{0xcf866ee1, 0x157231c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_148) {
  // 96842.3
  s21_decimal dec_1 = {{0xec6e7, 0x0, 0x0, 0x10000}};
  // -169172716561082
  s21_decimal dec_2 = {{0x97ad22ba, 0x99dc, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_149) {
  // -376033
  s21_decimal dec_1 = {{0x5bce1, 0x0, 0x0, 0x80000000}};
  // 573475428.8869
  s21_decimal dec_2 = {{0x39fe04e5, 0x537, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_150) {
  // -9.6681576633900
  s21_decimal dec_1 = {{0x6f08162c, 0x57ee, 0x0, 0x800d0000}};
  // 5194242.0382561
  s21_decimal dec_2 = {{0xc9840361, 0x2f3d, 0x0, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_151) {
  // 27.39999325
  s21_decimal dec_1 = {{0xa351125d, 0x0, 0x0, 0x80000}};
  // 44
  s21_decimal dec_2 = {{0x2c, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_152) {
  // -4095054877607381195
  s21_decimal dec_1 = {{0xf384c8cb, 0x38d48eb6, 0x0, 0x80000000}};
  // 6813547315458186169916803567
  s21_decimal dec_2 = {{0x3fcf49ef, 0x166ebad4, 0x160408c4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_153) {
  // -199275
  s21_decimal dec_1 = {{0x30a6b, 0x0, 0x0, 0x80000000}};
  // -2092240955284609559134093
  s21_decimal dec_2 = {{0xb56b7f8d, 0x9c052fae, 0x1bb0c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_154) {
  // 5612.49797691583274010
  s21_decimal dec_1 = {{0x22ac9c1a, 0x6ce7d55f, 0x1e, 0x110000}};
  // -18707313233747251
  s21_decimal dec_2 = {{0xc7ffdd33, 0x427633, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_155) {
  // 0.120508
  s21_decimal dec_1 = {{0x1d6bc, 0x0, 0x0, 0x60000}};
  // 6.163
  s21_decimal dec_2 = {{0x1813, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_156) {
  // -5975215516.7278318072897395
  s21_decimal dec_1 = {{0xe1e81f73, 0xd2789986, 0x316d02, 0x80100000}};
  // -206013014851.460520307498205
  s21_decimal dec_2 = {{0xca9cdd, 0xe9c1b6ec, 0xaa68f3, 0x800f0000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_157) {
  // 3254
  s21_decimal dec_1 = {{0xcb6, 0x0, 0x0, 0x0}};
  // 8474626.0
  s21_decimal dec_2 = {{0x50d2014, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_158) {
  // -87.0255703879
  s21_decimal dec_1 = {{0x9f483747, 0xca, 0x0, 0x800a0000}};
  // 7667239880756.613544
  s21_decimal dec_2 = {{0x7c34d1a8, 0x6a67820c, 0x0, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_159) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // 64414200653471
  s21_decimal dec_2 = {{0x998c669f, 0x3a95, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_160) {
  // 93797988799
  s21_decimal dec_1 = {{0xd6cbb9bf, 0x15, 0x0, 0x0}};
  // -39397060501530735
  s21_decimal dec_2 = {{0xf463686f, 0x8bf76a, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_161) {
  // -85361833343002970602.19
  s21_decimal dec_1 = {{0x92b9df7b, 0xbf574be8, 0x1ce, 0x80020000}};
  // 383435325830290236423
  s21_decimal dec_2 = {{0xb29c6407, 0xc93bed50, 0x14, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_162) {
  // 8814645471793873192974038
  s21_decimal dec_1 = {{0xd29376d6, 0xe3756b42, 0x74a92, 0x0}};
  // 152404676954766944434088675
  s21_decimal dec_2 = {{0x26d76ae3, 0x17b25f3b, 0x7e10f2, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_163) {
  // 7.4603851912683835397
  s21_decimal dec_1 = {{0xe35dd005, 0xb56200b, 0x4, 0x130000}};
  // 7.87916649146916466917466
  s21_decimal dec_2 = {{0xbabd005a, 0xc112dcc, 0xa6d9, 0x170000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_164) {
  // 304728027883339.7322588
  s21_decimal dec_1 = {{0x85f1535c, 0x3182546a, 0xa5, 0x70000}};
  // -39632272897869222803914
  s21_decimal dec_2 = {{0xb43c79ca, 0x78460bd4, 0x864, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_165) {
  // 368.6990
  s21_decimal dec_1 = {{0x38424e, 0x0, 0x0, 0x40000}};
  // -896729404278965
  s21_decimal dec_2 = {{0x159a08b5, 0x32f92, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_166) {
  // 9051.69631676
  s21_decimal dec_1 = {{0xc05079bc, 0xd2, 0x0, 0x80000}};
  // -2490288602834044786996.46791
  s21_decimal dec_2 = {{0x7715af47, 0x9108f32b, 0xcdfde9, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
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
  // tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  // tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, s21_div_18);
  tcase_add_test(tc, s21_div_19);
  tcase_add_test(tc, s21_div_20);
  tcase_add_test(tc, s21_div_21);
  tcase_add_test(tc, s21_div_22);
  tcase_add_test(tc, s21_div_23);
  tcase_add_test(tc, s21_div_24);
  tcase_add_test(tc, s21_div_25);
  tcase_add_test(tc, s21_div_26);
  // tcase_add_test(tc, s21_div_27);
  tcase_add_test(tc, s21_div_28);
  tcase_add_test(tc, s21_div_29);
  tcase_add_test(tc, s21_div_30);
  tcase_add_test(tc, s21_div_31);
  tcase_add_test(tc, s21_div_32);
  tcase_add_test(tc, s21_div_33);
  tcase_add_test(tc, s21_div_34);
  // tcase_add_test(tc, s21_div_35);
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
  // tcase_add_test(tc, s21_div_50);
  tcase_add_test(tc, s21_div_51);
  tcase_add_test(tc, s21_div_52);
  tcase_add_test(tc, s21_div_53);
  // tcase_add_test(tc, s21_div_54);
  // tcase_add_test(tc, s21_div_55);
  tcase_add_test(tc, s21_div_56);
  tcase_add_test(tc, s21_div_57);
  tcase_add_test(tc, s21_div_58);
  tcase_add_test(tc, s21_div_59);
  // tcase_add_test(tc, s21_div_60);
  tcase_add_test(tc, s21_div_61);
  // tcase_add_test(tc, s21_div_62);
  tcase_add_test(tc, s21_div_63);
  tcase_add_test(tc, s21_div_64);
  tcase_add_test(tc, s21_div_65);
  tcase_add_test(tc, s21_div_66);
  // tcase_add_test(tc, s21_div_67);
  // tcase_add_test(tc, s21_div_68);
  tcase_add_test(tc, s21_div_69);
  tcase_add_test(tc, s21_div_70);
  tcase_add_test(tc, s21_div_71);
  tcase_add_test(tc, s21_div_72);
  tcase_add_test(tc, s21_div_73);
  // tcase_add_test(tc, s21_div_74);
  // tcase_add_test(tc, s21_div_75);
  // tcase_add_test(tc, s21_div_76);
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
  // tcase_add_test(tc, s21_div_94);
  tcase_add_test(tc, s21_div_95);
  tcase_add_test(tc, s21_div_96);
  tcase_add_test(tc, s21_div_97);
  tcase_add_test(tc, s21_div_98);
  tcase_add_test(tc, s21_div_99);
  // tcase_add_test(tc, s21_div_100);
  tcase_add_test(tc, s21_div_101);
  // tcase_add_test(tc, s21_div_102);
  tcase_add_test(tc, s21_div_103);
  tcase_add_test(tc, s21_div_104);
  tcase_add_test(tc, s21_div_105);
  tcase_add_test(tc, s21_div_106);
  tcase_add_test(tc, s21_div_107);
  tcase_add_test(tc, s21_div_108);
  tcase_add_test(tc, s21_div_109);
  tcase_add_test(tc, s21_div_110);
  // tcase_add_test(tc, s21_div_111);
  // tcase_add_test(tc, s21_div_112);
  tcase_add_test(tc, s21_div_113);
  tcase_add_test(tc, s21_div_114);
  tcase_add_test(tc, s21_div_115);
  // tcase_add_test(tc, s21_div_116);
  tcase_add_test(tc, s21_div_117);
  tcase_add_test(tc, s21_div_118);
  tcase_add_test(tc, s21_div_119);
  tcase_add_test(tc, s21_div_120);
  tcase_add_test(tc, s21_div_121);
  tcase_add_test(tc, s21_div_122);
  tcase_add_test(tc, s21_div_123);
  tcase_add_test(tc, s21_div_124);
  // tcase_add_test(tc, s21_div_125);
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
  tcase_add_test(tc, s21_div_146);
  tcase_add_test(tc, s21_div_147);
  tcase_add_test(tc, s21_div_148);
  tcase_add_test(tc, s21_div_149);
  tcase_add_test(tc, s21_div_150);
  // tcase_add_test(tc, s21_div_151);
  tcase_add_test(tc, s21_div_152);
  tcase_add_test(tc, s21_div_153);
  tcase_add_test(tc, s21_div_154);
  tcase_add_test(tc, s21_div_155);
  tcase_add_test(tc, s21_div_156);
  tcase_add_test(tc, s21_div_157);
  tcase_add_test(tc, s21_div_158);
  // tcase_add_test(tc, s21_div_159);
  tcase_add_test(tc, s21_div_160);
  tcase_add_test(tc, s21_div_161);
  // tcase_add_test(tc, s21_div_162);
  tcase_add_test(tc, s21_div_163);
  tcase_add_test(tc, s21_div_164);
  tcase_add_test(tc, s21_div_165);
  tcase_add_test(tc, s21_div_166);
  tcase_add_test(tc, s21_div_167);
  tcase_add_test(tc, s21_div_168);
  tcase_add_test(tc, s21_div_169);
  tcase_add_test(tc, s21_div_170);
  // tcase_add_test(tc, s21_div_171);
  // tcase_add_test(tc, s21_div_172);
  tcase_add_test(tc, s21_div_173);
  tcase_add_test(tc, s21_div_174);
  // tcase_add_test(tc, s21_div_175);
  tcase_add_test(tc, s21_div_176);
  tcase_add_test(tc, s21_div_177);
  tcase_add_test(tc, s21_div_178);
  tcase_add_test(tc, s21_div_179);
  tcase_add_test(tc, s21_div_180);
  // tcase_add_test(tc, s21_div_181);
  tcase_add_test(tc, s21_div_182);
  // tcase_add_test(tc, s21_div_183);
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
  // tcase_add_test(tc, s21_div_234);
  tcase_add_test(tc, s21_div_235);
  tcase_add_test(tc, s21_div_236);
  tcase_add_test(tc, s21_div_237);
  tcase_add_test(tc, s21_div_238);
  // tcase_add_test(tc, s21_div_239);
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
  // tcase_add_test(tc, s21_div_250);
  tcase_add_test(tc, s21_div_251);
  tcase_add_test(tc, s21_div_252);
  // tcase_add_test(tc, s21_div_253);
  tcase_add_test(tc, s21_div_254);
  tcase_add_test(tc, s21_div_255);
  // tcase_add_test(tc, s21_div_256);
  tcase_add_test(tc, s21_div_257);
  tcase_add_test(tc, s21_div_258);
  tcase_add_test(tc, s21_div_259);
  // tcase_add_test(tc, s21_div_260);
  tcase_add_test(tc, s21_div_261);
  tcase_add_test(tc, s21_div_262);
  tcase_add_test(tc, s21_div_263);
  tcase_add_test(tc, s21_div_264);
  tcase_add_test(tc, s21_div_265);
  tcase_add_test(tc, s21_div_266);
  tcase_add_test(tc, s21_div_267);
  // tcase_add_test(tc, s21_div_268);
  tcase_add_test(tc, s21_div_269);
  // tcase_add_test(tc, s21_div_270);
  // tcase_add_test(tc, s21_div_271);
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
  // tcase_add_test(tc, s21_div_285);
  // tcase_add_test(tc, s21_div_286);
  tcase_add_test(tc, s21_div_287);
  // tcase_add_test(tc, s21_div_288);
  tcase_add_test(tc, s21_div_289);
  tcase_add_test(tc, s21_div_290);
  // tcase_add_test(tc, s21_div_291);
  tcase_add_test(tc, s21_div_292);
  tcase_add_test(tc, s21_div_293);
  tcase_add_test(tc, s21_div_294);
  tcase_add_test(tc, s21_div_295);
  tcase_add_test(tc, s21_div_296);
  // tcase_add_test(tc, s21_div_297);
  tcase_add_test(tc, s21_div_298);
  tcase_add_test(tc, s21_div_299);
  tcase_add_test(tc, s21_div_300);
  // tcase_add_test(tc, s21_div_301);
  tcase_add_test(tc, s21_div_302);
  // tcase_add_test(tc, s21_div_303);
  tcase_add_test(tc, s21_div_304);
  tcase_add_test(tc, s21_div_305);
  tcase_add_test(tc, s21_div_306);
  tcase_add_test(tc, s21_div_307);
  tcase_add_test(tc, s21_div_308);
  tcase_add_test(tc, s21_div_309);
  // tcase_add_test(tc, s21_div_310);
  tcase_add_test(tc, s21_div_311);
  tcase_add_test(tc, s21_div_312);
  tcase_add_test(tc, s21_div_313);
  tcase_add_test(tc, s21_div_314);
  tcase_add_test(tc, s21_div_315);
  tcase_add_test(tc, s21_div_316);
  tcase_add_test(tc, s21_div_317);
  tcase_add_test(tc, s21_div_318);
  // tcase_add_test(tc, s21_div_319);
  tcase_add_test(tc, s21_div_320);
  tcase_add_test(tc, s21_div_321);
  tcase_add_test(tc, s21_div_322);
  tcase_add_test(tc, s21_div_323);
  tcase_add_test(tc, s21_div_324);
  tcase_add_test(tc, s21_div_325);
  tcase_add_test(tc, s21_div_326);
  // tcase_add_test(tc, s21_div_327);
  tcase_add_test(tc, s21_div_328);
  tcase_add_test(tc, s21_div_329);
  // tcase_add_test(tc, s21_div_330);
  tcase_add_test(tc, s21_div_331);
  tcase_add_test(tc, s21_div_332);
  tcase_add_test(tc, s21_div_333);
  tcase_add_test(tc, s21_div_334);
  tcase_add_test(tc, s21_div_335);
  tcase_add_test(tc, s21_div_336);
  tcase_add_test(tc, s21_div_337);
  // tcase_add_test(tc, s21_div_338);
  tcase_add_test(tc, s21_div_339);
  tcase_add_test(tc, s21_div_340);
  tcase_add_test(tc, s21_div_341);
  // tcase_add_test(tc, s21_div_342);
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
  // tcase_add_test(tc, s21_div_357);
  tcase_add_test(tc, s21_div_358);
  tcase_add_test(tc, s21_div_359);
  tcase_add_test(tc, s21_div_360);
  tcase_add_test(tc, s21_div_361);
  tcase_add_test(tc, s21_div_362);
  tcase_add_test(tc, s21_div_363);
  tcase_add_test(tc, s21_div_364);
  // tcase_add_test(tc, s21_div_365);
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
  // tcase_add_test(tc, s21_div_376);
  tcase_add_test(tc, s21_div_377);
  tcase_add_test(tc, s21_div_378);
  tcase_add_test(tc, s21_div_379);
  tcase_add_test(tc, s21_div_380);
  tcase_add_test(tc, s21_div_381);
  tcase_add_test(tc, s21_div_382);
  tcase_add_test(tc, s21_div_383);
  tcase_add_test(tc, s21_div_384);
  // tcase_add_test(tc, s21_div_385);
  tcase_add_test(tc, s21_div_386);
  // tcase_add_test(tc, s21_div_387);
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
  // tcase_add_test(tc, s21_div_405);
  tcase_add_test(tc, s21_div_406);
  tcase_add_test(tc, s21_div_407);
  tcase_add_test(tc, s21_div_408);
  tcase_add_test(tc, s21_div_409);
  tcase_add_test(tc, s21_div_410);
  // tcase_add_test(tc, s21_div_411);
  tcase_add_test(tc, s21_div_412);
  tcase_add_test(tc, s21_div_413);
  tcase_add_test(tc, s21_div_414);
  // tcase_add_test(tc, s21_div_415);
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
  // tcase_add_test(tc, s21_div_435);
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
  // tcase_add_test(tc, s21_div_446);
  tcase_add_test(tc, s21_div_447);
  tcase_add_test(tc, s21_div_448);
  tcase_add_test(tc, s21_div_449);
  tcase_add_test(tc, s21_div_450);
  tcase_add_test(tc, s21_div_451);
  tcase_add_test(tc, s21_div_452);
  // tcase_add_test(tc, s21_div_453);
  tcase_add_test(tc, s21_div_454);
  // tcase_add_test(tc, s21_div_455);
  // tcase_add_test(tc, s21_div_456);
  tcase_add_test(tc, s21_div_457);
  tcase_add_test(tc, s21_div_458);
  tcase_add_test(tc, s21_div_459);
  tcase_add_test(tc, s21_div_460);
  tcase_add_test(tc, s21_div_461);
  tcase_add_test(tc, s21_div_462);
  tcase_add_test(tc, s21_div_463);
  tcase_add_test(tc, s21_div_464);
  // tcase_add_test(tc, s21_div_465);
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
  // tcase_add_test(tc, s21_div_477);
  tcase_add_test(tc, s21_div_478);
  tcase_add_test(tc, s21_div_479);
  tcase_add_test(tc, s21_div_480);
  tcase_add_test(tc, s21_div_481);
  tcase_add_test(tc, s21_div_482);
  // tcase_add_test(tc, s21_div_483);
  tcase_add_test(tc, s21_div_484);
  // tcase_add_test(tc, s21_div_485);
  tcase_add_test(tc, s21_div_486);
  // tcase_add_test(tc, s21_div_487);
  tcase_add_test(tc, s21_div_488);
  // tcase_add_test(tc, s21_div_489);
  tcase_add_test(tc, s21_div_490);
  tcase_add_test(tc, s21_div_491);
  tcase_add_test(tc, s21_div_492);
  tcase_add_test(tc, s21_div_493);
  tcase_add_test(tc, s21_div_494);
  tcase_add_test(tc, s21_div_495);
  tcase_add_test(tc, s21_div_496);
  tcase_add_test(tc, s21_div_497);
  // tcase_add_test(tc, s21_div_498);
  tcase_add_test(tc, s21_div_499);
  tcase_add_test(tc, s21_div_500);
  // tcase_add_test(tc, fail_s21_div_1);
  // tcase_add_test(tc, fail_s21_div_2);
  // tcase_add_test(tc, fail_s21_div_3);
  // tcase_add_test(tc, fail_s21_div_4);
  // tcase_add_test(tc, fail_s21_div_5);
  // tcase_add_test(tc, fail_s21_div_6);
  // tcase_add_test(tc, fail_s21_div_7);
  // tcase_add_test(tc, fail_s21_div_8);
  // tcase_add_test(tc, fail_s21_div_9);
  // tcase_add_test(tc, fail_s21_div_10);
  // tcase_add_test(tc, fail_s21_div_11);
  // tcase_add_test(tc, fail_s21_div_12);
  // tcase_add_test(tc, fail_s21_div_13);
  // tcase_add_test(tc, fail_s21_div_14);
  // tcase_add_test(tc, fail_s21_div_15);
  // tcase_add_test(tc, fail_s21_div_16);
  // tcase_add_test(tc, fail_s21_div_17);
  // tcase_add_test(tc, fail_s21_div_18);
  // tcase_add_test(tc, fail_s21_div_19);
  // tcase_add_test(tc, fail_s21_div_20);
  // tcase_add_test(tc, fail_s21_div_21);
  // tcase_add_test(tc, fail_s21_div_22);
  // tcase_add_test(tc, fail_s21_div_23);
  // tcase_add_test(tc, fail_s21_div_24);
  // tcase_add_test(tc, fail_s21_div_25);
  // tcase_add_test(tc, fail_s21_div_26);
  // tcase_add_test(tc, fail_s21_div_27);
  // tcase_add_test(tc, fail_s21_div_28);
  // tcase_add_test(tc, fail_s21_div_29);
  // tcase_add_test(tc, fail_s21_div_30);
  // tcase_add_test(tc, fail_s21_div_31);
  // tcase_add_test(tc, fail_s21_div_32);
  // tcase_add_test(tc, fail_s21_div_33);
  // tcase_add_test(tc, fail_s21_div_34);
  // tcase_add_test(tc, fail_s21_div_35);
  // tcase_add_test(tc, fail_s21_div_36);
  // tcase_add_test(tc, fail_s21_div_37);
  // tcase_add_test(tc, fail_s21_div_38);
  // tcase_add_test(tc, fail_s21_div_39);
  // tcase_add_test(tc, fail_s21_div_40);
  // tcase_add_test(tc, fail_s21_div_41);
  // tcase_add_test(tc, fail_s21_div_42);
  // tcase_add_test(tc, fail_s21_div_43);
  // tcase_add_test(tc, fail_s21_div_44);
  // tcase_add_test(tc, fail_s21_div_45);
  // tcase_add_test(tc, fail_s21_div_46);
  // tcase_add_test(tc, fail_s21_div_47);
  // tcase_add_test(tc, fail_s21_div_48);
  // tcase_add_test(tc, fail_s21_div_49);
  // tcase_add_test(tc, fail_s21_div_50);
  // tcase_add_test(tc, fail_s21_div_51);
  // tcase_add_test(tc, fail_s21_div_52);
  // tcase_add_test(tc, fail_s21_div_53);
  // tcase_add_test(tc, fail_s21_div_54);
  // tcase_add_test(tc, fail_s21_div_55);
  // tcase_add_test(tc, fail_s21_div_56);
  // tcase_add_test(tc, fail_s21_div_57);
  // tcase_add_test(tc, fail_s21_div_58);
  // tcase_add_test(tc, fail_s21_div_59);
  // tcase_add_test(tc, fail_s21_div_60);
  // tcase_add_test(tc, fail_s21_div_61);
  // tcase_add_test(tc, fail_s21_div_62);
  // tcase_add_test(tc, fail_s21_div_63);
  // tcase_add_test(tc, fail_s21_div_64);
  // tcase_add_test(tc, fail_s21_div_65);
  // tcase_add_test(tc, fail_s21_div_66);
  // tcase_add_test(tc, fail_s21_div_67);
  // tcase_add_test(tc, fail_s21_div_68);
  // tcase_add_test(tc, fail_s21_div_69);
  // tcase_add_test(tc, fail_s21_div_70);
  // tcase_add_test(tc, fail_s21_div_71);
  // tcase_add_test(tc, fail_s21_div_72);
  // tcase_add_test(tc, fail_s21_div_73);
  // tcase_add_test(tc, fail_s21_div_74);
  // tcase_add_test(tc, fail_s21_div_75);
  // tcase_add_test(tc, fail_s21_div_76);
  // tcase_add_test(tc, fail_s21_div_77);
  // tcase_add_test(tc, fail_s21_div_78);
  // tcase_add_test(tc, fail_s21_div_79);
  // tcase_add_test(tc, fail_s21_div_80);
  // tcase_add_test(tc, fail_s21_div_81);
  // tcase_add_test(tc, fail_s21_div_82);
  // tcase_add_test(tc, fail_s21_div_83);
  // tcase_add_test(tc, fail_s21_div_84);
  // tcase_add_test(tc, fail_s21_div_85);
  // tcase_add_test(tc, fail_s21_div_86);
  // tcase_add_test(tc, fail_s21_div_87);
  // tcase_add_test(tc, fail_s21_div_88);
  // tcase_add_test(tc, fail_s21_div_89);
  // tcase_add_test(tc, fail_s21_div_90);
  // tcase_add_test(tc, fail_s21_div_91);
  // tcase_add_test(tc, fail_s21_div_92);
  // tcase_add_test(tc, fail_s21_div_93);
  // tcase_add_test(tc, fail_s21_div_94);
  // tcase_add_test(tc, fail_s21_div_95);
  // tcase_add_test(tc, fail_s21_div_96);
  // tcase_add_test(tc, fail_s21_div_97);
  // tcase_add_test(tc, fail_s21_div_98);
  // tcase_add_test(tc, fail_s21_div_99);
  // tcase_add_test(tc, fail_s21_div_100);
  // tcase_add_test(tc, fail_s21_div_101);
  // tcase_add_test(tc, fail_s21_div_102);
  // tcase_add_test(tc, fail_s21_div_103);
  // tcase_add_test(tc, fail_s21_div_104);
  // tcase_add_test(tc, fail_s21_div_105);
  // tcase_add_test(tc, fail_s21_div_106);
  // tcase_add_test(tc, fail_s21_div_107);
  // tcase_add_test(tc, fail_s21_div_108);
  // tcase_add_test(tc, fail_s21_div_109);
  // tcase_add_test(tc, fail_s21_div_110);
  // tcase_add_test(tc, fail_s21_div_111);
  // tcase_add_test(tc, fail_s21_div_112);
  // tcase_add_test(tc, fail_s21_div_113);
  // tcase_add_test(tc, fail_s21_div_114);
  // tcase_add_test(tc, fail_s21_div_115);
  // tcase_add_test(tc, fail_s21_div_116);
  // tcase_add_test(tc, fail_s21_div_117);
  // tcase_add_test(tc, fail_s21_div_118);
  // tcase_add_test(tc, fail_s21_div_119);
  // tcase_add_test(tc, fail_s21_div_120);
  // tcase_add_test(tc, fail_s21_div_121);
  // tcase_add_test(tc, fail_s21_div_122);
  // tcase_add_test(tc, fail_s21_div_123);
  // tcase_add_test(tc, fail_s21_div_124);
  // tcase_add_test(tc, fail_s21_div_125);
  // tcase_add_test(tc, fail_s21_div_126);
  // tcase_add_test(tc, fail_s21_div_127);
  // tcase_add_test(tc, fail_s21_div_128);
  // tcase_add_test(tc, fail_s21_div_129);
  // tcase_add_test(tc, fail_s21_div_130);
  // tcase_add_test(tc, fail_s21_div_131);
  // tcase_add_test(tc, fail_s21_div_132);
  // tcase_add_test(tc, fail_s21_div_133);
  // tcase_add_test(tc, fail_s21_div_134);
  // tcase_add_test(tc, fail_s21_div_135);
  // tcase_add_test(tc, fail_s21_div_136);
  // tcase_add_test(tc, fail_s21_div_137);
  // tcase_add_test(tc, fail_s21_div_138);
  // tcase_add_test(tc, fail_s21_div_139);
  // tcase_add_test(tc, fail_s21_div_140);
  // tcase_add_test(tc, fail_s21_div_141);
  // tcase_add_test(tc, fail_s21_div_142);
  // tcase_add_test(tc, fail_s21_div_143);
  // tcase_add_test(tc, fail_s21_div_144);
  // tcase_add_test(tc, fail_s21_div_145);
  // tcase_add_test(tc, fail_s21_div_146);
  // tcase_add_test(tc, fail_s21_div_147);
  // tcase_add_test(tc, fail_s21_div_148);
  // tcase_add_test(tc, fail_s21_div_149);
  // tcase_add_test(tc, fail_s21_div_150);
  // tcase_add_test(tc, fail_s21_div_151);
  // tcase_add_test(tc, fail_s21_div_152);
  // tcase_add_test(tc, fail_s21_div_153);
  // tcase_add_test(tc, fail_s21_div_154);
  // tcase_add_test(tc, fail_s21_div_155);
  // tcase_add_test(tc, fail_s21_div_156);
  // tcase_add_test(tc, fail_s21_div_157);
  // tcase_add_test(tc, fail_s21_div_158);
  // tcase_add_test(tc, fail_s21_div_159);
  // tcase_add_test(tc, fail_s21_div_160);
  // tcase_add_test(tc, fail_s21_div_161);
  // tcase_add_test(tc, fail_s21_div_162);
  // tcase_add_test(tc, fail_s21_div_163);
  // tcase_add_test(tc, fail_s21_div_164);
  // tcase_add_test(tc, fail_s21_div_165);
  // tcase_add_test(tc, fail_s21_div_166);

  suite_add_tcase(c, tc);
  return c;
}
