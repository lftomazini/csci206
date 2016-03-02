CC=gcc
CFLAGS=-Wall

all: primes counte matrix-sum

primes: primes2.c is_prime.s 
	$(CC) $(CFLAGS)  primes2.c is_prime.s -o primes2

counte: counte.c counte.s
	$(CC) $(CFLAGS)  counte.c counte.s -o counte

matrix-sum: matrix-sum.c matrix_sum.s
	$(CC) $(CFLAGS)  matrix-sum.c matrix_sum.s -o sum
