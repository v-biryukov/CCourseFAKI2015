#include <iostream>
#include <thread>
#include <queue>
#include <string>
#include <chrono>
#include <random>
#include <mutex>
using std::cout, std::endl;

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1'000'000);



std::queue<int> q;
std::mutex m;


void doWork(int n)
{
    std::this_thread::sleep_for(std::chrono::microseconds(dist(rng)) * n);
}   


void sender()
{
    int k = 0;
    while (true)
    {
        {
            std::lock_guard lk(m);
            q.push(k);
        }
        k++;

        doWork(5);
    }
}


void reciever()
{
    while (true)
    {
        bool isEmpty = false;
        int number;

        {
            std::lock_guard lk(m);

            if (q.empty())
            {
                isEmpty = true;
                
            }
            else
            {
                number = q.front();
                q.pop();
                
            }
        }

        if (isEmpty)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "Got number from the queue: " << number << endl;
        }

        doWork(1);
    }
}





int main()
{
    std::thread s(sender);
    std::thread r(reciever);



    s.join();
    r.join();
}