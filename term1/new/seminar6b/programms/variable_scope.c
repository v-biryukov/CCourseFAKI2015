#include <stdio.h>

/* Объявление глобальной переменной: */
int a;

int main ()
{
  /* Объявление локальной переменной: */
  int b;

  /* Инициализация */
  a = 10;
  b = 20;

  {
    int b = 70;
    int f = 95;
  }

  if (true)
  {
	int b = 50;
  	printf("value of b inside if statement: %d \n", b);
  }
  
  printf("value of b : %d \n", b);
  //printf("value of f : %d \n", f);
 
  return 0;
}
