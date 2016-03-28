CC=gcc
CFLAGS=-Wall

all: snode-test dnode-test song_list dlist-test

snode.o: snode.h snode.c
	$(CC) $(CFLAGS) -c snode.c -o snode.o

dnode.o: dnode.h dnode.c
	$(CC) $(CFLAGS) -c dnode.c -o dnode.o

dlist.o: dlist.c dlist.h
	$(CC) $(CFLAGS) -c dlist.c -o dlist.o 

snode-test: snode.o snode-test.c
	$(CC) $(CFLAGS) snode-test.c snode.o -o snode-test

dnode-test: dnode.o dnode-test.c
	$(CC) $(CFLAGS) dnode-test.c dnode.o -o dnode-test

song_list: dlist.o song_list.c dnode.o
	$(CC) $(CFLAGS) dlist.o song_list.c dnode.o -o song_list

dlist-test: dnode.o dlist.o dlist_test.c
	$(CC) $(CFLAGS) dlist.o dnode.o dlist_test.c -o dlist-test
