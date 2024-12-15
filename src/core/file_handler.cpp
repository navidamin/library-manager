/**
 * @file file_handler.cpp
 * @brief Implementation of the FileHandler class methods
 */

#include "file_handler.h"

using json = nlohmann::json;

//====================================================================================
// Public File Operations Implementation
//====================================================================================

bool FileHandler::saveToFile(const std::string& filename, const std::vector<Book>& books, int nextBookId) {
    try {
        // Create JSON object and set nextBookId
        json j;
        j["nextBookId"] = nextBookId;
        j["books"] = json::array();

        // Convert each book to JSON format
        for (const auto& book : books) {
            json bookJson;
            bookJson["id"] = book.getBookId();
            bookJson["title"] = book.getTitle();
            bookJson["author"] = book.getAuthor();
            bookJson["year"] = book.getYear();
            bookJson["available"] = book.isAvailable();
            j["books"].push_back(bookJson);
        }

        // Write to file with pretty printing
        std::ofstream file(filename);
        if (!file) {
            return false;  // Failed to open file
        }
        file << j.dump(4);  // Pretty print with 4 spaces indentation
        return true;
    }
    catch (...) {
        // Catch all exceptions and return false
        return false;
    }
}

bool FileHandler::loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextBookId) {
    try {
        // Open and parse JSON file
        std::ifstream file(filename);
        if (!file) {
            return false;  // Failed to open file
        }

        json j;
        file >> j;

        // Clear existing books and load new data
        books.clear();
        nextBookId = j["nextBookId"];

        // Convert JSON objects back to Book objects
        for (const auto& bookJson : j["books"]) {
            Book book(
                bookJson["title"],
                bookJson["author"],
                bookJson["year"]
            );
            book.setId(bookJson["id"]);
            book.setAvailability(bookJson["available"]);
            books.push_back(book);
        }
        return true;
    }
    catch (...) {
        // Catch all exceptions and return false
        return false;
    }
}
