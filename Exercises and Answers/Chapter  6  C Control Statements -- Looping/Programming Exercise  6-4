/* Programming Exercise 6-4 */

// Use nested loops to produce the following pattern:

// A
// BC
// DEF
// GHIJ
// KLMNO
// PORSTU

// If your system doesn't encode letters in numeric order, see the suggestion in
// programming exercise 3.


#include <stdio.h>
#define ROWS 6

int main(void)
{
	int row, count = 0;
	char ch;
	
	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'A' + count; ch <= 'A'+ count + row; ch++)
			printf("%c", ch);
		count += row + 1;
		printf("\n");
	}
	
	return 0;
}
