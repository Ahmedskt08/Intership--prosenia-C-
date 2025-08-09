#include <iostream>
#include <vector>
#include <memory> // for smart pointers (optional but safe)
using namespace std;

// --------------------
// Interface-like Class
// --------------------
class Taxable {
public:
    virtual double calculateTax() const = 0;
    virtual ~Taxable() {}
};

// --------------------
// Abstract Base Class
// --------------------
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void displayInfo() const = 0;
    virtual double calculateSalary() const = 0;
    virtual ~Person() {
        cout << "Destroying Person: " << name << endl;
    }
};

// --------------------
// Derived: Employee
// --------------------
class Employee : public Person, public Taxable {
    double baseSalary;
public:
    Employee(string n, double salary) : Person(n), baseSalary(salary) {}
    
    void displayInfo() const override {
        cout << "Employee: " << name << ", Base Salary: " << baseSalary << endl;
    }
    
    double calculateSalary() const override {
        return baseSalary; // Full salary
    }

    double calculateTax() const override {
        return baseSalary * 0.15; // 15% tax
    }

    ~Employee() {
        cout << "Destroying Employee: " << name << endl;
    }
};

// --------------------
// Derived: Intern
// --------------------
class Intern : public Person, public Taxable {
    double stipend;
public:
    Intern(string n, double stipendAmt) : Person(n), stipend(stipendAmt) {}
    
    void displayInfo() const override {
        cout << "Intern: " << name << ", Stipend: " << stipend << endl;
    }
    
    double calculateSalary() const override {
        return stipend; // Stipend only
    }

    double calculateTax() const override {
        return stipend * 0.05; // 5% tax
    }

    ~Intern() {
        cout << "Destroying Intern: " << name << endl;
    }
};

// --------------------
// Main
// --------------------
int main() {
    vector<Person*> staff;

    // Adding Employee and Intern objects to base class pointer array
    staff.push_back(new Employee("Alice", 50000));
    staff.push_back(new Intern("Bob", 15000));
    staff.push_back(new Employee("Charlie", 60000));

    cout << "\n--- Payroll Details ---\n";
    for (Person* p : staff) {
        p->displayInfo();
        cout << "Salary: " << p->calculateSalary() << endl;

        // Dynamic cast to Taxable interface
        if (Taxable* t = dynamic_cast<Taxable*>(p)) {
            cout << "Tax: " << t->calculateTax() << endl;
        }
        cout << "---------------------\n";
    }

    // Cleanup
    for (Person* p : staff) {
        delete p; // Calls virtual destructor chain
    }

    return 0;
}
