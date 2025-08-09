#include <iostream>
#include <cassert>
using namespace std;

// ----------------------
// Template Functions
// ----------------------
template <typename T>
T addFunc(T a, T b) {
    return a + b;
}

template <typename T>
T subFunc(T a, T b) {
    return a - b;
}

template <typename T>
T mulFunc(T a, T b) {
    return a * b;
}

// General division template
template <typename T>
T divFunc(T a, T b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

// Specialization for int to handle division by zero
template <>
int divFunc<int>(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero for integers!\n";
        return 0; // return default value
    }
    return a / b;
}

// ----------------------
// Class Template
// ----------------------
template <typename T>
class Calculator {
public:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
    T multiply(T a, T b) { return a * b; }
    T divide(T a, T b) {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
};

// Specialization for int division
template <>
class Calculator<int> {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) {
        if (b == 0) {
            cout << "Error: Division by zero for integers!\n";
            return 0;
        }
        return a / b;
    }
};

// ----------------------
// Unit Tests
// ----------------------
void runTests() {
    assert(addFunc(2, 3) == 5);
    assert(subFunc(5, 2) == 3);
    assert(mulFunc(3, 4) == 12);
    assert(divFunc(10, 2) == 5);

    Calculator<double> c;
    assert(c.add(2.5, 3.5) == 6.0);
    assert(c.subtract(5.5, 2.0) == 3.5);
    assert(c.multiply(3.0, 4.0) == 12.0);
    assert(c.divide(10.0, 2.0) == 5.0);

    cout << "All tests passed successfully!\n";
}

// ----------------------
// Menu-driven Program
// ----------------------
template <typename T>
void performOperations() {
    Calculator<T> calc;
    int choice;
    T a, b;

    do {
        cout << "\n--- Calculator Menu ---\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;
        }

        switch (choice) {
            case 1: cout << "Result: " << calc.add(a, b) << endl; break;
            case 2: cout << "Result: " << calc.subtract(a, b) << endl; break;
            case 3: cout << "Result: " << calc.multiply(a, b) << endl; break;
            case 4: 
                try {
                    cout << "Result: " << calc.divide(a, b) << endl;
                } catch (runtime_error &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

// ----------------------
// Main
// ----------------------
int main() {
    runTests();

    int typeChoice;
    cout << "\nSelect Data Type:\n1. int\n2. float\n3. double\n";
    cout << "Enter choice: ";
    cin >> typeChoice;

    switch (typeChoice) {
        case 1: performOperations<int>(); break;
        case 2: performOperations<float>(); break;
        case 3: performOperations<double>(); break;
        default: cout << "Invalid type choice!\n";
    }

    return 0;
}
