#include "book.h"

Book::Book(const std::string& title, const std::string& author, int year)
    : bookId(0),  // Will be set by Library class
      title(title),
      author(author),
      year(year),
      available(true),
      currentBorrowerId(-1)  // -1 indicates no borrower
{
}

// Getters
int Book::getBookId() const {
    return bookId;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

// Checks if the book is available
bool Book::isAvailable() const {
    return available;
}

// Retrieves the current Borrwers's ID
int Book::getCurrentBorrowerId() const {
    return currentBorrowerId;
}

// Setters
void Book::setId(int id) {
    bookId = id;
}

void Book::setAvailability(bool status) {
    available = status;
}

void Book::setBorrowerId(int userId) {
    currentBorrowerId = userId;
    available = (userId == -1);  // Book is available if there's no borrower
}

// Utility methods
std::string Book::toString() const {
    return "Book ID: " + std::to_string(bookId) +
           "\nTitle: " + title +
           "\nAuthor: " + author +
           "\nYear: " + std::to_string(year) +
           "\nStatus: " + (available ? "Available" : "Borrowed") +
           (currentBorrowerId != -1 ? "\nBorrowed by user: " + std::to_string(currentBorrowerId) : "");
}
