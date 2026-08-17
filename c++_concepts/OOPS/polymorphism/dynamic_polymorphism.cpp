#include <iostream>

using namespace std;


// 2.Dynamic Polymorphism(Run time) [override,pure virtual, virtual]



class Employee //Object creation of an abstract class is not allowed
{
    protected:
        string emp_name;
        int emp_id;
        
    public:
        Employee(string employee_name, int employee_id): emp_name{employee_name}, emp_id{employee_id}
        {}
    
        virtual ~Employee() = default; //Virtual Destructor is used when we have virtual functions.

    public:
        virtual int CalculateAttendance() = 0; //Pure virtual function(abstract method).
    

};

class Attendance : public Employee
{
    public:
        int present_days;
        int absent_days;

        Attendance (string name, int id, int absent_days) : Employee(name,id)
        {
            this -> absent_days = absent_days;
        }

        int CalculateAttendance() override
        {
            present_days = 31 - absent_days;
            return present_days;
        }

};


class CalculateSalary
{
    protected:
        float salary;
    
    public: 
        int total_days;

        float SalaryCalculation(int total_days)
        {
            salary = 360.09 * total_days;
            return salary;
        }
        
};


class Employee_details : public Employee, public CalculateSalary     //Multiple Inheritance
{
    private:
        int absent_days;
        int present_days;

    public:
        Employee_details(string e_name, int e_id, int absent)
            : Employee(e_name, e_id), absent_days(absent)
        {}

        void Display_Employee()
        {
            float emp_salary = SalaryCalculation(CalculateAttendance());

            cout << "Employee Name : " << emp_name << endl;
            cout << "Employee ID   : " << emp_id << endl;
            cout << "Salary        : " << salary << endl;
        }

        int CalculateAttendance() override
        {
            present_days = 31 - absent_days;
            return present_days;
        }
};

int main()
{
    Employee* emp1 = new Employee_details ("Arnav", 101, 5);   

    emp1 -> CalculateAttendance(); //to access the child class method we use -> operator but not . operator because this overrides the base class method

    cout << "\n";

    Employee_details* details = dynamic_cast<Employee_details*>(emp1); //to access the display employee(child specific method) in the employee details class we use this type of casting
    details -> Display_Employee();

    cout << "\n";

    // Employee_details emp2("Anvitha", 102, 3);
    // emp2.Display_Employee(); //here we are access the method from the object itself there is no dereferencing needed so we use . operator

}

