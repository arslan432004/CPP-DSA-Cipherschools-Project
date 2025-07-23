#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string name;
    string author;
    bool borrowed;

public:
    Book(string name, string author) {
        this->name = name;
        this->author = author;
        borrowed = false;
    }

    string getBookName() const {
        return name;
    }

    string getAuthorName() const {
        return author;
    }

    bool isBorrowed() const {
        return borrowed;
    }

    void setBookStatus(bool status) {
        borrowed = status;
    }
};

class Library {
private:
    vector<Book> list;

public:
    Library() {}

    void addBook(string name, string author) {
        Book b(name, author);
        list.push_back(b);
    }

    int findBookIndexByName(string name) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getBookName() == name) return i;
        }
        return -1;  // Not found
    }

    void returnBookByName(string name) {
        int idx = findBookIndexByName(name);
        if (idx != -1 && list[idx].isBorrowed()) {
            list[idx].setBookStatus(false);
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book not found or not borrowed.\n";
        }
    }

    void borrowBookByName(string name) {
        int idx = findBookIndexByName(name);
        if (idx != -1 && !list[idx].isBorrowed()) {
            list[idx].setBookStatus(true);
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book not found or already borrowed.\n";
        }
    }

    void displayBooks() {
        if (list.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            cout << i + 1 << ". Book name: \"" << list[i].getBookName()
                 << "\" by " << list[i].getAuthorName()
                 << " [" << (list[i].isBorrowed() ? "Borrowed" : "Available") << "]\n";
        }
    }

    void displayBorrowedBooks() {
        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].isBorrowed()) {
                found = true;
                cout << i + 1 << ". Book name: \"" << list[i].getBookName()
                     << "\" by " << list[i].getAuthorName() << "\n";
            }
        }
        if (!found) {
            cout << "No borrowed books.\n";
        }
    }
};

int main() {
    Library lb;

    while (true) {
        cout << "\n=== LIBRARY MENU ===\n";
        cout << "1. Add a book\n";
        cout << "2. Return a book (by name)\n";
        cout << "3. Borrow a book (by name)\n";
        cout << "4. Display all books\n";
        cout << "5. Display all borrowed books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int ch;
        cin >> ch;
        cin.ignore();  // Flush newline

        string name, author;

        switch (ch) {
        case 1:
            cout << "Enter book name: ";
            getline(cin, name);
            cout << "Enter author name: ";
            getline(cin, author);
            lb.addBook(name, author);
            break;

        case 2:
            lb.displayBorrowedBooks();
            cout << "Enter the name of the book to return: ";
            getline(cin, name);
            lb.returnBookByName(name);
            break;

        case 3:
            lb.displayBooks();
            cout << "Enter the name of the book to borrow: ";
            getline(cin, name);
            lb.borrowBookByName(name);
            break;

        case 4:
            lb.displayBooks();
            break;

        case 5:
            lb.displayBorrowedBooks();
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
