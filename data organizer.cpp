#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


// Vector Functions
void addMark(vector<int>& marks, int mark) {
    marks.push_back(mark);
}

void searchMark(const vector<int>& marks, int mark) {
    auto it = find(marks.begin(), marks.end(), mark);
    if (it != marks.end())
        cout << "Mark found!\n";
    else
        cout << "Mark not found.\n";
}

void removeMark(vector<int>& marks, int mark) {
    auto it = remove(marks.begin(), marks.end(), mark);
    if (it != marks.end()) {
        marks.erase(it, marks.end());
        cout << "Mark removed.\n";
    } else {
        cout << "Mark not found.\n";
    }
}

void displayMarks(vector<int>& marks) {
    sort(marks.begin(), marks.end());
    cout << "Marks: ";
    for (auto it = marks.begin(); it != marks.end(); ++it)
        cout << *it << " ";
    cout << "\n";
}

// Set Functions
void addDepartment(set<string>& departments, const string& dept) {
    departments.insert(dept);
}

void displayDepartments(const set<string>& departments) {
    cout << "Departments: ";
    for (auto it = departments.begin(); it != departments.end(); ++it)
        cout << *it << " ";
    cout << "\n";
}
// Map Functions

void addStudentToDepartment(map<string, int>& deptCount, const string& dept) {
    deptCount[dept]++;
}

void removeStudentFromDepartment(map<string, int>& deptCount, const string& dept) {
    auto it = deptCount.find(dept);
    if (it != deptCount.end() && it->second > 0) {
        it->second--;
        cout << "Student removed from " << dept << "\n";
    } else {
        cout << "Department not found or no students to remove.\n";
    }
}

void displayDepartmentCounts(const map<string, int>& deptCount) {
    cout << "Department-wise Student Count:\n";
    for (auto it = deptCount.begin(); it != deptCount.end(); ++it)
        cout << it->first << ": " << it->second << "\n";
}

// -------------------------
// Main Menu
// -------------------------
int main() {
    vector<int> marks;
    set<string> departments;
    map<string, int> deptCount;
    int choice;

    do {
        cout << "\n--- Data Organizer Menu ---\n";
        cout << "1. Add mark\n2. Search mark\n3. Remove mark\n4. Display marks\n";
        cout << "5. Add department\n6. Display departments\n";
        cout << "7. Add student to department\n8. Remove student from department\n9. Display department counts\n";
        cout << "10. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int m; cout << "Enter mark: "; cin >> m;
            addMark(marks, m);
        } else if (choice == 2) {
            int m; cout << "Enter mark to search: "; cin >> m;
            searchMark(marks, m);
        } else if (choice == 3) {
            int m; cout << "Enter mark to remove: "; cin >> m;
            removeMark(marks, m);
        } else if (choice == 4) {
            displayMarks(marks);
        } else if (choice == 5) {
            string d; cout << "Enter department name: "; cin >> d;
            addDepartment(departments, d);
        } else if (choice == 6) {
            displayDepartments(departments);
        } else if (choice == 7) {
            string d; cout << "Enter department name: "; cin >> d;
            addStudentToDepartment(deptCount, d);
        } else if (choice == 8) {
            string d; cout << "Enter department name: "; cin >> d;
            removeStudentFromDepartment(deptCount, d);
        } else if (choice == 9) {
            displayDepartmentCounts(deptCount);
        }

    } while (choice != 10);

    return 0;
}
