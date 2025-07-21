#include <iostream>
using namespace std;

// Base Class
class Shape {
public:
    // Virtual function for polymorphism
    virtual void draw() {
        cout << "Drawing a generic shape.\n";
    }

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived Class: Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "?? Drawing a Circle\n";
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "? Drawing a Rectangle\n";
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
public:
    void draw() override {
        cout << "?? Drawing a Triangle\n";
    }
};

int main() {
    const int size = 3;
    Shape* shapes[size];

    // Dynamically allocate shapes
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();
    shapes[2] = new Triangle();

    // Call draw() using base class pointer
    cout << "\n--- Drawing Shapes ---\n";
    for (int i = 0; i < size; i++) {
        shapes[i]->draw();
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    return 0;
}
