/* Programming Exercise 4-7 */

// Write a program that sets a type double variable to 1.0/3.0 and a type float variable
// to 1.0/3.0. Display each result three times -- once showing four digits to the right of the
// decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits
// to the right of the decimal. Also have the program include float.h and display the
// values of FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these values?


#include <stdio.h>
#include <float.h>

int main(void)
{
	double nd = 1.0 / 3.0;
	float fd = 1.0 / 3.0;
	
	printf("double values:\n");
	printf("%.4lf %.12lf %.16lf\n", nd, nd, nd);
	printf("float values:\n");
	printf("%.4f %.12f %.16f\n", fd, fd, fd);
	
	printf("\n");
	
	printf("float precision = %d digits\n", FLT_DIG);
	printf("double precision = %d digits\n", DBL_DIG);
	
	return 0;
}
