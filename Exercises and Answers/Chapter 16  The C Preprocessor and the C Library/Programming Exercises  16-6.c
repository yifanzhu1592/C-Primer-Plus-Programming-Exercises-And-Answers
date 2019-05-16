/* Programming Exercise 16-6.c */

// Modify Listing 16.17 so that it uses an array of struct names elements (as defined after
// the listing) instead of an array of double. Use fewer elements, and initialize the array
// explicitly to a suitable selection of names.

/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 4
typedef struct names {
    char first[40];
    char last[40];
} NAME;

void showarray(const NAME ar[], int n);
int comp(const void * p1, const void * p2);

int main(void)
{
    struct names staff[NUM] = {
        {"yifan", "zhu"},
        {"fan", "long"},
        {"fan", "shaonv"},
        {"fan", "PG"}
    };
    puts("Before sorted list:");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(struct names), comp);
    puts("\nSorted list:");
    showarray(staff, NUM);
    return 0;
}

void showarray(const NAME ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s %s", ar[index].first, ar[index].last);
            putchar('\n');
    }
}

/* sort by increasing value */
int comp(const void * p1, const void * p2)  /* mandatory form */
{
    /* get right type of pointer */
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last);     /* compare last names */
    if (res != 0)
        return res;
    else        /* last names identical, so compare first names */
        return strcmp(ps1->first, ps2->first);
}
