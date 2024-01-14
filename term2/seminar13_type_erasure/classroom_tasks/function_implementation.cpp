#include <iostream>
using std::cout, std::endl;


template <typename T>
class Function;


template <typename Ret, typename... Args>
class Function<Ret(Args...)>
{
private:

    struct BaseStorage
    {

        virtual Ret call(Args&&... args) = 0;

        virtual ~BaseStorage() = default;
    };

    template <typename Func>
    struct Storage : public BaseStorage
    {
        template <typename T>
        Storage(T&& af) : f(af) {}

        Func f;

        Ret call(Args&&... args) override
        {
            return f(std::forward<Args>(args)...);
        }

        ~Storage() override = default;
    };


    BaseStorage* mpStorage;

public:

    template <typename Func>
    Function(Func&& f)
    {
        mpStorage = new Storage<Func>(f);
    }

    ~Function()
    {
        delete mpStorage;
    }

    template <typename Func>
    void operator=(Func&& f)
    {
        delete mpStorage;
        mpStorage = new Storage<Func>(f);
    }

    Ret operator()(Args... args)
    {
        return mpStorage->call(std::forward<Args>(args)...);
    }
};


template <typename T>
struct Signature{};

template <typename T, typename Ret, typename... Args>
struct Signature<Ret (T::*)(Args...)>
{
    using type = Ret(Args...);
};


template <typename F>
Function(F&& f) -> Function<typename Signature<decltype(&F::operator())>::type>;



int foo(int a, int b)
{
    return a + b;
}

int bar(int a, int b)
{
    return a * b;
}


class Functor
{
public:

    int operator()(int a, int b)
    {
        return a / b;
    }

};




int main()
{
    Function<int(int, int)> f(foo);

    cout << f(10, 20) << endl;

    f = bar;

    cout << f(10, 20) << endl;

    f = [](int a, int b) {return a + 1 + b;};

    cout << f(10, 20) << endl;

    f = Functor{};

    cout << f(100, 20) << endl;
}