/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - primes.c
 * compile with: make primes
 * notes: print prime numbers
 */

#include <stdio.h>

#define MAX 10020

int is_prime(int n) {
    int i;
    for (i = 2; i < n-1; i++) {
        if ((n % i) == 0) {
            return 0;
        }
    }
    return 1;
}

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