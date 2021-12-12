#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;



// Также как и unique_ptr, shared_ptr хранит только адреса объектов,
// выделеных в Куче.
// Вызов этой функции приведёт к ошибке
void stackVarAddressTest()
{
    cout << "Testing: address of stack variable" << endl;

    int a = 123;
    std::shared_ptr<int> p {&a};
    // Достигнув конца области видимости умный указатель попытается
    // удалить память, полагая, что &a это адрес объекта на Куче
}



// Несмотря на то, что несколько shared_ptr могут указывать на один объект
// Вызывать конструктор shared_ptr(T*) нужно только один раз для каждого объекта на Куче
// Создавать следующие shared_ptr нужно с помощью конструктора копирования shared_ptr(const shared_ptr&)
// Именно в конструкторе копирования и операторе присваивания происходит увеличение счётчика

// В следующей функции произойдёт ошибка
void manyConstructorsOfRawTest()
{
    cout << "Testing: many constructors of raw pointer" << endl;
    
    int* p = new int{123};
    std::shared_ptr<int> sp1 {p};
    std::shared_ptr<int> sp2 {p};

    // sp1 и sp2 указывают на один объект, но оба имеют свой счётчик, равный 1
    // При выходе из функции будет произведена попытка удалить объект дважды
}

// Ошибка произойдёт и при удалении
void deletePtrTest()
{
    cout << "Testing: delete raw ptr while shared" << endl;
    
    int* p = new int{123};
    std::shared_ptr<int> sp1 {p};
    std::shared_ptr<int> sp2 {sp1}; // Теперь в этом месте верно

    // Удалим объект
    delete p;
    // При этом, конечно, shared_ptr не может знать о том, что он удалился
    // и попробует удалить его повторно при выходе из функции
    // (Указатель int* p вообще не считается при подсчёте указателей в count)
}

// Все эти ошибки не будут возникать, если использовать std::make_shared



int main()
{
    // stackVarAddressTest();
    // manyConstructorsOfRawTest();
    // deletePtrTest();
    
    cout << "End of main" << endl;
}

/*
    Задача 1: Протестируйте эти 3 функции


*/