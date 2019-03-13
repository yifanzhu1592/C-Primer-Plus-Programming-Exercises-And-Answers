/* Programming Exercise 11-6 */

// Write a function called is_within() that takes a character and a string pointer as its two
// function parameters. Have the function return a nonzero value (true) if the charater is
// in the string and zero (false) otherwise. Test the function in a complete program that uses
// a loop to provide input values for feeding to the function.


#include <stdio.h>
#include <string.h>
#define LEN 80
_Bool is_within(const char * str, char c);
char * s_gets(char * st, int n);

int main(void)
{
    char input[LEN];
    char ch;
    int found;

    printf("Enter a string: ");
    while (s_gets(input, LEN) && input[0] != '\0')
    {
        printf("Enter a character: ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        found = is_within(input, ch);
        if (found == 0)
            printf("%c not found in string.\n", ch);
        else
            printf("%c found in string %s\n", ch, input);
        printf("Next string: ");
    }
    puts("Done.\n");

    return 0;
}

_Bool is_within(const char * str, char ch)
{
    while (*str != ch && *str != '\0')
        str++;
    return *str;   /* = 0 if \0 reached, non-zero otherwise */
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
                continue;
    }
    return ret_val;
}
