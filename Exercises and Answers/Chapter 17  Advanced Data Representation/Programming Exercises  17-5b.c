/* Programming Exercise 17-5b.c -- stack operation */

// Write a program that lets you input a string. The program then should push the
// characters of the string onto a stack, one by one (see review question 5), and then pop
// the characters from the stack and display them. This results in displaying the string in
// reverse order.


#include <stdio.h>
#include <stdlib.h>
#include "Programming Exercise  17-5.h"

void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

bool FullStack(const Stack * ps)
{
    return ps->top == MAXSTACK;
}

bool EmptyStack(const Stack * ps)
{
    return ps->top == 0;
}

bool Push(Item item, Stack * ps)
{
    if (ps->top == MAXSTACK)
        return false;
    else
    {
        ps->items[ps->top++] = item;
        return true;
    }
}

bool Pop(Item *pitem, Stack * ps)
{
    if (ps->top == 0)
        return false;
    else
    {
        ps->top--;
        *pitem = ps->items[ps->top];
        return true;
    }
}
