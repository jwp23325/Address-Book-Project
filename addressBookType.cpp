// This file implements the addressBookType class functions defined in the header file.
// The class manages an ordered linked list of extPersonType objects and provides various functionalities
// for managing address book entries.
// This code was outlined using ChatGPT and modified by the coder.

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
void addressBookType::findPerson(const std::string& lastName,const std::string& firstName) const {
    nodeType<extPersonType>* current = first;           // Start at the head of the linked list

    // Create a temporary extPersonType object for comparison
    extPersonType tempPerson(firstName, lastName, 0, 0, 0, "", "", "", 0, "", ""); // Use dummy values for the rest of the fields

    while (current != nullptr) {
        if (current->info == tempPerson) {
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
