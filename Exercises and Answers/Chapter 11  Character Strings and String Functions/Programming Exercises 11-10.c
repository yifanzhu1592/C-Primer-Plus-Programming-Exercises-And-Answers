/* Programming Exercise 11-10 */

// Write a function that takes a string as an argument and removes the spaces from the
// string. Test it in a program that uses a loop to read lines until you enter an empty line.
// The program should apply the function to each input string and display the result.


#include <stdio.h>
#include <string.h>     // for strchr();
#define LEN 81
int drop_space(char * s);
char * s_gets(char * st, int n);

int main(void)
{
    char orig[LEN];

    puts("Enter a string of 80 characters or less:");
    while (s_gets(orig, LEN) && orig[0] != '\0')
    {
        drop_space(orig);
        puts(orig);
        puts("Enter next string (or just Enter to quit):");
    }
    puts("Bye!");
    return 0;
}

int drop_space(char * s)
{
    char * pos;
    while (*s)     /* or while (*s != '\0') */
    {
        if (*s == ' ')
        {
            pos = s;
            do
            {
                *pos = *(pos + 1);
                pos++;
            } while (*pos);
        }
        else
            s++;
    }
    return 1;
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
