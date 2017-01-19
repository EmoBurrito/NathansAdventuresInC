#include <stdio.h>
#include <string.h>

//Note the use of the pointer declaration as a parameter
//Can't overload function names, what ass
void ReadString(char * cPtr, char  * cLengthPtr); //just by looking at this, don't know if single char or array
void PrintString(char * cPtr);
void ReadNumbers(int * iPrt);
void PrintNumbers(int * iPtr, int * iSize);
void ReadStringGets(char * cPtr);
char * ReadStringReturnBuffer();
void FlushDemo();

int main()
{
    char cArray1[5];
    char cArray2[2];
    int iArray [4];
    char cBuffer [256];

    /* Test 1 - Basic demo of scanf
     * Create a buffer to enter some data into
     * Note that this example restricts the input to a set number of characters
     */
    //ReadString(cArray, "4"); //4 is stored as string, length 2 because of the null terminator
    //PrintString(cArray);

    //Test 2 - Enter multiple values
    //scanf("%s %s", cArray1, cArray2);
    //PrintString(cArray1);
    //PrintString(cArray2);

    //Test 3 - Read in an integer
    //int iVal;
    //ReadNumbers(&iVal); //REMEMBER - The & passes in the address of the variable. Otherwise it would pass the value
    //printf("%d\n", iVal);
    //return 0;

    //Test 4 - Read in some integers
    //int iVal;
    //ReadNumbers(iArray); //REMEMBER - The & passes in the address of the variable. Otherwise it would pass the value
    //Note that sizeof returns the size of the item in bytes
    //For arrays, to get the number of elements we divide by sizeof the type
    //int iArrayLength = sizeof(iArray)/sizeof(int);
    //PrintNumbers(iArray, iArrayLength);

    //Test 5 - Using gets()
    //ReadStringGets(cBuffer);
    //PrintString(cBuffer);

    //Test 6 - Returning an array (buffer) - Not a good idea - Segmentation fault??
    // cPtr = ReadStringReturnBuffer();
    //PrintString(cPtr);
    //Rob had to setbuf(stdout, NULL); Eclipse issue, not C
    FlushDemo();

    return 0;
}

void FlushDemo()
{
    int iVal;
    char cArray [50];

    //scanf reads up the newline character, inserted when the user hits the enter key
    //scanf leaves the newline character on the buffer
    printf("Enter a number:\n");
    scanf("%d", &iVal); //scanf needs addresses I guess
    printf("The number is %d\n", iVal);

    //gets is set up to read up to a newline character. Since there is one on the buffer already. Essentially reads nothing
    //To get rid of the newline character, the stdin stream must be flushed
    //fflush(stdin); //Worked for Rob?
    setbuf(stdin, NULL); //This had to work for me, Mitchell agrees
    printf("Enter a string:\n");
    gets(cArray);
    PrintString(cArray);
}

char * ReadStringReturnBuffer()
{
    //When allocating a buffer on the call stack, the address should not be returned.
    //This memory space will eventually be overwritten. The solution is to pass the address of the buffer in as a parameter
    //OR dynamically allocate memory on the heap (We don't know how to do this yet). Primitives return values, arrays return addresses
    char cBuffer [256];
    gets(cBuffer);
    return cBuffer;
}

void ReadString(char * cPtr, char * cLengthPtr)
{
    char cFormat[4];
    cFormat[0] = '\0'; //Initialize as an empty string, just to ensure we don't read whatever was there before
    strcat(cFormat, "%"); //Use string concatenation function
    strcat(cFormat, cLengthPtr);
    strcat(cFormat, "s");

        /*
THIS S IF FOR STRING, THE S IS FOR STRING    :::
                                             :: :::.
                       \/,                    .:::::
           \),          \`-._                 :::888
           /\            \   `-.             ::88888
          /  \            | .(                ::88
         /,.  \           ; ( `              .:8888
            ), \         / ;``               :::888
           /_   \     __/_(_                  :88
             `. ,`..-'      `-._    \  /      :8
               )__ `.           `._ .\/.
              /   `. `             `-._______m         _,
  ,-=====-.-;'                 ,  ___________/ _,-_,'"`/__,-.
 C   =--   ;                   `.`._    V V V       -=-'"#==-._
:,  \     ,|      UuUu _,......__   `-.__A_A_ -. ._ ,--._ ",`` `-
||  |`---' :    uUuUu,'          `'--...____/   `" `".   `
|`  :       \   UuUu:
:  /         \   UuUu`-._
 \(_          `._  uUuUu `-.
 (_3             `._  uUu   `._
                    ``-._      `.
                         `-._    `.
                             `.    \
                               )   ;
                              /   /
               `.        |\ ,'   /
                 ",_A_/\-| `   ,'
                   `--..,_|_,-'\
                          |     \
                          |      \__
          dew             |__
     */

    //PrintString(cFormat);
    //Kinda backwards from printf. Takes the input of a string and PUTS IT INTO cArray
    scanf(cFormat, cPtr); //Arrays are ALWAYS pass by reference, even in Java. By value would be too cumbersome
    //Shit, it also cuts strings off at spaces. We can counter this by reading two things in but then we need two buffers
}

void ReadNumbers(int * iPtr)
{
    printf("Enter an integer number: ");
    /* The following loop runs until it can't read an integer (like entering text)
     * Since iPtr only points to the first element, we keep overwriting it
     */
    //while(scanf("%d", iPtr));

    /////////////////////////////////////////////////////////////////////////////
    //IMPORTANT - We need to use "Point Math" to advance iPtr each time we loop//
    //Note that the pointer moves one integer size, each time you add 1        //
    /////////////////////////////////////////////////////////////////////////////
    while(scanf("%d", iPtr))
    {
        //iPtr = iPtr + 1; //or...
        ++iPtr;
    }
}

void ReadStringGets(char * cPtr)
{
    gets(cPtr);
    //The following is the safe version of gets()
    //gets_s(cPtr, 255) or fgets
}

/* Why is the size of the array passed in?
 * If we do sizeof(iPtr)/sizeof(int), the size of a pointer is always 4!
 * We can't really do size of an array with only a pointer because the pointer is always size 4 (32-bit)
 */
void PrintNumbers(int * iPtr, int * iSize)
{
    for(int i = 0; i < iSize; ++i)
    {
        printf("%d\n", iPtr[i]); //Can still use [] on a pointer. Works the same as arrays
    }
}

void PrintString(char * cPtr)
{
    printf("%s\n", cPtr);
}
