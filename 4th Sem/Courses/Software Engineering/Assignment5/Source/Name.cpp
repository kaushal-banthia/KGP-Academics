// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include "Name.h"
#include "Exceptions.h"

Name::Name(string firstName, string middleName, string lastName):
    firstName_(firstName), middleName_(middleName), lastName_(lastName)
{}

Name::Name(const Name& name):
    firstName_(name.firstName_), middleName_(name.middleName_), lastName_(name.lastName_)
{}

Name::~Name()
{}

Name Name::NewName(string firstName, string middleName, string lastName)
{
    // Either First Name should be there
    // Or Last Name should be there
    // Both cannot be empty
    if (firstName == "" && lastName == "")
        throw InvalidName();
    return Name(firstName, middleName, lastName);
}

string Name::GetName() const
{
    string name = "";
    if (firstName_ != "")
        name += firstName_;
    
    if (middleName_ != "")
        name+= (" " + middleName_);

    if (lastName_ != "")
        name+= (" " + lastName_);

    return name;
}

ostream &operator<<(ostream &output, const Name &name){
    output<<name.GetName();
    return output;
}