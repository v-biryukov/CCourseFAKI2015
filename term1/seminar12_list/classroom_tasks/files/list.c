#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};
typedef struct node Node;


Node* list_create () {
    return NULL;
}

// Передайм указатель head в функцию по указателю
// так как head может измениться внутри функции (если head == NULL)
// Для односвязного списка эта функция неэффективна, так как нужно
// идти по всему списку, чтобы найти его конец
void list_add_last(Node** p_head, int x) {
    // Выделяем память на новый элемент
    Node* p_new_node = (Node*)malloc(sizeof(Node));
    p_new_node->value = x;
    p_new_node->next = NULL;
    
    // Создаём указатель на первый элемент
    Node* ptr = *p_head;
    if (ptr == NULL) {
        *p_head = p_new_node;
    }
    else {
        // Идём до последнего элемента и подсоединяем элемент в конец списка
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = p_new_node;
    }
}


// Печатаем список, элементы разделены строкой separator
void list_print(const Node* head, char separator[]) {
    // Создаём указатель на первый элемент, вместо ptr можно было использовать и head
    const Node* ptr = head;
    // Идём до последнего элемента и печатаем все элементы
    while (ptr->next != NULL){
        printf("%i%s", ptr->value, separator);
        ptr = ptr->next;
    }
    // Печатаем последний элемент
    printf("%i\n", ptr->value);
}


int main() {
    Node* head = list_create();

    for (int i = 1; i <= 10; ++i) {
        list_add_last(&head, i);
    }
    list_print(head, ", ");

    // Тестируем. Вам нужно написать соответствующие функции
    // чтобы код ниже работал
    /*
    printf("Adding 20 elements:\n");
    for (int i = 1; i <= 20; ++i) {
        list_add_first(&head, i);
    }
    list_print(head, ", ");
    printf("\nList size = %d\n\n", list_size(head));
    
    printf("Removing 5 first elements elements and 5 last elements:\n");
    for (int i = 0; i < 5; ++i) {
        list_remove_first(&head);
        list_remove_last(&head);
    }
    list_print(head, ", ");
    list_destroy(&head);
    */
}
