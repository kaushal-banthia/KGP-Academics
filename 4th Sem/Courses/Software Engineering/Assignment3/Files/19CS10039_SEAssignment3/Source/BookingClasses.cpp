#include "BookingClasses.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Constructor for BookingClasses
BookingClasses::BookingClasses(const string name, const bool isAC, const bool IsLuxury, const float loadFactor):
    name_(name), isAC_(isAC), isLuxury_(IsLuxury), loadFactor_(loadFactor)
{}

// Copy Constructor for BookingClasses
BookingClasses::BookingClasses(const BookingClasses &b):
    name_(b.name_), isAC_(b.isAC_), isLuxury_(b.isLuxury_), loadFactor_(b.loadFactor_)
{}

// Copy Assignment Operator for BookingClasses
BookingClasses& BookingClasses::operator=(const BookingClasses &b)
{
    return *this;
}

// Destructor for BookingClasses
BookingClasses::~BookingClasses()
{}

// Output Streaming Operator
ostream& operator<<(ostream &output, const BookingClasses &b)
{
    output<<b.name_<<endl;
    output<<"Fare Load Factor: "<<b.loadFactor_<<endl;
    output<<"Seat / Berth: "<<(b.IsSitting() ? "Seat" : "Berth")<<endl;
    output<<"AC: "<<(b.isAC_ ? "Yes" : "No")<<endl;
    output<<"# of Tiers: "<<b.GetNumberOfTiers()<<endl;
    output<<"Luxury / Ordinary: "<<(b.isLuxury_ ? "Luxury" : "Ordinary")<<endl;
    
    return output;
}

// Constructor for Seat
Seat::Seat(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    BookingClasses(name, isAC, isLuxury, loadFactor)
{
    isSitting_ = true;
    numTiers_ = 0;
}

// Destructor for Seat
Seat::~Seat(){}

// Constructor for Berth
Berth::Berth(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    BookingClasses(name, isAC, isLuxury, loadFactor)
{
    isSitting_ = false;
}

// Destructor for Berth
Berth::~Berth(){}

// Constructor for SecondTier
SecondTier::SecondTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    Berth(name, isAC, isLuxury, loadFactor)
{
    numTiers_ = 2;
}

// Destructor for SecondTier
SecondTier::~SecondTier(){}

// Constructor for ThirdTier
ThirdTier::ThirdTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    Berth(name, isAC, isLuxury, loadFactor)
{
    numTiers_ = 3;
}

// Destructor for ThirdTier
ThirdTier::~ThirdTier(){}

/*************************
Concrete Classes begin now
*************************/

// AC Chair Car
const string ACChairCar::sName = "AC Chair Car";
const bool ACChairCar::sIsAC = true;
const bool ACChairCar::sIsLuxury = false;
const float ACChairCar::sLoadFactor = 1.25;

// Constructor for ACChairCar
ACChairCar::ACChairCar(): Seat(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Destructor for ACChairCar
ACChairCar::~ACChairCar(){};

// Implementation for a singleton class
const ACChairCar &ACChairCar::Type()
{
    static const ACChairCar sACChairCarObj;
    return sACChairCarObj;
}

// Second Sitting
const string SecondSitting::sName = "Second Sitting";
const bool SecondSitting::sIsAC = false;
const bool SecondSitting::sIsLuxury = false;
const float SecondSitting::sLoadFactor = 0.5;

// Constructor for SecondSitting
SecondSitting::SecondSitting(): Seat(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Destructor for SecondSitting
SecondSitting::~SecondSitting(){};

// Implementation for a singleton class
const SecondSitting &SecondSitting::Type()
{
    static const SecondSitting sSecondSittingObj;
    return sSecondSittingObj;
}

// AC First Class
const string ACFirstClass::sName = "AC First Class";
const bool ACFirstClass::sIsAC = true;
const bool ACFirstClass::sIsLuxury = true;
const float ACFirstClass::sLoadFactor = 3;

// Constructor for ACFirstClass
ACFirstClass::ACFirstClass(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Destructor for ACFirstClass
ACFirstClass::~ACFirstClass(){};

// Implementation for a singleton class
const ACFirstClass &ACFirstClass::Type()
{
    static const ACFirstClass sACFirstClassObj;
    return sACFirstClassObj;
}

// AC 2 Tier
const string AC2Tier::sName = "AC 2 Tier";
const bool AC2Tier::sIsAC = true;
const bool AC2Tier::sIsLuxury = false;
const float AC2Tier::sLoadFactor = 2;

// Constructor for AC2Tier
AC2Tier::AC2Tier(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Constructor for AC2Tier
AC2Tier::~AC2Tier(){};

// Implementation for a singleton class
const AC2Tier &AC2Tier::Type()
{
    static const AC2Tier sAC2TierObj;
    return sAC2TierObj;
}

// First Class
const string FirstClass::sName = "First Class";
const bool FirstClass::sIsAC = false;
const bool FirstClass::sIsLuxury = true;
const float FirstClass::sLoadFactor = 2;

// Constructor for FirstClass
FirstClass::FirstClass(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Destructor for FirstClass
FirstClass::~FirstClass(){};

// Implementation for a singleton class
const FirstClass &FirstClass::Type()
{
    static const FirstClass sFirstClassObj;
    return sFirstClassObj;
}

// AC 3 Tier
const string AC3Tier::sName = "AC 3 Tier";
const bool AC3Tier::sIsAC = true;
const bool AC3Tier::sIsLuxury = false;
const float AC3Tier::sLoadFactor = 1.75;

// Constructor for AC3Tier
AC3Tier::AC3Tier(): ThirdTier(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Desstructor for AC3Tier
AC3Tier::~AC3Tier(){};

// Implementation for a singleton class
const AC3Tier &AC3Tier::Type()
{
    static const AC3Tier sAC3TierObj;
    return sAC3TierObj;
}

// Sleeper
const string Sleeper::sName = "Sleeper";
const bool Sleeper::sIsAC = false;
const bool Sleeper::sIsLuxury = false;
const float Sleeper::sLoadFactor = 1;

// Constructor for Sleeper
Sleeper::Sleeper(): ThirdTier(sName, sIsAC, sIsLuxury, sLoadFactor){}

// Desstructor for Sleeper
Sleeper::~Sleeper(){};

// Implementation for a singleton class
const Sleeper &Sleeper::Type()
{
    static const Sleeper sSleeperObj;
    return sSleeperObj;
}