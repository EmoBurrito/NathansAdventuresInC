/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "array_pointers.h"

// This is my attempt to just directly import, doesn't seem to work either. Don't know what's going wrong at this point, honestly
void intArrayPrinter(int[],int);
void charArrayPrinter(char[]);
void intArrayPrinterWithPointers(int * ArrayPtr, int iArraySize); // * splat means the same thing as []. Just means a pointer to such array
void charArrayPrinterWithPointers(char * cArrayPtr);
void intBytePrinter(int iValue);

void TestIntArray()
{
	int iArray[] = {2, 7, 9};

	//Note that the sizeof function returns the size of the array in BYTES, not the size of the array
	//This only works within the scope of where you declared the array.
	int iArraySize = sizeof(iArray)/sizeof(int);
	l(iArray, iArraySize);
	intArrayPrinterWithPointers(iArray, iArraySize);
}

int main(void)
{
    //setbuf(stdout, NULL);

    TestIntArray();

    return EXIT_SUCCESS;
}
