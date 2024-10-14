// This class represents a date with month, day, and year attributes.
// It provides methods for validating and setting the date, and checking for leap years.
// Additional methods allow retrieval of date components and printing the date.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include <iostream>

class DateType {
private:
    int dMonth;                                                 // Month
    int dDay;                                                   // Day
    int dYear;                                                  // Year

public:
    
    DateType(int month = 1, int day = 1, int year = 1900);      // Constructor with default parameter
    bool isLeapYear(int year) const;                            // Checks if year is a leap year
    void setDate(int month, int day, int year);                 // Sets date with validation

    int getDaysInMonth(int month, int year) const;              // Gets the number of days in the month
    int getDay() const;                                         // Gets day
    int getMonth() const;                                       // Gets month
    int getYear() const;                                        // Gets year

    void print() const;                                         // Print method
};
