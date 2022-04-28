#include <iostream>
#include <cstdlib>
using std::cout, std::endl;

/*
    Напишите operator[] для строки
    Этот оператор должен работать также как и [] у массива
*/

struct String 
{
private:
    unsigned int size;
    char* data;

public:

    String(const char* str) 
    {
        size = 0;
        while (str[size])
            size++;

        data = (char*)malloc(sizeof(char) * (size + 1));
        for (int i = 0; str[i]; i++)
            data[i] = str[i];
        data[size] = '\0';
    }

    String() 
    {
        cout << "Empty constructor" << endl;
        size = 0;
        data = (char*)malloc(sizeof(char) * (size + 1));
        data[0] = '\0';
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
    String a = String("Cat");
    String b = "Dog"; 
    String c("Axolotl");


    cout << c << endl;
    c[1] = 't';
    cout << c << endl;
    c.at(10) = 'b';
    cout << c << endl;
}

/* 
    Задание:

    1) Напишите перегруженный оператор взятия индекса, 
        которая должен работать также, как и [] у массива
        char& operator[](unsigned int id)

    2) Напишите функцию at, которая работает аналогично operator[], но при этом
        проверяет, находится ли индекс в допустимых пределах
        Если не находится, то она должна печатать ошибку и выходить из программы
*/