#include <stdio.h>
#include "list.h"


int main()
{
    printf("\n===== Testing linked list =====\n");
    Node* head = list_create();

    printf("Adding 20 elements:\n");
    for (int i = 0; i < 20; ++i)
        list_add_first(&head, i);
    list_print(head);
    printf("\nList size = %d\n\n", list_size(head));
    
    printf("Removing 5 first elements and 5 last elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        list_remove_first(&head);
        list_remove_last(&head);
    }
    list_print(head);
    list_destroy(&head);
}


