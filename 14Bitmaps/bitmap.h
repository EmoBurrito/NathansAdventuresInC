/*
 * bitmap.h
 *
 *  Created on: Mar 28, 2017
 *      Author: ins222
 */

#ifndef BITMAP_H_
#define BITMAP_H_
#include <stdio.h>


//This image editor is for 24 bit images, no compression, no alpha channel
#define BOOL unsigned char
#define TRUE 1
#define FALSE 0

#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned int
#define BMPHDRSIZE 54

/*
The default byte alignment for structs is 4 bytes in this environment.  We want to change
the alignment to align on 1 byte boundaries.  This way there will be no padding between attributes
and the size of the struct will be exactly 54 bytes, matching the signature of the header in the
BMP file.  The byte alignment can be changed with the "#pragma" pre-processor directive. This applies
to all structs that follow the pragma statement until another pragma is encountered.  Now
we can do a single read from the file to populate all attributes of the BITMAPHDR.
*/




//A struct to represent a 54 byte bmp header
#pragma pack (push) //Use to reset the alignment
#pragma pack(1) //Align on 1 byte boundaries
typedef struct
{
	WORD wType;
	DWORD dwFileSize;
	WORD wReserved1;
	WORD wReserved2;
	DWORD dwDataOffset;
	DWORD dwHeaderSize;
	DWORD dwWidth;
	DWORD dwHeight;
	WORD wPlanes;
	WORD wBitCount;
	DWORD dwCompression;
	DWORD dwImageSize;
	DWORD dwXPelsPerMeter;
	DWORD dwYPelsPerMeter;
	DWORD dwClrUsed;
	DWORD dwClrImportant;
}BITMAPHDR;

//A struct to represent a pixel
typedef struct
{
	BYTE bBlu, bGrn, bRed;
}PIXEL;

//Struct that represents a bitmap image
typedef struct
{
	BITMAPHDR * bmHDR;
	PIXEL * bmData;
}IMAGE;

#pragma pack (pop) //Reset the alignment

//Helper method to open a file
FILE * GetFile(char * cPrompt, char * cMode);

//A function pointer to a function that manipulates a pixel
typedef void (*BM_FUNC_PTR)(PIXEL *);
typedef void (*BM_TWO_PIXELS)(PIXEL *, PIXEL *);
//A function to loop through the array or pixels
BOOL ManipulateImage(IMAGE * imgPtr, BM_FUNC_PTR pixelFunc);
void ManipulateTwoImages(IMAGE * imgPtr1, IMAGE * imgPtr2, BM_TWO_PIXELS pixelsFunc);

//Functions to read in an image
void ReadImage (IMAGE * imgPtr, FILE * infile);
void ReadHeader(IMAGE * imgPtr, FILE * infile);
void ReadData(IMAGE * imgPtr, FILE * infile);

//Functions for writing out an image
void WriteImage (IMAGE * imgPtr, FILE * outfile);
void WriteHeader(IMAGE * imgPtr, FILE * outfile);
void WriteData(IMAGE * imgPtr, FILE * outfile);

#endif /* BITMAP_H_ */
