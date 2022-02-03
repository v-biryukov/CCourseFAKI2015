#include <iostream>
#include <algorithm>
#include <string>
using std::cout, std::endl;


/*
    Рассмотрим ещё недостатки кодов возврата

    Класс Dynarray, описанный ниже, это простая реализация динамического массива.
    Динамический массив должен выделять память в Куче и, следовательно, могут 
    возникнуть ошибки, связанные с невозможностью выделить необходимую память.

    Для обработки этих ошибок в нашем классе Dynarray используются коды возврата.
    (в отличии от std::vector, где используются исключения)
    
    В чём недостатки такого подхода?
*/




template <typename T>
class Dynarray
{
private:
    size_t m_size;
    size_t m_capacity;
    T* m_values;

public:

    Dynarray(size_t initialCapacity) 
    {
        if (initialCapacity < 0)
        {
            std::cout << "Dynarray's capacity has to be non-negative integer\n";
            exit(1);
        }
        m_size = 0;
        m_capacity = initialCapacity;
        m_values = (T*)malloc(m_capacity * sizeof(T));
        if (m_values == nullptr)
        {
            // В конструкторе мы ничего не можем вернуть (?)
        }
    }

    Dynarray() : Dynarray(0)
    {
    }
 
    bool pushBack(T x) 
    {
        if (m_size >= m_capacity)
        {
            if (m_capacity == 0)
                m_capacity = 1;
            else
                m_capacity *= 2;

            T* temp = (T*)malloc(m_capacity * sizeof(T));
            if (temp == nullptr)
            {
                // Если malloc возвращает ошибку, то pushBack будет возвращать false
                return false;
            }
            std::copy_n(m_values, m_size, temp);
            std::free(m_values);
            m_values = temp;
        }
        m_values[m_size] = x;
        m_size += 1;
        // Если всё прошло хорошо, то pushBack возвратит true
        return true;
    }

    size_t getSize() const
    {
        return m_size;
    }

    size_t getCapacity() const
    {
        return m_capacity;
    }

    T& operator[](size_t id) 
    {
        return m_values[id];
    }

    Dynarray& operator=(const Dynarray& right)
    {
        // Проверяем на случай a = a
        if (&right == this)
            return *this;

        free(m_values);

        m_size = right.m_size;
        m_capacity = right.m_capacity;
        m_values = (T*)malloc(m_capacity * sizeof(T));;
        if (m_values == nullptr)
        {
            // Тут мы ничего не можем вернуть (?)
        }
        for (size_t i = 0; i < m_size; i++)
            m_values[i] = right.m_values[i];

        return *this;
    }

    ~Dynarray() 
    {
        free(m_values);
    }
};




int main()
{
    Dynarray<int> a(2);
    int result = a.pushBack(10);
    if (!result)
    {
        cout << "Error: Not enough memory\n";
        std::exit(1);
    }

    result = a.pushBack(20);
    if (!result)
    {
        cout << "Error: Not enough memory\n";
        std::exit(1);
    }
}



/*
    Недостатки данного подхода:

    1) Невозможно ничего вернуть из конструкторов и перегруженных операторов

    2) Необходимость явной проверки после каждого вызова pushBack
       Так как pushBack, может вызвать malloc и привести к ошибке нехватки памяти,
       то после каждого pushBack нужно проверять не привёл ли он к ошибке
*/