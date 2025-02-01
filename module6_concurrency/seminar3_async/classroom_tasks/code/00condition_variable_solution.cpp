#include <iostream>
#include <thread>
#include <queue>
#include <string>
#include <chrono>
#include <random>
#include <mutex>
#include <condition_variable>
using std::cout, std::endl;

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1'000'000);



std::queue<int> q;
std::mutex m;
std::condition_variable cv;


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
            cv.notify_one();
        }
        k++;

        doWork(10);
    }
}


void reciever()
{
    while (true)
    {
        bool isEmpty = false;
        int number;

        {
            std::unique_lock lk(m);

            cv.wait(lk, [](){return !q.empty();});
            number = q.front();
            q.pop();
        }

        cout << "Got number from the queue: " << number << endl;

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