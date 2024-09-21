// This test file demonstrates the functionality of the AddressType class.
// It includes tests for the default constructor, parameterized constructor, 
// setting invalid states, and setting invalid zip codes.
// The output shows the behavior of the AddressType methods.
// This code was outlined using ChatGPT and modified by the coder.
#pragma once 
#include <iostream>
#include "AddressType.h"

using namespace std;

int main() {
    cout << "Testing default constructor ... " << endl;
    AddressType defAddress;
    defAddress.print();
    cout << endl;

    cout << "Testing constructor with parameters ... " << endl;
    AddressType address("123 South Street", "Newport News", "VA", 23664);
    address.print();
    cout << endl;

    cout << "Testing invalid state (Virginia)... " << endl;
    address.setState("Virginia");
    address.print();
    cout << endl;

    cout << "Testing invalid zipcode (55555555)..." << endl;
    address.setZipcode(55555555);
    address.print();
    cout << endl;

    cout << "Testing valid address ..." << endl;
    address.setAddress("44 East Main Street");
    address.setCity("Hampton");
    address.setState("VA");
    address.setZipcode(23669);
    address.print();
    cout << endl;

    return 0;
}
