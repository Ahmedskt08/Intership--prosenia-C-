#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
using namespace std;

// ----------------------
// Custom Exceptions
// ----------------------
class DivisionByZeroException : public runtime_error {
public:
    DivisionByZeroException() : runtime_error("Error: Division by zero!") {}
};

class InvalidInputException : public runtime_error {
public:
    InvalidInputException() : runtime_error("Error: Invalid numeric input!") {}
};

class OverflowException : public runtime_error {
public:
    OverflowException() : runtime_error("Error: Arithmetic overflow!") {}
};

// ----------------------
// Logging Function
// ----------------------
void logError(const string &msg) {
    ofstream log("error_log.txt", ios::app);
    log << msg << endl;
}

// ----------------------
// Safe Input Function
// ----------------------
double getNumber() {
    double num;
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputException();
    }
    return num;
}

// ----------------------
// Overflow Check (Optional)
// ----------------------
bool checkOverflow(double a, double b, char op) {
    double result;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
    }
    return (result > numeric_limits<double>::max() || result < -numeric_limits<double>::max());
}

// ----------------------
// Main
// ----------------------
int main() {
    double a, b;
    char op;

    cout << "--- Robust Calculator ---\n";
    try {
        cout << "Enter first number: ";
        a = getNumber();

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        b = getNumber();

        if (op == '/' && b == 0) throw DivisionByZeroException();
        if (checkOverflow(a, b, op)) throw OverflowException();

        double result;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: throw InvalidInputException();
        }

        cout << "Result: " << result << endl;

    } catch (const DivisionByZeroException &e) {
        cout << e.what() << endl;
        logError(e.what());
    } catch (const InvalidInputException &e) {
        cout << e.what() << endl;
        logError(e.what());
    } catch (const OverflowException &e) {
        cout << e.what() << endl;
        logError(e.what());
    } catch (const exception &e) {
        cout << "Unexpected error: " << e.what() << endl;
        logError(e.what());
    }

    cout << "Program finished.\n";
    return 0;
}
