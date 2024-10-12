#pragma once
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include <string>

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType();                                      // Constructor
    void initEntry(const std::string& filename);            // Reads from file and initializes entries
    void addEntry(const extPersonType& person);             // Adds a new entry (modified for linked list)
    void findPerson(const std::string& lastName) const;     // Finds a person by last name
    void findBirthdays(int month) const;                    // Finds entries with birthdays in a month
    void findRelations(const std::string& relation) const;  // Finds entries by relationship
    void print() const;                                     // Prints all entries
};

