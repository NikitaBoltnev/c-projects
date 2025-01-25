CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=201703L -pedantic
LDFLAGS = -lcheck -lm -lpthread -lrt -lsubunit

STRING_FUNCTION = $(shell ls string/*.c)
SPRINTF_FUNCTION = $(shell ls sprintf/*.c)
PROCESSING_FUNCTION = $(shell ls processing_functions/*.c)
TEST_FUNCTION = $(shell ls tests/*.c)
ALL_FUNCTION = $(STRING_FUNCTION) $(SPRINTF_FUNCTION) $(PROCESSING_FUNCTION)

all: clean test s21_string.a gcov_report

clean:
	rm -rf *.a *.info s21_string_test s21_string_test_gcov report

test: s21_string.a
	$(CC) $(CFLAGS) $(TEST_FUNCTION) s21_string.a -o s21_string_test $(LDFLAGS)
	./s21_string_test

s21_string.a:
	$(CC) $(CFLAGS) -c $(ALL_FUNCTION)
	ar rcs s21_string.a *.o
	rm *.o

gcov_report: s21_string.a
	$(CC) $(CFLAGS) --coverage $(TEST_FUNCTION) s21_string.a -o s21_string_test_gcov $(LDFLAGS)
	./s21_string_test_gcov
	lcov -t "s21_string_test_report" -o string.info -c -d .
	genhtml -o report string.info
	open report/index.html
	rm -rf *.gcda *.gcno
