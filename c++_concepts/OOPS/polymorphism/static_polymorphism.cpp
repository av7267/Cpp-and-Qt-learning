#include <iostream>
using namespace std;



// 1.Static Polymorphism(Compile time) [method overloading, operator overloading]

//Function Overloading : Overloading the methods with different parameters with the same name.

class FunctionOverloading
{
    public:

    int Add()
    {
        return 0;
    }
    int Add(int a)
    {
        return a;
    }

    int Add(int a, int b)
    {
        return a+b;
    }

    int Add(int a, int b,int c)
    {
        return a+b+c;
    }
};

//Operator Overloading : redefining the standard operators from c++

class Box
{
    int length;
    int breadth;

    public:

    Box(int l, int b) : length(l),breadth(b)
    {}

    Box operator +(const Box& obj )
    {
        cout << "Operator called\n";
        return Box(length + obj.length,
                    breadth + obj.breadth);

    }

    friend ostream& operator<<(ostream& os,const Box& b) //we tell the compiler when cout is called this method comes into action for this particular class
    {
        os << "length:" << b.length << " | breadth:" << b.breadth;
        return os;
    }
    
};

int main()
{
    FunctionOverloading fo;
    fo.Add();
    fo.Add(4);
    fo.Add(4,5,6);

    Box b1(4,5);
    Box b2(7,8);

    Box b3 = b1+b2;

    cout << b3;

    return 0;
};

