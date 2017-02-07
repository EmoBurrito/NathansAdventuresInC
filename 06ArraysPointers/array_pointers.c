#include <stdio.h>
#include <stdlib.h>
#include "array_pointers.h"

/* A function that returns a double
 * The first 4 bytes of the double contains a 3 letter null terminated string
 * The next single byte contains the age
 * The next two bytes contain the student loan
 */
double encode()
{
	//Create space to put information
	double x = 0;
	char * cNamePtr = (char *)&x; //Point to location of x. Casting as char so when we do pointer math, it'll move by byte

	printf("Enter a 3 letter name: ");
	scanf("%3s", cNamePtr); //Restrict to 3 characters, will actually put value in to x WHERE cNamePtr is

	printf("Enter your age: ");
	scanf("%d", (int *)(cNamePtr + NAME_SIZE)); //Brackets are important, because otherwise it'll convert cNamePtr then add 4 to that. Otherwise PointerMath will be done incorrectly

	printf("Enter your student loan: ");
	scanf("%hu", (short *)(cNamePtr + NAME_SIZE + AGE)); //%hu for unsigned pointer, casting to a short because only want two bytes

	return x;
}

double decode(double x)
{
	//Set a pointer to the start of the buffer
	char * cNamePtr = (char *)&x;
	short * loanPtr = (short *)(cNamePtr + NAME_SIZE + AGE);

	printf("The name is %s\n", cNamePtr); //Print the name as a string
	printf("The age is %d\n", *(cNamePtr + NAME_SIZE)); //Need to dereference it. If you had an int pointer, it'd print 4 bytes. We only want 1 so we're using a char pointer
	printf("The student loan is %hu\n", *loanPtr); //Print the student loan
}

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
void intArrayPrinterWithPointers(int * iArrayPtr, int iArraySize) // * splat means the same thing as []. Just means a pointer to such array
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
		 //The problem with this is... Well now your pointer is moved so if you need to go through again, you're kinda up a creek
		 printf("The value at iArrayPtr is %d and the value of iArrayPtr is %x\n", *iArrayPtr++, iArrayPtr);
	}
}

void charArrayPrinter(char cArray [])
{

}

void charArrayPrinterWithPointers(char * cArrayPtr)
{
	//Don't forget * is for dereference (get value at). Rob just put while(*cArrayPtr) because null terminator's value is 0, which C knows as false
	while (*cArrayPtr != '\0')
	{
		printf("%c\n", *cArrayPtr);
		++cArrayPtr;
	}
}

//Print each byte of an integer as a character
void intBytePrinter(int iValue)
{
	int iSize = sizeof(iValue);
	/* Create a pointer to the integer passed in.
	 * However, an int * will not work. If we do pointer math, it will go up 4 bytes at a time minimum
	 * Therefor, we will use a char * as it moves up by 1 byte at a time
	 */
	char * cPtr = (char *)&iValue; //Casting to a char, to tell the compiler that yes we do know what we are doing and not to warn us.

	for (int i = 0; i < iSize; ++i)
	{
		printf("%c", *(cPtr + i)); //Need to dereference so you don't print the memory address
	}
}

/*
double Encode()
{
	char name [4]; //3 char's plus null terminator
	char age;
	char loan [3]; //2 digits for loan, plus null term, total of 8 chars
	double toReturn;
	char * cReturnPtr = &toReturn; //A pointer to take us to the beginning of the double

	printf("Enter the first three letters of your name:\n");
	scanf("%s", name);
	setbuf(stdin, NULL); //Used to flush?
	printf("Enter your age:\n");
	scanf("%c", &age);
	setbuf(stdin, NULL); //Only worked once?
	printf("Enter your loan (two digits):\n");
	scanf("%s", loan);
	setbuf(stdin, NULL);

	//Iterate through variables to construct the double

	toReturn[0] = name[0];
	toReturn[1] = name[1];
	toReturn[2] = name[2];
	toReturn[3] = '\0';
	toReturn[4] = age;
	toReturn[5] = loan[0];
	toReturn[6] = loan[1];


	for (int i = 0; i < 3; ++i) //Copy the first three characters
	{
		*cReturnPtr = name[i];
	}

	//cReturnPtr should now be at [3]
	*cReturnPtr = '\0'; ++cReturnPtr;

	return toReturn;
}
*/
