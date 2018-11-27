/* Programming Exercise 6-3 */

// Use nested loops to produce the following pattern:

// F
// FE
// FED
// FEDC
// FEDCB
// FEDCBA

// Note: If your system doesn't use ASCII or some other code that encodes letters in
// numeric order, you can use the following to initialize a character array to the letters of the alphabet:

// char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Then you can use the array index to select inividual letters; for example, lets[0] is
// 'A', and so on.


#include <stdio.h>
#define ROWS 6

int main(void)
{
	int row;
	char ch;
	
	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'F'; ch >= 'F' - row; ch--)
			printf("%c", ch);
		printf("\n");
	}
	
	return 0;
}
