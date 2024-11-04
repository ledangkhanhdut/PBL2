#include "Schedule.h"

Schedule::Schedule(const string &time_W, unsigned int id_patient, const string &name, const string &Combo, const string &Medical, const string &About, char Status)
{
    this->Time_w = time_W;
    this->Id_patient = id_patient;
    this->Name_Patient = 
    this->Combo =  Combo;
    this->Medical = Medical;
    this->About = About;
    this->Status = Status;
}
Schedule::Schedule(const Schedule  &p){
    this->Time_w = p.Time_w;
    this->Id_patient = p.Id_patient;
    this->Name_Patient= p.Name_Patient;
    this->Combo = p.Combo;
    this->Medical = p.Medical;
    this->About = p.About;
    this->Status = p.Status;
}
void Schedule::Change_Status(){
    if (this->Status == 'N') this->Status = 'Y'; else  this->Status = 'N';
}
Schedule::~Schedule()
{
}