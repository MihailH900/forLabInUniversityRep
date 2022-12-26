#ifndef LIST_H
#define LIST_H

typedef struct Node
{
	char ch;
	struct Node* next;
} Node;

typedef struct List
{
	Node* head;
	Node* last;
} List;

short transform(List** list);
short add(List** list, char ch);
void clearList(List** list);
void printList(List* list);
void deleteTabsAndExtraSpaces(List** list);

#endif
