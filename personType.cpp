// PersonType.cpp
// This file implements the methods of the PersonType class, which manage a person's first and last names
// and allow for printing their details.
// This code was outlined using ChatGPT and modified by the coder.

#include "PersonType.h"

// Constructor with default parameters
PersonType::PersonType(const std::string& fName, const std::string& lName)
    : firstName(fName), lastName(lName) {}

// Sets the first name
void PersonType::setFirstName(const std::string& fName) {
    firstName = fName;
}

// Sets the last name
void PersonType::setLastName(const std::string& lName) {
    lastName = lName;
}

// Gets the first name
std::string PersonType::getFirstName() const {
    return firstName;
}

// Gets the last name
std::string PersonType::getLastName() const {
    return lastName;
}

// Print method
void PersonType::print() const {
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
}

