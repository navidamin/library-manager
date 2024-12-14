#include "file_handler.h"
#include <fstream>
#include <sstream>

bool FileHandler::saveToFile(const std::string& filename, const std::vector<Book>& books, int nextId) {
    try {
        std::ofstream file(filename);
        if (!file) {
            return false;
        }

        // Write next ID first
        file << nextId << '\n';

        // Write each book on a new line
        for (const Book& book : books) {
            file << bookToString(book) << '\n';
        }

        return true;
    }
    catch (...) {
        return false;
    }
}

bool FileHandler::loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextId) {
    try {
        std::ifstream file(filename);
        if (!file) {
            return false;
        }

        books.clear();

        // Read next ID first
        std::string line;
        if (std::getline(file, line)) {
            nextId = std::stoi(line);
        }

        // Read books
        while (std::getline(file, line)) {
            if (!line.empty()) {
                books.push_back(stringToBook(line));
            }
        }

        return true;
    }
    catch (...) {
        return false;
    }
}

std::string FileHandler::bookToString(const Book& book) {
    // Format: id,title,author,year,isAvailable
    return std::to_string(book.getBookId()) + "," +
           book.getTitle() + "," +
           book.getAuthor() + "," +
           std::to_string(book.getYear()) + "," +
           (book.isAvailable() ? "1" : "0");
}

Book FileHandler::stringToBook(const std::string& str) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> parts;

    // Split the string by commas
    while (std::getline(ss, item, ',')) {
        parts.push_back(item);
    }

    if (parts.size() >= 5) {
        Book book(parts[1], parts[2], std::stoi(parts[3]));
        book.setId(std::stoi(parts[0]));
        book.setAvailability(parts[4] == "1");
        return book;
    }

    // Return a default book if string parsing fails
    return Book("", "", 0);
}
