/* Programming Exercise 15-2.c */

// Write a program that reads two binary strings as command-line arguments and prints
// the results of applying the ~ operator to each number and the results of applying the
// &, |, and ^ operators to the pair. Show the results as binary strings. (If you don't have a
// command-line environment available, have the program read the strings interactively.)


#include <stdio.h>
#include <stdlib.h>

int bstr_to_dec(const char * str);
char * itobs(int, char *);
int main(int argc, char * argv[])
{
    int v1;
    int v2;
    char bstr[8 * sizeof(int) + 1];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    v1 = bstr_to_dec(argv[1]);
    v2 = bstr_to_dec(argv[2]);

    printf("~%s = %s\n", argv[1], itobs(~v1, bstr));
    printf("~%s = %s\n", argv[2], itobs(~v2, bstr));
    printf("%s & %s = %s\n", argv[1], argv[2], itobs(v1 & v2, bstr));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(v1 | v2, bstr));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(v1 ^ v2, bstr));

    puts("Done");
    return 0;
}

int bstr_to_dec(const char * str)
{
    int val = 0;

    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
}

char * itobs(int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
