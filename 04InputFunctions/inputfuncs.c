#include <stdio.h>
#include <string.h>

//Note the use of the pointer declaration as a parameter
void ReadString(char * cPtr, char  * cLengthPtr); //just by looking at this, don't know if single char or array
void PrintString(char * cPtr);


int main()
{
    /* Test 1 - Basic demo of scanf
     * Create a buffer to enter some data into
     */
    char cArray[5];
    ReadString(cArray, "4"); //4 is stored as string, length 2 because of the null terminator

    return 0;
}

void ReadString(char * cPtr, char * cLengthPtr)
{
    char cFormat[4];
    cFormat[0] = '\0'; //Initialize as an empty string, just to ensure we don't read whatever was there before
    strcat(cFormat, "%"); //Use string concatenation function
    strcat(cFormat, cLengthPtr);
    strcat(cFormat, "s");

    PrintString(cFormat);
}

void PrintString(char * cPtr)
{
    printf("%s\n", cPtr);
}
