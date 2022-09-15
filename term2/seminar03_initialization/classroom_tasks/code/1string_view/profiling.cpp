/*
    Сравнение производительность std::string и char* 

    Чтобы измерять время используем объект AutoProfiler, который засекает время в конструкторе
    и замеряет и печатает время в деструкторе.
*/


#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "miptstring.hpp"
using namespace std::chrono_literals;
using std::cout, std::cin, std::endl;

class AutoProfiler 
{
public:
    AutoProfiler(std::string name)
        : m_name(std::move(name)),
        m_beg(std::chrono::high_resolution_clock::now()) 
    {}

    ~AutoProfiler() 
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - m_beg);
        std::cout << m_name << " : " << dur.count() << " musec\n";
    }
private:
    std::string m_name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;
};



size_t sumc(const char* s, size_t size)
{
    size_t result = 0;

    for (int i = 0; i < size; ++i)
        result += s[i];

    return result;
}

size_t sum(const std::string& s)
{
    size_t result = 0;

    for (int i = 0; i < s.size(); ++i)
        result += s[i];

    return result;
}


size_t summs(const mipt::String& s)
{
    size_t result = 0;

    for (int i = 0; i < s.getSize(); ++i)
        result += s[i];

    return result;
}





const size_t iters = 100;


#define TESTSTR "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed imperdiet dolor eu velit gravida iaculis."


int main()
{   
    {
        AutoProfiler p("none");
        char a[] = TESTSTR;
        cout << sumc(a, sizeof(a)) << endl;
        mipt::String b = TESTSTR;
        cout << summs(b) << endl;
        std::string c = TESTSTR;
        cout << sum(c) << endl;
    }




    {
        AutoProfiler p("std::string");
        std::string s = TESTSTR;
        size_t result = 0;
        result += sum(s);
        result += sum(s);
        result += sum(s);
        cout << result << endl;
    }

    {
        AutoProfiler p("mipt::String");
        mipt::String s = TESTSTR;
        cout << summs(s) << endl;
    }
    {
        AutoProfiler p("char*");
        char s[] = TESTSTR;
        cout << sumc(s, sizeof(s)) << endl;
    }
}


/*
    1)  Протестируйте скорость работы этих функций без оптимизаций и с оптимизациями (-O3).

    2)  Протестируйте скорость работы для строк разной длины.
        В частности для пустой строки "".


*/