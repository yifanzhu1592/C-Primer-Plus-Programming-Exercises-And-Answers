/* Programming Exercise 13-6.c */

// Programs using command-line arguments rely on the user's memory of how to use them
// correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line
// arguments, it prompts the user for the required information.


#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>
#define LEN 10

int main(void)
{
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char dest[LEN];    // storage for output filename
    char source[LEN];  // storage for input filename
    int count = 0;

    printf("Please enter the source file name: ");
    scanf("%s", source);

    // set up input
    if ((in = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                source);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(dest, source, LEN - 5);  // copy filename
    dest[LEN - 5] = '\0';
    strcat(dest, ".red");            // append .red
    if ((out = fopen(dest, "w")) == NULL)
    {                       // open file for writing
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
