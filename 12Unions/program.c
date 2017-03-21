/* Author: Nathan Smith, CST235
 * Date: March 21, '17
 * Not bothering with headers for speed sake.
 */
#include <stdio.h>
#include <stdlib.h>

/* A union is a datatype that is similar in syntax to a struct.
 * A union can have several attributes, however, only one is assigned at a time.
 * The memory reserved by a union is equal to that of its largest member.
 * 
 * Example, suppose we want to store how much fertilizer a farmer purchased.
 * Fertilizer is sold in various units.
 * The following union could be used to store the amount purchased.
 */

typedef union
{
	unsigned char truckloads;
	unsigned int bags;
	double tons;
} FertilizerQuantity;

typedef struct
{
	unsigned char r; /**< Red */
	unsigned char g; /**< Green */
	unsigned char b; /**< Blue */
	unsigned char t; /**< Transparency */
} Pixel;

typedef union
{
	unsigned int iVal;
	Pixel components;
} ColorVal;

void TestColourConversion()
{
	ColorVal c;
	c.iVal = 0x2A3Bff1C; 

	printf("The whole colour as a hex val is %x\n", c.iVal);
	printf("The red component is %x\n", c.components.r);
	printf("The green component is %x\n", c.components.g);
	printf("The blue component is %x\n", c.components.b);
	printf("The transparency component is %x\n", c.components.t);
}

void TestVertilizerUnion()
{
	//Create an instance of a union
	FertilizerQuantity fq;

	//How big is the union
	printf("The size of an instance of FertilizerQuantity is %lu\n", sizeof(fq));

	//Assign truckloads
	fq.truckloads = 3.0;
	//Assign to bags. Note that truckloads will be overwritten
	fq.bags = 400;
	//Overwrite bags
	fq.tons = 12345.78965;

	printf("The value of truckloads is %d\n", fq.truckloads);
	printf("The value of bags is %d\n", fq.bags);
	printf("The value of tons is %f\n", fq.tons);
	printf("The address of truckloads is %p\n", &fq.truckloads);
	printf("The address of bags is %p\n", &fq.bags);
	printf("The address of tons is %p\n", &fq.tons);
}

int main(void)
{
	//TestVertilizerUnion();
	TestColourConversion();
}