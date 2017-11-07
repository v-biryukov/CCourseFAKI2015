#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int n;
	int capacity;
	int* values;
} Stack;


void stack_push(Stack* s, int x)
{
	if (s->n >= s->capacity)
	{
		s->capacity *= 2;
		s->values = realloc(s->values, s->capacity * sizeof(int));
	}
	s->values[s->n] = x;
	s->n += 1;
}

int stack_pop(Stack* s)
{
	if (s->n <= 0)
	{
		printf("Error! Stack is empty! Can't pop any elements\n");
		exit(1);
	}
	s->n -= 1;
	return s->values[s->n];
}

int stack_is_empty(Stack* s)
{
	return s->n == 0;
}

void stack_init(Stack* s, int initial_capacity)
{
	if (initial_capacity < 1)
	{
		printf("Stack's capacity has to be positive integer\n");
		exit(1);
	}
	s->n = 0;
	s->capacity = initial_capacity;
	s->values = malloc(s->capacity * sizeof(int));
}

void stack_destroy(Stack* s)
{
	free(s->values);
}


int main()
{
	Stack a;
	stack_init(&a, 100);

	stack_push(&a, 4);
	stack_push(&a, 8);
	stack_push(&a, 15);
	stack_push(&a, 16);

	for (int i = 0; i < 200; ++i)
		stack_push(&a, i);

	stack_pop(&a);

	printf("%d\n", stack_pop(&a));


	stack_destroy(&a);
	
}
