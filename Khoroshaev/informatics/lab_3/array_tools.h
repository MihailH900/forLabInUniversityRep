#ifndef ARRAY_TOOLS_H
#define ARRAY_TOOLS_H

short arrayInitializationOfVal(double** arr, int size, int *capacity, double numb);
short initializeElementInArr(double* arr, int size);
short insertElementInArr(double** arr, int* size, int* capacity);
short eraseElementInArr(double** arr, int* size, int* capacity);
int transform(double** arr, double** deletedElementsArr, int* size, int* capacity, int* deletedElementsArrSize, int* deletedElementsArrCapacity);
short insertInIndexes(int** indexes, int* size, int numb, int* c);
void printArr(double* arr, int size);
short insert(double** arr, int* size, int* capacity, int index, double numb);
short erase(double** arr, int* size, int* capacity, int index);

#endif /*ARRAY_TOOLS_H*/
