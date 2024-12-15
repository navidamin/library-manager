/**
 * @file file_handler.h
 * @brief Handles file operations for the Library Management System
 *
 * This class provides static methods for saving and loading library data to/from
 * JSON files. It handles the serialization and deserialization of Book objects
 * and maintains the system's state between sessions.
 */

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../models/book.h"
#include "../external/json.hpp"

class FileHandler {
public:
    //====================================================================================
    // File Operations
    //====================================================================================

    /**
     * @brief Saves the library data to a JSON file
     * @param filename Path to the target JSON file
     * @param books Vector of books to save
     * @param nextBookId Next available book ID
     * @return bool true if save successful, false otherwise
     * @throws Catches all exceptions and returns false
     */
    static bool saveToFile(const std::string& filename, const std::vector<Book>& books, int nextBookId);

    /**
     * @brief Loads library data from a JSON file
     * @param filename Path to the source JSON file
     * @param[out] books Vector to store loaded books
     * @param[out] nextBookId Variable to store next available book ID
     * @return bool true if load successful, false otherwise
     * @throws Catches all exceptions and returns false
     */
    static bool loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextBookId);

private:
    //====================================================================================
    // Helper Methods
    //====================================================================================

    /**
     * @brief Converts a Book object to its string representation
     * @param book The Book object to convert
     * @return std::string Formatted string containing book data
     */
    static std::string bookToString(const Book& book);

    /**
     * @brief Creates a Book object from its string representation
     * @param str String containing book data
     * @return Book The created Book object
     * @note Returns a default Book if parsing fails
     */
    static Book stringToBook(const std::string& str);
};
