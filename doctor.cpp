#include "doctor.h"

Doctor::Doctor(unsigned int Id,const string& name, int age , const string& phone ,const string& addr, char gender,const string& Exp):Person(Id,name,age,phone,addr,gender)
{
    this->Exp = Exp;
}
Doctor::Doctor(const Doctor &p):Person(p)
{
    this->Exp = p.Exp;
}
void Doctor::view_Workschedule()
{
}
void Doctor::view_Patient()
{
    cout << this->Exp;
}

// string Doctor::get_Time_Working() const {
//     return this->Time_Working;
// }
// void Doctor::set_Time_Working(const string & exp){
//     this->Exp = exp;
// }
string Doctor::get_Exp()const {
    return this->Exp;
}
void  Doctor::set_Exp(const string& Exp) {
    this->Exp = Exp;
}
Doctor::~Doctor(){};

