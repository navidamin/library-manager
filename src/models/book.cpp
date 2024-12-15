/**
 * @file book.cpp
 * @brief Implementation of the Book class methods
 */

#include "book.h"

//====================================================================================
// Constructor Implementation
//====================================================================================

Book::Book(const std::string& title, const std::string& author, int year)
    : bookId(0),            // Will be set by Library class
      title(title),
      author(author),
      year(year),
      available(true),      // New books are always available
      currentBorrowerId(-1) // -1 indicates no borrower
{
}

//====================================================================================
// Getter Implementations
//====================================================================================

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

bool Book::isAvailable() const {
    // Returns true if the book can be borrowed
    return available;
}

int Book::getCurrentBorrowerId() const {
    // Returns -1 if no one has borrowed the book
    return currentBorrowerId;
}

//====================================================================================
// Setter Implementations
//====================================================================================

void Book::setId(int id) {
    // Set the unique identifier for the book
    bookId = id;
}

void Book::setAvailability(bool status) {
    // Update the availability status
    available = status;
}

void Book::setBorrowerId(int userId) {
    // Update the borrower ID and automatically adjust availability
    currentBorrowerId = userId;
    available = (userId == -1);  // Book is available only if there's no borrower
}

//====================================================================================
// Utility Method Implementations
//====================================================================================

std::string Book::toString() const {
    // Create a formatted string representation of the book
    return "Book ID: " + std::to_string(bookId) +
           "\nTitle: " + title +
           "\nAuthor: " + author +
           "\nYear: " + std::to_string(year) +
           "\nStatus: " + (available ? "Available" : "Borrowed") +
           (currentBorrowerId != -1 ? "\nBorrowed by user: " + std::to_string(currentBorrowerId) : "");
}
