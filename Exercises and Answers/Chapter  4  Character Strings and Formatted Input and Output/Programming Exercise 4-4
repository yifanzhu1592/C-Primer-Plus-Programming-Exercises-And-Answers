/* Programming Exercise 4-4 */

// Write a program that requests your height in inches and your name, and then displays
// the information in the following form:

// Dabney, you are 6.208 feet tall

// Use type float, and use / for division. If you prefer, request the height in centimeters
// and display it in meters.


#include <stdio.h>

int main(void)
{
	float centimeters, meters;
	char name[10];
	
	printf("Please enter your height in centimeters:\n");
	scanf("%f", &centimeters);
	printf("Please enter your name:\n");
	scanf("%s", &name);
	
	meters = centimeters / 100;
	printf("%s, you are %.2f meters tall.\n", name, meters);
	
	return 0;
}
