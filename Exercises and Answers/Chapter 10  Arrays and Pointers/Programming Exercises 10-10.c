/* Programming Exercises 10-10.c */

// Write a function that sets each element in an array to the sum of the corresponding
// elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2
// has the values 1, 0, 4, and 6, the function assigns the array 3 the values 3, 4, 9, and 14. The
// function should take three array names and an array size as arguments. Test the function
// in a simple program.


#include <stdio.h>
#define SIZE 4

void function(int array1[], int array2[], int array3[], int number);

int main(void)
{
    int array1[SIZE] = {2, 4, 5, 8};
    int array2[SIZE] = {1, 0, 4, 6};
    int array3[SIZE];

    function(array1, array2, array3, SIZE);

    printf("The contents of the third array:\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("%d ", array3[j]);
    }
    printf("\n");

    return 0;
}

void function(int array1[], int array2[], int array3[], int number)
{
    for (int i = 0; i < number; i++)
    {
        array3[i] = array1[i] + array2[i];
    }
}
