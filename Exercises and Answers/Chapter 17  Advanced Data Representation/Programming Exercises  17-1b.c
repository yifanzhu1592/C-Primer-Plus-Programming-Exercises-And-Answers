/* Programming Exercise 17-1.c  double-link solution */
#include <stdio.h>
#include <stdlib.h>      /* has the malloc prototype      */
#include <string.h>      /* has the strcpy prototype      */
#define TSIZE    45      /* size of array to hold title   */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;  /* points to next struct in list */
    struct film * prev;  /* points to previous struct     */
};
char * s_gets(char * st, int n);
int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

/* Gather  and store information          */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head = NULL)        /* first structure       */
        {
            head = current;
            head->prev = NULL;
        }
        else                    /* subsequent structures */
        {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

/* Show list of movies                    */
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title, current->rating);
        prev = current;
        current = current->next;
    }
    if (head != NULL)
    {
        printf("\nHere is the list in reverse order:\n");
        current = prev;
        while (current != NULL)
        {
            printf("Movie: %s  Rating: %d\n", current->title, current->rating);
            current = current->prev;
        }
    }

/* Program done, so free allocated memory */
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("Bye!\n");

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
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
