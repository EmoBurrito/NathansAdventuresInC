/* Author: Nathan Smith, CST235
 * Date: , '17
 */
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void TestStructDeclarationBasicFormat()
{
	//Does this create a struct or a reference to a struct?
	//This is an instance, created on the stack (no call to malloc)
	struct BirthDate bd1;

	//Try to add a value to a struct member
	//It works!!
	bd1.day = 24;

	//How big is the struct? Anser 20. See notes for reasoning
	printf("The size of the struct in bytes is %lu\n", sizeof(bd1));

	//Instantiate a struct with data
	struct BirthDate bd2 = {"Rob", 'm', 21, 3, 1987};
	DisplayBirthDateBasic(bd2);
	//Change the day
	bd2.day = 15;
	//Change the month using pointer math (crazy way)
	//*(&bd2.day + 1) = 15;
	DisplayBirthDateBasic(bd2);

	//Display bd1 where not all attributes have been set
	DisplayBirthDateBasic(bd1);
}

void TestStructDeclarationTypedef()
{
	BirthDateTD bd = {"Mike", 'm', 21, 3, 1980};

	//Can we do assignment?
	BirthDateTD bd1 = bd;

	//Modfiy bd1
	bd1.day = 10;

	//Display both to see if a copy is made. They are different
	//In other words, a byte by byte copy of the struct is made when doing an assignment
	DisplayBirthDateTypeDef(bd);
	DisplayBirthDateTypeDef(bd1);

	//Are structs pass by value (copy is made) or pass by ref?
	//No change in the dat, so it is pass by value.
	//Ran into this in oChre with the attack method
	AlterBirthDate(bd);
	DisplayBirthDateTypeDef(bd);

	AlterBirthDateByRef(&bd);
	DisplayBirthDateTypeDef(bd);
}

void TestDynamicallyAllocatedStructs()
{
	BirthDateTD * bdPtr = NULL;
	//This fails, no struct allocated
	//(*bdPtr).day = 12;
	bdPtr = (BirthDateTD *)malloc(sizeof(BirthDateTD));
	//Unfortunately, the syntax for accessing attributes with a pointer is horrible
	(*bdPtr).day = 12;
	//There is a shortcut called the arrow operator
	bdPtr->day = 20;
	///////////////////////////////////////////////////////////////////
	//IN ESSENCE, IF IT'S A POINTER, USE ARROW. IF IT'S STACK, USE . //
	///////////////////////////////////////////////////////////////////

	DisplayBirthDateTypeDef(*bdPtr);

	free(bdPtr);
	bdPtr = NULL;
}

void TestStudentStruct()
{
	int marks [] = {89, 92, 96, 100};
	student * sPtr = CreateStudent("Rob Miller", 123456789, marks, sizeof(marks)/sizeof(int));

	DisplayStudent(*sPtr); //Because we aren't changing any values in this method, just pass by value

	FreeStudent(sPtr);
}

int main(void)
{
	TestStudentStruct();

	return EXIT_SUCCESS;
}