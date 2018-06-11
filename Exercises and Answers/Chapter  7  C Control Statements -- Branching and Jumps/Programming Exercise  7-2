/* Programming Exercise 7-2 */

// Write a program that reads input until encoutering #. Have the program print each
// input character and its ASCII decimal code. Print eight character-code pairs per line.
// Suggestion: Use a character count and the modulus operator (%) to print a newline
// character for every eight cycles of the loop.


#include <stdio.h>
#define ppl 8 // pairs per line

int main(void)
{
	char ch;
	int count = 0;
	
	printf("Please enter your characters:\n");
	while ((ch = getchar()) != '#')
	{
		count++;
		printf("%c-%3d ", ch, ch);
		
		if (count % ppl == 0)
			printf("\n");
	}
	
	return 0;
}
