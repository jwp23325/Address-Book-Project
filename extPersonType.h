// This header file defines the extPersonType class, which extends personType.
// It includes additional information such as birthdate, address, phone number,
// and relationship status. The class also provides methods to access and modify 
// these attributes. Code outlined by ChatGPT and modified by the coder.

#pragma once
#include "personType.h"
#include "dateType.h"   
#include "addressType.h" 
#include <string>
#include <iostream>

class extPersonType : public PersonType {
private:
    // Composition: dateType and addressType objects
    DateType birthdate;
    AddressType address;

    // Additional member variables
    std::string phoneNumber;
    std::string relationship;

public:
    // Constructor with default parameters
    extPersonType(const std::string& fName = "", const std::string& lName = "",
        int month = 1, int day = 1, int year = 1900,
        const std::string& street = "", const std::string& city = "",
        const std::string& state = "XX", int zip = 10000,
        const std::string& phone = "None", const std::string& relation = "None");

    // Sets phone number
    void setPhoneNumber(const std::string& phone);

    // Sets relationship
    void setRelationship(const std::string& relation);

    // Gets phone number
    std::string getPhoneNumber() const;

    // Gets relationhip
    std::string getRelationship() const;

    // Gets birth month
    int getBirthMonth() const;

    // Print function
    void print() const;
};
