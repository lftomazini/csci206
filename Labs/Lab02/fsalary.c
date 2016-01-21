/* Luis Felipe Tomazini
 * T 1pm
 * lab 02 - salary.c
 * compile with: make salary
 * notes: Calculates yearly salary
 */
#include <stdio.h>

int main(void) {
    float hourlyWage;
    int weeksWorked;

    printf("Enter hourly wage (float): ");
    scanf("%f", &hourlyWage);

    printf("Enter weeks worked (integer): ");
    scanf("%d", &weeksWorked);

   printf("Annual salary is: $");
   printf("%.2f", hourlyWage * weeksWorked * 40);
   printf("\n");

   return 0;
}
