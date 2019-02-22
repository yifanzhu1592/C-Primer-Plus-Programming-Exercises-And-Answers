/* Programming Exercise 10-13.c */

// Write a program that prompts the user to enter three sets of five double numbers each.
// (You may assume that the user responds correctly and doesn't enter non-numeric data.) The
// program should accomplish all of the following:

//    a. Store the information in a 3x5 array.
//    b. Compute the average of each set of five values.
//    c. Compute the average of all the values.
//    d. Determine the largest value of the 15 values.
//    e. Report the results.

// Each major task should be handled by a separate function using the traditional C
// approach to handling arrays. Accomplish task "b" by using a function that computes
// and returns the average of a one-dimensional array; use a loop to call this function three
// times. The other tasks should take the entire array as an argument, and the functions
// performing tasks "c" and "d" should return the answer to the calling program.


#include <stdio.h>

void Store(double array[][5]);
double Compute1(double array[][5], int index);
double Compute2(double array[][5]);
double Largest(double array[][5]);
void Report(double array[][5]);

int main(void)
{
    double array[3][5];

    Store(array);

    Report(array);

    return 0;
}

void Store(double array[][5])
{
    printf("Please enter three sets of five double numbers:\n");
    printf("Please enter the first set:\n");
    for (int i = 0; i < 5; i++)
        scanf("%lf", &array[0][i]);
    printf("Please enter the second set:\n");
    for (int j = 0; j < 5; j++)
        scanf("%lf", &array[1][j]);
    printf("Please enter the third set:\n");
    for (int k = 0; k < 5; k++)
        scanf("%lf", &array[2][k]);
}

double Compute1(double array[][5], int index)
{
    double average = 0;
    double sum = 0;

    for (int i = 0; i < 5; i++)
        sum += array[index][i];

    average = sum / 5;

    return average;
}

double Compute2(double array[][5])
{
    double average = 0;
    double sum = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            sum += array[j][i];

    average = sum / 15;

    return average;
}

double Largest(double array[][5])
{
    double largest = array[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[i][j] > largest)
            {
                largest = array[i][j];
            }
        }
    }

    return largest;
}

void Report(double array[][5])
{
    for (int i = 0; i < 3; i++)
        printf("The average of the %d set of five values is: %lf.\n", i, Compute1(array, i));

    printf("The average of all values is: %lf.\n", Compute2(array));

    printf("The largest value among these values is: %lf\n", Largest(array));
}
