/* Programming Exercise 14-6.c */

// A text file holds information about a softball team. Each line has data arranged as
// follows:
//
// 4 Jessie Joybat 5 2 1 1
//
// The first item is the player's number, conveniently in the range 0-18. The second item
// is the player's first name, and the third is the player's last name. Each name is a single
// word. The next item is the player's official times at bat, followed by the number of hits,
// walks, and runs batted in (RBIs). The file may contain data for more than one game,
// so the same player may have more than one line of data, and there may be data for
// other players between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last names, the
// at bats, hits, walks, and RBIs (runs batted in), and the batting aevrage (to be calculated
// later). You can use the player number as an array index. The program should read to end-
// of-file, and it should keep cumulative totals for each player.
//
// The world of baseball statistics is an involved one. For eaxmple, a walk or reaching base
// on an error doesn't count as an at-bat but could possibly produce an RBI. But all this
// program has to do is read and process the data file, as described next, without worrying
// about how realistic the data is.
//
// The simplest way for the program to proceed is to initialize the structure contents to
// zeros, read the file data into temporary variables, and then add them to the contents of
// the corresponding structure. After the program has finished reading the file, it should
// then calculate the batting average for each player and store it in the corresponding
// structure member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each player along
// with a line showing the combined statistics for the entire team.


#include <stdio.h>
#include <stdlib.h>

struct player {
    int number;
    char first_name[20];
    char last_name[20];
    int at_bats;
    int hits;
    int walks;
    int RBIs;
    float batting_average;
};

int main(void)
{
    FILE * fp;

    if ((fp = fopen("text.txt", "r")) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
        exit(EXIT_FAILURE);
    }

    struct player team[20];
    for (int m = 0; m < 20; m++)
    {
        team[m].number = -1;
        team[m].at_bats = 0;
        team[m].hits = 0;
        team[m].walks = 0;
        team[m].RBIs = 0;
    }

    int j = 0;
    int number;
    int exist = 0;
    char first_name[20];
    char last_name[20];
    int at_bats;
    int hits;
    int walks;
    int RBIs;

    while (fscanf(fp, "%d %s %s %d %d %d %d",
                        &number,
                        first_name,
                        last_name,
                        &at_bats,
                        &hits,
                        &walks,
                        &RBIs) == 7)
    {
        for (int i = 0; i < 20; i++)
        {
            if (team[i].number == number)
            {
                exist = 1;
                team[i].at_bats += at_bats;
                team[i].hits += hits;
                team[i].walks += walks;
                team[i].RBIs += RBIs;
            }
        }

        if (exist == 0)
        {
            team[j].number = number;
            for (int p = 0; p < 20; p++)
                team[j].first_name[p] = first_name[p];
            for (int q = 0; q < 20; q++)
                team[j].last_name[q] = last_name[q];
            team[j].at_bats += at_bats;
            team[j].hits += hits;
            team[j].walks += walks;
            team[j].RBIs += RBIs;
            j++;
        }
        exist = 0;
    }

    int total_at_bats = 0;
    int total_hits = 0;
    int total_walks = 0;
    int total_RBIs = 0;

    for (int k = 0; k < j; k++)
    {
        printf("%d %s %s %d %d %d %d %f\n",
            team[k].number,
            team[k].first_name,
            team[k].last_name,
            team[k].at_bats,
            team[k].hits,
            team[k].walks,
            team[k].RBIs,
            (float)team[k].hits / team[k].at_bats);
        total_at_bats += team[k].at_bats;
        total_hits += team[k].hits;
        total_walks += team[k].walks;
        total_RBIs += team[k].RBIs;
    }

    printf("%d %d %d %d %f\n",
            total_at_bats,
            total_hits,
            total_walks,
            total_RBIs,
            (float)total_hits / total_at_bats);

    return 0;
}
