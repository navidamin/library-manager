/*
 * This class encapsulates the file handling functions for saving and loading library.json file
*/

#pragma once
#include <string>
#include "user_interface.h"
#include "../core/library.h"

class TerminalUI : public UserInterface {
public:
    explicit TerminalUI(Library& library);

    // UserInterface implementation
    void displayMessage(const std::string& message) override;
    void displayError(const std::string& error) override;
    std::string getInput() override;
    void clear() override;

    // Main menu
    void showMainMenu();

private:
    Library& library;

    // Menu handlers
    void handleAddBook();
    void handleSearchBooks();
    void handleBorrowBook();
    void handleReturnBook();
    void handleDisplayAllBooks();

    // Helper methods
    void displayBooks(const std::vector<Book>& books);
    int getMenuChoice(int maxChoice);
    void waitForEnter();
};
