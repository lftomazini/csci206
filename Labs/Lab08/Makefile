CC=gcc
CFLAGS=-Wall

all: snode dnode song_list

snode: snode.c snode-test.c snode.h
	$(CC) $(CFLAGS) snode.c snode-test.c snode.h -o snode

dnode: dnode.c dnode-test.c dnode.h
	$(CC) $(CFLAGS) dnode.c dnode-test.c dnode.h -o dnode

song_list: dlist.c song_list.c dnode.c dnode.h dlist.h
	$(CC) $(CFLAGS) dlist.c song_list.c dnode.c dnode.h dlist.h -o song_list


