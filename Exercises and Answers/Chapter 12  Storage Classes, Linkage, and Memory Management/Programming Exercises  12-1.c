/* Programming Exercise 12-1.c */

// Rewrite the program in Listing 12.4 so that it does not use global variables.


#include <stdio.h>
void critic(int * u);
int main(void)
{
    int units;  /* units now local */
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int * u)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", u);
}

// or use a return value;
// units = critic();

// and have critic look like this:
/*
int critic(void)
{
    int u;
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &u);
    return u;
}
*/

// or have main() collect the next value for units
