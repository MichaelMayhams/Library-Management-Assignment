## Library Management System (Object-Oriented Design)
## Project Overview
This project implements a small-scale Library Management System in C++. It demonstrates the transition from single-class design to a multi-class system using composition, where a Library class manages a collection of Book objects.

The system focuses on core Object-Oriented Programming (OOP) principles, including:

Encapsulation: Private data members with public interfaces.

Composition: A "has-a" relationship between the Library and its Books.

Const-Correctness: Protecting object state during read-only operations.

Interface Separation: Clear division between declarations (.h) and implementations (.cpp).

## File Structure
Book.h / Book.cpp: Defines the Book class, handling titles, authors, availability, and a mathematically accurate running average for ratings.

Library.h / Library.cpp: Defines the Library class, which manages a std::vector<Book> and provides methods for searching, checking out, and reviewing books.

main.cpp: A driver program that demonstrates the system's functionality and business rule enforcement.

## Technical Features & Design Choices
Advanced C++ Concepts
The this Pointer: Used within constructors to resolve ambiguity between parameter names and private member variables (e.g., this->title_ = title).

Const-Correctness: Methods like listBooks() and findBookIndexByTitle() are marked const to guarantee they do not modify the library state.

Encapsulation Strategy: I chose to avoid friend classes/functions to ensure that the Library interacts with Book objects strictly through their public API, maintaining a clean boundary between the two classes.

Instance-based Design: I avoided static members for the book collection because each Library instance should represent an independent branch with its own unique inventory.

Business Rules
Duplicate Prevention: The Library will not add a book if a title already exists in the collection.

Validation: Reviews are only accepted if the rating is between 1 and 5.

State Management: Books can only be checked out if they are currently available and returned only if they are currently checked out.

## How to Run
In terminal/bash type:
g++ main.cpp Book.cpp Library.cpp -o program
./program
# Library-Management-Assignment
