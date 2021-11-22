#include <stdio.h>


struct stack {
	int size;
	int values[100];
};
typedef struct stack Stack;


void stack_push(Stack* s, int x) {
	s->values[s->size] = x;
	s->size += 1;
}

int stack_pop(Stack* s) {
	s->size -= 1;
	return s->values[s->size];
}

int stack_is_empty(const Stack* s) {
	return s->size == 0;
}

int main() {
	Stack a;
	a.size = 0;

	stack_push(&a, 4);
	stack_push(&a, 8);
	stack_push(&a, 15);
	stack_push(&a, 16);

	stack_pop(&a);

	printf("%d\n", stack_pop(&a));
}
