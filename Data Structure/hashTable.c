// Filename: hashTable.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C.
// 	    It is a hash table program one of data structure.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./hashTable.h"

struct HashTable* initHashTable()
{
    struct HashTable* hashTable = alloc(MODE_VALUE * sizeof(struct HashTable));

    for(int i = 0; i < MODE_VALUE; i++)
    {
        hashTable[i].size = 0;
        hashTable[i].header = NULL;
    }

    return hashTable;
}



struct Node* createNewNode(char* str, int value)
{
    struct Node* newNode = alloc(struct Node);

    // Create the new node
    strcpy(newNode->str, str);
	newNode->value = value;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;

    return newNode;
}


/*
*   Function: getHashValue()
*   Parameter:	    char* str: The original string.
*   Return Value:   int:	It will return the hash value which calculated by name.
*   Description:    This function calculate and return the hash value based on the name.
*/
int getHashValue(char* str)
{
	unsigned int result = 0;
    unsigned int sumValue = 0;
	int stringSize = 0;

	stringSize = strlen(str);
	for (int count = 0; count < stringSize; count++)
	{
		sumValue += (int)str[count];
	}

	result = sumValue % MODE_VALUE;

	return result;
}



struct HashTable insertHashTable(struct Node* newNode, struct HashTable hashTable)
{
    struct Node* tempNode = NULL;

    if (hashTable.size == 0)
    {
        hashTable.header = newNode;
    }
    else
    {
        tempNode = hashTable.header;

        while(tempNode->nextNode != NULL)
        {
            tempNode = tempNode->nextNode;
        }

        tempNode->nextNode = newNode;
        newNode->prevNode = tempNode;
    }
    
    ++(hashTable.size);

    return hashTable;
}


void printHashTable(struct HashTable hashTable)
{
    struct Node* tempNode = hashTable.header;

    while(tempNode != NULL)
    {
        printf("%s", tempNode->str);
        tempNode = tempNode->nextNode;
        if (tempNode != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}




int main()
{
    unsigned int hashValue = 0;
    struct HashTable* hashTable = initHashTable();
    
    struct Node* node1 = createNewNode("John", 1);
    struct Node* node2 = createNewNode("Bob", 2);
    struct Node* node3 = createNewNode("Smith", 3);

    hashValue = getHashValue(node1->str);
    hashTable[hashValue] = insertHashTable(node1, hashTable[hashValue]);
    hashTable[hashValue] = insertHashTable(node2, hashTable[hashValue]);
    hashTable[hashValue] = insertHashTable(node3, hashTable[hashValue]);
    // hashValue = getHashValue(node2->str);
    // hashValue = getHashValue(node3->str);


    // printf("%d\n", hashTable[hashValue].size);
    // printHashTable(hashTable[hashValue]);

    return 0;
}