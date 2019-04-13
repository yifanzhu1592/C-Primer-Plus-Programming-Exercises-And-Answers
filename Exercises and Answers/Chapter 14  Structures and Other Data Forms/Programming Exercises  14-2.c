/* Programming Exercise 14-2.c */

// Writing a program that prompts the user to enter the day, month, and year. The month
// can be a month number, a month name, or a month abbreviation. The program then
// should return the total number of days in the year up through the given day. (Do take
// leap years into account.)


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

const struct month months_heap[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 29, 2},
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

int days(int d, char * m, int y);
int days_heap(int d, char * m, int y);
int main(void)
{
    int day;
    char input[20];
    int year;
    int daytotal;

    printf("Please enter the day: ");
    while (scanf("%d", &day) == 1)
    {
        printf("Please enter the month: ");
        scanf("%s", input);
        printf("Please enter the year: ");
        scanf("%d", &year);
        if (year % 4 == 0 && year % 400 != 0)
            daytotal = days_heap(day, input, year);
        else
            daytotal = days(day, input, year);
        if (daytotal > 0)
            printf("There are %d days through %s %d in year %d.\n", daytotal, input, day, year);
        else
            printf("%s is not valid input.\n", input);
        printf("Please enter the day (q to quit): ");
    }
    puts("bye");

    return 0;
}

int days(int d, char * m, int y)
{
    int total = 0;
    int mon_num = 0;
    int i;
    if (isalpha(*m))
    {
        m[0] = toupper(m[0]);
        for (i = 1; m[i] != '\0'; i++)
            m[i] = tolower(m[i]);
    }
    for (i = 0; i < 12; i++)
        if (strcmp(m, months[i].name) == 0 || strcmp(m, months[i].abbrev) == 0 || atoi(m) == months[i].monumb)
        {
            mon_num = months[i].monumb;
            break;
        }
    if (mon_num == 0)
        total = -1;
    else
        for (i = 0; i < mon_num - 1; i++)
            total += months[i].days;
    total += d;

    return total;
}

int days_heap(int d, char * m, int y)
{
    int total = 0;
    int mon_num = 0;
    int i;
    if (isalpha(*m))
    {
        m[0] = toupper(m[0]);
        for (i = 1; m[i] != '\0'; i++)
            m[i] = tolower(m[i]);
    }
    for (i = 0; i < 12; i++)
        if (strcmp(m, months[i].name) == 0 || strcmp(m, months[i].abbrev) == 0 || atoi(m) == months[i].monumb)
        {
            mon_num = months[i].monumb;
            break;
        }
    if (mon_num == 0)
        total = -1;
    else
        for (i = 0; i < mon_num - 1; i++)
            total += months_heap[i].days;
    total += d;

    return total;
}
