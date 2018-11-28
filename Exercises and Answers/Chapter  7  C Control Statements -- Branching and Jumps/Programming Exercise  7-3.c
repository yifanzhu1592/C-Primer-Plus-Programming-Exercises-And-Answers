/* Programming Exercise 7-3 */

// Write a program that reads integers until 0 is entered. After input terminates, the
// program should report the total number of even integers (excluding the 0) entered, the
// average value of the even integers, the total number of odd integers entered, and the
// average value of the odd integers.


#include <stdio.h>

int main(void)
{
	int i;
	float sum_even = 0, sum_odd = 0;    // the total number of two respectively
	int count_even = 0, count_odd = 0;  // the number of two respectively
	float average_even, average_odd;    // the average value of two respectively
	
	printf("Please enter your numbers:\n");
	while (scanf("%d", &i) == 1 && i != 0)
	{
		if (i % 2 == 0)
		{
			sum_even += i;
			count_even++;
		}
		else
		{
			sum_odd += i;
			count_odd++;
		}
	}
	
	average_even = sum_even / count_even;
	average_odd = sum_odd / count_odd;
	
	printf("The number of evens: %d\n", count_even);
	if (count_even > 0)
		printf("The average value of evens: %g\n", average_even);
	
	printf("The number of odds: %d\n", count_odd);
	if (count_odd > 0)
		printf("The average value of odds: %g\n", average_odd);
			
	return 0;
}
