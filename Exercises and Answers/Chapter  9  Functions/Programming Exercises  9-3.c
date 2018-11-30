/* Programming Exercise 9-3 */

// Write a function that takes three arguments: a character and two integers. The character
// is to be printed. The first integer specifies the number of times that the character is to
// be printed on a line, and the second integer specifies the number of lines that are to be
// printed. Write a program that makes use of this function.


#include <stdio.h>

void function(char ch, int col, int row);

int main(void)
{
	char ch;
	int col, row;
	
	printf("Please enter the character: ");
	ch = getchar();
	printf("Please enter the number of columns and the number of rows: ");
	scanf("%d %d", &col, &row);
	function(ch, col, row);
	
	return 0;
}

void function(char ch, int col, int row)
{
	int c, r;
	
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
			printf("%c", ch);
		printf("\n");
	}
}
