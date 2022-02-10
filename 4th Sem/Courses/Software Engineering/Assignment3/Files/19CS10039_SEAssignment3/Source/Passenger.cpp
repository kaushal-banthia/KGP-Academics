#include "Passenger.h"
#include "Date.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Constructor
Passenger::Passenger(const string name, const long long aadharNumber, const Date &dateOfBirth, const string gender, const long long mobileNumber, const string category):
    name_(name), aadharNumber_(aadharNumber), dateOfBirth_(dateOfBirth), gender_(gender), mobileNumber_(mobileNumber), category_(category)
{}

// Copy Constructor
Passenger::Passenger(const Passenger& p): 
    name_(p.name_), aadharNumber_(p.aadharNumber_), dateOfBirth_(p.dateOfBirth_), gender_(p.gender_), mobileNumber_(p.mobileNumber_), category_(p.category_)
{}

// Copy Assignment Operator
Passenger& Passenger::operator=(const Passenger& p)
{
    return *this;
}

// Destructor
Passenger::~Passenger() {}

// Output Streaming Operator
ostream& operator<<(ostream &output, Passenger &p)
{
    output<<"Name: "<<p.name_<<endl;
    output<<"Aadhar Number: "<<p.aadharNumber_<<endl;
    output<<"Date of Birth: "<<p.dateOfBirth_;
    output<<"Gender: "<<p.gender_<<endl;
    output<<"Mobile Number: "<<p.mobileNumber_<<endl;
    output<<"Category: "<<p.category_<<endl;

    return output;
}