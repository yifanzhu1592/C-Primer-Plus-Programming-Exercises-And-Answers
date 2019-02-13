/* Programming Exercises 10-6.c */

// Write a function that reverses the contents of an array of double and test it in a simple
// program.


#include <stdio.h>
#define SIZE 3

void reverse(double array[], int number);

int main(void)
{
	double array[SIZE] = {1.1, 2.2, 3.3};
	
	printf("The contents of the array are:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%.1lf\n", array[i]);
	
	reverse(array, SIZE);
	
	printf("\nThe contents of the array now are:\n");
	for (int j = 0; j < SIZE; j++)
		printf("%.1lf\n", array[j]);
	
	return 0;
}

void reverse(double array[], int number)
{
	double temp;
	
	for (int k = 0; k < number / 2; k++)
	{
		temp = *(array + k);
		*(array + k) = *(array + number - k - 1);
		*(array + number - k - 1) = temp;
	}
}
