#include "Library.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

Library::Library(const string& name) : name_(name) {}

string Library::getName() const { return name_; }

int Library::getBookCount() const { return static_cast<int>(books_.size()); }

bool Library::addBook(const Book& book) {
  if (findBookIndexByTitle(book.getTitle()) != -1) {
    return false;
  }
  books_.push_back(book);
  return true;
}
int Library::findBookIndexByTitle(const string& title) const {
  for (size_t i = 0; i < books_.size(); ++i) {
    if (books_[i].getTitle() == title) {
      return static_cast<int>(i);
    }
  }
  return -1;
}
bool Library::checkoutBook(const string& title) {
  int index = findBookIndexByTitle(title);
  if (index == -1) return false;
  return books_[index].checkout();
}
bool Library::returnBook(const string& title) {
  int index = findBookIndexByTitle(title);
  if (index == -1) return false;
  return books_[index].returnBook(); 
}
bool Library::addReviewtoBook(const string& title, int rating) {
  int index = findBookIndexByTitle(title);
  if (index == -1) return false;
  return books_[index].addReview(rating);
}
string Library::listBooks() const {
  stringstream ss;
  ss << "Library: " << name_ << "\n";
  for (const auto& book : books_) {
    ss << "Title: " << book.getTitle()
       << " | Author: " << book.getAuthor()
       << " | Available: " << (book.isAvailable() ? "Yes" : "No")
       << " | Rating: " << fixed << setprecision(1) << book.getAverageRating()
       << " (" << book.getReviewCount() << " reviews)\n";
  }
  return ss.str();
}
