#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "dnode.h"
#include "dlist.h"

#ifdef DEBUG
#define TEST_SIZE 6
#define TEST_FIND 5
#else
#define TEST_SIZE 36
#define TEST_FIND 32
#endif


// test basic functionality
void test1()
{
    struct dlist* l = dlist_create();
    assert(NULL != l);

    // test add back
    struct dnode* a = dlist_add_back(l, "A");   
    assert(l->front == a);
    assert(l->back == a);
    assert(a->next == NULL);
    assert(a->prev == NULL);

    // test insert
    struct dnode* c = dlist_insert_after(l, a, "C");
    assert(l->front == a);
    assert(l->back == c);
    assert(a->next == c);
    assert(a->prev == NULL);
    assert(c->next == NULL);
    assert(c->prev == a);

    struct dnode* b = dlist_insert_after(l, a, "B");
    assert(l->front == a);
    assert(l->back == c);
    assert(l->front->next == b);
    assert(l->front->prev == NULL);
    assert(l->front->next->next == c );
    assert(l->front->next->prev == a );
    assert(l->back->prev == b);
    assert(l->back->prev->prev == a);

    // insert before first node
    struct dnode* first = dlist_insert_before(l, a, "FIRST");
    assert(l->front == first);
    assert(l->front->next == a);
    assert(first->next == a);
    assert(first->prev == NULL);

    // insert before not first node
    struct dnode* second = dlist_insert_before(l, a, "SECOND");
    assert(first->next == second);
    assert(second->prev == first);
    assert(second->next == a);
    assert(a->prev == second);

    assert(dlist_length(l) == 5);

    // add front
    struct dnode* tmp = dlist_add_front(l, "new front");
    assert(l->front == tmp);
    assert(l->front->next == first);
    assert(l->front->next->prev == tmp);
    
    printf("all test_insert tests passed...\n");

    // test find
    assert (a == dlist_find(l, "A"));
    assert (b == dlist_find(l, "B"));
    assert (c == dlist_find(l, "C"));
    assert (NULL == dlist_find(l, "not found"));

    printf("all find tests passed...\n");  

    // test remove
    struct dnode* rmv = dlist_remove(l, second);
    assert(NULL == dlist_find(l, "SECOND"));
    assert(rmv == second);
    assert(l->front->next->next == a);
    assert(a->prev == l->front->next);
    dnode_destroy(rmv);

    dlist_remove(l, tmp);
    rmv = dlist_remove(l, first);
    assert(NULL == dlist_find(l, "FIRST"));
    assert(rmv == first);
    assert(l->front == a);
    assert(first->next == NULL);
    assert(first->prev == NULL);
    dnode_destroy(tmp);
    dnode_destroy(rmv);

    assert(dlist_length(l) == 3);
    
    // test removing last item
    dlist_remove(l, c);
    assert(l->back == b);
    assert(b->next == NULL);

    dnode_destroy(c);
    dlist_destroy(l);
    l = NULL;

    printf("all tests1 passed.\n");
}

void print_list(struct dlist* l)
{
#ifdef DEBUG
    int i = 0;
    struct dnode *t;
    printf("%d :[ ", dlist_length(l));
    for (t = l->front; t != NULL; t = t->next){
        printf("%d:%s ", i++, t->str);        
    }
    printf("]\n");
#endif
}

// stress test the dlist
void test2()
{    
    //  save a copy of all test nodes in an array. Note this is an array of pointers.
    struct dnode** vals = (struct dnode**) malloc(TEST_SIZE * sizeof(struct dnode*));
    struct dlist* l = dlist_create();
    int i;
    FILE* fd = fopen("/usr/share/dict/words", "r");

    // add some data
    for (i=0; i<TEST_SIZE; i++){
        char word[80];
        fgets(word, 80, fd);
        word[strlen(word)-1] = 0; // remove newline
        printf("adding %s\n", word);
        vals[i] = dlist_add_back(l, word);
    }
    fclose(fd);

    srand(time(NULL)); // seed rng with current time
    assert(dlist_length(l) == TEST_SIZE);
    
    // test find
    for (i=0; i<TEST_FIND; i++){
        int j = rand() % TEST_SIZE; // select a random test case.
        printf("Searching for %s...", vals[j]->str);
        assert(vals[j] == dlist_find(l, vals[j]->str));
        printf("found.\n");
    }

    print_list(l);
    // remove some items
    for (i=0; i<TEST_FIND; i++){
        int j;
        do {
            j = rand() % TEST_SIZE;
        }while(vals[j] == NULL); // avoid repeats

        printf("Remove %s.\n", vals[j]->str);

        dlist_remove(l, vals[j]);        
        dnode_destroy(vals[j]);
        vals[j] = NULL;

        print_list(l);
    }

    assert(dlist_length(l) == TEST_SIZE - TEST_FIND);
    
    printf("Done with test2.\n");


    dlist_destroy(l);
    printf("Freed list\n");
    free (vals); 
    printf("Freed vals\n");

}

int main(int argc, char* argv[])
{
    test1();
    test2();
    return 0;
}
