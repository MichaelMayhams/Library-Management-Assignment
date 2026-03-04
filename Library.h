#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"

class Library {
public:
    Library(const std::string& name);

    std::string getName() const;
    int getBookCount() const;
    bool addBook(const Book& book);
    int findBookIndexByTitle(const std::string& title) const;
    bool checkoutBook(const std::string& title);
    bool returnBook(const std::string& title);
    bool addReviewtoBook(const std::string& title, int rating);
    std::string listBooks() const;

private:
    std::string name_;
    std::vector<Book> books_; // library class has collection of books
    // I avoided using friend to preserve encapsulation.
    //Library interacts with book only through the public methods. 
};
#endif
