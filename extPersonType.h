#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>
#include <regex>

// Inheritance
class extPersonType : public personType
{
private:
	// Composition
	dateType birthdate;
	addressType address;

	// Additional member variables
	std::string phoneNumber;
	std::string relationship;


public:
	// Constructor with default parameters
	extPersonType(const std::string& fName = "", const std::string& lName = "",
				  int month = 1, int day = 1, int year = 1900,
				  const std::string& street = "", const std::string& city = "",
				  const std::string& state = "XX", int zip = 10000,
				  const std::string& phone = "None", const std::string& relation = "None")
		: personType(fName,lName),
		  birthdate(month,day,year),
		  address(street,city,state,zip),
		  phoneNumber(phone),
		  relationship(relation) {}
	
	void setPhoneNumber(const std::string& phone) {
		
		// Define the regex patter for valid phone number
		const std::regex pattern(R"(\d{3}-\d{3}-\d{4})");

		// Validates phone number
		if (std::regex_match(phone, pattern)) {
			phoneNumber = phone;
		}

		// Default phone number
		else {
			phoneNumber = "None";
		}
	}

	void setRelationship(const std::string& relation) {
		if (relation == "Family" || relation == "Friend" || relation == "Business") {
			relationship = relation;
		}

		else {
			relationship = "None"
		}
	}



	


};

