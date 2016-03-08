/* Luis Felipe Tomazini
* T 1pm
* lab 08 - dnode.c
* compile with: make
* notes: creates a new node
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dnode.h"

struct dnode* dnode_create(char* s) {
	struct dnode* instance;
 	instance = (struct dnode*)malloc(sizeof(struct dnode)+strlen(s)*sizeof(char));
	instance->str = (char*)malloc((strlen(s)+1)*sizeof(char));
 	strcpy(instance->str, s);
	instance->length = strlen(s);
 	instance->prev = NULL;
	instance->next = NULL;
	
 	return instance;
}

void dnode_destroy(struct dnode *n) {
	free(n->str);
	free(n);
}
