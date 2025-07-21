#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;
    float salary;

public:
    Employee(string n, int i, float s) : name(n), id(i), salary(s) {}

    // Virtual function for polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    // Virtual destructor (good practice)
    virtual ~Employee() {}
};

// Derived Class: Manager
class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string n, int i, float s, float b) : Employee(n, i, s), bonus(b) {}

    void display() override {
        cout << "----- Manager Details -----" << endl;
        Employee::display();
        cout << "Bonus: " << bonus << endl;
        cout << "Total Compensation: " << (salary + bonus) << endl;
    }
};

// Derived Class: Developer
class Developer : public Employee {
private:
    string language;

public:
    Developer(string n, int i, float s, string lang) : Employee(n, i, s), language(lang) {}

    void display() override {
        cout << "----- Developer Details -----" << endl;
        Employee::display();
        cout << "Programming Language: " << language << endl;
    }
};

// Main Function
int main() {
    // Base class pointer array
    vector<Employee*> staff;

    // Creating derived class objects
    Manager* m1 = new Manager("Alice", 101, 70000, 10000);
    Developer* d1 = new Developer("Bob", 102, 60000, "C++");
    Developer* d2 = new Developer("Charlie", 103, 65000, "Python");

    // Storing them as base class pointers
    staff.push_back(m1);
    staff.push_back(d1);
    staff.push_back(d2);

    // Displaying polymorphically
    cout << "\n--- Employee Details ---\n";
    for (Employee* emp : staff) {
        emp->display();
        cout << "-------------------------\n";
    }

    // Cleanup
    for (Employee* emp : staff) {
        delete emp;
    }

    return 0;
}
