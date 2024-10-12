// This header file defines the extPersonType class, which extends personType.
// It includes additional information such as birthdate, address, phone number,
// and relationship status. The class also provides methods to access and modify 
// these attributes. Code outlined by ChatGPT and modified by the coder.
/*
#pragma once
#include "personType.h"
#include "dateType.h"   
#include "addressType.h" 
#include <string>
#include <iostream>

class extPersonType : public PersonType {
private:

    DateType birthdate;                                     // Birthdate: Composition of DateType object
    AddressType address;                                    // Address:   Composition of AddressType object
    std::string phoneNumber;                                // Phone number
    std::string relationship;                               // Relationship

public:
    
    extPersonType(const std::string& fName = "", 
                  const std::string& lName = "",
                  int month = 1, int day = 1, 
                  int year = 1900,
                  const std::string& street = "", 
                  const std::string& city = "",
                  const std::string& state = "XX", 
                  int zip = 10000,
                  const std::string& phone = "None", 
                  const std::string& relation = "None");    // Constructor with default parameters

    void setPhoneNumber(const std::string& phone);          // Sets phone number
    void setRelationship(const std::string& relation);      // Sets relationship

    std::string getPhoneNumber() const;                     // Gets phone number
    std::string getRelationship() const;                    // Gets relationhip    
    int getBirthMonth() const;                              // Gets birth month

    void print() const;                                     // Print function
};
*/


#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>

class extPersonType : public PersonType {
private:
    DateType birthdate;                                     // Birthdate: Composition of DateType object
    AddressType address;                                    // Address:   Composition of AddressType object
    std::string phoneNumber;                                // Phone number
    std::string relationship;                               // Relationship

public:
    extPersonType(const std::string& fName = "",
        const std::string& lName = "",
        int month = 1, int day = 1,
        int year = 1900,
        const std::string& street = "",
        const std::string& city = "",
        const std::string& state = "XX",
        int zip = 10000,
        const std::string& phone = "None",
        const std::string& relation = "None");    // Constructor with default parameters

    void setPhoneNumber(const std::string& phone);          // Sets phone number
    void setRelationship(const std::string& relation);      // Sets relationship

    std::string getPhoneNumber() const;                     // Gets phone number
    std::string getRelationship() const;                    // Gets relationship    
    int getBirthMonth() const;                              // Gets birth month

    void print() const;                                     // Print function

    // Overloaded relational operators
    bool operator==(const extPersonType& other) const {
        return (getLastName() == other.getLastName() && getFirstName() == other.getFirstName());
    }

    bool operator!=(const extPersonType& other) const {
        return !(*this == other);
    }

    bool operator>=(const extPersonType& other) const {
        std::string key1 = getLastName() + " " + getFirstName();
        std::string key2 = other.getLastName() + " " + other.getFirstName();
        return key1 >= key2;
    }
};
