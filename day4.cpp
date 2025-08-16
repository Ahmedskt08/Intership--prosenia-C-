#include <iostream>
#include <cmath>
using namespace std;

// Function to reverse an integer
int reverseNumber(int num) {
    int reversed = 0;
    bool isNegative = false;

    if (num < 0) {          // handle negative numbers
        isNegative = true;
        num = -num;
    }

    while (num != 0) {
        int digit = num % 10;        // take last digit
        reversed = reversed * 10 + digit; 
        num /= 10;                   // remove last digit
    }

    return isNegative ? -reversed : reversed; 
}

// Function to check if number is prime
bool isPrime(int n) {
    if (n <= 1) return false;        // 0, 1, negatives ? not prime

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false; // divisible ? not prime
    }
    return true; // prime
}

int main() {
    // --- Reverse Number Task ---
    int num;
    cout << "Enter an integer to reverse: ";
    cin >> num;
    cout << "Reversed Number: " << reverseNumber(num) << endl;

    // --- Prime Number Task ---
    int n;
    cout << "\nEnter a number to check prime: ";
    cin >> n;
    if (isPrime(n))
        cout << n << " is a PRIME number." << endl;
    else
        cout << n << " is NOT a prime number." << endl;

    return 0;
}
