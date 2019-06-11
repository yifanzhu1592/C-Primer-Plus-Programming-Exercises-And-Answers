/* Programming Exercise 17-7.h : copy of tree.h -- binary search tree */

// Write a program that opens and reads a text file and records how many times each word
// occurs in the file. Use a binary search tree modified to store both a word and the number
// of times it occurs. After the program has read the file, it should offer a menu with three
// choices. The first is to list all the words along with the number of occurrences. The
// second is to let you enter a word, with the program reporting how many times the word
// occurred in the file. The third choice is to quit.


/*           no duplicate items are allowed in this tree */

#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>    /* C99 */
/* enum bool {false, true}; */  /* pre-C99 */
#define SLEN 81

/* redefine Item as appropriate */
typedef struct item
{
    char wrd[SLEN];
    int count;
} Item;

#define MAXITEMS 100

typedef struct node
{
    Item item;
    struct node * left;     /* pointer to right branch  */
    struct node * right;    /* pointer to left branch   */
} Node;

typedef struct tree
{
    Node * root;            /* pointer to root of tree  */
    int size;               /* number of items in tree  */
} Tree;

/* function prototypes */

/* operation:      initialize a tree to empty          */
/* preconditions:  ptree points to a tree              */
/* postconditions: the tree is initialized to empty    */
void InitializeTree(Tree * ptree);

/* operation:      determine if tree is empty          */
/* preconditions:  ptree points to a tree              */
/* postconditions: function returns true if tree is    */
/*                 empty and returns false otherwise   */
bool TreeIsEmpty(const Tree * ptree);

/* operation:      determine if tree is full           */
/* preconditions:  ptree points to a tree              */
/* postconditions: function returns true if tree is    */
/*                 full and returns false otherwise    */
bool TreeIsFull(const Tree * ptree);

/* operation:      determine number of items in tree   */
/* preconditions:  ptree points to a tree              */
/* postconditions: function returns number of items in */
/*                 tree                                */
int TreeItemCount(const Tree * ptree);

/* operation:      add an item to a tree               */
/* preconditions:  pi is address of item to be added   */
/*                 ptree points to an initialized tree */
/* postconditions: if possible, function adds item to  */
/*                 tree and returns true; otherwise,   */
/*                 the function returns false          */
bool AddItem(const Item * pi, Tree * ptree);

/* operation:      find an item in a tree              */
/* preconditions:  pi points to an item                */
/*                 ptree points to an initialized tree */
/* postconditions: function returns true if item is in */
/*                 tree and returns false otherwise    */
bool InTree(const Item * pi, const Tree * ptree);

/* operation:      delete an item from a tree          */
/* preconditions:  pi is address of item to be deleted */
/*                 ptree points to an initialized tree */
/* postconditions: if possible, function deletes item  */
/*                 from tree and returns true;         */
/*                 otherwise the function returns false*/
bool DeleteItem(const Item * pi, Tree * ptree);

/* operation:      apply a function to each item in    */
/*                 the tree                            */
/* preconditions:  ptree points to a tree              */
/*                 pfun points to a function that takes*/
/*                 an Item argument and has no return  */
/*                 value                               */
/* postconditions: the function pointed to by pfun is  */
/*                 executed once for each item in tree */
void Traverse(const Tree * ptree, void (* pfun)(Item item));

/* operation:      delete everything from a tree       */
/* preconditions:  ptree points to an initialized tree */
/* postconditions: tree is empty                       */
void DeleteAll(Tree * ptree);

/* operation:      return address of item in a tree    */
/* preconditions:  pi points to an item                */
/*                 ptree points to an initialized tree */
/* postconditions: function returns address if item is */
/*                 in tree and returns NULL otherwise  */
const Item * WhereInTree(const Item * pi, const Tree * ptree);

#endif
