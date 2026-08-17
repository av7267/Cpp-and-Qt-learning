#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

template <typename T>
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

template<typename T>
void process(T value)
{
    cout << "Processing generic type: " << value << endl;
}

template<>
void process<int>(int value)
{
    cout << "Processing integer: " << value << endl;
}

template<>
void process<string>(string value)
{
    cout << "Processing string: " << value << endl;
}

template<>
void process<double>(double value)
{
    cout << "Processing floating point: " << value << endl;
}

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
    process(100);
    process(25.5);
    process(string("Arnav"));
    process('A');

    //type traits
    

}