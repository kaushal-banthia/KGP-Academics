#ifndef _NAME_H
#define _NAME_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <string>
#include <iostream>

using namespace std;

class Name
{
    string firstName_, middleName_, lastName_;
    Name &operator=(const Name& name);

    public:
        Name(string firstName, string middleName, string lastName);
        Name(const Name &name);
        ~Name();

        static Name NewName(const string firstName, const string middleName, const string lastName);
        string GetName() const;
        
        friend ostream &operator<<(ostream &output, const Name &name);
};

#endif