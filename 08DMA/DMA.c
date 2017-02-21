#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "DMA.h"
#define DEBUG 1

//Method to print an array of integers
void printInts (int * iBuffer, int iSize)
{
	int i = 0;
	printf("The integers are: \n");
	for(; i < iSize-1; i++) //Because we don't want the last
	{
		printf("%d, ", *(iBuffer++)); //Dereference, print, then increment. Rather crude, but effective
	}
	printf("%d\n", *iBuffer); //Finally print the last
}

/* The following function demonstrates how to use dynamically allocated memory (DMA)
 * Memory allocated dynamically is allocated on the heap. It is yours until you release it back to the system.
 * There is no garbage collection.
 */

//Return an array of integers that are dynamically allocated
int * getInts(int iNumInts)
{
	//Can't declare the array on the stack since the size is not known
	//Even if we know the size, we don't return the address of something on a stack frame (effectively disappears)
	//int ints[iNumInts];

	//Create a memory space for the integers on the heap using a function called malloc
	//Malloc takes the size of memory in bytes as a parameter
	//Malloc returns a void pointer (void *). This is still a pointer, just no associated type. Usually, a cast is required
	int * iBufferPtr = (int *)malloc(sizeof(int) * iNumInts); //This is the equivilent of keyword "new" in Java. Only, you need to figure out how many bytes you need

	for (int var = 0; var < iNumInts; ++var)
	{
		printf("Enter int %d: ", var);
		scanf("%d", iBufferPtr + var); //This is better than incrementing so your pointer stays at the beginning
	}

	return iBufferPtr; //Or was it iBuffer...
}

//Add an int to the end of a dynamic array
/* \brief Takes, an array, increasts its size by one. Asks the user for an int and adds it to the end.
 *
 * \param iArrayPtr The original dynamically allocated array
 * \param iSizePtr Pointer to the original size of the array passed in. Is a pointer because we need to modify it and are returning a reference to the array
 */
int * addInt (int * iArrayPtr, int * iSizePtr) //iSizePtr is different from what we usually do. Be careful nto to iBufferPtr[var] because this dereferences
{
	//Allocate new memory one int larger than the first
	int * iNewArray = (int *)malloc(sizeof(int) * (*iSizePtr + 1));

	if(DEBUG){printf("iSizePtr is %d\n", *iSizePtr);}

	//memcpy(destinationArray, sourceArray, how much to copy) need to Google to copy these over
	memcpy((void *)iNewArray, (void *)iArrayPtr, sizeof(int) * *iSizePtr);

	//Free the original array
	free(iArrayPtr);
	iArrayPtr = NULL;

	//Add new int to end of array
	printf("Enter another integer: ");
	scanf("%d", iNewArray + *iSizePtr); //Don't confuse %i with %d. %i is more powerful in that it will convert hex to decimal and some other stuff. %d would just flip the table

	//Finally, increment the size
	(*iSizePtr)++;

	return iNewArray;
}

//Get a dynamic string
char * getStringDynamic(char * cPrompt)
{
	//Pointer to a dynamically allocated temporary array
	char * cTempPtr = NULL; //If you aren't initializing, initialize to NULL. Otherwise it may point to actual old information

	//Pointer to dynamically allocated array of the exact size required
	char * cReturnPtr = NULL; //These are NOT arrays, just pointers

	//Allocate memory for the temp array
	cTempPtr = (char *)malloc(MAX_STRING_SIZE * sizeof(char)); //Good practice for cross platform in case of double wide. Also makes more readability.

	/*****************************************************************************************************
	 * BIG NOTE - DO NOT FORGET - If memory was allocated (malloc can fail, if it does, it returns NULL) *
	 *****************************************************************************************************/
	if(cTempPtr) //If malloc returned NULL which is 0 and 0 is false
	{
		//Prompt the user for a string
		printf("%s", cPrompt);
		//Scan in a string with spaces potentially
		fgets(cTempPtr, MAX_STRING_SIZE, stdin); //Previously subtracted 1, fgets does this for us apparently. Rob's lung example

		//Allocate a new buffer based on the actual size of the input
		//Always remember to allocated space for the null terminator
		cReturnPtr = (char *)malloc(sizeof(char)*(strlen(cTempPtr)+1)); //Adding one here because strlen does not account for null terminator
		if (cReturnPtr)
		{
			//Copy the data from temp pointer to current pointer
			strcpy(cReturnPtr, cTempPtr); //(Source, Destination). Copies up to and including null terminator. Gee, that's right bloody neato and would have made my assignment a little easier.
		}

		free(cTempPtr);
		cTempPtr = NULL;
	}

	return cReturnPtr;
}

//A function that creates a buffer with a name and SIN
char * getNameAndSin()
{
	//Create buffer
	char * cBuffer = (char *)malloc(sizeof(char)* MAX_NAME_SIZE + sizeof(int) * SIN_SIZE);

	//Ask user for name
	printf("Please enter a name: \n");
	//scanf("%20s", cBuffer); Can't use scanf because it doesn't support spaces.
	fgets(cBuffer, MAX_NAME_SIZE, stdin); //Params are char *, size to read (automatically null terminates after 19), read location
	//cBuffer[strlen(cBuffer - 1)] = '\0'; //Rob did this to counter fgets reading the new line. Worked for Rob but not me, seems to be a running pattern today

	//Read in the SIN
	printf("Please enter an int: \n");
	scanf("%d", (int *)(cBuffer + MAX_NAME_SIZE));

	return cBuffer;
}

//A function to display a name and SIN
void printNameAndSin(char * cBuffer)
{
	//Print the first 20 characters
	printf("%s\n", cBuffer);

	//Print the last 4 bytes as an int
	printf("The SIN is %d\n", *((int *)(cBuffer + MAX_NAME_SIZE))); //Cast to in, then dereference the whole thing
}