/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data.
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент data хранит две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    data - указатель, на элементы, хранящиеся в куче.
    capacity - размер массива data.
    size - сколько ячеек занимет число в массиве data, size <= capacity.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами). 
    апример, число 12345678 соответствует массиву:
    
        {78, 56, 34, 12}
    
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

class Number 
{
private:
    static const int sBase = 100;
    std::size_t mSize;
    std::size_t mCapacity;
    char* mData;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        mCapacity = 0;
        while (temp != 0) 
        {
            temp /= sBase;
            mCapacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (mCapacity == 0) 
            mCapacity = 1;

        // Выделяем память и записывем число a в массив mData
        mData = new char[mCapacity];

        for (int i = 0; i < mCapacity; ++i) 
        {
            mData[i] = a % sBase;
            a /= sBase;
        }

        // В данном случае размер будет равен вместимости
        mSize = mCapacity;
    }


    ~Number() 
    {
        delete [] mData;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.mData[num.mSize - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.mSize - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.mData[num.mSize - 2 - i]);

    return stream;
}

int main() 
{
    Number x = 12345;
    Number y = 0;
    std::cout << x << " " << y << std::endl;
}