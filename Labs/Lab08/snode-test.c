/* Luis Felipe Tomazini
 * T 1pm
 * lab 08 - snode-testch
 * compile with: make
 * notes: test struct snode
 */

#include <stdio.h>
#include "snode.h"

// global variables (data segment)

struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  n1 = snode_create("hello", 5);
  n2 = snode_create("there", 5);
  n3 = snode_create("prof", 4);

  printf("snode-test running...\n");

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

  return 0;
}