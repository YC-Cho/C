// Filename: stringTrim.c
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C
// 	    The system is trimming the whitespace from the string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
*   Function: ltrim()
*   Parameter:       char* str: The original string.
*   Return Value:    char*: The string after remove the left side of whitespace.
*   Description:
*                   This function is trimming the left side of the whitespace
*                       in the original string.
*/
char* ltrim(char* str)
{
    // Move one step if the character is space
    while(isspace(*str))
    {
        str++;
    }
    
    return str;
}



/*
*   Function: ltrim()
*   Parameter:       char* str: The original string.
*   Return Value:    char*: The string after remove the right side of whitespace.
*   Description:
*                   This function is to remove the whitespace from the endpoint of
*                       the original string.
*/
char* rtrim(char* str)
{
    char* last = str + strlen(str) - 1;

    while(isspace(*last))
    {
        *last = '\0';
        --last;
    }

    return str;
}



/*
*   Function: trim()
*   Parameter:       char* str: The original string.
*   Return Value:    char*: The string after remove the whitespace (left and right).
*   Description: This function is to remove the whitespace at prefix and suffix.
*/
char* trim(char* str)
{
    return rtrim(ltrim(str));
}


/*
*   Function: trimWhiteSpace()
*   Parameter:       char* str: The original string.
*   Return Value:    char*: The string after removing all whitespace in the string.
*   Description: This function is to remove all whitespace in the original string.
*/
char* trimWhiteSpace(char* str)
{
    char* returnStr = trim(str);
    char* target = returnStr;
    
    for(; *target += '\0'; target++)
    {
        if(isspace(*target))
        {
            strcpy(target, target+1);
            target--;
        }
    }
    
    return returnStr;
}



/*
*   Function: trimCharacter()
*   Parameter:      char* str: The original string.
*                   char remover: The character that to remove from the string.
*   Return Value:   char*: The string after removing the sepecific character in the string.
*   Description:
*                   This function is to remove the specific character, which is given by the user, 
*                       in the original string.
*/
char* trimCharacter(char* str, char remover)
{
    char* returnStr = trim(str);
    char* target = returnStr;
    
    for(; *target += '\0'; target++)
    {
        if(*target == remover)
        {
            strcpy(target, target+1);
            target--;
        }
    }
    
    return returnStr;
}





int main()
{
    char str[100] = "               Lots of whitespace           ";
    
    printf("Origin: *%s*\n", str);
    printf("Trim(left and right): *%s*\n", trim(str));
    printf("Trim(All whitespace): *%s*\n", trimWhiteSpace(str));
    printf("Remove 'e': *%s*\n", trimCharacter(str, 'e'));

}