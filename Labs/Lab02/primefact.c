/* Luis Felipe Tomazini
 * T 1pm
 * lab 02 - primefact.c
 * compile with: make primefact
 * notes: Calculates prime factors
 * The running time por the Python implementation of the algorithm was of 3.193 seconds,
 * as the C code was in 0.086 seconds. The implementation in C was more than 37 times faster
 * when compared to the same algorithm implemented in Python
 */
#include <stdio.h>

int main(void) {
    int n = 2147483645;
    int i = 2 ;
    while (i <= n){
        if (n % i == 0){
            printf("%d\n", i);
            n /= i;
            i -= 1;
        }
        i += 1;
    }
    return 0;
}










