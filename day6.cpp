#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

// Function to calculate sum of array
int getSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find index of first maximum element
int getMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find index of first minimum element
int getMinIndex(int arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to calculate average rounded to 2 decimal places
double getAverage(int arr[], int n) {
    int sum = getSum(arr, n);
    double avg = (double)sum / n;
    return avg;
}

// Function to reorder array: evens first, then odds (preserve order)
void reorderEvenOdd(int arr[], int n, int result[]) {
    int idx = 0;

    // Copy evens first
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            result[idx] = arr[i];
            idx++;
        }
    }
    // Then copy odds
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            result[idx] = arr[i];
            idx++;
        }
    }
}

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int reordered[SIZE];

    // Input
    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "\n=== Analyzing Array ===\n";

    // Sum & Average
    int sum = getSum(arr, SIZE);
    double avg = getAverage(arr, SIZE);

    // Max and Min (with index)
    int maxIndex = getMaxIndex(arr, SIZE);
    int minIndex = getMinIndex(arr, SIZE);

    cout << "Sum = " << sum << endl;
    cout << fixed << setprecision(2);
    cout << "Average = " << avg << endl;
    cout << "Maximum = " << arr[maxIndex] << " at position " << (maxIndex + 1) << endl;
    cout << "Minimum = " << arr[minIndex] << " at position " << (minIndex + 1) << endl;

    // Reorder even and odd
    reorderEvenOdd(arr, SIZE, reordered);

    cout << "\nReordered Array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << reordered[i] << " ";
    }
    cout << endl;

    return 0;
}
