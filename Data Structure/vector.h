// Filename: vector.h
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C
//      This file contains the constant value and integer type of vector function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFALUT_SIZE                10
#define DEFALUT_VALUE               -1 
#define IntAlloc(X)                 (int*)malloc(sizeof(int) * X)
#define IntReAlloc(X, Y)            (int*)realloc(X, sizeof(int) * Y)


typedef struct
{
    int     size;       // The number of data is in the data variable
    int     length;     // The allocated length of data variable
    int*    data;       // The actual value is in stored
} vectorInt;


// Initiated the integer vector structure
vectorInt vecIntInit(void);

// Push(insert) and pop(remove) from the front side
void vecIntPuchFront(vectorInt* vector, int num);
int vecIntPopFront(vectorInt* vector);

// Push(insert) and pop(remove) from the back side
void vecIntPushBack(vectorInt* vector, int num);
int vecIntPopBack(vectorInt* vector);