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
    std::string address;                                                // Street
    std::string city;                                                   // City
    std::string state;                                                  // State
    int zipcode;                                                        // Zipcode

    static const std::vector<std::string> validStates;                   // List of valid state abbreviations

public:
   
    AddressType(std::string addr = "", std::string cty = "", 
                std::string st = "XX", int zip = 10000);                // Constructor with default parameters using initialization list
    void setAddress(std::string addr);                                  // Sets street 
    void setCity(std::string cty);                                      // Sets city
    void setState(std::string st);                                      // Sets state
    void setZipcode(int zip);                                           // Sets zipcode

    std::string getAddress() const;                                     // Gets street
    std::string getCity() const;                                        // Gets city
    std::string getState() const;                                       // Gets state
    int getZipcode() const;                                             // Gets zipcode

    void print() const;                                                 // Print method
};



