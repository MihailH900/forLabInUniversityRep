#include <stdio.h>
#include <stdlib.h>

int getArray(int** a, int* len);

int main()
{
	int len = 0;
	int* a = NULL;

	if (getArray(&a, &len) == -1)
	{
		printf("Memory error");
		return 0;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", ( *(a+i) ) );
	}

	return 0;
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
			(*a) = (int*)realloc( (*a), pos+1);

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
				(*a) = (int*)realloc( (*a), (*len + 1) * sizeof(int));

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

