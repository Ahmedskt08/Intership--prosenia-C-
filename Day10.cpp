#include <iostream>
‎#include <fstream>
‎
‎using namespace std;
‎
‎const int MAX_ITEMS = 100;
‎const char* FILENAME = "inventory.txt";
‎const char* TEMP_FILE = "temp.txt";
‎
‎struct Item {
‎    int id;
‎    char name[50];
‎    int quantity;
‎    float price;
‎};
‎
‎void removeNewline(char *str) {
‎    for (int i = 0; str[i]; i++)
‎        if (str[i] == '\n') str[i] = '\0';
‎}
‎
‎bool readItems(Item items[], int &count) {
‎    ifstream in(FILENAME);
‎    if (!in.is_open()) return false;
‎    count = 0;
‎    while (in >> items[count].id) {
‎        in.ignore(3);
‎        in.getline(items[count].name, 50, '|');
‎        in >> items[count].quantity >> items[count].price;
‎        in.ignore();
‎        count++;
‎    }
‎    in.close();
‎    return true;
‎}
‎
‎void writeItem(Item &item, ofstream &out) {
‎    out << item.id << " | " << item.name << " | " 
‎        << item.quantity << " | " << item.price << '\n';
‎}
‎
‎void addItem() {
‎    Item item, items[MAX_ITEMS];
‎    int count = 0;
‎    readItems(items, count);
‎
‎    cout << "Enter Item ID: ";
‎    cin >> item.id;
‎    cin.ignore();
‎
‎    for (int i = 0; i < count; i++)
‎        if (items[i].id == item.id) {
‎            cout << "Error: Duplicate ID!\n";
‎            return;
‎        }
‎
‎    cout << "Enter Item Name: ";
‎    cin.getETL
‎    cin.getline(item.name, 50);
‎    removeNewline(item.name);
‎
‎    cout << "Enter Quantity: ";
‎    cin >> item.quantity;
‎
‎    cout << "Enter Price: ";
‎    cin >> item.price;
‎
‎    ofstream out(FILENAME, ios::app);
‎    if (!out.is_open()) {
‎        cout << "Error opening file!\n";
‎        return;
‎    }
‎    writeItem(item, out);
‎    out.close();
‎    cout << "Item added successfully!\n";
‎}
‎
‎void viewAllItems() {
‎    Item items[MAX_ITEMS];
‎    int count = 0;
‎    if (!readItems(items, count)) {
‎        cout << "No items found!\n";
‎        return;
‎    }
‎
‎    cout << "\n" << left << setw(10) << "ID" << setw(20) << "Name" 
‎         << setw(10) << "Qty" << setw(10) << "Price" << "\n";
‎    cout << "--------------------------------------------\n";
‎
‎    for (int i = 0; i < count; i++)
‎        cout << left << setw(10) << items[i].id << setw(20) << items[i].name 
‎             << setw(10) << items[i].quantity << setw(10) << fixed 
‎             << setprecision(2) << items[i].price << "\n";
‎}
‎
‎void searchItemByID() {
‎    int id;
‎    cout << "Enter Item ID to search: ";
‎    cin >> id;
‎
‎    Item items[MAX_ITEMS];
‎    int count = 0;
‎    if (!readItems(items, count)) {
‎        cout << "No items found!\n";
‎        return;
‎    }
‎
‎    for (int i = 0; i < count; i++)
‎        if (items[i].id == id) {
‎            cout << "\n" << left << setw(10) << "ID" << setw(20) << "Name" 
‎                 << setw(10) << "Qty" << setw(10) << "Price" << "\n";
‎            cout << "--------------------------------------------\n";
‎            cout << left << setw(10) << items[i].id << setw(20) << items[i].name 
‎                 << setw(10) << items[i].quantity << setw(10) << fixed 
‎                 << setprecision(2) << items[i].price << "\n";
‎            return;
‎        }
‎    cout << "Item not found!\n";
‎}
‎
‎void updateQuantity() {
‎    int id, newQty;
‎    cout << "Enter Item ID to update: ";
‎    cin >> id;
‎    cout << "Enter new quantity: ";
‎    cin >> newQty;
‎
‎    if (newQty < 0) {
‎        cout << "Error: Quantity cannot be negative!\n";
‎        return;
‎    }
‎
‎    Item items[MAX_ITEMS];
‎    int count = 0;
‎    if (!readItems(items, count)) {
‎        cout << "No items found!\n";
‎        return;
‎    }
‎
‎    ofstream out(TEMP_FILE);
‎    if (!out.is_open()) {
‎        cout << "Error creating temp file!\n";
‎        return;
‎    }
‎
‎    bool found = false;
‎    for (int i = 0; i < count; i++) {
‎        if (items[i].id == id) {
‎            items[i].quantity = newQty;
‎            found = true;
‎        }
‎        writeItem(items[i], out);
‎    }
‎    out.close();
‎
‎    if (!found) {
‎        cout << "Item not found!\n";
‎        remove(TEMP_FILE);
‎        return;
‎    }
‎
‎    remove(FILENAME);
‎    rename(TEMP_FILE, FILENAME);
‎    cout << "Quantity updated successfully!\n";
‎}
‎
‎void deleteItem() {
‎    int id;
‎    cout << "Enter Item ID to delete: ";
‎    cin >> id;
‎
‎    Item items[MAX_ITEMS];
‎    int count = 0;
‎    if (!readItems(items, count)) {
‎        cout << "No items found!\n";
‎        return;
‎    }
‎
‎    ofstream out(TEMP_FILE);
‎    if (!out.is_open()) {
‎        cout << "Error creating temp file!\n";
‎        return;
‎    }
‎
‎    bool found = false;
‎    for (int i = 0; i < count; i++)
‎        if (items[i].id != id)
‎            writeItem(items[i], out);
‎        else
‎            found = true;
‎    out.close();
‎
‎    if (!found) {
‎        cout << "Item not found!\n";
‎        remove(TEMP_FILE);
‎        return;
‎    }
‎
‎    remove(FILENAME);
‎    rename(TEMP_FILE, FILENAME);
‎    cout << "Item deleted successfully!\n";
‎}
‎
‎void displayMenu() {
‎    cout << "\nInventory Management System\n"
‎         << "1. Add Item\n2. View All Items\n3. Search by ID\n"
‎         << "4. Update Quantity\n5. Delete Item\n6. Exit\n"
‎         << "Enter your choice: ";
‎}
‎
‎int main() {
‎    int choice;
‎    while (true) {
‎        displayMenu();
‎        cin >> choice;
‎        switch (choice) {
‎            case 1: addItem(); break;
‎            case 2: viewAllItems(); break;
‎            case 3: searchItemByID(); break;
‎            case 4: updateQuantity(); break;
‎            case 5: deleteItem(); break;
‎            case 6: cout << "Exiting...\n"; return 0;
‎            default: cout << "Invalid choice!\n";
‎        }
‎    }
‎}