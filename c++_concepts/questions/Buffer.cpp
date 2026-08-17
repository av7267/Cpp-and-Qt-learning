#include <iostream>

using namespace std;


class Buffer
{
    private:
    int* arr;
    int size;

    public:
    Buffer(int size) //constructor
    {
        arr = new int[size]();
    }

    ~Buffer() //destructor
    {
        delete[] arr;
    }

    Buffer(const Buffer& other) //copy constructor
    {
        arr = new int[*other.arr]; //deep copy
    }

    Buffer& operator =(const Buffer& other) //copy assignment
    {
        if(this != &other) //comparing the current object reference to the new object reference if not equal then 
        {
            delete[] arr;
            size = other.size;
            arr = new int(other.size); //deep copy

            copy(other.arr, other.arr + size, arr);
        }

        return *this; //store the current reference of the object in the operator and return *this as the answer when given the output
    }

    Buffer(Buffer&& other) //move constructor
    {
        arr = other.arr;
        size = other.size;
        other.arr = nullptr;
        other.size = 0;

    }

    Buffer& operator =(Buffer&& other) //move assignement
    {
        if(this != &other)
        {
            delete[] arr;
            arr = new int[*other.arr];
            other.arr = nullptr;
        }

        return *this;
    }

    int& operator[](int index)
    {
        return arr[index];
    }

    

};
int main()

{

    Buffer a(5);

    a[0] = 10;
    a[1] = 20;

    // Copy Constructor
    Buffer b = a;

    // Move Constructor
    Buffer c = std::move(a);
    
    // Copy Assignment
    Buffer d(2);
    d = b;
  
    // Move Assignment
    d = std::move(c);

    return 0;

}