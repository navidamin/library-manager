# Library Management System

A simple command-line library management system implemented in C++. This application allows you to manage books, track their availability, and handle basic library operations.

## Features

- Add new books to the library
- Search books by title or author
- Borrow and return books
- Persistent storage using JSON format
- Command-line interface for easy interaction

## Prerequisites

- CMake (version 3.12 or higher)
- C++ compiler with C++17 support
- nlohmann/json library (single header, included in the project)

## Building the Project

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure the project with CMake:
```bash
cmake ..
```

3. Build the project:
```bash
make
```

## Running the Application

After building, you can run the application from the build directory:
```bash
./LibraryManagementSystem
```

The program will automatically create a data directory and initialize the library.json file if it doesn't exist.

## Project Structure

```
├── CMakeLists.txt
├── data
│   └── library.json
├── README.md
└── src
    ├── core/
    │   ├── file_handler.cpp
    │   ├── file_handler.h
    │   ├── library.cpp
    │   └── library.h
    ├── main.cpp
    ├── models/
    │   ├── book.cpp
    │   ├── book.h
    └── ui/
        ├── terminal_ui.cpp
        ├── terminal_ui.h
        └── user_interface.h
```

## Installation

To install the application system-wide:
```bash
cd build
sudo make install
```

This will install:
- The executable to `/usr/local/bin`
- Data files to `/usr/local/share/LibraryManagementSystem/data`

