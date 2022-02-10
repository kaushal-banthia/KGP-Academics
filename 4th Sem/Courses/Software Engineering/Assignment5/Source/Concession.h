#ifndef _CONCESSION_H
#define _CONCESSION_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

class Concession
{
    const string &name_;
    Concession &operator=(const Concession &);

    public:
        Concession(const string &name);
        ~Concession();
};

class GeneralConcession: public Concession
{
    static const string sName;
    static const double sConcessionFactor;
    GeneralConcession();
    ~GeneralConcession();

    public:
        inline static const GeneralConcession &Type()
        {
            static const GeneralConcession sObj;
            return sObj;
        }
        
        inline double GetConcessionFactor() const
        {
            return sConcessionFactor;
        }
};

class LadiesConcession: public Concession
{
    static const string sName;
    static const double sConcessionFactor;
    LadiesConcession();
    ~LadiesConcession();

    public:
        inline static const LadiesConcession &Type()
        {
            static const LadiesConcession sObj;
            return sObj;
        }
        
        inline double GetConcessionFactor(const Passenger &p) const
        {
            return sConcessionFactor;
        }
};

class DivyaangConcession: public Concession
{
    static const string sName;
    DivyaangConcession();
    ~DivyaangConcession();

    public:
        inline static const DivyaangConcession &Type()
        {
            static const DivyaangConcession sObj;
            return sObj;
        }
        
        inline double GetConcessionFactor(const Passenger &p, const BookingClasses &bookingClass) const
        {
            return p.GetDisabilityType().GetConcessionFactor(bookingClass);
        }
};

class SeniorCitizenConcession: public Concession
{
    static const string sName;
    SeniorCitizenConcession();
    ~SeniorCitizenConcession();

    public:
        inline static const SeniorCitizenConcession &Type()
        {
            static const SeniorCitizenConcession sObj;
            return sObj;
        }
        
        inline double GetConcessionFactor(const Passenger &p) const
        {
            return p.GetGender().GetSeniorCitizenConcessionFactor();
        }
};

#endif