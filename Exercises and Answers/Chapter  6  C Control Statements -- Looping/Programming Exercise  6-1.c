/* Programming Exercise 6-1 */

// Write a program that creates an array with 26 elements and store the 26 lowercase
// letters in it. Also have it shows the array contents.


#include <stdio.h>
#define SIZE 26

int main(void)
{
	char lowercase[SIZE];
	int i;
	
	for (i = 0; i <= SIZE; i++)
		lowercase[i] = 'a' + i;
	
	printf("The array contents:\n");
	for (i = 0; i < SIZE; i++)
		printf("%c\n", lowercase[i]);
	
	return 0;
}
