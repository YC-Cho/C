// Filename: linkedList.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C.
// 	    It is a linked list program one of data structure.

#include <stdio.h>
#include <stdbool.h>
#include "./linkedList.h"

/*
*   Function: listSize()
*   Parameter:      List* str: The linked list structure.
*   Return Value:   int: The size of list.
*   Description:    This function is returning the size of list.
*/
int listSize(List* list)
{
	return (list->count);
}


/*
*   Function: createNewNode()
*   Parameter:      strcut LinkedNode* str: The last node in the list.
*                   int value: the value that is insert into the list.
*   Return Value:   strcut LinkedNode*: The new node that include the value and pointer.
*   Description:    
*                This function is creating the new node
*                   that includes the value and the pointer of previous node.
*/
struct LinkedNode* createNewNode(struct LinkedNode* lastNode, int value)
{
    struct LinkedNode* newNode = alloc(struct LinkedNode);

    // Create the new node
    newNode->key = value;
	newNode->next = NULL;
    newNode->before = lastNode;

    return newNode;
}


/*
*   Function: inseartNode()
*   Parameter:      List* str: The linked list structure.
*                   int value: The value that is insert into the list.
*   Return Value:   None
*   Description:
*                This function is storing the value into the list.
*                Find the last list and connect the new list after that.
*/
void inseartNode(List* list, int value)
{
	struct LinkedNode* newNode = NULL;
	struct LinkedNode* tempNode = list->header;
    
	if (tempNode == NULL)
	{
        // Create the first node in the list
		list->header = createNewNode(tempNode, value);
        list->tail = list->header;
	}
	else
	{
        // Find the last list
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
        
        // Create the new node and put the pointer in the previous node.
		tempNode->next = createNewNode(tempNode, value);

        list->tail = tempNode->next;
	}

    // Increate the size
	++(list->count);
}



/*
*   Function: inseartList()
*   Parameter:      List* str: The linked list structure.
*                   int value: The value that is insert into the list.
*   Return Value:   None
*   Description:
*                   This function is finding and removing the node.
*                   First, to find the node that stores the value.
*                   Second, to change the pointer for skipping that node.
*                   Last, delete the node using free() for preventing the memory leak.
*/
bool removeNode(List* list, int targetValue)
{
	struct LinkedNode* previousNode = NULL;
    struct LinkedNode* nextNode = NULL;
	struct LinkedNode* tempNode = list->header;

    // Check the value for all nodes
    while(tempNode != NULL)
    {
        if (tempNode->key == targetValue)
        {
            // If target node is the first node
            if (list->header == tempNode)
            {   
                nextNode = tempNode->next;
                // Change the header
                list->header = nextNode;
                
            }
            // If target node is the last node
            else if (list->tail == tempNode)
            {
                previousNode = tempNode->before;
                // Change the tail
                list->tail = previousNode;
            }
            else
            {
                previousNode = tempNode->before;
                nextNode = tempNode->next;
            }
            
            // Switch the pointer to skip the node which is going to erase
            if (previousNode != NULL)
                previousNode->next = nextNode;
            if (nextNode != NULL)
                nextNode->before = previousNode;

            // Release the memory
            free(tempNode);

            // Decrese the list count
            --(list->count);

            return true;
        }
        else
        {
            tempNode = tempNode->next;
        }
    }

    return false;
}




/*
*   Function: printListForward()
*   Parameter:      List* str: The linked list structure.
*   Return Value:   None
*   Description:    This function is printing out the value of all nodes 
                        in the list in order.
*/
void printListForward(List* list)
{
	struct LinkedNode* tempNode = list->header;

	while (tempNode != NULL)
	{
		printf("%d -> ", tempNode->key);
		tempNode = tempNode->next;
	}

	printf("Done!!\n");
}


/*
*   Function: printListReverse()
*   Parameter:      List* str: The linked list structure.
*   Return Value:   None
*   Description:    This function is printing out the value of all nodes 
                        in the list in reverse order.
*/
void printListReverse(List* list)
{
	struct LinkedNode* tempNode = list->tail;

	while (tempNode != NULL)
	{
		printf("%d -> ", tempNode->key);
		tempNode = tempNode->before;
	}

	printf("Done!!\n");
}





int main()
{
    List* LinkedList = alloc(List);

	LinkedList->count = 0;
	LinkedList->header = NULL;

    inseartNode(LinkedList, 1);
    printf("List Size = %d\n", listSize(LinkedList));
    inseartNode(LinkedList, 2);
    printf("List Size = %d\n", listSize(LinkedList));
    inseartNode(LinkedList, 3);
    printf("List Size = %d\n", listSize(LinkedList));

    removeNode(LinkedList, 1);
    printf("List Size = %d\n", listSize(LinkedList));

    printListForward(LinkedList);
    printListReverse(LinkedList);

    return 0;
}


