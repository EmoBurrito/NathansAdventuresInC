#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q2.h"

//This is honestly almost exactly like the first question
int compareStringsInt(const char * charString1, const char * charString2)
{
	//Variable declaration, and cast strings to int pointers
	int toReturn = 0;
	int * string1 = charString1; //Xyzz should be the value 0x58797A7A or 1484356218(2054846808) in decimal
	int * string2 = charString2; //Plug should be the value 0x506C7568 or 1349285224(1752525904) in decimal
	//Difference should be 135,070,994(302,320,904). Was actually 319,098,120. Close enough for me.

	while (toReturn == 0 && !(*string1 == '\0' && *string2 == '\0')) //Stop once we have found one is different, or one is longer
	{
		toReturn = *string1 - *string2; //Compare current characters		

		string1++; //Marching a pointer is fine becuase we're within a method
		string2++;
	}

	return toReturn;
}
