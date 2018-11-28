/* Programming Exercise 7-9 */

// Write a program that accepts a positive integer as input and then displays all the prime
// numbers smaller than or equal to that number.


#include <stdio.h>

int isprime(int i);

int main(void)
{
	int n, i;
	
	printf("Please enter a positive integer:\n");
	scanf("%d", &n);
	
	printf("All the prime numbers that smaller than or equal to %d are:\n", n);
	for (i = 2; i <= n; i++)
		if (isprime(i))
			printf("%d ", i); // if the number is prime, print it
	
	return 0;
}

int isprime(int i) // to judge whether the number is prime or not
{
	int j;
	for (j = 2; j * j <= i; j++)
	{
		if (i % j == 0)
			return 0; // if the number is not prime, return 0
		else
			continue;
	}
	return 1; // if the number is prime, return 1
}
