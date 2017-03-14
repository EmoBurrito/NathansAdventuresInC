#ifndef STRUCTS_H_
#define STRUCTS_H_
#define NAME_SIZE 5
/* Structs, also known as record, are similar to Classes in Java and C#
 * with the exception that structs do not contain methods (in C).
 * Structs contain attributes (primitives, pointers to dynamically allocated memory, arrays, function pointers, etc.)
 * There is no (automatic) support for inheritance or polymorphism.
 *
 * Structs are generally defined in a header file.
 */

//Basic way to define a struct without a typedef statement
//We dont' really create structs this way
struct BirthDate
{
	//Attributes
	char cName [NAME_SIZE];
	char cGender;
	int day; //Could stick day/month into chars to save space, or even one int
	int month;
	int year;
};

//A typedef statement can be used to simplify the declaration of a struct
//Simple example:
typedef unsigned char BYTE; //Henceforth, I can use "BYTE" all over my code and it will be an unsigned char

//1. Keyword typedef
//2. Define what it is
//3. Lastly, a name
typedef struct
{
	//Attributes
	char cName [NAME_SIZE];
	char cGender;
	int day; //Could stick day/month into chars to save space, or even one int
	int month;
	int year;
} BirthDateTD;

typedef struct
{
	//Some of the attributes are dynamically allocated
	char * cNamePtr;
	int iStudentNum;
	int * iMarksPtr;
	int iMarkCount;
} student;

void DisplayBirthDateBasic(struct BirthDate); //C does not require formal names, but it does require struct in this situation
void DisplayBirthDateTypeDef(BirthDateTD); //C does not require formal names, but it does require struct in this situation
void AlterBirthDate(BirthDateTD);
void AlterBirthDateByRef(BirthDateTD *);
student * CreateStudent(char * cNamePtr, int iStudentNum, int * iMarksPtr, int iMarkCount);
void DisplayStudent(student);
void FreeStudent(student *);

#endif