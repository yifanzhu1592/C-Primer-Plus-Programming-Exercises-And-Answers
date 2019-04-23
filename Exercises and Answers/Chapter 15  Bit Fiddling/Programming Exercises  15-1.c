/* Programming Exercise 15-1.c */

// Write a function that converts a binary string to a numeric value. That is, if you have
//
// char * pbin = "01001001";
//
// you can pass pbin as an argument to the function and have the function return an int
// value of 25.


#include <stdio.h>
#include <stdbool.h>  // C99 -- otherwise use int
#include <limits.h>   // for CHAR_BIT
#include <string.h>   // for strchr()

int bstr_to_dec(const char * str);
bool check_val(const char * str);
char * s_gets(char * st, int n);
int main(void)
{
    const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
    char value[SLEN];

    printf("Enter a binary number with up to %zu digits: ", SLEN - 1);

    while (s_gets(value, SLEN) && value[0] != '\0')
    {
        if (!check_val(value))
            puts("A binary number contains just 0s and 1s.");
        else
            printf("%s is %d\n", value, bstr_to_dec(value));
        puts("Enter next value (empty line to quit):");
    }

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

bool check_val(const char * str)
{
    bool valid = true;

    while (valid && *str != '\0')
    {
        if (*str != '0' && *str != '1')
            valid = false;
        ++str;
    }

    return valid;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
