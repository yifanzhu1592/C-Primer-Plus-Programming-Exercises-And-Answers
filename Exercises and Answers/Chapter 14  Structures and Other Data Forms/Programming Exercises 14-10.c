/* Programming Exercise 14-10.c */

// Write a program that implements a menu by using an array of pointers to functions. For
// instance, choosing a from the menu would activate the function pointed to by the first
// element of the array.


#include <stdio.h>
#include <math.h>    // for sqrt()

double twice(double x);
double half(double x);
double thrice(double x);
void showmenu(void);
#define NUM 4
int main(void)
{
    double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
    double val;
    double ans;
    int sel;

    printf("Enter a number (negative to quit): ");
    while (scanf("%lf", &val) && val >= 0)
    {
        showmenu();
        while (scanf("%d", &sel) && sel >= 0 && sel <= 3)
        {
            ans = (*pf[sel])(val);        // first notation
            printf("answer = %f\n", ans);
            ans = pf[sel](val);           // alternative notaion
            printf("to repeat, answer = %f\n", ans);
            showmenu();
        }
        printf("Enter next number (negative to quit): ");
    }
    puts("bye");
    return 0;
}

void showmenu(void)
{
    puts("Enter one of the following choices:");
    puts("0) double the value        1) halve the value");
    puts("2) triple the value        3) squareroot the value");
    puts("4) next number");
}

double twice(double x) {return 2.0 * x;}
double half(double x) {return x / 2.0;}
double thrice(double x) {return 3.0 * x;}
