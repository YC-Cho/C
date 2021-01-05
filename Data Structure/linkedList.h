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



// Insert the Node into Linked List
void inseartNode(List* list, int value);
// Insert the Node into Linked List
bool removeNode(List* list, int targetValue);
// Print out all list information
void printList(List* list);
// Get the size of list
int listSize(List* list);


// // Print out the every information from the first to the last
// void printForword(struct node* header);
// // Print out the every information from the last to first
// void printBackword(struct node* tail);
// // Sort the Linked list
// void sortList(struct node* header);
// // Remove the information
// void removeList(struct node* header);
