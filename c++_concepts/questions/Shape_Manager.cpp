#include <iostream>

using namespace std;

class Shape
{
    public:

    Shape()
    {

    }

    virtual void area() = 0;

    virtual void print(){}

    virtual ~Shape() {} = default;

};

class Rectangle : public Shape
{
    public:
    int length;
    int width;
    Rectangle(int length,int width)
    {
        this -> length = length;
        this -> width = width;
    }

    void area() override
    {
        cout << "Rectangle Area: " << length * width << endl;
    }

    void print()
    {
        cout << "Rectangle: Length = " << length << ", Width = " << width << endl;
    }
};

class Circle : public Shape
{
    public:
    int radius;

    Circle(int radius)
    {
        this -> radius = radius;
    }

    void area() override
    {
        cout << "Circle Area: " << 3.14159 * radius * radius << endl;
    }

    void print() override
    {
        cout << "Circle: Radius = " << radius << endl;
    }
};


class Triangle : public Shape
{
    public:
    int base;
    int height;

    Triangle(int base,int height)
    {
        this -> base = base;
        this -> height = height;
    }

    void area() override
    {
        cout << "Triangle Area: " << 0.5 * base * height << endl;
    }

    void print() override
    {
        cout << "Triangle: Base = " << base << ", Height = " << height << endl;
    }
};




int main()
{

    //stack allocation
    // Circle c(5);
    // Rectangle r(10, 20);
    // Triangle t(10, 5);

    // Shape* s1 = &c;
    // Shape* s2 = &r;
    // Shape* s3 = &t;

    //heap allocation
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(10,20);
    Shape* s3 = new Triangle(10,5);

    s1->print(); 
    s2->print(); //calls the Shape class print
    s3->print();

    s1->area(); 
    s2->area(); //calls the rectangle class area
    s3->area();

    //dynamic cast
    Rectangle* r = dynamic_cast<Rectangle*>(s2);
    r -> print(); //calls the rectangle class print


    cout << typeid(s1).name() << "\n";
    cout << typeid(*s1).name() << "\n";


    //containers

    // vector<Shape*> shapes;

    // shapes.push_back(new Circle(5));
    // shapes.push_back(new Rectangle(10, 20));
    // shapes.push_back(new Triangle(10, 5));
    // shapes.push_back(new Circle(3));

    // for (Shape* shape : shapes)
    // {
    //     shape->print();
    //     shape->area();
    // }


    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(10, 20));
    shapes.push_back(make_unique<Triangle>(10, 5));
    shapes.push_back(make_unique<Circle>(3));

    shapes.clear();

    delete s1;
    delete s2;
    delete s3;

    return 0;

}