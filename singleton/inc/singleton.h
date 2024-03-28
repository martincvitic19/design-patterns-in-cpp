#include <iostream>
#include <string>
#include <mutex>

class Singleton
{
protected:
    /**
     * @brief Construct a new Singleton object.
     * 
     * @param value 
     */
    Singleton(const std::string value);

    /**
     * @brief Destroy the Singleton object.
     * 
     */
    ~Singleton();

    /**
     * @brief Private values that Singleton can store into.
     * 
     */
    std::string _value;

private:
    /**
     * @brief A single instance of Singleton that clients will have access to.
     * 
     */
    static Singleton* _singletonInstance;

    /**
     * @brief A mutex class used to prevent creating two Singleton instances if such
     * request arises simultaneously.
     * 
     */
    static std::mutex _mutex;

public:
    /**
     * @brief Destroy the object created with "new" keyword 
     * (created in Singleton::getInstance(const std::string& value)) by
     * deallocating the memory associated with the object. The "= delete" prohibits
     * copying (introduced in C++11).
     * 
     * @param other 
     */
    Singleton(Singleton& other) = delete;
    /**
     * @brief Prohibit assigments since Singletons should not be assignable.
     * The "= delete" specifier is used to explicitly delete the automatically
     * generated copy assignment operator for that class.
     * By doing so, the assignment operation is prohibited for objects of 
     * the Singleton class.
     * 
     */
    void operator=(const Singleton&) = delete;

    /**
     * @brief Get the Instance object. This method serves as
     * an alternative to the constructor and controls the access
     * to the singleton instance.
     * 
     * @param value 
     * @return Singleton* 
     */
    static Singleton* getInstance(const std::string& value);

    /**
     * @brief Getter function to obtain a Singleton's private string.
     * 
     * @return std::string 
     */
    std::string getValue() const;

    /**
     * @brief Arbitrary method that implemets business logic.
     * 
     */
    void printFromSingleton() const;
};