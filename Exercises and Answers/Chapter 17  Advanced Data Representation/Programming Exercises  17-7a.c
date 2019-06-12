/* Programming Exercise 17-7a.c */

// Write a program that opens and reads a text file and records how many times each word
// occurs in the file. Use a binary search tree modified to store both a word and the number
// of times it occurs. After the program has read the file, it should offer a menu with three
// choices. The first is to list all the words along with the number of occurrences. The
// second is to let you enter a word, with the program reporting how many times the word
// occurred in the file. The third choice is to quit.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Programming Exercises  17-7.h"
#define SLEN 81
void printitem(Item item);
char menu(void);
void showwords(const Tree * pt);
void findword(const Tree * pt);
char * s_gets(char * st, int n);

int main(void)
{
    Tree wordcount;
    FILE * fp;
    char filename[SLEN];
    char word[SLEN];
    Item entry;
    char choice;


    printf("Enter name of file to be processed: \n");
    s_gets(filename, SLEN);

    if ((fp = fopen(filename, "r")) == 0)
    {
        printf("Can't open file %s. Bye.\n", filename);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordcount);

    while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordcount))
    {
        strcpy(entry.wrd, word);
        AddItem(&entry, &wordcount);
    }

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 's' :  showwords(&wordcount);
                        break;
            case 'f' :  findword(&wordcount);
                        break;
            default  :  puts("Switching error");
        }
    }

    fclose(fp);
    puts("Done");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // look for newline
        if (find)                   // if the address is not NULL,
            *find = '\0';           // place a null character there
        else
            while (getchar() != '\n')
                continue;           // dispose of rest of line
    }
    return ret_val;
}

char menu(void)
{
    int ch;

    puts("Word counting program");
    puts("Enter the letter corresponding to your choice:");
    puts("s) show word list     f) find a word");
    puts("q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("sfq", ch) == NULL)
            puts("Please enter an s, f, or q:");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'q';

    return ch;
}

void showwords(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void findword(const Tree * pt)
{
    char word[SLEN];
    Item entry;
    const Item * pi;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }

    printf("Enter the word to find: ");
    scanf("%s", word);
    while (getchar() != '\n')
        continue;
    strcpy(entry.wrd, word);
    pi = WhereInTree(&entry, pt);
    if (pi == NULL)
        printf("%s is not in the list.\n", word);
    else
        printf("%s appears %d times.\n", word, pi->count);
}

void printitem(Item item)
{
    printf("%3d:  %s\n", item.count,
            item.wrd);
}
