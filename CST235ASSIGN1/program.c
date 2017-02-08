/**
 * Author: Nathan Smith
 * Jan 31, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
#include "q2.h"
#include "q3.h"
#define STRING1 Xyzzy
#define STRING2 Plugh

void TestQ1()
{
	printf("The difference between %s and %s is %d", "Xyzzy", "Plugh", compareStrings("Xyzzy", "Plugh"));
}

void TestQ2()
{

}

void TestQ3()
{

}

int main(void)
{
    TestQ1();
	TestQ2();
	TestQ3();

    return EXIT_SUCCESS;
}
