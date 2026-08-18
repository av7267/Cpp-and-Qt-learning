#include <iostream>

using namespace std;

//Constructor delegation is essentially one constructor forwarding the construction work to another constructor of the same class.


class Person{

    public:
    string name;
    int age;
    string city;

    Person() : Person("Unknown", 0, "Unknown") //calls the 3 parameter constructor
    {

    }

    Person(string name): Person(name, 0 , "unknown")
    {
        
    }
    
    Person(string name,int age) : Person(name,age,"Unknown")
    {
        
    }

    Person(string name, int age ,string city) : name(name),age(age),city(city)
    {
        this -> age = age;
        this -> name = name;
        this->city = city;
    }

    void print()
    {
        cout << name << "\n";
        cout << age << "\n";
        cout << city << "\n";
    }
};

int main()
{
    Person p1;
    Person p2("Arnav");
    Person p3("Arnav", 25, "Hyderabad");

    p1.print();
    p2.print();
    p3.print();


    /*

    p1 created
        ↓
    Person()
        ↓ delegates to
    Person("Unknown", 0, "Unknown")
        ↓
    name = "Unknown"
    age = 0
    city = "Unknown"
        ↓
    3-argument constructor body finishes
        ↓
    p1 is completely constructed



    p2 created
        ↓
    Person("Arnav")
        ↓ delegates to
    Person("Arnav", 0, "unknown")
        ↓
    name = "Arnav"
    age = 0
    city = "unknown"
        ↓
    3-argument constructor body
        ↓
    returns to
    Person("Arnav") body
        ↓
    p2 completely constructed


    p3 created
    ↓
    Person("Arnav", 25, "Hyderabad")
    ↓
    name initialized
    age initialized
    city initialized
    ↓
    constructor body executes
    ↓
    p3 completely constructed
    
    */

    return 0;
}