/* Programming Exercises 9-1 */

// Devise a function called min(x,y) that returns the smaller of two double values. Test
// the function with a simple driver.


#include <stdio.h>

double min(double a, double b);

int main(void)
{
	double x, y;
	
	printf("Please enter two numbers (q to quit): ");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The smaller one is %lf.\n", min(x, y));
		printf("The next two numbers (q to quit): ");
	}
	
	printf("See you!\n");
	
	return 0;
}

double min(double a, double b)
{
	return a < b ? a : b;
}
