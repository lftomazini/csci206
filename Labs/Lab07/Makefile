CC=gcc
CFLAGS=-Wall
DEPS=time.h

all: primes2 counte sum time

primes2: primes2.c is_prime.s 
	$(CC) $(CFLAGS) primes2.c is_prime.s -o primes2

counte: counte.c counte.s
	$(CC) $(CFLAGS) counte.c counte.s -o counte

sum: matrix-sum.c matrix_sum.s
	$(CC) $(CFLAGS) matrix-sum.c matrix_sum.s -o sum

time: time.c time.s
	$(CC) $(CFLAGS) time.c time.s -o time

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<