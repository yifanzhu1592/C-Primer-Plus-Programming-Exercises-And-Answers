/* Programming Exercise 13-8.c */

// Write a program that takes as command-line arguments a character and zero or more
// filenames. If no arguments follow the character, have the program read the standard
// input. Otherwise, have it open each file in turn and report how many times the character
// appears in each file. The filename and the character itself should be reported along with
// the count. Include error-checking to see whether the number of arguments is correct and
// whether the files can be opened. If a file can't be opened, have the program report that
// fact and go on to the next file.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int ch;
    int count = 0;
    int fct;

    if (argc < 3)
    {
        printf("Usage: %s character filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (fct = 2; fct < argc; fct++)
    {
        if ((file = fopen(argv[fct], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[fct]);
        else
        {
            if (ferror(file) != 0)
                fprintf(stderr, "Error in reading file %s.\n",
                        argv[fct]);
            ch = (char)getc(file);
            while (ch != EOF)
            {
                if (argv[1][0] == ch)
                    count++;
                ch = (char)getc(file);
            }
            printf("The character %s has appeared in file %s for %d times.\n",
                    argv[1], argv[fct], count);
            count = 0;
            fclose(file);
        }
    }

    return 0;
}
