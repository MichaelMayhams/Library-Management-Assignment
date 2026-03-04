#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
  public:
        Book(const std::string& title, const std::string& author);

        std::string getTitle() const;
        std:: string getAuthor() const;
        bool isAvailable() const;
        double getAverageRating() const;
        int getReviewCount() const;
        bool checkout();
        bool returnBook();
        bool addReview(int rating);
  private:
        std::string title_;
        std::string author_;
        bool isAvailable_;
        double averageRating_;
        int reviewCount_;
    
};
#endif
