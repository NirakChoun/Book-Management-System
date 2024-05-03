#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "book.h"
using namespace std;
using namespace mybook;

void menu();
void add_book(vector<Book>& bookRecord);
void display_book(const vector<Book>& bookRecord);
string search_book(const vector<Book>& bookRecord, const string& bookToSearch);
void update_book(vector<Book>& bookRecord, const string& bookToUpdate);
void delete_book(vector<Book>& bookRecord, const string& bookToDelete);

int main()
{
    int choice;
    vector<Book> bookRecord;
    bool endProgram = false;
    
    while (!endProgram)
    {
        menu();
        cout << "--------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        switch (choice) {
            case 1:
                add_book(bookRecord);
                break;
            case 2:
                display_book(bookRecord);
                break;
            case 3:
            {
                string searchBook;
                cout << "Enter book name: ";
                getline(cin, searchBook);
                cout << search_book(bookRecord, searchBook);
                break;
            }
            case 4:
            {
                string updateBook;
                cout << "Enter book name: ";
                getline(cin, updateBook);
                update_book(bookRecord, updateBook);
                break;
            }
            case 5:
            {
                string deleteBook;
                cout << "Enter book name: ";
                getline(cin, deleteBook);
                delete_book(bookRecord, deleteBook);
                break;
            }
            case 6:
                cout << "Exiting Program....\n";
                endProgram = true;
                break;
            default:
                cout << "Invalid input.\n";
                break;
        }
    }
    
    return 0;
}

void menu()
{
    cout << "\t\t\t\tControl Panel\n";
    cout << "\n";
    
    cout << "1. Add Book\n";
    cout << "2. Display Books\n";
    cout << "3. Search Book\n";
    cout << "4. Update Book\n";
    cout << "5. Delete Book\n";
    cout << "6. Exit\n";
}

void add_book(vector<Book>& bookRecord)
{
    string name, author, status, dateStart, dateFinish;
    cout << "Book Name : ";
    getline(cin, name);
    
    cout << "\n";
    cout << "Author Name : ";
    getline(cin, author);
    
    cout << "\n";
    cout << "Book Status (Plan to Read / Reading / Finished) : ";
    getline(cin, status);
    
    cout << "\n";
    cout << "Start Date (DD-MM-YYYY), if not yet start, please type None : ";
    getline(cin, dateStart);
    
    cout << "\n";
    cout << "Finish Date (DD-MM-YYYY), if not yet start, please type None : ";
    getline(cin, dateFinish);
    
    Book newBook(name, author, status, dateStart, dateFinish);
    bookRecord.push_back(newBook);
}

void display_book(const vector<Book>& bookRecord)
{
    cout << endl;
    
    cout << left << setw(15) << "Book Name"
             << setw(15) << "Author"
             << setw(15) << "Status"
             << setw(15) << "Start Date"
             << setw(15) << "Finish Date" << endl;

    for (const auto& book : bookRecord)
    {
        cout << left << setw(15) << book.getName()
             << setw(15) << book.getAuthor()
             << setw(15) << book.getStatus()
             << setw(15) << book.getDateStart()
             << setw(15) << book.getDateFinish() << endl;
    }
    cout << endl;
}

string search_book(const vector<Book>& bookRecord, const string& bookToSearch)
{
    for (const auto& book : bookRecord)
    {
        if (book.getName() == bookToSearch)
        {
            return book.getName() + " is found in the book record.\n";
        }
    }
    return bookToSearch + " is NOT FOUND in the book record.\n";
}

void update_book(vector<Book>& bookRecord, const string& bookToUpdate)
{
    for (auto& book : bookRecord)
    {
        if (book.getName() == bookToUpdate)
        {
            int choice;
            cout << "Which info do you want to update?\n";
            cout << "1. Book Name\n"
                 << "2. Book Author\n"
                 << "3. Book Status\n"
                 << "4. Book Date Start\n"
                 << "5. Book Date Finish\n"
                 << "6. Never mind\n";
            cout << "----------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1:
                {
                    string bookName;
                    cout << "Enter new book name: ";
                    getline(cin, bookName);
                    book.setName(bookName);
                    cout << "New name has been set for " << bookToUpdate << endl;
                    break;
                }
                case 2:
                {
                    string author;
                    cout << "Enter new author name: ";
                    getline(cin, author);
                    book.setAuthor(author);
                    cout << "New author has been set for " << bookToUpdate << endl;
                    break;
                }
                case 3:
                {
                    string status;
                    cout << "Enter new book status: ";
                    getline(cin, status);
                    book.setStatus(status);
                    cout << "New status has been set for " << bookToUpdate << endl;
                    break;
                }
                case 4:
                {
                    string dateStart;
                    cout << "Enter new book date start: ";
                    getline(cin, dateStart);
                    book.setDateStart(dateStart);
                    cout << "New date start has been set for " << bookToUpdate << endl;
                    break;
                }
                case 5:
                {
                    string dateFinish;
                    cout << "Enter new book date finish: ";
                    getline(cin, dateFinish);
                    book.setDateFinish(dateFinish);
                    cout << "New date finish has been set for " << bookToUpdate << endl;
                    break;
                }
                case 6:
                    cout << "Returning back to main menu.\n";
                    break;
                default:
                    cout << "Invalid input.\n";
                    break;
            }
        }
    }
}

void delete_book(vector<Book>& bookRecord, const string& bookToDelete)
{
    for (auto iter = bookRecord.begin(); iter != bookRecord.end(); ++iter)
    {
        if (iter->getName() == bookToDelete)
        {
            iter = bookRecord.erase(iter);
            cout << "Deleted successfully.\n";
            return;
        }
    }
    cout << bookToDelete + " is NOT FOUND in the book record.\n";
}
