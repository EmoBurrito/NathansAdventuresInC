/*
 * file.c
 *
 *  Created on: Feb 7, 2017
 *      Author: Nathan Smith, CST235
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //https://www.tutorialspoint.com/c_standard_library/string_h.htm
#include "q2.h"
#define DEBUG 1

//This is honestly almost exactly like the first question
int compareStringsInt(const char * charString1, const char * charString2)
{
	//Variable declaration, and cast strings to int pointers
	int toReturn = 0;
	int * string1 = charString1;
	int * string2 = charString2;

	while (toReturn == 0) 
	{
		if (*string1 == '\0' && *string2 == '\0')
		{
			return toReturn; 
		}

		toReturn = *string1 - *string2; 
		
		if (DEBUG)
		{
			printf("Comparing %c to %c: %d\n", *string1, *string2, toReturn);
		}

		string1++; 
		string2++;
	}

	return toReturn; 
}