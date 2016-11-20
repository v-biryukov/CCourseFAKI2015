#include <stdlib.h>
#include <stdio.h>


// typedef = Data будет "синонимом" int
typedef int Data;

// Описание структуры стека
struct Stack {
    int n;
    int size;
    Data * a; 
};


// Прототипы функций работы со стеком   ---------------

struct Stack * stack_create(int size);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);


// Реализация функций работы со стеком   ---------------

// Функция stack_create выделяет память для стека
// И инициализирует все переменные для работы с ним
struct Stack * stack_create(int size)
{
	// Сначала выделим память на структуру стека
	// Выделится память на 2 переменные типа int: s->n и s->size
	// И на 1 указатель s->a
	// Память на будущие элементы стека ещё не выделяется
	struct Stack * s = (struct Stack *)malloc(sizeof(struct Stack));

	// Инициализируем переменные n -- это текущее количество элементов в стеке
	// size -- текущий размер динамического массива
	s->n = 0;
	s->size = size;

	// Выделяем память под будущие элементы стека
	s->a = (Data *) malloc(size * sizeof(Data));

	// Не забываем возвратить указатель на структуру стека
	return s;
}

// Функция stack_push добавляет элемент в стек
void stack_push(struct Stack * s, Data x)
{
	// Сначала проверим хватает ли нам выделенной памяти
	// Если n == size, то массив уже заполнился
	if ( s->n == s->size )
	{
		// Если Не хватает, то нужно выделить больше памяти
		// Для этого:
		// 1) Определяемся с новым размером массива, я решил увеличивать его размер в 2 раза
		int new_size;
		if (s->size == 0)
			new_size = 2;
		else
			new_size = 2 * s->size;

		// 2) Выделяем память на новый массив нужного размера
		Data * new_a = malloc( new_size * sizeof(Data));

		// 3) Переписываем значения из старого массива в новый
		int i;
		for ( i = 0; i < s->size; ++i )
			new_a[i] = s->a[i];

		// 4) Удаляем старый массив (освобождаем память)
		free(s->a);

		// Задаем новые значения размера массива и указателя на массив
		s->a = new_a;
		s->size = new_size;
	}

	// Тепереь мы точно знаем, что места под новый элемент хватит
	// Добавляем его как обычно (как в задаче stack_1)
	s->a[s->n] = x;
	s->n++;
}

// Функция stack_pop вынимает верхний элемент стека и возвращает его
Data stack_pop(struct Stack * s)
{
	// Проверим пустой ли стек
	if ( s->n == 0 )
	{
		// Если стек пустой, элементов нет, то это ошибка!
		// Выходив из программы предварительно удалив стек
		printf("Error! Can't pop from stack! It's empty!\n");
		stack_destroy(s);
		exit(1);
	}

	// Тепере мы точно знаем, что стек не пуст
	// Делаем также как и в задаче stack_1
	s->n--;
	return s->a[s->n];
}

// Функция stack_get -- возвращает верхний элемент стека
Data stack_get(struct Stack * s)
{
	if ( s->n == 0 )
	{
		printf("Error! Can't get from stack! It's empty!\n");
		stack_destroy(s);
		exit(1);
	}
	return s->a[s->n-1];
}


// Функция stack_print -- печатает стек
void stack_print(struct Stack * s)
{
	// Если стек пуст, нужно напечатать "Empty stack"
	if (stack_is_empty(s))
		printf("Empty stack\n");
	else
	{
		int i;
		for (i = 0; i < s->n; ++i)
			printf("%d ", s->a[i]);
		printf("\n");
	}
}

int  stack_size(struct Stack * s)
{
	return s->n;
}

int  stack_is_empty(struct Stack * s)
{
	return s->n == 0;
}

void stack_clear(struct Stack * s)
{
	s->n = 0;	
}


// Функция stack_destroy -- освобождает память, выделенную в stack_create
void stack_destroy(struct Stack * s)
{
	free(s->a);
	free(s);
}


int main()
{
	// Чтобы полностью проверить работоспособность программы
	// 		нужно использовать специальную программу valgrind (в linux)
	// 		например так: valgrind ./a.out
	//		она укажет на ошибки работы с памятью
	//		например, в коде ниже size задается равным 3, а в стек добавляется 4 элемента
	// 		если бы мы это не предусмотрели в функции stack_push,
	//		то программа не всегда бы работала правильно


	struct Stack * sp = stack_create(3);

	stack_push(sp, 5);
	stack_push(sp, 19);
	stack_push(sp, -2);
	stack_print(sp);
	// 5 19 -2

	stack_push(sp, 27);
	stack_print(sp);
	// 5 19 -2 27
	printf("is_empty=%d\n", stack_is_empty(sp));
	// is_empty=0

	Data x = stack_pop(sp);
	printf("x=%d\n", x);
	// x=27

	x = stack_pop(sp);
	printf("x=%d\n", x);
	// x=-2

	stack_print(sp);
	// 5 19

	stack_destroy(sp);


	return 0;


}