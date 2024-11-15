#include "Schedule.h"

Schedule::Schedule(const string &time_W, unsigned int id_person, const string &name, const string &Combo, const string &Medical, const string &About, char Status)
{
    this->Time_w = time_W;
    this->ID_person = id_person;
    this->Name = name;
    this->Combo =  Combo;
    this->Medical = Medical;
    this->About = About;
    this->Status = Status;
}
Schedule::Schedule(const Schedule  &p){
    this->Time_w = p.Time_w;
    this->ID_person = p.ID_person;
    this->Name= p.Name;
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