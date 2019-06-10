/* Programming Exercise 17-6.c */

// Write a function that takes three arguments: the name of an array of sorted integers, the
// number of elements of the array, and an integer to seek. The function returns the value
// 1 if the integer is in the array, and 0 if it isn't. Have the function use the binary search
// technique.


#include <stdio.h>
int inarray(const int sorted[], int size, int val);
#define SIZE 10

int main(void)
{
    int nums[SIZE] = {1, 20, 40, 41, 42, 43, 70, 88, 92, 109};
    int num;
    int found;

    printf("Enter an integer to search for: ");
    while (scanf("%d", &num) == 1)
    {
        found = inarray(nums, SIZE, num);
        printf("%d %s in the array.\n", num, found? "is" : "isn't");
        printf("Next value (q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

int inarray(const int sorted[], int size, int val)
{
    int min = 0;
    int max = size - 1;
    int mid;
    int found = 0;

    while (min < max)
    {
        mid = (min + max) / 2;
        if (val < sorted[mid])
            max = mid - 1;
        else if (val > sorted[mid])
            min = mid + 1;
        else
        {
            found = 1;
            break;
        }
    }
    if (sorted[min] == val)
        found = 1;

    return found;
}
