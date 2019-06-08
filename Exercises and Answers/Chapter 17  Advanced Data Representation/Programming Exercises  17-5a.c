/* Programming Exercise 17-5a.c */

// Write a program that lets you input a string. The program then should push the
// characters of the string onto a stack, one by one (see review question 5), and then pop
// the characters from the stack and display them. This results in displaying the string in
// reverse order.


#include <stdio.h>
#include <string.h>
#include "Programming Exercises  17-5.h"
#define SLEN 81
char * s_gets(char * st, int n);
int main(void)
{
    Stack stch;
    char temp[SLEN];
    int i;
    char ch;
    
    InitializeStack(&stch);
    printf("Enter a line (an empty line to quit): \n");
    while (s_gets(temp, SLEN) && temp[0] != '\0')
    {
        i = 0;
        while (temp[i] != '\0' && !FullStack(&stch))
            Push(temp[i++], &stch);
        
        while (!EmptyStack(&stch))
        {
            Pop(&ch, &stch);
            putchar(ch);
        }
        putchar('\n');
        printf("Enter next line (empty line to quit): ");
    }
    puts("Done!");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    
    return ret_val;
}
