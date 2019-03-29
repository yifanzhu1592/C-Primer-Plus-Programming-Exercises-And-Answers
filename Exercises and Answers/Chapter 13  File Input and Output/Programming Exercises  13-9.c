/* Programming Exercise 13-9.c */
/* to simplify accounting, stores one number and word per line */

// Modify the program in Listing 13.3 so that each word is numbered according to the order
// in which it was added to the list, starting with 1. Make sure that, when the program is
// run a second time, new word numbering resumes where the previous numbering left off.


#include <stdio.h>
#include <stdlib.h>
#define MAX 47

int main(void)
{
    FILE *fp;
    char words[MAX];
    int wordct = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"words\" file.\n");
        exit(EXIT_FAILURE);
    }
    // determine current number of lines
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        wordct++;
    rewind(fp);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%3d: %s\n", ++wordct, words);
    puts("File contents:");
    rewind(fp);           // go back to beginning of file
    while (fgets(words, MAX, fp) != NULL) // read line including number
        fputs(words, stdout);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    puts("Done");

    return 0;
}
