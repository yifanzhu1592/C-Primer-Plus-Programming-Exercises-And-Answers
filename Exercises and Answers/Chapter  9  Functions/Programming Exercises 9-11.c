/* Programming Exercises 9-11 */

// Write and test a Fibonacci() function that uses a loop instead of recursion to calculate
// Fibonacci numbers.


#include <stdio.h>

void Fibonacci(int n);

int main(void)
{
	int n;
	
	printf("Please enter an integer: ");
	scanf("%d", &n);
	Fibonacci(n);
	
	return 0;
}

void Fibonacci(int n)
{
	int Fn = 0; // Fibonacci numbers
	int Fn1 = 0;
	int Fn2 = 1;
	int counter = 0;
	
	printf("All Fibanocci numbers that smaller than %d are: \n", n);
	while (Fn < n)
	{
		printf("%d", Fn);
		printf("\n");
		Fn = Fn1 + Fn2;
		if (counter % 2 == 0)
			Fn1 = Fn;
		else
			Fn2 = Fn;
		counter++;
	}
}
