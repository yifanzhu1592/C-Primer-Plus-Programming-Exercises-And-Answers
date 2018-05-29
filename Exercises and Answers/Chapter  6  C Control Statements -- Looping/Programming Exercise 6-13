/* Programming Exercise 6-13 */

// Write a program that creates an eight-element array of ints and sets the elements to the
// first eight powers of 2 and then prints the values. Use a for loop to set the values, and,
// for variety, use a do while loop to display the values.


#include <stdio.h>
#define SIZE 8

int main(void)
{
	int two_powers[SIZE];
	int value = 1; // 2^0 = 1
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		two_powers[i] = value;
		value *= 2;
	}
	
	i = 0;
	
	do
	{
		printf("%d ", two_powers[i]);
		i++;
	} while (i < SIZE);
	
	return 0;
}
