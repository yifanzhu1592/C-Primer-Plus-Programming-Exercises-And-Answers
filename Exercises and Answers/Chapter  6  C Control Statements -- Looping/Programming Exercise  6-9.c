/* Programming Exercise 6-9 */

// Modify exercise 8 so that it uses a function to return the value of the calculation.


#include <stdio.h>

float calculation(int a, int b);

int main(void)
{
	float a, b;
	
	printf("Please enter two floating-point numbers:\n");
	while (scanf("%f %f", &a, &b) == 2)
	{
		printf("The value of their difference divided by their product is: %f\n", calculation(a, b));
		printf("Please enter another pair (non-numeric to quit):\n");
	}
	printf("See you next time!\n");
	
	return 0;
}

float calculation(int a, int b)
{
	float difference, product, answer;
	
	difference = a - b;
	product = a * b;
	answer = difference / product;
	
	return answer;
}
