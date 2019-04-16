/* Programming Exercise 14-9.c */

// Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
// its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
// handle four flights. Have a top-level menu that offers a choice of flights and the option
// to quit. Selecting a particular flight should then bring up a menu similiar to that of
// exercise 8. However, one new item should be added: confirming a seat assignment. Also,
// the quit choice should be replaced with the choice of exiting to the top-level menu. Each
// display should indicate which flight is currently being handled. Also, the seat assignment
// display should indicate the confirmation status.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN         14
#define FLIGHTS      4
#define SEATS       12
#define EMPTY        0
#define TAKEN        1
#define CONFIRM      1
#define UNCONFIRMED  0
#define CONTINUE     1
#define DONE         0

struct planestats {
    int seat_id;
    int status;
    int confirmation;
    char last[LEN];
    char first[LEN];
};

struct flightstats {
    struct planestats plane_1[SEATS], *ps[SEATS];
    int flight_id;
};

int topmenu(void);
int getmenu(void);
int getlet(const char *);
int openings(const struct planestats [], int);
void show_empties(const struct planestats [], int);
void list_assign(struct planestats *[], int);
void assign_seat(struct planestats [], int);
void delete_seat(struct planestats [], int);
void show_seats(const struct planestats [], int);
void sort(struct planestats *[], int);
void makelist(const struct planestats [], char *, int);
void confirm_seat(struct planestats [], int);
char * s_gets(char * st, int n);

int main(void)
{
    struct flightstats flights[FLIGHTS];
    int flight_choice;
    int choice;
    int i, j;
    FILE *fp;
    size_t size = sizeof(struct flightstats);

    for (j = 0; j < FLIGHTS; j++)
        for (i = 0; i < SEATS; i++)
            flights[j].ps[i] = &flights[j].plane_1[i];
    if ((fp = fopen("air.dat", "rb")) == NULL)
        for (j = 0; j < FLIGHTS; j++)
            for (i = 0; i < SEATS; i++)
            {
                flights[j].plane_1[i].status = EMPTY;
                flights[j].plane_1[i].confirmation = UNCONFIRMED;
                flights[j].plane_1[i].seat_id = i + 1;
            }
    else
    {
        for (i = 0; i < FLIGHTS; i++)
            fread(flights[i].plane_1, size, SEATS, fp);
        fclose(fp);
    }
    while ((flight_choice = topmenu()) != 'q')
    {
        int index;
        switch (flight_choice)
        {
            case '1': index = 0;    break;
            case '3': index = 1;    break;
            case '4': index = 2;    break;
            case '5': index = 3;    break;
            default : puts("Switch trouble"); break;
        }
        while ((choice = getmenu()) != 'q')
        {
            switch (choice)
            {
                case 'o': printf("There are %d empty seats.\n",
                          openings(flights[index].plane_1, SEATS));
                          break;
                case 'e': show_empties(flights[index].plane_1, SEATS);
                          break;
                case 'l': list_assign(flights[index].ps, SEATS);
                          break;
                case 'a': assign_seat(flights[index].plane_1, SEATS);
                          break;
                case 'd': delete_seat(flights[index].plane_1, SEATS);
                          break;
                case 'c': confirm_seat(flights[index].plane_1, SEATS);
                          break;
                default : puts("Switch trouble");
                          break;
            }
        }
    }
    if ((fp = fopen("air.dat", "wb")) == NULL)
        puts("Can't save data to file.");
    else
    {
        for (i = 0; i < FLIGHTS; i++)
            fwrite(flights[i].plane_1, size, SEATS, fp);
        fclose(fp);
    }
    puts("Bye from Colossus Airlines!");
    return 0;
}

#define FLIGHTS_CHOICES 5
int topmenu(void)
{
    const char *descript[FLIGHTS_CHOICES] = {
        "102",
        "311",
        "444",
        "519",
        "Quit"
    };
    const char labels[FLIGHTS_CHOICES + 1] = "1345q";
    int i;

    puts("To choose a flight, enter its letter label");
    for (i = 0; i < FLIGHTS_CHOICES; i++)
        printf("%c) %s\n", labels[i], descript[i]);
    return getlet(labels);
}

