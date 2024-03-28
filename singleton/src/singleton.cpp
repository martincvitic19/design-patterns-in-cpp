#include "singleton.h"
#include <iostream>
#include <string>
#include <mutex>

/**
 * @brief The Singleton's constructor should always be private
 * to prevent direct construction calls with the "new" operator.
 * 
 */
Singleton::Singleton(const std::string value)
    :_value(value)
{

}

/**
 * @brief
 * 
 */
Singleton::~Singleton()
{

}

/**
 * @brief Example of some business logic that the
 * Singleton implements.
 * 
 */
void Singleton::printFromSingleton() const
{
    std::cout << "Hello from Singleton!" << std::endl;
}

Singleton* Singleton::_singletonInstance{nullptr};
std::mutex Singleton::_mutex;

std::string Singleton::getValue() const
{
    return _value;
}
/**
 * @brief The first time this nethod is called, it will lock storage location and then
 * make sure. This is done to prevent a situation where multiple threads can 
 * call the creation method simultaneously and get several instances of Singleton class.
 * 
 */
Singleton* Singleton::getInstance(const std::string& value) 
{
    std::lock_guard<std::mutex> lock(_mutex);
    if(_singletonInstance==nullptr)
    {
        _singletonInstance = new Singleton(value);
    }

    return _singletonInstance;
}
