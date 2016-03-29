CC=gcc
CFLAGS=-Wall

all: bits.o floats

bits.o: bits.h bits.c
	$(CC) $(CFLAGS) bits.c -o bits.o

floats: floats.c floats.s
	$(CC) $(CFLAGS) floats.c floats.s -o floats
