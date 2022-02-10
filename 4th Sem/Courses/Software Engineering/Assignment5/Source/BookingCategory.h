#ifndef _BOOKINGCATEGORY_H
#define _BOOKINGCATEGORY_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <string>
#include "Passenger.h"
#include "Category.h"
#include "Booking.h"
#include "Date.h"
#include "Exceptions.h"

using namespace std;

class Passenger;
class Station;
class Date;
class BookingClasses;

template<typename T>
class BookingCategoryTypes;

class BookingCategory
{ 
    // Abstract Base Class
    const string name_;

    protected:
        BookingCategory(const string &name);
        virtual ~BookingCategory();

    public:
        inline const string GetName() const { return name_; }
        virtual bool CheckEligibility(const Passenger& p) const = 0;
        virtual Booking* MakeReservation(const Station &from, const Station &to, const Date &, const Date&, const Passenger &p, const BookingClasses &bookingClass) const = 0;
        
        // Enumerated types - the target sub-types
        typedef BookingCategoryTypes<Category::GeneralType> General;
        typedef BookingCategoryTypes<Category::LadiesType> Ladies;
        typedef BookingCategoryTypes<Category::SeniorCitizenType> SeniorCitizen;
        typedef BookingCategoryTypes<Category::DivyaangType> Divyaang;
        typedef BookingCategoryTypes<Category::TatkalType> Tatkal;
        typedef BookingCategoryTypes<Category::PremiumTatkalType> PremiumTatkal;
};

template<typename T>
class BookingCategoryTypes : public BookingCategory
{
    static const string sName;

    // Constructor
    BookingCategoryTypes();

    // Destructor
    ~BookingCategoryTypes();
    
    public:

        // Singleton
        inline static const BookingCategoryTypes<T>& Type()
        {
            static const BookingCategoryTypes<T> sObj;
            return sObj;
        }

        bool CheckEligibility(const Passenger& p) const;
        Booking* MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const;
};

template<typename T> BookingCategoryTypes<T>::BookingCategoryTypes():
    BookingCategory(sName)
{}

template<typename T> BookingCategoryTypes<T>::~BookingCategoryTypes()
{}

// Checking the Eligibility for the various Booking Categories
template<> inline bool BookingCategory::General::CheckEligibility(const Passenger &passenger) const
{
    return true; // Always eligible for General Booking
}

template<> inline bool BookingCategory::Ladies::CheckEligibility(const Passenger &passenger) const
{
    if (passenger.GetDOB().GetAge(Date(9, 4, 2021))[2] < 12 || Gender::IsMale(passenger.GetGender()) != true)
        return true;
    throw IneligibleForLadies();
}

template<> inline bool BookingCategory::SeniorCitizen::CheckEligibility(const Passenger &passenger) const
{
    if ((passenger.GetDOB().GetAge(Date(9, 4, 2021))[2] >= 60) && (Gender::IsMale(passenger.GetGender()) == true))
        return true;
    else if ((passenger.GetDOB().GetAge(Date(9, 4, 2021))[2] >= 58) && (Gender::IsMale(passenger.GetGender()) != true))
        return true;
    throw IneligibleForSeniorCitizen();
}

template<> inline bool BookingCategory::Divyaang::CheckEligibility(const Passenger &passenger) const
{
    if (passenger.GetDisabilityType().GetName() != "No Disability")
        return true;
    throw IneligibleForDivyaang();
}

template<> inline bool BookingCategory::Tatkal::CheckEligibility(const Passenger &passenger) const
{
    return true;
}

template<> inline bool BookingCategory::PremiumTatkal::CheckEligibility(const Passenger &passenger) const
{
    return true;
}

// make reservation functions for different sub-types inlined
template<> inline Booking* BookingCategory::General::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    return new Booking::GeneralBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
}
template<> inline Booking* BookingCategory::Ladies::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    return new Booking::LadiesBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
}

template<> inline Booking* BookingCategory::SeniorCitizen::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    return new Booking::SeniorCitizenBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
}

template<> inline Booking* BookingCategory::Divyaang::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    return new Booking::DivyaangBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
}

template<> inline Booking* BookingCategory::Tatkal::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    int day = dateOfReservation.GetAge(dateOfBooking)[0];
    int month = dateOfReservation.GetAge(dateOfBooking)[1];
    int year = dateOfReservation.GetAge(dateOfBooking)[2];

    if (day == 1 && month == 0 && year == 0)
        return new Booking::TatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
    throw TatkalInvalid();
}

template<> inline Booking* BookingCategory::PremiumTatkal::MakeReservation(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass) const
{
    int day = dateOfReservation.GetAge(dateOfBooking)[0];
    int month = dateOfReservation.GetAge(dateOfBooking)[1];
    int year = dateOfReservation.GetAge(dateOfBooking)[2];

    if (day == 1 && month == 0 && year == 0)
        return new Booking::PremiumTatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass, GetName());
    throw TatkalInvalid();
}

#endif