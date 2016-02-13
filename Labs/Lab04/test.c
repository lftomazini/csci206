//
//  test.c
//  
//
//  Created by Luís Felipe on 2/13/16.
//
//

#include <stdio.h>
#include <string.h>
int main() {
    char c[13];
    strcpy(c, "--creat(");
    printf("size of %s is %lu\n", c, strlen(c));
    
    strcpy(c, "--creat(2)-");
    printf("size of %s is %lu\n", c, strlen(c));
    return 0;
}