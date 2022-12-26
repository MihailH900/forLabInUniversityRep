#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "car.h"
#include "file_processing.h"
#include "sort.h"

int (*getCmp(char* field, int reverse)) (const Car*, const Car*)
{
	if (reverse)
	{
		if (strcmp(field, "fullName") == 0)
		{
			return &rcarCmpByFullName;
		}
		if (strcmp(field, "model") == 0)
		{
			return &rcarCmpByModel;
		}
		if (strcmp(field, "numb") == 0)
		{
			return &rcarCmpByNumb;
		}
	}
	else
	{
		if (strcmp(field, "fullName") == 0)
		{
			return &carCmpByFullName;
		}
		if (strcmp(field, "model") == 0)
		{
			return &carCmpByModel;
		}
		if (strcmp(field, "numb") == 0)
		{
			return &carCmpByNumb;
		}
	}
}

void (*getSortType(int sortType)) (void* arr, size_t size, size_t sizeOfElem, int(cmp(const void*, const void*)))
{
	if (sortType == 1)
	{
		return &shekerSort;
	}
	else if (sortType == 2)
	{
		return &insertionSortWithBinarySearch;
	}
	else
	{
		return &qsort;
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int sortType, reverse, opt;
	char* field;
	
	while ( (opt = getopt(argc, argv, "f:s:r:")) != -1)
	{
		if (opt == 'f')
		{
			field = optarg;
			if (strcmp(field, "model") != 0 && strcmp(field, "fullName") != 0 && strcmp(field, "numb") != 0)
			{
				fprintf(stderr, "Wrong field of sort");
				return 1;
			}
		}
		else if (opt == 's')
		{
			
			sortType = atoi(optarg);
			if(sortType != 1 && sortType != 2 && sortType != 3)
			{
				fprintf(stderr, "There is no such type of sort");
				return 1;
			}
		}
		else if (opt == 'r')
		{
			reverse = atoi(optarg);
			if (reverse != 0 && reverse != 1)
			{
				fprintf(stderr, "There is no such sorting path");
				return 1;
			}
		}
		else
		{
			fprintf(stderr, "Invalid options");
			return 1;
		}
	}

	int numbOfElems, numbOfArrs;
	if (argc > 9 || argc <= 6)
	{
		fprintf(stderr, "Not enough arguments");
		return 1;
	}
	else
	{
		numbOfArrs = atoi(argv[argc - 1]);
		numbOfElems = atoi(argv[argc - 2]);
	}

	printf("KK %d %d\n", numbOfArrs, numbOfElems);

	int (*cmp)(const Car*, const Car*) = getCmp(field, reverse);
	void (*sort) (void* arr, size_t size, size_t sizeOfElem, int((const void*, const void*))) = getSortType(sortType);

	for (int i = 0; i < numbOfArrs; i++)
	{
		Car* cars = (Car*) malloc(numbOfElems*sizeof(Car));
		for (int i = 0; i < numbOfElems; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				*( (cars+i)->model+j) = rand()%92+32;
			}

			(cars+i)->fullName = (char*) malloc(9);
			if ( (cars+i)->fullName == NULL)
			{
				fprintf(stderr, "Memory error");
				return 1;
			}

			for (int j = 0; j < 8; j++)
			{
				*( (cars+i)->fullName + j) = rand()%92+32;
			}
			
			*( (cars+i)->fullName + 8) = '\0';

			(cars+i)->numb = (double) rand() / RAND_MAX * (1000);
		}

		clock_t start = clock();
	
		(*sort)(cars, numbOfElems, sizeof(Car), *cmp);

		clock_t stop = clock();
		double elapsed = (double) (stop-start)*1000.0/CLOCKS_PER_SEC;

		printf("%.10lf\n", elapsed);
			
		for (int i = 0; i < numbOfElems; i++)
		{
			free((cars+i)->fullName);
		}

		free(cars);
		cars = NULL;
	}

	return 0;
}
