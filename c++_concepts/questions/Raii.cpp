#include <iostream>
#include <stdexcept>

using namespace std;


class FileManager
{
    public:
    int* resource;

    FileManager() : resource(new int(0))
    {
    }

    ~FileManager()
    {
        cout << "destructor called\n";
        delete resource;
    }

    void setValue(int value)
    {
        resource = new int(value);
    }

    int getValue()
    {
        return *resource;
    }

    void print()
    {
        cout << *resource << endl;
    }
};


int main()
{
    cout << "Program started\n";

    
    FileManager file;
    file.setValue(100);
    file.print();
    
    FileManager a;
    FileManager b;

    a.setValue(10);
    b.setValue(20);

    a.print();
    b.print();

    cout << "FileManager is now destroyed\n";

    return 0;
}

