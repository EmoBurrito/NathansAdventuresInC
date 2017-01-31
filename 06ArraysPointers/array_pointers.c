#include <stdio.h>
#include <stdlib.h>
#include "array_pointers.h"

void intArrayPrinter(int iArray [],int iArraySize) //Name NOT optional in source, only in header
{
	//Note that the array is passed in as a pointer. If we do sizeof(iArray), it will return the size of the pointer, not the size of the array
	//Print the values of an array
	for (int i = 0; i < iArraySize; ++i)
	{
		printf("The value of loop counter is %d and the array value is %d\n", i, iArray[i]);
	}
}

//Example with formal argument names
void intArrayPrinterWithPointers(int * ArrayPtr, int iArraySize) // * splat means the same thing as []. Just means a pointer to such array
{
	//Print the values in the array
	for (int i = 0; i < iArraySize; ++i)
	{
		/* Note the use of the splat operator to get the value pointed to by the pointer.
		 * This process is called DEREFERENCING
		 */
		//printf("The value at iArrayPtr is %d\n", *(iArrayPtr + i));
		/* Dereferencing comes before addition in Order of Operations. Same as iArray[i] in Java
		 * Infact, this is pointer math. [] is literally just an overloaded operator, we've been doing this for years.
		 * iArrayPtr + i is an example of "Pointer Math" where we add or subtract from the value of pointer
		 * The system looks at the datatype of the pointer and adds the corresponding number of bytes.
		 * In this case, adding 1 to the pionter will add 4 bytes as the pointer is of type int *.
		 * To retrieve a value at an address, we use the dereference operator *.
		 * This is the exact reason why arrays start at 0
		 */

		 //Alternatively, we can "walk the pointer". Note that iArrayPtr no longer points to the start of the array
		 //It now points to the last element of the array
		 printf("The value at iArrayPtr is %d\n", *iArrayPtr++);
	}
}

void charArrayPrinter(char cArray []);
{

}

void charArrayPrinterWithPointers(char * cArrayPtr);
{

}

void intBytePrinter(int iValue);
{

}
