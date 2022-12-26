#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H
#include "car.h"

Car* getArr(int* size, const char* in);
void writeInFile(const Car* cars, int size, const char* outName);
char* freadline(FILE* f);

#endif
