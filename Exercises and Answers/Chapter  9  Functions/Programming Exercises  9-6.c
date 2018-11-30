/* Programming Exercises 9-6 */

// Write and test a function that takes the addresses of three double variables as arguments
// and that moves the value of the smallest variable into the first variable, the middle value
// to the second variable, and the largest value into the third variable.


#include <stdio.h>

void function(double &i, double &j, double &k);

int main(void)
{
	double i, j, k;
	
	printf("Please enter three numbers: ");
	while (scanf("%lf %lf %lf", &i, &j, &k) == 3)
	{
		function(i, j, k);
		printf("Now, after being reset, from the smallest to the biggest, they are: %lf %lf %lf.\n", i, j, k);
		printf("Please enter the next three numbers (# to quit): ");
	}
	
	printf("Bye!\n");
	
	return 0;
}

void function(double &i, double &j, double &k)
{
	double temp, temp1;
	
	if (i < j)
		if (i < k)
		{
			if (j > k)
			{
				temp = j;
				j = k;
				k = temp;
			}
		}
		else
		{
			temp = i;
			i = k;
			temp1 = j;
			j = temp;
			k = temp1;
		}
	else
	{
		if (i < k)
		{
			temp = i;
			i = j;
			j = temp;
		}
		else
		{
			if (j < k)
			{
				temp = i;
				i = j;
				temp1 = k;
				j = k;
				k = temp;
			}
			else
			{
				temp = i;
				i = k;
				k = temp;
			}
		}
	}
}
