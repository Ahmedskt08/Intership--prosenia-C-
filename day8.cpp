#include <iostream>
using namespace std;

// ? Helper: Check odd
bool isOdd(int n) {
    return (n % 2 != 0);
}

// ? Swap only if absolute difference > 10
void conditionalSwap(int* x, int* y) {
    int diff = *x - *y;
    if (diff < 0) diff = -diff;   // manual abs
    if (diff > 10) {
        int* temp = new int(*x);  // temporary pointer storage
        *x = *y;
        *y = *temp;
        delete temp; // free memory
    }
}

// ? Print array using pointer arithmetic
void printArrayViaPointer(int* arr, int size) {
    for (int* p = arr; p < arr + size; p++) {
        cout << *p << " @ " << p << endl;
    }
}

// ? Find first even element via pointer
int* findFirstEven(int* arr, int size) {
    for (int* p = arr; p < arr + size; p++) {
        if (*p % 2 == 0)
            return p;  // return address of first even
    }
    return nullptr;
}

// ? Increment all odd numbers
void incrementOddsByAddress(int* arr, int size) {
    for (int* p = arr; p < arr + size; p++) {
        if (isOdd(*p)) {
            (*p)++;
        }
    }
}

int main() {
    int a, b;
    cout << "Enter two integers (a b): ";
    cin >> a >> b;

    int arr[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "\n=== Pointer Logic Execution ===\n";
    cout << "Before Swap: a = " << a << ", b = " << b << endl;
    conditionalSwap(&a, &b);
    cout << "After Swap : a = " << a << ", b = " << b << endl;

    cout << "\nArray Elements (value @ address):\n";
    printArrayViaPointer(arr, 5);

    int* evenPtr = findFirstEven(arr, 5);
    if (evenPtr)
        cout << "\nFirst Even: " << *evenPtr << " @ " << evenPtr << endl;
    else
        cout << "\nNo even number found.\n";

    incrementOddsByAddress(arr, 5);
    cout << "\nArray After Incrementing Odds:\n";
    printArrayViaPointer(arr, 5);

    return 0;
}
