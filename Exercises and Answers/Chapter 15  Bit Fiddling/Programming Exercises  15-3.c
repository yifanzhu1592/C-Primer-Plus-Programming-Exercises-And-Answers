/* Programming Exercise 15-3.c */

// Write a function that takes an int argument and returns the number of "on" bits in the
// argument. Test the function in a program.


#include <stdio.h>
#include <limits.h>

char * itobs(int, char *);
int onbits(int);

int main(int argc, char * argv[])
{
    int val;
    char bstr[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer (q to quit): ");
    while (scanf("%d", &val))
    {
        printf("%d (%s) has %d bit(s) on.\n", val, itobs(val, bstr), onbits(val));
        printf("Next value: ");
    }

    puts("Done");
    return 0;
}

char * itobs(int n, char * ps)
{
    int i;
    static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

int onbits(int n)
{
    static const int size = CHAR_BIT * sizeof(int);
    int ct = 0;
    int i;

    for (i = 0; i < size; i++, n >>= 1)
        if ((1 & n) == 1)
            ct++;
    return ct;
}
