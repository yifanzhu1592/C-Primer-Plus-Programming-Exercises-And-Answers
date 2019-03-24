/* Programming Exercise 12-6.c */

// Write a program that generates 1,000 random numbers in the range 1-10. Don't save or
// print the numbers, but do print how many times each number was produced. Have the
// program do this for 10 different seed values. Do the numbers appear in equal amounts?
// You can use the functions from this chapter or the ANSI C rand() and srand()
// functions, which follow the same format that our functions do. This is one way to
// examine the randomness of a particular random-number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define TIMES 1000
int main(void)
{
    int i, j, k;
    int arr[SIZE];

    for (j = 0; j < 10; j++)
    {
        printf("Round %d\n", j);
        srand((unsigned int) time(NULL));
        for (i = 0; i < TIMES; i++)
        {
            arr[rand() % 10]++;
        }
        puts("The times each number was produced:\n");
        for (k = 0; k < 10; k++)
        {
            printf("%d: %dtimes\n", k + 1, arr[k]);
        }
        puts("\n");
    }

    return 0;
}
