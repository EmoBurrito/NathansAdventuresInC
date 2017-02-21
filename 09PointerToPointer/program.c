/* We're not using headers because we get the concept. For speed's sake we're not dealing.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @param cPtrPtr A pointer to a pointer of characters (a string)
 * @param iNumChars The number of chars to trim off the right end
 */
void trimRight(char ** cPtrPtr, int iNumChars)
{
	int iDiff = 0;

	//Create a pointer to the original array
	char * cTempPtr = *cPtrPtr; //Note that we dereference once to get a pointer to the array of chars

	//Difference in length of the old array and the number of chars to remove
	iDiff = strlen(cTempPtr) - iNumChars; //Subtract number of chars user wants to remove

	//Allocate space for the array
	*cPtrPtr = (char *)malloc((iDiff + 1) * sizeof(char));

	//Copy the data from the old string to the new string
	memcpy(*cPtrPtr, cTempPtr, iDiff * sizeof(char));

	//Add the null terminator, the old fashioned way
	*((*cPtrPtr) + iDiff) = '\0';

	//Free the old array
	free(cTempPtr);
	cTempPtr = NULL;
}

void testTrimRight()
{
	char cArray [] = "Robert";
	char * cPtr = (char *) malloc (sizeof(cArray)); //Returns the number of bytes allocated to that array

	strcpy(cPtr, cArray);

	printf("%s\n", cPtr);

	//Trim the right 3 characters
	trimRight(&cPtr, 3);

	printf("%s\n", cPtr);

	free(cPtr);
	cPtr = NULL;
}

/*
 *
 */
void printArray(char ** cPtrPtr, int iRows) //iRows needs to be passed in because it isn't null terminated
{
	for (int i = 0; i < iRows; ++i)
	{
		printf("%s\n", *cPtrPtr[i]);
	}
}

void testPrintArray()
{
	//Build a jagged array to pass in
l
}

int main(void)
{
	setbuf (stdout, NULL);
	//testTrimRight();

	return EXIT_SUCCESS;
}