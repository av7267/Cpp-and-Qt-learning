#include <iostream>
using namespace std;


class Base
{
    public:
    virtual void base()
    {
        cout << "Base\n";
    }
};

class child : public Base
{
    public:
    void base() override
    {
        cout << "child\n";
    }
    void display()
    {
        cout << "Derived\n";
    }
};

//Casting

int main()
{
    //Implicit casting : There is no data loss, smaller type -> larger type
    
    int p = 3; 
    double pi =  p; //converted int to double

    char s = 'A'; //ascii value of A is 65
    int n = s + 5; //adding the ascii value of A, 65+5 = 70.

    cout <<pi << "\n";
    cout << n << "\n";

  
    //Explicit casting : used when you want to force or specify a conversion explicitly.

    //1. static casting  : preffered method for ordinary type conversions because it provides compile-time type safety by telling the compiler that you need to do this conversion
    
    double x = 10.25;
    int y = static_cast<int>(x); //specifically forcing the casting.


    //2. dynamic casting : this is about casting between classes in a inheritance hierarchy (downcasting)

    Base* b = new child(); //the parent ptr is holding the child object 
    child* c = dynamic_cast<child*>(b); //the child ptr is forcing to cast to access the child specific methods.

    b -> base();    //this works on the child method as the base is referencing to the child object.
    c -> display(); //we can access the child specific methods with the help of casting.

    //3. const casting : const_cast is used to convert between const and non-const pointers or references.

    const int r = 10;
    const int* remove_ptr = &r;
    int* rp = const_cast<int*>(remove_ptr); //removing the const


    int z = 10;
    int* add_ptr = &z;
    const int* ap = const_cast<const int*>(add_ptr); //adding the const
    




}





