#ifndef CAR_H
#define CAR_H

typedef struct Car
{
	char model[17];
	char* fullName;
	double numb;
}
Car;

int carCmpByModel(const Car* p1, const Car* p2);
int rcarCmpByModel(const Car* p1, const Car* p2);
int carCmpByFullName(const Car* p1, const Car* p2);
int rcarCmpByFullName(const Car* p1, const Car* p2);
int carCmpByNumb(const Car* p1, const Car* p2);
int rcarCmpByNumb(const Car* p1, const Car* p2);
void writeCar(const Car* p, FILE* out);

#endif
