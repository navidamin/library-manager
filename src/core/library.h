/**
 * @file library.h
 * @brief Core library management functionality
 *
 * This class serves as the main interface for library operations, managing
 * the collection of books, handling search operations, and coordinating
 * borrowing/returning of books. It also handles persistence through FileHandler.
 */

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "../models/book.h"
#include "file_handler.h"

class Library {
public:
    //====================================================================================
    // Constructor
    //====================================================================================

    /**
     * @brief Constructs a new Library object
     * @param filename Path to the library data file (defaults to "data/library.json")
     * @note Automatically loads existing data from file if present
     */
    explicit Library(const std::string& filename = "data/library.json");

    //====================================================================================
    // Book Management
    //====================================================================================

    /**
     * @brief Adds a new book to the library
     * @param book The book to add
     * @note Automatically assigns a unique ID and saves to file
     */
    void addBook(const Book& book);

    /**
     * @brief Gets all books in the library
     * @return std::vector<Book>& Reference to the books collection
     */
    std::vector<Book>& getAllBooks();

    /**
     * @brief Searches for books by title
     * @param title The title to search for (partial match)
     * @return std::vector<Book> Vector of matching books
     */
    std::vector<Book> searchByTitle(const std::string& title) const;

    /**
     * @brief Searches for books by author
     * @param author The author to search for (partial match)
     * @return std::vector<Book> Vector of matching books
     */
    std::vector<Book> searchByAuthor(const std::string& author) const;

    /**
     * @brief Finds a book by its ID
     * @param id The book ID to search for
     * @return Book* Pointer to the found book, or nullptr if not found
     */
    Book* findBookById(int id);

    //====================================================================================
    // Borrowing Operations
    //====================================================================================

    /**
     * @brief Marks a book as borrowed
     * @param bookId ID of the book to borrow
     * @return bool true if successful, false if book not found or unavailable
     */
    bool borrowBook(int bookId);

    /**
     * @brief Marks a book as returned
     * @param bookId ID of the book to return
     * @return bool true if successful, false if book not found or already available
     */
    bool returnBook(int bookId);

    //====================================================================================
    // File Operations
    //====================================================================================

    /**
     * @brief Saves the current library state to file
     * @return bool true if save successful
     */
    bool saveToFile() const;

    /**
     * @brief Loads library state from file
     * @return bool true if load successful
     */
    bool loadFromFile();

private:
    std::string filename;     ///< Path to the library data file
    std::vector<Book> books;  ///< Collection of all books
    int nextBookId;           ///< Next available book ID
};
