#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

// Structure to store book details
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;  // Availability status

    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), available(true) {}
};

// Structure to store borrower details
struct Borrower {
    string name;
    vector<Book*> borrowedBooks;  // List of borrowed books

    Borrower(string n) : name(n) {}
};

// Structure to store transaction details
struct Transaction {
    Borrower* borrower;
    Book* book;
    time_t checkoutDate;
    bool returned;

    Transaction(Borrower* b, Book* bk) : borrower(b), book(bk), returned(false) {
        checkoutDate = time(0);  // Record the current time
    }

    void returnBook() {
        returned = true;
    }

    int calculateFine() {
        if (returned) return 0;

        time_t currentTime = time(0);
        int overdueDays = difftime(currentTime, checkoutDate) / (60 * 60 * 24);  // Calculate overdue days
        if (overdueDays > 14) {  // Assuming a 14-day borrowing period
            return (overdueDays - 14) * 1;  // Fine is $1 per day overdue
        }
        return 0;
    }
};

// Class to manage the library system
class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

public:
    // Function to add a book to the library
    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
    }

    // Function to search for a book by title, author, or ISBN
    void searchBook() {
        string searchTerm;
        cout << "Enter title, author, or ISBN to search: ";
        cin.ignore();
        getline(cin, searchTerm);

        bool found = false;
        for (const auto& book : books) {
            if (book.title == searchTerm || book.author == searchTerm || book.ISBN == searchTerm) {
                cout << "Found book: " << book.title << " by " << book.author << " (ISBN: " << book.ISBN << ")\n";
                found = true;
            }
        }
        if (!found) cout << "No books found.\n";
    }

    // Function to register a borrower
    void registerBorrower() {
        string name;
        cout << "Enter borrower's name: ";
        cin.ignore();
        getline(cin, name);
        borrowers.push_back(Borrower(name));
        cout << "Borrower registered successfully.\n";
    }

    // Function to checkout a book to a borrower
    void checkoutBook() {
        string borrowerName, ISBN;
        cout << "Enter borrower's name: ";
        cin.ignore();
        getline(cin, borrowerName);
        
        // Find the borrower
        Borrower* borrower = nullptr;
        for (auto& b : borrowers) {
            if (b.name == borrowerName) {
                borrower = &b;
                break;
            }
        }
        
        if (borrower == nullptr) {
            cout << "Borrower not found.\n";
            return;
        }

        cout << "Enter ISBN of the book to checkout: ";
        cin >> ISBN;

        // Find the book
        Book* book = nullptr;
        for (auto& b : books) {
            if (b.ISBN == ISBN && b.available) {
                book = &b;
                break;
            }
        }

        if (book == nullptr) {
            cout << "Book not found or is not available.\n";
            return;
        }

        // Checkout the book
        book->available = false;
        borrower->borrowedBooks.push_back(book);
        transactions.push_back(Transaction(borrower, book));
        cout << "Book checked out successfully.\n";
    }

    // Function to return a book
    void returnBook() {
        string borrowerName, ISBN;
        cout << "Enter borrower's name: ";
        cin.ignore();
        getline(cin, borrowerName);
        
        // Find the borrower
        Borrower* borrower = nullptr;
        for (auto& b : borrowers) {
            if (b.name == borrowerName) {
                borrower = &b;
                break;
            }
        }

        if (borrower == nullptr) {
            cout << "Borrower not found.\n";
            return;
        }

        cout << "Enter ISBN of the book to return: ";
        cin >> ISBN;

        // Find the book and the transaction
        Book* book = nullptr;
        Transaction* trans = nullptr;
        for (auto& t : transactions) {
            if (t.borrower == borrower && t.book->ISBN == ISBN && !t.returned) {
                book = t.book;
                trans = &t;
                break;
            }
        }

        if (book == nullptr) {
            cout << "Book not found or it wasn't checked out by this borrower.\n";
            return;
        }

        // Return the book
        book->available = true;
        trans->returnBook();
        int fine = trans->calculateFine();
        cout << "Book returned successfully.\n";
        if (fine > 0) {
            cout << "Fine due: $" << fine << "\n";
        } else {
            cout << "No fine due.\n";
        }
    }

    // Function to view all transactions
    void viewTransactions() {
        if (transactions.empty()) {
            cout << "No transactions found.\n";
            return;
        }
        
        for (const auto& t : transactions) {
            cout << t.borrower->name << " borrowed \"" << t.book->title << "\" on "
                 << ctime(&t.checkoutDate) << (t.returned ? "Returned" : "Not returned") << "\n";
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n===========================================\n";
    cout << "Library Management System\n";
    cout << "===========================================\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Register Borrower\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. View Transactions\n";
    cout << "7. Exit\n";
    cout << "===========================================\n";
}

// Main function to run the program
int main() {
    Library lib;
    int choice;

    bool flag = true;

    // Main menu loop
    do {
        if(flag) displayMenu();

        cout << endl;

        cout << "Enter your choice: " ;

        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string title, author, ISBN;
                    cout << "Enter book title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter author name: ";
                    getline(cin, author);
                    cout << "Enter ISBN: ";
                    getline(cin, ISBN);
                    lib.addBook(title, author, ISBN);
                    cout << "Book added successfully!\n";
                    break;
                }
            case 2:
                lib.searchBook();
                break;
            case 3:
                lib.registerBorrower();
                break;
            case 4:
                lib.checkoutBook();
                break;
            case 5:
                lib.returnBook();
                break;
            case 6:
                lib.viewTransactions();
                break;
            case 7:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }

        flag = false;

    } while (choice != 7);

    return 0;
}
