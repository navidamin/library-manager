/**
 * @file user_interface.h
 * @brief Implementation of the UI Interface calss
 */

#pragma once
#include <string>



class UserInterface {
public:
    virtual ~UserInterface() = default;

    // Basic I/O operations
    virtual void displayMessage(const std::string& message) = 0;
    virtual void displayError(const std::string& error) = 0;
    virtual std::string getInput() = 0;
    virtual void clear() = 0;
};
