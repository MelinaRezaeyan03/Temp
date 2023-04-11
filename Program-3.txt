#include <iostream>

#include <iostream>
#include <string>
using namespace std;

struct Book {
    string name;
    Book* prev;
    Book* next;
    Book(string name) {
        this->name = name;
        prev = nullptr;
        next = nullptr;
    }
};

class Library {
private:
    Book* left;
    Book* right;
    int size;
public:
    Library() {
        left = nullptr;
        right = nullptr;
        size = 0;
    }
    void AddLeft(string name) {
        Book* newBook = new Book(name);
        if (left == nullptr) {
            left = newBook;
            right = newBook;
        }
        else {
            newBook->next = left;
            left->prev = newBook;
            left = newBook;
        }
        size++;
    }
    void AddRight(string name) {
        Book* newBook = new Book(name);
        if (right == nullptr) {
            left = newBook;
            right = newBook;
        }
        else {
            newBook->prev = right;
            right->next = newBook;
            right = newBook;
        }
        size++;
    }
    void DeleteLeft() {
        if (left != nullptr) {
            Book* deleteBook = left;
            left = left->next;
            if (left != nullptr) {
                left->prev = nullptr;
            }
            else {
                right = nullptr;
            }
            delete deleteBook;
            size--;
        }
    }
    void Exit() {
        cout << "Number of books in the library: " << size << endl;
        cout << "Books in the library: ";
        Book* current = left;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main()
{
    cout << "Enter the number of books: ";
    int n;
    cin >> n;

    Library library;
    for (int i = 0; i < n; i++) {
        string bookName;
        cout << "Book " << i << ":";
        cin >> bookName;
        library.AddRight(bookName);
    }

    string command;
    while (cin >> command) {
        cout << "Enter command name: ";
        if (command == "AddLeft") {
            string bookName;
            cin >> bookName;
            library.AddLeft(bookName);
        }
        else if (command == "AddRight") {
            string bookName;
            cin >> bookName;
            library.AddRight(bookName);
        }
        else if (command == "DeleteLeft") {
            library.DeleteLeft();
        }
        else if (command == "Exit") {
            library.Exit();
            break;
        }
    }
}
