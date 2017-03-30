/* Author: Nathan Smith, CST235
 * Date: March 28, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

void TestLoadImage()
{
	FILE * infile = GetFile("Enter file to open", "rb");

	//Create an image struct with both of its pointers set to NULL. Fine because fixed size.
	IMAGE img = {NULL, NULL};

	//Read in an image
	ReadImage(&img, infile);

	//Close the file
	fclose(infile);
}

int main(void)
{
	//printf("Size of Bitmap header: %lu\n", sizeof(BITMAPHDR));

	TestLoadImage();

	return EXIT_SUCCESS;
}