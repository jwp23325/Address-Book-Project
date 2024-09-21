#pragma once
#include <iostream>

class DateType {
private:
    int dMonth;
    int dDay;
    int dYear;

public:
    // Constructor with default parameters
    DateType(int month = 1, int day = 1, int year = 1900);

    // Checks if year is a leap year
    bool isLeapYear(int year) const;

    // Sets date with validation
    void setDate(int month, int day, int year);

    // Gets the number of days in the month
    int getDaysInMonth(int month, int year) const;

    // Gets day
    int getDay() const;

    // Gets month
    int getMonth() const;

    // Gets year
    int getYear() const;

    // Print method
    void print() const;
};
