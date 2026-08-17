#include <iostream>
#include <string>

using namespace std;

class Logger
{
public:
    string name1;

    Logger(string s = "default") : name1(s)
    {
        cout << "Constructor called\n";
    }

    ~Logger()
    {
        cout << "Destructor called\n";
    }

};

class Database
{
public:
    
    Logger logger;
    //constructor initialiser list (used for things like const members, references, and members that don’t have a default constructor)
    Database() : logger("Database logger"){} //this is member initialisation where the member objects are constructed before the constructor body runs.
    //means the Logger object is constructed directly with that value
};

class Application
{
    public:
    Database database;
    Logger logger;
};

int main()
{
    Application app;
    return 0;
}


