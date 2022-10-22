#include "general_functions.h"
#include <stdio.h>

short getCorrectValOfX(double* x)
{
	printf("Input x (an argument of function): ");

	if (getCorrectTypeOfX(x) == -1)
	{
		return -1;
	}

	while ( !(dAbs(*x) <= 1) )
	{
		printf("Wrong val of x, please, try again: ");
		getchar();
		getCorrectTypeOfX(x);
	}

	return 1;
}

short getCorrectValOfCosArg(double* cosArg)
{
	printf("Input alpha (an argument of cos, in radians): ");

	return getCorrectTypeOfCosArg(cosArg);
}

short getCorrectValOfN(int* n)
{
	printf("Input n (members of the series): ");

	if (getCorrectTypeOfN(n) == -1)
	{
		return -1;
	}

	while ( (*n) <= 0)
	{
		printf("Wrong input, please, try again: ");
		getchar();
		getCorrectTypeOfN(n);
	}

	return 1;
}

short getCorrectValOfPrecision(double* precision)
{
	printf("Input precision: ");

	return getCorrectTypeOfPrecision(precision);
}

short getCorrectTypeOfX(double* x)
{
	short c = scanf("%lf", x);
	
	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try again: ");
			getchar();
			c = scanf("%lf", x);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}

short getCorrectTypeOfCosArg(double* cosArg)
{
	short c = scanf("%lf", cosArg);
	
	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try again: ");
			getchar();
			c = scanf("%lf", cosArg);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}

short getCorrectTypeOfPrecision(double* precision)
{
	short c = scanf("%lf", precision);

	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try again: ");
			getchar();
			c = scanf("%lf", precision);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}

short getCorrectTypeOfN(int* n)
{
	short c = scanf("%d", n);

	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try afain: ");
			getchar();
			c = scanf("%d", n);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}

double dAbs(double d)
{
	if (d >= (double)(0) )
	{
		return d;
	}

	return (d * -1);
}
