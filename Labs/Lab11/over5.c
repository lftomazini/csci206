#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The buffer has space for 14 characters + '\0'. The program copies "FirstName"
 * and then concatenates "LastName" into buffer. It results in a string of 17 characters + '\0'.
 * But this string is still written into buffer as shown by the printf function.
 */
int main(int argc, char** argv) {

	char name[15];

	strcpy(name, "FirstName");
	strcat(name, "LastName");

	printf("Name: %s\n", name);
	
	return(0);
}
