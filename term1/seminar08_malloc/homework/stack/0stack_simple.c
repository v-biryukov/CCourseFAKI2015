#include <stdio.h>


struct stack
{
	int n;
	int values[100];
};
typedef struct stack Stack;


void stack_push(Stack* s, int x)
{
	s->values[s->n] = x;
	s->n += 1;
}

int stack_pop(Stack* s)
{
	s->n -= 1;
	return s->values[s->n];
}

int stack_is_empty(const Stack* s)
{
	return s->n == 0;
}

int main()
{
	Stack a;
	a.n = 0;

	stack_push(&a, 4);
	stack_push(&a, 8);
	stack_push(&a, 15);
	stack_push(&a, 16);

	stack_pop(&a);

	printf("%d\n", stack_pop(&a));
}
