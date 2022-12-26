#include <stdio.h>
#include "list.h"

int main()
{
	char ch;
	List* list = NULL;
	while ( (ch = getchar()) != EOF)
	{
		while (ch != '\n')
		{
			add(&list, ch);
			ch = getchar();
		}

		add(&list, ch);
		printList(list);
		transform(&list);
		printList(list);
		clearList(&list);
	}
}
