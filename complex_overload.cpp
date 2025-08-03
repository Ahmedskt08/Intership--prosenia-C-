#include <iostream>
#include <cmath> // For magnitude calculation
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload > operator for magnitude comparison
    bool operator>(const Complex& other) const {
        return magnitude() > other.magnitude();
    }

    // Display function
    void display() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i" << endl;
        else cout << " - " << -imag << "i" << endl;
    }

    // Overload >> for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i";
        else out << " - " << -c.imag << "i";
        return out;
    }

private:
    // Calculate magnitude of complex number
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex c1, c2;
    cout << "--- Enter values for c1 ---" << endl;
    cin >> c1;
    cout << "--- Enter values for c2 ---" << endl;
    cin >> c2;

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;

    cout << "\n? Results:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;
    cout << "c1 - c2 = " << c4 << endl;
    cout << "c1 * c2 = " << c5 << endl;

    cout << "\n? Equality Check:\n";
    if (c1 == c2)
        cout << "c1 is equal to c2\n";
    else
        cout << "c1 is NOT equal to c2\n";

    cout << "\n? Magnitude Comparison:\n";
    if (c1 > c2)
        cout << "c1 has greater magnitude than c2\n";
    else
        cout << "c2 has greater or equal magnitude than c1\n";

    return 0;
}
