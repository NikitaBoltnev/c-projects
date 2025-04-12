CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=201703L -pedantic
LDFLAGS = -lcheck -lm -lsubunit

ARITHMETIC_FUNCTION = $(wildcard arithmetic/*.c)
COMPARISON_FUNCTION = $(wildcard comparison/*.c)
CONVERTORS_FUNCTION = $(wildcard convertors/*.c)
GENERAL_FUNCTION = $(wildcard general/*.c)
OTHER_FUNCTION = $(wildcard other/*.c)
TESTS_FUNCTION = $(wildcard tests/*.c)
ALL_FUNCTIONS = $(ARITHMETIC_FUNCTION) $(COMPARISON_FUNCTION) $(CONVERTORS_FUNCTION) $(GENERAL_FUNCTION) $(OTHER_FUNCTION)

all: clean test s21_decimal.a gcov_report

clean:
		rm -rf *.a *.info s21_decimal_test s21_decimal_test_gcov report

test: s21_decimal.a
		$(CC) $(CFLAGS) $(TESTS_FUNCTION) s21_decimal.a -o s21_decimal_test $(LDFLAGS)
		./s21_decimal_test

s21_decimal.a:
		$(CC) $(CFLAGS) -c $(ALL_FUNCTIONS)
		ar rcs s21_decimal.a *.o
		rm *.o

gcov_report: 
		$(CC) $(CFLAGS) --coverage -c $(ALL_FUNCTIONS)
		ar rcs s21_decimal.a *.o
		rm *.o
		$(CC) $(CFLAGS) --coverage $(TESTS_FUNCTION) s21_decimal.a -o s21_decimal_test_gcov $(LDFLAGS)
		./s21_decimal_test_gcov
		lcov -t "s21_decimal_test_report" -o s21_decimal.info -c -d .
		genhtml -o report s21_decimal.info
		open report/index.html
		rm -rf *.gcda *.gcno