// Filename: stringSplit.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C
// 	    The system got the string and split by separator.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
*   Function: split()
*   Parameter:       char* str: The original string.
*                    char separator: The separator (delimiter).
*                    char* buffer: It stores the split word from the original string.
*                    char prefix: The prefix if the use want to remove.
*   Return Value:    char*: The string after removing a word after the split
*   Description:
*                This function split the original string.
*                First, it is going to remove the prefix if the user gives it.
*                Second, it copies each character to buffer until
*                    it reaches the separator in the original string.
*                Last, it moves one more character,
*                    because it stopped at the separator position.
*   			    Finally, it returns the string that removed the word
*                    , which was split in this time, for the next split.
*/
char* split(char* str, char separator, char* buffer, char prefix)
{    
    // Remove the prefix character, if the first character of string is matched
    while (*str && *str == prefix)
    {
        ++str;
    }

    // Copy each character to buffer until it reached separator
    while (*str && *str != separator)
    {
        *buffer++ = *str++;
    }

    // NULL character at last position
    *buffer = '\0';

    // Skip the separator, it prepares for the next time
    if (*str == separator)
    {
        ++str;
    }

    return str;
}


int main()
{
    char* s = malloc(1024 * sizeof(char));
    char buffer[100] = { 0 };
    
    // Get the string from the user
    printf("Typing the string:\n");
    scanf("%[^\n]", s);
    
    // Resizeing the memory
    s = realloc(s, strlen(s) + 1);

    // Split for each word
    for (int i = 1; *s; i++)
    {
        s = split(s, ' ', buffer, 0);

        printf("*%s*\n", buffer);
    }

    return 0;
}