/* Programming Exercise 7-4 */

// Using if else statements, write a program that reads input up to #, replaces each period
// with an exclamation mark, replaces each exclamation mark initially present with two
// exclamation marks, and reports at the end the number of substitutions it has made.


#include <stdio.h>

int main(void)
{
	char ch;
	int count = 0;
	
	printf("Please enter your characters:\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			putchar('!');
			count++;
		}
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
			count++;
		}
		else
			putchar(ch);
	}
	printf("\n");
	
	printf("It has made %d substitutions.\n", count);
	
	return 0;
}
