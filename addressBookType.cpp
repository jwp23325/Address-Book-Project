// This file implements the addressBookType class functions defined in the header file.
// The class manages an ordered linked list of extPersonType objects and provides various functionalities
// for managing address book entries.
// This code was outlined using ChatGPT and modified by the coder.

/*
#include "addressBookType.h"
#include <iostream>
#include <fstream>
#include <limits>

// Constructor
addressBookType::addressBookType() : orderedLinkedList<extPersonType>() {}

// Initialize entries from a file
void addressBookType::initEntry(const std::string& filename) {
    std::ifstream inputFile(filename);

    // Returns error if file cannot be opened
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // Initializing Variables
    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    // Run while there are entries to read
    while (inputFile.peek() != EOF) {

        // Reads and stores first and last name
        inputFile >> fName >> lName;

        // Reads and stores birthdate
        inputFile >> month >> day >> year;
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');            // Skips to next line

        // Reads and stores street name
        std::getline(inputFile, street);

        // Reads and stores city name
        std::getline(inputFile, city);

        // Reads and stores state name
        std::getline(inputFile, state);

        // Reads and stores zipcode
        inputFile >> zip;
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');            // Skips to next line

        // Reads and stores phone number
        std::getline(inputFile, phone);

        // Reads and store relationship
        std::getline(inputFile, relation);

        // Creates a new person
        extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);

        // Adds entry into the linked list
        addEntry(newPerson);
    }
}

// Add an entry
void addressBookType::addEntry(const extPersonType& person)
{
    // Use insert method from orderedLinkedList
    insert(person);
}

// Find a person by last name
void addressBookType::findPerson(const std::string& lastName) const {
    nodeType<extPersonType>* current = first;           // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getLastName() == lastName) {
            current->info.print();
            return;
        }
        current = current->link;                        // Move to the next node
    }
    std::cout << "Person not found." << std::endl;
}

// Find entries with birthdays in a given month
void addressBookType::findBirthdays(int month) const {
    nodeType<extPersonType>* current = first;           // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link;                        // Move to the next node
    }
}

// Find entries by relationship
void addressBookType::findRelations(const std::string& relation) const {
    nodeType<extPersonType>* current = first;           // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getRelationship() == relation) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link;                        // Move to the next node
    }
}

// Print all entries
void addressBookType::print() const {
    nodeType<extPersonType>* current = first;           // Start at the head of the linked list

    while (current != nullptr) {
        current->info.print();                          // Print the info of the current person
        std::cout << std::endl;
        current = current->link;                        // Move to the next node
    }
}

*/
#include "addressBookType.h"
#include <iostream>
#include <fstream>
#include <limits>

// Constructor
addressBookType::addressBookType() : orderedLinkedList<extPersonType>() {}

// Initialize entries from a file
void addressBookType::initEntry(const std::string& filename) {
    std::ifstream inputFile(filename);

    // Returns error if file cannot be opened
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // Initializing Variables
    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    // Run while there are entries to read
    while (inputFile.peek() != EOF) {

        // Reads and stores first and last name
        inputFile >> fName >> lName;

        // Reads and stores birthdate
        inputFile >> month >> day >> year;
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skips to next line

        // Reads and stores street name
        std::getline(inputFile, street);

        // Reads and stores city name
        std::getline(inputFile, city);

        // Reads and stores state name
        std::getline(inputFile, state);

        // Reads and stores zipcode
        inputFile >> zip;
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skips to next line

        // Reads and stores phone number
        std::getline(inputFile, phone);

        // Reads and store relationship
        std::getline(inputFile, relation);

        // Creates a new person
        extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);

        // Adds entry into the linked list
        addEntry(newPerson);
    }
}

// Add an entry
void addressBookType::addEntry(const extPersonType& person) {
    // Use insert method from orderedLinkedList
    insert(person);
}

// Find a person by last name
void addressBookType::findPerson(const std::string& lastName) const {
    nodeType<extPersonType>* current = first; // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getLastName() == lastName) {
            current->info.print();
            return;
        }
        current = current->link; // Move to the next node
    }
    std::cout << "Person not found." << std::endl;
}

// Find entries with birthdays in a given month
void addressBookType::findBirthdays(int month) const {
    nodeType<extPersonType>* current = first; // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link; // Move to the next node
    }
}

// Find entries by relationship
void addressBookType::findRelations(const std::string& relation) const {
    nodeType<extPersonType>* current = first; // Start at the head of the linked list

    while (current != nullptr) {
        if (current->info.getRelationship() == relation) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link; // Move to the next node
    }
}

// Print all entries
void addressBookType::print() const {
    nodeType<extPersonType>* current = first; // Start at the head of the linked list

    while (current != nullptr) {
        current->info.print(); // Print the info of the current person
        std::cout << std::endl;
        current = current->link; // Move to the next node
    }
}

// Add a new entry interactively
void addressBookType::addInteractiveEntry() {
    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    std::cout << "Enter first name: ";
    std::cin >> fName;
    std::cout << "Enter last name: ";
    std::cin >> lName;
    std::cout << "Enter birth date (month day year): ";
    std::cin >> month >> day >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input

    std::cout << "Enter street address: ";
    std::getline(std::cin, street);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::getline(std::cin, state);
    std::cout << "Enter ZIP code: ";
    std::cin >> zip;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter relationship: ";
    std::getline(std::cin, relation);

    // Create new person and add to address book
    extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);
    addEntry(newPerson);
    std::cout << "Entry added successfully!" << std::endl;
}

// Deletes an entry based on the provided names
void addressBookType::deleteEntry(const std::string& lastName, const std::string& firstName) {
    // Create a temporary node to search for the entry
    nodeType<extPersonType>* current = first;
    nodeType<extPersonType>* trailCurrent = nullptr; // Pointer to the node before current

    while (current != nullptr) {
        if (current->info.getLastName() == lastName && current->info.getFirstName() == firstName) {
            // If found, delete the node
            if (current == first) { // If it's the first node
                first = first->link;
                if (first == nullptr) { // If list becomes empty
                    last = nullptr;
                }
                delete current;
            }
            else { // If it's not the first node
                trailCurrent->link = current->link;
                if (current == last) { // If it's the last node
                    last = trailCurrent;
                }
                delete current;
            }
            std::cout << "Entry deleted successfully!" << std::endl;
            return;
        }
        trailCurrent = current;
        current = current->link; // Move to the next node
    }
    std::cout << "Entry not found." << std::endl;
}

// Saves the address book data back to the file
void addressBookType::saveData(const std::string& filename) const {
    std::ofstream outputFile(filename);

    if (!outputFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    nodeType<extPersonType>* current = first; // Start at the head of the linked list

    while (current != nullptr) {
        const extPersonType& person = current->info;

        outputFile << person.getFirstName() << " "
            << person.getLastName() << "\n"
            << person.getBirthMonth() << " "
            << person.getBirthDay() << " "
            << person.getBirthYear() << "\n"
            << person.getStreet() << "\n"
            << person.getCity() << "\n"
            << person.getState() << "\n"
            << person.getZip() << "\n"
            << person.getPhone() << "\n"
            << person.getRelationship() << "\n";

        current = current->link; // Move to the next node
    }

    std::cout << "Data saved successfully!" << std::endl;
}

