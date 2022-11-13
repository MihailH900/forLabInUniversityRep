#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int* a, int* indexes, int L, int R);
int getArray(int** a, int* len);
int getValOfUniqueElements(int* a, int len);
void printArr(int* a, int len);
void swap(int* a, int* b);

int main()
{
	int len = 0;
	int* a = NULL;
	int* indexes = NULL;

	if (getArray(&a, &len) == -1)
	{
		printf("Memory error");
		return 0;
	}

	printArr(a, len);

	printf("\n");

	clock_t start = clock();

	indexes = (int*) malloc(len * sizeof(int));
	if (indexes == NULL)
	{
		printf("Memory error");
		return 0;
	}

	for (int i = 0; i < len; i++)
	{
		*(indexes+i) = i;
	}

	quickSort(a, indexes, 0, len);

	int countUnique = getValOfUniqueElements(a, len);

	int* ans = (int*) malloc(countUnique * sizeof(int));
	if (ans == NULL)
	{
		printf("Memory Error");
		return 0;
	}

	int* ansIndexes = (int*) malloc(countUnique * sizeof(int));
	if (ansIndexes == NULL)
	{
		printf("Memory Error");
		return 0;
	}

	int c = 0;
	for (int i = 0; i < len; i++)
	{

		if (i+1 < len)
		{
			if ( *(a+i) == *(a+i+1) )
			{
				while (i+1 < len && *(a+i) == *(a+i+1) )
				{
					i++;
				}
				*(ans+c) = *(a+i);
				*(ansIndexes+c) = *(indexes+i);
				c++;
			}
			else
			{
				*(ans+c) = *(a+i);
				*(ansIndexes+c) = *(indexes+i);
				c++;
			}
		}
		else
		{
			*(ans+c) = *(a+i);
			*(ansIndexes+c) = *(indexes+i);
			c++;
		}
	}

	quickSort(ansIndexes, ans, 0, countUnique);

	clock_t stop = clock();
	double elapsed = (double) (stop-start)*1000.0/CLOCKS_PER_SEC;

	printArr(ans, countUnique);

	free(a);
	free(indexes);
	free(ans);
	free(ansIndexes);

	return 0;
}

void quickSort(int* a, int* indexes, int L, int R)
{
	srand( time(NULL) );

	if (R - L <= 1)
	{
		return;
	}

	int mid = *(a + L + rand() % (R-L));
	int x = L, y = L;
	
	for (int i = L; i < R; i++)
	{
		if ( *(a+i) < mid)
		{
			swap( &(*(a+x)), &(*(a+i)) );
			swap( &(*(indexes+x)), &(*(indexes+i)) );
			if (x != y)
			{
				swap( &(*(a+y)), &(*(a+i)) );
				swap( &(*(indexes+y)), &(*(indexes+i)) );
			}
			
			x++, y++;
		}
		else if ( *(a+i) == mid)
		{
			swap( &(*(a+y)), &(*(a+i)) );
			swap( &(*(indexes+y)), &(*(indexes+i)) );

			y++;
		}
	}

	quickSort(a, indexes, L, x);
	quickSort(a, indexes, y, R);
}

int getArray(int** a, int* len)
{
	int pos, num;
	printf("Enter position of array(pos) and numb: ");
	scanf("%d%d", &pos, &num);

	while (num != 0)
	{
		if (pos >= (*len) )
		{
			(*a) = (int*) realloc( (*a), (pos+1) * sizeof(int) );

			if ( (*a) == NULL)
			{
				return -1;
			}

			for (int i = (*len); i < pos; i++)
			{
				( *( (*a) + i) ) = 0;
			}
			
			( *( (*a) + pos) ) = num;
			(*len) = pos+1;
		}
		else
		{
			if ( *( (*a) + pos) == 0 )
			{
				( *( (*a) + pos) ) = num;
			}
			else
			{
				(*a) = (int*) realloc( (*a), (*len + 1) * sizeof(int) );

				if ( (*a) == NULL)
				{
					return -1;
				}

				(*len) = (*len) + 1;
				
				for (int i = (*len)-1; i > pos; i--)
				{
					( *( (*a) + i) ) = ( *( (*a) + i - 1) );
				}

				( *( (*a) + pos) ) = num;
			}
		}
		
		printf("Enter position of array(pos) and numb: ");
		scanf("%d%d", &pos, &num);

	}

	return 1;
}

int getValOfUniqueElements(int* a, int len)
{
	int ans = 0;

	for (int i = 0; i < len; i++)
	{
		if (i+1 < len)
		{
			if ( *(a+i) == *(a+i+1) )
			{
				while (i+1 < len && *(a+i) == *(a+i+1) )
				{
					i++;
				}
				ans++;
			}
			else
			{
				ans++;
			}
		}
		else
		{
			ans++;
		}
	}

	return ans;
}

void printArr(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(a+i));
	}
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
