/* Programming Exercise 11-11 */

// Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
// offer the user a menu with five choices: print the original list of strings, print the strings
// in ASCII collating sequence, print the strings in order of increasing length, print the
// strings in order of the length of the first word in the string, and quit. Have the menu
// recycle until the user enters the quit request. The program, of course, should actually
// perform the promised tasks.


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 80
#define MAX 10

void function1(int cnt, char *s[]);
void function2(int cnt, char *s[]);
void function3(int cnt, char *s[]);
void function4(int cnt, char *s[]);

char * s_gets(char * st, int n);

int main(void)
{
    char s[MAX][LEN];
    char *strptr[MAX];
    int cnt = 0;

    for (int i = 0; i < MAX; i++)
		strptr[i] = s[i];

    puts("Enter up to 10 strings (or just Enter to finish):");
    while (s_gets(s[cnt], LEN) && s[cnt][0] != '\0')
    {
        cnt++;
        if (cnt == 10)
            break;
    }

    while(true)
    {
        puts("");
        puts("1. print the original list of strings");
        puts("2. print the strings in ASCII collating sequence");
        puts("3. print the strings in order of increasing length");
        puts("4. print the strings in order of the length of the first word in the string");
        puts("5. quit");
        printf("Please make a choice: ");
        char ch = getchar();
        while (getchar() != '\n')
            continue;
        switch(ch)
        {
            case '1': function1(cnt, strptr);   break;
            case '2': function2(cnt, strptr);   break;
            case '3': function3(cnt, strptr);   break;
            case '4': function4(cnt, strptr);   break;
            case '5': puts("Bye!");             return 0;
            default : puts("Error!");           return 0;
        }
    }

    puts("Bye!");
    return 0;
}

void function1(int cnt, char *s[])
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < strlen(s[i]); j++)
        {
            printf("%c", s[i][j]);
        }
        puts("");
    }
    puts("");
}

void function2(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (strcmp(s[i], s[j]) > 0)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
        }
    }

    for (int m = 0; m < cnt; m++)
    {
        for (int n = 0; n < strlen(s[m]); n++)
        {
            printf("%c", s[m][n]);
        }
        puts("");
    }
    puts("");
}

void function3(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (strlen(s[i]) > strlen(s[j]))
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
        }
    }

    for (int m = 0; m < cnt; m++)
    {
        for (int n = 0; n < strlen(s[m]); n++)
        {
            printf("%c", s[m][n]);
        }
        puts("");
    }
    puts("");
}

void function4(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            int first_word_si = -1, first_word_sj = -1;
            int k = 0, l = 0;
            char chi, chj;
            do
            {
                chi = s[i][k];
                k++;
                first_word_si++;
            } while(!isspace(chi));

            do
            {
                chj = s[j][l];
                l++;
                first_word_sj++;
            } while(!isspace(chj));

            if (first_word_si > first_word_sj)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
        }
    }

    for (int m = 0; m < cnt; m++)
    {
        for (int n = 0; n < strlen(s[m]); n++)
        {
            printf("%c", s[m][n]);
        }
        puts("");
    }
    puts("");
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
