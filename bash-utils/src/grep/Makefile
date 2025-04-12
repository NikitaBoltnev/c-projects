CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L -pedantic

all: s21_grep

s21_grep: s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o -o s21_grep
	rm -rf *.o

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c s21_grep.c

clean:
	rm -rf *.o *.out *.a s21_grep