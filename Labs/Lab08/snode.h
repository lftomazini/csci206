/* Luis Felipe Tomazini
 * T 1pm
 * lab 08 - snode.h
 * compile with: make
 * notes: creates a struct snode
 */

#ifndef __snode_h_
#define __snode_h_

struct snode *snode_create(char *s, int length);

struct snode {
	char			str[100];
	int				length;
	struct snode*	next;
};

#endif