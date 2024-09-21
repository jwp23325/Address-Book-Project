// PersonType.h
// This file defines the PersonType class, which includes attributes for a person's first and last name,
// along with methods for setting and getting these attributes, and a method for printing the details.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include <iostream>
#include <string>

class PersonType {
private:
    std::string firstName;
    std::string lastName;

public:
    // Constructor with default parameters
    PersonType(const std::string& fName = "", const std::string& lName = "");

    // Setters
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;

    // Print method
    void print() const;
};
