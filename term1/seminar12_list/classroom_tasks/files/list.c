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

// Передайм указатель head в функцию по указателю p_head
// так как head может измениться внутри функции
// *p_head == head
// Для односвязного списка эта функция неэффективна, так как нужно
// идти по всему списку, чтобы найти его конец
void list_add_last(Node** p_head, int x) {
    // Выделяем память на новый элемент и заполняем его
    Node* p_new_node = (Node*)malloc(sizeof(Node));
    p_new_node->value = x;
    p_new_node->next = NULL;
    
    if (*p_head == NULL) {
        // Если список пустой, то нужно сделать так,
        // чтобы head указывала на новый элемент
        *p_head = p_new_node;
    }
    else {
        // Если список не пустой, то нужно сделать так,
        // Создаём указатель на первый элемент
        Node* ptr = *p_head;
        // Идём этим указателем до последнего элемента 
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        // Присоединяем элемент в конец списка
        ptr->next = p_new_node;
    }
}


// Печатаем список, элементы разделены строкой separator
void list_print(const Node* head, char separator[]) {
    // Если список пуст, то просто ничего не делаем
    if (head == NULL) {
        return;
    }
    // Создаём указатель на первый элемент
    // const Node* означает, что нельзя менять то, на что указывает указатель
    // При этом сам указатель менять можно
    const Node* ptr = head;

    // Идём до последнего элемента и печатаем все элементы кроме последнего
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
