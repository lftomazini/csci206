/* Luis Felipe Tomazini
* T 1pm
* lab 08 - snode.c
* compile with: make
* notes: creates a new node
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snode.h"

struct snode* snode_create(char* s, int length) {
	struct snode* instance;
 	instance = (struct snode*)malloc(sizeof(struct snode));
 	strcpy(instance->str, s);
 	instance->length = length;
 	instance->next = NULL;
 	
 	return instance;
}