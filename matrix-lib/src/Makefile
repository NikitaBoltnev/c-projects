CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=201703L -pedantic
LDFLAGS = -lcheck -lm -lsubunit

ALGEBRA_FUNCTION = $(wildcard matrix_algebra/*.c)
ARITHMETIC_FUNCTION = $(wildcard matrix_arithmetic/*.c)
COMPARISON_FUNCTION = $(wildcard matrix_comparison/*.c)
CORE_FUNCTION = $(wildcard matrix_core/*.c)
TRANSFORMATIONS_FUNCTION = $(wildcard matrix_transformations/*.c)
VALIDATION_FUNCTION = $(wildcard matrix_validation/*.c)
TEST_FUNCTION = $(wildcard tests/*.c)
ALL_FUNCTIONS = $(ALGEBRA_FUNCTION) $(ARITHMETIC_FUNCTION) $(COMPARISON_FUNCTION) $(CORE_FUNCTION) $(TRANSFORMATIONS_FUNCTION) $(VALIDATION_FUNCTION)

all: clean s21_matrix.a test gcov_report

clean:
		rm -rf *.a *.gc* *.info s21_matrix_test s21_matrix_test_gcov report

test: s21_matrix.a
		$(CC) $(CFLAGS) $(TEST_FUNCTION) s21_matrix.a -o s21_matrix_test $(LDFLAGS)
		./s21_matrix_test

s21_matrix.a:
		$(CC) $(CFLAGS) -c $(ALL_FUNCTIONS)
		ar rcs s21_matrix.a *.o
		rm *.o

gcov_report: clean
		$(CC) $(CFLAGS) --coverage -c $(ALL_FUNCTIONS)
		ar rcs s21_matrix.a *.o
		rm *.o
		$(CC) $(CFLAGS) --coverage $(TEST_FUNCTION) s21_matrix.a -o s21_matrix_test_gcov $(LDFLAGS) -lgcov
		./s21_matrix_test_gcov
		lcov -t "s21_matrix_test_gcov" -o s21_matrix.info -c -d . --exclude "*tests/*"
		genhtml -o report s21_matrix.info --branch-coverage
		open report/index.html
		rm -rf *.gcda *.gcno