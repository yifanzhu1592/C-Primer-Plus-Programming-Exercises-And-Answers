/* Programming Exercise 14-1.c */

// Redo Review Question 5, but make the argument the spelled-out name of the month
// instead of the month number. (Don't forget about strcmp().) Test the function in a
// simple program.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

const struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int days(char * m);
int main(void)
{
    char input[20];
    int daytotal;

    printf("Enter the name of a month: ");
    while (scanf("%s", input) == 1 && input[0] != 'q')
    {
        daytotal = days(input);
        if (daytotal > 0)
            printf("There are %d days through %s.\n", daytotal, input);
        else
            printf("%s is not valid input.\n", input);
        printf("Next month (q to quit): ");
    }
    puts("bye");

    return 0;
}

int days(char * m)
{
    int total = 0;
    int mon_num = 0;
    int i;
    m[0] = toupper(m[0]);
    for (i = 1; m[i] != '\0'; i++)
        m[i] = tolower(m[i]);
    for (i = 0; i < 12; i++)
        if (strcmp(m, months[i].name) == 0)
        {
            mon_num = months[i].monumb;
            break;
        }
    if (mon_num == 0)
        total = -1;
    else
        for (i = 0; i < mon_num; i++)
            total += months[i].days;

    return total;
}
