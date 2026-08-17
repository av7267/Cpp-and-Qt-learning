#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

template <typename T> //the moment compiler looks at this statement it creates a class template.
class Statistics
{

    vector<T> digits;

public:
    void Add(T value)
    {
        digits.push_back(value);
    }

    T min() const
    {
        T minimum = digits[0];
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] < minimum)
            {
                minimum = digits[i];
            }
        }

        return minimum;
    }

    T max() const
    {
        T maximum = digits[0];

        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] > maximum)
            {
                maximum = digits[i];
            }
        }
        return maximum;
    }

    double average()
    {
        T sum = 0;
        T Count = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            sum = digits[i];
            Count++;
        }

        return static_cast<double>(sum) / Count;
    }

    void print()
    {
        for (int i = 0; i < digits.size(); i++)
        {
            cout << digits[i] << " ";

            cout << endl;
        }
    }
};

//Full Template Specialisation
template<typename T>
void process(T value)
{
    cout << "Processing generic type: " << value << endl;
}

template<>
void process<int>(int value)    //means the generic template has a special version specifically to implement int.
{
    cout << "Processing integer: " << value << endl;
}

template<> //this means I am providing a completely specific implementation for one exact type.
void process<string>(string value)
{
    cout << "Processing string: " << value << endl;
}

template<>
void process<double>(double value)
{
    cout << "Processing floating point: " << value << endl;
}

//Partial Template Specialisation
template<typename T, typename U>
class Pair
{
    T first;
    U second;
    public:
    Pair(T first, U second) : first(first), second(second)
    {}
    
    void print()
    {
        cout << "Generic pair\n";
    }
};

template<typename T>
class Pair<T, int>
{
    T first;
    int second;
    public:
    Pair(T first, int second) : first(first), second(second)
    {}

    void print()
    {
        cout << "Second Type is int\n";
    }

};

int main()
{

    //Normal template
    Statistics<int> numbers;

    numbers.Add(10);
    numbers.Add(20);
    numbers.Add(30);
    numbers.Add(40);

    cout << "Min: " << numbers.min() << endl;
    cout << "Max: " << numbers.max() << endl;
    cout << "Average: " << numbers.average()<< endl;

    numbers.print();

    Statistics<double> values;

    values.Add(2.5);
    values.Add(5.5);
    values.Add(10.0);

    cout << "Min: " << values.min() << endl;
    cout << "Max: " << values.max() << endl;
    cout << "Average: " << values.average() << endl;

    values.print();


    //Template Specialisation
    
    //Full
    process(100);
    process(25.5);
    process(string("Arnav"));
    process('A');

    //Partial

    Pair<double, string> genericPair(10.5, "Arnav");
    genericPair.print();

    Pair<double, int> intPair(10.5, 100);
    intPair.print();

    Pair<string, int> stringIntPair("Age", 25);
    stringIntPair.print();

    Pair<int, double> intDoublePair(10, 25.5);
    intDoublePair.print();




}