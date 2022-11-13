#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int* a = (int*) malloc(n* sizeof(int));

	if (a == NULL)
	{
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", a+i);
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ( *(a+i) == *(a+j) )
			{
				for (int k = j; k < n-1; k++)
				{
					*(a+k) = *(a+k+1);
				}

				n -= 1;
				j--;
			}
		}
	}
	

	free(a);

	return 0;
}
