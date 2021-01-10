


#include "vector.h"


/*
*   Function: vecIntInit()
*   Parameter:      None
*   Return Value:   vectorInt: The vector structure that is initiated.
*   Description:    This function is initiated the vector structure.
*/
vectorInt vecIntInit(void)
{
    vectorInt retValue;
    retValue.size = 0;
    retValue.length = DEFALUT_SIZE;
    retValue.data = IntAlloc(DEFALUT_SIZE);
    memset(retValue.data, DEFALUT_VALUE, sizeof(int) * DEFALUT_SIZE);
   
    return retValue;
}


/*
*   Function: vecIntPuchFront()
*   Parameter:      vectorInt* vector: The vector data.
*                   int: The value that is going to store in the vector.
*   Return Value:   None
*   Description:    
*                This function is inserting the value 
*                   into the front of the vactor.
*/
void vecIntPuchFront(vectorInt* vector, int num)
{
    // Check the vector size
    // If the vector is full, increase the size twice
    if (vector->size == vector->length)
    {
        int* temp = IntReAlloc(vector->data, vector->length * 2);

        vector->length *= 2;
        vector->data = temp;
    }

    // Move one step for existed data
    memcpy(vector->data + 1, vector->data, sizeof(int)*(vector->size));

    // Adding the data at the front and increase the vector size
    vector->data[0] = num;
    vector->size += 1;
}



/*
*   Function: vecIntPopFront()
*   Parameter:      vectorInt* vector: The vector data.
*   Return Value:   int: The integer that was stored in the vector at the front.
*   Description:    
*                This function is taking out the data 
*                   which is stored at the fornt of vector.
*/
int vecIntPopFront(vectorInt* vector)
{
    int retValue = vector->data[0];

    // Reduce the size of vector
    --(vector->size);

    // Remove the first value in the vector
    memcpy(vector->data, vector->data + 1, sizeof(int)*(vector->size));

    // Reduce the size of vector
    // if the vector size is too much bigger than that stores.
    // Reduce the unecessary memory space.
    if ( (vector->size < vector->length / 3)
        && (vector->length > DEFALUT_SIZE) )
    {
        int* temp = IntReAlloc(vector->data, (vector->length / 2));

        vector->length /= 2;
        vector->data = temp;
    }

    // Reset the value
    vector->data[vector->size] = DEFALUT_VALUE;

    return retValue;
}





/*
*   Function: vecIntPushBack()
*   Parameter:      vectorInt* vector: The vector data.
*                   int: The value that is going to store in the vector.
*   Return Value:   None
*   Description:    
*                This function is inserting the value 
*                   into the last location of the vactor.
*/
void vecIntPushBack(vectorInt* vector, int num)
{
    // Check the vector size
    // If the vector is full, increase the size twice
    if (vector->size == vector->length)
    {
        int* temp = IntReAlloc(vector->data, vector->length * 2);

        vector->length *= 2;
        vector->data = temp;
    }

    // Adding the data at the last and increase the vector size
    vector->data[(vector->size)++] = num;
}




/*
*   Function: vecIntPopBack()
*   Parameter:      vectorInt* vector: The vector data.
*   Return Value:   int: The integer that was stored in the vector at the last.
*   Description:    
*                This function is taking out the data 
*                   which is stored at the last value of vector.
*/
int vecIntPopBack(vectorInt* vector)
{
    // Get the value and Reduce the size of vector
    int retValue = vector->data[--(vector->size)];
    vector->data[vector->size] = DEFALUT_VALUE;

    // Remove the first value in the vector
    // memcpy(vector->data, vector->data + 1, sizeof(int)*(vector->size));

    // Reduce the size of vector
    // if the vector size is too much bigger than that stores.
    // Reduce the unecessary memory space.
    if ( (vector->size < vector->length / 3)
        && (vector->length > DEFALUT_SIZE) )
    {
        int* temp = IntReAlloc(vector->data, (vector->length / 2));

        vector->length /= 2;
        vector->data = temp;
    }


    return retValue;
}

void vecIntPrint(vectorInt* vector)
{
    for(int i = 0; i < vector->size; i++)
    {
        printf("%d) %d\n", i, vector->data[i]);
    }
}







int main()
{
    // Initialized the vector
    vectorInt vecInt = vecIntInit();

    // Push back 10 element into the vector
    for (int i = 0; i < 10; i++)
    {
        vecIntPushBack(&vecInt, i);
    }

    // Pop front 6 element from the vector
    for (int i = 0; i < 6; i++)
    {
        int temp = vecIntPopFront(&vecInt);
    }

    // Push back 6 element
    for (int i = 0; i < 6; i++)
    {
        vecIntPushBack(&vecInt, i);
    }

    printf("Before: \n");
    vecIntPrint(&vecInt);
    
    // Push 100 value into the vector at the front location
    vecIntPuchFront(&vecInt, 100);

    printf("Add 100: \n");
    vecIntPrint(&vecInt);

    // Remove the value from the back side
    int temp = vecIntPopBack(&vecInt);

    printf("Pop Back: (%d)\n", temp);
    vecIntPrint(&vecInt);

    return 0;
}