#include <iostream>
using std::cout, std::endl;

/*
    Функции можно перегружать и по указателю и ссылке

    Но в случае с перегрузкой по ссылке могут возникнуть ситуации при которых невозможно выбрать правильный

    Например, при вызове

        int a = 10;
        func(a);

    Можно выбрать функцию void func(int x)  или  void func(int& x) 
    Определить более правильную функцию в этом случае невозможно, это приведёт к ошибке
*/


void func(int x) 
{
    cout << "int x" << endl;
}

void func(int* x) 
{
    cout << "int* x" << endl;
}
    

void func(int& x) 
{
    cout << "int& x" << endl;
}


int main() 
{
    int a = 10;
    int* p = &a;
    int& r = a;

    func(a);
}


/*
    Задачи:

    1)  Определите какая функция вызовется при следующих вызовах функции func или произойдёт ошибка

            1)  func(a)
            2)  func(p)
            3)  func(&a)
            4)  func(20)
            5)  func(r)
            6)  func(&r)

    
    2)  Если добавить перегрузку, принимающую по константной ссылке, то что изменится?
    
            void func(const int& x) 
            {
                cout << "const int& x" << endl;
            }
*/