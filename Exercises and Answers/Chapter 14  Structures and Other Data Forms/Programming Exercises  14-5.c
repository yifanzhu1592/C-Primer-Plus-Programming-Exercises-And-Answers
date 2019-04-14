/* Programming Exercise 14-5.c */

// Write a program that fits the following recipe:
//
//      a. Externally define a name structure template with two members: a string to hold the
//         first name and a string to hold the second name.
//
//      b. Externally define a student structure template with three members: a name
//         structure, a grade array to hold three floating-point scores, and a variable to hold
//         the average of those three scores.
//      c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
//         structures and initialize the name portions to name of your choice. Use functions
//         to perform the tasks described in parts d., e., f., and g.
//
//      d. Interactively acquire scores for each student by prompting the user with a student
//         name and a request for scores. Place the scores in the grade array portion of the
//         appropriate structure. The required looping can be done in main() or in the
//         function, as you prefer.
//
//      e. Calculate the average score value for each structures and assign it to the proper
//         member.
//
//      f. Print the information in each strcuture.
//
//      g. Print the class average for each of the numeric structure members.


#include <stdio.h>
#include <string.h>
#define LEN 14
#define CSIZE 4
#define SCORES 3
struct name {
    char first[LEN];
    char last[LEN];
};
struct student {
    struct name person;
    float scores[SCORES];
    float mean;
};
void get_scores(struct student ar[], int lim);
void find_means(struct student ar[], int lim);
void show_class(const struct student ar[], int lim);
void show_ave(const struct student ar[], int lim);

int main(void)
{
    struct student class[CSIZE] = {
        { "Flip", "Snide"},
        { "Clare", "Voyans"},
        { "Bingo", "Higgs"},
        { "Fawn", "Hunter"}
    };
    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_ave(class, CSIZE);

    return 0;
}

void get_scores(struct student ar[], int lim)
{
    int i, j;
    for (i = 0; i < lim; i++)
    {
        printf("Please enter %d scores for %s %s:\n", SCORES,
            ar[i].person.first, ar[i].person.last);
        for (j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &ar[i].scores[j]) != 1)
            {
                scanf("%*s");
                puts("Please use numeric input.");
            }
        }
    }
}

void find_means(struct student ar[], int lim)
{
    int i, j;
    float sum;

    for (i = 0; i < lim; i++)
    {
        for (sum = 0, j = 0; j < SCORES; j++)
            sum += ar[i].scores[j];
        ar[i].mean = sum / SCORES;
    }
}

void show_class(const struct student ar[], int lim)
{
    int i, j;
    char wholename[2*LEN];

    for (i = 0; i < lim; i++)
    {
        strcpy(wholename, ar[i].person.first);
        strcat(wholename, " ");
        strcat(wholename, ar[i].person.last);
        printf("%27s: ", wholename);
        for (j = 0; j < SCORES; j++)
            printf("%6.1f ", ar[i].scores[j]);
        printf(" Average = %5.2f\n", ar[i].mean);
    }
}

void show_ave(const struct student ar[], int lim)
{
    int i, j;
    float total;

    printf("\n%27s: ", "QUIZ AVERAGES");
    for (j = 0; j < SCORES; j++)
    {
        for (total = 0, i = 0; i < lim; i++)
            total += ar[i].scores[j];
        printf("%6.2f ", total / lim);
    }
    for (total = 0, i = 0; i < lim; i++)
        total += ar[i].mean;
    printf("     All = %5.2f\n", total / lim);
}
