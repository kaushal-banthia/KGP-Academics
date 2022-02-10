#include "Passenger.h"
#include <cmath>
#include <regex>
#include "Exceptions.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Constructor
Passenger::Passenger(const Name &name, const long long aadharNumber, const Date &dateOfBirth, const Gender& gender, const long long mobileNumber, const string disabilityID, const Divyaang &disabilityType):
    name_(name), aadharNumber_(aadharNumber), dateOfBirth_(dateOfBirth), gender_(gender), mobileNumber_(mobileNumber), disabilityID_(disabilityID), disabilityType_(disabilityType)
{}

// Copy Constructor
Passenger::Passenger(const Passenger& p): 
    name_(p.name_), aadharNumber_(p.aadharNumber_), dateOfBirth_(p.dateOfBirth_), gender_(p.gender_), mobileNumber_(p.mobileNumber_), disabilityID_(p.disabilityID_), disabilityType_(p.disabilityType_)
{}

// Copy Assignment Operator
Passenger& Passenger::operator=(const Passenger& p)
{
    return *this;
}

// Destructor
Passenger::~Passenger() {}

// Output Streaming Operator
ostream& operator<<(ostream &output, const Passenger &p)
{
    output<<"Name: "<<p.name_<<endl;
    output<<"Aadhar Number: "<<p.aadharNumber_<<endl;
    output<<"Date of Birth: "<<p.dateOfBirth_;
    output<<"Gender: "<<p.gender_.GetName()<<endl;
    output<<"Mobile Number: "<<p.mobileNumber_<<endl;

    if (p.disabilityID_ != "")
    {
        output<<"Disability ID: "<<p.disabilityID_<<endl;
        output<<"Disability Type: "<<p.GetName()<<endl;
    }

    return output;
}

Passenger Passenger::CreateAndCheckPassenger(const Name &name, const long long aadharNumber, const long long mobileNumber, const Date &dateOfBirth, const Gender &gender, const Divyaang &disabilityType, const string disabilityID)
{
    if (log10(aadharNumber) + 1 != 12)
        throw InvalidAadharNumber();
    if (mobileNumber && log10(mobileNumber) + 1 != 10)
        throw InvalidMobileNumber();
    if (disabilityID != "" && regex_match(disabilityID, regex("[0-9]+")) == false)
        throw InvalidDisabilityID();;

    try{
        Date dob(Date::CreateDate(dateOfBirth.GetDay(), dateOfBirth.GetMonth(), dateOfBirth.GetYear()));
        return Passenger(name, aadharNumber, dob, gender, mobileNumber, disabilityID, disabilityType);
    }
    catch(const Bad_Date &e){
        cout<<e.what()<<endl;
        throw Invalid_Date_Of_Birth();
    }

    return Passenger(name, aadharNumber, dateOfBirth, gender, mobileNumber, disabilityID, disabilityType);
}