#include <iostream>
using namespace std;

int main() {
    string name; 
    int age;
    float gpa;

    // Input
    cout << "Enter your name: ";
    cin >> name; 
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your GPA: ";
    cin >> gpa;

    // Output
    cout << "\n===== Student Details =====\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;

    return 0;
}
