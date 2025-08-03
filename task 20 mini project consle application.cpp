#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// Base class: Book
class Book {
protected:
    int bookID;
    string title;
    string author;

public:
    Book() : bookID(0), title(""), author("") {
        cout << "[Book Created]\n";
    }

    Book(int id, string t, string a) : bookID(id), title(t), author(a) {}

    virtual void display() const {
        cout << left << setw(10) << bookID
             << setw(25) << title
             << setw(20) << author << endl;
    }

    int getID() const { return bookID; }

    virtual ~Book() {
        cout << "[Book Destroyed]\n";
    }
};

// Derived class: IssuedBook
class IssuedBook : public Book {
    string issuedTo;
    string issueDate;

public:
    IssuedBook(int id, string t, string a, string user, string date)
        : Book(id, t, a), issuedTo(user), issueDate(date) {}

    void display() const override {
        Book::display();
        cout << "Issued To: " << issuedTo << ", On: " << issueDate << endl;
    }

    ~IssuedBook() {
        cout << "[IssuedBook Destroyed]\n";
    }
};

// File Handling & Manager Class
class LibraryManager {
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.emplace_back(id, title, author);
        saveToFile();
    }

    void viewBooks() {
        loadFromFile();
        cout << "\n--- Book List ---\n";
        cout << left << setw(10) << "ID"
             << setw(25) << "Title"
             << setw(20) << "Author" << endl;
        for (const auto& book : books)
            book.display();
    }

    void saveToFile() {
        ofstream file("books.txt");
        for (const auto& book : books) {
            file << book.getID() << "|" << book.getID() << "|" << book.getID() << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        books.clear();
        ifstream file("books.txt");
        int id;
        string title, author, line;
        while (getline(file, line)) {
            size_t p1 = line.find("|");
            size_t p2 = line.find("|", p1 + 1);
            id = stoi(line.substr(0, p1));
            title = line.substr(p1 + 1, p2 - p1 - 1);
            author = line.substr(p2 + 1);
            books.emplace_back(id, title, author);
        }
        file.close();
    }

    ~LibraryManager() {
        cout << "[LibraryManager Destroyed]\n";
    }
};

// Menu-Driven Main Function
int main() {
    LibraryManager manager;
    int choice;

    do {
        cout << "\n====== Library Menu ======\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addBook();
                break;
            case 2:
                manager.viewBooks();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
