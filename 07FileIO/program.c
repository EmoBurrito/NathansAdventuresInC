/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "fileio.c"  //I seem to need to import .c not .h. What is going on?
//#include "fileio.h"

void TestOpenClose()
{
	int iErr = demoOpenClose("foo.txt", "r"); //If you add a b, it'd be in binary instead of text mode
	printf("The error number returned was %d\n", iErr);
}

void TestRead()
{
	int iErr = demoRead("foo.txt", "r");
	printf("The error number returned was %d\n", iErr);
}

void TestWrite()
{
	int iErr = demoWrite("foobar.txt", "w", "123456789"); //wb wouldn't matter here, because outputting text as bin would still be the same thing
	printf("The error number returned was %d\n", iErr);
}

void TestWriteBinary()
{
	int x = 123456789;
	int iErr = demoWriteBinary("foobin.bin", "wb", &x); //wb for write in binary, & because we're passing in the address? Not sure why...
	printf("The error number returned was %d\n", iErr);
}

void TestExerciseWrite()
{
	exerciseBinaryWrite("exercise.dat", "wb"); //wb may not be correct
}

void TestExerciseRead()
{
	int sin = 0;
	printf("Enter SIN# of person to find: ");
	scanf("%d", &sin);
	exerciseBinaryRead("exercise.dat", "rb", sin);
	//function fseek moves file pointer around, will use to skip 24 bytes if this isn't the sin we're looking for. f
}

int main(void)
{
    //setbuf(stdout, NULL);

    TestExerciseWrite();
    TestExerciseRead();

    return EXIT_SUCCESS;
}
