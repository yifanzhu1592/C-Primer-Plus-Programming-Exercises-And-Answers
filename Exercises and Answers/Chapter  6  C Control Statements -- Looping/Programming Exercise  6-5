/* Programming Exercise 6-5 */

// Have a program request the user to enter an uppercase letter. Use nested loops to produce
// a pyramid pattern like this:

//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA

// The pattern should extend to the character entered. For example, the preceding pattern
// would result from the input value of E. Hint: Use an outer loop to handle the rows. Use
// three inner loops in a row, one to handle the spaces, one for printing letters in ascending
// order, and one for printing letters in descending order. If your system doesn't use ASCII
// or a similar system that represents letters in a strict number order, see the suggestion in
// programming exercise 3.


#include <stdio.h>

int main(void)
{
	int row, space;
	char ch, ch1; // use "ch1" to make the value of "ch" unchangeable

	printf("Please enter an uppercase letter:\n");
	scanf("%c", &ch);
	ch1 = ch;
	
	for (row = 0; row < ch - 'A' + 1; row++)
	{
		for (space = 0; space < ch - 'A' - row; space++)
			printf(" ");
			
		for (ch = 'A'; ch < 'A' + row + 1; ch++)
			printf("%c", ch);
		
		for (ch = 'A' + row - 1; ch >= 'A'; ch--)
			printf("%c", ch);
			
		printf("\n");
		ch = ch1; // set "ch" to its initial value
	}
	
	return 0;
}
