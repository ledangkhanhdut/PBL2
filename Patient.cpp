#include "Patient.h"


Patient::Patient(unsigned int Id,const string &name, int age, const string &phone, const string &address, char gender) : Person(Id,name,age,phone,address,gender)
{
}
Patient::Patient(const Patient &p) : Person(p)
{
}
void Patient::update_information(const Patient &p){
    (*this) = p;
}
Patient::~Patient()
{
    
}