#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;


struct list
{
	Node* head;
	Node* tail;
};
typedef struct list List;

List* list_create()
{
	List* new_list = (List*)malloc(sizeof(List));
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

void list_print(const List* plist)
{
	Node* ptr = plist->head;
	while (ptr != NULL)
	{
		printf("%d  ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}


void list_add_last(List* plist, int new_value)
{
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->value = new_value;
	pn->next = NULL;
	pn->prev = plist->tail;

	// Отдельно обрабатываем случай пустого списка
	if (plist->head == NULL)
	{
		plist->head = pn;
	}
	else
	{
		plist->tail->next = pn;
	}
	plist->tail = pn;
}



int main()
{
	List* plist = list_create();
	for(int i = 1; i <= 20; i++)
	{
		list_add_last(plist, i);
	}
	list_print(plist);

	/*
	printf("Removing all elements:");
	for(int i = 1; i <= 20; i++)
	{
		int x = list_remove_last(pl);
		printf("Removing: %d\n", x);
	}

	printf("Adding new 20 elements:");
	for(int i = 1; i <= 10; i++)
	{
		list_add_first(plist, i);
		list_add_last(plist, i * i);
	}
	list_print(plist);

	printf("Removing all elements again:");
	for(int i = 1; i <= 20; i++)
	{
		int x = list_remove_first(plist);
		printf("Removing: %d\n", x);
	}

	printf("Adding new 10 elements:");
	for(int i = 1; i <= 10; i++)
	{
		list_add_last(plist, i);
	}
	list_print(plist);
	
	printf("Looking for element 7:");
	Node* element = list_find(plist, 7);

	printf("Inserting 5 elements after 7:");
	for(int i = 1; i <= 5; i++)
	{
		list_insert_after(plist, element, 100 + i);
	}
	list_print(plist);

	list_destroy(plist);
	*/

}