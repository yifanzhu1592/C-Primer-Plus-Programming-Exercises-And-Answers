/* Programming Exercises 10-8.c */

// Use a copy function from Programming Exercise 2 to copy the third through fifth
// elements of a seven-element array into a three-element array. The function itself need
// not be altered; just choose the right actual arguments. (The actual arguments need not be
// an array name and array size. They only have to be the address of an array element and a
// number of elements to be processed.)


#include <stdio.h>

void copy_arr(double target[], double source[], int number);

int main(void)
{
	double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target[3];
	copy_arr(target, &source[2], 3);

	for (int x = 0; x < 3; x++)
	{
		printf("%.1lf ", target[x]);
	}
	printf("\n");

	return 0;
}

void copy_arr(double target[], double source[], int number)
{
	for (int i = 0; i < number; i++)
	{
		target[i] = source[i];
	}
}
