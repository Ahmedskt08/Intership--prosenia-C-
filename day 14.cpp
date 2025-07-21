#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];
    float total;
    float average;

public:
    // Default constructor
    Student() {
        rollNo = 0;
        name = "";
        for (int i = 0; i < 3; i++) marks[i] = 0;
        total = 0;
        average = 0;
    }

    // Parameterized function to input student data
    void input(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateTotalAverage();
    }

    // Calculate total and average
    void calculateTotalAverage() {
        total = marks[0] + marks[1] + marks[2];
        average = total / 3.0;
    }

    // Return grade
    char getGrade() const {
        if (average >= 85) return 'A';
        else if (average >= 70) return 'B';
        else if (average >= 50) return 'C';
        else return 'F';
    }

    // Display student info
    void display() const {
        cout << left << setw(10) << rollNo
             << setw(15) << name
             << setw(10) << marks[0]
             << setw(10) << marks[1]
             << setw(10) << marks[2]
             << setw(10) << total
             << setw(10) << fixed << setprecision(2) << average
             << setw(5) << getGrade() << endl;
    }

    // Getter for total
    float getTotal() const {
        return total;
    }
};

// Sort students by total marks in descending order
void sortStudentsByTotal(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].getTotal() < students[j + 1].getTotal()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100]; // Fixed-size array

    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        float m1, m2, m3;

        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        students[i].input(roll, name, m1, m2, m3);
    }

    sortStudentsByTotal(students, n);

    // Display result table
    cout << "\n--- Student Result Table (Sorted by Total Marks) ---\n";
    cout << left << setw(10) << "RollNo"
         << setw(15) << "Name"
         << setw(10) << "Marks1"
         << setw(10) << "Marks2"
         << setw(10) << "Marks3"
         << setw(10) << "Total"
         << setw(10) << "Average"
         << setw(5) << "Grade" << endl;

    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    return 0;
}
