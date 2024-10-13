/*

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
    void addEntry();                                        // New function to add a new entry interactively
};
*/

#ifndef H_addressBookType
#define H_addressBookType

#include "orderedLinkedList.h"
#include "extPersonType.h"
#include <string>
#include <fstream>

class addressBookType : public orderedLinkedList<extPersonType>
{
public:
    void initEntry(const std::string& filename); // Assuming you have this function to initialize
    void print() const; // Assuming you have this function to print entries
    void findPerson(const std::string& lastName) const; // Assuming you have this function
    void findBirthdays(int month) const; // Assuming you have this function
    void findRelations(const std::string& relation) const; // Assuming you have this function

    void addEntry(); // Adds a new entry interactively
    void deleteEntry(const std::string& lastName, const std::string& firstName); // Deletes an entry
    void saveData(const std::string& filename) const; // Saves data to file automatically
};

#endif


