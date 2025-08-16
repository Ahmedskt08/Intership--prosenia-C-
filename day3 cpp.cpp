#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    float cgpa;

    // Input
    cout << "Enter your name: ";
    cin >> name;   // takes one word name
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your CGPA: ";
    cin >> cgpa;

    // Check eligibility
    cout << "\n===== Eligibility Check =====\n";
    if (age >= 18 && cgpa >= 2.5) {
        cout << "Congratulations " << name << "! You are eligible to apply." << endl;
    } else {
        cout << "Sorry " << name << ", you are not eligible to apply." << endl;
    }

    return 0;
}
