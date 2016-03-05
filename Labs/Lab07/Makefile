CC=gcc
CFLAGS=-Wall
DEPS=time.h

all: primes counte matrix-sum time

primes: primes2.c is_prime.s 
	$(CC) $(CFLAGS)  primes2.c is_prime.s -o primes2

counte: counte.c counte.s
	$(CC) $(CFLAGS)  counte.c counte.s -o counte

matrix-sum: matrix-sum.c matrix_sum.s
	$(CC) $(CFLAGS)  matrix-sum.c matrix_sum.s -o sum

time: time.c time.s
	$(CC) $(CFLAGS) time.c time.s -o time

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<