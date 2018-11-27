/* Programming Exercise 6-8 */

// Write a program that requests two floating-point numbers and prints the value of their
// difference divided by their product. Have the program loop through pairs of input values
// until the user enters nonnumeric input.


#include <stdio.h>

int main(void)
{
	float a, b;
	float difference, product;
	
	printf("Please enter two floating-point numbers:\n");
	while (scanf("%f %f", &a, &b) == 2)
	{
		difference = a - b;
		product = a * b;
		printf("The value of their difference divided by their product is: %f\n", difference / product);
		printf("Please enter another pair (non-numeric to quit):\n");
	}
	printf("See you next time!\n");
	
	return 0;
}
