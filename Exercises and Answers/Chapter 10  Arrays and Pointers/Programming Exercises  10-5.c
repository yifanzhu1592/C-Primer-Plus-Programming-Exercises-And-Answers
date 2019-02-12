/* Programming Exercises 10-5.c */

// Write a function that returns the difference between the largest and smallest elements of
// an array-of-double. Test the function in a simple program.


#include <stdio.h>
#define SIZE 3

double function(double array[], int number);

int main(void)
{
	double array[SIZE] = {1.2, 2.3, 3.4};
	
	printf("The largest value stored in the array is %.1lf.\n", function(array, SIZE));
	
	return 0;
}

double function(double array[], int number)
{
	double largest = *array;
	double smallest = *array;
	
	for (int i = 0; i < number; i++)
	{
		if (largest < *(array + i))
			largest = *(array + i);
		if (smallest > *(array + i))
			smallest = *(array + i);
	}
	
	return largest - smallest;
}
