#pragma once
#include "extPersonType.h"
#include <string>

class addressBookType {
private:
    extPersonType addressList[500]; // Array to hold extPersonType objects
    int length; // Current number of entries
    int maxLength; // Maximum entries allowed

public:
    addressBookType(); // Constructor
    void initEntry(const std::string& filename); // Reads from file and initializes entries
    void addEntry(const extPersonType& person); // Adds a new entry
    void findPerson(const std::string& lastName) const; // Finds a person by last name
    void findBirthdays(int month) const; // Finds entries with birthdays in a month
    void findRelations(const std::string& relation) const; // Finds entries by relationship
    void print() const; // Prints all entries
    void sortEntries(); // Sorts entries by last name
};
