#include "BookingClasses.h"
#include <string>

// Name: Kaushal Banthia
// Roll Number: 19CS10039

using namespace std;

// ACFirstClass
template<> const string BookingClasses::ACFirstClass::sName = "AC First Class";
template<> const bool BookingClasses::ACFirstClass::sIsAC = true;
template<> const bool BookingClasses::ACFirstClass::sIsLuxury = true;
template<> const bool BookingClasses::ACFirstClass::sIsSitting = false;
template<> const double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template<> const double BookingClasses::ACFirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::ACFirstClass::sBlindConcessionFactor = 0.50;
template<> const double BookingClasses::ACFirstClass::sOrthopaedicallyHandicappedConcessionFactor = 0.50;
template<> const double BookingClasses::ACFirstClass::sCancerConcessionFactor = 0.50;
template<> const double BookingClasses::ACFirstClass::sTBConcessionFactor = 0;
template<> const double BookingClasses::ACFirstClass::sReservationCharge = 60;
template<> const int BookingClasses::ACFirstClass::sNumberOfTiers = 2;
template<> const double BookingClasses::ACFirstClass::sMinimumTatkalCharge = 400;
template<> const double BookingClasses::ACFirstClass::sMaximumTatkalCharge = 500;
template<> const double BookingClasses::ACFirstClass::sMinimumTatkalDistance = 500;

// ExecutiveChairCar
template<> const string BookingClasses::ExecutiveChairCar::sName = "Executive Chair Car";
template<> const bool BookingClasses::ExecutiveChairCar::sIsAC = true;
template<> const bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template<> const bool BookingClasses::ExecutiveChairCar::sIsSitting = true;
template<> const double BookingClasses::ExecutiveChairCar::sLoadFactor = 5;
template<> const double BookingClasses::ExecutiveChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::ExecutiveChairCar::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::ExecutiveChairCar::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::ExecutiveChairCar::sCancerConcessionFactor = 0.75;
template<> const double BookingClasses::ExecutiveChairCar::sTBConcessionFactor = 0;
template<> const double BookingClasses::ExecutiveChairCar::sReservationCharge = 60;
template<> const int BookingClasses::ExecutiveChairCar::sNumberOfTiers = 0;
template<> const double BookingClasses::ExecutiveChairCar::sMinimumTatkalCharge = 400;
template<> const double BookingClasses::ExecutiveChairCar::sMaximumTatkalCharge = 500;
template<> const double BookingClasses::ExecutiveChairCar::sMinimumTatkalDistance = 250;

// AC2Tier
template<> const string BookingClasses::AC2Tier::sName = "AC 2 Tier";
template<> const bool BookingClasses::AC2Tier::sIsAC = true;
template<> const bool BookingClasses::AC2Tier::sIsLuxury = false;
template<> const bool BookingClasses::AC2Tier::sIsSitting = false;
template<> const double BookingClasses::AC2Tier::sLoadFactor = 4;
template<> const double BookingClasses::AC2Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::AC2Tier::sBlindConcessionFactor = 0.50;
template<> const double BookingClasses::AC2Tier::sOrthopaedicallyHandicappedConcessionFactor = 0.50;
template<> const double BookingClasses::AC2Tier::sCancerConcessionFactor = 0.50;
template<> const double BookingClasses::AC2Tier::sTBConcessionFactor = 0;
template<> const double BookingClasses::AC2Tier::sReservationCharge = 50;
template<> const int BookingClasses::AC2Tier::sNumberOfTiers = 2;
template<> const double BookingClasses::AC2Tier::sMinimumTatkalCharge = 400;
template<> const double BookingClasses::AC2Tier::sMaximumTatkalCharge = 500;
template<> const double BookingClasses::AC2Tier::sMinimumTatkalDistance = 500;

// FirstClass
template<> const string BookingClasses::FirstClass::sName = "First Class";
template<> const bool BookingClasses::FirstClass::sIsAC = false;
template<> const bool BookingClasses::FirstClass::sIsLuxury = true;
template<> const bool BookingClasses::FirstClass::sIsSitting = false;
template<> const double BookingClasses::FirstClass::sLoadFactor = 3;
template<> const double BookingClasses::FirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::FirstClass::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::FirstClass::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::FirstClass::sCancerConcessionFactor = 0.75;
template<> const double BookingClasses::FirstClass::sTBConcessionFactor = 0.75;
template<> const double BookingClasses::FirstClass::sReservationCharge = 50;
template<> const int BookingClasses::FirstClass::sNumberOfTiers = 2;
template<> const double BookingClasses::FirstClass::sMinimumTatkalCharge = 400;
template<> const double BookingClasses::FirstClass::sMaximumTatkalCharge = 500;
template<> const double BookingClasses::FirstClass::sMinimumTatkalDistance = 500;

