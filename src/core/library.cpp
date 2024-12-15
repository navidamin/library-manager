/**
 * @file library.cpp
 * @brief Implementation of the Library class methods
 */

#include "library.h"

//====================================================================================
// Constructor Implementation
//====================================================================================

Library::Library(const std::string& filename)
    : filename(filename), nextBookId(1) {
    loadFromFile();  // Load existing data if available
}

//====================================================================================
// Book Management Implementation
//====================================================================================

void Library::addBook(const Book& book) {
    // Create a copy and set its properties
    Book newBook = book;
    newBook.setId(nextBookId++);
    newBook.setAvailability(true);

    // Add to collection and persist
    books.push_back(newBook);
    saveToFile();
}

std::vector<Book>& Library::getAllBooks() {
    return books;
}

std::vector<Book> Library::searchByTitle(const std::string& title) const {
    std::vector<Book> results;
    // Case-insensitive partial match search
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

std::vector<Book> Library::searchByAuthor(const std::string& author) const {
    std::vector<Book> results;
    // Case-insensitive partial match search
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

Book* Library::findBookById(int id) {
    // Linear search for book by ID
    for (auto& book : books) {
        if (book.getBookId() == id) {
            return &book;
        }
    }
    return nullptr;  // Book not found
}

//====================================================================================
// Borrowing Operations Implementation
//====================================================================================

bool Library::borrowBook(int bookId) {
    Book* book = findBookById(bookId);
    if (book && book->isAvailable()) {
        book->setAvailability(false);
        saveToFile();  // Persist the change
        return true;
    }
    return false;  // Book not found or not available
}

bool Library::returnBook(int bookId) {
    Book* book = findBookById(bookId);
    if (book && !book->isAvailable()) {
        book->setAvailability(true);
        saveToFile();  // Persist the change
        return true;
    }
    return false;  // Book not found or already available
}

//====================================================================================
// File Operations Implementation
//====================================================================================

bool Library::saveToFile() const {
    return FileHandler::saveToFile(filename, books, nextBookId);
}

bool Library::loadFromFile() {
    return FileHandler::loadFromFile(filename, books, nextBookId);
}
