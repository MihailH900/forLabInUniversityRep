#ifndef ARRAY_TOOLS_H
#define ARRAY_TOOLS_H

short arrayInitializationOfVal(double** arr, int size, int *capacity, int numb);
short initializeElementInArr(double* arr, int size);
short insertElementInArr(double** arr, int* size, int* capacity);
short eraseElementInArr(double** arr, int* size, int* capacity);
int transform(double** arr, int* size, int* capacity);
void printArr(double* arr, int size);
short insert(double** arr, int* size, int* capacity, int index, int numb);
short erase(double** arr, int* size, int* capacity, int index);

#endif /*ARRAY_TOOLS_H*/
