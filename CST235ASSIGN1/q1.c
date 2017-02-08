#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

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
	do
	{
		toReturn = *string1 - *string2;
	}
	while (toReturn == 0); //Stop once we have found one is different

	return toReturn; //Return the value
}
