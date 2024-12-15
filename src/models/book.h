/**
 * @file book.h
 * @brief Defines the Book class for representing books in the Library Management System
 *
 * This class encapsulates all the properties and behaviors of a book entity,
 * including its metadata (title, author, year) and circulation status (availability,
 * current borrower).
 */

#pragma once
#include <string>

class Book {
private:
    //====================================================================================
    // Member Variables
    //====================================================================================

    int bookId;              ///< Unique identifier for the book
    std::string title;       ///< Title of the book
    std::string author;      ///< Author of the book
    int year;               ///< Publication year
    bool available;         ///< Availability status (true if book can be borrowed)
    int currentBorrowerId;  ///< ID of current borrower (-1 if not borrowed)

public:
    //====================================================================================
    // Constructor
    //====================================================================================

    /**
     * @brief Constructs a new Book object
     * @param title The title of the book
     * @param author The author of the book
     * @param year The publication year
     * @note bookId is initialized to 0 and will be set by the Library class
     * @note available is initialized to true
     * @note currentBorrowerId is initialized to -1 (no borrower)
     */
    Book(const std::string& title, const std::string& author, int year);

    //====================================================================================
    // Getters
    //====================================================================================

    /**
     * @brief Get the unique identifier of the book
     * @return int The book's ID
     */
    int getBookId() const;

    /**
     * @brief Get the title of the book
     * @return std::string The book's title
     */
    std::string getTitle() const;

    /**
     * @brief Get the author of the book
     * @return std::string The book's author
     */
    std::string getAuthor() const;

    /**
     * @brief Get the publication year of the book
     * @return int The book's publication year
     */
    int getYear() const;

    /**
     * @brief Check if the book is available for borrowing
     * @return bool true if available, false if currently borrowed
     */
    bool isAvailable() const;

    /**
     * @brief Get the ID of the current borrower
     * @return int The current borrower's ID, or -1 if not borrowed
     */
    int getCurrentBorrowerId() const;

    //====================================================================================
    // Setters
    //====================================================================================

    /**
     * @brief Set the book's unique identifier
     * @param id The new ID to set
     */
    void setId(int id);

    /**
     * @brief Set the book's availability status
     * @param status The new availability status
     */
    void setAvailability(bool status);

    /**
     * @brief Set the current borrower's ID
     * @param userId The ID of the borrower, or -1 to mark as returned
     * @note This automatically updates the availability status
     */
    void setBorrowerId(int userId);

    //====================================================================================
    // Utility Methods
    //====================================================================================

    /**
     * @brief Creates a string representation of the book
     * @return std::string Formatted string containing all book information
     */
    std::string toString() const;
};
