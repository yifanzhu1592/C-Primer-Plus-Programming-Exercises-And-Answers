/* Programming Exercise 13-3.c */

// Write a file copy program that prompts the user to enter the name of a text file to act as
// the source file and the name of an output file. The program should use the toupper()
// function from ctype.h to convert all text to uppercase as it's written to the output file.
// Use standard I/O and the text mode.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SLEN 20

int main(void)
{
    char ch;
    char sourcefile[SLEN];
    char targetfile[SLEN];
    FILE * source;
    FILE * target;

    printf("Please enter the name of a text file to act as the source file: ");
    scanf("%s", sourcefile);
    printf("Please enter the name of a text file to act as the output file: ");
    scanf("%s", targetfile);

    if ((source = fopen(sourcefile, "r")) == NULL)
    {
        printf("Could not open file %s for input\n", sourcefile);
        exit(EXIT_FAILURE);
    }

    if ((target = fopen(targetfile, "w")) == NULL)
    {
        printf("Could not open file %s for output\n", targetfile);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source)) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putc(ch, target);
    }

    if (fclose(source) != 0)
        printf("Could not close file %s\n", sourcefile);

    if (fclose(target) != 0)
        printf("Could not close file %s\n", targetfile);

    return 0;
}
