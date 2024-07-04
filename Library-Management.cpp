

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true) {}
};

struct Borrow{
    string name;
    unordered_map<string,time_t> borrowedBooks; 
}

vector<Book> books;
unordered_map<string, Borrow> borrowers;
const int finePerDay = 2; // Assume the fine is $2 per day overdue

void addBook(const string& title, const string& author, const string& ISBN) {
    books.push_back(Book(title, author, ISBN));
}


void searchBook(const string& keyword) {
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || 
            book.author.find(keyword) != string::npos || 
            book.ISBN.find(keyword) != string::npos) {
            cout<<"\n" << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
}

bool checkOutBook(const string& ISBN, const string& borrowerName) {
    for (auto& book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            time_t now = time(0);
            time_t dueDate = now + 7 * 24 * 60 * 60; // Due in 7 days
            borrowers[borrowerName].borrowedBooks[ISBN] = dueDate;
            cout << "Book checked out successfully." << endl;
            return true;
        }
    }
    cout << "Book not available or does not exist." << endl;
    return false;
}

bool returnBook(const string& ISBN, const string& borrowerName) {
    if (borrowers.find(borrowerName) != borrowers.end()) {
        auto& borrower = borrowers[borrowerName];
        if (borrower.borrowedBooks.find(ISBN) != borrower.borrowedBooks.end()) {
            time_t now = time(0);
            time_t dueDate = borrower.borrowedBooks[ISBN];
            int daysOverdue = difftime(now, dueDate) / (60 * 60 * 24);
            if (daysOverdue > 0) {
                int fine = daysOverdue * finePerDay;
                cout << "Book is overdue by " << daysOverdue << " days. Fine: $" << fine << endl;
            }
            for (auto& book : books) {
                if (book.ISBN == ISBN) {
                    book.isAvailable = true;
                    break;
                }
            }
            borrower.borrowedBooks.erase(ISBN);
            cout << "Book returned successfully." << endl;
            return true;
        }
    }
    cout << "No record of this book being borrowed by " << borrowerName << "." << endl;
    return false;
}

void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Check Out Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int choice;
    string title, keyword, author, ISBN, borrowerName;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                addBook(title, author, ISBN);
                break;
            case 2:
                cout << "Enter keyword (title, author, ISBN): ";
                cin.ignore();
                getline(cin, keyword);
                searchBook(keyword);
                break;
            case 3:
                cout << "Enter ISBN: ";
                cin.ignore();
                getline(cin, ISBN);
                cout << "Enter borrower's name: ";
                getline(cin, borrowerName);
                checkOutBook(ISBN, borrowerName);
                break;
            case 4:
                cout << "Enter ISBN: ";
                cin.ignore();
                getline(cin, ISBN);
                cout << "Enter borrower's name: ";
                getline(cin, borrowerName);
                returnBook(ISBN, borrowerName);
                break;
            case 5:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
