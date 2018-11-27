/* Programming Exercise 6-18 */

// Professor Rabnud joined a social media group. Initial he had five friends. He noticed
// that his friend count grew in the following fashion. The first week one friend dropped
// out and the remaining number of friends doubled. The second week two friends dropped
// out and the remaining number of friends doubled. In general, in the Nth week, N friends
// dropped out and the remaining number doubled. Write a program that computes and
// displays the number of friends each week. The program should continue until the count
// exceeds Dunbar's number. Dunbar's number is a rough estimate of the maximum size of
// a cohesive social group in which each member knows every other member and how they
// relate to one another. Its approximate value is 150.


#include <stdio.h>
#define initial 5 // initial number of friends
#define Dunbar 150

int main(void)
{
	int weeks = 1, friends = initial;
	while (friends <= Dunbar)
	{
		friends -= weeks;
		friends *= 2;
		printf("weeks friends\n");
		printf("%5d %7d\n", weeks, friends);
		weeks++;
	}
	
	return 0;
}
