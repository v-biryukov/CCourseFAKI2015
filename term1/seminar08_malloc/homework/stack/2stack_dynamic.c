#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct stack
{
	int size;
	int capacity;
	Data* values;
};
typedef struct stack Stack;


void stack_push(Stack* s, Data x)
{
	if (s->size >= s->capacity)
	{
		s->capacity *= 2;
		Data* temp;
		temp = realloc(s->values, s->capacity * sizeof(int));
		if (temp == NULL)
		{
			printf("Error! Can't reallocate %lu bytes of memmory using realloc()\n", s->capacity * sizeof(Data));
			free(s->values);
			exit(1);
		}
		else
		{
			s->values = temp;
		}
	}
	s->values[s->size] = x;
	s->size += 1;
}

Data stack_pop(Stack* s)
{
	if (s->size <= 0)
	{
		printf("Error! Stack is empty! Can't pop any elements\n");
		exit(1);
	}
	s->size -= 1;
	return s->values[s->size];
}

Data stack_get(Stack* s)
{
	if (s->size <= 0)
	{
		printf("Error! Stack is empty! Can't get any elements\n");
		exit(1);
	}
	return s->values[s->size - 1];
}

int stack_is_empty(const Stack* s)
{
	return s->size == 0;
}

void stack_init(Stack* s, int initial_capacity)
{
	if (initial_capacity < 1)
	{
		printf("Error! Stack's capacity has to be positive integer\n");
		exit(1);
	}
	s->size = 0;
	s->capacity = initial_capacity;
	s->values = malloc(s->capacity * sizeof(Data));
	if (s->values == NULL)
	{
		printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", s->capacity * sizeof(Data));
		exit(1);
	}
}

void stack_destroy(Stack* s)
{
	free(s->values);
}


int main()
{
	Stack a;
	stack_init(&a, 1000);

	stack_push(&a, 4);
	stack_push(&a, 8);
	stack_push(&a, 15);
	stack_push(&a, 16);

	for (int i = 0; i < 2000; ++i)
		stack_push(&a, i);

	stack_pop(&a);

	printf("%d\n", stack_pop(&a));


	stack_destroy(&a);
	
}
