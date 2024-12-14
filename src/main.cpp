#include <iostream>
#include "core/library.h"
#include "ui/terminal_ui.h"

void displayWelcomeMessage() {
    std::cout << "\n====================================\n";
    std::cout << "  Library Management System\n";
    std::cout << "====================================\n\n";
}

int main() {
    // Create library instance
    Library library("data/library.json");

    // Add some initial test data
    Book book1("Walden", "Henry David Thoreau", 1854);
    library.addBook(book1);

    // Display welcome message
    displayWelcomeMessage();

    // Create and run UI
    TerminalUI terminalUI(library);
    terminalUI.showMainMenu();

    return 0;
}
