#include <stdio.h>
#include <stdlib.h>
/* General Notes on Bit Operations
 * A bitwise operation operates on one or more bit patterns at the level of their individual bits.
 * It's a fast, primitive action directly supported by the processor,
 * and is used to manipulate values for comparisons and calculations.
 * On simple low-cost processors, typically, bitwise operations are substantially faster for division,
 * several times faster for multiplication and sometimes significantly faster for addition.
 * While modern processors perform addition and multiplication just as fast as bit operations,
 * bitwise operations do commonly use less power because of the reduced resources.
 * Source: http://en.wikipedia.org/wiki/bitwise_operation
 */

/* The reason we're multiplying by 2 is...
	1 in binary is 0001, 2 is 0010, 4 is 0100. It's just shifting the bit over
 */
void showBits(int value, int bytes)
{
	int filter = 1;
	int bit;

	char * bits = (char *)malloc(33); //33 is for null terminator
	for (bit = 0; bit < bytes * 8; bit++)
	{
		if (value & filter)
		{
			bits[31 - bit] = '1';
		}
		else
		{
			bits[31 - bit] = '0';
		}
		filter *= 2;
	}
	//Put in the null terminator
	bits[32] = 0;
	printf("The value %d in binary is %s\n", value, &bits[32 - bytes * 8]);
	free(bits);
}

//Bitwise AND (&) (Not to be confused with Logical AND (&&))
//If both bits in the compared position are 1,
//the bit in the resulting binary representation is 1.
//Otherwise, the result is 0.
//This method goes with the board example of bitADDing 0x48 and 0xB8, where we first convert them to binary and AND them toghether

//Suppose we wanted to turn third byte off. Just apply the filter mask of 110 to it. 1's will preserve the original value in that bit, 0 will turn it off
//EXAMPLE 101 & 110 = 100. Remember turning off execute?
void bitAND()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a & b;
	printf("Bitwise AND of a and b is %x\n", result);
	showBits(result, sizeof(char));
}

//Bitwise OR (|)
//The result in each position is 1 if the first bit is 1 OR the second bit is 1 or both bits are 1.
//Else, the result is 0
void bitOR()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a | b;
	printf("Bitwise OR of a and b is %x\n", result);
	showBits(result, sizeof(char));
}

//Bitwise "exclusive OR" XOR (^)
//The result in each position is 1 if only the first bit is 1 OR only the second bit is 1 (One or the other, not both)
//Will be 0 if both operands are 0 or both 1.
void bitXOR()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a ^ b;
	printf("Bitwise OR of a and b is %x\n", result);
	showBits(result, sizeof(char));
}

//Bitwise NOT (~) flips the bits
void inversion()
{
	unsigned char a = 0x48;
	unsigned char result = ~a;
	printf("Bitwise inversion of a %x\n", result);
	showBits(result, sizeof(char));
}

//Bitshift operators: << and >>
//No comparison is made, bits are simply moved left or right
//Will be used extensively in bitmap
//Shifting right n positions is equivalent dividing by 2^n
//Shifting lefn n positions is equivalent to multiplying by 2^n
//Some situations, this can actually be more efficient than actually multiplying by 32 or whatever you need
void shiftOperators()
{
	short x = 37;
	int z = 1;
	char y = -128;
	char value = 0xD3;
	char mask = 0x0f;
	char result;

	//Display x in binary
	//printf("No shift in x\n");
	//showBits(x, sizeof(short));

	//Note that bit shifting to the left is the same as multiplying by a power of 2
	//printf("Shift x 1 bit to the left");
	//showBits(x << 1, sizeof(short));

	//Note that bit shifting to the right is the same as dividing by a power of 2
	//printf("Shift x 1 bit to the right");
	//showBits(x >> 1, sizeof(short));
	//Notice how the result of 37/2 was 18. This is because the last bit was pushed off the end.
	//This is why integer division always truncates

	//Note that the right hand side is padded with 0's
	// printf("Shift z 30 bits to the left\n");
	// showBits(z << 30, sizeof(int));

	//Note that the right shift of 1 resulted in padding of 1's, not 0's
	//This is because it pads with whatever the sign bit is set to
	//90% of the time, you don't want this to happen. Typically counter by using unsigned variables.
	//printf("Shift z 31 bits to the left and then 1 bit to the right\n");
	//showBits(z << 31 >> 1, sizeof(int));

	//printf("Shift y left by 1\n");
	//showBits(y << 1, sizeof(char)); //Just because y is a char, doesn't mean << returns a char. It actually returns an int.

	//printf("shift y right by 1\n");
	//showBits(y >> 1, sizeof(char));

	//Masking demo
	printf("Value\n");
	showBits(value, sizeof(char));

	printf("Mask\n");
	showBits(mask, sizeof(char));

	//The lower nibble of value is 
	showBits(value & mask, sizeof(char));

	//The upper nibble of value
	showBits((value >> 4) & mask , sizeof(char));
	//Rob sais you can technically shift 4 left then shift 4 back right but that's doubling the processes. Don't do this on assignments.
}

int main (void)
{
	setbuf(stdout, NULL);

	//bitAND();
	//bitOR();
	//bitXOR();
	//inversion();
	shiftOperators();

	return EXIT_SUCCESS;
}