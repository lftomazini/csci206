/* Luis Felipe Tomazini
 * T 1pm
 * lab 07 - time.c
 * compile with: make
 * notes: print time
 */

#include <stdio.h>
#include <time.h>

void add_second(struct tm tm);

int main(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    printf ("it is now: %s\n", asctime(tm));
    int i = 0;
    for (i = 0; i < 2345; i++) {
        add_second(tm);
    }
    return 0;
}
