/* Programming Exercise 16-5.c */

// Write a function that takes as arguments the name of an array of type int elements, the
// size of an array, and a value representing the number of picks. The function then should
// select the indicated number of items at random from the array and prints them. No
// array element is to be picked more than once. (This simulates picking lottery numbers or
// jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a
// similar function available, use its output with srand() to initialize the rand() random-
// number generator. Write a simple program that tests the function.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_pick(int ar[], int arsize, int picks);
#define SPOTS 51
#define PICKS 6
int main(void)
{
    int lotto[SPOTS];
    int i;
    char ch;

    for (i = 0; i < SPOTS; i++)
        lotto[i] = i + 1;

    do {
        random_pick(lotto, SPOTS, PICKS);
        printf("Again? <y/n> ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    } while (ch == 'y' || ch == 'Y');

    puts("Done");
    return 0;
}

void random_pick(int ar[], int arsize, int picks)
{
    int i, index, temp;

    srand((unsigned int) time(0));
    if (picks > arsize)
    {
        fputs("Number of picks > array size\n", stderr);
        fputs("Setting picks = array size\n", stderr);
        picks = arsize;
    }
    for (i = 0; i < picks; i++)
    {
        index = rand() % (arsize - 1); /* pick a random element     */
        temp = ar[index];
        printf("%2d ", temp);          /* display it                */
        if (i % 20 == 19)
            putchar('\n');
        ar[index] = ar[arsize - 1];    /* swap it with last element */
        ar[arsize - 1] = temp;
        arsize--;                      /* exclude end from search   */
    }
    if (i % 20 != 0)
        putchar('\n');
}
