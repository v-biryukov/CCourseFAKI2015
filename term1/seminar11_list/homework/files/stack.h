#pragma once
#include "list.h"

// Сделаем стек на основе списка:

struct stack
{
    Node* head;
};
typedef struct stack Stack;

void stack_init(Stack* s)
{
    s->head = list_create();
}

void push(Stack* s, int x)
{
    list_add_first(&(s->head), x);
}

int pop(Stack* s)
{
    return list_remove_first(&(s->head));
}

void stack_print(Stack s)
{
    list_print(s.head);
}

void stack_destroy(Stack* s)
{
    list_destroy(&(s->head));
}
