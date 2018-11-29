/* Programming Exercise 8-3 */

// Write a program that reads input as a stream of characters until encountering EOF.
// Have it report the number of uppercase letters, the number of lowercase letters, and the
// number of other characters in the input. You may assume that the numeric values for the
// lowercase letters are sequantial and assume the same for uppercase. Or, more portably,
// you can use appropriate classification functions from the ctype.h library.


#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int num_of_upper = 0, num_of_lower = 0,
	    num_of_other = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			num_of_upper++;
		else if (islower(ch))
			num_of_lower++;
		else
			num_of_other++;
	}
	
	printf("The number of uppercase letters is %d,\n"
	       "the number of lowercase letters is %d,\n"
		   "and the number of other characters is %d.\n",
		   num_of_upper, num_of_lower, num_of_other);
	
	return 0;
}
