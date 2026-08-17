#include <iostream>
using namespace std;




class Student
{
public:
    void display()
    {
        cout << "Student display\n";
    }

    Student()
    {
        cout << "Student constructor\n";
    }
    ~Student()
    {
        cout << "Student destructor\n";
    }
};



//Using Array in unique ptr
    class Market{
        private:

        unique_ptr<int[]> data;

        Market()
        {
            data = make_unique<int[]>(10);
        }
        
    };

    //Using a single value in unique ptr
    class Single{
        private:
        unique_ptr<int> value;

        public:
        
        Single(int num)
        {
            value = make_unique<int>(num);
        }

    };

void func1 (int& num) //this function takes the reference of the values but not the actual values.
{
    cout << num;
    cout << "\n";
}

int main()
{
    //Memory management with new and delete keywords.
    //new keyword

    int* pointer;
    pointer = new int; //memory is allocated on heap and pointer is pointing to that memory location.
    *pointer = 45; //dereferencing the pointer to assign value to that memory location.

    delete pointer; //free up the memory allocated on heap.


    //References
    string city = "paris\n";
    string& ref_city = city;

    //city is the actual variable, ref_city has the reference to that variable.
    
    cout << &ref_city; //prints the reference address 
    cout << "\n";
    cout << ref_city; //prints the reference value

    //pass by reference
    int reference = 5;
    func1(reference); //passed only the reference of the variable to the function, not the actual value.



    //Pointers
    //Raw pointers= is a primitive variable type that directly stores the address of another object.

    int* a = new int(10); //allocated on heap, a stores the address
    delete a; //Free up memory

    a = nullptr; //avoid dangling pointer

    // Smart Pointers :
    // 1.unique pointer = which provides exclusive ownership of the object it points to. It cannot be copied, only moved.

    unique_ptr<int> u_ptr = make_unique<int>(10);  // u_ptr goes out of scope here -> Memory is automatically deleted


    // 2.shared_Pointer = implements shared ownership to the object it points to.

    shared_ptr<int> s_ptr = make_shared<int>(20);

    shared_ptr<int> s_ptr1 = s_ptr;  // Reference count is now 2

    // 3. Weak Pointer  =  it doesnt own any data and is only used to observe the data without referencing.

    // '.' vs '->'

    Student s1;
    s1.display(); 
    

    Student *s2 = new Student();
    s2->display();
    delete s2; //this calls the destructor of the Student class and frees up the memory allocated on heap.
    
    
}