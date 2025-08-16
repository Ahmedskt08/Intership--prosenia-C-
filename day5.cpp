#include <iostream>
using namespace std;

// Function to print banner
void printBanner(string message) {
    cout << "\n=====================\n";
    cout << "  " << message << endl;
    cout << "=====================\n";
}

// Factorial function (simple int version)
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

// Custom max function
int customMax(int a, int b, int c) {
    if (a == b && b == c) {
        return 0; // all equal
    }
    int maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;

    if ((a == b && a == maxVal) || (b == c && b == maxVal) || (a == c && a == maxVal)) {
        int sum = 0;
        if (a == maxVal) sum += a;
        if (b == maxVal) sum += b;
        if (c == maxVal) sum += c;
        return sum;
    }

    return maxVal; // normal maximum
}

int main() {
    // Factorial task
    printBanner("Factorial Calculation");
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0)
        cout << "Factorial not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << num << " = " << factorial(num) << endl;

    // Custom max task
    printBanner("Custom Max of Three Numbers");
    int n1, n2, n3;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;
    cout << "Custom Max Result = " << customMax(n1, n2, n3) << endl;

    return 0;
}
