/* Luis Felipe Tomazini
* T 1pm
* lab 08 - dlist.c
* compile with: make
* notes: creates a doubly-linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"
#include "dnode.h"

struct dlist *dlist_create() {
	struct dlist* instance;
 	instance = (struct dlist*)malloc(sizeof(struct dlist));
	instance->back = NULL;
	instance->front = NULL;
	instance->counter = 0;

 	return instance;
}

struct dnode* dlist_add_front(struct dlist *l, char *str) {
	struct dnode* node = dnode_create(str);
	node->next = l->front;
	node->prev = l->back;
	l->front->prev = node;
	l->front = l->front->prev;
	l->back->next = l->front;
	
	l->counter++;

	return	node;
}

struct dnode* dlist_add_back(struct dlist *l, char *str) {
	struct dnode* node = dnode_create(str);

	return	node;
}

void dlist_destroy(struct dlist *l) {
	free(l);
}

uint32_t dlist_length(struct dlist *l) {
	return l->counter;
}
