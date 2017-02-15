/*
 * file.c
 *
 *  Created on: Feb 7, 2017
 *      Author: Nathan Smith, CST235
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> //Allows us to use strlen()
#include "q1.h" //I trust this one more than q2
#include "q3.h"
#define DEBUG 0

/** \brief User passes in a filename to create or append.
 * User enters a phrase from the keyboard which is written to file.
 * User continues until they type in "Quit".
 * Data is Written to a text file.
 *
 * \param char * cFileNamePtr
 * \param 
 * \return int ErrorCode
 */
void writeDataToFile(const char * cFileNamePtr)
{

	FILE * filePtr;
	int iErr = EXIT_SUCCESS;
	char currentLine[1024];
	char iInputBuffer[1048576]; //A full MB of buffer for plain text should be more than enough for one instance of writing

	//I WAS checking for file existing but I guess that's gone now
	if ((filePtr = fopen(cFileNamePtr, "a")) != NULL)
	{
		printf("Begin message (Up to 1023 chars per line). Type 'Quit' to stop.\n");

		do
		{
			fgets(currentLine, 1023, stdin); //Get input
			setbuf(stdin, NULL); //Had to do this on Linux for scanf, not sure if I have to do it with this too.
			if (DEBUG){printf("currentLine is %s.\n", currentLine);}
			if (compareStrings(currentLine, "Quit\n"))
			{
				fwrite((void *)currentLine, sizeof(char), strlen(currentLine), filePtr); //Append the current line to the file
			}
		} while (compareStrings(currentLine, "Quit\n"));

		fclose(filePtr);
	}	
	//My original algorithm was storing all input in a char array before writing the whole thing to file and now I'm a bit booty bothered
}

/** \brief User enters a filename.
 * Program reads one line at a time, printing the line to the console window.
 * Continue until all lines are read.
 * NOTE: The file seems to be written in hex... Mousepad won't read it, Sublime showed me the hex. If I use cat <file>, it displays perfectly
 *
 * \param char * cFileNamePtr
 * \return int ErrorCode
 */
void readDataFromFile(const char * cFileNamePtr)
{
	FILE * filePtr;
	char cBuffer[1024];
	int iErr = 0;

	if ((filePtr = fopen(cFileNamePtr, "r")) != NULL)
	{
		if (DEBUG){printf("%s opened in read mode.\n", cFileNamePtr);}

		//We used fread but that just didn't make sense to me in a "I don't know how long the file is" kind of way...
		while (fgets(cBuffer, 1024, filePtr) != NULL)
		{
			printf("%s", cBuffer);
		}

	}
	else
	{
		//Could not open file
	}
}