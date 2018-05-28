/* Programming Exercise 6-10 */

// Write a program that requests lower and upper integer limits, calculates the sum of all
// the integer squares from the square of the lower limit to the square of the upper limit,
// and displays the answer. The program should then continue to prompt for limits and
// display answers until the user enters an upper limit that is equal to or less than the lower
// limit. A sample run should look something like this:

// Enter lower and upper integer limits: 5 9
// The sums of the squares from 25 to 81 is 255
// Enter next set of limits: 3 25
// The sums of the squares from 9 to 625 is 5520
// Enter next set of limits: 5 5
// Done


#include <stdio.h>

int main(void)
{
	int ll, ul, answer, i;
	
	printf("Enter lower and upper integer limits: ");
	scanf("%d %d", &ll, &ul);
	while (ll < ul)
	{
		answer = 0;
		for (i = ll; i <= ul; i++)
			answer += i * i;
		printf("The sum of the squares from %d to %d is %d\n", ll * ll, ul * ul, answer);
		printf("Enter next set of limits: ");
		scanf("%d %d", &ll, &ul);
	}
	
	printf("See you next time!\n");
	
	return 0;
}
