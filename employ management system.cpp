#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Struct Definition
struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

// Global vector to hold employees
vector<Employee> employees;

// File names
const string DATA_FILE = "employees.txt";
const string LOG_FILE = "log.txt";

// Utility to log actions
void logAction(const string& action) {
    ofstream logFile(LOG_FILE, ios::app);
    if (logFile) {
        logFile << action << endl;
        logFile.close();
    }
}

// Load employees from file
void loadFromFile() {
    ifstream file(DATA_FILE);
    Employee emp;
    while (file >> emp.id) {
        file.ignore(); // skip newline/space
        getline(file, emp.name);
        getline(file, emp.department);
        file >> emp.salary;
        file.ignore();
        employees.push_back(emp);
    }
    file.close();
}

// Save all employees to file
void saveToFile() {
    ofstream file(DATA_FILE);
    for (const auto& emp : employees) {
        file << emp.id << endl;
        file << emp.name << endl;
        file << emp.department << endl;
        file << emp.salary << endl;
    }
    file.close();
}

// Add a new employee
void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();

    for (const auto& e : employees) {
        if (e.id == emp.id) {
            cout << "Employee with this ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    employees.push_back(emp);
    logAction("Added Employee ID: " + to_string(emp.id));
    cout << "Employee added successfully!\n";
}

// View all employees
void viewEmployees() {
    cout << left << setw(6) << "ID" << setw(20) << "Name"
         << setw(15) << "Department" << setw(10) << "Salary" << endl;
    cout << "-----------------------------------------------------\n";
    for (const auto& emp : employees) {
        cout << left << setw(6) << emp.id
             << setw(20) << emp.name
             << setw(15) << emp.department
             << setw(10) << emp.salary << endl;
    }
}

// Search by ID
void searchByID() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << emp.id << "\nName: " << emp.name
                 << "\nDepartment: " << emp.department
                 << "\nSalary: " << emp.salary << "\n";
            logAction("Searched Employee ID: " + to_string(id));
            return;
        }
    }
    cout << "Employee not found.\n";
}

// Update salary
void updateSalary() {
    int id;
    double newSalary;
    cout << "Enter Employee ID to update salary: ";
    cin >> id;
    for (auto& emp : employees) {
        if (emp.id == id) {
            cout << "Current Salary: " << emp.salary << endl;
            cout << "Enter new salary: ";
            cin >> newSalary;
            emp.salary = newSalary;
            cout << "Salary updated!\n";
            logAction("Updated Salary for ID: " + to_string(id));
            return;
        }
    }
    cout << "Employee not found.\n";
}

// Calculate total and average salary
void salaryStats() {
    if (employees.empty()) {
        cout << "No employees in the system.\n";
        return;
    }

    double total = 0;
    for (const auto& emp : employees)
        total += emp.salary;

    double average = total / employees.size();

    cout << "Total Salary: " << total << endl;
    cout << "Average Salary: " << average << endl;
}

void menu() {
    loadFromFile();

    int choice;
    do {
        cout << "\n==== Employee Record Management ====\n";
        cout << "1. Add New Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee Salary\n";
        cout << "5. Salary Stats (Total & Average)\n";
        cout << "0. Exit & Save\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchByID(); break;
            case 4: updateSalary(); break;
            case 5: salaryStats(); break;
            case 0:
                saveToFile();
                logAction("Program exited and data saved.");
                cout << "Exiting... Data saved.\n";
                break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
