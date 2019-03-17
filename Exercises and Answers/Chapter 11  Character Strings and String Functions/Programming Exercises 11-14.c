/* Programming Exercise 11-14 */

// Write a power-law program that works on a command-line basis. The first command-line
// argument should be the type double number to be raised to a certain power, and the
// second argument should be the integer power.


#include <stdio.h>
#include <stdlib.h>      /* for atof() */
#include <math.h>        /* for pow()  */

int main(int argc, char *argv[])
{
	double num, exp;

	if (argc != 3)
		printf("Usage: %s number exponent\n", argv[0]);
	else
	{
		num = atof(argv[1]);
		exp = atof(argv[2]);
		printf("%f to the %f power = %g\n", num, exp, pow(num, exp));
	}

	return 0;
}
