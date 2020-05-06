#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

class Student
{
private:
    std::string name;
    int group;
public:
    Student(std::string init_name, int init_group) : name(init_name), group(init_group) {}
};


int main()
{
    // Создаём переменную int a на стеке
    int a = 16;
    // Создаём новую переменную типа int в куче
    int* p = new int(25);

    // Создадим новую переменную
    p = new int(100);
    // Удалим её
    delete p;

    // Найдите ошибку в коде выше, используя valgrind. Исправьте её.

    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Создайте экземпляр класса Student на стеке


    // Можно ли создать экземпляр класса Student следующим образом?:
    // Student s;

    // Создайте экземпляр класса Student в куче


    // Удалите его


}