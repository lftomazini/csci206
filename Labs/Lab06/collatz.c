/* Luis Felipe Tomazini
 * T 1pm
 * lab 06 - collatz.c
 * compile with: make
 * notes: Returns number of calls to collatz
 */

#include <stdio.h>
#define MAX_ITEMS 100

int collatz(int n) {
    if (n == 1) {
        return 1;
    } else if ((n % 2) == 0) {
        return 1 + collatz(n / 2);
    } else {
        return 1 + collatz(3 * n + 1);
    }
}

int find_length(int n) {
    return (n <= 1) ? 1 : collatz(n);
}

int main(void)
{
    int i;

    for (i = 1; i < MAX_ITEMS; i++){
        printf("%d ==> %d\n", i, find_length(i));
    }

    return 0;
}