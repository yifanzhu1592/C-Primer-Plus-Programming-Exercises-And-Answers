/* Programming Exercises 11-4 */

// Design and test a function like that described in Programming Exercise 3 except that it
// accepts a second parameter specifying the maximum number of characters that can be
// read.


#include <stdio.h>
#define LEN 80
#define MAX 10
char * getword(char * str, int n);
int main(void)
{
    char input[LEN];

    while (getword(input, MAX) != NULL)
        puts(input);
    puts("Done.\n");

    return 0;
}

#include <ctype.h>

char * getword(char * str, int n)
{
    int ch;
    char * orig = str;
// skip over initial whitespace
    while ((ch = getchar()) != EOF && isspace(ch))
        continue;
    if (ch == EOF)
        return NULL;
    else
        *str++ = ch;   // first character in word
// get rest of word
    while ((ch = getchar()) != EOF && !isspace(ch) && --n) {
        *str++ = ch;
    }
    *str = '\0';
    if (ch == EOF)
        return NULL;
    else
    {
        while (ch != '\n')
            ch = getchar();
        return orig;
    }
}
