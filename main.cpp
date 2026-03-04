#include <iostream>
#include "Library.h"
#include "Book.h"

using namespace std;
int main() {
  Library myLibrary("City Central Library");
  //create books
  Book b1("The Great Gatsby", "F. Scott Fitzgerald");
  Book b2("1984", "George Orwell");
  Book b3("The Hobbit", "J.R.R. Tolkien");

//add books
myLibrary.addBook(b1);
myLibrary.addBook(b2);
myLibrary.addBook(b3);

//dupicate attempt
cout << "Adding duplicate '1984': " << (myLibrary.addBook(b2) ? "Success" : "Failed") << endl;

//reviews
myLibrary.addReviewtoBook("The Hobbit", 5);
myLibrary.addReviewtoBook("The Hobbit", 4);
myLibrary.addReviewtoBook("The HObbit", 10); // invalid review

//print final listBooks
cout << "\n-- Library Inventory --\n";
cout << myLibrary.listBooks();
return 0;
}
