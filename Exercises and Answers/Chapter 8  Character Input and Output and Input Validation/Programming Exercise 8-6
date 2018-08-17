/* Programming Exercise 8-6 */

// Modify the get_first() function of Listing 8.8 so that it returns the first non-
// whitespace character encountered. Test it in a simple program.


#include <stdio.h>

char get_first(void);

int main(void)
{
	char fnc; //The first non-whitespace character
	
	printf("Enter your characters: ");
	fnc = get_first(); 
	printf("The first non-whitespace character encountered is %c.\n", fnc);
	
	return 0;
}

char get_first(void)
{
	char ch;
	
	while ((ch = getchar()) == ' ')
		continue;
	while (getchar() != '\n')
		continue;
	
	return ch;
}
