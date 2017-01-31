#include <stdio.h>
#include "mathfuncs.h"

int main ()
{
	double data[] = {12, 13.6, 12.4, 10.9, 100};
	double Avg = 0;
	double Std = 0;
	int iSize = sizeof(data)/sizeof(double); //This only works because the declaration is here. Otherwise wouldn't work

	Avg = Average(data, iSize);
	Std = StdDev(data, iSize);
	Display(Avg, Std);
	getchar();

	return 0;
}