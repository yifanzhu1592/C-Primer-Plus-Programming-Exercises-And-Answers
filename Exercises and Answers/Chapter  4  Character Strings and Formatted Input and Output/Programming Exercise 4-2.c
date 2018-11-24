/* Programming Exercise 4-2 */

// Write a program that requests your first name and does the following with it:

//  a. Prints it enclosed in double quotation marks
//  b. Prints it in a field 20 characters wide, with the whole field in quotes and the name
//     at the right end of the field
//  c. Prints it at the left end of a field 20 characters wide, with the whole field enclosed
//  d. Prints it in a field three characters wider than the name


#include <stdio.h>
#include <string.h>

int main(void)
{
	char fname[10];
	
	printf("Please enter your first name:\n");
	scanf("%s", fname);
	
	printf("\"%s\"\n", fname);
	printf("\"%20s\"\n", fname);
	printf("\"%-20s\"\n", fname);
	printf("%*s\n", strlen(fname) + 3, fname);
	
	return 0;
}
