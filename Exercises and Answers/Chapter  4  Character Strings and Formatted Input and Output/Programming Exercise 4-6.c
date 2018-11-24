/* Programming Exercise 4-6 */

// Write a program that requests the user's first name and then the user's last name. Have
// it print the entered names on one line and the number of letters in each name on the
// following line. Align each letter count with the end of the corresponding name, as in the
// following:

// Melissa Honeybee
//       7        8

// Next, have it print the same information, but with the counts aligned with the beginning
// of each name.

// Melissa Honeybee
// 7       8


#include <stdio.h>
#include <string.h>

int main(void)
{
	char fname[10], lname[10];
	
	printf("Please enter your first name:\n");
	scanf("%s", &fname);
	printf("Please enter your last name:\n");
	scanf("%s", &lname);
	
	printf("%s %s\n", fname, lname);
	printf("%*d %*d\n", strlen(fname), strlen(fname), strlen(lname), strlen(lname));
	printf("%s %s\n", fname, lname);
	printf("%-*d %-*d\n", strlen(fname), strlen(fname), strlen(lname), strlen(lname));
	
	return 0;
}
