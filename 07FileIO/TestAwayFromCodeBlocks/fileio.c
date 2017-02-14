/*
 * fileio.c
 *
 *  Created on: Feb 7, 2017
 *      Author: ins222
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileio.h"

#define NAME_SIZE 20

//Study errno.h on wikipedia before proceeding.
//Essentially, there is a global variable called errno that gets set to indicate an error.  See also, strerror function to get a message
//associated with this value.
int demoOpenClose(const char * fileName , const char * fileMode)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;

	//Use fopen to open a file.  Note that it returns a FILE pointer that must be assigned.
	//If it fails, it returns a NULL and sets the errno variable to indicate an error.
	//Parameters are a const char * indicating a path/file
	//The second is a const char * indicating the mode (read, write , append. etc).  See document on handout for various modes.
	if((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//Close the file when done.
		fclose(filePtr);
		printf("%s was successfully opened and closed.\n", fileName);
	}
	else
	{
		iErr = errno;
		//strerror returns a string associated with he error number.
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}


	return iErr;
}

int demoRead(const char * fileName, const char * fileMode)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;
	//Create two integers on one line
	int intChar, retVal;
	char cBuffer [MAXSIZE];





	//All read operations read data from the file to the memory location indicate (cBuffer).
	//Only fgets adds an additional null terminator to the data in the buffer
	//Return types vary so testing for success depends on the function used
	//fscanf/fread - return number of times assigned/read, fscanf returns EOF if a failure occurs before first assignment
	//fgets - returns a pointer to the string read or NULL.
	//fgetc - returns the character read or EOF
	if((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//How to initialize a buffer
		memset(cBuffer, '\0', MAXSIZE);


		//retVal = fscanf(filePtr, "%s\n", cBuffer); //Reads a string up to the first space.
		retVal = fgets(cBuffer, MAXSIZE, filePtr);

		//retVal = fread(cBuffer, sizeof(char), 8, filePtr);
		if(retVal > 0)
		{
			printf("%s\n", cBuffer);
		}
		else
		{
			//ferror returns 0 if no error was set on this stream.  Otherwise, non-zero value indicating an error
			if(iErr = ferror(filePtr))
			{
				printf("Error reading from the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not retrieve the data");
			}
		}
	}
	else
	{

		//strerror returns a string associated with he error number.
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

int demoWrite(const char * fileName, const char * fileMode, const char * str)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;
	//Create two integers on one line
	int intChar, retVal;


	if((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//fwrite
		//fprintf
		//fputs
		//fputc
		retVal = fwrite((void *)str, sizeof(char), strlen(str), filePtr);
		if(retVal > 0)
		{
			printf("File written: %s\n", fileName);

		}
		else
		{
			if(iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data");
			}
		}


	}
	else
	{

		//strerror returns a string associated with he error number.
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

int demoWriteBinary(const char * fileName, const char * fileMode, const int * iPtr)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;
	int retVal;


	if((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		retVal = fwrite((void *)iPtr, sizeof(int), 1, filePtr); //Using 1 because we know we're writing 4 bytes(sizeofint) once
		if(retVal > 0)
		{
			printf("File written: %s\n", fileName);

		}
		else
		{
			if(iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data");
			}
		}


	}
	else
	{

		//strerror returns a string associated with he error number.
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

/* First figure out what write/read types we need
 */