// AC3Tier
template<> const string BookingClasses::AC3Tier::sName = "AC3Tier";
template<> const bool BookingClasses::AC3Tier::sIsAC = true;
template<> const bool BookingClasses::AC3Tier::sIsLuxury = false;
template<> const bool BookingClasses::AC3Tier::sIsSitting = false;
template<> const double BookingClasses::AC3Tier::sLoadFactor = 2.50;
template<> const double BookingClasses::AC3Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::AC3Tier::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::AC3Tier::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::AC3Tier::sCancerConcessionFactor = 1;
template<> const double BookingClasses::AC3Tier::sTBConcessionFactor = 0;
template<> const double BookingClasses::AC3Tier::sReservationCharge = 40;
template<> const int BookingClasses::AC3Tier::sNumberOfTiers = 3;
template<> const double BookingClasses::AC3Tier::sMinimumTatkalCharge = 300;
template<> const double BookingClasses::AC3Tier::sMaximumTatkalCharge = 400;
template<> const double BookingClasses::AC3Tier::sMinimumTatkalDistance = 500;

// ACChairCar
template<> const string BookingClasses::ACChairCar::sName = "AC Chair Car";
template<> const bool BookingClasses::ACChairCar::sIsAC = true;
template<> const bool BookingClasses::ACChairCar::sIsLuxury = false;
template<> const bool BookingClasses::ACChairCar::sIsSitting = true;
template<> const double BookingClasses::ACChairCar::sLoadFactor = 2;
template<> const double BookingClasses::ACChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::ACChairCar::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::ACChairCar::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::ACChairCar::sCancerConcessionFactor = 1;
template<> const double BookingClasses::ACChairCar::sTBConcessionFactor = 0;
template<> const double BookingClasses::ACChairCar::sReservationCharge = 40;
template<> const int BookingClasses::ACChairCar::sNumberOfTiers = 0;
template<> const double BookingClasses::ACChairCar::sMinimumTatkalCharge = 125;
template<> const double BookingClasses::ACChairCar::sMaximumTatkalCharge = 225;
template<> const double BookingClasses::ACChairCar::sMinimumTatkalDistance = 250;

// Sleeper
template<> const string BookingClasses::Sleeper::sName = "Sleeper";
template<> const bool BookingClasses::Sleeper::sIsAC = false;
template<> const bool BookingClasses::Sleeper::sIsLuxury = false;
template<> const bool BookingClasses::Sleeper::sIsSitting = false;
template<> const double BookingClasses::Sleeper::sLoadFactor = 1;
template<> const double BookingClasses::Sleeper::sTatkalLoadFactor = 0.30;
template<> const double BookingClasses::Sleeper::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::Sleeper::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::Sleeper::sCancerConcessionFactor = 1;
template<> const double BookingClasses::Sleeper::sTBConcessionFactor = 0.75;
template<> const double BookingClasses::Sleeper::sReservationCharge = 20;
template<> const int BookingClasses::Sleeper::sNumberOfTiers = 3;
template<> const double BookingClasses::Sleeper::sMinimumTatkalCharge = 100;
template<> const double BookingClasses::Sleeper::sMaximumTatkalCharge = 200;
template<> const double BookingClasses::Sleeper::sMinimumTatkalDistance = 500;

// SecondSitting
template<> const string BookingClasses::SecondSitting::sName = "Second Sitting";
template<> const bool BookingClasses::SecondSitting::sIsAC = false;
template<> const bool BookingClasses::SecondSitting::sIsLuxury = false;
template<> const bool BookingClasses::SecondSitting::sIsSitting = true;
template<> const double BookingClasses::SecondSitting::sLoadFactor = 0.60;
template<> const double BookingClasses::SecondSitting::sTatkalLoadFactor = 0.10;
template<> const double BookingClasses::SecondSitting::sBlindConcessionFactor = 0.75;
template<> const double BookingClasses::SecondSitting::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const double BookingClasses::SecondSitting::sCancerConcessionFactor = 1;
template<> const double BookingClasses::SecondSitting::sTBConcessionFactor = 0.75;
template<> const double BookingClasses::SecondSitting::sReservationCharge = 15;
template<> const int BookingClasses::SecondSitting::sNumberOfTiers = 0;
template<> const double BookingClasses::SecondSitting::sMinimumTatkalCharge = 10;
template<> const double BookingClasses::SecondSitting::sMaximumTatkalCharge = 15;
template<> const double BookingClasses::SecondSitting::sMinimumTatkalDistance = 100;

BookingClasses::BookingClasses(const string name):
    name_(name)
{}

BookingClasses::~BookingClasses()
{}

ostream &operator<<(ostream &output, const BookingClasses &bookingClass){
    output<<bookingClass.GetName()<<endl;
    output<<"AC: "<<bookingClass.IsAC()<<endl;
    output<<"Sitting: "<<bookingClass.IsSitting()<<endl;
    output<<"Luxury: "<<bookingClass.IsLuxury()<<endl;
    output<<"Number of Tiers: "<<bookingClass.GetNumberOfTier()<<endl;
    output<<"Load Factor: "<<bookingClass.GetLoadFactor()<<endl;
    output<<"Tatkal Load Factor: "<<bookingClass.GetTatkalLoadFactor()<<endl;
    output<<"Reservation Charge: "<<bookingClass.GetReservationCharge()<<endl;
    output<<"Minimum Tatkal Charge: "<<bookingClass.GetMinimumTatkalCharge()<<endl;
    output<<"Maximum Tatkal Charge: "<<bookingClass.GetMaximumTatkalCharge()<<endl;
    output<<"Minimum Tatkal Distance: "<<bookingClass.GetMinimumTatkalDistance();
    return output;
}