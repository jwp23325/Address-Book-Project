#pragma once
#include <iostream>
#include <string>
#include <algorithm> // For std::find
#include <vector> // For std::vector


class AddressType
{
private:
	std::string address;
	std::string city;
	std::string state;
	int zipcode;

	// List of valid state abbreviations
	static const std::vector<std::string> validStates;

public:
	// Constructor with default parameters using initialization list
	AddressType(std::string addr = "", std::string cty = "", std::string st = "XX", int zip = 10000)
		: address(addr), city(cty), state(st), zipcode(zip) {
		
		// Validates state and zipcode
		setState(st);
		setZipcode(zip);
	}

	// Sets the Address
	void setAddress(std::string addr) {
		address = addr;
	}

	// Sets the City
	void setCity(std::string cty) { 
		city = cty;
	}

	// Sets the State
	void setState(std::string st) {
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
	void setZipcode(int zip) {
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
	std::string getAddress() const {
		return address;
	}

	// Gets the city
	std::string getCity() const {
		return city;
	}

	// Gets the state
	std::string getState() const {
		return state;
	}

	// Gets the zipcode
	int getZipcode() const {
		return zipcode;
	}

	// Print metho
	void print() const {
		std::cout << address << std::endl
				  << city << ", " << state << " "
			      << zipcode << std::endl;
	}
	

};

// Define the list of valid state abbreviations
const std::vector<std::string> AddressType::validStates = {
	"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID",
	"IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS",
	"MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK",
	"OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV",
	"WI", "WY"
};

