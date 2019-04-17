/* Programming Exercise 14-11.c */

// Write a function called transform() that takes four arguments: the name of a source
// array containing type double data, the name of a target array of type double, an int
// representing the number of array elements, and the name of a function (or, equivalently,
// a pointer to a function). The transform() function should apply the indicated function
// to each element in the source array, placing the return value in the target array. For
// example, the call
//
// transform(source, target, 100, sin);
//
// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
// in a program that calls transform() four times, using two functions from the math.h
// library and two suitable functions of your own devising as arguments to successive calls
// of the transform() function.


#include <stdio.h>
#include <math.h>

#define NUM 2

void transform(double source[], double target[], int num, double pf(double));
double halve(double snum);
double triple(double snum);

int main(void)
{
    double source[NUM] = {3.14159265 / 2.0, 0};
    double target[NUM];

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, sin);

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, cos);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, halve);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, triple);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    return 0;
}

void transform(double source[], double target[], int num, double pf(double))
{
    for (int i = 0; i < num; i++)
    {
        target[i] = (*pf)(source[i]);
    }
}

double halve(double snum)
{
    return snum / 2;
}

double triple(double snum)
{
    return snum * 3;
}
