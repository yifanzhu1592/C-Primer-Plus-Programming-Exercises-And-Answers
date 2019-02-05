/* Programming Exercises 10-3 */

// Write a function that returns the largest value stored in an array-int. Test the function
// in a simple program.


#include <stdio.h>
#define SIZE 3

int function(int array[], int number);

int main(void)
{
	int array[SIZE] = {1, 2, 3};
	
	printf("The largest value stored in the array is %d.\n", function(array, SIZE));
	
	return 0;
}

int function(int array[], int number)
{
	int largest = *array;
	
	for (int i = 0; i < number; i++)
	{
		if (largest < *(array + i))
			largest = *(array + i);
	}
	
	return largest;
}
