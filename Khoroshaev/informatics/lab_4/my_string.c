#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

char* readline(char* in)
{
	printf("%s", in);

	char* ptr = (char*) malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	
	do
	{
		n = scanf("%80[^\n]", buf);

		if (n < 0)
		{
			free(ptr);
			ptr = NULL;
			continue;
		}

		if (n == 0)
		{
			scanf("%*c");
		}
		else
		{
			len += strlen(buf);
			ptr = (char*) realloc(ptr, len+1);
			ptr = strcat(ptr, buf);
		}
	}
	while (n > 0);

	return ptr;
}

char* strtok(char* str, const char* delim)
{
	static char* p = NULL;

	char* token;

	if (str == NULL)
	{
		str = p;
	}

	str += strspn(str, delim);
	if (*str == '\0')
	{
		p = str;
		return NULL;
	}

	token = str;
	str = strpbrk(token, delim);
	if (str == NULL)
	{
		p = memchr(token, '\0', strlen(token)+1);
	}
	else
	{
		*str = '\0';
		p = str+1;
	}

	return token;
}

size_t strspn(const char* s1, const char* s2)
{
	const char* p = s1, *help = s2;
	size_t c = 0;

	while (*p != '\0')
	{
		while (*help != '\0')
		{
			if (*p == *help)
			{
				break;
			}
			help++;
		}

		if (*help == '\0')
		{
			return c;
		}
		else
		{
			c++;
		}
		p++;
	}

	return c;
}

char* strpbrk(const char* s1, const char* s2)
{
	while (*s1 != '\0')
	{
		const char* help = s2;
		while (*help != '\0')
		{
			if (*help++ == *s1)
			{
				return (char*) s1;
			}
		}
		s1++;
	}

	return NULL;
}

void* memchr(const void* memptr, int val, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		if (* ( (char*) memptr + i) == val)
		{
			return (char*) memptr+i;
		}
	}

	return NULL;
}

void* memcpy(void* m1, const void* m2, long unsigned int n)
{
	if (m1 == NULL || m2 == NULL)
	{
		return NULL;
	}

	char* help_1 = (char*) m1;
	char* help_2 = (char*) m2;

	while (n--)
	{
		*help_1 = *help_2;
		help_1++;
		help_2++;
	}

	return m1;		
}

unsigned long int strlen(const char* str)
{
	int c = 0;
	
	while ( str[c] != '\0')
	{
		c++;
	}

	return c;
}

char* strcat(char* s1, const char* s2)
{
	char* ptr = s1 + strlen(s1);

	while (*s2 != '\0')
	{
		*ptr++ = *s2++;
	}

	*ptr = '\0';

	return s1;
}
