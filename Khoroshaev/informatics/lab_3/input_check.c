#include <stdio.h>
#include "input_check.h"

short getCorrectValOfSize(int* size)
{
	if (getCorrectTypeOfIntegerNumb(size) == -1)
	{
		return -1;
	}

	while ( (*size) <= 0)
	{
		printf("Wrong input, please, try again: ");
		scanf("%*[^\n]");
		getCorrectTypeOfIntegerNumb(size);
	}

	return 1;
}

short getCorrectTypeOfIntegerNumb(int* numb)
{
	short c = scanf("%d", numb);

	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try again: ");
			scanf("%*[^\n]");
			c = scanf("%d", numb);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}

short getCorrectTypeOfDoubleNumb(double* numb)
{
	short c = scanf("%lf", numb);

	while (c != EOF)
	{
		if (c != 1)
		{
			printf("Wrong input, please, try again: ");
			scanf("%*[^n]");
			c = scanf("%lf", numb);
		}
		else
		{
			return 1;
		}
	}

	return -1;
}
