#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>

using namespace std;

class Shape {
protected:
   std::string name;
   double area;
   double perimeter;

public:
   Shape(){name = ""; area = 0.0; perimeter=0.0;}
   virtual ~Shape();
   virtual std::string toString() const {
      return "Name: "+name+
            "\nArea "+to_string(area)+
            "\nPerimeter "+to_string(perimeter);
   }
};

class Circle: public Shape{
   double radius;
public:
   Circle(double r){
      radius = r;
      Shape::name = "Circle";
      Shape::area = M_PI * pow(radius, 2);
      Shape::perimeter = 2 * M_PI * radius;
   }
   std::string toString() const{
      return Shape::toString() +
            "\nRadius = "+std::to_string(radius);
   }
};

class Rectangle: public Shape {
   double length, width;
public:
   Rectangle(double l, double w) {
      length = l;
      width = w;
      Shape::name="Rectangle";
      Shape::area = length * width;
      Shape::perimeter = 2 * (length + width);
   }
   std::string toString() const{
      return Shape::toString() +
            "\nLength = "+std::to_string(length)+
            "\nWidth = "+std::to_string(width);
   }
};

template<class T> void cleanup(T &t){
   typename T::iterator i;
   for (i=t.begin(); i != t.end(); ++i) {
      delete *i;
      *i = nullptr;
   }
}

int main()
{

   vector<Shape *> pf;
   pf.push_back(new Circle(5.0));
   pf.push_back(new Rectangle(6.2,5.6));
   pf.push_back(new Rectangle(3.5,2.5));
   pf.push_back(new Circle(8.9));

   try {
      for(vector<Shape *>::iterator iter = pf.begin();
            iter != pf.end(); ++iter){
            Rectangle *rptr =
                  dynamic_cast<Rectangle *>(*iter);
         if(rptr)
            cout<<rptr->toString()<<endl;
         else
            cout<<"Not a rectangle"<<endl;
      }
   } catch (std::bad_cast &bc) {
      cerr<<bc.what()<<endl;
   }

   try {
      Shape *sptr = new Circle(3.6);
      Rectangle *rptr = dynamic_cast<Rectangle *>(sptr);
      if(rptr)
         cout<<"Rectangle object"<<endl;
      Circle *cptr = dynamic_cast<Circle *>(sptr);
      if(cptr)
         cout<<"It is also a circle object"<<endl;
   } catch (std::bad_cast &bc) {
      cerr<<bc.what()<<endl;
   }

   cleanup(pf);
   return 0;
}