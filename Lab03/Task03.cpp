#include <iostream>
using namespace std;

class Library
{
    string booklist[50];  
    int availablebooks;
    int borrowedbooks;
    int isborrowed[50];  
public:
    Library()
    {
        availablebooks = 0;
        borrowedbooks = 0;
        
        for (int i = 0; i < 50; i++)
        {
            booklist[i] = "";
            isborrowed[i] = 1; 
        }
    }

    void addbooks()
    {
        int num;
        cout << "Enter the number of books you want to add: ";
        cin >> num;
        cin.ignore();

        if (availablebooks + num > 50)
        {
            cout << "Cannot add more books, library is full!" << endl;
            return;
        }

        for (int i = 0; i < num; i++)
        {
            cout << "Enter the name of book " << (availablebooks + 1) << ": ";
            getline(cin, booklist[availablebooks]);
            isborrowed[availablebooks] = 1; 
            availablebooks++;
        }
    }

    void displaybooks()
    {
        cout << "\nAvailable Books in the Library:\n";
        if (availablebooks == 0)
        {
            cout << "No books available!" << endl;
            return;
        }

        bool anyAvailable = false;
        for (int i = 0; i < availablebooks; i++)
        {
            if (booklist[i] != "" && isborrowed[i] == 1) 
            {
                cout << i + 1 << ") " << booklist[i] << endl;
                anyAvailable = true;
            }
        }
        if (!anyAvailable)
        {
            cout << "No books available!" << endl;
        }
    }

    void borrowbook(string book)
    {
        if (availablebooks == 0)
        {
            cout << "Library is empty. No books available to borrow!" << endl;
            return;
        }

        for (int i = 0; i < availablebooks; i++)
        {
            if (booklist[i] == book && isborrowed[i] == 1)
            {
                isborrowed[i] = 0;
                borrowedbooks++;
                cout << "Book borrowed successfully: " << book << endl;
                return;
            }
        }
        cout << "Book not found or already borrowed!" << endl;
    }

    void returnbook(string book)
    {
        if (borrowedbooks == 0) {
            cout << "No borrowed books to return!" << endl;
            return;
        }

        

        for (int i = 0; i < availablebooks; i++)
        {
            if (booklist[i] == book && isborrowed[i] == 0)
            {
                isborrowed[i] = 1;
                borrowedbooks--;
                cout << "Book returned successfully: " << book << endl;
                return;
            }
        }
        cout << "This book was not borrowed!" << endl;
    }
};

int main()
{
    Library library;
    cout << "Welcome to the Library System!\n" << endl;

    library.addbooks();
    library.displaybooks();

    string book;
    cout << "\nEnter the book name you want to borrow: ";
    getline(cin, book);
    library.borrowbook(book);
    library.displaybooks();

    cout << "\nEnter the book name you want to return: ";
    getline(cin, book);
    library.returnbook(book);
    library.displaybooks();

    return 0;
}
