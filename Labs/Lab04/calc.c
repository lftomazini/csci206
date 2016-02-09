/* Luis Felipe Tomazini
 * T 1pm
 * lab 04 - calc.c
 * compile with: make calc
 * notes: A simple calculator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char* argv[]) {
    char* operation = argv[1];
    int i = 0;
    
    // If the only argument is the program name
    if (argc == 1) {
        printf("Usage: ./calc <operation> <arguments...>\n");
        return 0;
    }
    
    if (strcmp(operation, "add") == 0) {
        float sum = 0;
        // Argument 0 is program name and argument 1 is operation
        for (i = 2; i < argc; i++) {
            sum += atof(argv[i]);
        }
        printf("%f\n", sum);
        return 0;
    }
        
    if (strcmp(operation, "mult") == 0) {
        float product = 1;
        // Argument 0 is program name and argument 1 is operation
        for (i = 2; i < argc; i++) {
            product *= atof(argv[i]);
        }
        printf("%f\n", product);
        return 0;
    }
    
    if (strcmp(operation, "div") == 0) {
        // Argument 0 is program name and argument 1 is operation
        // Assign the value of the argument 2 for initial division
        float quotient = atof(argv[2]);
        // Starts iterating from the next index
        for (i = 3; i < argc; i++) {
            quotient /= atof(argv[i]);
        }
        printf("%f\n", quotient);
        return 0;
    }
    
    if (strcmp(operation, "len") == 0) {
        int strsize = 0;
        for (i = 2; i < argc; i++) {
            strsize += strlen(argv[i]);
        }
        printf("%d\n", strsize);
        return 0;
    }

    // If no operation is detected prints function names
    printf("Unsupported function, try: add, mult, div, or len\n");
    
    return (0);
}

