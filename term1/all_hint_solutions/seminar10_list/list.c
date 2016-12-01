#include <stdio.h>
#include <stdlib.h>


// Описание структуры данных Список (List)

typedef int Data;

struct Node 
{
	Data val;
	struct Node * next;
};

struct List 
{
	struct Node * head;
};

// Прототипы функций для работы со списком

struct List * list_create ();
void list_add_first (struct List * list, Data x);
void list_add_last (struct List * list, Data x);
Data list_remove_first (struct List * list);
Data list_remove_last (struct List * list);
Data list_get_first (struct List * list);
Data list_get_last (struct List * list);
void list_print (struct List * list);
int list_size(struct List * list);
void list_clear(struct List * list);
void list_destroy (struct List * list);




// Функция list_create выделяет память под список
// Память выделяется только под структуру List
// pl->head -- это указатель на 1-й элемент
// pl->head = NULL означает, что никаких элементов в списке пока нет
struct List * list_create ()
{
	struct List * pl = (struct List *)malloc(sizeof(struct List));
	pl->head = NULL;
	return pl;
}

// list_add_first добавляет элемент в начало списка
// 1) Выделяем память под один элемент с помощью malloc
// 2) Заполняем значениями только что созданный элемент
//      так как новый элемент будет добавлен в начало, то
//      он будет указывать на старый 1-й элемент, т.е. list->head
// 3) list->head должен указывать на новый 1-й элемент
void list_add_first (struct List * list, Data x)
{
	// 1)
	struct Node *pn = (struct Node *)malloc(sizeof(struct Node));
	// 2)
	pn->val = x;
	pn->next = list->head;
	// 3)
	list->head = pn;
}

// list_add_last добавляет элемент в конец списка
// 1) Выделяем память под один элемент с помощью malloc
// 2) Заполняем значениями только что созданный элемент
//      так как новый элемент будет добавлен в конец, то
//      он не будет никуда указывать т.е. pn->next = NULL
// 3) Находим последний элемент обойдя весь список с помощью цикла while
// 4) Сделаем так, чтобы старый последний элемент указывал на новый последний элемент
void list_add_last(struct List * list, Data x)
{
	// 1)
	struct Node *pn = (struct Node *)malloc(sizeof(struct Node));
	// 2)
	pn->val = x;
	pn->next = NULL;

	// 3)
	struct Node * ptr = list->head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	// 4)
	ptr->next = pn;
}


// list_remove_last удаляет последний элемент списка
// Суть в том, чтобы найти предпоследний элемент и по нему удалить последний
// 1) Если в списке всего 1 элемент, то предпоследнего элемента нет, значит этот случай нужно обработать отдельно
// 2) Если в списке больше элементов, то сначала находи предпоследний элемент
//      обратите внимание на ptr->next->next != NULL  вместо ptr->next != NULL в цикле
//      так можно найти ptr -- предпоследний элемент
// 3) Так как мы хотим сначала освободить память последнего элемента, а потом вернуть значение,
//      которое в нем хранилось, то это значение нужно запомнить: Data result = ptr->next->val;
// 4) Освобождаем память последнего элемента
// 5) Делаем так, чтобы предпоследний элемент был последним
// 6) Возвращаем сохранённое ранее значение
Data list_remove_last (struct List * list)
{
	// 1)
	if (list->head->next == NULL)
	{
		Data result = list->head->val;
		free(list->head);
		list->head = NULL;
		return result;
	}
	// 2)
	struct Node * ptr = list->head;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}

	// 3)
	Data result = ptr->next->val;
	// 4)
	free(ptr->next);
	// 5)
	ptr->next = NULL;
	// 6)
	return result;
}

// list_remove_last удаляет первый элемент списка
// 1) Так как мы хотим сначала освободить память первого элемента, а потом вернуть значение
//        и присвоить правильное значение list->head,
//        то нам нужно сначала запомнить возвращаемое значение list->head->val  И  
//        запомнить указатель на следующий элемент  list->head->next
// 2) Освобождаем память первого элемента
// 3) Присваиваем правильное значение list->head (ранее сохранённое)
// 4) Возвращаем сохранённое ранее значение
Data list_remove_first (struct List * list)
{
	//  Эту функцию вам нужно написать самим
	//  |||||||||||||||||||||||||||||||||||||||||||||||
	//  |||||||  Ниже ваш код  ||||||||||||||||||||||||
	//  |||||||||||||||||||||||||||||||||||||||||||||||








	// ||||||||||||||||||||||||||||||||||||||||||||||||
}
// list_get_first возвращает первый элемент списка
// 1) Возвращаем первый элемент списка и всё
Data list_get_first (struct List * list)
{
	// 1)
	return list->head->val;
}

// list_get_first возвращает последний элемент списка
// 1) Находим последний элемент обойдя весь список с помощью цикла while
// 2) Возвращаем последний элемент списка
Data list_get_last (struct List * list)
{
	//  Эту функцию вам нужно написать самим
	//  |||||||||||||||||||||||||||||||||||||||||||||||
	//  |||||||  Ниже ваш код  ||||||||||||||||||||||||
	//  |||||||||||||||||||||||||||||||||||||||||||||||







	// ||||||||||||||||||||||||||||||||||||||||||||||||
}

// list_get_first печатаем все элементы списка
// 1) Если список пуст, то печатаем "Empty list"
// 2) Иначе, пробегаем по всему списку с помощью цикла while
// 3) И каждый раз печатаем элемент списка
void list_print (struct List * list)
{

	// 1)
	if (list->head == NULL)
		printf("Empty list\n");
	else
	{
		// 2)
		struct Node * ptr = list->head;
		while (ptr != NULL)
		{
			// 3)
			printf("%d ", ptr->val);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

// list_size находит количество элементов в списке
// 1) Вводим переменную n = 0
// 2) Пробегаем по всему списку с помощью цикла while
// 3) И каждый раз увеличиваем n на 1
// 4) Возвращаем n
int list_size(struct List * list)
{
	//  Эту функцию вам нужно написать самим
	//  |||||||||||||||||||||||||||||||||||||||||||||||
	//  |||||||  Ниже ваш код  ||||||||||||||||||||||||
	//  |||||||||||||||||||||||||||||||||||||||||||||||







	// ||||||||||||||||||||||||||||||||||||||||||||||||
}

// list_clear - удаляет все элементы списка и освобождает память
// 1) Заведём 2 указателя на элемент списка, один -- ptr -- как обычно будет пробегать по всему списку
//        второй -- вспомогательный
// 2) Пробегаем по всему списку с помощью цикла while
// 3) И каждый раз освобождаем память под элемент,
//        сохраняя, при этом, указатель на следующий элемент в temp_ptr
void list_clear(struct List * list)
{
	struct Node * ptr = list->head;
	struct Node * temp_ptr;

	while (ptr != NULL)
	{
		temp_ptr = ptr->next;
		free(ptr);
		ptr = temp_ptr;
	}
}

// list_destroy - удаляет все элементы списка и освобождает память
//       И удаляет саму структуру список
// 1) Удалить все элементы списка
// 2) Удалить саму структуру списка
void list_destroy (struct List * list)
{
	// 1)
	list_clear(list);
	// 2)
	free(list);
}


int main()
{
	struct List * list = list_create();
	list_add_first(list, 5)
	list_print(list);
	list_destroy(list);

	return 0;
}














