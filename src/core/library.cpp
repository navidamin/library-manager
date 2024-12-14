#include "library.h"
#include <algorithm>

Library::Library(const std::string& filename)
    : filename(filename), nextBookId(1) {
    loadFromFile();
}

void Library::addBook(const Book& book) {
    Book newBook = book;
    newBook.setId(nextBookId++);
    newBook.setAvailability(true);
    books.push_back(newBook);
    saveToFile();
}

std::vector<Book>& Library::getAllBooks() {
    return books;
}

std::vector<Book> Library::searchByTitle(const std::string& title) const {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

std::vector<Book> Library::searchByAuthor(const std::string& author) const {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

Book* Library::findBookById(int id) {
    for (auto& book : books) {
        if (book.getBookId() == id) {
            return &book;
        }
    }
    return nullptr;
}

bool Library::borrowBook(int bookId) {
    Book* book = findBookById(bookId);
    if (book && book->isAvailable()) {
        book->setAvailability(false);
        saveToFile();
        return true;
    }
    return false;
}

bool Library::returnBook(int bookId) {
    Book* book = findBookById(bookId);
    if (book && !book->isAvailable()) {
        book->setAvailability(true);
        saveToFile();
        return true;
    }
    return false;
}

bool Library::saveToFile() const {
    return FileHandler::saveToFile(filename, books, nextBookId);
}

bool Library::loadFromFile() {
    return FileHandler::loadFromFile(filename, books, nextBookId);
}
