/* Programming Exercise 17-5.h -- header file for a stack type */

// Write a program that lets you input a string. The program then should push the
// characters of the string onto a stack, one by one (see review question 5), and then pop
// the characters from the stack and display them. This results in displaying the string in
// reverse order.


#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>  /* C99 */
/* enum bool {false, true}; */  /* pre-C99*/

/* INSERT ITEM TYPE HERE */
/* FOR EXAMPLE, typedef int Item; */

typedef char  Item;

#define MAXSTACK 100

typedef struct stack
{
    Item item[MAXSTACK];    /* holds info                 */
    int top;                /* index of first, empty slot */
} Stack;

/* operation:       initialize the stack                */
/* precondition:    ps points to a stack                */
/* postcondition:   stack is initialized to being empty */
void InitializeStack(Stack * ps);

/* operation:       check if stack is full                      */
/* precondition:    ps points to previously initialized stack   */
/* postcondition:   returns True if stack is full, else False   */
bool FullStack(const Stack * ps);

/* operation:       check if stack is empty                     */
/* precondition:    ps points to previously initialized stack   */
/* postcondition:   returns True if stack is empty, else False  */
bool EmptyStack(const Stack * ps);

/* operation:       push item onto top of stack                 */
/* precondition:    ps points to previously initialized stack   */
/*                  item is to be placed on top of stack        */
/* postcondition:   if stack is not full, item is placed at     */
/*                  top of stack and function returns           */
/*                  True; otherwise, stack is unchanged and     */
/*                  function returns False                      */
bool Push(Item item, Stack * ps);

/* operation:       remove item from top of stack               */
/* precondition:    ps points to previously initialized stack   */
/* postcondition:   if stack is not empty, item at top of       */
/*                  stack is copied to *pitem and deleted from  */
/*                  stack, and function returns True; if the    */
/*                  operation empties the stack, the stack is   */
/*                  reset to empty. If the stack is empty to    */
/*                  begin with, stack is unchanged and the      */
/*                  function returns False                      */
bool Pop(Item *pitem, Stack * ps);

#endif
