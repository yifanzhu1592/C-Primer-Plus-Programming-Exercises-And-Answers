/* Programming Exercise 6-7 */

// Write a program that reads a single word into a character array and then prints the word
// backward. Hint: Use strlen() (Chapter 4) to compute the index of the last character in
// the array.


#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[20];
	int index;
	
	printf("Please enter a single word:\n");
	scanf("%s", a);
	for (index = strlen(a); index > 0; index--)
		printf("%c", a[index - 1]);
		
	return 0;
}
