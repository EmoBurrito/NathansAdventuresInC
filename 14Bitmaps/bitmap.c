/*
 * bitmap.c
 *
 *  Created on: Mar 28, 2017
 *      Author: CST235
 */

#include "bitmap.h"
#include <malloc.h>

BOOL ManipulateImage(IMAGE * imgPtr, BM_FUNC_PTR pixelFunc)
{
	BOOL bSuccess = TRUE;
	int i = 0; int j = 0;

	if(imgPtr != NULL && pixelFunc != NULL)
	{
		if(imgPtr->bmHDR != NULL && imgPtr->bmData != NULL)
		{
			//Process each pixel
			for ( i = 0; i < imgPtr->bmHDR->dwHeight; ++i)
			{
				for (j = 0; j < imgPtr->bmHDR->dwWidth; ++j)
				{
					pixelFunc(imgPtr->bmData + i*imgPtr->bmHDR->dwWidth + j);
				}
			}
		}
		else
		{
			bSuccess = FALSE;
		}
	}
	else
	{
		bSuccess = FALSE;
	}

	return bSuccess;
}

FILE * GetFile(char * cPrompt, char * cMode)
{
	FILE * aFile = NULL;
	char cFileName [256];
	printf("%s: \n", cPrompt);
	scanf("%s", cFileName);
	//Open the file with the mode passed in
	aFile = fopen(cFileName, cMode);
	return aFile;
}

void ReadImage (IMAGE * imgPtr, FILE * infile)
{
	if(imgPtr != NULL && infile != NULL)
	{
		//Read the header first
		ReadHeader(imgPtr, infile);
		//If the header was read in
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
	if((imgPtr->bmHDR = (BITMAPHDR *)malloc(BMPHDRSIZE)) != NULL)
	{
		if(fread(imgPtr->bmHDR, BMPHDRSIZE, 1, infile) == 1)
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
	padding = imgPtr->bmHDR->dwWidth%4;

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
		if(imgPtr->bmHDR != NULL)
		{
			free(imgPtr->bmHDR);
			imgPtr->bmHDR = NULL;
		}
		//Free the data if it exists
		if(imgPtr->bmData != NULL)
		{
			free(imgPtr->bmData );
			imgPtr->bmData = NULL;
		}
	}
}

void WriteImage (IMAGE * imgPtr, FILE * outfile)
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
	if (imgPtr->bmHDR != NULL)
	{
		if (fwrite(imgPtr->bmHDR, BMPHDRSIZE, 1, outfile) == 1)
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

	//if the header and data exist in the image
	if (imgPtr->bmHDR != NULL && imgPtr->bmData != NULL)
	{
		//Calculate the image size = # rows * size of a row
		imageSize = (imgPtr->bmHDR->dwWidth*sizeof(PIXEL) + padding) *imgPtr->bmHDR->dwHeight;
		//Write the data to file
		if (fwrite(imgPtr->bmData, imageSize, 1, outfile) == 1)
		{
			bSuccess = TRUE;
		}
	}
	//if we fail
	if (!bSuccess && outfile != NULL)
	{
		fclose(outfile);
		outfile = NULL;
	}
}
