/* Programming Exercise 13-12.c */

// Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
// 0-9 and be separated by spaces. The file is a digital representation of a picture, with
// the values 0 through 9 representing increasing levels of darkness. Write a program that
// reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use the values
// in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a
// space character, a 1 value to the period character, and so on, with each larger number
// represented by a character that occupies more space. For example, you might use # to
// represent 9. The last character (the 31st) in each row should be a null character, making
// it an array of 20 strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file.


#include <stdio.h>
#include <stdlib.h>

#define ROWS    20
#define COLS    30
#define LEVELS  10
const char trans[LEVELS + 1] = " .':~*=&%@";

void MakePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);

int main()
{
    int row, col;
    int picIn[ROWS][COLS];
    char picOut[ROWS][COLS];
    char fileName[81];
    FILE * infile;

    init(picOut, 'S');

    printf("Enter name of file: ");
    scanf("%80s", fileName);
    if ((infile = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            fscanf(infile, "%d", &picIn[row][col]);
    if (ferror(infile))
    {
        fprintf(stderr, "Error getting data from file.\n");
        exit(EXIT_FAILURE);
    }
    MakePic(picIn, pinOut, ROWS);

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
            putchar(picOut[row][col]);
        putchar('\n');
    }
    return 0;
}

void init(char arr[][COLS], char ch)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            arr[r][c] = ch;
}

void MakePic(int data[][COLS], char pic[][COLS], int rows)
{
    int row, col;
    for (row = 0; row < rows; row++)
        for (col = 0; col < COLS; col++)
            pic[row][col] = trans[data[row][col]];
}
