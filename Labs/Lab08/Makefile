CC=gcc
CFLAGS=-Wall
DEPS=snode.h

all: snode dnode

snode: snode.c snode-test.c snode.h
	$(CC) $(CFLAGS) snode.c snode-test.c snode.h -o snode

dnode: dnode.c dnode-test.c dnode.h
	$(CC) $(CFLAGS) dnode.c dnode-test.c dnode.h -o dnode

