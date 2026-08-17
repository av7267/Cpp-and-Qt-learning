#include <iostream>
#include<utility>

using namespace std;



template<typename T>
class Arnavptr
{
    private:
    T* ptr;

    public:

Arnavptr(T* p = nullptr) : ptr(p)
{

}
    ~Arnavptr()
    {
        delete ptr;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    T* Get()
    {
        return ptr;
    }

    //Delete copy constructor
    Arnavptr(const Arnavptr& other) = delete;

    //Delete copy assignment
    Arnavptr& operator =(const Arnavptr& other) = delete;

    //Move constructor
    Arnavptr(Arnavptr&& other)
    {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    //Move Assignment this transfers the ownership
    Arnavptr& operator = (Arnavptr&& other)
    {
        if(this != &other)
        {
            delete ptr;

            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

};
