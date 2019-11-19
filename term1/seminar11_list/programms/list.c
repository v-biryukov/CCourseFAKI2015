#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int val;
    struct node* next;
};
typedef struct node Node;


Node* list_create ()
{
    return NULL;
}

void list_add_last(Node** p_head, int x)
{
    // Выделяем память на новый элемент
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->val = x;
    p_new_node->next = NULL;
    
    // Создаём указатель на первый элемент
    Node* ptr = *p_head;
    if (ptr == NULL)
    {
        *p_head = p_new_node;
    }
    else
    {
        // Идём до последнего элемента
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = p_new_node;
    }
}


int main()
{
    printf("===== Linked list =====\n");
    Node* head = list_create();

    printf("Adding 20 elements:\n");
    for (int i = 0; i < 20; ++i)
        list_add_first(&head, i);
    list_print(head);
    printf("\nList size = %d\n\n", list_size(head));
    
    printf("Removing 5 first elements elements and 5 last elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        list_remove_first(&head);
        list_remove_last(&head);
    }
    list_print(head);
    list_destroy(&head);
}
