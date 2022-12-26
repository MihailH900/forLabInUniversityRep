#include <stdio.h>
#include <string.h>
#include "car.h"

int carCmpByModel(const Car* p1, const Car* p2)
{
	return strcmp(p1->model, p2->model);
}

int rcarCmpByModel(const Car* p1, const Car* p2)
{
	return -strcmp(p1->model, p2->model);
}

int carCmpByFullName(const Car* p1, const Car* p2)
{
	return strcmp(p1->fullName, p2->fullName);
}

int rcarCmpByFullName(const Car* p1, const Car* p2)
{
	return -strcmp(p1->fullName, p2->fullName);
}

int carCmpByNumb(const Car* p1, const Car* p2)
{
	return p1->numb > p2->numb;
}

int rcarCmpByNumb(const Car* p1, const Car* p2)
{
	return -(p1->numb > p2->numb);
}

void writeCar(const Car* p, FILE* out)
{
	fprintf(out, "%s\n", p->model);
	fprintf(out, "%s\n", p->fullName);
	fprintf(out, "%lf\n", p->numb);
}
