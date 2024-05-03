#include <string>
#include "book.h"
using namespace mybook;

// Default Constructor
Book::Book()
{
    bookName = "None";
    bookAuthor = "None";
    bookStatus = "None";
    dateStart = "None";
    dateFinish = "None";
}

// Overloaded Constructor
Book::Book(string bookName, string bookAuthor, string bookStatus, string dateStart, string dateFinish)
    : bookName(bookName), bookAuthor(bookAuthor), bookStatus(bookStatus), dateStart(dateStart), dateFinish(dateFinish)
{
    // No need for assignments here, as member initializer list is used
}

// Get Functions
string Book::getName() const
{
    return bookName;
}

string Book::getAuthor() const
{
    return bookAuthor;
}

string Book::getStatus() const
{
    return bookStatus;
}

string Book::getDateStart() const
{
    return dateStart;
}

string Book::getDateFinish() const
{
    return dateFinish;
}

// Set Functions
void Book::setStatus(string bookStatus)
{
    this->bookStatus = bookStatus;
}

void Book::setDateStart(string dateStart)
{
    this->dateStart = dateStart;
}

void Book::setDateFinish(string dateFinish)
{
    this->dateFinish = dateFinish;
}

void Book::setName(string bookName)
{
    this->bookName = bookName;
}

void Book::setAuthor(string bookAuthor)
{
    this->bookAuthor = bookAuthor;
}
