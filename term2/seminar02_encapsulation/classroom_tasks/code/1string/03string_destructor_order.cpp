#include <iostream>
#include <cstdlib>
using std::cout, std::endl;

/*
    Деструктор
        это специальный метод, который вызывается тогда, когда объект уничтожается
        Например, если объект создан на стеке, то он уничтожается когда завершается функция
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
        cout << "Constructor: " << str << endl;
        size = 0;
        while (str[size])
            size++;

        data = (char*)malloc(sizeof(char) * (size + 1));

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

    ~String() 
    {
        cout << "Destructor: " << data << endl;
        free(data);
    }

};

ostream& operator<<(ostream& left, const String& right) 
{
    left << right.c_str();
    return left;
}


int main() 
{
    String a {"Cat"};
    String b {"Dog"}; 
    String c {"Axolotl"};
}



/*  Задание:

    1) В каком порядке будут вызываться конструкторы и деструкторы
        Запустите программу, чтобы проверить вашу догадку

    2) Предположим, что мы захотели создать саму структуру String (а не только массив data)
        Вот так:
            String* s = (String*)malloc(sizeof(String));
        Вызовется ли конструктор в этом случае?

        А потом нужно эту память освободить
            free(s);
        Вызовется ли деструктор в этом случае?
        Проверьте ваши догадки
*/