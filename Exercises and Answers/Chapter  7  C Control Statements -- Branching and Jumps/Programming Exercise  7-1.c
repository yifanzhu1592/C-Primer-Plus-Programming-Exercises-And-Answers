/* Programming Exercise 7-1 */

// Write a program that reads input until encountering the # character and then reports
// the number of spaces read, the number of newline characters read, and then number of all
// other characters read.


#include <stdio.h>

int main(void)
{
	char ch;
	int ns = 0;  // the number of spaces read
	int nnc = 0; // the number of newline characters read
	int nao = 0; // the number of all other characters read
	
	printf("Please enter your characters:\n");
	
	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			ns++;
		else if (ch == '\n')
			nnc++;
		else
			nao++;
	}
	
	printf("The number of spaces read is %d.\n", ns);
	printf("The number of newline characters read is %d.\n", nnc);
	printf("The number of all other characters read is %d.\n", nao);
	
	return 0;
}
