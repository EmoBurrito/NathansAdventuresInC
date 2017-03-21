#ifndef FUNCS_H_
#define FUNCS_H_

/**
 * Define a function pointer type.
 * You are specifying the signature of the functions that your pointer will point to.
 * The part in all caps is the function pointer type.
 */

/**
 * A function pointer to a function that returns an int and takes an int
 * Use typedef even though we're only using it once, just for simplicity
 */
typedef int (*FNPTR_TYPE) (int); //On an assignment, use a more meaningful name

//An example of a function that utilizes a function pointer
void iterateNumbers (int iArray[], int iSize, FNPTR_TYPE fn); //Formal argument names not necessary

#endif