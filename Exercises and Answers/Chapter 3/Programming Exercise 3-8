/* Programming Exercise 3-8 */

// In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an
// ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a
// volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons,
// and teaspoons. Why does a floating-point type make more sense for this application than
// an integer type?


#include <stdio.h>

int main(void)
{
	float cups, pints, ounces, tablespoons, teaspoons;
	
	printf("Please enter a volume in cups:\n");
	scanf("%f", &cups);
	
	pints = cups / 2;
	ounces = cups * 8;
	tablespoons = ounces * 2;
	teaspoons = tablespoons * 3;
	
	printf("%.2f cups equal %.2f pints.\n", cups, pints);
	printf("%.2f cups equal %.2f ounces.\n", cups, ounces);
	printf("%.2f cups equal %.2f tablespoons.\n", cups, tablespoons);
	printf("%.2f cups equal %.2f teaspoons.\n", cups, teaspoons);
	
	return 0;
}
