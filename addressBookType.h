// This header file defines the addressBookType class, which manages an 
// online address book using a linked list. It includes methods for 
// initializing entries, adding new contacts, and finding individuals 
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include <string>

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType();                                                                  // Constructor
    void initEntry(const std::string& filename);                                        // Reads from file and initializes entries
    void addEntry(const extPersonType& person);                                         // Adds a new entry (modified for linked list)
    void findPerson(const std::string& lastName) const;                                 // Finds a person by last name
    void findBirthdays(int month) const;                                                // Finds entries with birthdays in a month
    void findRelations(const std::string& relation) const;                              // Finds entries by relationship
    void print() const;                                                                 // Prints all entries
    void addInteractiveEntry();                                                         // New function to add a new entry interactively
    void deleteEntry(const std::string& lastName, const std::string& firstName);        // Deletes an entry
    void saveData(const std::string& filename) const;                                   // Saves data back to the Address Book data file
};



