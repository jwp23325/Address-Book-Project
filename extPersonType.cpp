// This source file implements the methods defined in the extPersonType class.
// It includes the constructor and member functions to set and get attributes,
// as well as a method to print the information of an extended person.
// Code outlined by ChatGPT and modified by the coder.

#pragma once
#include "extPersonType.h"

// Constructor
extPersonType::extPersonType(const std::string& fName, const std::string& lName,
    int month, int day, int year,
    const std::string& street, const std::string& city,
    const std::string& state, int zip,
    const std::string& phone, const std::string& relation)
    : PersonType(fName, lName),
    birthdate(month, day, year),
    address(street, city, state, zip),
    phoneNumber(phone),
    relationship(relation) {}

// Setter for phone number
void extPersonType::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone; // Set the phone number
}

// Setter for relationship
void extPersonType::setRelationship(const std::string& relation) {
    relationship = relation; // Set the relationship
}

// Getter for phone number
std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

// Getter for relationship
std::string extPersonType::getRelationship() const {
    return relationship;
}

// Getter for birth month
int extPersonType::getBirthMonth() const {
    return birthdate.getMonth();
}

// Getter for birth day
int extPersonType::getBirthDay() const {
    return birthdate.getDay();
}

// Getter for birth year
int extPersonType::getBirthYear() const {
    return birthdate.getYear();
}

// Getter for street
std::string extPersonType::getAddress() const {
    return address.getAddress();
}

// Getter for city
std::string extPersonType::getCity() const {
    return address.getCity();
}

// Getter for state
std::string extPersonType::getState() const {
    return address.getState();
}

// Getter for zip
int extPersonType::getZipcode() const {
    return address.getZipcode();
}

// Print function
void extPersonType::print() const {
    PersonType::print();  // Print the base class information
    std::cout << "Birthdate: " << birthdate.getDay() << "/"
        << birthdate.getMonth() << "/" << birthdate.getYear() << std::endl;
    std::cout << "Address: " << address.getAddress() << ", "
        << address.getCity() << ", "
        << address.getState() << " "
        << address.getZipcode() << std::endl;
    std::cout << "Phone: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}

// Overloaded operators
bool extPersonType::operator==(const extPersonType& other) const {
    return (getFirstName() == other.getFirstName() && getLastName() == other.getLastName());
}

bool extPersonType::operator!=(const extPersonType& other) const {
    return !(*this == other);
}

bool extPersonType::operator>=(const extPersonType& other) const {
    return (getLastName() >= other.getLastName());
}
