/*


// This source file implements the methods defined in the extPersonType class.
// It includes the constructor and member functions to set and get attributes,
// as well as a method to print the information of an extended person.
// Code outlined by ChatGPT and modified by the coder.

#include "extPersonType.h"

// Constructor with default parameters
extPersonType::extPersonType(const std::string& fName, 
                             const std::string& lName,
                             int month, int day, 
                             int year,
                             const std::string& street,
                             const std::string& city,
                             const std::string& state,
                             int zip,
                             const std::string& phone, 
                             const std::string& relation)

    : PersonType(fName, lName),
    birthdate(month, day, year),
    address(street, city, state, zip),
    phoneNumber(phone),
    relationship(relation) {}

// Sets phone number
void extPersonType::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

// Sets relationship
void extPersonType::setRelationship(const std::string& relation) {
    if (relation == "Family" || relation == "Friend" || relation == "Business") {
        relationship = relation;
    }
    else {
        relationship = "None";
    }
}

// Gets phone number
std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

// Gets relationship
std::string extPersonType::getRelationship() const {
    return relationship;
}

// Gets birth month
int extPersonType::getBirthMonth() const {
    return birthdate.getMonth();
}

// Print function
void extPersonType::print() const {
    PersonType::print(); 
    std::cout << "Birthdate: " << birthdate.getMonth() << "/"
        << birthdate.getDay() << "/" << birthdate.getYear() << std::endl;
    std::cout << "Address: " << address.getAddress() << ", "
        << address.getCity() << ", " << address.getState() << " "
        << address.getZipcode() << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}

*/

#include "extPersonType.h"

// Constructor implementation
extPersonType::extPersonType(const std::string& fName, 
                             const std::string& lName,
                             int month, int day, 
                             int year,
                             const std::string& street, 
                             const std::string& city,
                             const std::string& state, 
                             int zip,
                             const std::string& phone, 
                             const std::string& relation)
    : PersonType(fName, lName), // Call the base class constructor
      birthdate(month, day, year), // Initialize birthdate
      address(street, city, state, zip), // Initialize address
      phoneNumber(phone), // Initialize phone number
      relationship(relation) // Initialize relationship
{}

// Overload the == operator
bool extPersonType::operator==(const extPersonType& other) const {
    return (this->getLastName() == other.getLastName() && 
            this->getFirstName() == other.getFirstName());
}

// Overload the != operator
bool extPersonType::operator!=(const extPersonType& other) const {
    return !(*this == other);  // Utilizing the == operator
}

// Overload the >= operator
bool extPersonType::operator>=(const extPersonType& other) const {
    std::string thisKey = this->getLastName() + " " + this->getFirstName();
    std::string otherKey = other.getLastName() + " " + other.getFirstName();
    return thisKey >= otherKey;
}

// Set phone number
void extPersonType::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

// Set relationship
void extPersonType::setRelationship(const std::string& relation) {
    relationship = relation;
}

// Get phone number
std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

// Get relationship
std::string extPersonType::getRelationship() const {
    return relationship;
}

// Get birth month
int extPersonType::getBirthMonth() const {
    return birthdate.getMonth();
}

// Print function
void extPersonType::print() const {
    std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
    std::cout << "Birthdate: ";
    birthdate.print();
    std::cout << "Address: ";
    address.print();
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}
