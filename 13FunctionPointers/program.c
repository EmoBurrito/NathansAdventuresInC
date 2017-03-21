/* Author: Nathan Smith, CST235
 * Date: March 21, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int doNothing(int i)
{
	return i;
}

int doSquare(int i)
{
	return i*i;
}

//Do we NEED to match signature?
//No, it will compile and run. Doesn't mean you'll get desired results.
//YOU need to make sure that there are no errors in converting one data type to the next if your signature does not match.
//In general, using functions that do not match signatures with the function pointer is not a good idea.
int dontMatchSignature(short x)
{
	return(int)x;
}

int main(void)
{
	int iArray [] = {45, 56, 35000};
	//Note that we pass a function into iterate number as the last parameter
	//The name of the function stores the address of the function
	iterateNumbers(iArray, sizeof(iArray)/sizeof(int), dontMatchSignature);

	return EXIT_SUCCESS;
}