/* Programming Exercise 11-15 */

// Use the character classification functions to prepare an implementation of atoi(); have
// this version return the value of 0 if the input string is not a pure number.


#include <stdio.h>
#include <string.h>

int my_atoi(char * ch);

int main(void)
{
	int converted1 = my_atoi("5G");

	printf("%d\n", converted1);

	int converted2 = my_atoi("5");

	printf("%d\n", converted2);

	return 0;
}

int my_atoi(char * ch)
{
	int answer = 0;
	int place = 1;

	for (int i = strlen(ch) - 1; i >= 0; i--)
	{
		if (ch[i] - '0' < 0 || ch[i] - '0' > 9)
		{
			printf("The input string is not a pure number.\n");
			return 0;
		}
		answer += (ch[i] - '0') * place;
		place *= 10;
	}

	return answer;
}
