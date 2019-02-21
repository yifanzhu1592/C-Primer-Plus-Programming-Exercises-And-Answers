/* Programming Exercises 10-12.c */

// Rewrite the rain program in Listing 10.7 so that the main tasks are performed by
// functions instead of in main().


#include <stdio.h>
#define ROWS 2
#define COLS 3

void copy_ptr(double target[][COLS], double source[][COLS], int rows, int cols);
void display(double target[][COLS], double source[][COLS], int rows, int cols);

int main(void)
{
	double source[ROWS][COLS] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
	double target[ROWS][COLS];

	copy_ptr(target, source, ROWS, COLS);
	display(target, source, ROWS, COLS);

	return 0;
}

void copy_ptr(double target[][COLS], double source[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    target[i][j] = source[i][j];
	    }
    }
}

void display(double target[][COLS], double source[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    printf("%.1lf ", target[i][j]);
	    }
	    printf("\n");
    }
}
