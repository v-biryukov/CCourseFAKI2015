#include <iostream>
#include <functional>
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>
#include <ranges>

using std::cout, std::endl;


template <typename T>
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

template <typename T>
void printTypeName()
{
    std::cout << getTypeName<T>() << std::endl;
}

int main()
{
    auto a = std::ranges::views::iota(0, 10);
    auto b = std::ranges::views::drop(3);

    auto c = a | b;

    printTypeName<decltype(a)>();
    printTypeName<decltype(b)>();
    printTypeName<decltype(c)>();

    for (auto el : c)
    {
        cout << el << endl;
    }
}