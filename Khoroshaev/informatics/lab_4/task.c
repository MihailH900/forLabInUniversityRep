#include <stdio.h>
#include "my_string.h"

int main()
{
	char* str = myReadline();
	
	if (EOF)
	{
		printf("SHUTDOWN");
		return 0;
	}
	printf("%s", str);

	return 0;
}
