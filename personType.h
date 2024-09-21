// PersonType.h
// This file defines the PersonType class, which includes attributes for a person's first and last name,
// along with methods for setting and getting these attributes, and a method for printing the details.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include <iostream>
#include <string>

class PersonType {
private:
    std::string firstName;                                                      // First Name
    std::string lastName;                                                       // Last Name

public:

    PersonType(const std::string& fName = "", const std::string& lName = "");   // Constructor with default parameters
    void setFirstName(const std::string& fName);                                // Sets first name
    void setLastName(const std::string& lName);                                 // Sets last name
    std::string getFirstName() const;                                           // Gets first name
    std::string getLastName() const;                                             // Gets last nme
    void print() const;                                                         // Print method
};
