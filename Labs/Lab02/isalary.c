/* Luis Felipe Tomazini
 * T 1pm
 * lab 02 - salary.c
 * compile with: make salary
 * notes: Calculates yearly salary
 */
#include <stdio.h>

int main(void) {
   int hourlyWage;

    printf("Enter hourly wage (integer): ");
    scanf("%d", &hourlyWage);

   printf("Annual salary is: ");
   printf("%d", hourlyWage * 40 * 50);
   printf("\n");

   return 0;
}
