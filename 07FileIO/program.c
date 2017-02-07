/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
//#include "fileio.h"  //I seem to need to import .c not .h. What is going on?
#include "fileio.h"

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
	int iErr = demoWrite("foobar.txt", "w", "Blah blah blah");
	printf("The error number returned was %d\n", iErr);
}

int main(void)
{
    //setbuf(stdout, NULL);

    TestWrite();

    return EXIT_SUCCESS;
}
