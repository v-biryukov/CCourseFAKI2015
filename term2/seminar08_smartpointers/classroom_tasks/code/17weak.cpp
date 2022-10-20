/*
    Умный указатель std::weak_ptr работает в паре с std::shared_ptr
    он не увеличивает счётчик и не вызывает деструктор 
*/


#include <iostream>
#include <string>
#include <memory>

using std::cout, std::endl;

int main()
{
    auto p1 = std::make_shared<int>(123);
    auto p2 = p1;
    auto p3 = p1;
    cout << p1.use_count() << endl;


    // weak_ptr не увеличивает счётчик
    std::weak_ptr<int> pw = p1;
    cout << p1.use_count() << endl;


    // Метод lock возвращает shared_ptr
    std::shared_ptr p4 = pw.lock();
    cout << p1.use_count() << endl;


    // Если на момент вызова lock объект удалился, то вернёт нулевой shared_ptr
    // Так можно проверить, существует ли ещё объект
}
