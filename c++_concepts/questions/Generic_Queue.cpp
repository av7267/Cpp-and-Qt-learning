#include<iostream>

using namespace std;
template<typename T>
class Queue{
    private:

    T* data;
    size_t capacity;
    size_t frontIndex;
    size_t rearIndex;
    size_t count;
    
    public:
    
    Queue(size_t capacity)
    {
        this -> capacity = capacity;
        data = new T[capacity];

        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    void enqueue(T value)
    {
       
        if(count == capacity)
        {
            return;
        }
        data[rearIndex] = value;
        rearIndex = (rearIndex+1) % capacity;
        count++;

    }

    void dequeue()
    {  
        if (count == 0)
        {
            throw runtime_error("Queue is empty");
        }

        frontIndex = (frontIndex +1) % capacity; 
        count--;
    }

    void print()
    {
        for (size_t i = 0; i < count; i++)
        {
            size_t index = (frontIndex + i) % capacity;
            cout << data[index] << " ";
        }
        cout << endl;
    }

    T& front()    //Return a reference to the actual element stored at the front of the queue.
    {
        return data[frontIndex];
    }

    ~Queue()
    {
        delete[] data;
    }

    size_t size()
    {
        return count;
    }

    Queue(const Queue& other) //copy constructor
    {
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        count = other.count;

        data = new T[capacity];

        for(size_t i=0;i < count ; i++)
        {
            data[i] = other.data[i];
        }
    }

    Queue& operator =(Queue& other) //copy assignment
    {
        if(this != &other)
        {

            T* newdata = new T[other.capacity];

            for(size_t i =0;i<other.capacity; i++)
            {
                newdata[i] = other.data[i];
            }

            delete[] data;

            capacity = other.capacity;
            frontIndex = other.frontIndex;
            rearIndex = other.rearIndex;
            count = other.count;

            
        }
        return *this;
    }

    Queue(Queue&& other) //move constructor
    {
        capacity = other.capacity;
        data = other.data;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        count = other.count;

        other.capacity = 0;
        other.frontIndex = 0;
        other.count = 0;
        other.rearIndex = 0;
        other.data = nullptr;
    }

    Queue& operator=(Queue&& other) //move assignment
    {
        if(this != &other)
        {
            delete[] data;

            capacity = other.capacity;
            data = other.data;
            frontIndex = other.frontIndex;
            rearIndex = other.rearIndex;
            count = other.count;

            other.capacity = 0;
            other.data = nullptr;
            other.frontIndex = 0;
            other.rearIndex = 0;
            other.count = 0;

        }

        return *this;
    }
};


int main()
{
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.print();

    cout << "Front: " << q.front() << endl;

    cout << "Size: "
         << q.size() << endl;


    q.dequeue();

    cout << "After dequeue: ";

    q.print();

    cout << "Front: " << q.front() << endl;

    
    Queue<int> a(5);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);

    Queue<int> b = a;
    cout << "Original: ";
    a.print();

    cout << "Copy: ";
    b.print();

    // ========================================
    // Test 7: Copy Assignment
    // ========================================
    
    Queue<int> c(10);
    c.enqueue(999);
    c = a;
    cout << "Copy assigned: ";
    c.print();
    c = c;
    cout << "After self assignment: ";
    c.print();
    
    // ========================================
    // Test 8: Move Constructor
    // ========================================
    
    Queue<int> moved = std::move(a);
    cout << "Moved queue: ";
    moved.print();
    cout << "Original size after move: " << a.size() << endl;
    
    // ========================================
    // Test 9: Move Assignment
    // ========================================
    
    Queue<int> moveAssigned(3);
    moveAssigned.enqueue(500);
    moveAssigned.enqueue(600);
    moveAssigned = std::move(moved);
    
    cout << "Move assigned queue: ";
    moveAssigned.print();
    cout << "Moved-from size: " << moved.size() << endl;



}