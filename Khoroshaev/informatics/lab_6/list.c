#include <stdio.h>
#include <stdlib.h>
#include "list.h"

short transform(List** list)
{
	if (*list == NULL)
	{
		return 1;
	}

	deleteTabsAndExtraSpaces(list);
	
	Node* help = (*list)->head;
	while (help->ch != '\n')
	{
		Node* t = help;
		int size = 0;
		while (help->ch != ' ' && help->ch != '\n')
		{
			size++;
			help = help->next;
		}
	
		if (size % 2 == 0)
		{
			
			if (help->ch != '\n')
			{
				Node* p = help->next;
				while (t->ch != ' ')
				{
					help->next = (Node*) malloc(sizeof(Node));
					help->next->ch = t->ch;
					t = t->next;
					help = help->next;
				}
				
				help->next = (Node*) malloc(sizeof(Node));
				help->next->ch = ' ';
				help->next->next = p;
				help = help->next;
				help = help->next;
				//printList(*list);
			}
			else
			{
				help->ch = ' ';
				while (t->ch != ' ')
				{
					help->next = (Node*) malloc(sizeof(Node));
					help->next->ch = t->ch;
					t = t->next;
					help = help->next;
				}

				help->next = (Node*) malloc(sizeof(Node));
				help->next->ch = '\n';
				help->next->next = NULL;
			}
		}
		else
		{
			if (help->ch == '\n')
			{
				break;
			}
			help = help->next;
		}
	}	
	return 1;
}

short add(List** list, char ch)
{
	if (*list == NULL)
	{
		*list = (List*) malloc(sizeof(List));
		Node* vert = (Node*) malloc(sizeof(Node));
		if (vert == NULL)
		{
			return -1;
		}

		vert->ch = ch;
		vert->next = NULL;

		(*list)->head = vert;
		(*list)->last = vert;

		return 1;
	}
	else
	{
		Node* vert = (Node*) malloc(sizeof(Node));
		if (vert == NULL)
		{
			return -1;
		}

		vert->ch = ch;
		vert->next = NULL;

		(*list)->last->next = vert;
		(*list)->last = vert;

		return 1;
	}
}

void clearList(List** list)
{
	Node* help = (*list)->head;
	while ( (*list)->head != NULL )
	{
		(*list)->head = (*list)->head->next;
		free(help);
		help = (*list)->head;
	}
	
	(*list)->last = NULL;
	free(*list);
	*list = NULL;
}

void printList(List* list)
{
	Node* help = list->head;
	while (help != NULL)
	{
		printf("%c", help->ch);
		help = help->next;
	}
}

void deleteTabsAndExtraSpaces(List** list)
{
	Node* help = (*list)->head;
	if (help-> ch == '\n')
	{
		return;
	}

	
	while (help->ch == ' ' || help->ch == '\t') 
	{
		(*list)->head = help->next;
		free(help);
		help = (*list)->head;
	}
	
	while (help->ch != '\n')
	{
		while (help->ch != ' ' && help->ch != '\t') 
		{
			help = help->next;
			if (help == NULL)
			{
				return;
			}
		}

		if (help->ch == '\t')
		{
			help->ch = ' ';
		}

		Node* t = help;
		help = help->next;

		while (help->ch == ' ' || help->ch == '\t')
		{
			t->next = help->next;
			free(help);
			help = t->next;
		}
	}
}
