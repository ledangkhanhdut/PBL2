#include "Schedule.h"

Schedule::Schedule(const string &time_W, unsigned int id_patient, const string &Combo, const string &Medical, const string &About, char = 'N')
{
    this->Time_w = time_W;
    this->Id_patient = id_patient;
    this->Combo =  Combo;
    this->Medical = Medical;
    this->About = About;
    this->Status = Status;
}
Schedule::~Schedule()
{
}