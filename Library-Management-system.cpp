
#include<bits/stdc++.h>
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

struct Borrow {
    string name;
    unordered_map<string, time_t> borrowedBooks;
};

vector<Book> books;
unordered_map<string, Borrow> borrowers; // Corrected the spelling from 'borrowere' to 'borrowers'
const int finePerDay = 2;

void addBook(const string& title, const string& author, const string& ISBN) {
    books.push_back(Book(title, author, ISBN));
}

void searchBook(const string& keyword) {
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos ||
            book.ISBN.find(keyword) != string::npos) {
            cout << "\n\t" << " Title: " << book.title << " ," << " Author: " << book.author << " ," << book.ISBN << " ," << " Book Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
}

bool CheckOutBook(const string& ISBN, const string& borrowerName) {
    for (auto& book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            time_t now = time(0);
            time_t dueDate = now + 7 * 24 * 60 * 60;

            // If borrower does not exist, create a new borrower entry
            if (borrowers.find(borrowerName) == borrowers.end()) {
                borrowers[borrowerName] = Borrow{borrowerName};
            }

            borrowers[borrowerName].borrowedBooks[ISBN] = dueDate; // Corrected the assignment of the borrowedBooks

            cout << "\tBook Checked out Successfully." << endl;
            return true;
        }
    }
    cout << "\tBook is not available or does not exist." << endl; // Corrected the message
    return false;
}

bool ReturnBook(const string& ISBN, const string& borrowerName) { // Corrected function name from 'Return_Book' to 'ReturnBook'
    if (borrowers.find(borrowerName) != borrowers.end()) {
        auto& borrower = borrowers[borrowerName];

        if (borrower.borrowedBooks.find(ISBN) != borrower.borrowedBooks.end()) {
            time_t now = time(0);
            time_t dueDate = borrower.borrowedBooks[ISBN];

            int daysOver = difftime(now, dueDate) / (60 * 60 * 24);

            if (daysOver > 0) {
                int fine = daysOver * finePerDay;
                cout << "\tBook is overdue by " << daysOver << " days. Fine: $" << fine << endl;
            }
            for (auto& book : books) {
                if (book.ISBN == ISBN) {
                    book.isAvailable = true;
                    break;
                }
            }
            borrower.borrowedBooks.erase(ISBN);
            cout << "\tBook returned successfully." << endl;
            return true;
        }
    }
    cout << "\tNo record of this book being borrowed by " << borrowerName << "." << endl;
    return false;
}

void display() {
    cout << "\t1. Add Books." << endl;
    cout << "\t2. Search Books." << endl;
    cout << "\t3. Check out Books." << endl;
    cout << "\t4. Return Books." << endl;
    cout << "\t5. Exit" << endl;
}

int main() {
    int choice;
    string author, title, keyword, ISBN, borrowerName;

    while (true) {
        cout << "\n\t***Library Management***\n";
        display();
        cout << "\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\tEnter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "\tEnter Author: ";
                getline(cin, author);
                cout << "\tEnter ISBN: ";
                getline(cin, ISBN);
                addBook(title, author, ISBN);
            }
            break;
            case 2: {
                cout << "\tEnter any keyword to identify the book: ";
                cin.ignore();
                getline(cin, keyword);
                searchBook(keyword);
            }
            break;
            case 3: {
                cout << "\tEnter ISBN: ";
                cin.ignore();
                getline(cin, ISBN);
                cout << "\tEnter the Name of Borrower: ";
                getline(cin, borrowerName);
                CheckOutBook(ISBN, borrowerName);
            }
            break;
            case 4: {
                cout << "\tEnter ISBN: ";
                cin.ignore();
                getline(cin, ISBN);
                cout << "\tEnter borrower's Name: ";
                getline(cin, borrowerName);
                ReturnBook(ISBN, borrowerName);
            }
            break;
            case 5: {
                cout << "\tExit";
                return 0; // Added return statement to exit the program
            }
            break;
            default: {
                cout << "\tInvalid choice. Please try again." << endl;
            }
            break;
        }
    }
    return 0;
}
