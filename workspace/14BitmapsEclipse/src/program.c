/*
 * program.c
 *
 *  Created on: Mar 28, 2017
 *      Author: ins222
 */

/*
 Author: ins222
 Date: Mar 28, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"


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


	//Write the image out to file
	WriteImage(&img, outfile);
	fclose(outfile);
}

int main (void)
{
	setbuf(stdout, NULL);

	//printf("Sizeof bitmaphdr %d\n", sizeof(BITMAPHDR));
	TestLoadWriteImage();

	return EXIT_SUCCESS;
}
