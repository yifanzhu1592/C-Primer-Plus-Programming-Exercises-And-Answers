/* Programming Exercise 12-8.c */

// Here's part of a program:
// #include <stdio.h>
// int * make_array(int elem, int val);
// void show_array(const int ar[], int n);
// int main(void)
// {
//     int * pa;
//     int size;
//     int value;

//     printf("Enter the number of elements: ");
//     while (scanf("%d", &size) == 1 && size > 0)
//     {
//         printf("Enter the initialization value: ");
//         scanf("%d", &value);
//         pa = make_array(size, value);
//         if (pa)
//         {
//             show_array(pa, size);
//             free(pa);
//         }
//         printf("Enter the number of elements (<1 to quit): ");
//     }
//     printf("Done.\n");
//     return 0;
// }

// Complete the program by providing function definitions for make_array() and show_
// array(). The make_array() function takes two arguments. The first is the number
// of elements of an int array, and the second is a value that is to be assigned to each
// element. The function uses malloc() to create an array of a suitable size, sets each
// element to the indicated value, and returns a pointer to the array. The show_array()
// function displays the contents, eight numbers to a line.


#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int * make_array(int elem, int val)
{
    int * arr = (int *) malloc(elem * sizeof (int));

    for (int i = 0; i < elem; i++)
        *(arr + i) = val;

    return arr;
}

void show_array(const int ar[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[cnt]);
        cnt++;
        if (cnt % 8 == 0)
            puts("");
    }
    puts("");
}
