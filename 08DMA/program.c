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
	iBuffer[5] = 9;
	printInts(iBuffer, iSize + 1);
	//Problem with this is that you may very well get away with this if your program is simple enough, but you never know what's in that memory

	//Once you are done with memory that was allocated on the heap (malloc) you must FREE!!!! the memory
	free(iBuffer);
	iBuffer = NULL; //Not necessary, but good practice. Rob will dock marks if not done. It's like handing the keys back to your apartment landlord
}

int main (void)
{
	setbuf(stdout, NULL);

	TestIntDMA();

	return EXIT_SUCCESS;
}