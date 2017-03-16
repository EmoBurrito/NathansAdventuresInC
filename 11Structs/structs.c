#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "structs.h"

void DisplayBirthDateBasic(struct BirthDate bd)
{
	printf("Name is %s\n", bd.cName);
	printf("Gender is %c\n", bd.cGender);
	printf("Date is %d %d %d\n", bd.day, bd.month, bd.year);
}

void DisplayBirthDateTypeDef(BirthDateTD bd)
{
	printf("Name is %s\n", bd.cName);
	printf("Gender is %c\n", bd.cGender);
	printf("Date is %d %d %d\n", bd.day, bd.month, bd.year);
}

void AlterBirthDate(BirthDateTD bd)
{
	bd.day = 31;
}

void AlterBirthDateByRef(BirthDateTD * bdPtr)
{
	(*bdPtr).day = 31;
}

/**
 * To dynamically allocate a student struct and initialize with the data passed in.
 * @param cNamePtr a pointer to a null terminated string
 * @param iStudentNum an integer containing the studen number
 * @param iMarksPtr a pointer to an array of integers, each int representing a grade
 * @param iMarkCount number of marks in the array of integers
 */
student * CreateStudent(char * cNamePtr, int iStudentNum, int * iMarksPtr, int iMarkCount)
{
	//Allocat memory for the student struct
	student * sPtr = (student *)malloc(sizeof(student));

	//Allocate memory for the name. Need to deep copy.
	sPtr->cNamePtr = (char *)malloc((strlen(cNamePtr)+1)*sizeof(char));
	//Copy the string to the allocated buffer
	strcpy(sPtr->cNamePtr, cNamePtr);

	//Assign the student number. Shallow copy because it's a primitive?
	sPtr->iStudentNum = iStudentNum;

	//Marks array
	sPtr->iMarksPtr = (int *)malloc(iMarkCount*sizeof(int));
	//strcpy is only good for strings, otherwise use memcpy
	memcpy(sPtr->iMarksPtr, iMarksPtr, iMarkCount*sizeof(int));

	//Set the mark count
	sPtr->iMarkCount = iMarkCount;

	return sPtr;
}

//Note student is pass by value, therefore use . operator on s
void DisplayStudent(student s)
{
	printf("Name: %s\n", s.cNamePtr);
	printf("Student number: %d\n", s.iStudentNum);
	printf("Marks: \n");

	for (int i = 0; i < s.iMarkCount; ++i)
	{
		printf("%d ", s.iMarksPtr[i]);
	}
	printf("\n");
}

//Student is pass by reference, use -> operator on sPtr
void FreeStudent(student * sPtr)
{
	free(sPtr->cNamePtr);
	sPtr->cNamePtr = NULL;
	free(sPtr->iMarksPtr);
	sPtr->iMarksPtr = NULL;
	free(sPtr);
	sPtr = NULL;
}

classroom PopulateClassRoom()
{
	unsigned short iNumStudents;
	printf("How many students would you like to enter?:\n");
	scanf("%hu", iNumStudents);

	//Prompt for each student
	for (int i = 0; i < iNumStudents; ++i)
	{
		//Get Name
		char * sName;
		printf("Name:\n");
		fgets();

		//Get student number
		int iStudentNum;
		printf("Student number: \n");
		scanf("%d", iStudentNum);

		marks [] = {};
		student * sPtr = CreateStudent("Rob Miller", 123456789, marks, sizeof(marks)/sizeof(int));
	}

	classroom toReturn();
}

void DisplayClassroom(classroom myClassroom);
{
	//For each student
	for (int i = 0; i < myClassroom->sNumStudents; ++i)
	{
		//Display student
		//DisplayStudent()
	}
}