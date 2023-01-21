#include "sort.h"
#include <stdlib.h>
#include <string.h>

void shekerSort(void* arr, size_t size, size_t sizeOfElem, int(*cmp)(const void*, const void*))
{
	long unsigned int left = 0, right = size - 1;
	short c = 1;
	while ((left < right) && c > 0)
	{
		c = 0;
		for (int i = left; i < right; i++)
		{
			if (cmp(arr+i*sizeOfElem, arr+(i+1)*sizeOfElem))
			{
				swap(arr+i*sizeOfElem, arr+(i+1)*sizeOfElem, sizeOfElem);
				c = 1;
			}
		}

		right--;

		for (int i = right; i > left; i--)
		{
			if (cmp(arr+(i-1)*sizeOfElem, arr+i*sizeOfElem))
			{
				swap(arr+(i-1)*sizeOfElem, arr+i*sizeOfElem, sizeOfElem);
				c = 1;
			}
		}

		left++;
	}

}
void insertionSortWithBinarySearch(void* arr, size_t size, size_t sizeOfElem, int(*cmp)(const void*, const void*))
{
	int left, right, s;
	void* x = malloc(sizeOfElem);
	for (int i = 1; i < size; i++)
	{
		if (cmp(arr+(i-1)*sizeOfElem, arr+i*sizeOfElem))
		{
			memmove(x, arr+i*sizeOfElem, sizeOfElem);
			left = 0, right = i-1;
			do
			{
				s = (left+right)/2;
				if (cmp(x, arr+s*sizeOfElem))
				{
					left = s+1;
				}
				else
				{
					right = s-1;
				}
			} while (left <= right);

			for (int j = i-1; j >= left; j--)
			{
				memmove(arr+(j+1)*sizeOfElem, arr+j*sizeOfElem, sizeOfElem);
			}

			memmove(arr+left*sizeOfElem, x, sizeOfElem);
		}
	}

	free(x);
}

void swap(void* a, void* b, size_t size)
{
	char* aCh = (a);
	char* bCh = (b);

	do
	{
		char tmp = *aCh;
		*aCh++ = *bCh;
		*bCh++ = tmp;
	} while (--size > 0);
}
