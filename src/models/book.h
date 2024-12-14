#pragma once
#include <string>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    int year;
    bool available;
    int currentBorrowerId;

public:
    // Constructor
    Book(const std::string& title, const std::string& author, int year);

    // Getters
    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool isAvailable() const;
    int getCurrentBorrowerId() const;

    // Setters
    void setId(int id);
    void setAvailability(bool status);
    void setBorrowerId(int userId);

    // Utility methods
    std::string toString() const;
};
