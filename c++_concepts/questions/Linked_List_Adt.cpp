#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList{

private:
    Node<T>* head;

public:

    LinkedList() : head(nullptr)
    {
        
    }

    ~LinkedList()
    {
        Node<T>* curr = head;
        while (curr != nullptr)
        {
            Node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void push_back(T data) 
    {
        Node<T>* newNode = new Node<T>(data);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T>* curr = head;
        while(curr -> next != nullptr)
        {
            curr = curr -> next;
        }

        curr -> next = newNode;
    }

    Node<T> push_front(T data) 
    {
        Node<T>* newNode = new Node<T>(data);
        newNode -> next = head;
        head = newNode;
    }

    Node<T> pop_front() 
    {
        Node<T>* temp = head;
        head = head -> next;
        delete temp;
    }

    void pop_back() 
    {
        if(head -> next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* curr = head;

        while(curr -> next->next != nullptr)
        {
            curr = curr -> next;
        }

        delete curr -> next;
        curr -> next = nullptr;
    }

    void print()
    {
        Node<T>* curr = head;

        while(curr-> next != nullptr)
        {
            cout << curr->data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }

    int size() { 

        int count = 0;

        Node<T>*curr = head;
    
        while(curr != nullptr)
        {
            count++;
            curr = curr -> next; 
        }
        return count;       
    }


    bool empty() { 
        return head == nullptr; 
    }

    bool contains(T& data) 
    {
       
        Node<T>* curr = head;

        while(curr -> next != nullptr)
        {
            if(curr -> data == data)
            {
                return true;
            }
            curr = curr -> next;
        }
        return false;
    }

    void remove(T data) {
        

        if(head == nullptr)
        {
            return;
        }

        if(head->data == data)
        {
            pop_front();
            return;
        }

        Node<T>* curr = head;

        while(curr-> next != nullptr)
        {
            if(curr-> next -> data == data)
            {
                Node<T>* temp = curr ->next;
                curr -> next = temp -> next;
                delete temp;
                return;
            }

            curr = curr -> next;
        }
    }


    LinkedList(const LinkedList& other)   //copy constructor
    {
        head = nullptr;

        Node<T>* curr = other.head;
        while(curr != nullptr)
        {
            push_back(curr -> data);
            curr = curr -> next;
        }
    }

    LinkedList& operator=(const LinkedList& other) //copy assignment
    {
        if (this != &other)
        {
            Node<T>* curr = head;
            while (curr != nullptr)
            {
                Node<T>* temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = nullptr;
            curr = other.head;
            while (curr != nullptr)
            {
                push_back(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }


    LinkedList(LinkedList&& other) //move constructor 
    {
        head = other.head;
        other.head = nullptr;
    }

    LinkedList& operator = (LinkedList&& other) //move assignment
    {
        if(this != &other)
        {
            Node<T>* curr = head;
            while(curr != nullptr)
            {
                Node<T>* temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = other.head;

            other.head = nullptr;
        }

        return *this;
    }

};

int main()
{
    // -----------------------------------------
    // Test 1: Basic insertion
    // -----------------------------------------

    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    cout << "List: ";
    list.print();

    cout << "Size: " << list.size() << endl;


    // -----------------------------------------
    // Test 2: Insert at front
    // -----------------------------------------

    list.push_front(5);

    cout << "After push_front: ";
    list.print();


    // -----------------------------------------
    // Test 3: Remove from front
    // -----------------------------------------

    list.pop_front();

    cout << "After pop_front: ";
    list.print();


    // -----------------------------------------
    // Test 4: Remove from back
    // -----------------------------------------

    list.pop_back();

    cout << "After pop_back: ";
    list.print();


    // -----------------------------------------
    // Test 5: Copy constructor
    // -----------------------------------------

    LinkedList<int> copy = list;

    cout << "Original: ";
    list.print();

    cout << "Copy: ";
    copy.print();

    copy.push_back(100);

    cout << "Original after modifying copy: ";
    list.print();

    cout << "Copy after modification: ";
    copy.print();


    // -----------------------------------------
    // Test 6: Copy assignment
    // -----------------------------------------

    LinkedList<int> assigned;

    assigned.push_back(999);
    assigned.push_back(888);

    assigned = list;

    cout << "Assigned list: ";
    assigned.print();


    // -----------------------------------------
    // Test 7: Self assignment
    // -----------------------------------------

    assigned = assigned;

    cout << "After self assignment: ";
    assigned.print();


    // -----------------------------------------
    // Test 8: Move constructor
    // -----------------------------------------

    LinkedList<int> moved = std::move(list);

    cout << "Moved list: ";
    moved.print();

    cout << "Original size after move: "
         << list.size() << endl;


    // -----------------------------------------
    // Test 9: Move assignment
    // -----------------------------------------

    LinkedList<int> moveAssigned;

    moveAssigned.push_back(500);
    moveAssigned.push_back(600);

    moveAssigned = std::move(moved);

    cout << "Move assigned list: ";
    moveAssigned.print();

    cout << "Moved-from list size: "
         << moved.size() << endl;


    // -----------------------------------------
    // Test 11: String template
    // -----------------------------------------

    LinkedList<string> names;

    names.push_back("Arnav");
    names.push_back("Rahul");
    names.push_back("John");

    cout << "Names: ";
    names.print();

    names.push_front("David");

    cout << "Names after push_front: ";
    names.print();

    return 0;
}