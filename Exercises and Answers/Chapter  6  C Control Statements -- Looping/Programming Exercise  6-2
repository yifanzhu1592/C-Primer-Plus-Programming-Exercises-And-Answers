/* Programming Exercise 6-2 */

// Use nested loops to produce the following pattern:

// $
// $$
// $$$
// $$$$
// $$$$$


#include <stdio.h>
#define ROWS 5  

int main(void)
{
	int row;
	int column;
	
	for (row = 0; row < ROWS; row++)
	{
		for (column = 0; column <= row; column++) // In row 'n', there are 'n+1' columns
			printf("$");
		printf("\n");
	}
	
	return 0;
}
