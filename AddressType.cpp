gi// This source file implements the methods of the AddressType class.
// It contains the definitions for the constructor, setters, getters, 
// and a print method for displaying address information.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include "AddressType.h"


// Define the list of valid state abbreviations
const std::vector<std::string> AddressType::validStates = {
    "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID",
    "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS",
    "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK",
    "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV",
    "WI", "WY"
};

// Constructor with default parameters using initialization list
AddressType::AddressType(std::string addr, std::string cty, std::string st, int zip)
    : address(addr), city(cty), state(st), zipcode(zip) {
    // Validates state and zipcode
    setState(st);
    setZipcode(zip);
}

// Sets the Address
void AddressType::setAddress(std::string addr) {
    address = addr;
}

// Sets the City
void AddressType::setCity(std::string cty) {
    city = cty;
}

// Sets the State
void AddressType::setState(std::string st) {
    // Validates state before setting
    if (std::find(validStates.begin(), validStates.end(), st) != validStates.end()) {
        state = st;
    }
    // Sets state to default value
    else {
        state = "XX";
    }
}

// Sets the Zipcode
void AddressType::setZipcode(int zip) {
    // Validates zipcode before setting
    if (zip >= 11111 && zip <= 99999) {
        zipcode = zip;
    }
    // Sets zipcode to default value
    else {
        zipcode = 10000;
    }
}

// Gets the address
std::string AddressType::getAddress() const {
    return address;
}

// Gets the city
std::string AddressType::getCity() const {
    return city;
}

// Gets the state
std::string AddressType::getState() const {
    return state;
}

// Gets the zipcode
int AddressType::getZipcode() const {
    return zipcode;
}

// Print method
void AddressType::print() const {
    std::cout << address << std::endl
        << city << ", " << state << " "
        << zipcode << std::endl;
}

