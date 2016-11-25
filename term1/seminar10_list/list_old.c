struct node 
{
	int data;
	struct node *next;
};
typedef struct node Node;


struct list 
{
	Node *head;
};
typedef struct list List;


// Функции, которые реализованы
void init_list (List *);                      /* Инициализация пустого массива */
void insert_front(List *, int val);           /* Вставить элемент в начало */
void insert_back(List *, int val);            /* Вставить элемент в конец */
int get_item(List l, int n);                  /* Вернуть значение n-го элемента листа */
void destroy(List *);                         /* Удалить лист */

// Функции, которые нужно реализовать
int length(List l);                              /* Длина связного листа */
int print(List l);                               /* Распечатать лист */
void insert_n(List * pl, int n, int val);        /* Вставить элемент между n-м и (n+1)-м элементом */
void set_item(List * pl, int n, int val);        /* Изменить элемент листа*/
int pop(List * pl);                              /* Удаляем 1-й элемент и возвращаем его значение */
void destroy_element(List * pl, int n);          /* Удалить n-й элемент листа */
int reverse(List * pl);                          /* Разворачивает лист (Задание из контрольной прошлого года)*/




void init_list(struct List * pl) 
{
	pl->head = 0;
}

void insert_front(struct List * pl, int val) 
{
	Node *newitem;
	newitem = (Node *)malloc(sizeof(Node));
	newitem->next = pl->head;
	newitem->data = val;
	pl->head = newitem;
}

void insert_back(List * pl, int val) 
{
	Node *ptr;
	Node *newitem;
	newitem = (Node *)malloc(sizeof(Node));
	newitem->data = val;
	newitem->next = 0;
	if (!pl->head) 
	{
		pl->head = newitem;
		return;
	}
	ptr = pl->head;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = newitem;
}


int get_item(List l, int n) 
{
	Node *ptr;
	int count = 0;
	if (!l.head) 
		return 0;
	ptr = l.head;
	if (n == 0) 
		return ptr->data;
	while (ptr->next) 
	{
		ptr = ptr->next;
		count++;
		if (n == count)
			return (ptr->data);
	}
	return 0;
}


void destroy(List * pl) 
{ 
	Node *current, *next;
	if (!pl->head) 
		return;
	current = pl->head; /* удаляем по одному элементу */
	while (current) 
	{
		next = current;
		current = current->next;
		free(next);
	}
	pl->head = 0;
}


// Напишите функции length, print, insert_n, set_item, pop, destroy_element и reverse ниже
// -----------------------------------------------------------------------------------------

// Пример: функция length
int length(List l)
{
	// Объявляем новый указатель на Node, приравниваем его к указателю на начало списка (l.head)
	Node * ptr = l.head;
	int count = 0;
	// С помощью цикла while пробегаем весь список
	while (ptr->next)
	{
		ptr = ptr->next;
		// Измените count здесь
		// count = ?
		// -----------------------------------
	}
	// Верните правильное значение -- количество элементов в списке
	// return ?;
}



// -----------------------------------------------------------------------------------------


int main()
{
	// Объявляем лист
	List l;
	// Инициализация листа
	init_list(&l);
	// Вставляем элементы
	insert_front(&l, 5);   // Лист: 5
	insert_front(&l, 4);   // Лист: 4 -> 5
	insert_front(&l, 3);   // Лист: 3 -> 4 -> 5
	insert_back(&l, 1);    // Лист: 3 -> 4 -> 5 -> 1
	
	printf("Печатаем третий элемент листа = %d\n", get_item(l, 2));

	// Раскомментируйте строки ниже для тестирования ваших функциий
	
	// 1) нужно написать функцию length(List l)
	// printf("Длина связного листа = %d\n ", length(l));
	
	// 2) нужно написать функцию print(List l)
	// printf("Печатаем лист:\n");
	// print(l);
	
	// 3) нужно написать функцию insert_n(List * pl, int n, int val)
	// printf("Вставляем новый элемент между 2-м и 3-м элементом и печатаем получившийся лист\n");
	// insert_n( &l, 2, 17);
	// print(l);

	// 4) нужно написать функцию set_item(List * pl, int n, int val)
	// printf("Задаём значение 2-го элемента\n");
	// set_item( &l, 1, 9);
	// print(l);

	// 5) нужно написать функцию pop(List * pl)
	// printf("Удаляем 1-й элемент\n");
	// int a = pop(&l);
	// printf("Он равен %d\n, a");
	// print(l);

	// 6) нужно написать функцию destroy_element(List * pl, int n)
	// printf("Удаляем 3-й элемент\n");
	// destroy_element( &l, 2);
	// print(l);
	
	// 7) нужно написать функцию reverse(List * pl)
	// printf("Переворачиваем лист\n");
	// reverse(&l);
	// print(l);
	

	// Не забываем освободить память
	destroy(&l);


	
	
	return 0;
}
