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

student * CreateStudent(char * cNamePtr, int iStudentNum, int * iMarksPtr, int iMarkCount)
{

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