/* Programming Exercise 15-6.c */

// Design a bit-field structure that holds the following information:
// Font ID: A number in the range 0-255
// Font Size: A number in the range 0-127
// Alignment: A number in the range 0-2 represented the choices Left, Center, and Right
// Bold: Off (0) or on (1)
// Italic: Off (0) or on (1)
// Underline: Off (0) or on (1)
// Use this structure in a program that displays the font parameters and uses a looped menu
// to let the user change parameters.
// The program should use the & operator and suitable masks to ensure that the ID and size
// entries are converted to the specified range.


#include <stdio.h>
#include <stdbool.h>

#define LEFT        0
#define CENTER      1
#define RIGHT       2
#define ID_MASK     0xFF
#define SIZE_MASK   0x7F

struct Font {
    unsigned int id         : 8;
    unsigned int size       : 7;
    unsigned int            : 1;
    unsigned int alignment  : 2;
    bool bold               : 1;
    bool italic             : 1;
    bool underline          : 1;
    unsigned int            : 3;
};

int main(void)
{
    struct Font font = {1, 12, LEFT, false, false, false};

    puts(" ID SIZE ALIGNMENT   B   I   U");
    printf("%3d %4d", font.id, font.size);
    if (font.alignment == 0)
        printf("   left    ");
    else if (font.alignment == 1)
        printf(" center    ");
    else
        printf("  right    ");

    if (font.bold)
        printf("  on");
    else
        printf(" off");
    if (font.italic)
        printf("  on");
    else
        printf(" off");
    if (font.underline)
        printf("  on");
    else
        printf(" off");
    putchar('\n');
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");

    char choice;
    scanf("%c", &choice);
    getchar();
    while (choice != 'q')
    {
        switch(choice)
        {
            case 'f':   printf("Enter font id (0-255): ");
                        int input_id;
                        scanf("%d", &input_id);
                        font.id = input_id & ID_MASK;
                        getchar();
                        break;

            case 's':   printf("Enter font size (0-127): ");
                        int input_size;
                        scanf("%d", &input_size);
                        font.size = input_size & SIZE_MASK;
                        getchar();
                        break;

            case 'a':   puts("Select alignment:");
                        puts("l)left   c)center   r)right");
                        char input_alignment;
                        scanf("%c", &input_alignment);
                        if (input_alignment == 'l')
                            font.alignment = 0;
                        else if (input_alignment == 'c')
                            font.alignment = 1;
                        else
                            font.alignment = 2;
                        getchar();
                        break;

            case 'b':   font.bold = ~font.bold;
                        break;

            case 'i':   font.italic = ~font.italic;
                        break;

            case 'u':   font.underline = ~font.underline;
                        break;
        }

        puts(" ID SIZE ALIGNMENT   B   I   U");
        printf("%3d %4d", font.id, font.size);
        if (font.alignment == 0)
            printf("   left    ");
        else if (font.alignment == 1)
            printf(" center    ");
        else
            printf("  right    ");

        if (font.bold)
            printf("  on");
        else
            printf(" off");
        if (font.italic)
            printf("  on");
        else
            printf(" off");
        if (font.underline)
            printf("  on");
        else
            printf(" off");
        putchar('\n');
        puts("f)change font    s)change size    a)change alignment");
        puts("b)toggle bold    i)toggle italic  u)toggle underline");
        puts("q)quit");

        scanf("%c", &choice);
        getchar();
    }

    puts("Bye!");

    return 0;
}
