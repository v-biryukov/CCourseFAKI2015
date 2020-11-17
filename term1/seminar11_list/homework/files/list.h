#pragma once
#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int value;
    struct node* next;
};
typedef struct node Node;


Node* list_create()
{
    return NULL;
}

void list_add_first(Node** p_head, int x)
{
    // Выделяем новый элемент и задаём его значения
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->value = x;
    p_new_node->next = *p_head;

    // Изменяем head
    *p_head = p_new_node;
}

void list_add_last(Node** p_head, int x)
{
    // Выделяем память на новый элемент
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->value = x;
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

int list_remove_first(Node** p_head)
{
    if (*p_head == NULL)
    {
        printf("Error! Can't remove an element. List is empty!\n");
        exit(1);
    }
    // Запоминаем result, чтобы вернуть это значение и temp, чтобы освободить эту память в конце функции
    Node* temp = *p_head;
    int result = temp->value;

    // head должен указывать на 2-й элемент
    *p_head = (*p_head)->next;

    free(temp);
    return result;
}

int list_remove_last(Node** p_head)
{
	// Отдельно обрабатываем случаи пустого списка и списка, состоящего из 1-го элемента
    if (*p_head == NULL)
    {
        printf("Error! Can't remove an element. List is empty!\n");
        exit(1);
    }
    else if ((*p_head)->next == NULL)
    {
        int result = (*p_head)->value;
        free(*p_head);
        *p_head = NULL;
        return result;
    }

    // Находим предпоследний элемент
    Node* ptr = *p_head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    // Удаляем последний элемент и возвращаем его значение
    int result = ptr->next->value;
    free(ptr->next);
    ptr->next = NULL;
    return result;
}


int list_get_first(const Node* head)
{
    if (head == NULL)
    {
        printf("Error! Can't get an element. List is empty!\n");
        exit(1);
    }
    return head->value;
}

int list_get_last(const Node* head)
{
    if (head == NULL)
    {
        printf("Error! Can't get an element. List is empty!\n");
        exit(1);
    }
    const Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    return ptr->value;
}

void list_print(const Node* head)
{
    // Можно менять head так как этот указатель передаётся по значению и вне этой функции не изменится
    // const означает, что нельзя менять то, на что указывает head. Сам head менять можно
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int list_size(const Node* head)
{
    int size = 0;
    while (head)
    {
        size++;
        head = head->next;
    }
    return size;
}

void list_destroy(Node** p_head)
{
    Node* ptr = *p_head;
    Node* ptr_next;
    while (ptr != NULL)
    {
        ptr_next = ptr->next;
        free(ptr);
        ptr = ptr_next;
    }
    *p_head = NULL;
}



