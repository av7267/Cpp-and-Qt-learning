#include <iostream>
using namespace std;
#include <memory>


class Resource{
    public:
    int* data;

    Resource(int value)
    {
        data = new int(value);

        cout << "Resource acquired\n";
    }

    ~Resource()
    {
        cout << "Resource released\n";
        delete data;
    }
};

class ResourceManager{

    public:
    unique_ptr<Resource>resource;

    ResourceManager(int value) : resource(make_unique<Resource>(value))
    {}

    ResourceManager(ResourceManager&& other) : resource(std::move(other.resource)) //move constructor
    {}

    ResourceManager& operator =(ResourceManager&& other) //move assignment
    {
        if(this != &other)
        {
            resource = std::move(other.resource);
        }

        return *this;
    }
};

int main()
{
    cout << "Program started\n";
    ResourceManager a(100);
    ResourceManager b = std::move(a);

    return 0;
}