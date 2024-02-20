CC = gcc
CFLAGS =
TFLAGS = -lcheck -lsubunit -lm
GFLAGS = -fprofile-arcs -ftest-coverage
LIB_NAME = s21_decimal.a
LIB_SRC = s21_decimal_arithmetic.c s21_decimal_converter.c s21_common.c s21_dectostr.c s21_decimal_compare.c s21_decimal_other.c
LIB_OBJ = $(LIB_SRC:.c=.o)
TEST_SRC = $(wildcard ./tests/*.c)
# TEST_SRC = tests/s21_string_test.c tests/apply_format_test.c tests/s21_sprintf.c
TEST_GCDA = $(LIB_SRC:.c=.gcda)
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(LIB_NAME) test

test: $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o test -L. -l:$(LIB_NAME) $(TFLAGS)
	rm -f $(TEST_OBJ)
	./test


gcov_report: clean
	@command -v lcov >/dev/null 2>&1 || { echo >&2 "Error: lcov not found. Please install lcov."; exit 1; }
	gcc -o s21_decimal_arithmetic.o -c $(GFLAGS) s21_decimal_arithmetic.c
	gcc -o s21_decimal_converter.o -c $(GFLAGS) s21_decimal_converter.c
	gcc -o s21_common.o -c $(GFLAGS) s21_common.c
	gcc -o s21_dectostr.o -c $(GFLAGS) s21_dectostr.c
	gcc -o s21_decimal_compare.o -c $(GFLAGS) s21_decimal_compare.c
	gcc -o s21_decimal_other.o -c $(GFLAGS) s21_decimal_other.c
	ar rcs $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)
	rm -f $(LIB_OBJ)
	$(CC) $(CFLAGS) -o gcov_r $(GFLAGS) $(TEST_SRC) -L. -l:$(LIB_NAME) $(TFLAGS)
	./gcov_r
	geninfo $(TEST_GCDA) $(LIB_SRC) -o ./coverage.info
	genhtml coverage.info -o coverage_report
	# rm -rf gcov_r* coverage.info *.gcda *.gcno tests/*.gcno
	open coverage_report/index.html

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(LIB_OBJ)
	ar rcs $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)
	rm -f $(LIB_OBJ)

clean:
	rm -f $(LIB_OBJ) $(LIB_NAME) $(TEST_OBJ) test gcov* coverage.info *.gcda *.gcno tests/*.gcno
	rm -rf coverage_report

re: clean all