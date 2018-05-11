/* Programming Exercise */

// In C, one function can call another. Write a program that calls a function named one_
// three(). This function should display the word one on one line, call a second function
// named two(), and then display the word three on one line. The function two() should
// display the word two on one line. The main() function should display the phrase
// starting now: before calling one_three() and display done! after calling it. Thus, the
// output should look like the following:

// starting now:
// one
// two
// three
// done!


#include <stdio.h>

void one_three();
void two();

int main()
{
	printf("starting now:\n");
	one_three();
	printf("done!\n");
	
	return 0;
}

void one_three()
{
	printf("one\n");
	two();
	printf("three\n");
}

void two()
{
	printf("two\n");
}
