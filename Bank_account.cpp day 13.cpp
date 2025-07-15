#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount() {}
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void display() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << holderName
             << "\nBalance: $" << fixed << setprecision(2) << balance << "\n";
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string toFileString() const {
        return to_string(accountNumber) + "," + holderName + "," + to_string(balance);
    }

    static BankAccount fromFileString(const string& line) {
        int accNo;
        string name;
        double bal;

        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');

        accNo = stoi(line.substr(0, pos1));
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        bal = stod(line.substr(pos2 + 1));

        return BankAccount(accNo, name, bal);
    }
};

// ?? Global accounts list
vector<BankAccount> accounts;

// ?? Load from file
void loadAccountsFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        accounts.push_back(BankAccount::fromFileString(line));
    }
    file.close();
}

// ?? Save to file
void saveAccountsToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& acc : accounts) {
        file << acc.toFileString() << endl;
    }
    file.close();
}

// ?? Search account by number
BankAccount* searchAccount(int accNo) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo)
            return &acc;
    }
    return nullptr;
}

int main() {
    string filename = "accounts.txt";
    loadAccountsFromFile(filename);

    int choice;
    do {
        cout << "\n----- Bank Account Menu -----\n";
        cout << "1. Add Account\n2. Deposit\n3. Withdraw\n4. Display All Accounts\n5. Search Account\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double bal;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> bal;

            accounts.push_back(BankAccount(accNo, name, bal));
            saveAccountsToFile(filename);
            cout << "Account created!\n";
        } else if (choice == 2) {
            int accNo;
            double amt;
            cout << "Enter Account Number: ";
            cin >> accNo;
            BankAccount* acc = searchAccount(accNo);
            if (acc) {
                cout << "Enter amount to deposit: ";
                cin >> amt;
                acc->deposit(amt);
                saveAccountsToFile(filename);
            } else {
                cout << "Account not found!\n";
            }
        } else if (choice == 3) {
            int accNo;
            double amt;
            cout << "Enter Account Number: ";
            cin >> accNo;
            BankAccount* acc = searchAccount(accNo);
            if (acc) {
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                acc->withdraw(amt);
                saveAccountsToFile(filename);
            } else {
                cout << "Account not found!\n";
            }
        } else if (choice == 4) {
            for (const auto& acc : accounts)
                acc.display();
        } else if (choice == 5) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            BankAccount* acc = searchAccount(accNo);
            if (acc)
                acc->display();
            else
                cout << "Account not found!\n";
        }

    } while (choice != 6);

    return 0;
}
