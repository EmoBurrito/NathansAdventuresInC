#include <stdio.h>
#include "mathfuncs.h"
#include <math.h>

double Average(double data[], int iSize)
{
	int i = 0;
	double sum = 0;

	for (i = 0; i < iSize; ++i)
	{
		sum += data[i];
	}

	return sum / iSize;
}

/**
 * Standard Deviation is how far off the average were most of the people
 * If the class average is 70, but a bunch of people got 40 then StdDev is 30
 */
double StdDev(double data[], int iSize)
{
	double dAvg = Average(data, iSize);
	int i = 0;
	double sum = 0;

	for (i = 0; i < iSize; ++i)
	{
		sum += Square(data[i] - dAvg);
	}

	return sqrt(sum/(iSize - 1));
}

double Square(double dNum)
{
	return dNum * dNum;
}
