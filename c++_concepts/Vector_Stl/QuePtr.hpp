#include <iostream>
#include <utility>

using namespace std;


template<typename T>
class QuePtr{

    private:
    T* ptr;

    public:

    QuePtr(T* p = nullptr) : ptr(p)
    {
    }

    ~QuePtr()
    {
        delete[] ptr;
    }

    //Copy constructor
    QuePtr(const QuePtr& other) = delete;

    //Delete Copy assignment constructor
    QuePtr& operator = (const QuePtr& other) = delete;

    //Move Constructor
    QuePtr(QuePtr&& other)
    {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    //Move Assignment 
    QuePtr& operator = (QuePtr&& other)
    {
        if(this != &other)
        {
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator[](int index)
    {
        return ptr[index];
    }

};

