#ifndef ARRAY_POINTERS_H_
#define ARRAY_POINTERS_H_

#define NAME_SIZE 4 //3 plus null terminator
#define AGE 1
#define STUDENT_LOAN 2

//The formal argument is optional
void intArrayPrinter(int[],int);
void charArrayPrinter(char[]);

//Example with formal argument names
void intArrayPrinterWithPointers(int * ArrayPtr, int iArraySize); // * splat means the same thing as []. Just means a pointer to such array
void charArrayPrinterWithPointers(char * cArrayPtr);
void intBytePrinter(int iValue);

#endif // ARRAY_POINTERS_H_
