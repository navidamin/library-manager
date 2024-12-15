/*
 * This class encapsulates the file handling functions for saving and loading library.json file
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
    // Static methods for file operations
    static bool saveToFile(const std::string& filename, const std::vector<Book>& books, int nextBookId);
    static bool loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextBookId);

private:
    // Helper methods
    static std::string bookToString(const Book& book);
    static Book stringToBook(const std::string& str);
};
