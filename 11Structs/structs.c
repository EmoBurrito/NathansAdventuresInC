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

/**
 * Ask the user how many students they want to enter.
 * For each student, ask the user for data.
 * Call CreateStudent, and add that pointer to the classroom array of students.
 * Set the number of students.
*/
classroom PopulateClassroom()
{
	classroom c;
	printf("Enter number of students:");
	scanf("%hu", &c.sNumStudents);

	c.sPtrPtr = (student **)malloc(c.sNumStudents*sizeof(student *));


	for (int var = 0; var < c.sNumStudents; ++var)
	{
		c.sPtrPtr[var] = GetStudent();
	}
	return c;
}

student * GetStudent()
{
	char cName [256];
	int iMarks [2];
	int iStudentNum = 0;;

	printf("Enter student name: ");
	fflush(stdin);
	gets(cName);

	printf("Enter student number: ");
	scanf("%d", &iStudentNum);

	printf("Enter two marks: ");
	scanf("%d %d",iMarks, iMarks + 1);

	return CreateStudent(cName, iStudentNum, iMarks, 2);
}

//Display each student in the classroom.
void DisplayClassroom(classroom c)
{
	for (int var = 0; var < c.sNumStudents; ++var)
	{
		DisplayStudent(*c.sPtrPtr[var]);
	}
}