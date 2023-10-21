/*
    Функция, возвращающая имя типа выражения

    Функция getTypeName, совместно с decltype, позволяет узнать имя типа выражения.
    У этой функции только один шаблонный параметр, через который функция принимает некоторый тип.
    Функция возвращает строку - название этого типа.

    Применять так:

        getTypeName<тип>()

    или так:

        getTypeName<decltype(выражение)>()


    Очень полезная функция при изучении C++ так как позволяет увидеть настоящий тип выражения.
    Не всегда просто понять какой у выражения настоящий тип из-за неявного приведения, сининимов типов (typedef-ов),
    скрытых шаблонных параметров.
    Например, тип std::size_t является сининимом для одного из встроенных типов.
    А у класса std::vector есть один скрытый шаблонный параметр (аллокатор).

    Функция различает lvalue и rvalue ссылки, а также квалификатор const.
*/


#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string getTypeName()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own(
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r = "const " + r;
    if (std::is_volatile<TR>::value)
        r = "volatile " + r;
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}



#include <iostream>
#include <vector>
using std::cout, std::endl;

int main()
{
    int a = 100;
    cout << getTypeName<int>() << endl;
    cout << getTypeName<decltype(200)>() << endl;
    cout << getTypeName<decltype(a)>() << endl;
    cout << getTypeName<decltype(a + 1.5)>() << endl;
    cout << getTypeName<std::size_t>() << endl;


    cout << endl;


    int& r = a;
    cout << getTypeName<decltype(r)>() << endl;
    cout << getTypeName<decltype(std::move(r))>() << endl;


    cout << endl;


    std::vector<std::pair<int, float>> v;
    cout << getTypeName<decltype(v)>() << endl;
    cout << getTypeName<decltype(v.begin())>() << endl;
}