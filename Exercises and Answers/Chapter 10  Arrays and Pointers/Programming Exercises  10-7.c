/* Programming Exercises 10-7.c */

// Write a program that initializes a two-dimensional array-of-double and uses one of the
// copy function from exercise 2 to copy it to a second two-dimensional array. (Because a
// two-dimensional array is an array of arrays, a one-dimensional copy function can be used
// with each subarray.)


#include <stdio.h>

void copy_ptr(double target[], double source[], int number);

int main(void)
{
	double source[2][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
	double target[2][3];
	for (int i = 0; i < 2; i++)
	{
	    copy_ptr(target[i], source[i], 3);
	}

	for (int y = 0; y < 2; y++)
	{
	    for (int x = 0; x < 3; x++)
	    {
		    printf("%.1lf ", target[y][x]);
	    }
	}
	printf("\n");

	return 0;
}

void copy_ptr(double target[], double source[], int number)
{
	for (int j = 0; j < number; j++)
	{
		*(target + j) = *(source + j);
	}
}
