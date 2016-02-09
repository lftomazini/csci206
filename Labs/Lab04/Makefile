CC=gcc
CFLAGS=-Wall
DEPS=fileio.h
 
head2: head2.o fileio.o
	$(CC) $(CFLAGS) head2.o fileio.o -o head2

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

