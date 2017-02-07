#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileio.h"



/* Study errno.h on Wikipedia before proceeding
 * Essentially there is a global variable called errno that gets set to indicate an error See also strerror function to get a message associated with this value
 */
int demoOpenClose(const char * fileName , const char * fileMode)
{
	//Pointer to a file stream
	FILE * filePtr;
	//A variable to store potential error codes
	int iErr = EXIT_SUCCESS;

	/* Use fopen to open a file. Note that it returns a file pointer that must be assigned
	 * If it fails, it returns a NULL and sets the errno variable to indicate an error
	 * Parameters are a const char * indicating a path/file
	 * The second is a const char * indicating the mode (read, write, append, etc.) See document on handout drive for various modes
	 */
	if ((filePtr = fopen(fileName, fileMode)) != NULL) //fopen will either return NULL or a file pointer, then check if filePtr is not null
	{
		//Close the file when done, otherwise it'll be locked by process. Most modern OS's will probably catch this but it's good habit
		fclose(filePtr);
		printf("%s was successfully opened and closed.\n", fileName);
	}
	else
	{
		iErr = errno;
		//strerror returns a string associated with the error number
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
	char cBuffer[MAXSIZE];

	//All read operations read data from the file to the memory location indicate (cBuffer). Won't go through all, may be necessary to Google others later
	//Only fgets adds an additional null terminator to the data in the buffer
	//fscanf (file scanf)/fread - number of times assigned/read, fscanf returns EOF if a failure occurs before the first assignment
	//fgets - returns a pointer to the string read or NULL
	//fgetc - returns the character read or EOF
	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//How to initialize a buffer
		memset(cBuffer, '\0', MAXSIZE);


		//retVal = fscanf(filePtr, "%s\n", cBuffer); //Reads a string up to the first space. \n is to ensure it only reads until the end of the line
		retVal = fgets(cBuffer, MAXSIZE, filePtr); //Can replace filePtr with stdio to read from keyboard, but with safety feature of "please only read this many bytes"
		//retVal = fread(cBuffer, sizeof(char), 8, filePtr); //Buffer to read into, type you want to read, the number you want to read, where you're reading from. retVal is number of characters returned

		if (retVal > 0)
		{
			printf("%s\n", cBuffer);
		}
		else
		{
			//ferror returns 0 if no error was set on this stream. Otherwise, non-zero value indicating an error
			if(iErr = ferror(filePtr))
			{
				printf("Error reading from file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not retrieve the data");
			}
		}
	}
	else
	{
		//strerror returns a string assco
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
	char cBuffer[MAXSIZE];

	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//fwrite
		//fprintf
		//fputs
		//fputc
		retVal = fwrite((void *)str, sizeof(char), strlen(str), filePtr); //void pointer can point to anything, system just doesn't care about the type. Can't do pointer math
		if (retVal > 0)
		{
			printf("File written: %s\n", fileName);
		}
		else
		{
			if(iErr = ferror(filePtr))
			{
				printf("Error writing to file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not retrieve the data");
			}
		}
	}
	else
	{
		//strerror returns a string associated with the error number
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

/*
int demoWriteBinary(const char *, const char *, const int *)
{

}
*/
