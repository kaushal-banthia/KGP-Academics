#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

#include <string>
#include <iostream>
using namespace std;

// Name: Kaushal Banthia
// Roll Number: 19CS10039

template<typename T>
class BookingClassesType;


class BookingClasses
{ 
    // Abstract Base Class
    const string name_;

    struct ACFirstClassType {};
    struct ExecutiveChairCarType {};
    struct AC2TierType {};
    struct FirstClassType {};
    struct AC3TierType {};
    struct ACChairCarType {};
    struct SleeperType {};
    struct SecondSittingType {};

    protected:
        BookingClasses(const string name);
        virtual ~BookingClasses();

    public:
        inline string GetName() const
        {
            return name_;
        }
        
        virtual bool IsLuxury() const = 0;
        virtual bool IsSitting() const = 0;
        virtual bool IsAC() const = 0;
        virtual double GetLoadFactor() const = 0;
        // concessions
        virtual double GetBlindConcessionFactor() const = 0;
        virtual double GetOrthopaedicallyHandicappedConcessionFactor() const = 0;
        virtual double GetCancerConcessionFactor() const = 0;
        virtual double GetTBConcessionFactor() const = 0;
        // concessions over
        virtual double GetTatkalLoadFactor() const = 0;
        virtual double GetReservationCharge() const = 0;
        virtual int GetNumberOfTier() const = 0;
        virtual double GetMinimumTatkalCharge() const = 0;
        virtual double GetMaximumTatkalCharge() const = 0;
        virtual double GetMinimumTatkalDistance() const = 0;
        
        // Enumerated types - the target sub-types
        typedef BookingClassesType<ACFirstClassType> ACFirstClass;
        typedef BookingClassesType<ExecutiveChairCarType> ExecutiveChairCar;
        typedef BookingClassesType<AC2TierType> AC2Tier;
        typedef BookingClassesType<FirstClassType> FirstClass;
        typedef BookingClassesType<AC3TierType> AC3Tier;
        typedef BookingClassesType<ACChairCarType> ACChairCar;
        typedef BookingClassesType<SleeperType> Sleeper;
        typedef BookingClassesType<SecondSittingType> SecondSitting;

        friend ostream &operator<<(ostream &output, const BookingClasses &bookingClass);
};

template<typename T>
class BookingClassesType : public BookingClasses
{
    static const string sName;
    static const bool sIsAC;
    static const bool sIsLuxury;
    static const bool sIsSitting;
    static const double sLoadFactor;
    static const double sTatkalLoadFactor;
    // concessions
    static const double sBlindConcessionFactor;
    static const double sOrthopaedicallyHandicappedConcessionFactor;
    static const double sCancerConcessionFactor;
    static const double sTBConcessionFactor;
    // concessions over
    static const double sReservationCharge;
    static const int sNumberOfTiers;
    static const double sMinimumTatkalCharge;
    static const double sMaximumTatkalCharge;
    static const double sMinimumTatkalDistance;

    // Constructor
    BookingClassesType();
    // Destructor
    ~BookingClassesType();
    
    public:

        // Singleton
        inline static const BookingClassesType<T>& Type()
        {
            static const BookingClassesType<T> sObj;
            return sObj;
        }

        inline bool IsLuxury() const // Dynamic dispatch
        { return BookingClassesType<T>::sIsLuxury; } // sIsLuxury parametrized by static

        inline bool IsSitting() const // Dynamic dispatch
        { return BookingClassesType<T>::sIsSitting; } // sIsSitting parametrized by static

        inline bool IsAC() const // Dynamic dispatch
        { return BookingClassesType<T>::sIsAC; } // sIsAC parametrized by static

        inline double GetLoadFactor() const // Dynamic dispatch
        { return BookingClassesType<T>::sLoadFactor; } // sLoadFactor parametrized by static

        inline double GetTatkalLoadFactor() const // Dynamic dispatch
        { return BookingClassesType<T>::sTatkalLoadFactor; } // sLoadFactor parametrized by static

        // concessions
        double GetBlindConcessionFactor() const
        { return BookingClassesType<T>::sBlindConcessionFactor; }

        double GetOrthopaedicallyHandicappedConcessionFactor() const
        { return BookingClassesType<T>::sOrthopaedicallyHandicappedConcessionFactor; }

        double GetCancerConcessionFactor() const
        { return BookingClassesType<T>::sCancerConcessionFactor; }

        double GetTBConcessionFactor() const
        { return BookingClassesType<T>::sTBConcessionFactor; }
        // concessions over

        inline double GetReservationCharge() const // Dynamic dispatch
        { return BookingClassesType<T>::sReservationCharge; } // sReservationCharge parametrized by static

        inline int GetNumberOfTier() const // Dynamic dispatch
        { return BookingClassesType<T>::sNumberOfTiers; } // sNumberOfTiers parametrized by static

        inline double GetMinimumTatkalCharge() const // Dynamic dispatch
        { return BookingClassesType<T>::sMinimumTatkalCharge; } // sMinimumTatkalCharge parametrized by static

        inline double GetMaximumTatkalCharge() const // Dynamic dispatch
        { return BookingClassesType<T>::sMaximumTatkalCharge; } // sMaximumTatkalCharge parametrized by static

        inline double GetMinimumTatkalDistance() const // Dynamic dispatch
        { return BookingClassesType<T>::sMinimumTatkalDistance; } // sMinimumTatkalDistance parametrized by static
};

template<typename T> BookingClassesType<T>::BookingClassesType():
    BookingClasses(sName)
{}

template<typename T> BookingClassesType<T>::~BookingClassesType()
{}

#endif