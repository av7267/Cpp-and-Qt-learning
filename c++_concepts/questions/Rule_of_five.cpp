#include <iostream>

using namespace std;


class DynamicArray{

    private:
    int* data;
    size_t size;

    public:
    DynamicArray(size_t s = 0) //constructor
    {
        size = s;
        data = new int[size]();

    }

    DynamicArray(const DynamicArray& other) //copy constructor
    {
        size = other.size;
        data = new int[size];

        std::copy(other.data,other.data + size,data);  //copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
    }

    DynamicArray& operator =(const DynamicArray& other) //copy assignment
    {
        if(this != &other)
        {
            delete[] data;
            
            size = other.size;
            data = new int[size];   
        }
        
        return *this;
    }

   
    DynamicArray(DynamicArray&& other) //move constructor
    { 
        data = other.data;
        size = other.size;

        other.size = 0;
        other.data = nullptr;
    }


    DynamicArray& operator =(DynamicArray&& other) //move assignment 
    {
        if(this != &other)
        {
            delete[] data;

            data = other.data;
            size = other.size;

            other.size = 0;
            other.data = nullptr;
        }

        return *this;
    }

    int& operator[](size_t index)
    {
        return data[index];
    }

    size_t getSize()
    {
        return size;
    }

    void print()
    {
        for(int i=0;i<size;i++)
        {
           cout << data[i] << "\n";
        }
        cout << endl;
    }

};


int main()
{
    DynamicArray a(5);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    cout << "a: ";
    a.print();

    // Copy constructor
    DynamicArray b = a;

    cout << "b after copy: ";
    b.print();

    // Prove deep copy
    b[0] = 999;

    cout << "a after modifying b: ";
    a.print();

    cout << "b after modifying b: ";
    b.print();

    // Move constructor
    DynamicArray c = std::move(a);

    cout << "c after move: ";
    c.print();

    cout << "a size after move: "
         << a.getSize() << endl;

    // Copy assignment
    DynamicArray d(2);

    d[0] = 100;
    d[1] = 200;

    d = b;

    cout << "d after copy assignment: ";
    d.print();

    // Move assignment
    d = std::move(c);

    cout << "d after move assignment: ";
    d.print();

    cout << "c size after move: "<< c.getSize() << endl;

    return 0;
}