/* Programming Exercise 7-5 */

// Redo exercise 4 using a switch.


#include <stdio.h>

int main(void)
{
	char ch;
	int count = 0;
	
	printf("Please enter your characters:\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '.' : putchar('!');
			           count++;
			           continue;
			
			case '!' : putchar('!');
			           putchar('!');
			           count++;
			           continue;
			
			default  : putchar(ch);
		}
	}
	printf("\n");
	
	printf("It has made %d substitutions.\n", count);
	
	return 0;
}
