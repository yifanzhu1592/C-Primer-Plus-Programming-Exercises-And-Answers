/* Programming Exercise 12-4.c */

// Write and test in a loop a function that returns the number of times it has been called.


#include <stdio.h>

int function();

int main(void)
{
    int times;
    scanf("%d", &times);

    for (int i = 0; i < times; i++)
    {
        printf("The function has been called for %d times.\n", function());
    }

    return 0;
}

int function()
{
    static int times = 0;

    return ++times;
}
