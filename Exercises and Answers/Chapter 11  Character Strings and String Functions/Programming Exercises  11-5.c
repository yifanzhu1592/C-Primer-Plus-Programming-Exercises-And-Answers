/* Programming Exercises 11-5 */

// Design and test a function that searches the string specified by the first function
// parameter for the first occurrence of a character specified by the second function
// parameter. Have the function return a pointer to the character if successful, and a null
// if the character is not found in the string. (This duplicates the way that the library
// strchr() function works.) Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.


#include <stdio.h>
#include <string.h>

char * strchr1(char * s, int c);

int main(void)
{
    char s[20];
    char c;

    printf("Enter the string and the character: ");

    while (scanf("%s %c", s, &c) == 2)
    {
        while (getchar() != '\n')
            continue;
        char * check = strchr1(s, c);
        if (!check)
            printf("The character %c is not found in the string.\n", c);
        else
            printf("The character %c is found!\n", *check);
        printf("Enter another pair of the string and the character: ");
    }

    return 0;
}

char * strchr1(char * s, int c)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
            return &s[i];
    }

    return NULL;
}
