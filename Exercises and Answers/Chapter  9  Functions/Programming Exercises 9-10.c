/* Programming Exercises 9-10 */

// Generalize the to_binary() function of Listing 9.8 to a to_base_n() function that
// takes a second argument in the range 2-10. It then should print the number that is its
// first argument to the number base given by the second argument. For example, to_
// base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a
// complete program.


#include <stdio.h>

void to_base_n(unsigned long n, unsigned base);

int main(void)
{
	unsigned long number;
	unsigned base;
	int count;
	
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu", &number) == 1)
	{
		printf("Please enter the number base (2-10): ");
		while ((count = scanf("%u", &base)) == 1 && (base < 2 || base > 10))
			printf("The base should be in the range 2-10: \n");
		if (count != 1)
			break;
		printf("Base-%u equivalent: ", base);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");
	
	return 0;
}

void to_base_n(unsigned long n, unsigned base)
{
	int r;
	r = n % base;
	if (n >= base)
		to_base_n(n / base, base);
	putchar('0' + r);
	
	return;
}
