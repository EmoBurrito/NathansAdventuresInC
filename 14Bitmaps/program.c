/*
 * program.c
 *
 *  Created on: Mar 28, 2017
 *      Author: CST235
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

void GreyScale(PIXEL * p)
{
	BYTE Grey = 0;
	Grey = (BYTE)((0.11*p->bBlu + 0.59*p->bGrn + 0.3*p->bRed));
	p->bBlu = Grey;
	p->bGrn = Grey;
	p->bRed = Grey;
}

void TestLoadWriteImage()
{
	FILE * infile = GetFile("Enter file to open ", "rb");
	FILE * outfile = GetFile("Enter output file name ", "w+b");

	//Create an image struct with both of its pointers set to NULL
	IMAGE img = {NULL, NULL};

	//Read in an image
	ReadImage(&img, infile);
	//Close the file
	fclose(infile);

	ManipulateImage(&img, GreyScale);

	//Write the image out to file
	WriteImage(&img, outfile);
	fclose(outfile);
}

int main (void)
{
	//setbuf(stdout, NULL);

	//printf("Sizeof bitmaphdr %d\n", sizeof(BITMAPHDR));
	TestLoadWriteImage();

	return EXIT_SUCCESS;
}
