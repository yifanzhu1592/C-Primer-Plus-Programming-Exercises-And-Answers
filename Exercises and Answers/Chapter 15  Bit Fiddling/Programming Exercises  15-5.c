/* Programming Exercise 15-5.c */

// Write a function that rotates the bits of an unsigned int by a specified number of bits
// to the left. For instance, rotate_1(x,4) would move the bits in x four places to the left,
// and the bits lost from the left end would reappear at the right end. That is, the bit moved
// out of the high-order position is placed in the low-order position. Test the function in a
// program.


#include <stdio.h>
#include <limits.h>
unsigned int rotate_1(unsigned int, unsigned int);
char * itobs(int, char *);

int main(void)
{
    unsigned int val;
    unsigned int rot;
    unsigned int places;
    char bstr1[CHAR_BIT * sizeof (int) + 1];
    char bstr2[CHAR_BIT * sizeof (int) + 1];

    printf("Enter an integer (q to quit): ");
    while (scanf("%ud", &val))
    {
        printf("Enter the number of bits to be rotated: \n");
        if (scanf("%ul", &places) != 1)
            break;
        rot = rotate_1(val, places);
        itobs(val, bstr1);
        itobs(rot, bstr2);
        printf("%u rotated is %u.\n", val, rot);
        printf("%s rotated is %s.\n", bstr1, bstr2);
        printf("Next value: ");
    }

    puts("Done");
    return 0;
}

unsigned int rotate_1(unsigned int n, unsigned int b)
{
    static const int size = CHAR_BIT * sizeof(int);
    unsigned int overflow;

    b %= size;  /* keep b a valid value */

    overflow = n >> (size - b);  /* save bits that are shifted out */
    return (n << b) | overflow;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) +'0';
    ps[size] = '\0';

    return ps;
}
