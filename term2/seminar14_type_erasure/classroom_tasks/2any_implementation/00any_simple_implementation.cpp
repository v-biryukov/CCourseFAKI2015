#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl;

class Any
{
private:

    struct Base
    {
        virtual ~Base() {};
    };


    template <typename T>
    struct Derived : public Base
    {
        T value;

        Derived(const T& aValue) : value(aValue)
        {
        }
    };


    Base* mpNode;


public:

    template <typename T>
    Any(const T& value)
    {
        mpNode = new Derived<T>(value);
    }

    template <typename T>
    void operator=(const T& value)
    {
        delete mpNode;
        mpNode = new Derived<T>(value);
    }


    ~Any()
    {
        delete mpNode;
    }

    template <typename T>
    friend T& anyCast(Any& a);
};



template <typename T>
T& anyCast(Any& a)
{
    auto* p = dynamic_cast<Any::Derived<T>*>(a.mpNode);

    if (p == nullptr)
    {
        throw std::runtime_error("Bad any cast");
    }
    else
    {
        return p->value;
    }
}






int main()
{
    Any a = 123;

    cout << anyCast<int>(a) << endl;


    a = std::string("Cat");

    cout << anyCast<std::string>(a) << endl;


    a = std::vector<int>{10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i)
    {
        cout << anyCast<std::vector<int>>(a)[i] << " ";
    }
    cout << std::endl;


    // cout << anyCast<int>(a) << endl; // Bad any cast
}