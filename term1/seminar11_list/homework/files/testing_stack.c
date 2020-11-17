#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int main()
{
    printf("\n===== Testing Stack (linked list implementation) =====\n");
    Stack s;
    stack_init(&s);
    printf("Push 20 elements (from 0 to 19):\n");
    for (int i = 0; i < 20; ++i)
        push(&s, i);
    stack_print(s);

    printf("\nPop 15 elements:\n");
    for (int i = 0; i < 15; ++i)
       pop(&s);
    stack_print(s);

    printf("\nPush + Pop 10000 elements:\n");
    for (int i = 0; i < 10000; ++i)
    {
        push(&s, i);
        pop(&s);
    }
    stack_print(s);
    stack_destroy(&s);
}


