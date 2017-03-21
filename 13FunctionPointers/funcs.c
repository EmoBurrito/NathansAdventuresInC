/* Author: Nathan Smith, CST235
 * Date: , '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void iterateNumbers (int iArray[], int iSize, FNPTR_TYPE fn)
{
	for (int i = 0; i < iSize; ++i)
	{
		printf("The value after the function pointer is applied is: %d\n", fn(iArray[i]));
	}
}