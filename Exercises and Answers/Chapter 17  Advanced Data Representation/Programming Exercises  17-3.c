/* Programming Exercise 17-3.c -- revised list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list17-3.h"

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

/* returns number of items in list */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* adds item to list */
/* assumes = operator defined for type Item */
bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
        return false;
    else
    {
        plist->entries[plist->items++] = item;
        return true;
    }
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    int i;

    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);  /* apply function to item in list */
}

/* malloc() not used, nothing need be deallocated */
/* set items member to 0                          */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}
