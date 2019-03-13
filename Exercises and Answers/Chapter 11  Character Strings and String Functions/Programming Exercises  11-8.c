/* Programming Exercise 11-8 */

// Write a function called string_in() that takes two string pointers as arguments. If
// the second string is contained in the first string, have the function return the address
// at which the contained string begins. For instance, string_in("hats", "at") would
// return the address of the a in hats. Otherwise, have the function return the null pointer.
// Test the function in a complete program that uses a loop to provide input values for
// feeding to the function.


#include <stdio.h>
#define LEN 20
char * string_in(const char * s1, const char * s2);
int main(void)
{
    char orig[LEN] = "transportation";
    char * find;

    puts(orig);
    find = string_in(orig, "port");
    if (find)
        puts(find);
    else
        puts("Not found");
    find = string_in(orig, "part");
    if (find)
        puts(find);
    else
        puts("Not found");

    return 0;
}

#include <string.h>
char * string_in(const char * s1, const char * s2)
{
    int l2 = strlen(s2);
    int tries;            /* maximum number of comparisons    */
    int nomatch = 1;    /* set to 0 if match is found        */

    tries = strlen(s1) + 1 - l2;
    if (tries > 0)
        while (( nomatch = strncmp(s1, s2, l2)) && tries--)
            s1++;
    if (nomatch)
        return NULL;
    else
        return (char *) s1;  /* cast const away */
}
