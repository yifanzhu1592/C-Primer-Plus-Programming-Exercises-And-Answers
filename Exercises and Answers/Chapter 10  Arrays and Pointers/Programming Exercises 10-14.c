/* Programming Exercise 10-14.c */

// Do Programming Exercise 13, but use variable-length array function parameters.


#include <stdio.h>
#define ROWS 3
#define COLS 5

void store(double ar[], int n);
double average2d(int rows, int cols, double ar[rows][cols]);
double max2d(int rows, int cols, double ar[rows][cols]);
void showarr2(int rows, int cols, double ar[rows][cols]);
double average(const double ar[], int n);

int main(void)
{
    double stuff[ROWS][COLS];
    int row;

    for (row = 0; row < ROWS; row++)
    {
        printf("Enter %d numbers for row %d\n", COLS, row + 1);
        store(stuff[row], COLS);
    }

    printf("array contents:\n");
    showarr2(ROWS, COLS, stuff);

    for (row = 0; row < ROWS; row++)
        printf("average value of row %d = %g\n", row + 1, average(stuff[row],COLS));
    printf("average value of all rows = %g\n", average2d(ROWS, COLS, stuff));
    printf("largest value = %g\n", max2d(ROWS, COLS, stuff));
    printf("Bye!\n");
    return 0;
}

void store(double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter value #%d: ", i + 1);
        scanf("%lf", & ar[i]);
    }
}

double average2d(int rows, int cols, double ar[rows][cols])
{
    int r, c;
    double sum = 0.0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            sum += ar[r][c];
    if (rows * cols > 0)
        return sum / (rows * cols);
    else
        return 0.0;
}

double max2d(int rows, int cols, double ar[rows][cols])
{
    int r, c;
    double max = ar[0][0];

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            if (max < ar[r][c])
                max = ar[r][c];
    return max;
}

void showarr2(int rows, int cols, double ar[rows][cols])
{
    int row, col;

    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
            printf("%g ", ar[row][col]);
        putchar('\n');
    }
}

double average(const double ar[], int n)
{
    int i;
    double sum = 0.0;

    for (i = 0; i < n; i++)
        sum += ar[i];
    if (n > 0)
        return sum / n;
    else
        return 0.0;
}
