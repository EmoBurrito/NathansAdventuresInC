/*
 * program.c
 *
 *  Created on: Feb 7, 2017
 *      Author: Nathan Smith, CST235
 */

#include <stdio.h>
#include <stdlib.h>

//Write a function that takes an unsigned char, swaps its high order nibble with the low order nibbles and then returns the result.
//So, if you pass in a char set of 0x32, it will return a char set of 0x23 
unsigned char swapNibbles(unsigned char c)
{
	return (c << 4) + (c >> 4);
}

//Write a function that takes an integer (8 nibbles) and displays the value of each nibble on a separate line
void displayNibbles(unsigned int iValue)
{
	unsigned int mask = 0xC000; //1100 0000 0000 0000 in binary

	for (int i = 0; i < 8; ++i) //Magic numbers AND system specific... Rob'll have my hide
	{
		printf("%d: %x\n", i, iValue & mask);
		mask = mask >> 2;
	}
}

//Write a function that takes two chars, a and b and combines the data as follows, returning char c
char mashBits(unsigned char a, unsigned char b)
{
	//This is harder to do in plain text... Take the letters out of these, not the puncuation
	//char a = XX!! YY!!
	//char b = !!ZZ ZZ!!
	//return ZZZZ XXYY 
	return (a & 0xC0) + (a & 0x0C) + (b & 0x3C);
}

int main (void)
{
	printf("<Swap Nibbles> Expected: %i. Result: %i\n", 0x23, swapNibbles(0x32));
	printf("<displayNibbles>Uhh...\n");
	displayNibbles(27);
	printf("<Mash Bits> Expected: %i. Result: %i\n", 0xC8, mashBits(0xB3, 0x33));
}