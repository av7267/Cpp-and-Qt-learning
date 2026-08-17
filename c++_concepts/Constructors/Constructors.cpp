#include <iostream>
using namespace std;
 


//default Constructor : it is a constructor that is called when an object of the class is created without any arguments.
class Delta2{
    public:
    int length = {4};

    Delta2() = default;
};


//Parameterised Constructor : it is a constructor that takes parameters to initialize an object of the class.
class Delta3
{
    public:
    int len;
    int hgt;

    Delta3(int length,int height) : len(length), hgt(height)
    {}
};


//Copy constructor : we could create a duplicate copy of an object using copy constructor.
class Delta1
{
    public:
    int* length;
    int* breadth;

    //copies the data of the obj parameter which does a deep copy because we explitly write the copy contructor
    Delta1(int len, int bre)
    {
        //heap objects
        length = new int(len); 
        breadth = new int(bre);
    } 

    //this is not deep copy its a shallow copy
    Delta1 (const Delta1& other) //we use const because copying should not modify the original value
    {
        //stack object creation
        length = other.length;
        breadth = other.breadth;
    }

   
};


//Copy Assignment operator

class Delta5
{
    int* age;

public:
    Delta5& operator=(const Delta5& other)
    {
        if(this != &other)
        {
            delete age; 
            age = new int(*other.age); //deep copy
        }
    
        return *this;
    }
};



//move constructor  : it transfers the resources of an existing object to a new object, leaving the existing object in a valid but unspecified state.
class Delta4
{
    public:
    int* data;

    Delta4(int value)
    {
        data = new int(value);
    }

    Delta4(Delta4&& other) //&& is called an rvalue reference.
    {
        data = other.data; 
        other.data = nullptr; //delete the older value
    }

    ~Delta4()
    {
        delete data;    //Destroy the resource owned by this object.
    }
};

//Move Assignment 
class Delta6
{
    int *rollno;
   
    public:
    Delta6(int value)
    {
        rollno = new int(value);
    }

    Delta6& operator=(Delta6&& other)
    {
        if(this != &other)
        {
            delete rollno;
        }
        rollno = other.rollno; //take ownership 
        other.rollno = nullptr; //remove ownership

        return *this;
    }

    ~Delta6()
    {
        delete rollno;
    }
};


int main()
{

    //Default constructor
    Delta2 d2;

    //Parameterised Constructor
    Delta3 d3(4,9);

    //copy constructor
    Delta1 d1(10,4);
    Delta1 d11 = d1;

    //Copy Assignement
    Delta5 d4;
    Delta5 d5;
    d4 = d5;

    //Move Constructor
    Delta4 a(10); //initialse the object 
    Delta4 b = std::move(a);

    //Move Assignment operator
    Delta6 x(20);
    Delta6 y(30);
    y = std::move(x); //y takes the ownership of x and this calls the move assignment operator as y already exists.

}