#include "terminal_ui.h"
#include <iostream>
#include <limits>
#include <cstdlib>

TerminalUI::TerminalUI(Library& lib) : library(lib) {}

// UserInterface implementation
void TerminalUI::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void TerminalUI::displayError(const std::string& error) {
    std::cout << "\nError: " << error << std::endl;
}

std::string TerminalUI::getInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void TerminalUI::clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Main menu
void TerminalUI::showMainMenu() {
    while (true) {
        clear();
        displayMessage("\n=== Library Management System ===\n");
        displayMessage("1. Add Book");
        displayMessage("2. Search Books");
        displayMessage("3. Borrow Book");
        displayMessage("4. Return Book");
        displayMessage("5. Display All Books");
        displayMessage("6. Exit");

        int choice = getMenuChoice(6);
        switch (choice) {
            case 1: handleAddBook(); break;
            case 2: handleSearchBooks(); break;
            case 3: handleBorrowBook(); break;
            case 4: handleReturnBook(); break;
            case 5: handleDisplayAllBooks(); break;
            case 6: return;
        }
    }
}

void TerminalUI::handleAddBook() {
    displayMessage("\n=== Add New Book ===\n");

    displayMessage("Enter title: ");
    std::string title = getInput();

    displayMessage("Enter author: ");
    std::string author = getInput();

    displayMessage("Enter year: ");
    int year;
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Book newBook(title, author, year);
    library.addBook(newBook);

    displayMessage("Book added successfully!");
    waitForEnter();
}

void TerminalUI::handleSearchBooks() {
    displayMessage("\n=== Search Books ===\n");
    displayMessage("Enter search term (title or author): ");
    std::string searchTerm = getInput();

    auto results = library.searchByTitle(searchTerm);
    auto authorResults = library.searchByAuthor(searchTerm);
    results.insert(results.end(), authorResults.begin(), authorResults.end());

    if (results.empty()) {
        displayMessage("No books found.");
    } else {
        displayBooks(results);
    }
    waitForEnter();
}

void TerminalUI::handleBorrowBook() {
    displayMessage("\n=== Borrow Book ===\n");
    handleDisplayAllBooks();

    displayMessage("\nEnter book ID to borrow: ");
    int bookId;
    std::cin >> bookId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (library.borrowBook(bookId)) {
        displayMessage("Book borrowed successfully!");
    } else {
        displayError("Could not borrow book. It might be unavailable or invalid ID.");
    }
    waitForEnter();
}

void TerminalUI::handleReturnBook() {
    displayMessage("\n=== Return Book ===\n");
    handleDisplayAllBooks();

    displayMessage("\nEnter book ID to return: ");
    int bookId;
    std::cin >> bookId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (library.returnBook(bookId)) {
        displayMessage("Book returned successfully!");
    } else {
        displayError("Could not return book. Please check the ID.");
    }
    waitForEnter();
}

void TerminalUI::handleDisplayAllBooks() {
    displayMessage("\n=== All Books ===\n");
    auto& books = library.getAllBooks();

    if (books.empty()) {
        displayMessage("No books in the library.");
    } else {
        displayBooks(books);
    }
    waitForEnter();
}

// Helper methods
void TerminalUI::displayBooks(const std::vector<Book>& books) {
    for (const auto& book : books) {
        displayMessage("\n" + book.toString());
    }
    displayMessage("");
}

int TerminalUI::getMenuChoice(int maxChoice) {
    while (true) {
        displayMessage("\nEnter your choice (1-" + std::to_string(maxChoice) + "): ");
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            displayError("Invalid input. Please enter a number.");
            continue;
        }

        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }

        displayError("Please enter a number between 1 and " + std::to_string(maxChoice));
    }
}

void TerminalUI::waitForEnter() {
    displayMessage("\nPress Enter to continue...");
    getInput();
}
