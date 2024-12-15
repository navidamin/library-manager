/**
 * @file terminal_ui.h
 * @brief Terminal-based user interface implementation for the Library Management System
 *
 * This class provides a text-based interface for interacting with the library system.
 * It implements the UserInterface abstract class and provides concrete implementations
 * for all required UI operations.
 */

#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include "user_interface.h"
#include "../core/library.h"

class TerminalUI : public UserInterface {
public:
    /**
     * @brief Constructs a new Terminal UI object
     * @param library Reference to the Library object to be managed
     */
    explicit TerminalUI(Library& library);

    //====================================================================================
    // UserInterface Implementation
    //====================================================================================

    /**
     * @brief Displays a message to the user
     * @param message The message to be displayed
     */
    void displayMessage(const std::string& message) override;

    /**
     * @brief Displays an error message to the user
     * @param error The error message to be displayed
     */
    void displayError(const std::string& error) override;

    /**
     * @brief Gets input from the user
     * @return std::string The user's input
     */
    std::string getInput() override;

    /**
     * @brief Clears the terminal screen
     */
    void clear() override;

    //====================================================================================
    // Main Menu Interface
    //====================================================================================

    /**
     * @brief Displays and handles the main menu loop
     */
    void showMainMenu();

private:
    /** Reference to the library being managed */
    Library& library;

    //====================================================================================
    // Menu Action Handlers
    //====================================================================================

    /**
     * @brief Handles the process of adding a new book
     */
    void handleAddBook();

    /**
     * @brief Handles the book search functionality
     */
    void handleSearchBooks();

    /**
     * @brief Handles the book borrowing process
     */
    void handleBorrowBook();

    /**
     * @brief Handles the book return process
     */
    void handleReturnBook();

    /**
     * @brief Handles displaying all books in the library
     */
    void handleDisplayAllBooks();

    //====================================================================================
    // Helper Methods
    //====================================================================================

    /**
     * @brief Displays a formatted list of books
     * @param books Vector of books to display
     */
    void displayBooks(const std::vector<Book>& books);

    /**
     * @brief Gets and validates menu choice from user
     * @param maxChoice Maximum valid choice number
     * @return int The validated user choice
     */
    int getMenuChoice(int maxChoice);

    /**
     * @brief Pauses execution until user presses Enter
     */
    void waitForEnter();
};
