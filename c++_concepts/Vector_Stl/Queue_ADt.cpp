#include<iostream>
using namespace std;

#include "QuePtr.hpp"

template<typename T>


class Queue
{
private:
    QuePtr<T> data;
    int front;
    int rear;
    int capacity;
    int size;

public:

    Queue()
    {
        front = -1;
        rear = -1;
        capacity = 10;
        data = new T[capacity];
    }

    
    void Enqueue(T value)
    {

    //if the queue is empty totally we increment f from -1 to 0 and r from -1 ro 0 and then else if queue has atleast one element then only r is being incremented 
    //in botht the cases size will be incremented by 1   

        if(IsEmpty())
        { 
            front++;
            rear++;
            data[rear] = value;
            size ++;
        }
        else
        {
            rear++;
            data[rear] = value;
            size++;
        }
    }

    void Dequeue()
    {

        //we remove the front element of the queue by incrementing the front by one position. and size gets decremented
        //if there is only one element in the  queue then both f and r becomes -1 and then size becomes equals to 0
        if(IsEmpty())
        {
            cout << "Queue already empty";
            return;
        }
        else if(size == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        size--;
    }


    T GetPeek()
    {
        if(IsEmpty())
        {
            cout << "Queue is empty";
            return T();
        }

        return data[front];
    }

    int Size()
    {
        return size;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

};


int main()
{
    Queue<int> q;

    cout << "Enqueue elements\n";

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);

    cout << "Front element: " << q.GetPeek() << endl;

    cout << "Queue size: " << q.Size() << endl;


    cout << "\nRemoving element...\n";

    q.Dequeue();

    cout << "Front element after dequeue: " << q.GetPeek() << endl;

    cout << "Queue size after dequeue: " << q.Size() << endl;


    cout << "\nRemoving remaining elements...\n";

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();


    cout << "Queue size: " << q.Size() << endl;


    if(q.IsEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue has elements" << endl;
    }


    return 0;
}