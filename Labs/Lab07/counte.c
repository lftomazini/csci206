/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - counte.c
 * compile with: make
 * notes: count number of e's in a string
 */

#include <stdio.h>

int counte(char* myString);

int main (void) {
    char myString[30];
    
    printf("Type a string: ");
    scanf("%s", myString);
    
    int count = counte(myString);
    printf("There are %d e's\n", count);
    
    return 0;
}
