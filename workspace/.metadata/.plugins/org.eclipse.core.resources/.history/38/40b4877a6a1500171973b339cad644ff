/* Author: Nathan Smith, CST235
 * Date: March 28, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include <malloc.h>

FILE * GetFile(char * cPrompt, char * cMode)
{
	FILE * aFile = NULL;
	char cFileName [256];
	printf("%s: \n", cPrompt);
	scanf("%s", cFileName);
	//Open the file with the mode passed in
	aFile = fopen(cFileName, cMode);
}

void ReadImage(IMAGE * imgPtr, FILE * infile)
{
	if(imgPtr != NULL && infile != NULL)
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
	if((imgPtr->bmHDR = (BITMAPHDR *)malloc(BMPHDRSIZE)) != NULL) //Kinda weird. Does the malloc, if fails, returns null then evaluates to boolean
	{
		if(fread(imgPtr->bmHDR, BMPHDRSIZE, 1, infile) == 1) //fread is best. First, where you want it, then how many bytes, how many times, source
		{
			bSuccess = TRUE;
		}
	}

	//What happens if we failed to read
	if(!bSuccess && imgPtr->bmHDR != NULL)
	{
		free(imgPtr->bmHDR);
		imgPtr->bmHDR = NULL;
	}
}

void ReadData(IMAGE * imgPtr, FILE * infile)
{
	BOOL bSuccess = FALSE;

	//The size of the image in bytes
	unsigned int imageSize = 0, padding = 0;

	//Calculate the padding
	padding = imgPtr->bmHDR->dwWidth % 4;

	//Calculate the image size (data portion of the image)
	imageSize = (imgPtr->bmHDR->dwWidth*sizeof(PIXEL) + padding) * imgPtr->bmHDR->dwHeight;

	//Allocate memory for pixel data
	if((imgPtr->bmData = (PIXEL *)malloc(imageSize)) != NULL)
	{
		//Read in the pixel array
		if((fread(imgPtr->bmData, imageSize, 1, infile) == 1))
		{
			bSuccess = TRUE;
		}
	}

	//If we failed to read
	if(!bSuccess)
	{
		//Free the header
		if (imgPtr->bmHDR != NULL)
		{
			free(imgPtr->bmHDR);
			imgPtr->bmHDR = NULL;
		}

		//Free the data if it exists
		if(imgPtr->bmData != NULL)
		{
			free(imgPtr->bmData);
			imgPtr->bmData = NULL;
		}
	}
}

void WriteImage(IMAGE * imgPtr, FILE * outfile)
{
	if (imgPtr != NULL && outfile != NULL)
	{
		//Write the header out
		WriteHeader(imgPtr, outfile);
		//Check if header wrote out
		if (outfile != NULL)
		{
			WriteData(imgPtr, outfile);
		}
	}
}

void WriteHeader(IMAGE * imgPtr, FILE * outfile)
{
	BOOL bSuccess = FALSE;
	if(imgPtr->bmHDR != NULL)
	{
		if(fwrite(imgPtr->bmHDR, BMPHDRSIZE, 1, outfile) == 1)
		{
			bSuccess = TRUE;
		}
	}

	//If we failed
	if (!bSuccess && outfile != NULL)
	{
		fclose(outfile);
		outfile = NULL;
	}
}

void WriteData(IMAGE * imgPtr, FILE * outfile)
{
	BOOL bSuccess = FALSE;
	unsigned int imageSize = 0, padding = 0;
	padding = imgPtr->bmHDR->dwWidth % 4;

	//If the header and data exist in the iamge
	if (imgPtr->bmHDR != NULL && imgPtr->bmData != NULL)
	{
		//Calculate the iamge size = # rows * size of row
		imageSize = (imgPtr->bmHDR->dwWidth*sizeof(PIXEL) + padding) * imgPtr->bmHDR->dwHeight;
		//Write the data to file
		if(fwrite(imgPtr->bmData, imageSize, 1, outfile) == 1)
		{
			bSuccess = TRUE;
		}
	}
	//If we fail
	if (!bSuccess && outfile != NULL)
	{
		fclose(outfile);
		outfile = NULL;
	}
}
