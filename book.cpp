#include "Book.h"
#include <string>
using namespace std;

Book::Book(const string& title, const string& author)
    : isAvailable_(true), averageRating_(0.0), reviewCount_(0) {
      this->title_ = title;
      this->author_ = author;
    }
string Book::getTitle() const { return title_; }
string Book::getAuthor() const { return author_; }
bool Book::isAvailable() const { return isAvailable_; }
double Book::getAverageRating() const { return averageRating_; }
int Book::getReviewCount() const { return reviewCount_; }

bool Book::checkout() {
    if (isAvailable_) {
      isAvailable_ = false;
      return true;
    }
    return false;
}
bool Book::returnBook() {
  if (!isAvailable_) {
    isAvailable_ = true;
    return true;
  }
  return false;
}
bool Book::addReview(int rating) {
  if (rating < 1 || rating > 5) return false;
  double totalPoints = (averageRating_ * reviewCount_) + rating;
  reviewCount_++;
  averageRating_ = totalPoints / reviewCount_;
  return true;
}
