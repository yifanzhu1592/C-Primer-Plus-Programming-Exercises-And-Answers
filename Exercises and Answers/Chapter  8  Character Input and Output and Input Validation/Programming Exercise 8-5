/* Programming Exercise 8-5 */

// Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing
// strategy. For example, have the program initially guess 50, and have it ask the user
// whether the guess is high, lower, or correct. If, say, the guess is low, have the next guess
// be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be
// halfway between 75 and 50, and so on. Using this binary search strategy, the program
// quickly zeros in on the correct answer, at least if the user does not cheat.


#include <stdio.h>

int main(void)
{
	char response;
	int guess = 50;
	int upper_limit = 100;
	int lower_limit = 0;
	
	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a l if my guess is lower, with a ");
	printf("h if it is higher and with a c if it is correct.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'c')
	{
		if (response == 'l')
		{
			lower_limit = guess;
			guess = (upper_limit + lower_limit) / 2;
		}
		else if (response == 'h')
		{
			upper_limit = guess;
			guess = (upper_limit + lower_limit) / 2;
		}
		else
		{
			printf("Please enter h or l or c.\n");
			while (getchar() != '\n')
				continue;
			continue;
		}
		
		printf("Well, then, is it %d?\n", guess);
		while (getchar() != '\n')
			continue;
	}
 	printf("I knew I could do it!\n");
	
	return 0;
}
