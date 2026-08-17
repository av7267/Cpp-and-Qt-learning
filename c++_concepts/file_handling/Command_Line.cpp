#include <iostream>
using namespace std;
#include <vector>
#include <fstream>


//Files Example Workflow


int main()
{
    int arr[5] = {1,2,3,4,5};
    
    for (int i=0;i<5;i++)
    {
        cout<<arr[i];
        
    }

    cout << "\n";

    vector<int> nums = {1,2,3,4,5};
    nums.push_back(10);
    nums.push_back(220);

    for(int j = 0; j< nums.size();j++)
    {
        cout << nums[j];
        cout << "\n";
    }

    nums.pop_back();
    cout << nums.size();

    ofstream outfile("example.txt");

    if(!outfile)
    {
        cout << "Error opening the file";
        return 1;
    }

    outfile << "Hi"; //this

    outfile.close();
}