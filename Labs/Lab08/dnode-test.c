/* Luis Felipe Tomazini
 * T 1pm
 * lab 08 - dnode-test.c
 * compile with: make
 * notes: test struct dnode
 */

#include <stdio.h>
#include "dnode.h"

// global variables (data segment)

struct dnode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create dnodes
  n1 = dnode_create("hello");
  n2 = dnode_create("there");
  n3 = dnode_create("prof");

  printf("dnode-test running...\n");

  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    printf("str: %s - length: %d\n", p->str, p->length);
    p = p->next;
  }

  dnode_destroy(n1);
  dnode_destroy(n2);
  dnode_destroy(n3);

  return 0;
}
