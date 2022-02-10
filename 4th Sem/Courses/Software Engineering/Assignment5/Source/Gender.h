#ifndef _GENDER_H
#define _GENDER_H

#include <string>
// Kaushal Banthia
// 19CS10039

#include <iostream>

template<typename T>
class GenderTypes;

using namespace std;

class Gender
{    
    const string name_;

    struct MaleType {};
    struct FemaleType {};

    protected:
        Gender(const string& name);
        virtual ~Gender();

    public:
        string GetName() const;
        virtual const string GetTitle() const = 0;
        virtual const double GetSeniorCitizenConcessionFactor() const = 0;
        static bool IsMale(const Gender&);
        
        typedef GenderTypes<MaleType> Male;
        typedef GenderTypes<FemaleType> Female;

        // Output Streaming Operator
        friend ostream& operator<<(ostream &output, Gender &g);
};

template<typename T>
class GenderTypes : public Gender
{
    static const string sName; // Respective name of the gender
    static const string sSalutation; // Respective salutation for the gender
    static const double sSeniorCitizenConcessionFactor; // Respective Senior Citizen Concession Factor for the gender
    
    GenderTypes();
    ~GenderTypes();

    public:
        static const GenderTypes<T>& Type(); // Singleton Class

        const double GetSeniorCitizenConcessionFactor() const;
        const string GetTitle() const;
};

inline string Gender::GetName() const
{
    return name_;
}

template<typename T> GenderTypes<T>::GenderTypes():
    Gender(sName) 
{}

template<typename T> GenderTypes<T>::~GenderTypes()
{}

template<typename T> inline const GenderTypes<T> &GenderTypes<T>::Type()
{
    static const GenderTypes<T> sObject;
    return sObject;
}

template<typename T> inline const double GenderTypes<T>::GetSeniorCitizenConcessionFactor() const
{
    return sSeniorCitizenConcessionFactor;
}

template<typename T> inline const string GenderTypes<T>::GetTitle() const
{
    return sSalutation;
}

inline
bool Gender::IsMale(const Gender& g) { return &g == &Gender::Male::Type(); }

#endif