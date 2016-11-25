#include <stdio.h>
#include <stdlib.h>



typedef int Data;

struct Node 
{
	Data val;
    struct Node * next;
};

struct List 
{
	struct Node * head;
};





struct List * list_create ();
void list_add_first (struct List * list, Data x);
void list_add_last (struct List * list, Data x);
Data list_remove_first (struct List * list);
Data list_remove_last (struct List * list);
Data list_get_first (struct List * list);
Data list_get_last (struct List * list);
void list_print (struct List * list);
int list_size(struct List * list);
void list_clear(struct List * list);
void list_destroy (struct List * list);



struct List * list_create ()
{
	struct List * pl = (struct List *)malloc(sizeof(struct List));
	pl->head = 0;
	return pl;
}


void list_add_first (struct List * list, Data x)
{
	struct Node *pn = (struct Node *)malloc(sizeof(struct Node));
	pn->val = x;
	pn->next = list->head;

	list->head = pn;
}

void list_print (struct List * list)
{
	struct Node * ptr = list->head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}



int main()
{
	struct List * a = list_create();
	list_add_first(a, 1);
	list_add_first(a, 5);
	list_add_first(a, 16);
	list_add_first(a, 4);
	list_print(a);
}














