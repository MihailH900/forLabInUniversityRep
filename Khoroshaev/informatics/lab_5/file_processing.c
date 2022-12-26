#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_processing.h"

Car* getArr(int* size, const char* in)
{
	FILE* f;
	f = fopen(in, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Can't open file");
		return NULL;
	}

	Car* cars = NULL;
	int c = 0, len = 0;
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);

	while (ftell(f) < len-1)
	{
		char* model = freadline(f);
		char* fullName = freadline(f);
		double numb;
		int res = fscanf(f, "%lf", &numb);

		if (strlen(model) <= 16 && res == 1 && numb >= 0)
		{
			cars = (Car*) realloc(cars, (c+1)*sizeof(Car));
			if (cars == NULL)
			{
				fprintf(stderr, "Memory error");
				return NULL;
			}
			
			strcpy(cars[c].model, model);
			cars[c].fullName = (char*) malloc(strlen(fullName)+1);
			if (cars[c].fullName == NULL)
			{
				fprintf(stderr, "Memory error");
				return NULL;
			}

			strcpy(cars[c].fullName, fullName);
			cars[c].numb = numb;
			c++;
		}
		fseek(f, 1, SEEK_CUR);

		free(model);
		free(fullName);
	}

	*size = c;
	fclose(f);

	return cars;
}

void writeInFile(const Car* cars, int size, const char* outName)
{
	FILE* out = fopen(outName, "a+");
	if (out == NULL)
	{
		fprintf(stderr, "Error while opening file");
		return;
	}

	for (int i = 0; i < size; i++)
	{
		writeCar(cars+i, out);
	}

	fclose(out);
}


char* freadline(FILE* f)
{
	char* ptr = (char*) malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';

	do
	{
		n = fscanf(f, "%80[^\n]", buf);

		if (n < 0)
		{
			free(ptr);
			ptr = NULL;
			continue;
		}
		
		if (n == 0)
		{
			fscanf(f, "%*c");
		}
		else
		{
			len += strlen(buf);

			ptr = (char*) realloc(ptr, len+1);
			if (ptr == NULL)
			{
				return NULL;
			}

			strcat(ptr, buf);
		}

	} while (n > 0);

	return ptr;

}
