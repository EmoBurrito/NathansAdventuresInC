/**
 * Author: Nathan Smith
 * Date: Thurs Jan 26, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

enum BOOL {false,true};



void enumerations()
{
	int i=1;
	//Instance of enumeration.
	enum BOOL done = false;
	do
	{
		printf("%d\n",i);
		i++;
		if(i > 15)
		{
			done = true;
		}

	}while(!done);
}

void enter_name(char * cNamePtr, char * cPrompt)
{
	printf("%s:",cPrompt);
	scanf("%10s", cNamePtr);
	printf("Your name is %s\n", cNamePtr);
	test_strlen(cNamePtr);
	/**
	 * I had & here before the variable names, but that's not necessary here.
	 * & means "the address of" but array pointers already ARE pointers of
	 * If you were using a primitive char, it would be necessary
	 */
	test_strcpy(cNamePtr);
	test_strcat(cNamePtr);
	test_strcmp(cNamePtr);
	printf("Your string with custom concat is %s", string_cat(cNamePtr, cNamePtr));
}

void test_enter_name()
{
	char name[MAX];
	enter_name(name, "Enter your name");
}

void test_strlen(char * myString)
{
	printf("The length of your string is %d\n", strlen(myString));
}

void test_strcpy(char src[])
{
	char dest[MAX];
	strcpy(dest, src);
	printf("Copied %s into destination\n", dest);
}

void test_strcat(char src[])
{
	printf("Your string twice is %s\n", strcat(src,src));
}

void test_strcmp(char src[])
{
	printf("Your string is %d compared to xyzzy", strcmp(src, "xyzzy"));
}

void string_cat(char * leftPtr, char * rightPtr)
{
	//leftPtr's null terminator is at it's length (because the array is 0 based
	rightPtr =

	//Start will be the null terminator of leftPtr
	char * start = strlen(leftPtr) + leftPtr; //IMPORTANT: Add the offset TO THE CURRENT MEMORY ADDRESS
	start[0] = ;//The beginning of right pointer. You now need to have a "for loop" to iterate through that array
}

int main()
{
	setbuf(stdout, NULL);

	enumerations();
	test_enter_name();

	return 0;
}
