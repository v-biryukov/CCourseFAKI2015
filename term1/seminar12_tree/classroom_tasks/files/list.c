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

void list_add_first(Node** p_head, int x)
{
    // Выделяем новый элемент и задаём его значения
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->val = x;
    p_new_node->next = *p_head;

    // Изменяем head
    *p_head = p_new_node;
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

int list_remove_first(Node** p_head)
{
    if (*p_head == NULL)
    {
        printf("Error! Can't remove an element. List is empty!\n");
        exit(1);
    }
    // Запоминаем result, чтобы вернуть это значение и temp, чтобы освободить эту память в конце функции
    Node* temp = *p_head;
    int result = temp->val;

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
        int result = (*p_head)->val;
        free(*p_head);
        *p_head = NULL;
        return result;
    }

    // Находим предпоследний элемент
    Node* ptr = *p_head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    // Удаляем последний элемент и возвращаем его значение
    int result = ptr->next->val;
    free(ptr->next);
    ptr->next = NULL;
    return result;
}


int list_get_first(Node* head)
{
    if (head == NULL)
    {
        printf("Error! Can't get an element. List is empty!\n");
        exit(1);
    }
    return head->val;
}

int list_get_last(Node* head)
{
    if (head == NULL)
    {
        printf("Error! Can't get an element. List is empty!\n");
        exit(1);
    }
    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    return ptr->val;
}

void list_print(Node* head)
{
    // Можно менять head так как этот указатель передаётся по значению и вне этой функции не изменится
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int list_size(Node* head)
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



// Сделаем стек на основе списка:
struct stack
{
    Node* head;
};
typedef struct stack Stack;

void stack_init(Stack* ps)
{
    ps->head = list_create();
}
void push(Stack* ps, int x)
{
    list_add_first(&(ps->head), x);
}
int pop(Stack* ps)
{
    return list_remove_first(&(ps->head));
}
void stack_print(Stack s)
{
    list_print(s.head);
}
void stack_destroy(Stack* ps)
{
    list_destroy(&(ps->head));
}



// Сделаем очередь на основе списка:
struct queue
{
    Node* head;
};
typedef struct queue Queue;

void queue_init(Queue* pq)
{
    pq->head = list_create();
}
void enqueue(Queue* pq, int x)
{
	// Эта операция займёт O(n), что очень плохо
	// Чтобы исправить это, нужно использовать двусвязный список
    list_add_last(&pq->head, x);
}
int dequeue(Queue* pq)
{
    return list_remove_first(&pq->head);
}
void queue_print(Queue q)
{
    list_print(q.head);
}
void queue_destroy(Queue* pq)
{
    list_destroy(&pq->head);
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
    
    printf("Removing 5 first elements and 5 last elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        list_remove_first(&head);
        list_remove_last(&head);
    }
    list_print(head);
    list_destroy(&head);


    printf("\n===== Stack using linked list =====\n");
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


    printf("\n===== Queue using linked list =====\n");
    Queue q;
    queue_init(&q);
    printf("Enqueue 20 elements (from 0 to 19):\n");
    for (int i = 0; i < 20; ++i)
        enqueue(&q, i);
    queue_print(q);

    printf("\nDequeue 15 elements:\n");
    for (int i = 0; i < 15; ++i)
       dequeue(&q);
    queue_print(q);

    printf("\nEnqueue + Dequeue 10000 elements:\n");
    for (int i = 0; i < 10000; ++i)
    {
        enqueue(&q, i);
        dequeue(&q);
    }
    queue_print(q);
    queue_destroy(&q);
}
