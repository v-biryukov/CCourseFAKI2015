typedef int Data;

struct node 
{
    Data val;
    struct node* next;
};
typedef struct node Node;


Node* list_create ()
{
    return NULL;
}

void list_add_first(Node** p_head, Data x)
{
    // Выделяем новый элемент и задаём его значения
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->val = x;
    p_new_node->next = *p_head;

    // Изменяем head
    *p_head = p_new_node;
}

void list_add_last(Node** p_head, Data x)
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

Data list_remove_first(Node** p_head)
{
    if (*p_head == NULL)
    {
        printf("Error! Can't remove an element. List is empty!\n");
        exit(1);
    }
    // Запоминаем result, чтобы вернуть это значение и temp, чтобы освободить эту память в конце функции
    Node* temp = *p_head;
    Data result = temp->val;

    // head должен указывать на 2-й элемент
    *p_head = (*p_head)->next;

    // Освобождаем память под 1-й элемент и возвращаем соответствующее значение
    free(temp);
    return result;
}

Data list_remove_last(Node** p_head)
{
    if (*p_head == NULL)
    {
        printf("Error! Can't remove an element. List is empty!\n");
        exit(1);
    }
    else if ((*p_head)->next == NULL)
    {
        Data result = (*p_head)->val;
        free(*p_head);
        *p_head = NULL;
        return result;
    }

    Node* ptr = *p_head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    Data result = ptr->next->val;
    free(ptr->next);
    ptr->next = NULL;
    return result;
}


Data list_get_first(Node* head)
{
    if (head == NULL)
    {
        printf("Error! Can't get an element. List is empty!\n");
        exit(1);
    }
    return head->val;
}

Data list_get_last(Node* head)
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
    while (head != NULL)
    {
        printf("(%d, %d)", head->val.x, head->val.y);
        head = head->next;
    }
    printf("\n");
}

int list_size(Node* head)
{
    int size = 0;
    while (head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

int list_is_empty(Node* head)
{
    return head == NULL;
}

void list_destroy(Node** p_head)
{
    Node* ptr = *p_head;
    Node* next;
    while (ptr != NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
