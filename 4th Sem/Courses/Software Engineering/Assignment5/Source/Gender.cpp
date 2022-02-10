// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include "Gender.h"
#include <string>

using namespace std;

// Names defined as static constants
template <> const string Gender::Male::sName = "Male";
template <> const string Gender::Female::sName = "Female";

// Salutations defined as static constants
template <> const string Gender::Male::sSalutation = "Mr.";
template <> const string Gender::Female::sSalutation = "Ms.";

// Senior Citizen Concessions as static constants
template <> const double Gender::Male::sSeniorCitizenConcessionFactor = 0.40; // 60+ Males
template <> const double Gender::Female::sSeniorCitizenConcessionFactor = 0.50; //  58+ Females

Gender::Gender(const string& name):
    name_(name)
{}

Gender::~Gender()
{}

// Output Streaming Operator
ostream& operator<<(ostream &output, Gender &g)
{
    output<<g.GetName()<<endl;
    return output;
}