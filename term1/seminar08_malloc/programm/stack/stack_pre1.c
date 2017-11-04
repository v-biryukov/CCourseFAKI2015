#include <stdio.h>



int n;
int values[100];


void stack_push(int x)
{
	values[n] = x;
	n += 1;
}

int stack_pop()
{
	n -= 1;
	return values[n];
}

int stack_is_empty()
{
	return n == 0;
}

int main()
{
	
	n = 0;

	stack_push(4);
	stack_push(8);
	stack_push(15);
	stack_push(16);

	stack_pop();

	printf("%d\n", stack_pop());


}
