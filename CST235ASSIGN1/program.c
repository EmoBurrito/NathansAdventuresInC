/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
#include "q2.h"
#include "q3.h"
#define STRING1 "Xyzzy"
#define STRING2 "Plugh"
#define STRING_LONG "XyzzyLonger"
#define STRING_SPACE "Xyzzy Plugh"
#define FILE_NAME "myA1File.txt"

void TestQ1()
{
	printf("The difference between %s and %s is %d\n", STRING1, STRING1, compareStrings(STRING1, STRING1));
	printf("The difference between %s and %s is %d\n", STRING1, STRING2, compareStrings(STRING1, STRING2));
	printf("The difference between %s and %s is %d\n", STRING1, STRING_LONG, compareStrings(STRING1, STRING_LONG));
	printf("The difference between %s and %s is %d\n", STRING2, STRING1, compareStrings(STRING2, STRING1));
	printf("The difference between %s and %s is %d\n", STRING2, STRING_SPACE, compareStrings(STRING2, STRING_SPACE));
}

//If this were C#, I'd probably use a function pointer to make this a little more efficient
void TestQ2()
{
	printf("The difference between %s and %s is %d\n", STRING1, STRING1, compareStringsInt(STRING1, STRING1));
	printf("The difference between %s and %s is %d\n", STRING1, STRING2, compareStringsInt(STRING1, STRING2));
	printf("The difference between %s and %s is %d\n", STRING1, STRING_LONG, compareStringsInt(STRING1, STRING_LONG));
	printf("The difference between %s and %s is %d\n", STRING2, STRING1, compareStringsInt(STRING2, STRING1));
	printf("The difference between %s and %s is %d\n", STRING2, STRING_SPACE, compareStringsInt(STRING2, STRING_SPACE));
}

void TestQ3()
{
	writeDataToFile(FILE_NAME);
	readDataFromFile(FILE_NAME);
}

int main(void)
{
    //TestQ1();
	//TestQ2();
	TestQ3();

    return EXIT_SUCCESS;
}
