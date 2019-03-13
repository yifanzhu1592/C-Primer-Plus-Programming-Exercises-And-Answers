/* Programming Exercise 11-7 */

// The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating
// s2 or padding it with extra null characters as necessary. The target string may not be
// null-terminated if the length of s2 is n or more. The function returns s1. Write your own
// version of this function; call it mystrncpy(). Test the function in a complete program
// that uses a loop to provide input values for feeding to the function.


#include <stdio.h>
#include <string.h>

char * mystrncpy(char * s1, char * s2, int n);

int main(void)
{
    char s1[10] = "";
    char s2[] = "Longfan";

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    mystrncpy(s1, s2, 4);

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    mystrncpy(s1, s2, 10);

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    if (strlen(s2) >= n)
    {
        for (int i = 0; i < n; i++)
        {
            s1[i] = s2[i];
        }
    }
    else
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            s1[j] = s2[j];
        }
        for (int k = strlen(s2); k < n; k++)
        {
            s1[k] = '\0';
        }
    }

    return s1;
}
