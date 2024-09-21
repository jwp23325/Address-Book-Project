// This file implements the addressBookType class functions defined in the header file.
// The class manages an array of extPersonType objects and provides various functionalities
// for managing address book entries.
// This code was outlined using ChatGPT and modified by the coder.

#include "addressBookType.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Constructor
addressBookType::addressBookType() : length(0), maxLength(500) {}

// Initialize entries from a file
void addressBookType::initEntry(const std::string& filename) {
    std::ifstream inputFile(filename);

    // Returns error if file can not be opened
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // Initializing Variables
    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    // Run while array has room AND not at the end of text file
    while (length < maxLength && inputFile.peek() != EOF) {

        // Reads and stores first and last name
        inputFile >> fName >> lName;                                            

        // Reads and stores birthdate
        inputFile >> month >> day >> year;                                      
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Skips to next line

        // Reads and stores street name
        std::getline(inputFile, street);                                        
        
        // Reads and stores city name
        std::getline(inputFile, city);                                         
        
        // Reads and stores state name
        std::getline(inputFile, state);                                         
        
        // Reads and stores zipcode
        inputFile >> zip;                                                       
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Skips to next line

        // Reads and stores phone number
        std::getline(inputFile, phone);                                         
        
        // Reads and store relationship
        std::getline(inputFile, relation);                                      

        // Cretes a new person
        extPersonType newPerson(fName, lName, month, day, year, street, city, state, zip, phone, relation);

        // Adds entry into array
        addEntry(newPerson);
    }
}

// Add an entry
void addressBookType::addEntry(const extPersonType& person) {

    // 
    if (length < maxLength) {
        addressList[length] = person;
        length++;
    }
    else {
        std::cerr << "Address book is full!" << std::endl;
    }
}

// Find a person by last name
void addressBookType::findPerson(const std::string& lastName) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getLastName() == lastName) {
            addressList[i].print();
            return;
        }
    }
    std::cout << "Person not found." << std::endl;
}

// Find entries with birthdays in a given month
void addressBookType::findBirthdays(int month) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) {
            std::cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << std::endl;
        }
    }
}

// Find entries by relationship
void addressBookType::findRelations(const std::string& relation) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getRelationship() == relation) {
            std::cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << std::endl;
        }
    }
}

// Print all entries
void addressBookType::print() const {
    for (int i = 0; i < length; i++) {
        addressList[i].print();
        std::cout << std::endl;
    }
}

// Sort entries by last name
void addressBookType::sortEntries() {
    for (int current = 1; current < length; current++) {
        int index = current;
        bool placeFound = false;

        while (index > 0 && !placeFound) {
            if (addressList[index].getLastName() < addressList[index - 1].getLastName()) {
                std::swap(addressList[index], addressList[index - 1]);
                index--;
            }
            else {
                placeFound = true;
            }
        }
    }
}
