/* Programming Exercises 10-4.c */

// Write a function that returns the index of the largest value stored in an array-of-double.
// Test the function in a simple program.


#include <stdio.h>
#define SIZE 3

int function(double array[], int number);

int main(void)
{
	double array[SIZE] = {1.1, 2.2, 3.3};
	
	printf("The index of the largest value stored in the array is %d.\n", function(array, SIZE));
	
	return 0;
}

int function(double array[], int number)
{
	int largest = *array;
	int largest_index = 0;
	
	for (int i = 0; i < number; i++)
	{
		if (largest < *(array + i))
		{
			largest = *(array + i);
			largest_index = i;
		}
	}
	
	return largest_index;
}
