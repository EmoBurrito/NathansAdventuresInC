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
    int x = 12;
    float f = PI;
    double d = 12345.6789;

    //Print the value of the variables
    printf("The value of c is %c\n", c); //Placeholders start with %, called format specifier. %c is one character, coincidence the variable is named that
    printf("The value of x is %d\n", x);
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

//Lazy quick method
void main (void)
{
    printf("Hello world!\n");
    PrimitiveDataTypes();
    return 0;
}
