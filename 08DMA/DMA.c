#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "DMA.h"

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
int * addInt (int * iArrayPtr, int * iSizePtr) //iSizePtr is different from what we usually do. Be careful nto to iBufferPtr[var] because this dereferences
{

}

//Get a dynamic string
char * getStringDynamic(char * cPrompt)
{

}

//A function that creates a buffer with a name and SIN
char * getNameAndSin()
{

}

//A function to display a name and SIN
void printNameAndSin(char * cBuffer)
{

}