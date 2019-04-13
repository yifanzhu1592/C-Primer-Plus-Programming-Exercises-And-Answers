/* Programming Exercise 14-4.c */

// Write a program that creates a structure template with two members according to the
// following criteria:
//      a. The first member is a social security number. The second number is a structure
//         with three members. Its first member contains a first name, its second member
//         contains a middle name, and its final member contains a last name. Create and
//         initialize an array of five such structures. Have the program print the data in this
//         format:
//
//         Dribble, Flossie M. -- 302039823
//
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed is the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
//      b. Modify part a. by passing the structure value instead of the address.

// part a


#include <stdio.h>
#include <string.h>

struct name {
    char first_name[20];
    char middle_name[20];
    char last_name[20];
};

struct identity {
    char number[20];
    struct name handle;
};

void printing(struct identity array[]);

int main(void)
{
    struct identity array[5] = {
        {"302039823", {"Flossie", "Malan", "Dribble"}},
        {"001", {"Fan", "Yi", "Zhu"}},
        {"002", {"Fan", "", "Long"}},
        {"003", {"Fan", "Nv", "Shao"}},
        {"004", {"Fan", "G", "P"}}
    };

    printing(array);

    return 0;
}

void printing(struct identity array[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(array[i].handle.middle_name, "") != 0)
            printf("%s, %s %c. -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].handle.middle_name[0], array[i].number);
        else
            printf("%s, %s -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].number);
    }
}
