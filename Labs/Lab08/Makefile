CC=gcc
CFLAGS=-Wall
DEPS=snode.h

all: snode

snode: snode.o snode-test.o
	$(CC) $(CFLAGS) snode.o snode-test.o -o snode

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

