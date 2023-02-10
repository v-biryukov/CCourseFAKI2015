#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout, std::endl;


/*
    Разберём ошибки, которые могут возникнуть при работе с умными указателями

    Также как и unique_ptr, shared_ptr хранит только адреса объектов, выделеных в Куче.
    Вызов функции stackVarAddressTest  приведёт к ошибке.

    Достигнув конца области видимости умный указатель попытается удалить память, 
    полагая, что &a это адрес объекта на Куче
*/

void stackVarAddressTest()
{
    cout << "Testing: address of stack variable" << endl;

    int a = 123;
    std::shared_ptr<int> p {&a};
}



/*
    Несмотря на то, что несколько shared_ptr могут указывать на один объект
    Вызывать конструктор shared_ptr(T*) нужно только один раз для каждого объекта на Куче
    Создавать следующие shared_ptr нужно с помощью конструктора копирования shared_ptr(const shared_ptr&)
    Именно в конструкторе копирования и операторе присваивания происходит увеличение счётчика

    В функции manyConstructorsOfRawTest произойдёт ошибка, так как два умных указателя
    sp1 и sp2 были созданы из одного сырого указателя p

    sp1 и sp2 указывают на один объект, но оба имеют свой счётчик, равный 1
    При выходе из функции будет произведена попытка удалить объект дважды
*/
void manyConstructorsOfRawTest()
{
    cout << "Testing: many constructors of raw pointer" << endl;
    
    int* p = new int{123};
    std::shared_ptr<int> sp1 {p};
    std::shared_ptr<int> sp2 {p};
}


/*
    В функции deletePtrTest произойдёт ошибка из-за ручного удаления объекта

    Умный указатель sp1 создан с помощью сырого указателя p    (OK)
    Умный указатель sp2 создан с помощью умного указателя sp1  (OK, верно в отличии от предыдущего примера)

    
    Ошибка происходит когда мы удаляем объект строкой
        delete p;

    При этом, конечно, shared_ptr не может знать о том, что объект удалился и попробует удалить его повторно 
    при выходе из функции и произойдёт ошибка.

*/
void deletePtrTest()
{
    cout << "Testing: delete raw ptr while shared" << endl;
    
    int* p = new int{123};
    std::shared_ptr<int> sp1 {p};
    std::shared_ptr<int> sp2 {sp1}; // Теперь в этом месте верно

    delete p;

}

// Все эти ошибки не будут возникать, если использовать std::make_shared


int main()
{
    // stackVarAddressTest();
    // manyConstructorsOfRawTest();
    // deletePtrTest();
    
    cout << "End of main" << endl;
}