#define CHOICES 7
int getmenu(void)
{
    const char *descript[CHOICES] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Confirm a seat assignment",
        "Exit to the top-level menu"
    };
    const char labels[CHOICES + 1] = "oeladcq";
    int i;

    puts("To choose a function, enter its letter label");
    for (i = 0; i < CHOICES; i++)
        printf("%c) %s\n", labels[i], descript[i]);
    return getlet(labels);
}

int getlet(const char * s)
{
    char c;

    c = getchar();
    while (strchr(s, c) == NULL)
    {
        printf("Enter a character in the list %s\n", s);
        while (getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;

    return c;
}

int openings(const struct planestats pl[], int n)
{
    int count = 0;
    int seat;

    for (seat = 0; seat < n; seat++)
        if (pl[seat].status == EMPTY)
            count++;
    return count;
}

void show_empties(const struct planestats pl[], int n)
{
    char seating[3 * SEATS];

    if (openings(pl, n) == 0)
        puts("All seats are assigned");
    else
    {
        puts("The following seats are available:");
        makelist(pl, seating, EMPTY);
        puts(seating);
    }
}

void makelist(const struct planestats pl[], char * str, int kind)
{
    int seat;
    char temp[LEN];

    str[0] = '\0';
    for (seat = 0; seat < SEATS; seat++)
        if (pl[seat].status == kind)
        {
            sprintf(temp, " %d", pl[seat].seat_id);
            strcat(str, temp);
        }
}

void list_assign(struct planestats *ps[], int n)
{
    int i;
    if (openings(*ps, n) == SEATS)
        puts("All seats are empty.");
    else
    {
        sort(ps, n);
        for (i = 0; i < SEATS; i++)
            if (ps[i]->status == TAKEN)
            {
                printf("Seat %d: %s, %s",
                    ps[i]->seat_id, ps[i]->last, ps[i]->first);
                if (ps[i]->confirmation == CONFIRM)
                    puts(", confirmed");
                else
                    puts(", unconfirmed");
            }

    }
}

void assign_seat(struct planestats pl[], int n)
{
    char list[3 * SEATS];
    int seat, loop;

    if (openings(pl, n) == 0)
        puts("All seats are assigned.");
    else
    {
        makelist(pl, list, EMPTY);
        puts("Which seat do you want? Choose from this list:");
        puts(list);
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == TAKEN)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        puts("Enter first name:");
        s_gets(pl[seat - 1].first, LEN);
        puts("Enter last name:");
        s_gets(pl[seat - 1].last, LEN);
        printf("%s %s assigned to seat %d.\n",
        pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter a to accept assignment, c to cancel it.");
        if (getlet("ac") == 'a')
        {
            pl[seat - 1].status = TAKEN;
            puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned.");
    }
}

void delete_seat(struct planestats pl[], int n)
{
    int seat, loop;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
        puts("All seats already are empty.");
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Enter the number of the seat to be cancelled:");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == EMPTY)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        printf("%s %s to be cancelled for seat %d.\n",
            pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter d to delete assignment, a to abort.");
        if (getlet("da") == 'd')
        {
            pl[seat - 1].status = EMPTY;
            puts("Passenger dropped.");
        }
        else
            puts("Passenger retained.");
    }
}

void show_seats(const struct planestats pl[], int n)
{
    int i;

    puts("Seats currently taken:");
    for (i = 0; i < SEATS; i++)
        if (pl[i].status == TAKEN)
        {
            printf("Seat %d: %s, %s", pl[i].seat_id,
                pl[i].last, pl[i].first);
            if (pl[i].confirmation == CONFIRM)
                puts(", confirmed");
            else
                puts(", unconfirmed");
        }
}

void sort(struct planestats *array[], int limit)
{
    int top, search;
    struct planestats * temp;

    for (top = 0; top < limit - 1; top++)
        for (search = top + 1; search < limit; search++)
            if (strcmp(array[search]->last, array[top]->last) < 0)
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
}

void confirm_seat(struct planestats pl[], int n)
{
    int seat, loop;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
        puts("All seats already are empty.");
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Enter the number of the seat to be confirmed:");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == EMPTY)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        printf("%s %s to be confirmed for seat %d.\n",
            pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter c to confirm assignment, a to abort.");
        if (getlet("ca") == 'c')
        {
            pl[seat - 1].confirmation = CONFIRM;
            puts("Passenger confirmed to seat.");
        }
        else
            puts("Passenger not confirmed.");
    }
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
