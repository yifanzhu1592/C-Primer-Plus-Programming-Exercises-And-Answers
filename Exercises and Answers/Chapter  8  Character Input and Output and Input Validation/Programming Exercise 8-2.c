/* Programming Exercise 8-2 */

// Write a program that reads input as a stream of characters until encoutering EOF. Have
// the program print each input character and its ASCII decimal value. Note that characters
// preceding the space character in the ASCII sequence are nonprinting characters.
// Treat them specially. If the nonprinting character is a newline or tab, print \n or \t,
// respectively. Otherwise, use control-character notaion. For instance, ASCII 1 is Ctrl+A,
// which can be displayed as ^A. Note that the ASCII value for A is the value for Ctrl+A
// plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per
// line, except start a fresh line each time a newline character is encountered. (Note: The
// operating system may have special interpretations for some control characters and keep
// them from reaching the program.)


#include <stdio.h>

int main(void)
{
	char ch;
	int pairs = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (ch == 9)
			printf("\\t");
		else if (ch == 10)
		{
			printf("\\n");
			printf("-%d ", ch);
			printf("\n");
			pairs = 0;
			continue;
		}
		else if (ch < 32)
			printf("^%c", ch + 64);
		else
			printf("%c", ch);
        
		printf("-%d ", ch);
		pairs++;
		if (pairs % 10 == 0)
			printf("\n");
	}
	
	return 0;
}
