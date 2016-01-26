/* Luis Felipe Tomazini
 * T 1pm
 * lab 02 - salary.c
 * compile with: make switchcase
 * notes: Converts a string to uppercase
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int MAX_STRING_SIZE = 256;
    char string[MAX_STRING_SIZE];

    // this loop will read one line of input at a time
    // if EOF is reached, the loop will exit.
    while ( fgets(string, MAX_STRING_SIZE, stdin) ){

        /* convert the string here */
        int i=0;
	for (i = 0; i < MAX_STRING_SIZE; i++){
            string[i] = toupper(string[i]);
        }

        // print the result
        printf("%s", string);
    }

    return 0;
}
