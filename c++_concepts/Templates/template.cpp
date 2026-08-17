#include<iostream>

using namespace std;



//Function template
//T is the placeholder type
template<typename T> //the moment compiler looks at this statement it creates a function template.

void print(T value) //calling the function template 
{
    cout << value << "\n";
}


//class Template 1
template<typename T>
class Calculator
{
    public:
    T add(T a, T b) //calling the function add with the same data type as the class
    {
        return a+b;
    }

    T subtract(T a, T b)
    {
        return a-b;
    }

};


//class Template 2
template<typename T, int N> //the moment compiler looks at this statement it creates a class template.

class Array //im trying to create an array of any type with a fixed size.
{
    private:
        T m_array[N]; //this is a Type safe array and N is the size of the array
    public:
        int GetSize()
        {
            return N;
        }

};

int main()
{
    //Function Template instantiation
    print(5.5);
    print(4);
   
    //class Template instantiation 1

    Calculator<int> calc1;
    cout << calc1.add(4,5) << "\n";
    
    Calculator<float> calc2;
    cout << calc2.subtract(2,3) << "\n"; 
   

    //class Template instantiation 2
    Array<int, 5> num1;
    Array<string, 4> string1;

    cout << num1.GetSize() << "\n";
    cout << string1.GetSize() << "\n";

    



}