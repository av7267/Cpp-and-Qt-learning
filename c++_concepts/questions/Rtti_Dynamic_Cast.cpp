#include <iostream>

using namespace std;

class Animal{

    public:

    string name;

    Animal(string name)
    {
        this -> name = name;
    }

    virtual void Speak() = 0;

};

class Dog : public Animal{

    public:
    Dog(string name) : Animal(name){}

    virtual void Speak() override
    {
        cout << name <<" barks\n"<<endl;
    }

    void Details()
    {
        cout << "the dogs name is " << name << endl;
    }
};

class Cat : public Animal{

    public:

    Cat(string name) : Animal(name){}

    virtual void Speak() override
    {
        cout << name << " meowss" << endl;
    }

};
int main()
{
    Animal* a = new Dog("Jimmy");  //dynamically object creation with the parent class reference to the child class object
    Dog* d = dynamic_cast<Dog*>(a); //to access the child specific method by downcasting the pointer to the child class object.
    d->Details(); //child specific method
    a->Speak();
    
}