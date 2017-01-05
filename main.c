#include <stdio.h>
/**Similar to "Using" statements in C# or "Import" in Java
Tells the pre-processor that there is some existing code that we want to utilize in this code
Note that the <> tell the pre-processor where to look in the built in standard libraries.
We will use "" instead of <> to tell the pre-processor to look in the local project first.

Note that the pre-processor reads this file, looking for pre-processor directives (starts with #)
In this case, the #include tells the pre-processor to find stdio.h and substitute its text into this file

Another type of pre-processor directive is the "define"
**/
#define PI 3.14159
#define Radius 2
/**Note that the define statement does not end with a semi-colon, or use equals**/

void PrimitiveDataTypes()
{
    char c = 'R';
    c = 130;
    int x = 123456;
    float f = PI;
    double d = 12345.6789;

    //Print the value of the variables
    printf("The value of c is %c\n", c); //Placeholders start with %, called format specifier. %c is one character, coincidence the variable is named that
    printf("The value of x is %d\n", x);
    printf("The value of x as a character is %c\n", x);
    printf("Again with i: %i\n", x);
    printf("The value of f is %f\n", f);
    //Can use format specifiers to modify output. For example, to display 10 digits total, with only two decimals:
    printf("The value of d is %10.2f\n", d); //Still prints type f, 10 digits maximum, 2 of which are decimal

    //What are the sizes of each datatype?
    //The sizeof() function is used to return the size of a datatype or a structure or an array etc.
    //You can put a variable with that type, or hell you can just put the datatype itself
    printf("The size of a char is %d\n", sizeof(c));
    printf("The size of a char is %d\n", sizeof(int));
    printf("The size of a char is %d\n", sizeof(f));
    printf("The size of a char is %d\n", sizeof(d));
}

/**Typical main method:
Return type indicates success or failure of the application to the OS.
Parameters: argc --> is the number of command line parameters passed in.
            argv --> an array of arrays (2D Array)
int main (int argc, char *argv[] )
**/

//Modifiers to the primitive data types
void Modifiers()
{
    //Note that C defaults to signed values
    //Unsigned means positive values only. To do this, use keyword unsigned
    //Char is used for a lot of number storage in C because it's a single byte. EX:
    unsigned char e = 255;
    e = e + 1;
    printf("e is %d", e);

    //Inversely, signed can have negatives but only -128 through +127
    //This is because the first bit is your sign. 0 for positive, 1 for negative
    //Note
}








//Modifiers to the primitive data types
void Modifiers ()
{
	//Note that C defaults to signed values
    //Unsigned means positive values only. To do this, use keyword unsigned
    //Char is used for a lot of number storage in C because it's a single byte. EX:
	unsigned char e = 255;
	signed char c = 127;

	//"short" and "long"
	short int x;
	short y; //Note that this defaults to short int if a primitive is not specified.
	long int z;
	//long float f; Can't do this!!!! No long floats.

	//Add one to e and c
	e = e + 1;
	c += 1;

	printf("The value of e is %d\n", e);
	printf("The value of c is %d\n", c);


	//Print out the size of short and long primitives
	printf("The size of x is %d\n", sizeof(x)); //A short is 2 bytes on this system.
	printf("The size of z is %d\n", sizeof(z)); //A long is 4 bytes
	//printf("The size of f is %d\n", sizeof(f));
}


void DemoConstants()
{
	//Note the keyword const
	const float pi = 3.14159;
	//pi = pi + 1;  //Can't do!
	printf("The value of pi is %f\n", pi);
}


void CastDemo()
{
	int x;
	float y = 3.2f;
	float fahr = 0;
	float celc = 0;


	//Assign y to x, potential loss of data
	//Cast is better to indicate that you know what you are doing.
	x = (int)y;

	printf("The value of x is %d\n",x);
}

//Lazy quick method
void main (void)
{
    printf("Hello world!\n");
    PrimitiveDataTypes();
    return 0;
}
