/* Author: Nathan Smith, CST235
 * Date: March 28, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include <malloc.h>

void ReadImage(IMAGE * imgPtr, FILE * infile)
{
	if(imgPtr != NULL * infile != NULL)
	{
		//Read the header first
		ReadHeader(imgPtr, infile);
		//If the header was read in properly
		if(imgPtr->bmHDR != NULL)
		{
			//Read in the data
			ReadData(imgPtr, infile);
		}
	}
}

void ReadHeader(IMAGE * imgPtr, FILE * infile)
{
	BOOL bSuccess = FALSE;
	//Allocate memory for the header
	if((imgPtr_>bmHDR = (BITMAPHDR *)malloc(BMPHDRSIZE)) != NULL) //Kinda weird. Does the malloc, if fails, returns null then evaluates to boolean
	{
		if(fread(imgPtr->bmHDR, BMPHDRSIZE, 1, infile) == 1) //fread is best. First, where you want it, then how many bytes, how many times, source
		{
			bSuccess = TRUE;
		}
	}

	//What happens if we failed to read
	if(!bSuccess && imgPtr->bmHDR != NULL)
	{
		free(imgPtr->bmHdr);
		imgPtr->bmH = NULL;
	}
}

void ReadData(IMAGE * imgPtr, FILE * infile)
{
	BOOL bSuccess = FALSE;

	//The size of the image in bytes
	unsigned int imageSize = 0, padding = 0;
}

void WriteImage(IMAGE * imgPtr, FILE * outfile)
{

}

void WriteHeader(IMAGE * imgPtr, FILE * outfile)
{

}

void WriteData(IMAGE * imgPtr, FILE * outfile)
{

}
