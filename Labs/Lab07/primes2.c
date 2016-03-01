/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - primes.c
 * compile with: make primes
 * notes: print prime numbers
 */

#include <stdio.h>

#define MAX 10020

int is_prime(int n);

int main (void) {
    int i, n = 0;
    
    for (i = 2; n < MAX; i++) {
        if (is_prime(i)){
            if ((n % 10) == 0) {
                printf("\n");
            }
            printf("%7d", i);
            n++;
        }
    }
    printf("\n");
    
    return 0;
}

// C
// Real: 21.349s
// User: 16.837s
// Sys:   0.216s

// Assembly
// Real: 19.003s
// User	  6.904s
// Sys	  0.272s

// C code generates instruction that are not essential. Writting directly in assembly makes it have only the necessary code for it to work.

