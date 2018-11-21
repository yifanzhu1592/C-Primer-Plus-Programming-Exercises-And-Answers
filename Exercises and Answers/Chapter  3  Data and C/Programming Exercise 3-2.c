/* Programming Exercise 3-2 */

// Write a program that asks you to enter an ASCII code value, such as 66, and then prints
// the character having that ASCII code.


#include <stdio.h>

int main(void)
{
	char ascii;
	
	printf("Enter an ASCII code value:\n");
	scanf("%d", &ascii);
	printf("The character having ASCII code %d is %c.\n", ascii, ascii);
	
	return 0;
}
