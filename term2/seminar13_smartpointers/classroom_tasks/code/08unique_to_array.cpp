#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>

using std::cout;
using std::endl;

class Cat
{
private:
    std::string m_name;
    int m_age;

public:

    Cat(std::string name = "", int age = 0) : m_name(name), m_age(age)
    {
        std::cout << m_name << " Constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << m_name << " Destructor" << std::endl;
    }

    std::string getName()
    {
        return m_name;
    }

    int getAge()
    {
        return m_age;
    }

    void say()
    {
        std::cout << "Meow, I am " << m_name << std::endl;
    }
};

const int N = 20;

int main()
{
    // Если нужно создать умный указатель на массив из объектов, то лучше использовать контейнеры STL
    // такие как std::vector, std::array и другие

    auto pv = std::make_unique<std::vector<int>>();
    for (int i = 0; i < N; ++i)
    {
        (*pv).push_back(i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << (*pv)[i] << " ";
    }
    cout << endl;


    // Если очень нужно, то можно и создать указатель на массив объектов в куче
    // (Аналог int* p = new int[N];)
    // Для этого используется специализация std::unique_ptr<int[]>
    // В этой специализации unique_ptr, при удалении, использует оператор delete [], а не delete
    // Также в этом случае переопределен operator[] (но не переопределены операторы * и ->)

    // Создаём указатель типа std::unique_ptr<int[]>:
    auto pa = std::make_unique<int[]>(N);
    for (int i = 0; i < N; ++i)
    {
        pa[i] = i + 1;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << pa[i] << " ";
    }

    pa + 1;
}


/*
    Задачи:

        1) Создайте умный указатель на std::array<int> из чисел от 1 до 20

        2) Создайте умный указатель на std::vector<Cat> из объектов типа Cat
        с именами "Alisa", "Barsik" и "Casper" и возрастами 10, 20 и 30
        соответственно

*/


