#ifndef _DIVYAANG_H
#define _DIVYAANG_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <string>
#include <iostream>
#include "BookingClasses.h"
using namespace std;


template<typename T>
class DivyaangTypes;

class Divyaang
{    
    const string& name_;

    struct NoDisabilityType {};
    struct BlindType {};
    struct CancerPatientType {};
    struct TBPatientType {};
    struct OrthopaedicallyHandicappedType {};

    Divyaang(const Divyaang & d);
    Divyaang &operator=(const Divyaang &);

    public:
        Divyaang(const string& name);
        virtual ~Divyaang();
        
        const string& GetName() const;
        virtual double GetConcessionFactor(const BookingClasses &) const = 0;

        typedef DivyaangTypes<NoDisabilityType> NoDisability;
        typedef DivyaangTypes<BlindType> Blind;
        typedef DivyaangTypes<CancerPatientType> CancerPatient;
        typedef DivyaangTypes<TBPatientType> TBPatient;
        typedef DivyaangTypes<OrthopaedicallyHandicappedType> OrthopaedicallyHandicapped;

        // Output Streaming Operator
        friend ostream& operator<<(ostream &output, Divyaang &d);
};

template<typename T>
class DivyaangTypes : public Divyaang
{
    static const string sName;
    static const double sACFirstClassConcession;
    static const double sExecutiveChairCarConcession;
    static const double sAC2TierConcession;
    static const double sFirstClassConcession;
    static const double sAC3TierConcession;
    static const double sACChairCarConcession;
    static const double sSleeperConcession;
    static const double sSecondSittingConcession;
    
    DivyaangTypes();
    ~DivyaangTypes();

    public:
        static const DivyaangTypes<T>& Type();
        double GetConcessionFactor(const BookingClasses&) const;
};

template <typename T> DivyaangTypes<T>::DivyaangTypes():
    Divyaang(sName)
{}

template <typename T> DivyaangTypes<T>::~DivyaangTypes()
{}

template <typename T> inline const DivyaangTypes<T> &DivyaangTypes<T>::Type()
{
        static const DivyaangTypes<T> sObject; // May be non-const for changeable behavior
        return sObject;
}

inline const string& Divyaang::GetName() const
{
    return name_;
}

template<> inline double Divyaang::NoDisability::GetConcessionFactor(const BookingClasses &bookingClass) const
{
    return 0;
}

template<> inline double Divyaang::Blind::GetConcessionFactor(const BookingClasses &bookingClass) const
{
    return bookingClass.GetBlindConcessionFactor();
}

template<> inline double Divyaang::OrthopaedicallyHandicapped::GetConcessionFactor(const BookingClasses &bookingClass) const
{
    return bookingClass.GetOrthopaedicallyHandicappedConcessionFactor();
}

template<> inline double Divyaang::CancerPatient::GetConcessionFactor(const BookingClasses &bookingClass) const
{
    return bookingClass.GetCancerConcessionFactor();
}

template<> inline double Divyaang::TBPatient::GetConcessionFactor(const BookingClasses &bookingClass) const
{
    return bookingClass.GetTBConcessionFactor();
}

#endif
