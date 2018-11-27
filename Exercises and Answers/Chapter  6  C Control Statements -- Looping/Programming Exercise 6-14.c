/* Programming Exercise 6-14 */

// Write a program that creates two eight-element arrays of doubles and uses a loop to let
// the user enter values for the eight elements of the first array. Have the program set the
// elements of the second array to the cumulative totals of the elements of the first array.
// For example, the fourth element of the second array should equal the sum of the first
// four elements of the first array, and the fifth element of the second array should equal
// the sum of the first five elements of the first array. (It's possible to do this with nested
// loops, but by using the fact that the fifth element of the second array equals the fourth
// element of the second array plus the fifth element of the first array, you can avoid
// nesting and just use a single loop for this task.) Finally, use loops to display the contents
// of the two arrays, with the first array displayed on one line and with each element of the
// second array displayed below the corresponding element of the first array.


#include <stdio.h>
#define SIZE 8

int main(void)
{
	int i;
	double fa[SIZE]; // first array
	double sa[SIZE]; // second array
	
	printf("Please enter eight numbers:\n");
	for (i = 0; i < SIZE; i++)
		scanf("%lf", &fa[i]);
	
	sa[0] = fa[0];
	for (i = 1;i < SIZE; i++)
		sa[i] = fa[i] + sa[i - 1];
	
	for (i = 0; i < SIZE; i++)
		printf("%8g ", fa[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++)
		printf("%8g ", sa[i]);
	printf("\n");
		
	return 0;
}
