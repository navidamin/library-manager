#pragma once
#include <string>
#include <vector>
#include "../models/book.h"

class FileHandler {
public:
    // Static methods for file operations
    static bool saveToFile(const std::string& filename, const std::vector<Book>& books, int nextId);
    static bool loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextId);

private:
    // Helper methods
    static std::string bookToString(const Book& book);
    static Book stringToBook(const std::string& str);
};
