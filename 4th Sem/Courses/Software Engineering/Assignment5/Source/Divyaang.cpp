// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include "Divyaang.h"
#include <string>
using namespace std;

template <> const string Divyaang::NoDisability::sName = "No Disability";
template <> const string Divyaang::Blind::sName = "Blind";
template <> const string Divyaang::CancerPatient::sName = "Cancer Patient";
template <> const string Divyaang::TBPatient::sName = "TB Patient";
template <> const string Divyaang::OrthopaedicallyHandicapped::sName = "Orthopaedically Handicapped";

Divyaang::Divyaang(const string& name):
    name_(name)
{}

Divyaang::~Divyaang()
{}

// Output Streaming Operator
ostream& operator<<(ostream &output, Divyaang &d)
{
    output<<d.GetName()<<endl;
    return output;
}