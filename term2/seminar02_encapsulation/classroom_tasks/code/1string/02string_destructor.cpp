#include <iostream>
#include <cstdlib>
using std::cout, std::endl;

/*

    В конструкторе мы выделили память с malloc. Как её освободить?

    Деструктор
        это специальный метод, который вызывается тогда, когда объект уничтожается
        Если объект создан на стеке, то он уничтожается когда завершается функция
        Если объект создан в куче с помощью new, то он уничтожается при вызове delete
        Синтаксис деструктора такой:
        ~String()
        {
            ...
        }
*/

struct String 
{
private:
    unsigned int size;
    char* data;

public:

    String(const char* str) 
    {
        // Находим размер строки str (strlen не будем пользоваться)
        size = 0;
        while (str[size])
            size++;

        data = (char*)malloc(sizeof(char) * (size + 1));

        // Копируем массив str в новый массив data
        for (int i = 0; str[i]; i++)
            data[i] = str[i];
        data[size] = '\0';
    }

    unsigned int getSize() const 
    {
        return size;
    }

    const char* c_str() const 
    {
        return data;
    }
};

ostream& operator<<(ostream& left, const String& right) 
{
    left << right.c_str();
    return left;
}


int main() {
    String a = String("Cat");
    String b = "Dog";
    String c("Axolotl");
    String d = {"Lion"};
    String e {"Elephant"};         

    cout << a << endl << b << endl << c << endl << d << endl << e << endl;
}



/* Задание:
    1) Напишите деструктор, который будет освобождать память, используя std::free
*/
