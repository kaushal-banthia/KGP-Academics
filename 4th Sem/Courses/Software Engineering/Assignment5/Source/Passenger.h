#ifndef _PASSENGER_H
#define _PASSENGER_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <string>

#include "Date.h"
#include "Gender.h"
#include "Divyaang.h"
#include "Name.h"

using namespace std;

class Passenger
{
    // Copy Assignment Operator
    Passenger& operator=(const Passenger& p);

    const Name &name_;
    const Date dateOfBirth_;
    const Gender &gender_;
    const long long aadharNumber_;
    const long long mobileNumber_;
    const string disabilityID_ = "";
    const Divyaang &disabilityType_;

    public:
    // Constructor
    Passenger(const Name &name, const long long aadharNumber, const Date &dateOfBirth, const Gender &gender, const long long mobileNumber, const string disabilityID, const Divyaang &disabilityType);

    // Copy Constructor
    Passenger(const Passenger& p);

    const Name &GetName() const;
    long long GetAadharNumber() const;
    inline const Date &GetDOB() const {return dateOfBirth_;}
    const Gender &GetGender() const;
    long long GetMobileNumber() const;
    string GetDisabilityID() const;
    const Divyaang &GetDisabilityType() const;

    static Passenger CreateAndCheckPassenger(const Name &name, const long long aadharNumber, const long long mobileNumber, const Date &dateOfBirth, const Gender &gender, const Divyaang &disabilityType = Divyaang::NoDisability::Type(), const string disabilityID = "");

    // Destructor for Passenger
    ~Passenger();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, const Passenger &p);
};


// Getter function for getting the Name of the Passenger
inline const Name &Passenger::GetName() const
{
    return name_;
}

// Getter function for getting the Aadhar Number of the Passenger
inline long long Passenger::GetAadharNumber() const
{
    return aadharNumber_;
}

// Getter function for getting the Gender of the Passenger
inline const Gender &Passenger::GetGender() const
{
    return gender_;
}

// Getter function for getting the Mobile Number of the Passenger
inline long long Passenger::GetMobileNumber() const
{
    return mobileNumber_;
}

// Getter function for getting the Disability ID of the Passenger
inline string Passenger::GetDisabilityID() const
{
    return disabilityID_;
}

// Getter function for getting the Disabilty Type of the Passenger
inline const Divyaang &Passenger::GetDisabilityType() const
{
    return disabilityType_;
}

#endif