int exerciseBinaryWriteMine(const char* fileName, const char * fileMode)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;
	int retVal;
	unsigned short records;

	//Prompt for how many records to print
	printf("How many records do you want to input?(0 - 65535): \n");
	scanf("%hu", &records); //hu for unsigned short. Can't remember why & is needed

	char strToFile[10000]; //Greatly memory inefficient but whatever. Rob says we'll do dynamic memory allocation later


	//Store # of records in the first two bytes of the file
	* strToFile = (char *) &records;
	printf("DEBUG: %s\n", strToFile);

	//Repeat a fixed number of times
	for(int i = 0; i < records; ++i)
	{
		unsigned int currentSIN;
		char currentName[20];

		//Store a SIN (int)
		printf("Please enter a SIN:\n");
		scanf("%du", &currentSIN);
		//Store a full name (up to 20 char including null term), (char[20])
		printf("Please enter a name:\n");
		scanf("%19s", &currentName);
	}

	//Finally, write the whole thing to file
	if((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		retVal = fwrite((void *)strToFile, sizeof(int), 1, filePtr); //Using 1 because we know we're writing 4 bytes(sizeofint) once
		if(retVal > 0)
		{
			printf("File written: %s\n", fileName);

		}
		else
		{
			if(iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data");
			}
		}


	}
	else
	{

		//strerror returns a string associated with he error number.
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;

}

/* Pass in SIN. Read until ID is found, or reach end of file.
 * If found, print the following name.
 * If not, print "Not found."
 */
int exerciseBinaryReadMine(const char * filename, const char * fileMode, int id)
{
	//If this is the sin we want, read the next 20 bytes for name. If not, fseek 24 bytes ahead
	//for(int i = 0; i < WRITE_LOOPS; ++i)
	//{

	//}
}

int exerciseBinaryWrite(const char * fileName, const char * fileMode)
{
	FILE * filePtr;
	int iErr = 0;
	int iSin, retSin, retName;
	char cNameArray [MAX_NAME_SIZE];
	short sNumRecords = NUM_RECORDS;

	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
        //Write out the number of records
        fwrite((void *)&sNumRecords, sizeof(short), 1, filePtr); //Not sure why we need the & here when I want to write the value...

        //Loop for number of records
        for (int var = 0; var < NUM_RECORDS; ++var)
        {
        	printf("Enter a SIN number: ");
        	scanf("%d", &iSin); //& gets the address


			//Get rid of new line left behind from scanf. Not sure if only an Ecplisism
			fflush(stdin);
			setbuf(stdin, NULL);

			printf("Enter name: ");
			fgets(cNameArray, MAX_NAME_SIZE - 1, stdin); //Second param is how many characters to read in -1 for terminator, last is file to read from. We're just gonna pass stdin

			retSin = fwrite((void*)&iSin, sizeof(int), 1, filePtr); //We're just writing out one. If we pass in array of 3, we'd just say 3
			retName = fwrite((void*)cNameArray, MAX_NAME_SIZE, 1, filePtr); //Not using & here because this is already a pointer

			//These values will be the number that it wrote. If its 0's then something went wrong
			if (retSin == 0 || retName == 0)
			{
				if (iErr = ferror(filePtr))
				{
					printf("Error writing the file %s: %s\n", fileName, strerror(iErr));
				}
				else
				{
					printf("Could not write data.\n");
				}
			}
        }
		//Make sure to close the file
		fclose(filePtr); //Rob's got an extra closing brace, I may be missing one
	}
	else
	{
		printf("Error accessing file\n");
	}
	return iErr;
}

int exerciseBinaryRead(const char * fileName, const char * fileMode, int id)
{
	FILE * filePtr;
	int iErr = 0;
	int iSin, retSin, retName;
	char cNameArray [MAX_NAME_SIZE];
	short sNumRecords = NUM_RECORDS;
	int found = 0;

	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//Read in the number of records
		fread(&sNumRecords, sizeof(short), 1, filePtr);

		for (int var = 0; var < sNumRecords && !found; ++var) //0 is false, anything else is true
		{
			//Read in the SIN#
			fread(&iSin, sizeof(int), 1, filePtr);
			if (iSin == id)
			{
				found = fread(cNameArray, MAX_NAME_SIZE, 1, filePtr);
				printf("The name is %s\n", cNameArray);
			}
			else
			{
				//Jump ahead to the next SIN#
				fseek(filePtr, MAX_NAME_SIZE, SEEK_CUR); //Move 20 bytes from current position. Other options are SEEK_SET for start, SEEK_END with negative for end
			}
		}

		if (!found)
		{
			printf("SIN not found.\n");
		}
		fclose(filePtr);
	}
	else
	{
		printf("Error accessing file.\n");
	}
}
