/* Programming Exercise 12-5.c */

// Write a program that generates a list of 100 random numbers in the range 1-10
// in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11,
// "Character Strings and String Functions,", to type int. In this case, just sort the numbers
// themselves.)


#include <stdio.h>
#include <stdlib.h>
void print(const int array[], int limit);
void sort(int array[], int limit);

#define SIZE 100
int main(void)
{
    int i;
    int arr[SIZE];

    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 10 + 1;
    puts("initial array");
    print(arr, SIZE);
    sort(arr, SIZE);
    puts("\nsorted array");
    print(arr, SIZE);

    return 0;
}

/* sort.c -- sorts an integer array in decreasing order */
void sort(int array[], int limit)
{
    int top, search, temp;

    for (top = 0; top < limit - 1; top++)
        for (search = top + 1; search < limit; search++)
            if (array[search] > array[top])
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
}

/* print.c -- prints an array */
void print(const int array[], int limit)
{
    int index;

    for (index = 0; index < limit; index++)
    {
        printf("%2d ", array[index]);
        if (index % 10 == 9)
            putchar('\n');
    }
    if (index % 10 != 0) // if last line not complete
        putchar('\n');
}
