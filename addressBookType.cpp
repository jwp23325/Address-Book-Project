// This file implements the addressBookType class functions defined in the header file.
// The class manages an ordered linked list of extPersonType objects and provides various functionalities
// for managing address book entries.
// This code was outlined using ChatGPT and modified by the coder.
# pragma once
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

        // Reads and stores relationship
        std::getline(inputFile, relation);

        // Creates a new person
        extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);

        // Adds entry into the linked list
        insert(newPerson);
    }
}
/*
// Add an entry
void addressBookType::addEntry(const extPersonType& person) {
    // Use insert method from orderedLinkedList
    insert(person);
}
*/

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

void addressBookType::addEntry() {
    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    std::cout << "Enter first name: ";
    std::getline(std::cin, fName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lName);

    std::cout << "Enter birth month: ";
    std::cin >> month;
    std::cout << "Enter birth day: ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;

    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "Enter street address: ";
    std::getline(std::cin, street);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::getline(std::cin, state);
    std::cout << "Enter zip code: ";
    std::cin >> zip;
    std::cin.ignore(); // Clear the newline character
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter relationship: ";
    std::getline(std::cin, relation);

    // Create a new entry
    extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);
    insertLast(newPerson); // Insert at the end of the linked list
}

void addressBookType::deleteEntry(const std::string& lastName, const std::string& firstName) {
    extPersonType tempPerson(firstName, lastName, 0, 0, 0, "", "", "", 0, "", "");
    // Use the deleteNode function from orderedLinkedList to remove the entry
    deleteNode(tempPerson);
}

/*
void addressBookType::saveData(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    // Assuming the linked list is implemented with a method to traverse and get the data
    for (const auto& person : *this) {
        outFile << person.getFirstName() << " " << person.getLastName() << " "
            << person.getBirthMonth() << " " << person.getBirthDay() << " "
            << person.getBirthYear() << " " << person.getStreet() << " "
            << person.getCity() << " " << person.getState() << " "
            << person.getZipcode() << " " << person.getPhoneNumber() << " "
            << person.getRelationship() << std::endl;
    }
    outFile.close();
}
*/

void addressBookType::saveData(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    // Manually traverse the linked list using the first node
    nodeType<extPersonType>* current = this->first;
    while (current != nullptr) {
        const extPersonType& person = current->info; // Access the info
        outFile << person.getFirstName() << " " << person.getLastName() << " "
            << person.getBirthMonth() << " " << person.getBirthDay() << " "
            << person.getBirthYear() << " " << person.getStreet() << " "
            << person.getCity() << " " << person.getState() << " "
            << person.getZipcode() << " " << person.getPhoneNumber() << " "
            << person.getRelationship() << std::endl;
        current = current->link; // Move to the next node
    }

    outFile.close();
}

