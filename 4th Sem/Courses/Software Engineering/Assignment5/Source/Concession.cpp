#include "Concession.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

const double GeneralConcession::sConcessionFactor = 0;
const double LadiesConcession::sConcessionFactor = 0;

const string GeneralConcession::sName = "General Concession";
const string LadiesConcession::sName = "Ladies Concession";
const string DivyaangConcession::sName = "Divyaang Concession";
const string SeniorCitizenConcession::sName = "Senior Citizen Concession";

GeneralConcession::GeneralConcession() : Concession(sName) {}
GeneralConcession::~GeneralConcession() {}

LadiesConcession::LadiesConcession() : Concession(sName) {}
LadiesConcession::~LadiesConcession() {}

DivyaangConcession::DivyaangConcession() : Concession(sName) {}
DivyaangConcession::~DivyaangConcession() {}

SeniorCitizenConcession::SeniorCitizenConcession() : Concession(sName) {}
SeniorCitizenConcession::~SeniorCitizenConcession() {}

Concession::Concession(const string &name):
    name_(name)
{}

Concession::~Concession()
{}