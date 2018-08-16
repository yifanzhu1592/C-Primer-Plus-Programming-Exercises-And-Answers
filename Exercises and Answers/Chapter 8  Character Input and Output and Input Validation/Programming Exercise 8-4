/* Programming Exercise 8-4 */

// Write a program that reads input as a stream of characters until encoutering EOF. Have
// it report the average number of letters per word. Don't count whitespace as being letters
// in a word. Actually, punctuation shouldn't be counted either, but don't worry about that
// now. (If you do want to worry about it, consider using the ispunct() function from the
// ctype.h family.)


#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	float num_of_letters = 0, num_of_words = 0;
	float average;                    // average number of letters per word
	bool new_word = true;
	
	while ((ch = getchar()) != EOF)
	{
		if (ispunct(ch))
			continue;
		else if (isspace(ch))
		{
			new_word = true;
			continue;
		}
		else
		{
			num_of_letters++;
			if (new_word)
			{
				num_of_words++;
				new_word = false;
			}
		}
	}
	
	average = num_of_letters / num_of_words;
	printf("The average number of letters per word is %f.\n", average);
	
	return 0;
}
