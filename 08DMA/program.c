#include <stdio.h>
#include <stdlib.h>
#include "DMA.h"
#include <malloc.h>

void TestIntDMA()
{
	int iSize = 5;
	int* iBuffer = getInts(iSize);
	printInts(iBuffer, iSize);

	/* Demo a buffer overflow.
	 * C "allows" us to overflow the buffer, creating potential errors and security vulnerabilities
	 * "Allows" in quotes, because it's like a car without a seatbelt "allows" us to fly through the windshield
	 * It is up to the programmer to ensure that you never go beyond the bounds of the buffer.
	 */
	// iBuffer[5] = 9;
	// printInts(iBuffer, iSize + 1);
	//Problem with this is that you may very well get away with this if your program is simple enough, but you never know what's in that memory

	//Add an integer to the buffer
	iBuffer = addInt(iBuffer, &iSize);
	printInts(iBuffer, iSize);

	//Once you are done with memory that was allocated on the heap (malloc) you must FREE!!!! the memory
	free(iBuffer);
	iBuffer = NULL; //Not necessary, but good practice. Rob will dock marks if not done. It's like handing the keys back to your apartment landlord
}

void TestDynamicString()
{
	char * cFirstPtr = getStringDynamic("Enter first name: ");
	char * cLastPtr = getStringDynamic("Enter last name: ");

	//Read in names
	// cFirstPtr = getStringDynamic("Enter first name: ");
	// cLastPtr = getStringDynamic("Enter last name");

	//If this comes back with any address at all, that'll be true
	if (cFirstPtr)
	{
		printf("The first name is %s\n", cFirstPtr);
		free(cFirstPtr);
		cFirstPtr = NULL;
	}
	if (cLastPtr)
	{
		printf("The last name is %s\n", cLastPtr);
		free(cLastPtr);
		cLastPtr = NULL;
	}
}

void testSIN()
{
	printNameAndSin(getNameAndSin());
}

int main (void)
{
	setbuf(stdout, NULL);

	testSIN();

	return EXIT_SUCCESS;
}