#include <iostream>
using namespace std;

int main() {
    float m1, m2, m3, total, average;
    char grade;

    // Input
    cout << "Enter marks for Subject 1: ";
    cin >> m1;
    cout << "Enter marks for Subject 2: ";
    cin >> m2;
    cout << "Enter marks for Subject 3: ";
    cin >> m3;

    // Calculate total and average
    total = m1 + m2 + m3;
    average = total / 3;

    // Determine grade
    if (average >= 80)
        grade = 'A';
    else if (average >= 60)
        grade = 'B';
    else if (average >= 40)
        grade = 'C';
    else
        grade = 'F';

    // Output
    cout << "\n===== Result =====\n";
    cout << "Total Marks: " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
