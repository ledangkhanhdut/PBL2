#include "doctor.h"

Doctor::Doctor(unsigned int Id,const string& name, int age , const string& phone ,const string& addr, char gender,const string& Time_WK,const string& Exp):Person(Id,name,age,phone,addr,gender)
{
    this->Time_Working = Time_WK;
    this->Exp = Exp;
}
Doctor::Doctor(const Doctor &p):Person(p)
{
    this->Time_Working = p.Time_Working;
    this->Exp = p.Exp;
}
void Doctor::view_Workschedule()
{
}
void Doctor::view_Patient()
{
    cout << this->Exp;
}
void Doctor::add_Medical()
{
}
Doctor::~Doctor() {};

// Doctor Tachchuoi(const string &line)
// {
//     Doctor p1.
// }
