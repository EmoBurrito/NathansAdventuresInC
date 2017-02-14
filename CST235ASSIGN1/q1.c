#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
#define DEBUG 1

/*
 *
 */
int compareStrings(char * string1, char * string2)
{
	int toReturn = 0; //The number to store the comparison

	/* By subtracting the second character's value from the first
	 * we will get 0 if they are the same character.
	 * If the character string1 is pointing to is less, then toReturn will be negative.
	 * Else, it will be positive
	 */
	while (toReturn == 0) //Stop once we have found one is different, or one is longer
	{
		if (*string1 == '\0' && *string2 == '\0')
		{
			return toReturn; //If we haven't found a difference yet and both are null terminated, they match.
		}
		toReturn = *string1 - *string2;
		if (DEBUG)
		{
			printf("Comparing %c to %c: %d\n", *string1, *string2, toReturn);
		}

		string1++; //Marching a pointer is fine becuase we're within a method
		string2++;
	}

	return toReturn; //Return the value
}
