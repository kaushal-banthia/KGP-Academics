#ifndef _PASSENGER_H
#define _PASSENGER_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

// Abstract Base Class
class Passenger
{
    // Copy Assignment Operator
    Passenger& operator=(const Passenger& p);

    protected:
    // Name of the Passenger
    const string name_;

    // Aadhar Number of the Passenger
    const long long aadharNumber_;

    // Date of Birth of the Passenger
    const Date dateOfBirth_;

    // Gender of the Passenger
    const string gender_;

    // Mobile Number of the Passenger
    const long long mobileNumber_;

    // Category of the Passenger
    const string category_;

    public:
    // Constructor
    Passenger(const string name, const long long aadharNumber, const Date &dateOfBirth, const string gender, const long long mobileNumber, const string category);

    // Copy Constructor
    Passenger(const Passenger& p);

    // Getter function for getting the Name of the Passenger
    inline string GetName() const
    {
        return name_;
    }

    // Getter function for getting the Aadhar Number of the Passenger
    inline long long GetAadharNumber() const
    {
        return aadharNumber_;
    }

    // Getter function for getting the Date of the Passenger
    inline Date GetDate() const
    {
        return dateOfBirth_;
    }

    // Getter function for getting the Gender of the Passenger
    inline string GetGender() const
    {
        return gender_;
    }

    // Getter function for getting the Mobile Number of the Passenger
    inline long long GetMobileNumber() const
    {
        return mobileNumber_;
    }

    // Pure Virtual function for getting the Category of the Passenger
    virtual string GetCategory() const = 0;

    // Destructor for Passenger
    virtual ~Passenger();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Passenger &p);
};

#endif