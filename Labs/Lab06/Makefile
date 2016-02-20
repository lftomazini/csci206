CC=gcc
CFLAGS=-Wall

all: collatz

collatz: collatz.o
	$(CC) $(CFLAGS) collatz.o -o collatz

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

