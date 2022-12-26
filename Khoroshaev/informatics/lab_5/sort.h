#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void shekerSort(void* arr, size_t size, size_t sizeOfElem, int(*cmp)(const void*, const void*));
void insertionSortWithBinarySearch(void* arr, size_t size, size_t sizeOfElem, int(*cmp)(const void*, const void*));
void swap(void* a, void* b, size_t size);

#endif
