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

	if (l->counter == 0) {
		node->next = NULL;
		node->prev = NULL;
		l->front = node;
	} else {
		node->next = l->front;
		l->front->prev = node;
		l->front = node;
	}

	l->counter++;

	return	node;
}

struct dnode* dlist_add_back(struct dlist *l, char *str) {
	struct dnode* node = dnode_create(str);

	if (l->counter == 0) {
		node->prev = l->back;
		l->front = node;
		l->back = node;
	} else {
		node->prev = l->back;
		l->back->next = node;
		l->back = node;
	}

	l->counter++;
	l->back = node;

	return	node;
}

void dlist_destroy(struct dlist *l) {
	struct dnode *node;
	for (node = l->front; node != NULL; node = node->next){
		dnode_destroy(node);
		printf("free\n");
	}
printf("final\n");
	free(l);
	printf("done\n");
}

uint32_t dlist_length(struct dlist *l) {
	return l->counter;
}

struct dnode* dlist_find(struct dlist* l, char * str) {
	struct dnode *node;
	for (node = l->front; node != NULL; node = node->next){
		if (dnode_cmp(node,str) == 0) {
			return node;
		}
	}

	return NULL;
}

int dnode_cmp(struct dnode *n, char *str) {
	return strcmp(n->str, str);
}

struct dnode* dlist_insert_after(struct dlist* l, struct dnode* n, char * str) {
	struct dnode *node = dnode_create(str);
	node->prev = n;
	node->next = n->next;
	if (n->next != NULL)
		n->next->prev = node;
	n->next = node;
    if (l->back == n)
    	l->back = node;

	l->counter++;

	return node;
}

struct dnode* dlist_insert_before(struct dlist* l, struct dnode* n, char * str) {
	struct dnode *node = dnode_create(str);
	node->next = n;
	node->prev = n->prev;
    if(n->prev != NULL)
		n->prev->next = node;
	n->prev = node;
	if (l->front == n)
		l->front = node;

	l->counter++;

	return node;

}


struct dnode* dlist_remove(struct dlist* l, struct dnode* n) {
	if (n->next != NULL)
		n->next->prev = n->prev;
	if (n->prev != NULL)
		n->prev->next = n->next;
	if (n == l->front)
		l->front = n->next;
	if (n == l->back)
		l->back = n->prev;

	n->prev = NULL;
	n->next = NULL;

	l->counter--;

	return n;

}

