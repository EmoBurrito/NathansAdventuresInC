/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "array_pointers.c" //Rob's importing .h, mine seems to need to import the .c in order to run. Not sure why the difference

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
	//l(iArray, iArraySize);
	intArrayPrinterWithPointers(iArray, iArraySize);
}

void TestcharArrayPrinterWithPointers()
{
	char myString[] = "xyzzy";
    charArrayPrinterWithPointers(myString);
}

void TestIntBytePointer()
{
	int x = 0x4F324A5A;
	int y = 6451026;
	int z = 0x6874614E;

	intBytePrinter(z);
}

void TestEncodeDecode()
{
	double x = encode();
	decode(x);
}

int main(void)
{
    //setbuf(stdout, NULL); //Not needed for me, Rob did it to counter an Eclipse-ism

    TestIntArray();

    TestcharArrayPrinterWithPointers(); //Proves it can run through the array twice fine, so the pointer it is using is temporary
    TestcharArrayPrinterWithPointers();

    TestIntBytePointer();

    TestEncodeDecode();

    return EXIT_SUCCESS;
}
