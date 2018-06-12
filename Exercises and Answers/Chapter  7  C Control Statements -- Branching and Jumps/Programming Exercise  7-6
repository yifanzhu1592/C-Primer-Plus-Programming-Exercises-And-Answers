/* Programming Exercise 7-6 */

// Write a program that reads input up to # and reports the number of times that the
// sequence ei occurs.

// Note:
// The program will have to "remember" the preceding character as well as the current character.
// Test it with input such as "Receive your eieio award."


#include <stdio.h>

int main(void)
{
	char ch;
	int flag = 0;
	int count = 0;
	
	printf("Please enter your characters:\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == 'e')
			flag = 1;
		else if (ch == 'i' && flag == 1)
		{
			count++;
			flag = 0;
		}
		else
			flag = 0;
	}
	
	printf("The number of times that the sequence ei occurs is %d.\n", count);
	
	return 0;
}
