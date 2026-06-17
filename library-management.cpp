#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book Class
class Book {
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};

// Member Class
class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) {
        memberID = id;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Add Book
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

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    // Add Member
    void addMember() {
        int id;
        string name;

        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "Member Added Successfully!\n";
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "Enter Book ID to Issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.bookID == id) {
                if (!book.issued) {
                    book.issued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book Already Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "Enter Book ID to Return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.bookID == id) {
                if (book.issued) {
                    book.issued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book Was Not Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    // Search by Title
    void searchByTitle() {
        string title;

        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);

        bool found = false;

        for (auto book : books) {
            if (book.title == title) {
                cout << "\nBook ID: " << book.bookID
                     << "\nTitle: " << book.title
                     << "\nAuthor: " << book.author
                     << "\nStatus: "
                     << (book.issued ? "Issued" : "Available")
                     << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "No Book Found!\n";
    }

    // Search by Author
    void searchByAuthor() {
        string author;

        cin.ignore();
        cout << "Enter Author Name: ";
        getline(cin, author);

        bool found = false;

        for (auto book : books) {
            if (book.author == author) {
                cout << "\nBook ID: " << book.bookID
                     << "\nTitle: " << book.title
                     << "\nAuthor: " << book.author
                     << "\nStatus: "
                     << (book.issued ? "Issued" : "Available")
                     << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "No Book Found!\n";
    }

    // Display Books
    void displayBooks() {
        cout << "\n----- Books List -----\n";

        for (auto book : books) {
            cout << "ID: " << book.bookID
                 << " | Title: " << book.title
                 << " | Author: " << book.author
                 << " | Status: "
                 << (book.issued ? "Issued" : "Available")
                 << endl;
        }
    }

    // Display Members
    void displayMembers() {
        cout << "\n----- Members List -----\n";

        for (auto member : members) {
            cout << "ID: " << member.memberID
                 << " | Name: " << member.name << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by Title\n";
        cout << "6. Search Book by Author\n";
        cout << "7. Display Books\n";
        cout << "8. Display Members\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.addMember();
            break;
        case 3:
            lib.issueBook();
            break;
        case 4:
            lib.returnBook();
            break;
        case 5:
            lib.searchByTitle();
            break;
        case 6:
            lib.searchByAuthor();
            break;
        case 7:
            lib.displayBooks();
            break;
        case 8:
            lib.displayMembers();
            break;
        case 9:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}
