/*
 * file.c
 *
 *  Created on: Feb 7, 2017
 *      Author: Nathan Smith, CST235
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Needed so we can use access() method
//#include "q2.h" //May not be necessary
#include "q3.h"

/** \brief User passes in a filename to create or append.
 * User enters a phrase from the keyboard which is written to file.
 * User continues until they type in "Quit".
 * Data is Written to a text file.
 *
 * \param char * cFileNamePtr
 * \param 
 * \return int ErrorCode
 */
void writeDataToFile(char * cFileNamePtr)
{
	char fileMode = "w"; //Does not need to be splat, because no chance of binary
	FILE * filePtr;
	int iErr = 0;
	char currentLine[1024];

	//If file already exists, change to append mode
	if (access(cFileNamePtr, W_OK) != -1) //R_OK, W_OK, and X_OK to check for permission. F_OK default. W_OK DOES NOT RELIABLY WORK ON WINDOWS
	{
		fileMode = "a";
	}

	//TODO check folder for write permissions

	printf("Begin message (Up to 1023 chars per line). Type 'Quit' to stop.\n");
	fgets(currentLine, 1023, stdin);
	setbuf(stdin, NULL); //Had to do this on Linux for scanf, not sure if I have to do it with this too.

	if ((filePtr = fopen(cFileNamePtr, fileMode)) != NULL)
	{
		//Probably unneccessary, it just makes more sense in my head to clear a spot on the workbench before sitting down to business
		char * iInputBuffer[1048576]; //A full MB of buffer for plain text should be more than enough for one instance of writing

		do
		{
			//Accept input, no prompt
			fgets(currentLine, 1023, stdin);

			//Append it to the inputBuffer, if it isn't the Quit command
			//Pray to the Pagan gods that the word Quit appearing mid sentance doesn't close the input
			if (compareStringsInt(currentLine, "Quit"))
			{
				strcat(iInputBuffer, currentLine);
				strcat(iInputBuffer, "\n");
			}
			
		}
		while (compareStringsInt(currentLine, "Quit")); //While our current line is not quit

		//Write the beast to file
		fwrite((void*)&iInputBuffer, sizeof(char), 1048576, filePtr); //Will this write blank space making all files a full MB?

		return iErr;
	}
}

/** \brief User enters a filename.
 * Program reads one line at a time, printing the line to the console window.
 * Continue until all lines are read.
 *
 * \param char * cFileNamePtr
 * \return int ErrorCode
 */
void readDataFromFile(char * cFileNamePtr)
{

}