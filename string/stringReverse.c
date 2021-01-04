// Filename: stringReverse.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C
// 	    The system got the string and return the string after reversed.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*   Function: reverseString()
*   Parameter:       char* str: The original string, which is going to reverse it.
*   Return Value:    char*: The string that reversed the original one.
*   Description:
*                This function reveserse the original string.
*                Basically, it gets from the last character of the original
*                    and then copies to the returning string the first position.
*                It going to repeat until it reached the first position of the original string.
*   			    Also, it is going to copy center character seperatly
*                    if the original string length is odd.
*/
char* reverseString(char* str)
{
    int size = strlen(str);
	char* result = malloc(sizeof(char) * size);

	int middle = size / 2;
    for (int i = 0; i < middle; i++)
    {
    	result[i] = str[size - 1 - i];
		result[size - 1 - i] = str[i];
	}

    // Copy the center node from the original string.
    // If the original string length is odd number
    // the center node is not copy yet.        
	if (size % 2 != 0)
	{
		result[middle] = str[middle];
	}
	result[size] = '\0';

	return result;
}

/*
*   Function: reverseStringMemcpy()
*   Parameter:       char* str: The original string, which is going to reverse it.
*   Return Value:    char*: The string that reversed the original one.
*   Description:
*                This function reveserse the original string.
*                First, the original string memory is going to copy to returning string.
*                Then, it gets from the last character of the original
*                    and then copies to the returning string the first position.
*                It going to repeat until it reached the first position of the original string.
*/
char* reverseStringMemcpy(char* str)
{
    int size = strlen(str);
    char* result = malloc(sizeof(char) * size);

    // Because of memory copy, the result is same as original string.
    // (Does not care of center node of odd length of string)
    memcpy(result, str, size+1);

    int middle = size / 2;
    for (int i = 0; i < middle; i++)
    {
    	result[i] = str[size - 1 - i];
		result[size - 1 - i] = str[i];
	}
    result[size] = '\0';

	return result;
}



int main()
{
    char str[30] = { "Thank you very much!" };

    printf("Original string: %s\n", str);
    printf("Reverse string: %s\n", reverseString(str));
    printf("Reverse2 string: %s\n", reverseStringMemcpy(str));

    return 0;
}