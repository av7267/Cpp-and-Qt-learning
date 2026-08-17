#include <iostream>

using namespace std;


class Student //having the pure virtual function in this class makes it abstract
{
    protected:
        string name;
    
    public:
        Student(string name) :name(name)
        {}
    
    public: 
        virtual ~Student() //this is required to write because compiler doesnt create a virtual destructor implicitly 
        {}
    
        virtual void display() = 0; //assigning to 0 makes this function a pure virtual function, making the class abstract
};


class Arnav : public Student 
{
public:
    Arnav(string n) : Student(n)
    {}

    ~Arnav()  //this is not required to write
    {}

    void display() override      //for a pure virtual function you must ovveride the method in the child class.
    {
        cout << "Hello, I am " << name << endl;
    }

};



/*In C++ Functions can exist outside classes (global/free functions), 
so main() is simply a global function that the operating system calls when the program starts.
This is why it doesn’t need public or static. */

int main()
{
    //You only use new when you explicitly need a heap-allocated object. If you omit new, the object is created on the stack

    Arnav a("Arnav"); //Object creation for the child class in Stack.
    a.display(); //Accessing the child class method

    Student* st = new Arnav("Anvi"); //Object creation being done as the parent reference is being pointed out to the child class object where the virtual function plays the primary role in this polymorphism.
    st->display();   // goes to the base class display() method and then gets overrides in the child class
   
    delete st; // Release heap memory and also calls the virtual destructor in the parent class cause we are doing the runtime polymorphism.

}

