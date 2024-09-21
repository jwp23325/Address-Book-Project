// This source file implements the methods defined in the extPersonType class.
// It includes the constructor and member functions to set and get attributes,
// as well as a method to print the information of an extended person.
// Code outlined by ChatGPT and modified by the coder.

#include "extPersonType.h"

// Constructor with default parameters
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

// Setter and getter for phoneNumber
void extPersonType::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

// Setter and getter for relationship
void extPersonType::setRelationship(const std::string& relation) {
    if (relation == "Family" || relation == "Friend" || relation == "Business") {
        relationship = relation;
    }
    else {
        relationship = "None";
    }
}

std::string extPersonType::getRelationship() const {
    return relationship;
}

// Getter for birth month
int extPersonType::getBirthMonth() const {
    return birthdate.getMonth();
}

// Print function
void extPersonType::print() const {
    PersonType::print(); // Call the base class print function
    std::cout << "Birthdate: " << birthdate.getMonth() << "/"
        << birthdate.getDay() << "/" << birthdate.getYear() << std::endl;
    std::cout << "Address: " << address.getAddress() << ", "
        << address.getCity() << ", " << address.getState() << " "
        << address.getZipcode() << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}

