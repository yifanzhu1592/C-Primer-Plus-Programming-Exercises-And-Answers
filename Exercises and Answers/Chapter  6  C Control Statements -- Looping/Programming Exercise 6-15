 /* Programming Exercise 6-15 */
 
 // Write a program that reads in a line of input and then prints the line in reverse order.
 // You can store the input in an array of char; assume that the line is no longer than 255
 // characters. Recall that you can use scanf() with the %c specifier to read a character at
 // a time from input and that the newline character (\n) is generated when you press the
 // Enter key.
 
 
#include <stdio.h>

int main(void)
{
	int i = 0;
	char a[255];
	
	printf("Please enter a line of input:\n");
	do
	{
		scanf("%c", &a[i]);
		i++;
	} while (a[i - 1] != '\n'); // begin with a[0]
	
	while (i >= 2) // loop until a[0]
	{
		printf("%c", a[i - 2]); // begin with a[i - 2] so "\n" won't be printed
		i--;
	}
	printf("\n");
	printf("See you next time!\n");
	
	return 0;
}
