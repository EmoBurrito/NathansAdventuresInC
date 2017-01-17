#include <stdio.h>
#include "memory.h" //In the source file, remember to include the associated header file

int MemoryMap(float x)
{
    static int i = 0;
    int a = 1235257896;
    double d = 9.0; //8
    float b = 3.2; //4
    char c = 'a'; //1
    short s = 10815; //2
    char cArray [] = "Hello";

    //Print the address of each local variable
    //The "address of" operator is the &
    printf("The address of int i is \t\t %p\n", &i); //%p is used for printing hexadecimal
    printf("The address of int a is \t\t %p\n", &a);
    printf("The address of double d is \t\t %p\n", &d);
    printf("The address of float b is \t\t %p\n", &b);
    printf("The address of char c is \t\t %p\n", &c);
    printf("The address of short s is \t\t %p\n", &s);
    printf("The address of cArray is \t\t %p\n", cArray); //ROB EXPECTS US TO NOT USE & FOR ARRAYS because Name of the array is an address.

    printf("The address of float x is \t\t %p\n", &x); //Print the address of the parameter

    printf("The address of MemoryMap is \t\t %p\n", &MemoryMap); //Print address of function
}
