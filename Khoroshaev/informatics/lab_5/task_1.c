#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	int sortType, reverse, opt;
	char* field;
	char* in;
	char* out;

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

	if (argc > 9 || argc <= 6)
	{
		fprintf(stderr, "Not enough arguments");
		return 1;
	}
	else
	{
		in = argv[argc - 2];
		out = argv[argc - 1];
	}

	int size = 0;
	Car* cars = getArr(&size, in);

	if (cars == NULL)
	{
		return 0;
	}
	
	int (*cmp)(const Car*, const Car*) = getCmp(field, reverse);
	void (*sort) (void* arr, size_t size, size_t sizeOfElem, int((const void*, const void*))) = getSortType(sortType);

	(*sort)(cars, size, sizeof(Car), *cmp);

	//for (int i = 0; i < size; i++)
	//{
	//	printf("s_%d: %s %s %lf\n", i, (cars+i)->model, (cars+i)->fullName, (cars+i)->numb);
	//}
	writeInFile(cars, size, out);
	
	for (int i = 0; i < size; i++)
	{
		free((cars+i)->fullName);
	}
	free(cars);

	return 0;
}
