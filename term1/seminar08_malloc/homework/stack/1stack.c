#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000
typedef int Data;

struct stack
{
	int n;
	Data values[CAPACITY];
};
typedef struct stack Stack;


void stack_push(Stack* s, Data x)
{
	if (s->n >= CAPACITY)
	{
		printf("Error! Stack is full! Can't push any elements\n");
		exit(1);
	}
	s->values[s->n] = x;
	s->n += 1;
}

Data stack_pop(Stack* s)
{
	if (s->n <= 0)
	{
		printf("Error! Stack is empty! Can't pop any elements\n");
		exit(1);
	}
	s->n -= 1;
	return s->values[s->n];
}

Data stack_get(const Stack* s)
{
	if (s->n <= 0)
	{
		printf("Error! Stack is empty! Can't get any elements\n");
		exit(1);
	}
	return s->values[s->n - 1];
}

int stack_is_empty(const Stack* s)
{
	return s->n == 0;
}

void stack_init(Stack* s)
{
	s->n = 0;
}

int main()
{
	Stack a;
	stack_init(&a);

	stack_push(&a, 4);
	stack_push(&a, 8);
	stack_push(&a, 15);
	stack_push(&a, 16);

	for (int i = 0; i < 200; ++i)
		stack_push(&a, 16);

	stack_pop(&a);

	printf("%d\n", stack_pop(&a));

}
