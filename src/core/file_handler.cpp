#include "file_handler.h"

using json = nlohmann::json;

bool FileHandler::saveToFile(const std::string& filename, const std::vector<Book>& books, int nextBookId) {
    try {
        json j;
        j["nextBookId"] = nextBookId;
        j["books"] = json::array();

        for (const auto& book : books) {
            json bookJson;
            bookJson["id"] = book.getBookId();
            bookJson["title"] = book.getTitle();
            bookJson["author"] = book.getAuthor();
            bookJson["year"] = book.getYear();
            bookJson["available"] = book.isAvailable();
            j["books"].push_back(bookJson);
        }

        std::ofstream file(filename);
        if (!file) {
            return false;
        }
        file << j.dump(4);  // Pretty print with 4 spaces indentation
        return true;
    }
    catch (...) {
        return false;
    }
}

bool FileHandler::loadFromFile(const std::string& filename, std::vector<Book>& books, int& nextBookId) {
    try {
        std::ifstream file(filename);
        if (!file) {
            return false;
        }

        json j;
        file >> j;

        books.clear();
        nextBookId = j["nextBookId"];

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
        return false;
    }
}
