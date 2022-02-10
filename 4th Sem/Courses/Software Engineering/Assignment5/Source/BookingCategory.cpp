#include "BookingCategory.h"
#include <string>

// Name: Kaushal Banthia
// Roll Number: 19CS10039

using namespace std;

template <> const string BookingCategory::General::sName = "General";
template <> const string BookingCategory::Ladies::sName = "Ladies";
template <> const string BookingCategory::SeniorCitizen::sName = "Senior Citizen";
template <> const string BookingCategory::Divyaang::sName = "Divyaang";
template <> const string BookingCategory::Tatkal::sName = "Tatkal";
template <> const string BookingCategory::PremiumTatkal::sName = "Premium Tatkal";

BookingCategory::BookingCategory(const string &name):
    name_(name)
{}

BookingCategory::~BookingCategory()
{}