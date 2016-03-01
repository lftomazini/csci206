/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - primes.c
 * compile with: make primes
 * notes: print prime numbers
 */

#include <stdio.h>

#define MAX 10

int main (void) {
    int i, n = 0;
    
    for (i = 2; n < MAX; i++) {
	printf("Here\n");
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

// Real: 21.349s
// User: 16.837s
// Sys:   0.216s
