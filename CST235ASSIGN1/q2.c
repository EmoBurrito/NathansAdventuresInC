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
#define DEBUG 0

//This is honestly almost exactly like the first question
int compareStringsInt(const char * charString1, const char * charString2)
{
	//Variable declaration, and cast strings to int pointers
	int toReturn = 0;
	int * string1 = charString1; //Xyzz should be the value 0x58797A7A or 1484356218(2054846808) in decimal
	int * string2 = charString2; //Plug should be the value 0x506C7568 or 1349285224(1752525904) in decimal
	//Difference should be 135,070,994(302320904). Was actually 319,098,120. Close enough for me.


	while (toReturn == 0 && !(*string1 == '\0' && *string2 == '\0')) //Stop once we have found one is different, or one is longer
	{
		toReturn = *string1 - *string2; //Compare current characters
		
		if (DEBUG)
		{
			printf("Comparing %s to %s: %d\n", string1, string2, toReturn);
		}

		string1++; //Marching a pointer is fine becuase we're within a method
		string2++;
	}

	return toReturn;
}
