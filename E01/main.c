/**
 * Author: Nathan Smith
 * Date: Thurs Jan 26, '17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

enum BOOL {false,true}; //enumerations are for short lists of dictionaries, like suits
//They are right neato because they will have values like 0, or 1, or 2, depending on where they are? I think??

void enumerations()
{
	int i = 1;
	enum BOOL done = false;
	do
	{
		printf("%d\n", i);
		i++;
		if(i > 15)
		{
			done = true;
		}
		//printf("%s", done);
		printf("%d", done); //You can't really print true/false as a string. You can print it as a digit of 0 and 1 though
	} while (!done);
}

void enter_name(char * cNamePtr, char * cPrompt)
{
	printf("%s: ",cPrompt); //Will prompt the user for input, given the passed in prompt
	scanf("%9s", cNamePtr); //Ideally, we'd use string concatenation to build the %10s based on the constant at the top, but for the sake of time...
	//Scanf actually only takes 9 because spot 10 is null terminator
	printf("Your name is %s\n", cNamePtr);

	//strlen - reads up to null terminator. Returns the length not counting the null terminator
	printf("The length of your string is %d\n", strlen(cNamePtr));
	printf("The length of overwrittenTerminator is %d\n", strlen("!")); //SCARED.jpg. Use double quotes for string because is expecting array, not single char
	/* I had & here before the variable names, but that's not necessary here.
	 * & means "the address of" but array pointers already ARE pointers of
	 * If you were using a primitive char, it would be necessary
	 */

	test_strcpy(cNamePtr);
	printf("Your string twice is %s\n", strcat(cNamePtr, "xyzzy"));
	test_strcmp(cNamePtr);
	printf("Your string with custom concat is %s", string_cat(cNamePtr, cNamePtr));
	test_string_cat();
}

void test_enter_name()
{
	char name[MAX]; //Did use the const here though :D.
	enter_name(name, "Enter your name");

	/* GENERAL ALGORITHM FOR USING STRINGS, OR REALLY ALL THINGS C
		1. Create a space, either on stack or heap or wherever. Like if you're ordering a couch, they need to know where to dump it
		2. Do the scan (scanf, gets, whatever you want in your miriad of options)
		3. Do something with the data. Print it out
	*/
}

void test_strcpy(char src[])
{
	char dest[MAX];
	dest[0] = '\0'; //Use char here because we're placing something in the exact bucket
	/* Our environment is 0ing out the destination variable for us, but other environments may not.
	 * For this reason, we should slap a null terminator in the beginning spot.
	 * Remember the example about the old tenant that moves out and leaves his all crap behind and food in the fridge?
	 * Java or C# would handle this for us, THIS C environment is, but say Visual Studio's C environment may not.
	 * We do this just to be thorough.
	 */
	strcpy(dest, src);
	printf("Copied %s into destination\n", dest);
}

void test_strcmp(char src[])
{
	src[0] = '\0';
	strcpy(src, "a different string");
	if (strcmp(src, "a different string") == 0) //strcmp returns the difference, so if they are equal it will actually return 0 which C thinks is false
	{
		printf("Equals\n");
	}
	else
	{
		printf("Not equal\n");
	}
}

void string_cat(char * leftPtr, char * rightPtr)
{
	char * appendPtr;
	int i = 0;

	//Use pointer math to find the location of the null terminator in the leftPtr
	appendPtr = leftPtr + strlen(leftPtr);

	//Copy over the characters - Need to make sure we also copy the null terminator
	while(rightPtr[i] != '\0') //While rightPtr is not pointing at a null terminator
	{
		appendPtr[i] = rightPtr[i];
		i++;
	}
	//Append the null terminator to the end of the array
	appendPtr[i] = '\0';

	//Did Rob do this? Where did this come from?
	//leftPtr[0] = '\0'; //It starts at the point of where the null terminator is
	//strcat(leftPtr, rightPtr);
	//strcat(leftPtr, " ");
	//strcat(leftPtr, rightPtr);
	//("Left Pointer is %s\n", leftPtr);

	//My Attempt?
	//leftPtr's null terminator is at it's length (because the array is 0 based
	//rightPtr = ;
	//TODO: This method

	//Start will be the null terminator of leftPtr
	//char * start = strlen(leftPtr) + leftPtr; //IMPORTANT: Add the offset TO THE CURRENT MEMORY ADDRESS
	//start[0] = ;//The beginning of right pointer. You now need to have a "for loop" to iterate through that array
}

void test_string_cat()
{
	char left [] = "Hello";
	char right [] = "World";
	char concat [20];

	concat[0] = '\0';

	string_cat(concat, left);
	string_cat(concat, " ");
	string_cat(concat, right);


	printf("%s\n", concat);
}

int main()
{
	setbuf(stdout, NULL);

	enumerations();
	test_enter_name();

	return 0;
}
