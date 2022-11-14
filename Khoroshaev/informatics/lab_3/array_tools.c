#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input_check.h"
#include "array_tools.h"

short arrayInitializationOfVal(double** arr, int size, int* capacity, int numb)
{
	*arr = (double*) malloc(size * sizeof(double));

	if (*arr == NULL)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		*( *(arr) + i) = numb;
	}

	*(capacity) = size;

	return 1;
}

short initializeElementInArr(double* arr, int size)
{
	int index;
	printf("Input the index of the position, wich you want to initialize: ");

	short c = getCorrectTypeOfIntegerNumb(&index);

	if (c != 1)
	{
		return -2;
	}

	if (index >= size || index < 0)
	{
		return -1;
	}

	double numb;
	printf("Input initialazation numb: ");

	c = getCorrectTypeOfDoubleNumb(&numb);

	if(c != 1)
	{
		return -2;
	}

	*(arr+index) = numb;

	return 1;
}

short insertElementInArr(double** arr, int* size, int* capacity)
{
	int index;
	printf("Input the index of the position, wich you want to insert: ");
	
	int c = getCorrectTypeOfIntegerNumb(&index);

	if (c != 1)
	{
		return -2;
	}

	if (index > *(size) || index < 0)
	{
		return -1;
	}

	double numb;
	printf("Input inserted value: ");
	
	c = getCorrectTypeOfDoubleNumb(&numb);
	
	if (c != 1)
	{
		return -2;
	}

	c = insert(arr, size, capacity, index, numb);
		
	return c;
}

short eraseElementInArr(double** arr, int* size, int* capacity)
{
	int index;
	printf("Input the index of the element, wich youy want to remove: ");
	
	short c = getCorrectTypeOfIntegerNumb(&index);
	
	if (c != 1)
	{
		return -2;
	}

	if (index >= *(size) || index < 0)
	{
		return -1;
	}
	else
	{
		c = erase(arr, size, capacity, index);
	}

	return c;
}

int transform(double** arr, int* size, int* capacity)
{
	int c = 0;

	for (int i = 0; i < *size; i++)
	{
		double fractPart, intPart;
		fractPart = modf(*( *(arr)+i ), &intPart);

		int equalIntPart = (int)(intPart);
		while (equalIntPart > 0)
		{
			if (equalIntPart % 10 == 9)
			{
				c++;
				int k = erase(arr, size, capacity, i);
				if (k == 0)
				{
					return -1;
				}

				break;
			}
			equalIntPart /= 10;
		}

		while (fractPart - (int)(fractPart) != 0)
		{
			fractPart *= 10;
			if ( fmod(fractPart, 10) == 9)
			{
				c++;
				int k =  erase(arr, size, capacity, i);
				if (k == 0)
				{
					return -1;
				}

				break;
			}
		}
	}

	return c;
}

void printArr(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%lf ", *(arr+i));
	}
}

short insert(double** arr, int* size, int* capacity, int index, int numb)
{
	if ( *(size) == *(capacity))
	{
		double* p = (double*) malloc( *(size)*2 * sizeof(double));

		if (p == NULL)
		{
			return 0;
		}

		for (int i = 0; i < *(size)+1; i++)
		{
			if (i < index)
			{
				*(p+i) = *( *arr+i);
			}
			else if (i == index)
			{
				*(p+i) = numb;
			}
			else
			{
				*(p+i) = *( *(arr)+i-1 );
			}
		}

		free(*arr);
		*(arr) = p;
		p = NULL;

		*(size) += 1;
	}
	else
	{
		for (int i = *(size); i > index; i--)
		{
			*( *(arr)+i ) = *( *(arr)+i-1 );
		}

		*( *(arr)+index ) = numb;
		*(size) += 1;
	}

	return 1;
}


short erase(double** arr, int* size, int* capacity, int index)
{
	if ( *(size)-1 == *(capacity)*2)
	{
		double* p = (double*) malloc( ( (*size) - 1) * sizeof(double) );

		if (p == NULL)
		{
			return 0;
		}

		for (int i = 0; i < *(size) - 1; i++)
		{
			if (i < index)
			{
				*(p+i) = *( *(arr)+i );
			}
			else if (i >= index)
			{
				*(p+i) = *( *(arr)+i+1 );
			}
		}

		free(*arr);
		*(arr) = p;
		p = NULL;

		*(size) /= 2;
		*(capacity) /= 2;
	}
	else
	{
		for (int i = index; i < *(size)-1; i++)
		{
			*( *(arr)+i ) = *( *(arr)+i+1 );
		}

		*(size) -= 1;
	}

	return 1;
}