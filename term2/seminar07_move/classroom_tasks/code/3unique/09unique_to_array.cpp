#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>

using std::cout, std::endl;

// Специальный класс, который печатает на экран, когда вызывается его конструктор и деструктор
class Cat
{
private:
    std::string mName {};

public:
    Cat() : mName("None")  {cout << "Cat Default Constructor (" << mName << ")" << endl;}
    Cat(std::string name) : mName(name) {cout << "Cat Constructor (" << mName << ")" << endl;}
    void say() {cout << "Meow, I am " << mName << endl;}
    ~Cat()  {cout << "Cat Destructor (" << mName << ")" << endl;}
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

        1)  Создайте умный указатель на std::array<int> из чисел от 1 до 20

        2)  Создайте умный указатель на std::vector<Cat> из объектов типа Cat
            с именами "Alisa", "Barsik" и "Casper".

*/


