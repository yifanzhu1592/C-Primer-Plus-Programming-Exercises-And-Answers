/* Programming Exercises 11-2 */

// Design and test a function that fetches the next n characters from input (including
// blanks, tabs, and newlines), storing the results in an array whose address is passed as an
// argument.


#include <stdio.h>
#include <ctype.h>
#define LEN 10
char * getnchar(char * str, int n);
int main(void)
{
    char input[LEN];
    char *check;

    check = getnchar(input, LEN - 1);
    if (check == NULL)
        puts("Input failed.");
    else
        puts(input);
    puts("Done.\n");

    return 0;
}

char * getnchar(char * str, int n)
{
    int i;
    int ch;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch != EOF && !isspace(ch))
            str[i] = ch;
        else
            break;
    }
    if (ch == EOF)
        return NULL;
    else
    {
        str[i] = '\0';
        return str;
    }
}
