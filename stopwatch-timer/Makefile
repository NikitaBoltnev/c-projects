CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude
LDFLAGS = -lncurses -lpthread

all: stopwatchAndTimer

stopwatchAndTimer: main.o interface.o stopwatch.o timer.o
	$(CC) main.o interface.o stopwatch.o timer.o -o stopwatchAndTimer $(LDFLAGS)
	rm -rf *.o

run: stopwatchAndTimer
	./stopwatchAndTimer

main.o:
	$(CC) $(CFLAGS) -c src/main.c -o main.o

interface.o:
	$(CC) $(CFLAGS) -c src/interface.c -o interface.o

stopwatch.o:
	$(CC) $(CFLAGS) -c src/stopwatch.c -o stopwatch.o

timer.o:
	$(CC) $(CFLAGS) -c src/timer.c -o timer.o

clean:
	rm -rf *.o stopwatchAndTimer