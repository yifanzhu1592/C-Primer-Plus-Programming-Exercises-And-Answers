/* Programming Exercise 5-1 */

// Write a program that converts time in minutes to time in hours and minutes. Use
// #define or const to create a symbolic constant for 60. Use a while loop to allow the
// user to enter values repeatedly and terminate the loop if a value for the time of 0 or less
// is entered.


#include <stdio.h>
#define mph 60 // minutes_per_hour

int main(void)
{
	int tim; // time_in_minutes
	int h;   // hours
	int m;   // minutes
	
	printf("Please enter the time to convert in minutes:\n");
	scanf("%d", &tim);
	while (tim > 0) 
	{
		h = tim / mph;
		m = tim % mph;
		printf("%d minutes equals to %d hours and %d minutes.\n", tim, h, m);
		printf("Please enter another time (<=0 to quit):\n");
		scanf("%d", &tim);
	}
	printf("See you next time!\n");
	
	return 0;
}
