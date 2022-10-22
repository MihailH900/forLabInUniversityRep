#include <stdio.h>
#include <math.h>
#include "general_functions.h"

double getFuncWithSeries(double x, double cosArg, int n);
short getParams(double* x, double* cosArg, int* n);

int main()
{
	double x, cosArg;
	int n;

	if (1 != getParams(&x, &cosArg, &n))
	{
		printf("shutdown");
		return 0;
	}

	printf("%.15lf\n%.15lf", log(1 - 2*x*cos(cosArg)+x*x), getFuncWithSeries(x, cosArg, n));

	return 0;
}

double getFuncWithSeries(double x, double cosArg, int n)
{
	double res = 0;
	double t = 1;

	for (int i = 1; i <= n; i++)
	{
		t *= x;

		res += (t*cos(i*cosArg))/i;
	}

	return res*(-2);
}

short getParams(double* x, double* cosArg, int* n)
{
	if (getCorrectValOfX(x) == -1)
	{
		return -1;
	}

	if (getCorrectValOfCosArg(cosArg) == -1)
	{
		return -1;
	}

	if (getCorrectValOfN(n) == -1)
	{
		return -1;
	}

	return 1;
}
