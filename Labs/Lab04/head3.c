/* Luis Felipe Tomazini
 * T 1pm
 * lab 04 - head2.c
 * compile with: make head
 * notes: Reads a file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

int main(int argc, char* argv[]) {
    int readlines = 10;         // default to 10 lines
    char buffer[10][MAXBYTES+1];    // buffer to hold file data

    if (argc < 1){
        // missing required argument
        printf("Usage %s <filename>\n",
                argv[0]);
        exit(-1);
    }

    if (read_file_lines (argv[1], buffer) >= 0){
        int i = 0;
        for (i = 0; i < readlines; i++) {
            printf("%s", buffer[i]);
        }
    } else {
        printf("Error: could not read file!\n");
        exit(-3);
    }
    return 0;
}
