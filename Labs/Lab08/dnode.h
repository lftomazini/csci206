/* Luis Felipe Tomazini
 * T 1pm
 * lab 08 - dnode.h
 * compile with: make
 * notes: creates a struct dnode
 */

#ifndef __dnode_h_
#define __dnode_h_

struct dnode *dnode_create(char *s);
void dnode_destroy(struct dnode *n);

struct dnode {
	char*		str;
	int		length;
	struct dnode*	next;
	struct dnode*	prev;
};

#endif
