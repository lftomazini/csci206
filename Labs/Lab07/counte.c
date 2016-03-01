/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - primes.c
 * compile with: make primes
 * notes: print prime numbers
 */

#include <stdio.h>

int main (void) {
    char* myString;
    
    printf("Type a string: ");
    scanf("%s", myString);
    
    int count = counte(myString);
    printf("There are %d e's", count);
    
    return 0;
}
