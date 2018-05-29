/* Programming Exercise 6-12 */

// Consider these two infinite series:

// 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...

// Write a program that evaluates running totals of these two series up to some limit of
// number of terms. Hint: -1 times itself an odd number of times is -1, and -1 times itself
// an even number of times is 1. Have the user enter the limit interactively; let a zero or
// negative value terminate input. Look at the running totals after 100 terms, 1000 terms,
// 10,000 terms. Does either series appear to be converging to some value?


#include <stdio.h>

int main(void)
{
	int n, sign = 1;
	float i, answer1 = 0, answer2 = 0;
	
	printf("Please enter the number of terms:\n");
	scanf("%d", &n);
	
	while (n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			answer1 += 1 / i;
			answer2 += 1 / i * sign;
			sign = -sign;
		}
		printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... 1.0/%d.0 = %f\n", n, answer1);
		printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... 1.0/%d.0 = %f\n", n, answer2);
		printf("Please enter the next number of terms (zero or negative to terminate):\n");
		scanf("%d", &n);
		answer1 = 0;
		answer2 = 0;
	}
	printf("See you next time!\n");
	
	return 0;
}
