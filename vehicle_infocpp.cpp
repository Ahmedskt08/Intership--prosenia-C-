#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string company;
    string model;
    int year;

    // Static variable to count objects
    static int vehicleCount;

public:
    // Default Constructor
    Vehicle() {
        company = "Unknown";
        model = "Unknown";
        year = 0;
        vehicleCount++;
        cout << "[Default Constructor] Vehicle Created!\n";
    }

    // Parameterized Constructor
    Vehicle(string c, string m, int y) {
        company = c;
        model = m;
        year = y;
        vehicleCount++;
        cout << "[Parameterized Constructor] Vehicle Created!\n";
    }

    // Destructor
    ~Vehicle() {
        cout << "[Destructor] Vehicle Destroyed: " << company << " " << model << " (" << year << ")\n";
        vehicleCount--;
    }

    // Function to display vehicle details
    void displayInfo() const {
        cout << "Company: " << company
             << ", Model: " << model
             << ", Year: " << year << endl;
    }

    // Static function to get current count
    static void showVehicleCount() {
        cout << "Total Vehicles: " << vehicleCount << endl;
    }
};

// Initialize static variable
int Vehicle::vehicleCount = 0;

int main() {
    cout << "--- Vehicle Info Management System ---\n";

    // Show count before any object is created
    Vehicle::showVehicleCount();

    // Create vehicle objects
    Vehicle v1; // default
    Vehicle v2("Toyota", "Corolla", 2020); // parameterized
    Vehicle v3("Honda", "Civic", 2021);

    // Show info
    cout << "\nVehicle Details:\n";
    v1.displayInfo();
    v2.displayInfo();
    v3.displayInfo();

    // Show count after creation
    Vehicle::showVehicleCount();

    cout << "\n--- Exiting Program ---\n";
    return 0; // destructors will be called automatically here
}
