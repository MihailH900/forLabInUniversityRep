#include <stdio.h>
#include <stdlib.h>
#include "input_check.h"
#include "array_tools.h"

void printMenu();

int main()
{
	printf("Hello. Input size of array: ");
	
	int size, capacity = 0;
	if (-1 == getCorrectValOfSize(&size))
	{
		printf("Shutdown");
		return 0;
	}

	double* arr = NULL;
	short k = arrayInitializationOfVal(&arr, size, &capacity, 0.0);

	if (k != 1)
	{
		printf("Shutdown");
		return 0;
	}

	double* deletedElementsArr = NULL;
	int deletedElementsArrSize = 0, deletedElementsArrCapacity = 0;
	
	printf("\n");
	printf("Now the array is initialized with zeroes\n");
	printf("\n");

	printMenu();

	short c = 0;
	while ( scanf("%hd", &c) == 1 )
	{
		printf("\n");

		if (c == 1)
		{
			short res = initializeElementInArr(arr, size);
			
			if (res == -2)
			{
				printf("\nShutdown\n");
				return 0;
			}
			if (res == 1)
			{
				printf("\nElement initialized\n");
				printf("\n");
			}
			else
			{
				printf("\nThere is no such index\n");
				printf("Input other command\n");
				printf("\n");
			}
		}
		else if (c == 2)
		{
			short res = insertElementInArr(&arr, &size, &capacity);
			
			if (res == -2)
			{
				printf("\nShutdown\n");
				return 0;
			}
			if (res == 1)
			{
				printf("\nElement inserted\n");
				printf("\n");
			}
			else if (res == -1)
			{
				printf("\nBad index, try new command\n");
				printf("\n");
			}
			else
			{
				printf("\nAn error in heap has occurred\n");
				return 0;
			}
		}
		else if (c == 3)
		{
			short res = eraseElementInArr(&arr, &size, &capacity);

			if (res == -2)
			{
				printf("\nShutdown\n");
				return 0;
			}
			if (res == 1)
			{
				printf("\nElement removed\n");
				printf("\n");
			}
			else if (res == -1)
			{
				printf("\nBad index, try new command\n");
				printf("\n");
			}
			else
			{
				printf("\nAn error in heap has occurred\n");
				return 0;
			}
		}
		else if (c == 4)
		{
			int res = transform(&arr, &deletedElementsArr, &size, &capacity, &deletedElementsArrSize, &deletedElementsArrCapacity);
			
			if (res == -1)
			{
				printf("\nAn eroor in heap has occurred\n");
				return 0;
			}
			else
			{
				printf("\nRemoved %d elements\n", res);
				printf("\n");
			}
		}
		else if (c == 5)
		{
			printArr(arr, size);
			printf("\n");
			printf("\n");
		}
		else if (c == 6)
		{
			printArr(deletedElementsArr, deletedElementsArrSize);
			printf("\n");
			printf("\n");
		}
		else
		{
			free(arr);
			free(deletedElementsArr);
			printf("Goodbye");
			return 0;
		}
		
		printMenu();
	}
	
	free(arr);
	free(deletedElementsArr);
	printf("Goodbye");

	return 0;
}

void printMenu()
{
	printf("1: initialaze array element\n");
	printf("2: insert in array\n");
	printf("3: erase array elem\n");
	printf("4: transfom array\n");
	printf("5: print array\n");
	printf("6: print arr where we can see deleted numbs\n");
	printf("other input: exit the program\n");
	printf("\n");
	printf("Input something: ");
}
