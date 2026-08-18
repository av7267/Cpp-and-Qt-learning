#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
private:
    T* data;
    size_t capacity;
    size_t topIndex;

public:
    Stack(size_t capacity): capacity(capacity), topIndex(0)
    {
        data = new T[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(const T& value)
    {
        if (full())
        {
            throw overflow_error("Stack is full");
        }

        data[topIndex] = value;
        topIndex++;
    }

    void pop()
    {
        if (empty())
        {
            throw underflow_error("Stack is empty");
        }

        topIndex--;
    }

    T& top()
    {
        if (empty())
        {
            throw underflow_error("Stack is empty");
        }

        return data[topIndex - 1];
    }

    bool empty() const
    {
        return topIndex == 0;
    }

    bool full() const
    {
        return topIndex == capacity;
    }

    size_t size() const
    {
        return topIndex;
    }


    Stack(const Stack& other) //copy constructor
    {
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = new T[capacity];
        for (size_t i = 0; i < topIndex; i++)
        {
            data[i] = other.data[i];
        }
    }


    Stack& operator =(const Stack& other)
    {
        if(this != &other)
        {
            delete[] data;

            capacity = other.capacity;
            topIndex = other.topIndex;
            data = new T[capacity];
            for (size_t i = 0; i < topIndex; i++)
            {
                data[i] = other.data[i];
            }

            return *this;
        }
    }


    Stack(Stack&& other)    //move constructor
    {
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = other.data;
        other.data = nullptr;
        other.capacity = 0;
        other.topIndex = 0;
    } 

    Stack& operator=(Stack&& other)
    {
        if(this != &other)
        {
            delete[] data;
            capacity = other.capacity;
            topIndex = other.topIndex;
            data = other.data;
            other.data = nullptr;
            other.capacity = 0;
            other.topIndex = 0;
        }

        return *this;
    }
};

int main()
{
    Stack<int> s(5);

    cout << "Empty: " << s.empty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    Stack<int> b = s; //copy constructor

    Stack<int> c(10); //copy assignment operator
    c.push(100);
    c.push(200);
    c = s;


    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;
    cout << "Size after pop: " << s.size() << endl;

    Stack<int> d = std::move(s); //Move constructor

    Stack<int> e(2);    //Move assignment operator
    e.push(999);
    e = std::move(d);


    Stack<string> names(3);

    names.push("Arnav");
    names.push("Rahul");
    names.push("John");

    cout << names.top() << endl;

    names.pop();

    cout << names.top() << endl;

}