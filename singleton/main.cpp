#include "singleton.h"
#include <thread>
#include <iostream>

void ThreadOne()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* Singleton = Singleton::getInstance("[ThreadOne] - I am thread one!");
    std::cout << Singleton->getValue() << "\n";
}

void ThreadTwo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* Singleton = Singleton::getInstance("[ThreadTwo] - I am thread two!");
    std::cout << Singleton->getValue() << "\n";
}

int main()
{
    std::cout << "Two threads are defined and running. You should only see output from one thread." << std::endl;

    std::thread t1(ThreadOne);
    std::thread t2(ThreadTwo);
    t1.join();
    t2.join();

    return 0;
}