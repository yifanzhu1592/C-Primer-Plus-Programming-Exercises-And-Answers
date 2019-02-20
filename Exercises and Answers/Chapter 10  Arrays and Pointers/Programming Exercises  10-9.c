/* Programming Exercises 10-9.c */

// Write a program that initializes a two-dimensional 3x5 array-of-double and uses a VLA-
// based function to copy it to a second two-dimensional array. Also provide a VLA-based
// function to display the contents of the two arrays. The two functions should be capable.
// In general, of processing arbitray NxM arrays. (If you don't have access to a VLA-capable
// compiler, use the traditional C approach of functions that can process an Nx5 array).


#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void display(int rows, int cols, double target[rows][cols], double source[rows][cols]);

int main(void)
{
	double source[ROWS][COLS] = {{1.1, 2.2, 3.3, 4.4, 5.5}, {6.6, 7.7, 8.8, 9.9, 10.10}, {11.11, 12.12, 13.13, 14.14, 15.15}};
	double target[ROWS][COLS];

	copy(ROWS, COLS, target, source);
	display(ROWS, COLS, target, source);

	return 0;
}

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    target[i][j] = source[i][j];
	    }
    }
}

void display(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    printf("Source array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    printf("%.2lf ", source[i][j]);
	    }
	    printf("\n");
    }
    printf("\n");

    printf("Target array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    printf("%.2lf ", target[i][j]);
	    }
	    printf("\n");
    }
}
