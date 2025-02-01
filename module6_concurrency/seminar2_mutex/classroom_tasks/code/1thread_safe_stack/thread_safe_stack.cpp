#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <stack>


template <typename T>
class ThreadSafeStack
{
private:

    std::stack<T> mData;
    std::mutex mMutex;

public:

    void push(const T& elem)
    {
        std::lock_guard lk(mMutex);
        mData.push(elem);
    }

    std::shared_ptr<T> tryPop()
    {
        std::lock_guard lk(mMutex);

        if (mData.empty())
        {
            return std::shared_ptr<T>();
        }

        std::shared_ptr<T> result = std::make_shared<T>(mData.top());
        mData.pop();

        return result;
    }
};



ThreadSafeStack<int> s;



void func1()
{
    for (int i = 0; i < 10'000; ++i)
    {
        s.push(i);
    }
}


void func2()
{
    for (int i = 0; i < 10'000; ++i)
    {
        auto p = s.tryPop();
        if (p)
        {
            std::cout << *p << '\n';
        }
        else
        {
            std::cout << "Stack is empty!\n";
        }
    }
}




int main()
{
    std::thread t2(func2);
    std::thread t1(func1);

    t1.join();
    t2.join();
}