//
//  book.h
//  Book Management System
//
//  Created by Nirak on 29/4/24.
//

#ifndef book_h
#define book_h
#include <string>
using namespace std;

namespace mybook
{
    class Book
    {
        public:
            // Constructors
            Book();
            Book(string bookName, string bookAuthor, string bookStatus, string dateStart, string dateFinish);
        
            // Get Functions
            string getName() const;
            string getAuthor() const;
            string getStatus() const;
            string getDateStart() const;
            string getDateFinish() const;
            
            // Set Functions
            void setName(string bookName);
            void setAuthor(string bookAuthor);
            void setStatus(string bookStatus);
            void setDateStart(string dateStart);
            void setDateFinish(string dateFinish);
        
        private:
            // Private member variables
            string bookName;
            string bookAuthor;
            string bookStatus;
            string dateStart;
            string dateFinish;
    };
}

#endif /* book_h */
