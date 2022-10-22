#include <stdio.h>
#include <math.h>
#include "general_functions.h"

int getParams(double* x, double* cosArg, double* precision);
double getFuncWithSeries(double x, double cosArg, double precision, int* i);

int main()
{
	double x, cosArg, precision;

	if (1 != getParams(&x, &cosArg, &precision))
	{
		printf("shutdown");
		return 0;
	}

	int i = 0;
	double res = getFuncWithSeries(x, cosArg, precision, &i);

	printf("Etalon is: %lf\nValue with your precision: %lf\nNumber of series members: %d", log(1 - 2*x*cos(cosArg) + x*x), res, i);

	return 0;
}

int getParams(double* x, double* cosArg, double* precision)
{
	if (getCorrectValOfX(x) == -1)
	{
		return -1;
	}

	if (getCorrectValOfCosArg(cosArg) == -1)
	{
		return -1;
	}
	
	if (getCorrectValOfPrecision(precision) == -1)
	{
		return -1;
	}

	return 1;
}

double getFuncWithSeries(double x, double cosArg, double precision, int* i)
{	
	double resNumberBeforeC = 0, resNumberC = cos(cosArg)*x*(-2), t = x;
	double res = cos(cosArg)*x;

	(*i) = 2;

	if (dAbs(resNumberC-resNumberBeforeC) <= precision)
	{
		(*i) = 1;
		return resNumberC;
	}

	while (dAbs(resNumberC-resNumberBeforeC) > precision)
	{
		t *= x;
		res += ( t  * cos( (*i) * cosArg)) / (*i);
		
		(*i) += 1;
		resNumberBeforeC = resNumberC;
		resNumberC = res*(-2);
	}

	return resNumberBeforeC;
}
