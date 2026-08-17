#include <iostream>
#include <algorithm> //this is the stl library
using namespace std;


//Lamda Expressions take the values.

int main()
{
    //[](){} => Format to write the lambda expressions
    // [] => this is the capture claws
    // () => parameters holder
    // {} => function implementation

  

    int arr[5] = {1,2,3,4,5};

    //No capture
    for_each(begin(arr), end(arr),[](int x){     //looping over the array
        if(x % 2 == 0)
        {
            cout << x << " is divisible by 2" << "\n";
        }
        else
        {
            cout << "Not divisible" << "\n";
        }
    });

    cout << "\n";

    //Capture by value

    int limit = 10;
    auto checklimit = [limit](int x){     //we pass the exact value of the limit variable.
        return x >limit;
    };

    checklimit(20);


    //Capture everything by value
    auto printlimit = [=](){       //here the values of limit are taken because its in the lambda scope.
        cout << limit;
     };

    printlimit();


    //Capture by reference
    int sum = 0;
    auto s = [&sum](int x){    //we pass the reference value of the sum in this place.
        sum += x;
    };

    s(20); //20 is the x

    cout << "\n";


    //Capture everything by reference

    int total = 3;
    int count = 0;
    auto increment = [&](){
        total++;
        count++;
    };

    increment();
   

    cout << "Total = " << total << "\n";
    cout << "Count = " << count << "\n";



    //Mixed capture
    auto mixed = [limit,&sum](int z)
    {
        if (z > limit)
        {
            sum += z;
        }
           
    };

    mixed(11);

    cout << "Updated Sum = " << sum << "\n";
}


