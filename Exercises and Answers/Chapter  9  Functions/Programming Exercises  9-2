/* Programming Exercise 9-2 */

// Devise a function chline(ch, i, j) that prints the requested character in columns i
// through j. Test it in a simple driver.


#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
	char ch;
	int i, j;
	
	printf("Please enter ch, i, j:\n");
	ch = getchar();
	scanf("%d %d", &i, &j);
	chline(ch, i, j);
	
	return 0;
}

void chline(char ch, int i, int j)
{
	int k;
	
	for (k = 0; k < i; k++)
		printf(" ");
	for (k = i; k <= j; k++)
		printf("%c", ch);
}
