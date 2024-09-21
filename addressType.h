// This header file defines the AddressType class, which represents a physical address.
// It includes methods for setting and getting address details, 
// as well as validation for state abbreviations and zip codes.
// This code was outlined using ChatGPT and modified by the coder.


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class AddressType {
private:
    std::string address;
    std::string city;
    std::string state;
    int zipcode;

    // List of valid state abbreviations
    static const std::vector<std::string> validStates;

public:
    // Constructor with default parameters using initialization list
    AddressType(std::string addr = "", std::string cty = "", std::string st = "XX", int zip = 10000);

    // Setters
    void setAddress(std::string addr);
    void setCity(std::string cty);
    void setState(std::string st);
    void setZipcode(int zip);

    // Getters
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    int getZipcode() const;

    // Print method
    void print() const;
};



