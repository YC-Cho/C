// Filename: linkedList.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C.
// 	    It checks two strings are match as an anagram or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE        (26 * 2)       // a - z and A - Z

typedef enum  {
    Success = 0,
    False = 1,
    Unknown = 2
} Result;




/*
*   Function: getCollect()
*   Parameter:      char str[]: The original string.
*   Return Value:   int*: It stores how many characters are in the string.
*   Description:    This function is to read the string
*                       and counting for each alphabet.
*/
int* getCollect(char str[])
{
    int strSize = strlen(str);
    int* retValue = (int*)malloc(sizeof(int) * MAX_SIZE);
    int position = 0;

    // Set all value is 0
    memset(retValue, 0, sizeof(int) * MAX_SIZE);

    for (int i = 0; i < strSize; i++)
    {
        if(isupper(str[i]))
        {
            // Upper case alphabet will store from 0 to 25
            position = str[i] - 'A';
        }
        else if(islower(str[i]))
        {
            // Lower case alphabet will store from 26 to 51
            position = str[i] - 'a' + (MAX_SIZE / 2);
        }
        else if (isblank(str[i]))
        {
            // Skip the whitespace
            continue;
        }
        else
        {
            // Only alphabet and whitespace are acceptable
            printf("This program only accepts the alphabet!\n");
            printf("\t'%c' is not alphabet.\n", str[i]);
            return NULL;
        }
        
        retValue[position]++;
    }

    return retValue;
}



/*
*   Function: stringAnagrams()
*   Parameter:      char* str1: The first original string.
*                   char* str2: The second original string.
*   Return Value:   int: It indicates the result of processing.
*                       If 0, two stirngs are match.
*                       If 1, two stirngs are not match.
*                       If 2, strings have a non-alphabet character.
*   Description:    This function is checking the two strings.
*                       
*/
int stringAnagrams(char* str1, char* str2)
{

    if (strlen(str1) != strlen(str2))
    {
        // If the length of two strings are not matched,
        // it is not an anagram
        return False;
    }

    // Get the collection of alphabet
    int* str1List = getCollect(str1);
    int* str2List = getCollect(str2);

    
    if((str1List != NULL) && (str2List != NULL))
    {
        // Check the count of each alphabet
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (str1List[i] != str2List[i])
            {
                // If the counting number is not matched,
                // it is not an anagram
                return False;
            }
        }

        return Success;
    }

    return Unknown;
}






int main()
{
    char str1[30] = "To be or not to be zzz";
    char str2[30] = "zzz not to be or To be";

    int result = stringAnagrams(str1, str2);

    switch (result)
    {
        case Success:
            printf("'%s' and '%s' is anagram.\n", str1, str2);
            break;
        case False:
            printf("'%s' and '%s' is NOT anagram.\n", str1, str2);
            break;
        case Unknown:
            printf("'%s' and '%s' is not only alphabet character.\n", str1, str2);
            break;
    }
        
        

    return 0;
}