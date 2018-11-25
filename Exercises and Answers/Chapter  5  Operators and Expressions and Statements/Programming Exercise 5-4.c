/* Programming Exercise 5-4 */

// Write a program that asks the user to enter a height in centimeters and then displays the
// height in centimeters and in feet and inches. Fractional centimeters and inches should
// be allowed, and the program should allow the user to continue entering heights until a
// nonpositive value is entered. A sample run should look like this:

// Enter a height in centimeters: 182
// 182.0 cm = 5 feet, 11.7 inches
// Enter a height in centimeters (<=0 to quit): 168.7
// 168.0 cm = 5 feet, 6.4 inches
// Enter a height in centimeters (<=0 to quit): 0
// bye


#include <stdio.h>

int main(void)
{
	const float cmpf = 30.48; // centimeters_per_foot
	const float cmpi = 2.54;  // centimeters_per_inch
	float cm; //centimeters
	int feet;
	float inches;
	
	printf("Enter a height in centimeters: ");
	scanf("%f", &cm);
	while (cm > 0)
	{
		feet = cm / cmpf;
		inches = (cm - feet * cmpf) / cmpi;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inches);
		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &cm);
	}
	printf("bye\n");
	
	return 0;
}
