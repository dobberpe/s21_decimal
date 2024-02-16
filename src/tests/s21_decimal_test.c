#include "s21_decimal_test.h"

int main() {
  int number_failed;
  Suite *suite = NULL;
  SRunner *runner = srunner_create(suite);

  Suite *suits_list[] = {s21_add_cases(), s21_sub_cases(), s21_mul_cases(), NULL};

  for (Suite **current = suits_list; *current != NULL; current++)
    srunner_add_suite(runner, *current);

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}