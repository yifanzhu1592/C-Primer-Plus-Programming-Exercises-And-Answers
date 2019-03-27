/* Programming Exercise 13-1.c */

// Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user's
// response instead of using command-line arguments.


#include <stdio.h>
#include <stdlib.h> // exit() prototype
#define SLEN 20

int main(void)
{
    int ch;         // place to store each character as read
    FILE *fp;       // "file pointer"
    char file[20];
    unsigned long count = 0;

    printf("Please enter the filename: ");
    scanf("%s", file);

    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file, count);

    return 0;
}
