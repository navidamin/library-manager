/*
 * The library class contains the core of the library functionalities
*/
#pragma once
#include <vector>
#include <string>
#include "../models/book.h"
#include "file_handler.h"

class Library {
public:
    // Constructor
    explicit Library(const std::string& filename = "data/library.json");

    // Book management
    void addBook(const Book& book);
    std::vector<Book>& getAllBooks();
    std::vector<Book> searchByTitle(const std::string& title) const;
    std::vector<Book> searchByAuthor(const std::string& author) const;
    Book* findBookById(int id);

    // Borrowing operations
    bool borrowBook(int bookId);
    bool returnBook(int bookId);

    // File operations
    bool saveToFile() const;
    bool loadFromFile();

private:
    std::string filename;
    std::vector<Book> books;
    int nextBookId;
};
