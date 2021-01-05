// Filename: linkedList.h
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C
//      This file contains the constant value and LinkedList function.

#include <stdlib.h>

#define alloc(X)	malloc(sizeof(X));


struct LinkedNode {
	int key;
    struct LinkedNode* before;
	struct LinkedNode* next;
} ;


typedef struct {
	int count;
	struct LinkedNode* header;
    struct LinkedNode* tail;
} List;


// Get the size of list
int listSize(List* list);

// Insert the Node into Linked List
void inseartNode(List* list, int value);
// Insert the Node into Linked List
bool removeNode(List* list, int targetValue);

// Print out all list information
void printListForward(List* list);
void printListReverse(List* list);