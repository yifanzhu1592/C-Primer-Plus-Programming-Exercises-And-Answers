/* Programming Exercise 15-4.c */

// Write a function that takes two int arguments: a value and a bit position. Have the
// function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
// the function in a program.


#include <stdio.h>
#include <limits.h>

char * itobs(int, char *);
int one_or_zero(int val, int bit_pos);

int main(int argc, char * argv[])
{
    int val, bit_pos;
    char bstr[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer and a bit position (q to quit): ");
    while (scanf("%d %d", &val, &bit_pos))
    {
        printf("%d (%s) has bit %d on position %d.\n", val, itobs(val, bstr), one_or_zero(val, bit_pos), bit_pos);
        printf("Next value and nit position: ");
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

int one_or_zero(int val, int bit_pos)
{
    for (int i = 0; i < bit_pos; i++)
        val >>= 1;

    return (1 & val);
}
