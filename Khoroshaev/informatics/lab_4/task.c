#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 3

#if FLAG
	#include "my_string.h"
#else
	#include <string.h>
	#include <readline/readline.h>
#endif

char* transform(char* str, char** ptr);
int getAnsSize(const char* str, int size);
void addWord(char* ans, char* word, int c);

int main()
{
	char* str = readline("Input string that starts with a character other than a space: ");

	while (str != NULL)
	{
		char* ptr = NULL;
		clock_t start = clock();
		char* ans = transform(str, &ptr);
		clock_t stop = clock();
		double elapsed = (double) (stop-start)*1000.0/CLOCKS_PER_SEC;

		if (ans == NULL)
		{
			printf("Memory error\n");
			return 0;
		}

		printf("'%s'\n Time - %lf\n", ans, elapsed);
		free(ans);
		free(str);
		ans = NULL;
		str = NULL;
		str = readline("input string that starts with a character other than a space: ");
	}

	printf("SHUTDOWN");

	return 0;
}

char* transform(char* str)
{
	if (strlen(str) == 0)
	{
		char* ans = (char*) malloc(1);
		ans[0] = '\0';
		return ans;
	}

	int strSize = strlen(str);
	int ansSize = getAnsSize(str, strSize);

	char* ans = (char*) malloc(ansSize+1);
	char* copyStr = (char*) calloc(strSize+1, sizeof(char));

	if (ans == NULL)
	{
		return NULL;
	}

	memcpy(copyStr, str, strSize+1);
	ans[0] = '\0';

	int c = 0;
	
	char* word = strtok(str, " \t");
	c++;
	
	addWord(ans, word, c);

	while (word != NULL)
	{
		word = strtok(NULL, " \t");
		if (word == NULL)
		{
			free(copyStr);
			return ans;
		}
		c++;
		
		if (c % N == 0 && c % M != 0)
		{
			continue;
		}

		strcat(ans, " ");
		addWord(ans, word, c);
	}

	free(copyStr);
	return ans;
}

int getAnsSize(const char* str, int size)
{
	int ansSize = 0, c = 0;

	for (int i = 0; i < size; i++)
	{
		while (i < size && (str[i] == ' ' || str[i] == '\t') )
		{
			i++;
		}

		int k = 0;
		while (i < size && str[i] != ' ' && str[i] != '\t')
		{
			k++;
			i++;
		}

		c++;
		if ( (c % N == 0 && c % M == 0) || (c % N != 0 && c % M != 0) )
		{
			ansSize += k + 1;
		}

		if (c % N != 0 && c % M == 0)
		{ 
			ansSize += k*2 + 2;
		}

		if (c % N == 0 && c % M != 0)
		{
			while (i < size && (str[i] == ' ' || str[i] == '\t') )
			{
				i++;
			}
		}
		
		i--;
	}	
	
	ansSize--;
	return ansSize;
}

void addWord(char* ans, char* word, int c)
{
	if ( (c % N == 0 && c % M == 0) || (c % N != 0 && c % M != 0) )
	{
		strcat(ans, word);
	}

	if (c % N != 0 && c % M == 0)
	{
		strcat(ans, word);
		strcat(ans, " ");
		strcat(ans, word);
	}
}
