#include <stdio.h>
int a = 0;  // глобальная переменная

void test()
{
	// область видимости функции
	printf("Inside test function, before local a declaration. a = %d\n", a);
	int a = 3; // глобальная переменная скроется
	printf("Inside test function, after local a declaration. a = %d\n", a); 
}

int main()
{
    printf("Inside main function, first. a = %d\n", a);
    {
       int a = 1; // объявлена локальная переменная а, глобальная переменная a не видна
       test();
       printf("Inside main function, second. a = %d\n", a); 
       {
          int a = 2; // еще локальная переменная в блоке, глобальная переменная a не видна, не видна и предыдущая локальная переменная
          printf("Inside main function, third. a = %d\n", a);  
          int b = 5;
       }
	   // printf("Will never b printed. b = %d\n", b); // Ошибка
    }
	return 0;
}
